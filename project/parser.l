OCTAL   [0-7]
DIGIT   [0-9]
NON_ZERO  [1-9]
LITERAL   [a-zA-Z_]
ALPHARITHMETIC   [a-zA-Z_0-9]
HEX   [a-fA-F0-9]
HEX_PREFIX  (0[xX])
E   ([Ee][+-]?{DIGIT}+)
P   ([Pp][+-]?{DIGIT}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WHITE_SPACE  [ \t\v\f]

%{

    #include <stdio.h>
    #include <stdlib.h>           
    #include <string.h>     
    #include "y.tab.h"

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

    static void comment();
    static void step();
    char* concat(const char *s1, const char *s2);

    int number_of_errors=0;
    int line_no=1;
    char linebuf[FILE_LENGTH][LINE_LENGTH];

    // Extern
    extern void yyerror(const char *); 
    extern void dump_variables();
%}

%%
"/*"             	{ step();  comment(); }
"//".*       		{ step();  /* consume //-comment */ }
"break"			{ step(); yylval.str = strdup(yytext); return(BREAK); }
"char"			{ step(); yylval.str = strdup(yytext); return(CHAR); }
"continue"		{ step(); yylval.str = strdup(yytext); return(CONTINUE); }
"double"		{ step(); yylval.str = strdup(yytext); return(DOUBLE); }
"else"			{ step(); yylval.str = strdup(yytext); return(ELSE); }
"for"			{ step(); yylval.str = strdup(yytext); return(FOR); }
"if"			{ step(); yylval.str = strdup(yytext); return(IF); }
"int"			{ step(); yylval.str = strdup(yytext); return(INT); }
"return"		{ step(); yylval.str = strdup(yytext); return(RETURN); }
"void"			{ step(); yylval.str = strdup(yytext); return(VOID); }
"bool"         		{ step(); yylval.str = strdup(yytext); return BOOL; }
"byref"         	{ step(); yylval.str = strdup(yytext); return BYREF; }
"true"          	{ step(); yylval.str = strdup(yytext); return TRUE; }
"false"         	{ step(); yylval.str = strdup(yytext); return FALSE; }
"new"           	{ step(); yylval.str = strdup(yytext); return NEW; }
"delete"        	{ step(); yylval.str = strdup(yytext); return DELETE; }
"null"        		{ step(); yylval.str = strdup(yytext); return NIL; }
"\n"            	{ step(); line_no++;}
"\t"            	{ step(); }
"\v"            	{ step(); }
"\f"            	{ step(); }

{LITERAL}{ALPHARITHMETIC}*			{step(); yylval.str = strdup(yytext); return IDENTIFIER;}

{HEX_PREFIX}{HEX}+{IS}?				{ step(); yylval.str = strdup(yytext); return I_CONSTANT; }
{NON_ZERO}{DIGIT}*{IS}?				{ step(); yylval.str = strdup(yytext); return I_CONSTANT; }
"0"{OCTAL}*{IS}?				{ step(); yylval.str = strdup(yytext); return I_CONSTANT; }
{CP}?"'"([^'\\]|{ES})+"'"			{ step(); yylval.str = strdup(yytext); return C_CONSTANT; }

{DIGIT}+{E}?					{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }
{DIGIT}*"."{DIGIT}+{E}?				{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }
{DIGIT}+"."{E}?					{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }
{HEX_PREFIX}{HEX}+{P}?				{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }
{HEX_PREFIX}{HEX}*"."{HEX}+{P}?			{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }
{HEX_PREFIX}{HEX}+"."{P}?			{ step(); yylval.str = strdup(yytext); return D_CONSTANT; }

({SP}?\"([^"\\]|{ES})*\"{WHITE_SPACE}*)+	{ step(); yylval.str = strdup(yytext);return STRING_LITERAL; }

">>="			{ step(); yylval.str = strdup(yytext); return RIGHT_ASSIGN; }
"<<="			{ step(); yylval.str = strdup(yytext); return LEFT_ASSIGN; }
"+="			{ step(); yylval.str = strdup(yytext); return ADD_ASSIGN; }
"-="			{ step(); yylval.str = strdup(yytext); return SUB_ASSIGN; }
"*="			{ step(); yylval.str = strdup(yytext); return MUL_ASSIGN; }
"/="			{ step(); yylval.str = strdup(yytext); return DIV_ASSIGN; }
"%="			{ step(); yylval.str = strdup(yytext); return MOD_ASSIGN; }
"&="			{ step(); yylval.str = strdup(yytext); return AND_ASSIGN; }
"^="			{ step(); yylval.str = strdup(yytext); return XOR_ASSIGN; }
"|="			{ step(); yylval.str = strdup(yytext); return OR_ASSIGN; }
">>"			{ step(); yylval.str = strdup(yytext); return RIGHT_OP; }
"<<"			{ step(); yylval.str = strdup(yytext); return LEFT_OP; }
"++"			{ step(); yylval.str = strdup(yytext); return INC_OP; }
"--"			{ step(); yylval.str = strdup(yytext); return DEC_OP; }
"->"			{ step(); yylval.str = strdup(yytext); return PTR_OP; }
"&&"			{ step(); yylval.str = strdup(yytext); return AND_OP; }
"||"			{ step(); yylval.str = strdup(yytext); return OR_OP; }
"<="			{ step(); yylval.str = strdup(yytext); return LE_OP; }
">="			{ step(); yylval.str = strdup(yytext); return GE_OP; }
"=="			{ step(); yylval.str = strdup(yytext); return EQ_OP; }
"!="			{ step(); yylval.str = strdup(yytext); return NE_OP; }
";"			{ step(); yylval.str = strdup(yytext); return ';'; }
("{")			{ step(); yylval.str = strdup(yytext); return '{'; }
("}")			{ step(); yylval.str = strdup(yytext); return '}'; }
","			{ step(); yylval.str = strdup(yytext); return ','; }
":"			{ step(); yylval.str = strdup(yytext); return ':'; }
"="			{ step(); yylval.str = strdup(yytext); return '='; }
"("			{ step(); yylval.str = strdup(yytext); return '('; }
")"			{ step(); yylval.str = strdup(yytext); return ')'; }
("[")			{ step(); yylval.str = strdup(yytext); return '['; }
("]")			{ step(); yylval.str = strdup(yytext); return ']'; }
"."			{ step(); yylval.str = strdup(yytext); return '.'; }
"&"			{ step(); yylval.str = strdup(yytext); return '&'; }
"!"			{ step(); yylval.str = strdup(yytext); return '!'; }
"~"			{ step(); yylval.str = strdup(yytext); return '~'; }
"-"			{ step(); yylval.str = strdup(yytext); return '-'; }
"+"			{ step(); yylval.str = strdup(yytext); return '+'; }
"*"			{ step(); yylval.str = strdup(yytext); return '*'; }
"/"			{ step(); yylval.str = strdup(yytext); return '/'; }
"%"			{ step(); yylval.str = strdup(yytext); return '%'; }
"<"			{ step(); yylval.str = strdup(yytext); return '<'; }
">"			{ step(); yylval.str = strdup(yytext); return '>'; }
"^"			{ step(); yylval.str = strdup(yytext); return '^'; }
"|"			{ step(); yylval.str = strdup(yytext); return '|'; }
"?"			{ step(); yylval.str = strdup(yytext); return '?'; }
{WHITE_SPACE}+		{ step(); }
.					{ /* discard bad characters */ }

%%

int yywrap()        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void step()
{
  ECHO; // print token to output file
  strcat(linebuf[line_no],yytext);
}

static void comment()
{
    int c;
    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;
            if (c == '/') return;
            if (c == 0) break;
        }
    yyerror("unterminated comment");
}

/**
 * Adds to strings
 */
char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1); //+1 for the zero-terminator
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1); //+1 to copy the null-terminator
    return result;
}

int main ( int argc, char **argv  )
{
	++argv; 
	--argc;

	if ( argc > 0 )
		yyin = fopen(argv[0], "r"); // Read from file
	else
		yyin = stdin; // Read from stdin
	yyout = fopen ("output", "w"); // Output file
	
	yyparse(); //Parsing
	
	if(number_of_errors>0){
		printf(ANSI_COLOR_RED "[-] %d errors detected! \n" ANSI_COLOR_RESET, number_of_errors);
	} else {
		printf("[+] No errors detected\n");
	}

	return number_of_errors;
}
