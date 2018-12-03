/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    D_CONSTANT = 260,
    C_CONSTANT = 261,
    STRING_LITERAL = 262,
    PTR_OP = 263,
    INC_OP = 264,
    DEC_OP = 265,
    LEFT_OP = 266,
    RIGHT_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    LEFT_ASSIGN = 279,
    RIGHT_ASSIGN = 280,
    AND_ASSIGN = 281,
    XOR_ASSIGN = 282,
    OR_ASSIGN = 283,
    BOOL = 284,
    CHAR = 285,
    INT = 286,
    DOUBLE = 287,
    VOID = 288,
    BYREF = 289,
    IF = 290,
    ELSE = 291,
    FOR = 292,
    CONTINUE = 293,
    BREAK = 294,
    RETURN = 295,
    TRUE = 296,
    FALSE = 297,
    NIL = 298,
    NEW = 299,
    DELETE = 300
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define I_CONSTANT 259
#define D_CONSTANT 260
#define C_CONSTANT 261
#define STRING_LITERAL 262
#define PTR_OP 263
#define INC_OP 264
#define DEC_OP 265
#define LEFT_OP 266
#define RIGHT_OP 267
#define LE_OP 268
#define GE_OP 269
#define EQ_OP 270
#define NE_OP 271
#define AND_OP 272
#define OR_OP 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define LEFT_ASSIGN 279
#define RIGHT_ASSIGN 280
#define AND_ASSIGN 281
#define XOR_ASSIGN 282
#define OR_ASSIGN 283
#define BOOL 284
#define CHAR 285
#define INT 286
#define DOUBLE 287
#define VOID 288
#define BYREF 289
#define IF 290
#define ELSE 291
#define FOR 292
#define CONTINUE 293
#define BREAK 294
#define RETURN 295
#define TRUE 296
#define FALSE 297
#define NIL 298
#define NEW 299
#define DELETE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

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

#line 254 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    62,    57,     2,
      51,    52,    48,    58,    47,    59,     2,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    46,
      63,    65,    64,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    80,    81,    82,    87,    88,    89,    90,
      95,    99,   100,   105,   106,   125,   126,   131,   132,   133,
     134,   139,   140,   146,   147,   152,   153,   154,   159,   160,
     165,   171,   184,   185,   186,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   205,   206,   210,
     214,   215,   216,   217,   218,   219,   220,   232,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   257,
     289,   295,   301,   307,   308,   309,   310,   314,   319,   320,
     321,   331,   332,   333,   334,   335,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     358,   359,   364,   365,   366,   367,   368,   369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "D_CONSTANT",
  "C_CONSTANT", "STRING_LITERAL", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "BOOL", "CHAR", "INT", "DOUBLE", "VOID", "BYREF", "IF", "ELSE", "FOR",
  "CONTINUE", "BREAK", "RETURN", "TRUE", "FALSE", "NIL", "NEW", "DELETE",
  "';'", "','", "'*'", "'['", "']'", "'('", "')'", "'{'", "'}'", "':'",
  "'?'", "'&'", "'+'", "'-'", "'!'", "'/'", "'%'", "'<'", "'>'", "'='",
  "$accept", "program", "declarations", "declaration",
  "variable_declaration", "declaratives", "data_type", "pointers",
  "basic_data_type", "declarative", "function_declaration",
  "parameter_list", "parameter", "function_definition", "statements",
  "statement", "if_statement", "for_statement", "for_parameters",
  "expression", "expression_list", "unary_op", "binary_op",
  "unary_assign_op", "binary_assign_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    44,    42,    91,
      93,    40,    41,   123,   125,    58,    63,    38,    43,    45,
      33,    47,    37,    60,    62,    61
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -6

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -89,   -89,   -89,   -89,   -89,    12,    14,    11,   -89,
      15,   -11,   -89,   -89,   -12,   -89,   -89,   144,   -22,    -8,
      20,   -11,   -89,    29,   -89,    49,    29,   -89,    59,   -89,
      69,    65,    18,    25,    26,    23,    28,   -89,    76,   -89,
     -37,    29,   -89,   -23,   -89,   -89,   204,   -89,   -89,   204,
     262,   262,    -3,   -89,   -89,   -89,   -89,   -89,   -89,    32,
      34,    -1,     4,   350,   -89,   -89,   -89,    69,   552,   -89,
     -89,   320,   262,   -89,   -89,   -89,   -89,    33,   262,   -89,
     -89,   604,   552,   552,    35,   552,    53,   552,   378,   262,
      40,   -89,    46,   -89,    43,   -89,   624,    47,  1081,    55,
     681,    41,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   552,   552,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   552,   -89,   552,
    1081,  1081,   -89,  1081,   -21,   -89,   700,   408,   757,   -89,
     -89,   -89,   -89,   552,   552,   -89,   -89,   776,   833,  1081,
    1081,   552,   -89,   262,   436,   853,   466,   910,  1081,   -89,
     552,  1081,    72,   -89,   929,   494,    58,   986,   -89,  1081,
     262,   -89,   -89,  1005,   -89,   524,   -89,   -89,   -89,  1062,
     -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    19,    18,    17,    20,     0,     0,     0,     6,
       0,    13,     7,     8,     0,     1,     2,     0,    21,     0,
      12,    16,    14,    27,     3,     0,    27,    10,     0,    15,
       0,     0,     0,    26,     0,     0,    21,    11,     0,    28,
       0,    27,    22,     0,    29,    24,     0,    25,    23,     0,
      34,    34,    57,    62,    63,    64,    65,   100,   101,     0,
       0,     0,     0,     0,    59,    60,    61,     0,     0,    35,
      82,     0,    34,    81,    83,    84,    85,     0,    33,    44,
      45,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,    43,     0,    41,    57,    39,     0,    75,    77,     0,
       0,     0,    31,    32,    93,    94,    95,    96,    97,    98,
     103,   104,   105,   106,   107,    36,    99,    86,     0,     0,
      89,    90,    87,    88,    91,    92,   102,     0,    71,     0,
      68,    70,    30,    79,     0,    46,     0,     0,     0,    49,
      42,    40,    38,     0,     0,    58,    37,     0,     0,    69,
      72,     0,    66,     0,     0,     0,     0,     0,    73,    67,
       0,    78,    47,    50,     0,     0,     0,     0,    76,    74,
       0,    56,    54,     0,    51,     0,    48,    55,    52,     0,
      53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,     0,   105,   -89,    85,   -20,    93,   -89,   -89,
     -89,   -13,   -89,   -89,     6,   -88,   -89,    30,   -89,   -63,
     -89,   -89,   -89,   -27,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    16,    17,     9,    19,    10,    22,    11,    20,
      12,    32,    33,    13,    77,    78,    79,    80,    89,    81,
     134,    82,   127,    83,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,   139,    90,    31,     1,    98,    31,    92,   100,    45,
      38,    -5,     1,    35,    15,    14,    46,    24,    18,   130,
     131,    31,   133,    48,   136,   138,   151,    25,    47,    26,
      49,   152,     2,     3,     4,     5,     6,    21,    27,    23,
       2,     3,     4,     5,     6,    91,    50,    97,    85,    51,
      93,    99,    86,    34,   128,   147,   148,    84,     2,     3,
       4,     5,    36,    30,   149,   162,   150,    28,    39,   128,
      40,   128,    41,   128,   155,    43,    42,    25,   101,    44,
     157,   158,   176,    87,   103,    88,   140,   102,   161,   132,
      60,   164,   141,   167,    85,   146,   143,   169,     2,     3,
       4,     5,   173,   128,   128,     8,   128,   144,   170,   128,
     174,   128,   179,    37,    29,     0,   135,     0,     0,     0,
     128,   128,   128,   128,     0,     0,     0,     0,   128,     0,
     128,   128,     0,     0,   128,     0,     0,   128,     0,     0,
     128,     0,   128,     0,    -4,     1,   128,    -4,    -4,    -4,
      -4,    -4,   128,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,     0,     0,    -4,     0,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,     1,     0,    -5,    -5,    -5,
      -5,    -5,     0,    -5,    -5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     0,    -5,
       0,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,     0,    -5,     0,     0,    -5,     0,    -5,    -5,     0,
       0,    -5,    -5,    -5,    -5,    52,    53,    54,    55,    56,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,     0,     0,    71,     0,    72,     0,     0,     0,    73,
      74,    75,    76,    94,    53,    54,    55,    56,     0,    57,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,    94,    53,    54,    55,    56,     0,    57,
      58,    64,    65,    66,    67,    68,     0,     0,    70,     0,
       0,    71,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    94,    53,    54,    55,    56,     0,    57,    58,     0,
       0,    64,    65,    66,    67,    68,    95,     0,    70,     0,
       0,    71,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    94,    53,    54,    55,    56,     0,    57,    58,    64,
      65,    66,    67,    68,   137,     0,    70,     0,     0,    71,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    94,
      53,    54,    55,    56,     0,    57,    58,     0,     0,    64,
      65,    66,    67,    68,   154,     0,    70,     0,     0,    71,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    94,
      53,    54,    55,    56,     0,    57,    58,    64,    65,    66,
      67,    68,     0,     0,    70,     0,     0,    71,   163,     0,
       0,     0,     0,    73,    74,    75,    76,    94,    53,    54,
      55,    56,     0,    57,    58,     0,     0,    64,    65,    66,
      67,    68,   166,     0,    70,     0,     0,    71,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    94,    53,    54,
      55,    56,     0,    57,    58,    64,    65,    66,    67,    68,
       0,     0,    70,     0,     0,    71,   172,     0,     0,     0,
       0,    73,    74,    75,    76,    94,    53,    54,    55,    56,
       0,    57,    58,     0,     0,    64,    65,    66,    67,    68,
       0,     0,    70,     0,     0,    71,   178,     0,     0,     0,
       0,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,     0,     0,
      70,     0,     0,    71,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    57,    58,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,    57,    58,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
     119,     0,   120,   121,     0,   122,   123,   124,   125,   126,
     142,   116,   117,   118,     0,     0,     0,     0,     0,     0,
     119,     0,   120,   121,     0,   122,   123,   124,   125,   126,
      57,    58,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,    57,
      58,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   116,   117,
     118,     0,     0,   145,     0,     0,     0,   119,     0,   120,
     121,     0,   122,   123,   124,   125,   126,   116,   117,   118,
       0,     0,   153,     0,     0,     0,   119,     0,   120,   121,
       0,   122,   123,   124,   125,   126,    57,    58,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,    57,    58,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,   156,   116,   117,   118,     0,     0,     0,
       0,     0,     0,   119,     0,   120,   121,     0,   122,   123,
     124,   125,   126,   116,   117,   118,   159,     0,     0,     0,
       0,     0,   119,     0,   120,   121,     0,   122,   123,   124,
     125,   126,    57,    58,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,    57,    58,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
     116,   117,   118,     0,     0,     0,     0,     0,   160,   119,
       0,   120,   121,     0,   122,   123,   124,   125,   126,   165,
     116,   117,   118,     0,     0,     0,     0,     0,     0,   119,
       0,   120,   121,     0,   122,   123,   124,   125,   126,    57,
      58,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,    57,    58,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   116,   117,   118,
     168,     0,     0,     0,     0,     0,   119,     0,   120,   121,
       0,   122,   123,   124,   125,   126,   116,   117,   118,     0,
       0,   171,     0,     0,     0,   119,     0,   120,   121,     0,
     122,   123,   124,   125,   126,    57,    58,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,     0,    57,    58,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,     0,   175,   116,   117,   118,     0,     0,     0,     0,
       0,     0,   119,     0,   120,   121,     0,   122,   123,   124,
     125,   126,   116,   117,   118,     0,     0,   177,     0,     0,
       0,   119,     0,   120,   121,     0,   122,   123,   124,   125,
     126,    57,    58,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,     0,     0,
      57,    58,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   116,
     117,   118,     0,     0,   180,     0,     0,     0,   119,     0,
     120,   121,     0,   122,   123,   124,   125,   126,   116,   117,
     118,     0,     0,     0,     0,     0,     0,   119,     0,   120,
     121,     0,   122,   123,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
      63,    89,     3,    23,     1,    68,    26,     3,    71,    46,
      30,     0,     1,    26,     0,     3,    53,    17,     3,    82,
      83,    41,    85,    46,    87,    88,    47,    49,    41,    51,
      53,    52,    29,    30,    31,    32,    33,    48,    46,    51,
      29,    30,    31,    32,    33,    46,    46,    67,    51,    49,
      46,    71,    55,     4,    81,   118,   119,    51,    29,    30,
      31,    32,     3,    34,   127,   153,   129,    47,     3,    96,
      52,    98,    47,   100,   137,    52,    50,    49,    72,     3,
     143,   144,   170,    51,    78,    51,    46,    54,   151,    54,
      37,   154,    46,   156,    51,    54,    49,   160,    29,    30,
      31,    32,   165,   130,   131,     0,   133,    52,    36,   136,
      52,   138,   175,    28,    21,    -1,    86,    -1,    -1,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   155,    -1,
     157,   158,    -1,    -1,   161,    -1,    -1,   164,    -1,    -1,
     167,    -1,   169,    -1,     0,     1,   173,     3,     4,     5,
       6,     7,   179,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      -1,    57,    58,    59,    60,     1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    51,    -1,    53,    54,    -1,
      -1,    57,    58,    59,    60,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      58,    59,    60,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,     3,     4,     5,     6,     7,    -1,     9,
      10,    41,    42,    43,    44,    45,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,     3,     4,     5,     6,     7,    -1,     9,    10,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,     3,
       4,     5,     6,     7,    -1,     9,    10,    41,    42,    43,
      44,    45,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,     3,     4,     5,
       6,     7,    -1,     9,    10,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    61,    62,    63,    64,    65,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    61,    62,    63,    64,    65,
       9,    10,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,
      59,    -1,    61,    62,    63,    64,    65,    47,    48,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    65,     9,    10,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,    62,
      63,    64,    65,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    62,    63,
      64,    65,     9,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    63,    64,    65,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    -1,    61,    62,    63,    64,    65,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,     9,    10,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    65,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,
      61,    62,    63,    64,    65,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    61,    62,    63,
      64,    65,    47,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    56,    -1,    58,    59,    -1,    61,    62,    63,    64,
      65,     9,    10,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
       9,    10,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,    -1,
      58,    59,    -1,    61,    62,    63,    64,    65,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    -1,    61,    62,    63,    64,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    29,    30,    31,    32,    33,    67,    69,    70,
      72,    74,    76,    79,     3,     0,    68,    69,     3,    71,
      75,    48,    73,    51,    68,    49,    51,    46,    47,    73,
      34,    72,    77,    78,     4,    77,     3,    71,    72,     3,
      52,    47,    50,    52,     3,    46,    53,    77,    46,    53,
      68,    68,     3,     4,     5,     6,     7,     9,    10,    35,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    51,    53,    57,    58,    59,    60,    80,    81,    82,
      83,    85,    87,    89,    80,    51,    55,    51,    51,    84,
       3,    46,     3,    46,     3,    46,    85,    72,    85,    72,
      85,    80,    54,    80,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    46,    47,    48,    49,    56,
      58,    59,    61,    62,    63,    64,    65,    88,    89,    90,
      85,    85,    54,    85,    86,    83,    85,    46,    85,    81,
      46,    46,    46,    49,    52,    52,    54,    85,    85,    85,
      85,    47,    52,    52,    46,    85,    46,    85,    85,    50,
      55,    85,    81,    52,    85,    46,    46,    85,    50,    85,
      36,    52,    52,    85,    52,    46,    81,    52,    52,    85,
      52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    90,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     1,     1,     1,     1,
       3,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     3,     1,     0,     2,     3,
       9,     9,     2,     1,     0,     1,     2,     3,     3,     2,
       3,     2,     3,     2,     1,     1,     3,     5,     7,     3,
       4,     5,     6,     7,     5,     6,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     3,
       2,     2,     3,     4,     5,     2,     5,     2,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 13:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.exp).type = (yyvsp[0].exp).type;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "parser.y" /* yacc.c:1646  */
    {
			switch((yyvsp[-1].exp).type){
				case TY_int:
					(yyval.exp).type = TY_int_ptr;
					break;				
				case TY_char:
					(yyval.exp).type = TY_char_ptr;
					break;				
				case TY_bool:
					(yyval.exp).type = TY_bool_ptr;
					break;			
				case TY_double:
					(yyval.exp).type = TY_double_ptr;
					break;
			}
	}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_int;}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_char;}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_bool;}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_double;}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "parser.y" /* yacc.c:1646  */
    { insert_variable(linebuf[line_no] ,(yyvsp[0].str)); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "parser.y" /* yacc.c:1646  */
    { insert_variable(linebuf[line_no] ,(yyvsp[-3].str));}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1646  */
    { insert_function(linebuf[line_no] ,(yyvsp[-4].str)); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "parser.y" /* yacc.c:1646  */
    { insert_function(linebuf[line_no] ,(yyvsp[-4].str)); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 165 "parser.y" /* yacc.c:1646  */
    {
		if(check_function((yyvsp[-7].str)) == -1) yyerror(concat("undeclared function ", (yyvsp[-7].str)));
		if (check_function((yyvsp[-7].str)) != (yyvsp[-8].exp).type) yyerror("conflicting type");
		if ((yyvsp[-1].exp).type > 9) yyerror("no appropriate return command found");
		else if ((yyvsp[-1].exp).type != (yyvsp[-8].exp).type) yyerror("conflicting return type");	
	}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "parser.y" /* yacc.c:1646  */
    {
		if(check_function((yyvsp[-7].str)) == -1) yyerror(concat("undeclared function ", (yyvsp[-7].str)));
		if (check_function((yyvsp[-7].str)) != TY_void) yyerror("conflicting type");
		if ((yyvsp[-1].exp).type < 10 && (yyvsp[-1].exp).type != TY_void) yyerror("conflicting return type");
	}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[0].exp).type;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[0].exp).type;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type=(yyvsp[-1].exp).type;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[-1].exp).type;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 205 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[-2].exp).type != TY_bool) yyerror("type mismatch: bool expected"); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 206 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[-4].exp).type != TY_bool) yyerror("type mismatch: bool expected");}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 232 "parser.y" /* yacc.c:1646  */
    {
		if(check_variable((yyvsp[0].str)) == -1) yyerror(concat("undeclared variable ", (yyvsp[0].str)));
		else (yyval.exp).type = check_variable((yyvsp[0].str));
	}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_bool;}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_bool;}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_int;}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_double;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_char;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = TY_char_ptr;}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 244 "parser.y" /* yacc.c:1646  */
    { if(check_function((yyvsp[-3].str)) == -1) yyerror(concat("undeclared function ", (yyvsp[-3].str))); }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].exp).type != TY_int) yyerror("type mismatch: int expected"); }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "parser.y" /* yacc.c:1646  */
    {
                //printf("%d \n",$2.type);
		if (!strcmp((yyvsp[-1].str),"+") || !strcmp((yyvsp[-1].str),"-")) {
			if ((yyvsp[0].exp).type == TY_int || (yyvsp[0].exp).type == TY_double) (yyval.exp).type = (yyvsp[0].exp).type;	
			else yyerror("type mismatch: numeric type expected");
		}
		if (!strcmp((yyvsp[-1].str),"!")) {
			if ((yyvsp[0].exp).type == TY_bool) (yyval.exp).type = TY_bool;	
			else yyerror("type mismatch: bool expected");
		}
	}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 257 "parser.y" /* yacc.c:1646  */
    {
                 //printf("%d %d %d\n",$1.type, $3.type,line_no);
		if (!strcmp((yyvsp[-1].str),"+") || !strcmp((yyvsp[-1].str),"-") || !strcmp((yyvsp[-1].str),"*") || !strcmp((yyvsp[-1].str),"/")) {
			if ((yyvsp[-2].exp).type == TY_int)
				if ((yyvsp[0].exp).type == TY_int) 
					(yyval.exp).type = TY_int;
				else if ((yyvsp[0].exp).type == TY_double) 
					(yyval.exp).type = TY_double;
				else 
					yyerror("type mismatch: numeric type expected");
			else if ((yyvsp[-2].exp).type == TY_double)
				if ((yyvsp[0].exp).type == TY_int) 
					(yyval.exp).type = TY_double;
				else if ((yyvsp[0].exp).type == TY_double) 
					(yyval.exp).type = TY_double;
				else 
					yyerror("type mismatch: numeric type expected");
			else yyerror("type mismatch: numeric type expected");
		}
		else if (!strcmp((yyvsp[-1].str),"%")) {
			if ((yyvsp[-2].exp).type == TY_int && (yyvsp[0].exp).type == TY_int)
				(yyval.exp).type = TY_int;
			else
				yyerror("type mismatch");
		}
		else if (!strcmp((yyvsp[-1].str),"<") || !strcmp((yyvsp[-1].str),">")  || !strcmp((yyvsp[-1].str),"<=")  || !strcmp((yyvsp[-1].str),">=") || !strcmp((yyvsp[-1].str),"==")) {
			if (((yyvsp[-2].exp).type != TY_int && (yyvsp[-2].exp).type != TY_double) || ((yyvsp[0].exp).type != TY_int && (yyvsp[0].exp).type != TY_double))
				yyerror("type mismatch");
			else 
				(yyval.exp).type = TY_bool;
		}
	}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 289 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].exp).type != TY_bool)
			(yyval.exp).type = (yyvsp[0].exp).type;
		else 
			yyerror("type mismatch: numeric type expected");
	}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 295 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].exp).type != TY_bool)
			(yyval.exp).type = (yyvsp[-1].exp).type;
		else 
			yyerror("type mismatch: numeric type expected");
	}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 301 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].exp).type != (yyvsp[0].exp).type)
			yyerror("type mismatch");
		else 
			(yyval.exp).type = (yyvsp[0].exp).type;
	}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[-2].exp).type;}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 310 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].exp).type != TY_int)
			yyerror("type mismatch: int expected");
	}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[0].exp).type;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.exp).type = (yyvsp[0].exp).type;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1977 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 371 "parser.y" /* yacc.c:1906  */


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
