/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 32 "external/selinux/checkpolicy/policy_parse.y"

#include <sys/types.h>
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include <sepol/policydb/expand.h>
#include <sepol/policydb/policydb.h>
#include <sepol/policydb/services.h>
#include <sepol/policydb/conditional.h>
#include <sepol/policydb/flask.h>
#include <sepol/policydb/hierarchy.h>
#include <sepol/policydb/polcaps.h>
#include "queue.h"
#include "checkpolicy.h"
#include "module_compiler.h"
#include "policy_define.h"

extern policydb_t *policydbp;
extern unsigned int pass;

extern char yytext[];
extern int yylex(void);
extern int yywarn(const char *msg);
extern int yyerror(const char *msg);

typedef int (* require_func_t)(int pass);


#line 107 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_OUT_SOONG_TEMP_SBOX_288F4549ADF4444E35FCFFAF10E314760461EC2F_OUT_EXTERNAL_SELINUX_CHECKPOLICY_POLICY_PARSE_H_INCLUDED
# define YY_YY_OUT_SOONG_TEMP_SBOX_288F4549ADF4444E35FCFFAF10E314760461EC2F_OUT_EXTERNAL_SELINUX_CHECKPOLICY_POLICY_PARSE_H_INCLUDED
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
    PATH = 258,
    QPATH = 259,
    FILENAME = 260,
    CLONE = 261,
    COMMON = 262,
    CLASS = 263,
    CONSTRAIN = 264,
    VALIDATETRANS = 265,
    INHERITS = 266,
    SID = 267,
    ROLE = 268,
    ROLEATTRIBUTE = 269,
    ATTRIBUTE_ROLE = 270,
    ROLES = 271,
    TYPEALIAS = 272,
    TYPEATTRIBUTE = 273,
    TYPEBOUNDS = 274,
    TYPE = 275,
    TYPES = 276,
    ALIAS = 277,
    ATTRIBUTE = 278,
    EXPANDATTRIBUTE = 279,
    BOOL = 280,
    TUNABLE = 281,
    IF = 282,
    ELSE = 283,
    TYPE_TRANSITION = 284,
    TYPE_MEMBER = 285,
    TYPE_CHANGE = 286,
    ROLE_TRANSITION = 287,
    RANGE_TRANSITION = 288,
    SENSITIVITY = 289,
    DOMINANCE = 290,
    DOM = 291,
    DOMBY = 292,
    INCOMP = 293,
    CATEGORY = 294,
    LEVEL = 295,
    RANGE = 296,
    MLSCONSTRAIN = 297,
    MLSVALIDATETRANS = 298,
    USER = 299,
    NEVERALLOW = 300,
    ALLOW = 301,
    AUDITALLOW = 302,
    AUDITDENY = 303,
    DONTAUDIT = 304,
    ALLOWXPERM = 305,
    AUDITALLOWXPERM = 306,
    DONTAUDITXPERM = 307,
    NEVERALLOWXPERM = 308,
    SOURCE = 309,
    TARGET = 310,
    SAMEUSER = 311,
    FSCON = 312,
    PORTCON = 313,
    NETIFCON = 314,
    NODECON = 315,
    IBPKEYCON = 316,
    IBENDPORTCON = 317,
    PIRQCON = 318,
    IOMEMCON = 319,
    IOPORTCON = 320,
    PCIDEVICECON = 321,
    DEVICETREECON = 322,
    FSUSEXATTR = 323,
    FSUSETASK = 324,
    FSUSETRANS = 325,
    GENFSCON = 326,
    U1 = 327,
    U2 = 328,
    U3 = 329,
    R1 = 330,
    R2 = 331,
    R3 = 332,
    T1 = 333,
    T2 = 334,
    T3 = 335,
    L1 = 336,
    L2 = 337,
    H1 = 338,
    H2 = 339,
    NOT = 340,
    AND = 341,
    OR = 342,
    XOR = 343,
    CTRUE = 344,
    CFALSE = 345,
    IDENTIFIER = 346,
    NUMBER = 347,
    EQUALS = 348,
    NOTEQUAL = 349,
    IPV4_ADDR = 350,
    IPV6_ADDR = 351,
    MODULE = 352,
    VERSION_IDENTIFIER = 353,
    REQUIRE = 354,
    OPTIONAL = 355,
    POLICYCAP = 356,
    PERMISSIVE = 357,
    FILESYSTEM = 358,
    DEFAULT_USER = 359,
    DEFAULT_ROLE = 360,
    DEFAULT_TYPE = 361,
    DEFAULT_RANGE = 362,
    LOW_HIGH = 363,
    LOW = 364,
    HIGH = 365,
    GLBLUB = 366
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "external/selinux/checkpolicy/policy_parse.y"

	unsigned int val;
	uint64_t val64;
	uintptr_t valptr;
	void *ptr;
        require_func_t require_func;

#line 279 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_OUT_SOONG_TEMP_SBOX_288F4549ADF4444E35FCFFAF10E314760461EC2F_OUT_EXTERNAL_SELINUX_CHECKPOLICY_POLICY_PARSE_H_INCLUDED  */



#ifdef short
# undef short
#endif

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

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  198
/* YYNRULES -- Number of rules.  */
#define YYNRULES  407
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  817

#define YYUNDEFTOK  2
#define YYMAXUTOK   366


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     117,   118,   121,     2,   116,   119,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   115,   114,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,     2,   113,   120,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   166,   166,   167,   169,   171,   174,   169,   178,   179,
     181,   184,   185,   187,   190,   192,   193,   195,   196,   198,
     201,   202,   204,   206,   208,   211,   212,   214,   215,   216,
     217,   218,   219,   220,   221,   223,   225,   228,   230,   233,
     235,   238,   240,   242,   244,   246,   248,   250,   253,   254,
     256,   258,   259,   261,   263,   266,   268,   270,   273,   274,
     276,   277,   279,   281,   284,   285,   287,   289,   292,   293,
     295,   296,   298,   301,   304,   305,   307,   308,   309,   310,
     311,   312,   314,   315,   316,   317,   318,   319,   320,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   335,   338,   341,   343,   346,   349,   352,   355,   356,
     358,   361,   364,   366,   369,   372,   375,   377,   379,   382,
     385,   388,   391,   394,   397,   400,   404,   407,   409,   411,
     413,   416,   419,   422,   425,   429,   431,   433,   435,   438,
     442,   446,   450,   455,   457,   459,   461,   464,   466,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   479,   482,
     485,   488,   491,   494,   497,   500,   503,   506,   509,   512,
     515,   517,   519,   522,   525,   527,   530,   532,   535,   538,
     539,   541,   542,   544,   545,   547,   550,   553,   555,   558,
     561,   564,   567,   570,   573,   576,   576,   579,   579,   582,
     582,   585,   585,   588,   588,   591,   591,   594,   594,   597,
     597,   600,   600,   603,   606,   606,   609,   609,   612,   615,
     615,   618,   618,   621,   624,   627,   630,   633,   636,   640,
     642,   645,   647,   649,   651,   654,   655,   657,   660,   661,
     663,   664,   666,   669,   669,   671,   672,   674,   675,   676,
     677,   678,   680,   683,   685,   688,   690,   693,   696,   699,
     700,   702,   703,   705,   708,   710,   711,   713,   714,   716,
     718,   721,   722,   724,   725,   727,   729,   732,   733,   735,
     736,   738,   741,   742,   744,   745,   747,   750,   751,   753,
     754,   756,   758,   761,   762,   764,   765,   767,   769,   771,
     774,   775,   777,   778,   780,   782,   782,   784,   787,   790,
     792,   794,   796,   800,   802,   803,   805,   805,   806,   807,
     809,   812,   814,   815,   817,   819,   822,   824,   827,   828,
     830,   832,   834,   836,   838,   841,   844,   847,   847,   850,
     853,   856,   857,   858,   859,   860,   862,   863,   865,   868,
     869,   871,   873,   873,   875,   875,   875,   875,   877,   880,
     882,   885,   887,   890,   893,   896,   899,   902,   905,   910,
     915,   918,   920,   922,   924,   926,   927,   929,   930,   931,
     932,   933,   934,   936,   938,   939,   941,   942,   944,   947,
     948,   949,   950,   951,   952,   953,   954,   955,   957,   959,
     963,   962,   967,   969,   971,   974,   977,   978
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PATH", "QPATH", "FILENAME", "CLONE",
  "COMMON", "CLASS", "CONSTRAIN", "VALIDATETRANS", "INHERITS", "SID",
  "ROLE", "ROLEATTRIBUTE", "ATTRIBUTE_ROLE", "ROLES", "TYPEALIAS",
  "TYPEATTRIBUTE", "TYPEBOUNDS", "TYPE", "TYPES", "ALIAS", "ATTRIBUTE",
  "EXPANDATTRIBUTE", "BOOL", "TUNABLE", "IF", "ELSE", "TYPE_TRANSITION",
  "TYPE_MEMBER", "TYPE_CHANGE", "ROLE_TRANSITION", "RANGE_TRANSITION",
  "SENSITIVITY", "DOMINANCE", "DOM", "DOMBY", "INCOMP", "CATEGORY",
  "LEVEL", "RANGE", "MLSCONSTRAIN", "MLSVALIDATETRANS", "USER",
  "NEVERALLOW", "ALLOW", "AUDITALLOW", "AUDITDENY", "DONTAUDIT",
  "ALLOWXPERM", "AUDITALLOWXPERM", "DONTAUDITXPERM", "NEVERALLOWXPERM",
  "SOURCE", "TARGET", "SAMEUSER", "FSCON", "PORTCON", "NETIFCON",
  "NODECON", "IBPKEYCON", "IBENDPORTCON", "PIRQCON", "IOMEMCON",
  "IOPORTCON", "PCIDEVICECON", "DEVICETREECON", "FSUSEXATTR", "FSUSETASK",
  "FSUSETRANS", "GENFSCON", "U1", "U2", "U3", "R1", "R2", "R3", "T1", "T2",
  "T3", "L1", "L2", "H1", "H2", "NOT", "AND", "OR", "XOR", "CTRUE",
  "CFALSE", "IDENTIFIER", "NUMBER", "EQUALS", "NOTEQUAL", "IPV4_ADDR",
  "IPV6_ADDR", "MODULE", "VERSION_IDENTIFIER", "REQUIRE", "OPTIONAL",
  "POLICYCAP", "PERMISSIVE", "FILESYSTEM", "DEFAULT_USER", "DEFAULT_ROLE",
  "DEFAULT_TYPE", "DEFAULT_RANGE", "LOW_HIGH", "LOW", "HIGH", "GLBLUB",
  "'{'", "'}'", "';'", "':'", "','", "'('", "')'", "'-'", "'~'", "'*'",
  "$accept", "policy", "base_policy", "$@1", "$@2", "$@3", "classes",
  "class_def", "initial_sids", "initial_sid_def", "access_vectors",
  "opt_common_perms", "common_perms", "common_perms_def", "av_perms",
  "av_perms_def", "opt_default_rules", "default_rules", "default_user_def",
  "default_role_def", "default_type_def", "default_range_def", "opt_mls",
  "mls", "sensitivities", "sensitivity_def", "alias_def", "dominance",
  "opt_categories", "categories", "category_def", "levels", "level_def",
  "mlspolicy", "mlspolicy_decl", "mlsconstraint_def",
  "mlsvalidatetrans_def", "te_rbac", "te_rbac_decl", "rbac_decl",
  "te_decl", "attribute_def", "expandattribute_def", "type_def",
  "typealias_def", "typeattribute_def", "typebounds_def", "opt_attr_list",
  "bool_def", "tunable_def", "bool_val", "cond_stmt_def", "cond_else",
  "cond_expr", "cond_expr_prim", "cond_pol_list", "cond_rule_def",
  "cond_transition_def", "cond_te_avtab_def", "cond_allow_def",
  "cond_auditallow_def", "cond_auditdeny_def", "cond_dontaudit_def",
  "transition_def", "range_trans_def", "te_avtab_def", "allow_def",
  "auditallow_def", "auditdeny_def", "dontaudit_def", "neverallow_def",
  "xperm_allow_def", "xperm_auditallow_def", "xperm_dontaudit_def",
  "xperm_neverallow_def", "attribute_role_def", "role_type_def",
  "role_attr_def", "role_dominance", "role_trans_def", "role_allow_def",
  "roles", "role_def", "roleattribute_def", "opt_constraints",
  "constraints", "constraint_decl", "constraint_def", "validatetrans_def",
  "cexpr", "cexpr_prim", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "op", "role_mls_op",
  "users", "user_def", "opt_mls_user", "initial_sid_contexts",
  "initial_sid_context_def", "opt_dev_contexts", "dev_contexts",
  "dev_context_def", "pirq_context_def", "iomem_context_def",
  "ioport_context_def", "pci_context_def", "dtree_context_def",
  "opt_fs_contexts", "fs_contexts", "fs_context_def", "net_contexts",
  "opt_port_contexts", "port_contexts", "port_context_def",
  "opt_ibpkey_contexts", "ibpkey_contexts", "ibpkey_context_def",
  "opt_ibendport_contexts", "ibendport_contexts", "ibendport_context_def",
  "opt_netif_contexts", "netif_contexts", "netif_context_def",
  "opt_node_contexts", "node_contexts", "node_context_def", "opt_fs_uses",
  "fs_uses", "fs_use_def", "opt_genfs_contexts", "genfs_contexts",
  "genfs_context_def", "$@17", "ipv4_addr_def", "xperms",
  "nested_xperm_set", "nested_xperm_list", "nested_xperm_element", "$@18",
  "xperm", "security_context_def", "opt_mls_range_def", "mls_range_def",
  "mls_level_def", "id_comma_list", "tilde", "asterisk", "names", "$@19",
  "tilde_push", "asterisk_push", "names_push", "identifier_list_push",
  "identifier_push", "identifier_list", "nested_id_set", "nested_id_list",
  "nested_id_element", "$@20", "identifier", "filesystem", "path",
  "filename", "number", "number64", "ipv6_addr", "policycap_def",
  "permissive_def", "module_policy", "module_def", "version_identifier",
  "avrules_block", "avrule_decls", "avrule_decl", "require_block",
  "require_list", "require_decl", "require_class", "require_decl_def",
  "require_id_list", "optional_block", "$@21", "optional_else",
  "optional_decl", "else_decl", "avrule_user_defs", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   123,   125,    59,    58,    44,    40,    41,    45,
     126,    42
};
# endif

#define YYPACT_NINF (-714)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-232)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,   -17,   111,  -714,   179,  -714,   834,  -714,   259,  -714,
     -17,   198,  -714,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,    93,   -17,   -17,    92,    93,    93,    93,    93,    93,
      48,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      81,  -714,   -17,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,   508,  -714,  -714,  -714,
     113,  -714,  -714,  -714,  -714,  -714,   126,  -714,   -17,  -714,
     106,  -714,    10,   -17,   219,   330,   -17,   -17,    16,   254,
     -26,  -714,  -714,   -31,  -714,   248,  -714,   147,   248,   248,
      92,    92,   186,  -714,  -714,    93,    93,    93,    93,    93,
     288,    93,    93,    93,    93,    93,    93,    93,    93,    93,
     177,   257,   -17,   311,  -714,  -714,   834,  -714,  -714,   -17,
    -714,  -714,   350,   356,  -714,    93,   -17,   265,   286,  -714,
    -714,    93,   268,   300,   303,   283,   289,  -714,  -714,  -714,
     107,  -714,  -714,  -714,  -714,  -714,  -714,   310,  -714,   324,
     328,   249,    70,    92,    92,    92,    92,    92,  -714,   347,
     360,   372,    89,   170,   363,    20,  -714,   387,   162,   388,
     389,   390,   394,   395,   396,   404,   -17,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,    22,  -714,   358,   -17,
    -714,   491,  -714,   411,   417,   199,   -17,   350,  -714,  -714,
     416,   400,  -714,  -714,   -17,  -714,  -714,  -714,  -714,   428,
    -714,   -17,  -714,  -714,  -714,   -17,  -714,  -714,  -714,   249,
     174,   253,  -714,  -714,    24,    93,    93,    93,    93,   430,
      93,   431,   398,   432,  -714,   322,  -714,  -714,    93,  -714,
      93,    93,    93,    93,    93,    93,    93,    93,    93,  -714,
    -714,  -714,  -714,   321,    93,  -714,   -17,    93,    93,    93,
      93,   512,   199,  -714,  -714,  -714,  -714,    18,  -714,  -714,
    -714,  -714,  -714,  -714,    93,    93,    93,    93,    93,    93,
      93,   520,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
     -17,   -17,   -17,   -17,  -714,   -17,  -714,   -17,   -17,   288,
    -714,    93,    93,    93,    93,    93,   -17,   -17,   -17,   -17,
    -714,  -714,   -17,   509,   522,   -16,  -714,   402,   405,   425,
      25,   -17,   939,  -714,   447,  -714,  -714,  -714,  -714,  -714,
     -17,   -17,    93,    93,    93,    93,    93,    93,    93,   439,
    -714,     6,   448,   449,   451,   452,  -714,   400,    21,   453,
     454,   455,   456,   458,     2,     2,     2,     2,  -714,   -17,
     459,  -714,  -714,   462,  -714,  -714,   461,   463,   464,   465,
     466,   467,   267,   279,   468,    14,   -17,  -714,   620,  -714,
    -714,  -714,  -714,  -714,  -714,   208,  -714,   525,   471,   187,
     469,   470,   472,   473,   474,   476,   477,  -714,  -714,  -714,
     479,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,    32,   480,  -714,  -714,    32,  -714,   481,   482,   483,
     545,  -714,   834,  -714,  -714,  -714,  -714,  -714,  -714,   484,
     485,   486,   487,   488,   489,  -714,  -714,   490,   492,  -714,
     152,  -714,   -17,  -714,   -17,   550,   525,  -714,   -17,  -714,
      93,    93,    93,    93,    93,    93,    93,   119,  -714,  -714,
     232,  -714,   494,  -714,  -714,  -714,  -714,  -714,  -714,   -17,
     496,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,    93,
      93,  -714,   475,  -714,  -714,  -714,  -714,   202,    28,   -17,
     351,  -714,  -714,   216,   -17,   -17,   -17,    93,    93,    93,
      93,  -714,  -714,  -714,  -714,  -714,  -714,    93,   173,   593,
    -714,  -714,  -714,   497,   376,    93,    93,  -714,   450,  -714,
    -714,  -714,  -714,    15,   498,   500,   501,   502,   503,   504,
     528,   173,    46,    95,   244,  -714,   401,   401,   401,    46,
     401,   401,   401,   401,   401,    46,    46,    46,   173,   173,
     149,  -714,   -17,    86,  -714,  -714,  -714,   -17,    93,   173,
    -714,  -714,   507,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
     151,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,   551,  -714,  -714,   547,   549,  -714,  -714,   548,
    -714,  -714,   323,   542,   357,  -714,    83,   173,   173,  -714,
     -17,   528,  -714,   352,   571,  -714,   339,   173,   157,  -714,
    -714,   121,   121,   121,   121,  -714,   121,   121,   121,   121,
    -714,   121,   121,  -714,   121,   121,   121,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,   543,  -714,   515,   528,   245,
     -17,   -17,   560,   352,  -714,  -714,  -714,   183,  -714,   363,
    -714,  -714,   241,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,   -17,   -17,
    -714,  -714,   -17,   -17,   -17,   245,   574,   560,  -714,  -714,
    -714,   217,  -714,   363,  -714,   521,   -17,   527,   534,   540,
     493,   -17,   346,   583,   574,  -714,  -714,  -714,  -714,   228,
     -17,  -714,  -714,  -714,  -714,  -714,  -714,   -15,   528,   528,
     564,   528,   528,   493,   596,   346,  -714,  -714,  -714,  -714,
    -714,  -714,   -17,   598,   583,  -714,  -714,  -714,   546,    80,
    -714,    88,   -17,  -714,    98,   103,   -17,   -17,   567,   612,
     596,  -714,  -714,   -17,   403,  -714,   598,  -714,  -714,   -17,
    -714,  -714,   -17,   528,  -714,  -714,   564,  -714,   528,  -714,
    -714,  -714,  -714,   528,   -17,  -714,   612,  -714,  -714,   -17,
     580,   567,  -714,  -714,   -17,  -714,   -17,   -17,   -17,   140,
     528,  -714,  -714,   -17,   -17,  -714,  -714,  -714,  -714,   528,
    -714,   -17,  -714,  -714,   -17,  -714,  -714
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     0,     0,     2,     0,     3,     0,   358,     0,     1,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,   382,   377,   378,    89,    90,    91,    92,
      93,    94,    95,    96,   379,    97,    98,    99,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    82,    83,    88,
      84,    85,    86,    87,   100,   369,   407,   376,   380,   381,
       0,   364,   308,   371,   373,   372,     0,    10,     0,     9,
      16,    11,   109,     0,     0,     0,     0,     0,   109,     0,
       0,   330,   331,     0,   334,     0,   333,   332,     0,     0,
       0,     0,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   375,   374,     0,   370,    13,     0,
      12,     5,     0,    15,    17,     0,     0,     0,     0,   328,
     167,     0,     0,     0,     0,   109,     0,   101,   355,   357,
       0,   352,   354,   336,   335,   112,   113,     0,   337,     0,
       0,   118,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   389,   392,   390,
     391,   394,   395,   396,   397,   393,     0,   385,     0,     0,
     368,     0,   406,     0,     0,    26,     0,    14,    20,    18,
       0,   108,   169,   178,     0,    55,   105,   106,   107,     0,
     104,     0,   351,   353,   102,     0,   110,   111,   117,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   325,   327,   348,     0,   170,   175,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
     384,   386,   398,     0,     0,   400,     0,     0,     0,     0,
       0,    49,    25,    27,    28,    29,    30,     0,    21,   168,
     329,   103,   356,   338,     0,     0,     0,     0,     0,     0,
       0,   116,   126,   128,   129,   135,   136,   137,   138,   130,
       0,     0,     0,     0,   171,     0,   147,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     388,   387,     0,   239,   403,     0,   349,     0,     0,     0,
       0,     0,     0,    48,     0,    51,    31,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,   324,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,   405,   401,     0,    19,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,    74,
      77,    76,    78,    80,    79,     0,    52,    59,    23,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   363,   144,
       0,   145,   146,   172,   148,   177,   162,   158,   159,   160,
     161,     0,     0,   310,   309,     0,   320,     0,     0,     0,
       0,   237,     0,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,    47,    54,     0,     0,    75,
     180,   235,     0,    56,     0,     0,    58,    60,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   319,
       0,   314,   318,   163,   312,   311,   164,   165,   166,     0,
       0,    43,    41,    42,    46,    44,    45,    53,   367,     0,
       0,     6,   179,   181,   183,   184,   236,     0,     0,     0,
       0,    64,    61,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   313,   315,   316,   238,   402,     0,     0,     0,
     182,    57,    63,     0,     0,     0,     0,    65,    50,    68,
      70,    71,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,   260,   240,    62,    67,     0,     0,     0,
      69,   132,     0,   133,   134,   139,   140,   141,   142,   317,
       0,   232,   233,   234,   229,   230,   231,   218,   214,   219,
     216,   221,   195,   197,   199,   201,     0,   203,   205,   207,
     209,   211,     0,     0,     0,   188,     0,     0,     0,   186,
       0,     0,   241,   294,   259,   261,     0,     0,     0,   131,
     185,     0,     0,     0,     0,   192,     0,     0,     0,     0,
     193,     0,     0,   194,     0,     0,     0,   223,   227,   224,
     228,   225,   226,   187,   189,   190,   242,     0,     0,     0,
       0,     0,   301,   293,   295,   262,    66,     0,    73,     0,
     339,   340,     0,   343,   215,   341,   220,   217,   222,   196,
     198,   200,   202,   204,   206,   208,   210,   212,     0,     0,
     360,   359,     0,     0,     0,     0,   266,   300,   302,   296,
      72,     0,   346,     0,   344,     0,     0,     0,     0,     0,
       0,     0,   244,   283,   265,   267,   303,   342,   347,     0,
       0,   263,   297,   298,   299,   361,   362,     0,     0,     0,
       0,     0,     0,     0,   272,   243,   245,   247,   248,   249,
     250,   251,     0,   288,   282,   284,   268,   345,   323,     0,
     307,     0,     0,   365,     0,     0,     0,     0,     0,   278,
     271,   273,   246,     0,     0,   264,   287,   289,   285,     0,
     321,   305,     0,     0,   269,   252,     0,   253,     0,   255,
     257,   258,   366,     0,     0,     7,   277,   279,   274,     0,
       0,     0,   290,   322,     0,   304,     0,     0,     0,     0,
       0,   280,   286,     0,     0,   306,   270,   254,   256,     0,
     275,     0,   291,   292,     0,   281,   276
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -714,  -714,  -714,  -714,  -714,  -714,  -714,   665,  -714,   587,
    -714,  -714,  -714,   535,  -714,   478,  -714,  -714,   397,   399,
     407,   408,  -714,  -714,  -714,   336,   -93,  -714,  -714,  -714,
     218,  -714,   172,  -714,   145,  -714,  -714,  -714,   287,  -298,
    -273,  -714,  -714,  -714,  -714,  -714,  -714,   -52,  -714,  -714,
     392,  -257,  -714,   -22,  -714,   269,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,   375,  -177,  -714,  -714,  -714,   194,  -714,  -714,  -511,
    -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,  -714,  -714,  -714,  -112,  -169,  -714,  -359,  -714,  -714,
     124,  -714,  -714,   -37,  -714,  -714,  -714,  -714,  -714,  -714,
    -714,    76,  -714,  -714,  -714,   -13,  -714,  -714,   -58,  -714,
    -714,   -83,  -714,  -714,   -40,  -714,  -714,   -60,  -714,  -714,
      44,  -714,  -714,    11,  -714,  -673,    54,  -368,  -714,   229,
    -714,  -403,  -371,  -714,  -311,  -274,   -94,  -350,  -272,   800,
    -714,  -714,  -714,  -168,     8,  -183,  -341,   -41,  -714,   552,
    -714,    -1,    19,   -20,   175,    41,   -61,  -713,  -714,  -714,
    -714,  -714,  -714,  -129,  -714,   640,  -238,  -714,   511,  -714,
    -714,  -714,  -252,  -714,  -714,  -714,  -714,   590
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,   215,   529,    11,    12,    90,    91,
     141,   142,   143,   144,   217,   218,   281,   282,   283,   284,
     285,   286,   342,   343,   344,   345,   152,   407,   465,   466,
     467,   510,   511,   538,   539,   540,   541,   398,   399,    44,
      45,    46,    47,    48,    49,    50,    51,   147,    52,    53,
     167,    54,   360,   112,   113,   244,   302,   303,   304,   305,
     306,   307,   308,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   185,   186,    73,   501,   502,   503,   504,   505,   570,
     571,   636,   637,   638,   639,   641,   642,   644,   645,   646,
     631,   633,   632,   634,   596,   597,   460,   133,   380,   573,
     574,   734,   735,   736,   737,   738,   739,   740,   741,   623,
     624,   625,   712,   713,   714,   715,   759,   760,   761,   785,
     786,   787,   743,   744,   745,   765,   766,   767,   662,   663,
     664,   696,   697,   698,   794,    84,   432,   433,   480,   481,
     550,   434,   656,   770,   251,   252,   148,   103,   104,   105,
     235,   672,   673,   674,   701,   675,   335,   106,   160,   161,
     231,   107,   692,   727,   420,   436,   754,   783,   403,    74,
       5,     6,    86,    75,    76,    77,    78,   206,   207,   208,
     209,   273,    79,   334,   382,    80,   383,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,   255,   153,   154,   365,   155,   309,   213,   257,    87,
     409,   418,    92,    93,    94,    95,    96,    97,    98,    99,
     418,   108,   109,   114,   435,   435,   435,   435,   482,   350,
     196,   145,   485,   184,   184,   197,   151,   198,   151,   461,
     590,   131,   199,   366,   400,   200,   156,   201,   202,    85,
     151,   791,   221,   294,   295,   296,   203,   615,   616,   159,
       7,   204,   163,   479,     1,     7,   205,   484,   628,   401,
     297,   298,   299,   300,     7,     7,     7,   482,   804,   392,
     393,   100,   591,   592,   593,   402,   100,   138,   171,   172,
     404,   790,   149,   158,    81,   149,   149,   384,   572,   162,
     400,   506,   164,   229,   749,   440,   654,   655,   598,   114,
     114,     9,   479,   139,   431,   599,   667,   803,    88,   159,
     419,   507,   101,    40,    81,   401,   146,   513,   456,   581,
     351,   211,   146,   256,   425,   269,   394,   301,   214,   594,
     595,   402,   532,   621,   431,   149,   404,   589,   294,   295,
     296,   239,   240,   241,   242,   243,   173,   174,   175,   162,
     120,   499,   500,   176,   177,   297,   298,   299,   300,   617,
     618,     7,   114,   114,   114,   114,   114,   110,   525,     7,
       7,   249,   253,     7,     7,   196,   552,    10,   238,     7,
     197,   257,   198,   130,     7,   268,   132,   199,     7,   771,
     200,   653,   201,   202,   248,   100,    10,   773,   272,   111,
      88,   203,   254,   101,   102,   287,   204,   776,    40,   100,
     232,   205,   778,   290,   367,   136,   158,   553,   554,   555,
     292,     7,   521,   669,   293,   617,   618,   617,   618,   309,
     137,   101,   102,   617,   618,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   600,   568,   809,
     173,     7,   175,   619,   601,   630,   168,   176,   177,   617,
     618,   668,   173,   174,   175,   336,   259,   260,     7,   176,
     177,   670,   670,   670,   670,   250,   670,   670,   670,   670,
     569,   670,   670,     7,   670,   670,   670,   700,   178,     7,
     469,   184,   457,   277,   278,   279,   280,     7,   254,   361,
     362,   363,   364,   490,   253,   531,   253,   149,   706,   254,
     462,   707,   708,   709,    81,   374,   375,   376,   377,   542,
     717,   378,   254,   150,   385,   721,   690,   165,   166,   173,
     395,   747,   176,   177,   431,   522,   176,   177,   691,   408,
     336,    81,   151,   703,    82,   132,   750,    83,   216,   671,
     671,   671,   671,   139,   671,   671,   671,   671,   157,   671,
     671,   210,   671,   671,   671,   449,   450,   451,   253,   222,
     774,   775,   226,   777,   779,   780,   781,   452,   453,   454,
     606,   509,   789,   535,   536,   458,   612,   613,   614,   146,
     223,   795,   224,   230,   463,   647,   648,   649,   385,   729,
     730,   731,   732,   733,   227,   533,   224,   228,   802,   224,
     659,   660,   661,   805,   234,   806,   807,   808,   810,   437,
     438,   439,   812,   813,   319,   331,   320,   332,   236,   651,
     815,   652,   237,   816,   602,   603,   604,   605,   607,   608,
     609,   610,   611,   666,   254,   224,   386,   387,   793,   388,
     389,   336,   245,   508,   676,   677,   678,   336,   679,   680,
     681,   682,   271,   683,   684,   246,   685,   686,   687,   390,
     391,   341,   405,   626,   499,   500,   702,   247,   253,   704,
     576,   577,   535,   536,   594,   595,   725,   726,    82,   782,
     169,   170,   258,   261,   262,   263,   385,   274,   534,   264,
     265,   266,   385,   543,   544,   545,   224,   317,   718,   267,
     702,    13,    14,    15,   275,    16,    17,    18,    19,   276,
     289,    20,    21,    22,    23,    24,   718,    25,    26,    27,
      28,    29,   291,    30,   314,   316,   341,   318,   359,   379,
     381,   417,   132,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   421,   422,   464,   423,   424,   426,   427,   428,
     429,   620,   430,   441,   442,   443,   149,   444,   445,   446,
     447,   448,   455,   468,   470,   471,   489,   472,   473,   474,
     509,   475,   476,   478,   483,   486,   487,   488,   491,   492,
     493,   494,   495,   496,   497,   572,   498,    40,    41,   526,
      42,   575,   583,   524,   584,   585,   586,   587,   588,   657,
      81,   629,    43,  -231,   635,   640,   650,   643,   621,   617,
     688,   695,   711,    13,    14,    15,   720,    16,    17,    18,
      19,   722,   742,    20,    21,    22,    23,    24,   723,    25,
      26,    27,    28,    29,   724,    30,   753,   758,   764,   693,
     694,   769,   658,   782,   132,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   784,    82,    89,   140,   219,   346,
     406,   347,   537,   580,   512,   459,   477,   705,   657,   348,
     349,   657,   657,   657,   368,   288,   530,   622,   762,   689,
     665,   746,   788,   801,   768,   657,   792,   699,   716,   523,
     728,   719,   233,   757,   710,   797,   134,   270,   582,   748,
      41,   396,    42,   212,     0,     0,   657,     0,     0,     0,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
       0,   763,     0,     0,     0,     0,     0,     0,   772,     0,
     657,   657,     0,   657,   657,   657,   657,     0,     0,     0,
       0,     0,   657,     0,     0,     0,     0,     0,   253,   751,
     752,   657,   755,   756,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   800,     0,     0,     0,     0,   657,     0,
       0,     0,     0,   657,     0,   657,   657,   657,   657,     0,
       0,     0,   657,   657,     0,     0,     0,     0,     0,     0,
     657,     0,     0,   657,   796,     0,     0,     0,     0,   798,
       0,     0,     0,     0,   799,   115,   116,   117,   118,   119,
       0,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,   811,     0,     0,     0,     0,     0,    13,    14,    15,
     814,    16,    17,    18,    19,     0,     0,    20,    21,    22,
      23,    24,     0,    25,    26,    27,    28,    29,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,   181,   182,   183,
       0,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,     0,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,    43,     0,
       0,   225,    13,    14,    15,     0,    16,    17,    18,    19,
       0,     0,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,    29,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
     396,    42,     0,     0,     0,   310,   311,   312,   313,     0,
     315,     0,     0,   397,     0,     0,     0,     0,   321,     0,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   333,     0,     0,   337,   338,   339,
     340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   369,   370,   371,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   411,   412,   413,   414,   415,   416,     0,
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
     514,   515,   516,   517,   518,   519,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   546,   547,   548,
     549,     0,     0,     0,     0,     0,     0,   551,     0,     0,
       0,     0,     0,     0,     0,   578,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   627
};

static const yytype_int16 yycheck[] =
{
       1,   184,    96,    97,   315,    98,   244,   136,   185,    10,
     351,     5,    13,    14,    15,    16,    17,    18,    19,    20,
       5,    22,    23,    24,   374,   375,   376,   377,   431,    11,
       8,    21,   435,    13,    13,    13,    22,    15,    22,   398,
     551,    42,    20,   317,   342,    23,    98,    25,    26,     8,
      22,   764,   146,    29,    30,    31,    34,   568,   569,   100,
      91,    39,   103,   431,    97,    91,    44,   435,   579,   342,
      46,    47,    48,    49,    91,    91,    91,   480,   791,    54,
      55,   112,    36,    37,    38,   342,   112,    88,   110,   111,
     342,   764,    93,   119,    92,    96,    97,   113,    12,   100,
     398,   460,   103,   155,   119,   379,   617,   618,    13,   110,
     111,     0,   480,     7,   112,    20,   627,   790,    12,   160,
     114,   462,   120,    99,    92,   398,   116,   468,   114,   114,
     112,   132,   116,   113,   113,   113,   111,   113,   139,    93,
      94,   398,   114,    57,   112,   146,   398,   550,    29,    30,
      31,   173,   174,   175,   176,   177,    86,    87,    88,   160,
     112,     9,    10,    93,    94,    46,    47,    48,    49,    86,
      87,    91,   173,   174,   175,   176,   177,    85,   489,    91,
      91,   182,   183,    91,    91,     8,    13,     8,   118,    91,
      13,   368,    15,   112,    91,   196,    44,    20,    91,   119,
      23,   118,    25,    26,   115,   112,     8,   119,   209,   117,
      12,    34,    91,   120,   121,   216,    39,   119,    99,   112,
     113,    44,   119,   224,   318,   112,   119,    54,    55,    56,
     231,    91,   113,   112,   235,    86,    87,    86,    87,   477,
     114,   120,   121,    86,    87,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    13,    85,   119,
      86,    91,    88,   114,    20,   114,   119,    93,    94,    86,
      87,   114,    86,    87,    88,   276,   114,   115,    91,    93,
      94,   631,   632,   633,   634,   115,   636,   637,   638,   639,
     117,   641,   642,    91,   644,   645,   646,   114,   112,    91,
     113,    13,   395,   104,   105,   106,   107,    91,    91,   310,
     311,   312,   313,   442,   315,   113,   317,   318,   689,    91,
     112,   692,   693,   694,    92,   326,   327,   328,   329,   113,
     113,   332,    91,   114,   335,   706,    91,    89,    90,    86,
     341,   113,    93,    94,   112,   113,    93,    94,   103,   350,
     351,    92,    22,   112,    95,    44,   727,    98,     8,   631,
     632,   633,   634,     7,   636,   637,   638,   639,   114,   641,
     642,   114,   644,   645,   646,   108,   109,   110,   379,   114,
     751,   752,   114,   754,   755,   756,   757,   108,   109,   110,
     559,    40,   763,    42,    43,   396,   565,   566,   567,   116,
     114,   772,   116,   114,   405,    82,    83,    84,   409,    63,
      64,    65,    66,    67,   114,   508,   116,   114,   789,   116,
      68,    69,    70,   794,   114,   796,   797,   798,   799,   375,
     376,   377,   803,   804,   112,   114,   114,   116,   114,    82,
     811,    84,   114,   814,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   114,    91,   116,    54,    55,   769,    54,
      55,   462,   115,   464,   632,   633,   634,   468,   636,   637,
     638,   639,   114,   641,   642,   115,   644,   645,   646,    54,
      55,    34,    35,   577,     9,    10,   669,   115,   489,   672,
     114,   115,    42,    43,    93,    94,     3,     4,    95,    96,
     108,   109,   115,   115,   115,   115,   507,    16,   509,   115,
     115,   115,   513,   514,   515,   516,   116,   119,   701,   115,
     703,    13,    14,    15,   113,    17,    18,    19,    20,   112,
     114,    23,    24,    25,    26,    27,   719,    29,    30,    31,
      32,    33,   114,    35,   114,   114,    34,   115,    28,    40,
      28,   112,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   114,   114,    39,   114,   114,   114,   114,   114,
     114,   572,   114,   114,   112,   114,   577,   114,   114,   114,
     114,   114,   114,   112,   115,   115,    41,   115,   115,   115,
      40,   115,   115,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,    12,   114,    99,   100,   113,
     102,   114,   114,   119,   114,   114,   114,   114,   114,   620,
      92,   114,   114,    76,    73,    76,    84,    79,    57,    86,
     115,    71,    58,    13,    14,    15,   115,    17,    18,    19,
      20,   114,    59,    23,    24,    25,    26,    27,   114,    29,
      30,    31,    32,    33,   114,    35,    92,    61,    60,   660,
     661,   115,   621,    96,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    62,    95,    11,    90,   143,   282,
     344,   282,   510,   538,   466,   398,   417,   688,   689,   282,
     282,   692,   693,   694,   319,   217,   502,   573,   735,   658,
     624,   714,   760,   786,   744,   706,   766,   663,   697,   480,
     711,   703,   160,   733,   695,   776,    76,   206,   543,   720,
     100,   101,   102,   133,    -1,    -1,   727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,   749,    -1,
     751,   752,    -1,   754,   755,   756,   757,    -1,    -1,    -1,
      -1,    -1,   763,    -1,    -1,    -1,    -1,    -1,   769,   728,
     729,   772,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   784,    -1,    -1,    -1,    -1,   789,    -1,
      -1,    -1,    -1,   794,    -1,   796,   797,   798,   799,    -1,
      -1,    -1,   803,   804,    -1,    -1,    -1,    -1,    -1,    -1,
     811,    -1,    -1,   814,   773,    -1,    -1,    -1,    -1,   778,
      -1,    -1,    -1,    -1,   783,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,   800,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
     809,    17,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    99,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,   114,    -1,
      -1,   151,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
     250,    -1,    -1,   114,    -1,    -1,    -1,    -1,   258,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,   277,   278,   279,
     280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,   295,   296,   297,   298,   299,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,   322,   323,   324,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,   353,   354,   355,   356,   357,   358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,   471,   472,   473,   474,   475,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,
     500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,   518,   519,
     520,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    97,   123,   124,   125,   302,   303,    91,   293,     0,
       8,   128,   129,    13,    14,    15,    17,    18,    19,    20,
      23,    24,    25,    26,    27,    29,    30,    31,    32,    33,
      35,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      99,   100,   102,   114,   161,   162,   163,   164,   165,   166,
     167,   168,   170,   171,   173,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   205,   301,   305,   306,   307,   308,   314,
     317,    92,    95,    98,   267,   297,   304,   293,    12,   129,
     130,   131,   293,   293,   293,   293,   293,   293,   293,   293,
     112,   120,   121,   279,   280,   281,   289,   293,   293,   293,
      85,   117,   175,   176,   293,   281,   281,   281,   281,   281,
     112,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     112,   293,    44,   229,   307,   319,   112,   114,   293,     7,
     131,   132,   133,   134,   135,    21,   116,   169,   278,   293,
     114,    22,   148,   278,   278,   148,   169,   114,   119,   289,
     290,   291,   293,   289,   293,    89,    90,   172,   119,   172,
     172,   175,   175,    86,    87,    88,    93,    94,   112,   281,
     281,   281,   281,   281,    13,   203,   204,   281,   281,   281,
     281,   281,   281,   281,   281,   281,     8,    13,    15,    20,
      23,    25,    26,    34,    39,    44,   309,   310,   311,   312,
     114,   293,   319,   305,   293,   126,     8,   136,   137,   135,
     281,   278,   114,   114,   116,   281,   114,   114,   114,   169,
     114,   292,   113,   291,   114,   282,   114,   114,   118,   175,
     175,   175,   175,   175,   177,   115,   115,   115,   115,   293,
     115,   276,   277,   293,    91,   287,   113,   204,   115,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   293,   113,
     310,   114,   293,   313,    16,   113,   112,   104,   105,   106,
     107,   138,   139,   140,   141,   142,   143,   293,   137,   114,
     293,   114,   293,   293,    29,    30,    31,    46,    47,    48,
      49,   113,   178,   179,   180,   181,   182,   183,   184,   308,
     281,   281,   281,   281,   114,   281,   114,   119,   115,   112,
     114,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   114,   116,   281,   315,   288,   293,   281,   281,   281,
     281,    34,   144,   145,   146,   147,   140,   141,   142,   143,
      11,   112,   281,   281,   281,   281,   281,   281,   281,    28,
     174,   293,   293,   293,   293,   276,   277,   278,   203,   281,
     281,   281,   281,   281,   293,   293,   293,   293,   293,    40,
     230,    28,   316,   318,   113,   293,    54,    55,    54,    55,
      54,    55,    54,    55,   111,   293,   101,   114,   159,   160,
     161,   162,   173,   300,   314,    35,   147,   149,   293,   288,
     281,   281,   281,   281,   281,   281,   281,   112,     5,   114,
     296,   114,   114,   114,   114,   113,   114,   114,   114,   114,
     114,   112,   268,   269,   273,   279,   297,   268,   268,   268,
     277,   114,   112,   114,   114,   114,   114,   114,   114,   108,
     109,   110,   108,   109,   110,   114,   114,   148,   293,   160,
     228,   229,   112,   293,    39,   150,   151,   152,   112,   113,
     115,   115,   115,   115,   115,   115,   115,   177,   114,   269,
     270,   271,   273,   114,   269,   273,   114,   114,   114,    41,
     305,   114,   114,   114,   114,   114,   114,   114,   114,     9,
      10,   206,   207,   208,   209,   210,   229,   288,   293,    40,
     153,   154,   152,   288,   281,   281,   281,   281,   281,   281,
     281,   113,   113,   271,   119,   276,   113,   281,   281,   127,
     208,   113,   114,   148,   293,    42,    43,   154,   155,   156,
     157,   158,   113,   293,   293,   293,   281,   281,   281,   281,
     272,   281,    13,    54,    55,    56,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    85,   117,
     211,   212,    12,   231,   232,   114,   114,   115,   281,   281,
     156,   114,   296,   114,   114,   114,   114,   114,   114,   273,
     211,    36,    37,    38,    93,    94,   226,   227,    13,    20,
      13,    20,   226,   226,   226,   226,   227,   226,   226,   226,
     226,   226,   227,   227,   227,   211,   211,    86,    87,   114,
     293,    57,   232,   241,   242,   243,   278,   281,   211,   114,
     114,   222,   224,   223,   225,    73,   213,   214,   215,   216,
      76,   217,   218,    79,   219,   220,   221,    82,    83,    84,
      84,    82,    84,   118,   211,   211,   274,   293,   297,    68,
      69,    70,   260,   261,   262,   243,   114,   211,   114,   112,
     279,   280,   283,   284,   285,   287,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   115,   297,
      91,   103,   294,   293,   293,    71,   263,   264,   265,   262,
     114,   286,   287,   112,   287,   293,   274,   274,   274,   274,
     294,    58,   244,   245,   246,   247,   265,   113,   287,   286,
     115,   274,   114,   114,   114,     3,     4,   295,   293,    63,
      64,    65,    66,    67,   233,   234,   235,   236,   237,   238,
     239,   240,    59,   254,   255,   256,   247,   113,   293,   119,
     274,   297,   297,    92,   298,   297,   297,   295,    61,   248,
     249,   250,   235,   293,    60,   257,   258,   259,   256,   115,
     275,   119,   293,   119,   274,   274,   119,   274,   119,   274,
     274,   274,    96,   299,    62,   251,   252,   253,   250,   274,
     267,   299,   259,   276,   266,   274,   297,   298,   297,   297,
     293,   253,   274,   267,   299,   274,   274,   274,   274,   119,
     274,   297,   274,   274,   297,   274,   274
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   122,   123,   123,   125,   126,   127,   124,   128,   128,
     129,   130,   130,   131,   132,   133,   133,   134,   134,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     145,   146,   146,   147,   147,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   161,   161,   161,   161,   161,   161,   161,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   163,   164,   165,   165,   166,   167,   168,   169,   169,
     170,   171,   172,   172,   173,   174,   174,   175,   175,   175,
     175,   175,   175,   175,   175,   176,   177,   177,   178,   178,
     178,   179,   179,   179,   179,   180,   180,   180,   180,   181,
     182,   183,   184,   185,   185,   185,   185,   186,   186,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   201,   202,   203,   203,   204,   204,   205,   206,
     206,   207,   207,   208,   208,   209,   210,   211,   211,   211,
     211,   211,   212,   212,   212,   213,   212,   214,   212,   215,
     212,   216,   212,   217,   212,   218,   212,   219,   212,   220,
     212,   221,   212,   212,   222,   212,   223,   212,   212,   224,
     212,   225,   212,   212,   212,   212,   212,   212,   212,   226,
     226,   227,   227,   227,   227,   228,   228,   229,   230,   230,
     231,   231,   232,   233,   233,   234,   234,   235,   235,   235,
     235,   235,   236,   237,   237,   238,   238,   239,   240,   241,
     241,   242,   242,   243,   244,   245,   245,   246,   246,   247,
     247,   248,   248,   249,   249,   250,   250,   251,   251,   252,
     252,   253,   254,   254,   255,   255,   256,   257,   257,   258,
     258,   259,   259,   260,   260,   261,   261,   262,   262,   262,
     263,   263,   264,   264,   265,   266,   265,   265,   267,   268,
     268,   268,   268,   269,   270,   270,   272,   271,   271,   271,
     273,   274,   275,   275,   276,   276,   277,   277,   278,   278,
     279,   280,   281,   281,   281,   281,   281,   282,   281,   283,
     284,   285,   285,   285,   285,   285,   286,   286,   287,   288,
     288,   289,   290,   290,   291,   292,   291,   291,   293,   294,
     294,   295,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   304,   304,   305,   306,   306,   307,   307,   307,
     307,   307,   307,   308,   309,   309,   310,   310,   311,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   313,   313,
     315,   314,   316,   316,   317,   318,   319,   319
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     0,     0,    19,     1,     2,
       2,     1,     2,     2,     2,     1,     0,     1,     2,     5,
       1,     2,     5,     4,     7,     1,     0,     1,     1,     1,
       1,     2,     2,     2,     2,     4,     4,     4,     4,     4,
       4,     5,     5,     5,     5,     5,     5,     4,     1,     0,
       5,     1,     2,     4,     3,     2,     2,     4,     1,     0,
       1,     2,     4,     3,     1,     2,     5,     3,     1,     2,
       1,     1,     5,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     5,     4,     4,     4,     4,     2,     0,
       4,     4,     1,     1,     6,     4,     0,     3,     2,     3,
       3,     3,     3,     3,     1,     1,     2,     0,     1,     1,
       1,     8,     7,     7,     7,     1,     1,     1,     1,     7,
       7,     7,     7,     8,     7,     7,     7,     5,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     7,
       7,     7,     7,     8,     8,     8,     8,     3,     5,     4,
       4,     5,     7,     4,     1,     2,     3,     5,     4,     1,
       0,     1,     2,     1,     1,     5,     4,     3,     2,     3,
       3,     1,     3,     3,     3,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     2,     0,
       4,     0,     4,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     6,     4,     0,
       1,     2,     3,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     3,     3,     5,     3,     5,     3,     3,     1,
       0,     1,     2,     5,     3,     1,     0,     1,     2,     4,
       6,     1,     0,     1,     2,     4,     6,     1,     0,     1,
       2,     4,     1,     0,     1,     2,     4,     1,     0,     1,
       2,     4,     4,     1,     0,     1,     2,     4,     4,     4,
       1,     0,     1,     2,     6,     0,     7,     4,     1,     1,
       1,     2,     2,     3,     1,     2,     0,     4,     1,     1,
       1,     6,     2,     0,     3,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     2,     0,     4,     1,
       1,     1,     3,     1,     2,     4,     1,     2,     1,     1,
       2,     3,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       4,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     1,     2,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     6,     4,     0,     1,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 4:
#line 169 "external/selinux/checkpolicy/policy_parse.y"
                          { if (define_policy(pass, 0) == -1) return -1; }
#line 2205 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 5:
#line 171 "external/selinux/checkpolicy/policy_parse.y"
                          { if (pass == 1) { if (policydb_index_classes(policydbp)) return -1; }
                            else if (pass == 2) { if (policydb_index_others(NULL, policydbp, 0)) return -1; }}
#line 2212 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 6:
#line 174 "external/selinux/checkpolicy/policy_parse.y"
                         { if (pass == 1) { if (policydb_index_bools(policydbp)) return -1;}
			   else if (pass == 2) { if (policydb_index_others(NULL, policydbp, 0)) return -1;}}
#line 2219 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 10:
#line 182 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_class()) return -1;}
#line 2225 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 13:
#line 188 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_initial_sid()) return -1;}
#line 2231 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 19:
#line 199 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_common_perms()) return -1;}
#line 2237 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 22:
#line 205 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_av_perms(FALSE)) return -1;}
#line 2243 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 23:
#line 207 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_av_perms(TRUE)) return -1;}
#line 2249 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 24:
#line 209 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_av_perms(TRUE)) return -1;}
#line 2255 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 35:
#line 224 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_user(DEFAULT_SOURCE)) return -1; }
#line 2261 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 36:
#line 226 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_user(DEFAULT_TARGET)) return -1; }
#line 2267 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 37:
#line 229 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_role(DEFAULT_SOURCE)) return -1; }
#line 2273 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 38:
#line 231 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_role(DEFAULT_TARGET)) return -1; }
#line 2279 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 39:
#line 234 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_type(DEFAULT_SOURCE)) return -1; }
#line 2285 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 40:
#line 236 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_type(DEFAULT_TARGET)) return -1; }
#line 2291 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 41:
#line 239 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_SOURCE_LOW)) return -1; }
#line 2297 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 42:
#line 241 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_SOURCE_HIGH)) return -1; }
#line 2303 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 43:
#line 243 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_SOURCE_LOW_HIGH)) return -1; }
#line 2309 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 44:
#line 245 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_TARGET_LOW)) return -1; }
#line 2315 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 45:
#line 247 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_TARGET_HIGH)) return -1; }
#line 2321 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 46:
#line 249 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_TARGET_LOW_HIGH)) return -1; }
#line 2327 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 47:
#line 251 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_default_range(DEFAULT_GLBLUB)) return -1; }
#line 2333 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 53:
#line 262 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_sens()) return -1;}
#line 2339 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 54:
#line 264 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_sens()) return -1;}
#line 2345 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 56:
#line 269 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_dominance()) return -1;}
#line 2351 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 57:
#line 271 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_dominance()) return -1;}
#line 2357 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 62:
#line 280 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_category()) return -1;}
#line 2363 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 63:
#line 282 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_category()) return -1;}
#line 2369 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 66:
#line 288 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_level()) return -1;}
#line 2375 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 67:
#line 290 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_level()) return -1;}
#line 2381 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 72:
#line 299 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_constraint((constraint_expr_t*)(yyvsp[-1].valptr))) return -1; }
#line 2387 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 73:
#line 302 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_validatetrans((constraint_expr_t*)(yyvsp[-1].valptr))) return -1; }
#line 2393 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 101:
#line 336 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_attrib()) return -1;}
#line 2399 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 102:
#line 339 "external/selinux/checkpolicy/policy_parse.y"
                        { if (expand_attrib()) return -1;}
#line 2405 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 103:
#line 342 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_type(1)) return -1;}
#line 2411 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 104:
#line 344 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_type(0)) return -1;}
#line 2417 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 105:
#line 347 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_typealias()) return -1;}
#line 2423 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 106:
#line 350 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_typeattribute()) return -1;}
#line 2429 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 107:
#line 353 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_typebounds()) return -1;}
#line 2435 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 110:
#line 359 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_bool_tunable(0)) return -1; }
#line 2441 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 111:
#line 362 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_bool_tunable(1)) return -1; }
#line 2447 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 112:
#line 365 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("T",0)) return -1; }
#line 2453 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 113:
#line 367 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("F",0)) return -1; }
#line 2459 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 114:
#line 370 "external/selinux/checkpolicy/policy_parse.y"
                        { if (pass == 2) { if (define_conditional((cond_expr_t*)(yyvsp[-4].ptr), (avrule_t*)(yyvsp[-2].ptr), (avrule_t*)(yyvsp[0].ptr)) < 0) return -1;  }}
#line 2465 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 115:
#line 373 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 2471 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 116:
#line 375 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = NULL; }
#line 2477 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 117:
#line 378 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[-1].ptr);}
#line 2483 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 118:
#line 380 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_NOT, (yyvsp[0].ptr), 0);
			  if ((yyval.ptr) == 0) return -1; }
#line 2490 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 119:
#line 383 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_AND, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
#line 2497 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 120:
#line 386 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_OR, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			  if ((yyval.ptr) == 0) return   -1; }
#line 2504 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 121:
#line 389 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_XOR, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
#line 2511 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 122:
#line 392 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_EQ, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
#line 2518 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 123:
#line 395 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_NEQ, (yyvsp[-2].ptr), (yyvsp[0].ptr));
			  if ((yyval.ptr) == 0) return  -1; }
#line 2525 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 124:
#line 398 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2531 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 125:
#line 401 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_expr(COND_BOOL,0, 0);
			  if ((yyval.ptr) == COND_ERR) return   -1; }
#line 2538 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 126:
#line 405 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_pol_list((avrule_t *)(yyvsp[-1].ptr), (avrule_t *)(yyvsp[0].ptr)); }
#line 2544 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 127:
#line 407 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = NULL; }
#line 2550 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 128:
#line 410 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2556 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 129:
#line 412 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2562 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 130:
#line 414 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = NULL; }
#line 2568 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 131:
#line 417 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_filename_trans() ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
#line 2575 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 132:
#line 420 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_compute_type(AVRULE_TRANSITION) ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
#line 2582 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 133:
#line 423 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_compute_type(AVRULE_MEMBER) ;
                          if ((yyval.ptr) ==  COND_ERR) return -1;}
#line 2589 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 134:
#line 426 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_compute_type(AVRULE_CHANGE) ;
                          if ((yyval.ptr) == COND_ERR) return -1;}
#line 2596 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 135:
#line 430 "external/selinux/checkpolicy/policy_parse.y"
                          { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2602 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 136:
#line 432 "external/selinux/checkpolicy/policy_parse.y"
                          { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2608 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 137:
#line 434 "external/selinux/checkpolicy/policy_parse.y"
                          { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2614 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 138:
#line 436 "external/selinux/checkpolicy/policy_parse.y"
                          { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2620 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 139:
#line 439 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_te_avtab(AVRULE_ALLOWED) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
#line 2627 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 140:
#line 443 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_te_avtab(AVRULE_AUDITALLOW) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
#line 2634 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 141:
#line 447 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_te_avtab(AVRULE_AUDITDENY) ;
                          if ((yyval.ptr) == COND_ERR) return -1; }
#line 2641 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 142:
#line 451 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = define_cond_te_avtab(AVRULE_DONTAUDIT);
                          if ((yyval.ptr) == COND_ERR) return -1; }
#line 2648 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 143:
#line 456 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_filename_trans()) return -1; }
#line 2654 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 144:
#line 458 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_compute_type(AVRULE_TRANSITION)) return -1;}
#line 2660 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 145:
#line 460 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_compute_type(AVRULE_MEMBER)) return -1;}
#line 2666 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 146:
#line 462 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_compute_type(AVRULE_CHANGE)) return -1;}
#line 2672 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 147:
#line 465 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_range_trans(0)) return -1; }
#line 2678 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 148:
#line 467 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_range_trans(1)) return -1; }
#line 2684 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 158:
#line 480 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab(AVRULE_ALLOWED)) return -1; }
#line 2690 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 159:
#line 483 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab(AVRULE_AUDITALLOW)) return -1; }
#line 2696 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 160:
#line 486 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab(AVRULE_AUDITDENY)) return -1; }
#line 2702 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 161:
#line 489 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab(AVRULE_DONTAUDIT)) return -1; }
#line 2708 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 162:
#line 492 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab(AVRULE_NEVERALLOW)) return -1; }
#line 2714 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 163:
#line 495 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab_extended_perms(AVRULE_XPERMS_ALLOWED)) return -1; }
#line 2720 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 164:
#line 498 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab_extended_perms(AVRULE_XPERMS_AUDITALLOW)) return -1; }
#line 2726 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 165:
#line 501 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab_extended_perms(AVRULE_XPERMS_DONTAUDIT)) return -1; }
#line 2732 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 166:
#line 504 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_te_avtab_extended_perms(AVRULE_XPERMS_NEVERALLOW)) return -1; }
#line 2738 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 167:
#line 507 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_attrib_role()) return -1; }
#line 2744 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 168:
#line 510 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_role_types()) return -1;}
#line 2750 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 169:
#line 513 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_role_attr()) return -1;}
#line 2756 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 171:
#line 518 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_role_trans(0)) return -1; }
#line 2762 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 172:
#line 520 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_role_trans(1)) return -1;}
#line 2768 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 173:
#line 523 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_role_allow()) return -1; }
#line 2774 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 174:
#line 526 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = (yyvsp[0].ptr); }
#line 2780 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 175:
#line 528 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.ptr) = merge_roles_dom((role_datum_t*)(yyvsp[-1].ptr), (role_datum_t*)(yyvsp[0].ptr)); if ((yyval.ptr) == 0) return -1;}
#line 2786 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 176:
#line 531 "external/selinux/checkpolicy/policy_parse.y"
                        {(yyval.ptr) = define_role_dom(NULL); if ((yyval.ptr) == 0) return -1;}
#line 2792 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 177:
#line 533 "external/selinux/checkpolicy/policy_parse.y"
                        {(yyval.ptr) = define_role_dom((role_datum_t*)(yyvsp[-1].ptr)); if ((yyval.ptr) == 0) return -1;}
#line 2798 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 178:
#line 536 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_roleattribute()) return -1;}
#line 2804 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 185:
#line 548 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_constraint((constraint_expr_t*)(yyvsp[-1].valptr))) return -1; }
#line 2810 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 186:
#line 551 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_validatetrans((constraint_expr_t*)(yyvsp[-1].valptr))) return -1; }
#line 2816 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 187:
#line 554 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = (yyvsp[-1].valptr); }
#line 2822 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 188:
#line 556 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NOT, (yyvsp[0].valptr), 0);
			  if ((yyval.valptr) == 0) return -1; }
#line 2829 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 189:
#line 559 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_AND, (yyvsp[-2].valptr), (yyvsp[0].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2836 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 190:
#line 562 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_OR, (yyvsp[-2].valptr), (yyvsp[0].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2843 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 191:
#line 565 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = (yyvsp[0].valptr); }
#line 2849 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 192:
#line 568 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_USER, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2856 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 193:
#line 571 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_ROLE, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2863 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 194:
#line 574 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_TYPE, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2870 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 195:
#line 576 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2876 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 196:
#line 577 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_USER, (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2883 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 197:
#line 579 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2889 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 198:
#line 580 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_USER | CEXPR_TARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2896 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 199:
#line 582 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2902 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 200:
#line 583 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_USER | CEXPR_XTARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2909 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 201:
#line 585 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2915 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 202:
#line 586 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_ROLE, (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2922 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 203:
#line 588 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2928 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 204:
#line 589 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_TARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2935 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 205:
#line 591 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2941 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 206:
#line 592 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_XTARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2948 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 207:
#line 594 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2954 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 208:
#line 595 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_TYPE, (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2961 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 209:
#line 597 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2967 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 210:
#line 598 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_TARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2974 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 211:
#line 600 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_separator(1)) return -1; }
#line 2980 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 212:
#line 601 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_XTARGET), (yyvsp[-2].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 2987 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 213:
#line 604 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_USER, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
#line 2994 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 214:
#line 606 "external/selinux/checkpolicy/policy_parse.y"
                                      { if (insert_separator(1)) return -1; }
#line 3000 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 215:
#line 607 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_ROLE, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
#line 3007 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 216:
#line 609 "external/selinux/checkpolicy/policy_parse.y"
                                      { if (insert_separator(1)) return -1; }
#line 3013 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 217:
#line 610 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_ROLE | CEXPR_TARGET), CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
#line 3020 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 218:
#line 613 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_ROLE, (yyvsp[0].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3027 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 219:
#line 615 "external/selinux/checkpolicy/policy_parse.y"
                                      { if (insert_separator(1)) return -1; }
#line 3033 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 220:
#line 616 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, CEXPR_TYPE, CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
#line 3040 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 221:
#line 618 "external/selinux/checkpolicy/policy_parse.y"
                                      { if (insert_separator(1)) return -1; }
#line 3046 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 222:
#line 619 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_NAMES, (CEXPR_TYPE | CEXPR_TARGET), CEXPR_EQ);
			  if ((yyval.valptr) == 0) return -1; }
#line 3053 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 223:
#line 622 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1L2, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3060 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 224:
#line 625 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1H2, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3067 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 225:
#line 628 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_H1L2, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3074 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 226:
#line 631 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_H1H2, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3081 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 227:
#line 634 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L1H1, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3088 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 228:
#line 637 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = define_cexpr(CEXPR_ATTR, CEXPR_L2H2, (yyvsp[-1].valptr));
			  if ((yyval.valptr) == 0) return -1; }
#line 3095 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 229:
#line 641 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = CEXPR_EQ; }
#line 3101 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 230:
#line 643 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = CEXPR_NEQ; }
#line 3107 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 231:
#line 646 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = (yyvsp[0].valptr); }
#line 3113 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 232:
#line 648 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = CEXPR_DOM; }
#line 3119 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 233:
#line 650 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = CEXPR_DOMBY; }
#line 3125 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 234:
#line 652 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.valptr) = CEXPR_INCOMP; }
#line 3131 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 237:
#line 658 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_user()) return -1;}
#line 3137 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 242:
#line 667 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_initial_sid_context()) return -1;}
#line 3143 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 252:
#line 681 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_pirq_context((yyvsp[-1].val))) return -1;}
#line 3149 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 253:
#line 684 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_iomem_context((yyvsp[-1].val64),(yyvsp[-1].val64))) return -1;}
#line 3155 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 254:
#line 686 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_iomem_context((yyvsp[-3].val64),(yyvsp[-1].val64))) return -1;}
#line 3161 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 255:
#line 689 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ioport_context((yyvsp[-1].val),(yyvsp[-1].val))) return -1;}
#line 3167 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 256:
#line 691 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ioport_context((yyvsp[-3].val),(yyvsp[-1].val))) return -1;}
#line 3173 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 257:
#line 694 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_pcidevice_context((yyvsp[-1].val))) return -1;}
#line 3179 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 258:
#line 697 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_devicetree_context()) return -1;}
#line 3185 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 263:
#line 706 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_fs_context((yyvsp[-3].val),(yyvsp[-2].val))) return -1;}
#line 3191 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 269:
#line 717 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_port_context((yyvsp[-1].val),(yyvsp[-1].val))) return -1;}
#line 3197 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 270:
#line 719 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_port_context((yyvsp[-3].val),(yyvsp[-1].val))) return -1;}
#line 3203 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 275:
#line 728 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ibpkey_context((yyvsp[-1].val),(yyvsp[-1].val))) return -1;}
#line 3209 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 276:
#line 730 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ibpkey_context((yyvsp[-3].val),(yyvsp[-1].val))) return -1;}
#line 3215 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 281:
#line 739 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ibendport_context((yyvsp[-1].val))) return -1;}
#line 3221 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 286:
#line 748 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_netif_context()) return -1;}
#line 3227 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 291:
#line 757 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ipv4_node_context()) return -1;}
#line 3233 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 292:
#line 759 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_ipv6_node_context()) return -1;}
#line 3239 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 297:
#line 768 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_fs_use(SECURITY_FS_USE_XATTR)) return -1;}
#line 3245 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 298:
#line 770 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_fs_use(SECURITY_FS_USE_TASK)) return -1;}
#line 3251 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 299:
#line 772 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_fs_use(SECURITY_FS_USE_TRANS)) return -1;}
#line 3257 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 304:
#line 781 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_genfs_context(1)) return -1;}
#line 3263 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 305:
#line 782 "external/selinux/checkpolicy/policy_parse.y"
                                                           {insert_id("-", 0);}
#line 3269 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 306:
#line 783 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_genfs_context(1)) return -1;}
#line 3275 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 307:
#line 785 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_genfs_context(0)) return -1;}
#line 3281 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 308:
#line 788 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3287 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 309:
#line 791 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_separator(0)) return -1; }
#line 3293 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 310:
#line 793 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_separator(0)) return -1; }
#line 3299 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 311:
#line 795 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("~", 0)) return -1; }
#line 3305 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 312:
#line 797 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("~", 0)) return -1;
			  if (insert_separator(0)) return -1; }
#line 3312 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 316:
#line 805 "external/selinux/checkpolicy/policy_parse.y"
                                { if (insert_id("-", 0)) return -1; }
#line 3318 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 320:
#line 810 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3324 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 324:
#line 818 "external/selinux/checkpolicy/policy_parse.y"
                        {if (insert_separator(0)) return -1;}
#line 3330 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 325:
#line 820 "external/selinux/checkpolicy/policy_parse.y"
                        {if (insert_separator(0)) return -1;}
#line 3336 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 326:
#line 823 "external/selinux/checkpolicy/policy_parse.y"
                        {if (insert_separator(0)) return -1;}
#line 3342 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 327:
#line 825 "external/selinux/checkpolicy/policy_parse.y"
                        {if (insert_separator(0)) return -1;}
#line 3348 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 332:
#line 835 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_separator(0)) return -1; }
#line 3354 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 333:
#line 837 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_separator(0)) return -1; }
#line 3360 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 334:
#line 839 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("*", 0)) return -1; 
			  if (insert_separator(0)) return -1; }
#line 3367 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 335:
#line 842 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("~", 0)) return -1;
			  if (insert_separator(0)) return -1; }
#line 3374 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 336:
#line 845 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("~", 0)) return -1; 
			  if (insert_separator(0)) return -1; }
#line 3381 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 337:
#line 847 "external/selinux/checkpolicy/policy_parse.y"
                                         { if (insert_id("-", 0)) return -1; }
#line 3387 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 338:
#line 848 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_separator(0)) return -1; }
#line 3393 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 339:
#line 851 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("~", 1)) return -1; }
#line 3399 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 340:
#line 854 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id("*", 1)) return -1; }
#line 3405 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 348:
#line 866 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext, 1)) return -1; }
#line 3411 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 355:
#line 875 "external/selinux/checkpolicy/policy_parse.y"
                                           { if (insert_id("-", 0)) return -1; }
#line 3417 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 358:
#line 878 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3423 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 359:
#line 881 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3429 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 360:
#line 883 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3435 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 361:
#line 886 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3441 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 362:
#line 888 "external/selinux/checkpolicy/policy_parse.y"
                        { yytext[strlen(yytext) - 1] = '\0'; if (insert_id(yytext + 1,0)) return -1; }
#line 3447 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 363:
#line 891 "external/selinux/checkpolicy/policy_parse.y"
                        { yytext[strlen(yytext) - 1] = '\0'; if (insert_id(yytext + 1,0)) return -1; }
#line 3453 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 364:
#line 894 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.val) = strtoul(yytext,NULL,0); }
#line 3459 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 365:
#line 897 "external/selinux/checkpolicy/policy_parse.y"
                        { (yyval.val64) = strtoull(yytext,NULL,0); }
#line 3465 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 366:
#line 900 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3471 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 367:
#line 903 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_polcap()) return -1;}
#line 3477 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 368:
#line 906 "external/selinux/checkpolicy/policy_parse.y"
                        {if (define_permissive()) return -1;}
#line 3483 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 369:
#line 911 "external/selinux/checkpolicy/policy_parse.y"
                        { if (end_avrule_block(pass) == -1) return -1;
                          if (policydb_index_others(NULL, policydbp, 0)) return -1;
                        }
#line 3491 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 370:
#line 916 "external/selinux/checkpolicy/policy_parse.y"
                        { if (define_policy(pass, 1) == -1) return -1; }
#line 3497 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 371:
#line 919 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3503 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 372:
#line 921 "external/selinux/checkpolicy/policy_parse.y"
                        { if (insert_id(yytext,0)) return -1; }
#line 3509 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 388:
#line 945 "external/selinux/checkpolicy/policy_parse.y"
                        { if (require_class(pass)) return -1; }
#line 3515 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 389:
#line 947 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_role; }
#line 3521 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 390:
#line 948 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_type; }
#line 3527 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 391:
#line 949 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_attribute; }
#line 3533 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 392:
#line 950 "external/selinux/checkpolicy/policy_parse.y"
                                           { (yyval.require_func) = require_attribute_role; }
#line 3539 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 393:
#line 951 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_user; }
#line 3545 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 394:
#line 952 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_bool; }
#line 3551 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 395:
#line 953 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_tunable; }
#line 3557 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 396:
#line 954 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_sens; }
#line 3563 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 397:
#line 955 "external/selinux/checkpolicy/policy_parse.y"
                                      { (yyval.require_func) = require_cat; }
#line 3569 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 398:
#line 958 "external/selinux/checkpolicy/policy_parse.y"
                        { if ((yyvsp[-1].require_func) (pass)) return -1; }
#line 3575 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 399:
#line 960 "external/selinux/checkpolicy/policy_parse.y"
                        { if ((yyvsp[-3].require_func) (pass)) return -1; }
#line 3581 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 400:
#line 963 "external/selinux/checkpolicy/policy_parse.y"
                        { if (end_avrule_block(pass) == -1) return -1; }
#line 3587 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 401:
#line 965 "external/selinux/checkpolicy/policy_parse.y"
                        { if (end_optional(pass) == -1) return -1; }
#line 3593 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 402:
#line 968 "external/selinux/checkpolicy/policy_parse.y"
                        { if (end_avrule_block(pass) == -1) return -1; }
#line 3599 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 404:
#line 972 "external/selinux/checkpolicy/policy_parse.y"
                        { if (begin_optional(pass) == -1) return -1; }
#line 3605 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;

  case 405:
#line 975 "external/selinux/checkpolicy/policy_parse.y"
                        { if (begin_optional_else(pass) == -1) return -1; }
#line 3611 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"
    break;


#line 3615 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
