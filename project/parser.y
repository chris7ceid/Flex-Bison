%{
	#include <stdio.h>
	#include <string.h>

	#define FILE_LENGTH 5000
	#define LINE_LENGTH 500

	//Colors
	#define ANSI_COLOR_RED     "\x1b[31m"
	#define ANSI_COLOR_GREEN   "\x1b[32m"
	#define ANSI_COLOR_YELLOW  "\x1b[33m"
	#define ANSI_COLOR_BLUE    "\x1b[34m"
	#define ANSI_COLOR_MAGENTA "\x1b[35m"
	#define ANSI_COLOR_CYAN    "\x1b[36m"
	#define ANSI_COLOR_RESET   "\x1b[0m"

	extern int number_of_errors;
	extern int line_no;
	extern char yytext[];
	extern char linebuf[FILE_LENGTH][LINE_LENGTH];

	struct decl
	{
		int type;
		int kind;
		char variable[1024];
	} variables[1024];

	void insert_variable(char*, char*);
	void insert_function(char*, char*);
	int check_function(char*);
	int check_variable(char*);
	
	//bison
	void yyerror(const char *);
	int yylex();
	
	extern char* concat(const char *s1, const char *s2);
%}

%union{
	char* str;
	struct {
		enum Type {
			TY_int, 
			TY_double, 
			TY_bool, 
			TY_char,
			TY_int_ptr, 
			TY_double_ptr, 
			TY_bool_ptr, 
			TY_char_ptr,
			TY_void
		} type;
		char* str;
	} exp;				
}
%type<exp> expression data_type basic_data_type statement statements expression_list const_expression
%type<str> binary_op binary_assign_op unary_op unary_assign_op
%token<str> IDENTIFIER 
%token  I_CONSTANT D_CONSTANT C_CONSTANT STRING_LITERAL 
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	BOOL CHAR INT DOUBLE VOID BYREF
%token	IF ELSE FOR CONTINUE BREAK RETURN
%token	TRUE FALSE NIL
%token	NEW DELETE


%%

// <program> ::= (<declaration>) +
program
	: declaration declarations
;

declarations
	: declaration declarations
	| declaration
	|
;

// <declaration> ::= <variable_declaration>|<function_declaration>|<function_definition>
declaration
	: variable_declaration
	| function_declaration
	| function_definition
	| error
;

// <variable_declaration> ::= <data_type><declerative>(,<declerative>) * ;
variable_declaration
	: data_type declaratives ';'
;

declaratives
	: declarative ',' declaratives
	| declarative
;

// <data_type> ::= <basic_data_type>(*) *
data_type
	: basic_data_type{ $$.type = $1.type;} 
	| basic_data_type pointers {
			switch($1.type){
				case TY_int:
					$$.type = TY_int_ptr;
					break;				
				case TY_char:
					$$.type = TY_char_ptr;
					break;				
				case TY_bool:
					$$.type = TY_bool_ptr;
					break;			
				case TY_double:
					$$.type = TY_double_ptr;
					break;
			}
	}
;

pointers
	: '*' pointers
	| '*'
;

// <basic_data_type> ::= int|char|bool|double
basic_data_type
	: INT {$$.type = TY_int;}
	| CHAR {$$.type = TY_char;}
	| BOOL {$$.type = TY_bool;}
	| DOUBLE {$$.type = TY_double;}
;

// <declerative> ::= <id>[[<const_expression>]]
declarative
	: IDENTIFIER { insert_variable(linebuf[line_no] ,$1); }
	| IDENTIFIER '[' I_CONSTANT ']' { insert_variable(linebuf[line_no] ,$1);}
;

// <function_declaration> ::= <return_type><id>([<parameter_list>]);
// <return_type> ::= <data_type>|void
function_declaration
	: data_type IDENTIFIER '(' parameter_list ')' ';' { insert_function(linebuf[line_no] ,$2); }
	| VOID IDENTIFIER '(' parameter_list ')' ';' { insert_function(linebuf[line_no] ,$2); }
;

// <parameter_list> ::= <parameter>(,<parameter>) *
parameter_list
	: parameter ',' parameter_list
	| parameter
	|
;

// <parameter> ::= [byref]<data_type><id>
parameter
	: data_type IDENTIFIER
	| BYREF data_type IDENTIFIER
;

// <function_declaration> ::= <return_type><id>([<parameter_list>]){(<declaration>) * (<statement>) * }
function_definition
	: data_type IDENTIFIER '(' parameter_list ')' '{' declarations statements '}' {
		if(check_function($2) == -1) yyerror(concat("undeclared function ", $2));
		if (check_function($2) != $1.type) yyerror("conflicting type");
		if ($8.type > 9) yyerror("no appropriate return command found");
		else if ($8.type != $1.type) yyerror("conflicting return type");	
	}
	| VOID IDENTIFIER '(' parameter_list ')'  '{' declarations statements'}' {
		if(check_function($2) == -1) yyerror(concat("undeclared function ", $2));
		if (check_function($2) != TY_void) yyerror("conflicting type");
		if ($8.type < 10 && $8.type != TY_void) yyerror("conflicting return type");
	}
;

/*
<statement> ::= ;|<expression>;|{(<statement>) * }|if(<expression>)<statement>[else<statement>]
	|[<id>:]for([<expression>];[<expression>];[<expression>])<statement>
	|continue[<id>];|break[<id>];|return[<expression>];
*/
statements
	: statement statements {$$.type = $2.type;}
	| statement {$$.type = $1.type;}
	|
;

statement
	: ';'
	| expression ';' 
	| '{' statements '}' {$$.type=$2.type;}
	| RETURN expression ';' {$$.type = $2.type;}
	| RETURN ';' 
	| BREAK IDENTIFIER ';'
	| BREAK ';'
	| CONTINUE IDENTIFIER ';'
	| CONTINUE ';'
	| if_statement
	| for_statement
	| IDENTIFIER ':' for_statement
;

if_statement
	: IF '(' expression ')' statement {if ($3.type != TY_bool) yyerror("type mismatch: bool expected"); }
	| IF '(' expression ')' statement ELSE statement {if ($3.type != TY_bool) yyerror("type mismatch: bool expected");}
;

for_statement
	: FOR for_parameters statement
;

for_parameters
	: '(' ';' ';' ')'
	| '(' expression ';' ';' ')'
	| '(' expression ';' expression ';' ')'
	| '(' expression ';' expression ';' expression ')'
	| '(' ';' expression ';' ')'
	| '(' ';' expression ';' expression')'
	| '(' ';' ';' expression ')'
;

/*
<expression> ::= <id>|(<expression>)|true|false|NULL|<int-const>|<char-const>|<double-const>
	|<string-literal>|[<id>]([<expression_list>])|<expression>[<expression>]
	|<binary_operator><expression>|<expression><binary_operator><expression>
	|<binary_assign_operator><expression>|<expression><binary_assign_operator>
	|<expression><binary_assignment_operator><expression>|(<datatype>)<expression>
	|<expression>?<expression>:<expression>|new<datatype>[[<expression>]]|delete<expression>
*/
expression
	: IDENTIFIER {
		if(check_variable($1) == -1) yyerror(concat("undeclared variable ", $1));
		else $$.type = check_variable($1);
	}
	| '(' expression ')' 
	| TRUE {$$.type = TY_bool;}
	| FALSE {$$.type = TY_bool;}
	| NIL
	| I_CONSTANT {$$.type = TY_int;} 
	| D_CONSTANT {$$.type = TY_double;}
	| C_CONSTANT {$$.type = TY_char;}
	| STRING_LITERAL {$$.type = TY_char_ptr;}
	| IDENTIFIER '(' expression_list ')'{ if(check_function($1) == -1) yyerror(concat("undeclared function ", $1)); }
	| expression '[' expression ']' { if ($3.type != TY_int) yyerror("type mismatch: int expected"); }
	| unary_op expression {
                //printf("%d \n",$2.type);
		if (!strcmp($1,"+") || !strcmp($1,"-")) {
			if ($2.type == TY_int || $2.type == TY_double) $$.type = $2.type;	
			else yyerror("type mismatch: numeric type expected");
		}
		if (!strcmp($1,"!")) {
			if ($2.type == TY_bool) $$.type = TY_bool;	
			else yyerror("type mismatch: bool expected");
		}
	}
	| expression binary_op expression {
                 //printf("%d %d %d\n",$1.type, $3.type,line_no);
		if (!strcmp($2,"+") || !strcmp($2,"-") || !strcmp($2,"*") || !strcmp($2,"/")) {
			if ($1.type == TY_int)
				if ($3.type == TY_int) 
					$$.type = TY_int;
				else if ($3.type == TY_double) 
					$$.type = TY_double;
				else 
					yyerror("type mismatch: numeric type expected");
			else if ($1.type == TY_double)
				if ($3.type == TY_int) 
					$$.type = TY_double;
				else if ($3.type == TY_double) 
					$$.type = TY_double;
				else 
					yyerror("type mismatch: numeric type expected");
			else yyerror("type mismatch: numeric type expected");
		}
		else if (!strcmp($2,"%")) {
			if ($1.type == TY_int && $3.type == TY_int)
				$$.type = TY_int;
			else
				yyerror("type mismatch");
		}
		else if (!strcmp($2,"<") || !strcmp($2,">")  || !strcmp($2,"<=")  || !strcmp($2,">=") || !strcmp($2,"==")) {
			if (($1.type != TY_int && $1.type != TY_double) || ($3.type != TY_int && $3.type != TY_double))
				yyerror("type mismatch");
			else 
				$$.type = TY_bool;
		}
	}
	| unary_assign_op expression {
		if ($2.type != TY_bool)
			$$.type = $2.type;
		else 
			yyerror("type mismatch: numeric type expected");
	}
	| expression unary_assign_op {
		if ($1.type != TY_bool)
			$$.type = $1.type;
		else 
			yyerror("type mismatch: numeric type expected");
	}
	| expression binary_assign_op expression {
		if ($1.type != $3.type)
			yyerror("type mismatch");
		else 
			$$.type = $3.type;
	}
	| '(' data_type ')' expression {$$.type = $2.type;}
	| expression '?' expression ':' expression
	| NEW data_type
	| NEW data_type '[' expression ']' {
		if ($4.type != TY_int)
			yyerror("type mismatch: int expected");
	}
	| DELETE expression
;

// <expression_list> ::= <expression>(,<expression>) *
expression_list
	: expression_list ',' expression {$$.type = $3.type;}
	| expression {$$.type = $1.type;}
	|
;

// <const_expression> ::= <expression>
const_expression
	: expression {$$.type = $1.type;}
;

// <const_expression> ::= <expression>
unary_op
	: '&' 
	| '*' 
	| '+' 
	| '-' 
	| '!' 
;

// <binary_operator> ::= *|/|%|+|-|<|>|<=|>=|==|!=|&&||||,
binary_op
	: '*' 
	| '/' 
	| '%' 
	| '+'
	| '-' 
	| '<' 
	| '>' 
	| LE_OP  
	| GE_OP 
	| EQ_OP 
	| NE_OP 
	| AND_OP 
	| OR_OP 
	| ',' 
;

// <unary_assign_op> ::= ++|--
unary_assign_op
	: INC_OP 
	| DEC_OP 
;

// <binary_assign_op> ::= ++|--
binary_assign_op
	: '=' 
	| MUL_ASSIGN 
	| DIV_ASSIGN 
	| MOD_ASSIGN 
	| ADD_ASSIGN 
	| SUB_ASSIGN 
;
%%

void insert_variable(char* declaration, char* variable)
{
	int i;
	char* type = strtok(declaration," ");
	for(i=0; strcmp(variables[i].variable, "") !=0; i++);

	if (!strcmp(type,"char*")) variables[i].type = TY_char_ptr;
	if (!strcmp(type,"int*")) variables[i].type = TY_int_ptr;
	if (!strcmp(type,"bool*")) variables[i].type = TY_bool_ptr;
	if (!strcmp(type,"double*")) variables[i].type = TY_double_ptr;
	if (!strcmp(type,"char")) variables[i].type = TY_char;
	if (!strcmp(type,"int")) variables[i].type = TY_int;
	if (!strcmp(type,"double")) variables[i].type = TY_double;
	if (!strcmp(type,"bool")) variables[i].type = TY_bool;	

	strcpy(variables[i].variable, variable);
	variables[i].kind=0;
}

void insert_function(char* declaration, char* variable)
{
	int i;
	char* type = strtok(declaration," ");
	for(i=0; strcmp(variables[i].variable, "") !=0; i++);
	
	if (!strcmp(type,"char*")) variables[i].type = TY_char_ptr;
	if (!strcmp(type,"int*")) variables[i].type = TY_int_ptr;
	if (!strcmp(type,"bool*")) variables[i].type = TY_bool_ptr;
	if (!strcmp(type,"double*")) variables[i].type = TY_double_ptr;
	if (!strcmp(type,"char")) variables[i].type = TY_char;
	if (!strcmp(type,"int")) variables[i].type = TY_int;
	if (!strcmp(type,"double")) variables[i].type = TY_double;
	if (!strcmp(type,"bool")) variables[i].type = TY_bool;
	if (!strcmp(type,"void")) variables[i].type = TY_void;
	
	strcpy(variables[i].variable, variable);
	variables[i].kind=1;
}

void dump_variables()
{
	int i;
	for(i=0; strcmp(variables[i].variable, "") !=0; i++)
	{
		printf("%c - %s - %d\n", variables[i].type, variables[i].variable, variables[i].kind);
	}
}

int check_variable(char* variable)
{
	int i;
	for(i=0; strcmp(variables[i].variable, "") !=0; i++)
	{
		if(strcmp(variables[i].variable, variable) == 0 && variables[i].kind==0)
		{
			return variables[i].type;
		}
	}
	return -1;
}

int check_function(char* variable)
{
	int i;
	for(i=0; strcmp(variables[i].variable, "") !=0; i++)
	{
		if(strcmp(variables[i].variable, variable) == 0 && variables[i].kind==1)
		{

			return variables[i].type;
		}
	}
	return -1;
}

void yyerror(const char *s)
{
	printf(ANSI_COLOR_RED "[-]Error: " ANSI_COLOR_RESET "'%s'\n",s);
	printf("\tat line %d ", line_no);
	printf("near " ANSI_COLOR_CYAN "'%s'" ANSI_COLOR_RESET "\n", linebuf[line_no]);

	number_of_errors++;
}
