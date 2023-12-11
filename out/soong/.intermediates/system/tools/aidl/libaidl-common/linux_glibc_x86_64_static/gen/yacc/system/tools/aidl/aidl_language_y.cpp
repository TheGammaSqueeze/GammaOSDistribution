// A Bison parser, made by GNU Bison 3.5.

// Skeleton implementation for Bison GLR parsers in C

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/* C GLR parser skeleton written by Paul Hilfinger.  */

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.cc"

/* Pure parsers.  */
#define YYPURE 1






// First part of user prologue.
#line 17 "system/tools/aidl/aidl_language_y.yy"

#include "aidl_language.h"
#include "parser.h"
#include "aidl_language_y.h"
#include "logging.h"
#include <android-base/parseint.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(yy::parser::semantic_type *, yy::parser::location_type *, void *);

AidlLocation loc(const yy::parser::location_type& begin, const yy::parser::location_type& end) {
  AIDL_FATAL_IF(begin.begin.filename != begin.end.filename, AIDL_LOCATION_HERE);
  AIDL_FATAL_IF(begin.end.filename != end.begin.filename, AIDL_LOCATION_HERE);
  AIDL_FATAL_IF(end.begin.filename != end.end.filename, AIDL_LOCATION_HERE);
  AidlLocation::Point begin_point {
    .line = begin.begin.line,
    .column = begin.begin.column,
  };
  AidlLocation::Point end_point {
    .line = end.end.line,
    .column = end.end.column,
  };
  return AidlLocation(*begin.begin.filename, begin_point, end_point, AidlLocation::Source::EXTERNAL);
}

AidlLocation loc(const yy::parser::location_type& l) {
  return loc(l, l);
}

#define lex_scanner ps->Scanner()


#line 94 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "aidl_language_y.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;

// Second part of user prologue.
#line 139 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
static void yyerror (const yy::parser::location_type *yylocationp, yy::parser& yyparser, Parser* ps, const char* msg);
#line 141 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

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

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX \
  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__)))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 10
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   289
/* YYFAULTYTOK -- Token number (for yychar) that denotes a
   syntax_error thrown from the scanner.  */
#define YYFAULTYTOK (YYMAXUTOK + 1)
/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
   token.  */
#define YYUNDEFTOK  2

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                         \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    52,    39,     2,
      18,    19,    50,    48,    20,    49,    24,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      42,    21,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,    37,    26,    56,     2,     2,     2,
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
      15,    16,    17,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    40,    41,    44,    45,    46,    47,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   187,   187,   207,   208,   212,   215,   224,   225,   239,
     246,   249,   257,   263,   271,   286,   287,   288,   289,   293,
     298,   305,   306,   311,   316,   321,   328,   335,   338,   342,
     346,   352,   356,   364,   369,   375,   384,   385,   387,   389,
     395,   396,   397,   401,   411,   415,   425,   429,   433,   436,
     439,   442,   445,   448,   451,   454,   457,   460,   463,   466,
     469,   472,   475,   478,   481,   484,   487,   490,   493,   496,
     499,   502,   506,   516,   519,   522,   528,   532,   539,   555,
     559,   566,   570,   577,   578,   582,   591,   599,   603,   611,
     621,   637,   641,   648,   649,   653,   657,   663,   673,   677,
     684,   692,   693,   708,   716,   723,   724,   734,   740,   743,
     748,   753,   764,   771,   782,   784,   786
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"package\"", "\"import\"",
  "\"annotation\"", "\"string literal\"", "\"identifier\"",
  "\"interface\"", "\"parcelable\"", "\"oneway\"", "\"enum\"", "\"union\"",
  "\"const\"", "\"char literal\"", "\"float literal\"", "\"hex literal\"",
  "\"int literal\"", "'('", "')'", "','", "'='", "'['", "']'", "'.'",
  "'{'", "'}'", "';'", "\"unrecognized character\"",
  "\"cpp_header (which can also be used as an identifier)\"", "\"in\"",
  "\"inout\"", "\"out\"", "\"true\"", "\"false\"", "LOGICAL_OR",
  "LOGICAL_AND", "'|'", "'^'", "'&'", "EQUALITY", "NEQ", "'<'", "'>'",
  "LEQ", "GEQ", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UNARY_PLUS", "UNARY_MINUS", "'!'", "'~'", "$accept", "document",
  "identifier", "package", "imports", "import", "qualified_name", "decls",
  "decl", "unannotated_decl", "type_params", "optional_type_params",
  "parcelable_decl", "parcelable_members", "variable_decl",
  "interface_decl", "interface_members", "const_expr",
  "constant_value_list", "constant_value_non_empty_list", "constant_decl",
  "enumerator", "enumerators", "enum_decl_body", "enum_decl", "union_decl",
  "method_decl", "arg_non_empty_list", "arg_list", "arg", "non_array_type",
  "type", "type_args", "annotation_list", "parameter", "parameter_list",
  "parameter_non_empty_list", "annotation", "direction", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-182)
#define YYTABLE_NINF (-106)

  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
static const yytype_int16 yypact[] =
{
      52,    50,    97,  -182,  -182,  -182,  -182,   -16,  -182,   114,
      50,  -182,    50,  -182,   120,  -182,   243,  -182,    47,  -182,
     104,     8,    11,   119,    50,    50,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,    50,   112,   121,   117,    99,    50,   124,
     -20,   131,  -182,   134,   137,  -182,  -182,  -182,   152,    50,
      45,   130,    50,  -182,   154,   216,  -182,    50,    25,   149,
     133,  -182,    -7,  -182,  -182,  -182,   156,  -182,   -10,  -182,
    -182,  -182,  -182,  -182,  -182,   191,   216,  -182,  -182,   216,
     216,   216,   216,   157,   329,  -182,   153,  -182,  -182,  -182,
     142,    50,   289,  -182,  -182,    50,  -182,   135,   189,   216,
      54,  -182,   290,   166,   238,   329,   160,   168,  -182,  -182,
    -182,  -182,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
    -182,  -182,   171,    59,  -182,  -182,   157,  -182,   174,  -182,
    -182,  -182,    50,    18,  -182,   329,  -182,  -182,  -182,  -182,
    -182,  -182,   216,   346,   362,   377,   391,   404,   415,   415,
     258,   258,   258,   258,   162,   162,   115,   115,  -182,  -182,
    -182,   161,    73,    32,    36,   100,   181,    50,    50,  -182,
      63,   329,  -182,  -182,  -182,  -182,  -182,  -182,   197,   200,
    -182,    50,  -182,  -182,   203,   205,   216,  -182,    -1,   185,
      73,   140,    71,  -182,    50,   100,   216,   285,  -182,  -182,
    -182,   211,  -182,  -182,   210,   311,  -182,    13,   208,   108,
    -182,  -182,  -182,   219,  -182,   215,  -182
};

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     7,     3,     4,    10,     0,     1,   105,
       0,     6,     0,     8,   105,    12,     0,    11,     0,    13,
     112,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,   106,     9,   108,     0,     0,     0,    21,     0,     0,
      21,     0,   110,     0,   109,    36,    36,    26,     0,     0,
       0,     0,     0,    85,     0,     0,   113,     0,     0,     0,
       0,    19,     0,    27,    23,    36,    80,    81,     0,    27,
      46,    42,    44,    45,    43,     0,    73,    40,    41,     0,
       0,     0,     0,    47,   107,   111,     0,    35,    38,    37,
     101,   105,     0,    33,    25,     0,    22,     0,     0,     0,
       0,    83,     0,     0,     0,    76,     0,    74,    67,    68,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,   105,     0,     0,   105,   105,    97,    20,     0,    24,
      28,    29,   105,     0,    34,    79,    84,    82,    86,    72,
      71,    48,    75,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   101,   103,     0,     0,   105,     0,   105,   105,    30,
       0,    77,   105,   105,    98,   114,   116,   115,    94,     0,
      91,   105,   105,   102,     0,     0,     0,    31,     0,   101,
     104,   105,     0,    96,   105,   105,     0,     0,    99,   105,
      92,     0,    87,    95,     0,     0,    32,     0,     0,     0,
      78,   100,    89,     0,    88,     0,    90
};

  // YYPGOTO[NTERM-NUM].
static const yytype_int16 yypgoto[] =
{
    -182,  -182,    -4,  -182,  -182,  -182,     2,  -182,   223,  -182,
    -182,   198,  -182,   175,  -182,  -182,   -44,   -13,  -182,  -182,
      24,   143,  -182,  -182,  -182,  -182,  -182,  -182,    51,    57,
    -124,   -58,  -181,    -9,   202,  -182,  -182,  -182,  -182
};

  // YYDEFGOTO[NTERM-NUM].
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     3,     9,    13,    83,    14,    15,    26,
      62,    50,    27,    97,   140,    28,    58,    84,   106,   107,
      88,    67,    68,    53,    29,    30,    89,   188,   189,   190,
      90,    91,   173,   174,    42,    43,    44,    31,   192
};

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
static const yytype_int16 yytable[] =
{
      16,   198,    59,     7,    10,    16,    17,   171,    10,    34,
     100,    11,    36,    95,    18,     4,   101,    35,     4,   183,
      39,    98,    49,    20,    37,     4,    86,    40,   217,    41,
    -105,   135,  -105,   183,    51,  -105,    96,     5,  -105,   142,
       5,    20,   184,     4,   142,    61,   208,     5,    66,    92,
      92,    87,   183,    41,  -105,     1,   184,     4,   171,   199,
     221,     4,   104,   105,    20,     5,   108,   109,   110,   111,
      63,    10,    64,   172,    32,   184,   177,   178,  -105,     5,
     146,   176,   133,     5,   196,   171,   145,   132,   143,    92,
     197,   137,   211,   143,   136,  -105,    66,     8,   212,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   191,    12,   -93,
      -2,   141,    33,    10,   172,   200,   141,    38,    48,   223,
     185,   186,   187,   133,   204,   224,   138,    45,   180,   181,
    -105,    49,  -105,   191,    47,   136,    46,   191,  -105,    52,
      86,   172,    55,    56,  -105,    65,  -105,    57,    60,  -105,
      94,   139,  -105,   133,  -105,   127,   128,   129,   133,   133,
     185,   186,   187,   194,   195,    93,   136,    99,  -105,    69,
     130,    10,   133,   207,   131,   149,   151,   203,   152,   175,
      86,   133,   103,   215,  -105,   133,  -105,    70,     4,  -105,
     213,   179,  -105,   182,   193,    71,    72,    73,    74,    75,
     125,   126,   127,   128,   129,   144,    76,   201,  -105,   202,
       5,   205,    70,     4,    77,    78,   206,   209,   218,   219,
      71,    72,    73,    74,    75,   222,   225,    19,    54,    79,
      80,    76,   226,   147,   102,     5,    81,    82,    20,    77,
      78,    21,    22,    23,    24,    25,   214,   150,   210,    85,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,    81,    82,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   138,     0,     0,    20,  -105,     4,  -105,     0,   134,
       0,     0,   135,  -105,   123,   124,   125,   126,   127,   128,
     129,     0,   216,     0,     0,     0,   148,     0,     5,  -105,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   220,     0,
       0,     0,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
       9,   182,    46,     1,    24,    14,    10,   131,    24,     1,
      20,    27,     1,    20,    12,     7,    26,    21,     7,    20,
      24,    65,    42,     5,    22,     7,     1,    25,   209,    33,
       5,    13,     7,    20,    38,    10,    43,    29,    13,    97,
      29,     5,    43,     7,   102,    49,    47,    29,    52,    58,
      59,    26,    20,    57,    29,     3,    43,     7,   182,   183,
      47,     7,    75,    76,     5,    29,    79,    80,    81,    82,
      25,    24,    27,   131,    27,    43,   134,   135,     5,    29,
      26,    22,    91,    29,    21,   209,    99,    91,    97,    98,
      27,    95,    21,   102,    92,    22,   100,     0,    27,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   175,     4,    19,
       0,    97,    18,    24,   182,   183,   102,     8,    29,    21,
      30,    31,    32,   142,   192,    27,     1,    25,   142,   152,
       5,    42,     7,   201,    27,   143,    25,   205,    13,    25,
       1,   209,    21,    19,     5,    25,     7,    20,     6,    10,
      27,    26,    13,   172,    29,    50,    51,    52,   177,   178,
      30,    31,    32,   177,   178,    26,   174,    21,    29,    25,
      27,    24,   191,   196,    42,    19,    26,   191,    20,    18,
       1,   200,     1,   206,     5,   204,     7,     6,     7,    10,
     204,    27,    13,    42,    23,    14,    15,    16,    17,    18,
      48,    49,    50,    51,    52,    26,    25,    20,    29,    19,
      29,    18,     6,     7,    33,    34,    21,    42,    17,    19,
      14,    15,    16,    17,    18,    27,    17,    14,    40,    48,
      49,    25,    27,   100,    69,    29,    55,    56,     5,    33,
      34,     8,     9,    10,    11,    12,   205,    19,   201,    57,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    56,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     1,    -1,    -1,     5,     5,     7,     7,    -1,    10,
      -1,    -1,    13,    13,    46,    47,    48,    49,    50,    51,
      52,    -1,    27,    -1,    -1,    -1,    26,    -1,    29,    29,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
static const yytype_int8 yystos[] =
{
       0,     3,    58,    60,     7,    29,    59,    63,     0,    61,
      24,    27,     4,    62,    64,    65,    90,    59,    63,    65,
       5,     8,     9,    10,    11,    12,    66,    69,    72,    81,
      82,    94,    27,    18,     1,    59,     1,    63,     8,    59,
      63,    59,    91,    92,    93,    25,    25,    27,    29,    42,
      68,    59,    25,    80,    68,    21,    19,    20,    73,    73,
       6,    59,    67,    25,    27,    25,    59,    78,    79,    25,
       6,    14,    15,    16,    17,    18,    25,    33,    34,    48,
      49,    55,    56,    63,    74,    91,     1,    26,    77,    83,
      87,    88,    90,    26,    27,    20,    43,    70,    73,    21,
      20,    26,    70,     1,    74,    74,    75,    76,    74,    74,
      74,    74,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      27,    42,    59,    90,    10,    13,    63,    59,     1,    26,
      71,    77,    88,    90,    26,    74,    26,    78,    26,    19,
      19,    26,    20,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    87,    88,    89,    90,    18,    22,    88,    88,    27,
      59,    74,    42,    20,    43,    30,    31,    32,    84,    85,
      86,    88,    95,    23,    59,    59,    21,    27,    89,    87,
      88,    20,    19,    59,    88,    18,    21,    74,    47,    42,
      86,    21,    27,    59,    85,    74,    27,    89,    17,    19,
      27,    47,    27,    21,    27,    17,    27
};

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    81,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    95
};

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     1,     0,     3,     0,     2,     3,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     1,
       3,     0,     3,     4,     6,     5,     3,     0,     2,     2,
       3,     3,     5,     5,     6,     5,     0,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     0,     1,     2,     1,     3,     7,     3,
       1,     1,     3,     3,     4,     3,     6,     6,     8,     8,
      10,     1,     3,     0,     1,     3,     2,     2,     4,     6,
       8,     1,     4,     1,     3,     0,     2,     3,     0,     1,
       1,     3,     1,     4,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif



/*--------------------.
| Print this symbol.  |
`--------------------*/

static void
yy_symbol_print (FILE *, int yytype, const yy::parser::semantic_type *yyvaluep, const yy::parser::location_type *yylocationp, yy::parser& yyparser, Parser* ps)
{
  YYUSE (yyparser);
  YYUSE (ps);
  yyparser.yy_symbol_print_ (yytype, yyvaluep, yylocationp);
}


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Type, Value, Location, yyparser, ps);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

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
static ptrdiff_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      ptrdiff_t yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return YY_CAST (ptrdiff_t, strlen (yystr));
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers. */
typedef int yyStateNum;

/** Rule numbers. */
typedef int yyRuleNum;

/** Grammar symbol. */
typedef int yySymbol;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  ptrdiff_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  ptrdiff_t yysize;
  ptrdiff_t yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  ptrdiff_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, yyparser, ps, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  return yytoken == YYEMPTY ? "" : yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yySymbol
yygetToken (int *yycharp, yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  yySymbol yytoken;
  YYUSE (yyparser);
  YYUSE (ps);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token: "));
#if YY_EXCEPTIONS
      try
        {
#endif // YY_EXCEPTIONS
          *yycharp = yylex (&yylval, &yylloc, lex_scanner);
#if YY_EXCEPTIONS
        }
      catch (const yy::parser::syntax_error& yyexc)
        {
          YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
          yylloc = yyexc.location;
          yyerror (&yylloc, yyparser, ps, yyexc.what ());
          // Map errors caught in the scanner to the undefined token
          // (YYUNDEFTOK), so that error handling is started.
          // However, record this with this special value of yychar.
          *yycharp = YYFAULTYTOK;
        }
#endif // YY_EXCEPTIONS
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = yytoken = YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (yyparser);
  YYUSE (ps);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, yyparser, ps, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

#if YY_EXCEPTIONS
  typedef yy::parser::syntax_error syntax_error;
  try
  {
#endif // YY_EXCEPTIONS
  switch (yyn)
    {
  case 2:
#line 187 "system/tools/aidl/aidl_language_y.yy"
                         {
    Comments comments;
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.package)) {
      comments = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.package)->GetComments();
    } else if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.imports)->empty()) {
      comments = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.imports)->front()->GetComments();
    }
    ps->SetDocument(std::make_unique<AidlDocument>(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), comments, std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.imports)), std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declarations))));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.package);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.imports);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declarations);
  }
#line 1357 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 3:
#line 207 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token); }
#line 1363 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 4:
#line 208 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token); }
#line 1369 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 5:
#line 212 "system/tools/aidl/aidl_language_y.yy"
   {
    ((*yyvalp).package) = nullptr;
 }
#line 1377 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 6:
#line 215 "system/tools/aidl/aidl_language_y.yy"
                              {
    ((*yyvalp).package) = new AidlPackage(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetComments());
    ps->SetPackage((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
  }
#line 1388 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 7:
#line 224 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).imports) = new std::vector<std::unique_ptr<AidlImport>>(); }
#line 1394 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 8:
#line 226 "system/tools/aidl/aidl_language_y.yy"
  {
    ((*yyvalp).imports) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.imports);
    auto it = std::find_if(((*yyvalp).imports)->begin(), ((*yyvalp).imports)->end(), [&](const auto& i) {
      return (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.import)->GetNeededClass() == i->GetNeededClass();
    });
    if (it == ((*yyvalp).imports)->end()) {
      ((*yyvalp).imports)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.import));
    } else {
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.import);
    }
  }
#line 1410 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 9:
#line 239 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).import) = new AidlImport(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetComments());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
  }
#line 1420 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 10:
#line 246 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1428 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 11:
#line 250 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).token) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
    ((*yyvalp).token)->Append('.');
    ((*yyvalp).token)->Append((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1438 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 12:
#line 258 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).declarations) = new std::vector<std::unique_ptr<AidlDefinedType>>();
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration) != nullptr) {
      ((*yyvalp).declarations)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration));
    }
  }
#line 1448 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 13:
#line 264 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).declarations) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.declarations);
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration) != nullptr) {
      ((*yyvalp).declarations)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration));
    }
  }
#line 1458 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 14:
#line 272 "system/tools/aidl/aidl_language_y.yy"
   {
    ((*yyvalp).declaration) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration);

    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)->size() > 0 && ((*yyvalp).declaration) != nullptr) {
      // copy comments from annotation to decl
      ((*yyvalp).declaration)->SetComments((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)->begin()->GetComments());
      ((*yyvalp).declaration)->Annotate(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)));
    }

    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list);
   }
#line 1474 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 15:
#line 286 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).declaration) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration); }
#line 1480 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 16:
#line 287 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).declaration) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration); }
#line 1486 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 17:
#line 288 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).declaration) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration); }
#line 1492 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 18:
#line 289 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).declaration) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.declaration); }
#line 1498 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 19:
#line 293 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).type_params) = new std::vector<std::string>();
    ((*yyvalp).type_params)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1508 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 20:
#line 298 "system/tools/aidl/aidl_language_y.yy"
                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type_params)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    ((*yyvalp).type_params) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type_params);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1518 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 21:
#line 305 "system/tools/aidl/aidl_language_y.yy"
               { ((*yyvalp).type_params) = nullptr; }
#line 1524 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 22:
#line 306 "system/tools/aidl/aidl_language_y.yy"
                        {
    ((*yyvalp).type_params) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type_params);
  }
#line 1532 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 23:
#line 311 "system/tools/aidl/aidl_language_y.yy"
                                                      {
    ((*yyvalp).declaration) = new AidlParcelable(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetText(), ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetComments(), "", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type_params));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
 }
#line 1542 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 24:
#line 316 "system/tools/aidl/aidl_language_y.yy"
                                                                             {
    ((*yyvalp).declaration) = new AidlStructuredParcelable(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetText(), ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token)->GetComments(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type_params), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
 }
#line 1552 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 25:
#line 321 "system/tools/aidl/aidl_language_y.yy"
                                                  {
    ((*yyvalp).declaration) = new AidlParcelable(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(), ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetComments(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
  }
#line 1564 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 26:
#line 328 "system/tools/aidl/aidl_language_y.yy"
                        {
    ps->AddError();
    ((*yyvalp).declaration) = nullptr;
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
  }
#line 1574 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 27:
#line 335 "system/tools/aidl/aidl_language_y.yy"
               {
    ((*yyvalp).members) = new std::vector<std::unique_ptr<AidlMember>>();
  }
#line 1582 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 28:
#line 338 "system/tools/aidl/aidl_language_y.yy"
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.variable));
    ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members);
  }
#line 1591 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 29:
#line 342 "system/tools/aidl/aidl_language_y.yy"
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constant));
    ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members);
  }
#line 1600 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 30:
#line 346 "system/tools/aidl/aidl_language_y.yy"
                                {
    ps->AddError();
    ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.members);
  }
#line 1609 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 31:
#line 352 "system/tools/aidl/aidl_language_y.yy"
                       {
   ((*yyvalp).variable) = new AidlVariableDeclaration(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText());
   delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
 }
#line 1618 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 32:
#line 356 "system/tools/aidl/aidl_language_y.yy"
                                      {
   // TODO(b/123321528): Support enum type default assignments (TestEnum foo = TestEnum.FOO).
   ((*yyvalp).variable) = new AidlVariableDeclaration(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(),  (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.const_expr));
   delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
 }
#line 1628 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 33:
#line 364 "system/tools/aidl/aidl_language_y.yy"
                                                  {
    ((*yyvalp).declaration) = new AidlInterface(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetComments(), false, ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
  }
#line 1638 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 34:
#line 369 "system/tools/aidl/aidl_language_y.yy"
                                                         {
    ((*yyvalp).declaration) = new AidlInterface(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(),  (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token)->GetComments(), true, ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
  }
#line 1649 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 35:
#line 375 "system/tools/aidl/aidl_language_y.yy"
                                             {
    ps->AddError();
    ((*yyvalp).declaration) = nullptr;
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members);
  }
#line 1660 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 36:
#line 384 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).members) = new std::vector<std::unique_ptr<AidlMember>>(); }
#line 1666 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 37:
#line 386 "system/tools/aidl/aidl_language_y.yy"
  { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members)->push_back(std::unique_ptr<AidlMember>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method))); ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members); }
#line 1672 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 38:
#line 388 "system/tools/aidl/aidl_language_y.yy"
  { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members)->push_back(std::unique_ptr<AidlMember>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constant))); ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members); }
#line 1678 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 39:
#line 389 "system/tools/aidl/aidl_language_y.yy"
                               {
    ps->AddError();
    ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.members);
  }
#line 1687 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 40:
#line 395 "system/tools/aidl/aidl_language_y.yy"
                { ((*yyvalp).const_expr) = AidlConstantValue::Boolean(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), true); }
#line 1693 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 41:
#line 396 "system/tools/aidl/aidl_language_y.yy"
                 { ((*yyvalp).const_expr) = AidlConstantValue::Boolean(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), false); }
#line 1699 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 42:
#line 397 "system/tools/aidl/aidl_language_y.yy"
             {
    ((*yyvalp).const_expr) = AidlConstantValue::Character(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1708 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 43:
#line 401 "system/tools/aidl/aidl_language_y.yy"
            {
    ((*yyvalp).const_expr) = AidlConstantValue::Integral(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    if (((*yyvalp).const_expr) == nullptr) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc))) << "Could not parse integer: "
                << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText();
      ps->AddError();
      ((*yyvalp).const_expr) = AidlConstantValue::Integral(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), "0");
    }
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1723 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 44:
#line 411 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).const_expr) = AidlConstantValue::Floating(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1732 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 45:
#line 415 "system/tools/aidl/aidl_language_y.yy"
            {
    ((*yyvalp).const_expr) = AidlConstantValue::Integral(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    if (((*yyvalp).const_expr) == nullptr) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc))) << "Could not parse hexvalue: "
                << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText();
      ps->AddError();
      ((*yyvalp).const_expr) = AidlConstantValue::Integral(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), "0");
    }
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1747 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 46:
#line 425 "system/tools/aidl/aidl_language_y.yy"
         {
    ((*yyvalp).const_expr) = AidlConstantValue::String(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 1756 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 47:
#line 429 "system/tools/aidl/aidl_language_y.yy"
                  {
    ((*yyvalp).const_expr) = new AidlConstantReference(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
 }
#line 1765 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 48:
#line 433 "system/tools/aidl/aidl_language_y.yy"
                               {
    ((*yyvalp).const_expr) = AidlConstantValue::Array(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<vector<unique_ptr<AidlConstantValue>>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constant_value_list)));
  }
#line 1773 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 49:
#line 436 "system/tools/aidl/aidl_language_y.yy"
                                    {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "||", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1781 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 50:
#line 439 "system/tools/aidl/aidl_language_y.yy"
                                     {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "&&", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1789 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 51:
#line 442 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "|" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1797 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 52:
#line 445 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "^" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1805 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 53:
#line 448 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "&" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1813 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 54:
#line 451 "system/tools/aidl/aidl_language_y.yy"
                                  {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "==", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1821 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 55:
#line 454 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "!=", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1829 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 56:
#line 457 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "<" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1837 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 57:
#line 460 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), ">" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1845 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 58:
#line 463 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "<=", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1853 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 59:
#line 466 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), ">=", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1861 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 60:
#line 469 "system/tools/aidl/aidl_language_y.yy"
                                {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "<<", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1869 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 61:
#line 472 "system/tools/aidl/aidl_language_y.yy"
                                {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), ">>", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1877 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 62:
#line 475 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "+" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1885 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 63:
#line 478 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "-" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1893 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 64:
#line 481 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "*" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1901 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 65:
#line 484 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "/" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1909 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 66:
#line 487 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).const_expr) = new AidlBinaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.const_expr)), "%" , std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1917 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 67:
#line 490 "system/tools/aidl/aidl_language_y.yy"
                                    {
    ((*yyvalp).const_expr) = new AidlUnaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), "+", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1925 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 68:
#line 493 "system/tools/aidl/aidl_language_y.yy"
                                    {
    ((*yyvalp).const_expr) = new AidlUnaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), "-", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1933 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 69:
#line 496 "system/tools/aidl/aidl_language_y.yy"
                  {
    ((*yyvalp).const_expr) = new AidlUnaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), "!", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1941 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 70:
#line 499 "system/tools/aidl/aidl_language_y.yy"
                  {
    ((*yyvalp).const_expr) = new AidlUnaryConstExpression(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), "~", std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
  }
#line 1949 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 71:
#line 503 "system/tools/aidl/aidl_language_y.yy"
  {
    ((*yyvalp).const_expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.const_expr);
  }
#line 1957 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 72:
#line 507 "system/tools/aidl/aidl_language_y.yy"
   {
     AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc))) << "invalid const expression within parenthesis";
     ps->AddError();
     // to avoid segfaults
     ((*yyvalp).const_expr) = AidlConstantValue::Integral(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), "0");
   }
#line 1968 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 73:
#line 516 "system/tools/aidl/aidl_language_y.yy"
               {
    ((*yyvalp).constant_value_list) = new std::vector<std::unique_ptr<AidlConstantValue>>;
 }
#line 1976 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 74:
#line 519 "system/tools/aidl/aidl_language_y.yy"
                                 {
    ((*yyvalp).constant_value_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constant_value_list);
 }
#line 1984 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 75:
#line 522 "system/tools/aidl/aidl_language_y.yy"
                                      {
    ((*yyvalp).constant_value_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constant_value_list);
 }
#line 1992 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 76:
#line 528 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).constant_value_list) = new std::vector<std::unique_ptr<AidlConstantValue>>;
    ((*yyvalp).constant_value_list)->push_back(std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
 }
#line 2001 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 77:
#line 532 "system/tools/aidl/aidl_language_y.yy"
                                                {
    ((*yyvalp).constant_value_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constant_value_list);
    ((*yyvalp).constant_value_list)->push_back(std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr)));
 }
#line 2010 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 78:
#line 539 "system/tools/aidl/aidl_language_y.yy"
                                                            {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.annotation_list)->size() > 0) {
      (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type)->SetComments((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.annotation_list)->begin()->GetComments());
    } else {
      (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type)->SetComments((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token)->GetComments());
    }
    // TODO(b/151102494) do not merge annotations.
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type)->Annotate(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.annotation_list)));
    ((*yyvalp).constant) = new AidlConstantDeclaration(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.const_expr));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.annotation_list);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
   }
#line 2028 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 79:
#line 555 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).enumerator) = new AidlEnumerator(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetComments());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
   }
#line 2037 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 80:
#line 559 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).enumerator) = new AidlEnumerator(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText(), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetComments());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
   }
#line 2046 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 81:
#line 566 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).enumerators) = new std::vector<std::unique_ptr<AidlEnumerator>>();
    ((*yyvalp).enumerators)->push_back(std::unique_ptr<AidlEnumerator>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumerator)));
   }
#line 2055 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 82:
#line 570 "system/tools/aidl/aidl_language_y.yy"
                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.enumerators)->push_back(std::unique_ptr<AidlEnumerator>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumerator)));
    ((*yyvalp).enumerators) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.enumerators);
   }
#line 2064 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 83:
#line 577 "system/tools/aidl/aidl_language_y.yy"
                       { ((*yyvalp).enumerators) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.enumerators); }
#line 2070 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 84:
#line 578 "system/tools/aidl/aidl_language_y.yy"
                           { ((*yyvalp).enumerators) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.enumerators); }
#line 2076 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 85:
#line 582 "system/tools/aidl/aidl_language_y.yy"
                                  {
    ((*yyvalp).declaration) = new AidlEnumDeclaration(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumerators), ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetComments());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumerators);
   }
#line 2087 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 86:
#line 591 "system/tools/aidl/aidl_language_y.yy"
                                                                        {
    ((*yyvalp).declaration) = new AidlUnionDecl(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetText(), ps->Package(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token)->GetComments(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type_params), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.members));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
  }
#line 2097 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 87:
#line 599 "system/tools/aidl/aidl_language_y.yy"
                                        {
    ((*yyvalp).method) = new AidlMethod(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), false, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.arg_list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type)->GetComments());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
  }
#line 2106 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 88:
#line 603 "system/tools/aidl/aidl_language_y.yy"
                                                               {
    const auto& comments = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.annotation_list)->size() > 0) ? (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.annotation_list)->begin()->GetComments() : (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token)->GetComments();
    ((*yyvalp).method) = new AidlMethod(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)), true, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.arg_list), comments);
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type)->Annotate(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.annotation_list)));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.annotation_list);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.token);
  }
#line 2119 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 89:
#line 611 "system/tools/aidl/aidl_language_y.yy"
                                                     {
    int32_t serial = 0;
    if (!android::base::ParseInt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText(), &serial)) {
        AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc))) << "Could not parse int value: " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText();
        ps->AddError();
    }
    ((*yyvalp).method) = new AidlMethod(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yyloc)), false, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.arg_list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type)->GetComments(), serial);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
  }
#line 2134 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 90:
#line 621 "system/tools/aidl/aidl_language_y.yy"
                                                                            {
    const auto& comments = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.annotation_list)->size() > 0) ? (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.annotation_list)->begin()->GetComments() : (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.token)->GetComments();
    int32_t serial = 0;
    if (!android::base::ParseInt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText(), &serial)) {
        AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc))) << "Could not parse int value: " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token)->GetText();
        ps->AddError();
    }
    ((*yyvalp).method) = new AidlMethod(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yyloc)), true, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.arg_list), comments, serial);
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type)->Annotate(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.annotation_list)));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.annotation_list);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.token);
  }
#line 2153 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 91:
#line 637 "system/tools/aidl/aidl_language_y.yy"
       {
    ((*yyvalp).arg_list) = new std::vector<std::unique_ptr<AidlArgument>>();
    ((*yyvalp).arg_list)->push_back(std::unique_ptr<AidlArgument>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.arg)));
  }
#line 2162 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 92:
#line 641 "system/tools/aidl/aidl_language_y.yy"
                              {
    ((*yyvalp).arg_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.arg_list);
    ((*yyvalp).arg_list)->push_back(std::unique_ptr<AidlArgument>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.arg)));
  }
#line 2171 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 93:
#line 648 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).arg_list) = new std::vector<std::unique_ptr<AidlArgument>>(); }
#line 2177 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 94:
#line 649 "system/tools/aidl/aidl_language_y.yy"
                      { ((*yyvalp).arg_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.arg_list); }
#line 2183 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 95:
#line 653 "system/tools/aidl/aidl_language_y.yy"
                             {
    ((*yyvalp).arg) = new AidlArgument(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.direction), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 2192 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 96:
#line 657 "system/tools/aidl/aidl_language_y.yy"
                   {
    ((*yyvalp).arg) = new AidlArgument(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 2201 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 97:
#line 663 "system/tools/aidl/aidl_language_y.yy"
                                  {
    ((*yyvalp).type) = new AidlTypeSpecifier(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText(), false, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetComments());
    ps->DeferResolution(((*yyvalp).type));
    if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)->empty()) {
      ((*yyvalp).type)->SetComments((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)->begin()->GetComments());
      ((*yyvalp).type)->Annotate(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)));
    }
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 2216 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 98:
#line 673 "system/tools/aidl/aidl_language_y.yy"
                                    {
    ps->SetTypeParameters((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type_args));
    ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type);
  }
#line 2225 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 99:
#line 677 "system/tools/aidl/aidl_language_y.yy"
                                                          {
    ps->SetTypeParameters((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type_args));
    auto params = new std::vector<std::unique_ptr<AidlTypeSpecifier>>();
    params->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type));
    ps->SetTypeParameters((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type), params);
    ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type);
  }
#line 2237 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 100:
#line 684 "system/tools/aidl/aidl_language_y.yy"
                                                                        {
    ps->SetTypeParameters((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type_args));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type_args)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type));
    ps->SetTypeParameters((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.type_args));
    ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.type);
  }
#line 2248 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 101:
#line 692 "system/tools/aidl/aidl_language_y.yy"
   { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type); }
#line 2254 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 102:
#line 693 "system/tools/aidl/aidl_language_y.yy"
                                {
    if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.annotation_list)->empty()) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc))) << "Annotations for arrays are not supported.";
      ps->AddError();
    }
    if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type)->SetArray()) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc))) << "Can only have one dimensional arrays.";
      ps->AddError();
    }
    ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.annotation_list);
  }
#line 2271 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 103:
#line 708 "system/tools/aidl/aidl_language_y.yy"
        {
    if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->GetAnnotations().empty()) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc))) << "Annotations for type arguments are not supported.";
      ps->AddError();
    }
    ((*yyvalp).type_args) = new std::vector<std::unique_ptr<AidlTypeSpecifier>>();
    ((*yyvalp).type_args)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type));
  }
#line 2284 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 104:
#line 716 "system/tools/aidl/aidl_language_y.yy"
                      {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type_args)->emplace_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type));
    ((*yyvalp).type_args) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type_args);
  }
#line 2293 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 105:
#line 723 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).annotation_list) = new std::vector<AidlAnnotation>(); }
#line 2299 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 106:
#line 725 "system/tools/aidl/aidl_language_y.yy"
  {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotation) != nullptr) {
      (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list)->emplace_back(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotation)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotation);
    }
    ((*yyvalp).annotation_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotation_list);
  }
#line 2311 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 107:
#line 734 "system/tools/aidl/aidl_language_y.yy"
                              {
    ((*yyvalp).param) = new AidlAnnotationParameter{(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token)->GetText(), std::unique_ptr<AidlConstantValue>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.const_expr))};
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.token);
  }
#line 2320 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 108:
#line 740 "system/tools/aidl/aidl_language_y.yy"
             {
    ((*yyvalp).param_list) = new std::map<std::string, std::shared_ptr<AidlConstantValue>>();
  }
#line 2328 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 109:
#line 743 "system/tools/aidl/aidl_language_y.yy"
                              {
    ((*yyvalp).param_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param_list);
  }
#line 2336 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 110:
#line 748 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).param_list) = new std::map<std::string, std::shared_ptr<AidlConstantValue>>();
    ((*yyvalp).param_list)->emplace(std::move((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->name), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->value.release());
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param);
  }
#line 2346 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 111:
#line 753 "system/tools/aidl/aidl_language_y.yy"
                                           {
    ((*yyvalp).param_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.param_list);
    if (((*yyvalp).param_list)->find((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->name) != ((*yyvalp).param_list)->end()) {
      AIDL_ERROR(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc))) << "Trying to redefine parameter " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->name << ".";
      ps->AddError();
    }
    ((*yyvalp).param_list)->emplace(std::move((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->name), std::move((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param)->value));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.param);
  }
#line 2360 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 112:
#line 764 "system/tools/aidl/aidl_language_y.yy"
              {
    ((*yyvalp).annotation) = AidlAnnotation::Parse(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetText(), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token)->GetComments());
    if (!((*yyvalp).annotation)) {
      ps->AddError();
    }
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.token);
  }
#line 2372 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 113:
#line 771 "system/tools/aidl/aidl_language_y.yy"
                                     {
    ((*yyvalp).annotation) = AidlAnnotation::Parse(loc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetText(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.param_list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token)->GetComments());
    if (!((*yyvalp).annotation)) {
      ps->AddError();
    }
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.token);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.param_list);
  }
#line 2385 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 114:
#line 783 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).direction) = AidlArgument::IN_DIR; }
#line 2391 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 115:
#line 785 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).direction) = AidlArgument::OUT_DIR; }
#line 2397 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;

  case 116:
#line 787 "system/tools/aidl/aidl_language_y.yy"
  { ((*yyvalp).direction) = AidlArgument::INOUT_DIR; }
#line 2403 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
    break;


#line 2407 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"

      default: break;
    }
#if YY_EXCEPTIONS
  }
  catch (const syntax_error& yyexc)
    {
      YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
      *yylocp = yyexc.location;
      yyerror (yylocp, yyparser, ps, yyexc.what ());
      YYERROR;
    }
#endif // YY_EXCEPTIONS

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yy::parser& yyparser, Parser* ps)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyparser);
  YYUSE (ps);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: // "package"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2469 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 4: // "import"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2475 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 5: // "annotation"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2481 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 6: // "string literal"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2487 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 7: // "identifier"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2493 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 8: // "interface"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2499 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 9: // "parcelable"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2505 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 10: // "oneway"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2511 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 11: // "enum"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2517 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 12: // "union"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2523 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 13: // "const"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2529 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 14: // "char literal"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2535 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 15: // "float literal"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2541 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 16: // "hex literal"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2547 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 17: // "int literal"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2553 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 29: // "cpp_header (which can also be used as an identifier)"
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2559 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 59: // identifier
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2565 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 60: // package
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).package)); }
#line 2571 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 61: // imports
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).imports)); }
#line 2577 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 62: // import
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).import)); }
#line 2583 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 63: // qualified_name
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).token)); }
#line 2589 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 64: // decls
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declarations)); }
#line 2595 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 65: // decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2601 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 66: // unannotated_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2607 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 67: // type_params
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).type_params)); }
#line 2613 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 68: // optional_type_params
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).type_params)); }
#line 2619 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 69: // parcelable_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2625 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 70: // parcelable_members
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).members)); }
#line 2631 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 71: // variable_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).variable)); }
#line 2637 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 72: // interface_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2643 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 73: // interface_members
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).members)); }
#line 2649 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 74: // const_expr
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).const_expr)); }
#line 2655 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 75: // constant_value_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).constant_value_list)); }
#line 2661 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 76: // constant_value_non_empty_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).constant_value_list)); }
#line 2667 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 77: // constant_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).constant)); }
#line 2673 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 78: // enumerator
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).enumerator)); }
#line 2679 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 79: // enumerators
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).enumerators)); }
#line 2685 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 80: // enum_decl_body
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).enumerators)); }
#line 2691 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 81: // enum_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2697 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 82: // union_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).declaration)); }
#line 2703 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 83: // method_decl
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).method)); }
#line 2709 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 84: // arg_non_empty_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).arg_list)); }
#line 2715 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 85: // arg_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).arg_list)); }
#line 2721 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 86: // arg
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).arg)); }
#line 2727 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 87: // non_array_type
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).type)); }
#line 2733 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 88: // type
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).type)); }
#line 2739 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 89: // type_args
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).type_args)); }
#line 2745 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 90: // annotation_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).annotation_list)); }
#line 2751 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 91: // parameter
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).param)); }
#line 2757 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 92: // parameter_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).param_list)); }
#line 2763 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 93: // parameter_non_empty_list
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).param_list)); }
#line 2769 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 94: // annotation
#line 100 "system/tools/aidl/aidl_language_y.yy"
            { delete (((*yyvaluep).annotation)); }
#line 2775 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

    case 95: // direction
#line 99 "system/tools/aidl/aidl_language_y.yy"
            { }
#line 2781 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yy::parser& yyparser, Parser* ps)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, yyparser, ps);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, yyparser, ps);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyisDefaultedState (yystate)
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  ptrdiff_t yynewSize;
  ptrdiff_t yyn;
  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  ptrdiff_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
            ptrdiff_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
                 yyRuleNum yyrule, yy::parser& yyparser, Parser* ps)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , yyparser, ps);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule, yyparser, ps));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, yyparser, ps);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, yyparser, ps));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, yyparser, ps);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, yy::parser& yyparser, Parser* ps)
{
  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, yyparser, ps);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      ptrdiff_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static ptrdiff_t
yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, yyparser, ps));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, yyparser, ps));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, yyparser, ps);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, yyparser, ps);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, yyparser, ps);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState])));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState]),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, yyparser, ps, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, yy::parser& yyparser, Parser* ps)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, yyparser, ps);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, yyparser, ps);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, yyparser, ps);
              return yyreportAmbiguity (yybest, yyp, yylocp, yyparser, ps);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, ps);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, yyparser, ps);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, yyparser, ps);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, ps);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , yyparser, ps));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                   ptrdiff_t yyposn, YYLTYPE *yylocp, yy::parser& yyparser, Parser* ps)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n", YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], yyparser, ps);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken = yygetToken (&yychar, yystackp, yyparser, ps);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], yyparser, ps);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, yyparser, ps));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], yyparser, ps);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (&yylloc, yyparser, ps, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  ptrdiff_t yysize = 0;

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
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
      yysize = yysize0;
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
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
                yyarg[yycount++] = yytokenName (yyx);
                {
                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  if (YYSIZEMAX - yysize < yysz)
                    yysize_overflow = yytrue;
                  else
                    yysize += yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
    if (YYSIZEMAX - yysize < yysz)
      yysize_overflow = yytrue;
    else
      yysize += yysz;
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, yyparser, ps, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, yyparser, ps, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, Parser* ps)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, yyparser, ps, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, yyparser, ps);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, yyparser, ps);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    ptrdiff_t yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, yyparser, ps, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, yyparser, ps);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, yyparser, ps, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (yy::parser& yyparser, Parser* ps)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  ptrdiff_t yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  // User initialization code.
yylloc.initialize ();
#line 54 "system/tools/aidl/aidl_language_y.yy"
{
    yylloc.begin.filename = yylloc.end.filename =
        const_cast<std::string *>(&ps->FileName());
}

#line 4196 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, yyparser, ps);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, yyparser, ps));
            }
          else
            {
              yySymbol yytoken = yygetToken (&yychar, yystackp, yyparser, ps);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Don't issue an error message again for exceptions
                     thrown from the scanner.  */
                  if (yychar != YYFAULTYTOK)
                    yyreportSyntaxError (&yystack, yyparser, ps);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, yyparser, ps));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          ptrdiff_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, yyparser, ps));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, yyparser, ps, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, yyparser, ps));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, yyparser, ps);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, yyparser, ps));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, yyparser, ps);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (&yylloc, yyparser, ps, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, yyparser, ps);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          ptrdiff_t yysize = yystack.yytops.yysize;
          ptrdiff_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, yyparser, ps);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    ptrdiff_t yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 789 "system/tools/aidl/aidl_language_y.yy"


#include <ctype.h>
#include <stdio.h>

void yy::parser::error(const yy::parser::location_type& l, const std::string& errstr) {
  AIDL_ERROR(loc(l)) << errstr;
  // parser will return error value
}
#line 4494 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"

/*------------------.
| Report an error.  |
`------------------*/

static void
yyerror (const yy::parser::location_type *yylocationp, yy::parser& yyparser, Parser* ps, const char* msg)
{
  YYUSE (yyparser);
  YYUSE (ps);
  yyparser.error (*yylocationp, msg);
}


namespace yy {
#line 4510 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"

  /// Build a parser object.
  parser::parser (Parser* ps_yyarg)
    :
#if YYDEBUG
      yycdebug_ (&std::cerr),
#endif
      ps (ps_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    return ::yyparse (*this, ps);
  }

#if YYDEBUG
  /*--------------------.
  | Print this symbol.  |
  `--------------------*/

  void
  parser::yy_symbol_value_print_ (int yytype,
                           const semantic_type* yyvaluep,
                           const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    YYUSE (yytype);
  }


  void
  parser::yy_symbol_print_ (int yytype,
                           const semantic_type* yyvaluep,
                           const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < YYNTOKENS ? "token" : "nterm")
               << ' ' << yytname[yytype] << " ("
               << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }

  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    // Actually, it is yydebug which is really used.
    yydebug = l;
  }

#endif
} // yy
#line 4598 "out/soong/.intermediates/system/tools/aidl/libaidl-common/linux_glibc_x86_64_static/gen/yacc/system/tools/aidl/aidl_language_y.cpp"
