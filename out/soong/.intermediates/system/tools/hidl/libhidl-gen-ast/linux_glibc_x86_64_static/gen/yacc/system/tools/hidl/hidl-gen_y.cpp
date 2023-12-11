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
#line 17 "system/tools/hidl/hidl-gen_y.yy"


#include "AST.h"
#include "Annotation.h"
#include "ArrayType.h"
#include "CompoundType.h"
#include "ConstantExpression.h"
#include "Coordinator.h"
#include "DocComment.h"
#include "EnumType.h"
#include "Interface.h"
#include "Location.h"
#include "Method.h"
#include "Scope.h"
#include "TypeDef.h"
#include "VectorType.h"

#include "hidl-gen_y-helpers.h"

#include <android-base/logging.h>
#include <hidl-util/FQName.h>
#include <hidl-util/StringHelper.h>
#include <stdio.h>

using namespace android;

extern int yylex(yy::parser::semantic_type*, yy::parser::location_type*, void*, AST* const,
                 Scope** const);

void enterScope(AST* /* ast */, Scope** scope, Scope* container) {
    CHECK(container->parent() == (*scope));
    *scope = container;
}

void leaveScope(AST* ast, Scope** scope) {
    CHECK((*scope) != &ast->getRootScope());
    *scope = (*scope)->parent();
}

::android::Location convertYYLoc(const yy::parser::location_type& loc, const AST* ast) {
    return ::android::Location(
            ::android::Position(ast->getCoordinator().makeRelative(*(loc.begin.filename)),
                                loc.begin.line, loc.begin.column),
            ::android::Position(ast->getCoordinator().makeRelative(*(loc.end.filename)),
                                loc.end.line, loc.end.column));
}

bool isValidInterfaceField(const std::string& identifier, std::string *errorMsg) {
    static const std::vector<std::string> reserved({
        // Injected names to C++ interfaces by auto-generated code
        "isRemote", "descriptor", "hidlStaticBlock", "onTransact",
        "castFrom", "Proxy", "Stub", "getService",

        // Injected names to Java interfaces by auto-generated code
        "asInterface", "castFrom", "getService", "toString",

        // Inherited methods from IBase is detected in addMethod. Not added here
        // because we need hidl-gen to compile IBase.

        // Inherited names by interfaces from IInterface / IBinder
        "onAsBinder", "asBinder", "queryLocalInterface", "getInterfaceDescriptor", "isBinderAlive",
        "pingBinder", "dump", "transact", "checkSubclass", "attachObject", "findObject",
        "detachObject", "localBinder", "remoteBinder", "mImpl",

        // Inherited names from HidlInstrumentor
        "InstrumentationEvent", "configureInstrumentation", "registerInstrumentationCallbacks",
        "isInstrumentationLib", "mInstrumentationCal1lbacks", "mEnableInstrumentation",
        "mInstrumentationLibPackage", "mInterfaceName",

        // Collide with names in BsFoo
        "mImpl", "addOnewayTask", "mOnewayQueue",

        // Inherited names from Java IHwInterface
        "asBinder",
    });
    if (std::find(reserved.begin(), reserved.end(), identifier) != reserved.end()) {
        *errorMsg = identifier + " cannot be a name inside an interface";
        return false;
    }
    return true;
}

bool isValidStructField(const std::string& identifier, std::string *errorMsg) {
    static const std::vector<std::string> reserved({
        // Injected names to structs and unions by auto-generated code
        "readEmbeddedFromParcel", "writeEmbeddedToParcel", "readVectorFromParcel",
        "writeVectorToParcel", "writeEmbeddedToBlob",
    });
    if (std::find(reserved.begin(), reserved.end(), identifier) != reserved.end()) {
        *errorMsg = identifier + " cannot be a name inside an struct or union";
        return false;
    }
    return true;
}

bool isValidCompoundTypeField(CompoundType::Style style, const std::string& identifier,
                              std::string *errorMsg) {
    // Unions don't support fix-up types; as such, they can't
    // have name collisions with embedded read/write methods.
    if (style == CompoundType::STYLE_UNION) { return true; }

    return isValidStructField(identifier, errorMsg);;
}

bool isValidIdentifier(const std::string& identifier, std::string *errorMsg) {
    static const std::vector<std::string> keywords({
        "uint8_t", "uint16_t", "uint32_t", "uint64_t",
        "int8_t", "int16_t", "int32_t", "int64_t", "bool", "float", "double",
        "interface", "struct", "union", "string", "vec", "enum", "ref", "handle",
        "package", "import", "typedef", "generates", "oneway", "extends",
        "fmq_sync", "fmq_unsync", "safe_union",
    });
    static const std::vector<std::string> cppKeywords({
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
        "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char16_t", "char32_t", "class", "compl", "concept", "const", "constexpr",
        "const_cast", "continue", "decltype", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "import", "long", "module", "mutable",
        "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq",
        "private", "protected", "public", "register", "reinterpret_cast", "requires", "return",
        "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct",
        "switch", "synchronized", "template", "this", "thread_local", "throw", "true", "try",
        "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
        "volatile", "wchar_t", "while", "xor", "xor_eq",
    });
    static const std::vector<std::string> javaKeywords({
        "abstract", "continue", "for", "new", "switch", "assert", "default", "goto", "package",
        "synchronized", "boolean", "do", "if", "private", "this", "break", "double",
        "implements", "protected", "throw", "byte", "else", "import", "public", "throws",
        "case", "enum", "instanceof", "return", "transient", "catch", "extends", "int",
        "short", "try", "char", "final", "interface", "static", "void", "class", "finally",
        "long", "strictfp", "volatile", "const", "float", "native", "super", "while",
    });
    static const std::vector<std::string> cppCollide({
        "size_t", "offsetof",
    });

    // errors
    if (std::find(keywords.begin(), keywords.end(), identifier) != keywords.end()) {
        *errorMsg = identifier + " is a HIDL keyword "
            "and is therefore not a valid identifier";
        return false;
    }
    if (std::find(cppKeywords.begin(), cppKeywords.end(), identifier) != cppKeywords.end()) {
        *errorMsg = identifier + " is a C++ keyword "
            "and is therefore not a valid identifier";
        return false;
    }
    if (std::find(javaKeywords.begin(), javaKeywords.end(), identifier) != javaKeywords.end()) {
        *errorMsg = identifier + " is a Java keyword "
            "and is therefore not a valid identifier";
        return false;
    }
    if (std::find(cppCollide.begin(), cppCollide.end(), identifier) != cppCollide.end()) {
        *errorMsg = identifier + " collides with reserved names in C++ code "
            "and is therefore not a valid identifier";
        return false;
    }
    if (StringHelper::StartsWith(identifier, "_hidl_")) {
        *errorMsg = identifier + " starts with _hidl_ "
            "and is therefore not a valid identifier";
        return false;
    }
    if (StringHelper::StartsWith(identifier, "hidl_")) {
        *errorMsg = identifier + " starts with hidl_ "
            "and is therefore not a valid identifier";
        return false;
    }
    if (StringHelper::EndsWith(identifier, "_cb")) {
        *errorMsg = identifier + " ends with _cb "
            "and is therefore not a valid identifier";
        return false;
    }

    return true;
}

// Return true if identifier is an acceptable name for an UDT.
bool isValidTypeName(const std::string& identifier, std::string *errorMsg) {
    if (!isValidIdentifier(identifier, errorMsg)) {
        return false;
    }

    if (identifier == "toString") {
        *errorMsg = identifier + " is not a valid type name";
        return false;
    }

    return true;
}


#line 251 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"

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

#include "hidl-gen_y.h"

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
#line 296 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
static void yyerror (const yy::parser::location_type *yylocationp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope, const char* msg);
#line 298 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"


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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 10
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   288
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
       2,     2,     2,    46,     2,    48,     2,    43,    30,     2,
      50,    51,    41,    39,    52,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    56,
      33,    53,    34,    24,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    28,    55,    47,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      27,    31,    32,    35,    36,    37,    38,    44,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   345,   345,   349,   353,   354,   358,   359,   367,   368,
     372,   384,   397,   400,   408,   416,   419,   426,   431,   439,
     446,   451,   455,   460,   468,   476,   478,   485,   495,   508,
     512,   519,   531,   540,   548,   556,   560,   561,   565,   566,
     579,   605,   606,   607,   611,   615,   616,   636,   641,   645,
     664,   665,   666,   667,   672,   671,   732,   736,   749,   759,
     771,   776,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   807,   816,   821,   827,   828,
     837,   846,   864,   867,   874,   883,   895,   899,   903,   918,
     919,   920,   925,   924,   942,   946,   947,   954,   959,   962,
     963,   981,  1001,  1010,  1011,  1015,  1016,  1021,  1020,  1048,
    1049,  1053,  1058,  1062,  1066,  1074,  1075,  1080,  1085,  1092,
    1102,  1103,  1108,  1117,  1121,  1129,  1130,  1134,  1142,  1143
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"multiline comment\"",
  "\"doc comment\"", "\"keyword `enum`\"", "\"keyword `extends`\"",
  "\"fully-qualified name\"", "\"keyword `generates`\"", "\"identifier\"",
  "\"keyword `import`\"", "\"integer value\"", "\"float value\"",
  "\"keyword `interface`\"", "\"keyword `package`\"", "\"type\"",
  "\"keyword `struct`\"", "\"string literal\"", "\"keyword `typedef`\"",
  "\"keyword `union`\"", "\"keyword `safe_union`\"", "\"templated type\"",
  "\"keyword `oneway`\"", "\"unknown character\"", "'?'", "':'",
  "LOGICAL_OR", "LOGICAL_AND", "'|'", "'^'", "'&'", "EQUALITY", "NEQ",
  "'<'", "'>'", "LEQ", "GEQ", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UNARY_MINUS", "UNARY_PLUS", "'!'", "'~'", "'#'", "'@'",
  "'('", "')'", "','", "'='", "'{'", "'}'", "';'", "'['", "']'", "$accept",
  "program", "doc_comment", "doc_comments", "ignore_doc_comments",
  "valid_identifier", "valid_type_name", "opt_annotations", "annotation",
  "opt_annotation_params", "annotation_params", "annotation_param",
  "annotation_string_value", "annotation_string_values", "error_stmt",
  "require_semicolon", "fqname", "fqtype", "package", "import_stmt",
  "opt_extends", "interface_declarations", "declarations",
  "commentable_declaration", "commentable_type_declaration",
  "type_declaration", "type_declaration_body", "interface_declaration",
  "$@1", "interface_declaration_body", "typedef_declaration", "const_expr",
  "commentable_method_declaration", "method_declaration", "typed_vars",
  "non_empty_typed_vars", "typed_var", "uncommented_typed_var",
  "struct_or_union_keyword", "named_struct_or_union_declaration", "$@2",
  "struct_or_union_body", "field_declarations",
  "commentable_field_declaration", "field_declaration",
  "annotated_compound_declaration", "compound_declaration",
  "enum_storage_type", "named_enum_declaration", "$@3",
  "enum_declaration_body", "commentable_enum_value", "enum_value",
  "enum_values", "array_type_base", "array_type", "type",
  "type_or_inplace_compound_declaration", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-197)
#define YYTABLE_NINF (-126)

  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
static const yytype_int16 yypact[] =
{
     179,  -197,  -197,  -197,    17,    46,  -197,   179,   323,    -8,
    -197,  -197,   323,    26,  -197,   146,  -197,  -197,   146,  -197,
     184,    50,   115,  -197,  -197,    50,  -197,    48,  -197,    61,
      61,  -197,   130,  -197,  -197,    76,  -197,  -197,    -8,    -8,
      61,    -8,    -8,    -8,  -197,    -8,  -197,    64,   100,  -197,
      96,  -197,    62,  -197,  -197,  -197,    96,    40,    61,    69,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,   107,  -197,   107,
    -197,    96,  -197,   342,    66,   306,  -197,  -197,   112,  -197,
      71,    96,    82,  -197,    87,   109,   119,   306,  -197,   306,
     306,   306,   306,   151,   111,   347,   104,    60,  -197,  -197,
    -197,  -197,    28,  -197,  -197,  -197,   342,  -197,   380,  -197,
    -197,  -197,  -197,   110,   413,   157,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,  -197,     4,  -197,   112,    58,
     118,  -197,   201,   123,  -197,  -197,    75,   265,   -12,  -197,
    -197,  -197,  -197,   441,   478,   494,   509,   523,   360,   391,
     391,   327,   327,   327,   327,   269,   269,   193,   193,  -197,
    -197,  -197,  -197,   162,  -197,  -197,    89,   137,   158,  -197,
    -197,  -197,    35,  -197,   176,   201,    96,   306,    14,  -197,
     285,   141,   224,  -197,  -197,  -197,  -197,  -197,  -197,   306,
    -197,   113,  -197,  -197,  -197,  -197,  -197,  -197,  -197,    -8,
    -197,  -197,   461,   147,   201,   154,  -197,  -197,  -197,  -197,
     176,   165,   461,   195,  -197,  -197,   201,  -197,   166,    30,
    -197,  -197,    30,   130,   174,   178,  -197,   175,  -197,   176,
      32,    96,    -8,    96,   182,  -197,  -197,  -197,  -197,    30,
     187,    -8,  -197
};

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
static const yytype_uint8 yydefact[] =
{
       0,    32,     5,     4,     0,     0,     6,     0,     0,    26,
       1,     7,     0,     0,    42,    12,    25,    31,    12,    24,
      12,     3,     0,    43,    45,     2,    44,     0,    46,     0,
       0,    99,     0,   100,   101,     0,    13,    49,    26,    26,
       0,    26,    26,    26,    11,    26,    35,   116,    36,    27,
       8,    30,     0,    28,    29,   130,     8,     8,     0,    15,
      53,    52,   102,    50,    51,    33,    34,     0,   117,     0,
      54,     9,   137,     0,   135,     0,   136,    57,     0,    14,
       0,     8,     0,    37,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,    59,     0,     0,     0,    17,   105,
     103,   115,     0,   118,    38,    55,     0,   131,     0,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,    16,     0,     0,
       0,    10,     0,   123,   126,   122,     0,     0,     0,   133,
      85,    84,    60,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    20,     0,    19,    18,     0,     0,     0,   109,
     106,   108,     8,   138,     0,     0,     8,     0,     0,   119,
       0,     0,     0,    88,    39,    48,    40,    87,   132,     0,
      22,     0,   107,   104,   113,   112,   114,   111,   139,    26,
     128,   121,   124,     0,     9,     0,   127,    47,    86,    56,
       0,     0,    61,     0,    21,   110,     0,   120,     0,     8,
      23,   129,     8,     0,     0,    93,    94,     0,    96,    98,
      26,     8,    26,     8,     0,    89,    95,    90,    97,     8,
       0,    26,    91
};

  // YYPGOTO[NTERM-NUM].
static const yytype_int16 yypgoto[] =
{
    -197,  -197,     5,     1,   -15,  -164,   173,   -75,  -197,  -197,
    -197,   101,  -197,  -197,   -21,   -34,   -22,   -17,   234,  -197,
    -197,  -197,   233,  -197,  -197,   -18,  -197,  -197,  -197,  -197,
    -197,   131,  -197,    77,  -196,  -197,    31,  -197,  -197,    93,
    -197,  -197,  -197,  -197,    99,  -197,  -197,  -197,    98,  -197,
    -197,  -158,  -128,  -197,  -197,  -197,   -19,  -197
};

  // YYDEFGOTO[NTERM-NUM].
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    71,   233,   143,    53,    22,    36,    79,
      97,    98,   174,   201,    14,    17,    94,    55,     8,    28,
      70,   147,    15,    23,   194,    24,    37,    38,    84,   105,
      39,    95,   196,   197,   234,   235,   236,   238,    40,    41,
      80,   100,   139,   180,   181,   182,   205,    68,    42,    82,
     103,   144,   145,   146,    56,    57,   183,   184
};

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
static const yytype_int16 yytable[] =
{
      21,     7,    26,    25,    60,    61,    46,    63,    64,    65,
      54,    66,    11,    58,   186,   213,    20,     2,     3,    20,
     209,   172,   107,   141,     9,    11,   198,   210,   221,   140,
     216,     2,     3,     2,     3,    72,   237,   141,     2,     3,
     244,    74,    76,     2,     3,    54,    10,    54,    16,    13,
      81,    54,    83,   250,    86,    43,   228,    44,   173,    13,
      27,     2,     3,   -12,   178,    49,   101,    44,   231,    -8,
      44,    50,   192,    51,   -12,   243,    11,   -12,   -12,    52,
    -125,   -92,    19,  -125,    54,    59,   186,   148,    16,    67,
      13,   207,     2,     3,   -12,    73,    49,    75,    44,     2,
       3,   178,    50,   142,    51,   -12,    69,   -12,   -12,   -12,
      52,   137,   138,    -8,    49,   192,    44,    54,   179,    78,
      29,    96,    51,    87,   177,    99,   193,   188,    30,   195,
     189,    31,   191,    32,    33,    34,   102,    49,   -12,    44,
     176,   104,   106,    50,    -9,    51,    -8,    11,   190,     2,
       3,    52,   113,   107,    54,   179,    -8,   136,    49,   115,
      44,   150,    88,    29,    35,   223,   152,   208,   224,   193,
     185,   211,   217,   215,    31,   225,   187,    33,    34,   200,
       1,    11,     2,     3,    -9,   141,   142,     2,     3,   214,
      89,    90,   203,     4,    -9,    11,   219,    91,    92,   226,
      45,    93,    47,    48,     2,     3,   245,    35,   247,   227,
     141,    54,   230,    62,   239,   229,   232,   252,   108,    11,
     109,   110,   111,   112,   114,   240,   242,   142,   248,    29,
     241,    77,   249,   141,   132,   133,   134,    30,   251,   175,
      31,    12,    32,    33,    34,    18,   220,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    13,   218,     2,     3,
     -12,   204,   246,    35,   -12,   202,   206,     0,   -12,     0,
       0,   -12,     0,   -12,   -12,   -12,    13,   -12,     2,     3,
     -12,     0,     0,     0,   -12,     0,     0,     0,   -12,     0,
       0,   -12,     0,   -12,   -12,   -12,     0,   -12,   130,   131,
     132,   133,   134,    49,   -12,    44,     0,    88,   212,     0,
      -8,     0,     0,   -41,    13,     0,   -41,   -41,   -41,     0,
     222,     0,     0,   -41,   -12,     0,   -41,     0,     0,   -41,
      -9,   -41,   -41,   -41,     0,    89,    90,     0,     0,    49,
       0,    44,    91,    92,     0,    50,    93,    51,     0,     0,
       0,     0,     0,    85,   128,   129,   130,   131,   132,   133,
     134,   116,   -41,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   116,   135,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,   116,   149,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,   151,   116,   199,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134
};

static const yytype_int16 yycheck[] =
{
      15,     0,    20,    18,    38,    39,    27,    41,    42,    43,
      32,    45,     7,    32,   142,     1,    15,     3,     4,    18,
     184,    17,    34,     9,     7,    20,    38,   185,   192,     1,
     188,     3,     4,     3,     4,    50,   232,     9,     3,     4,
       8,    56,    57,     3,     4,    67,     0,    69,    56,     1,
      67,    73,    69,   249,    73,     7,   220,     9,    54,     1,
      10,     3,     4,     5,   139,     7,    81,     9,   226,    55,
       9,    13,   147,    15,    16,   239,    71,    19,    20,    21,
      52,    51,    56,    55,   106,     9,   214,   106,    56,    25,
       1,    56,     3,     4,     5,    33,     7,    57,     9,     3,
       4,   176,    13,   102,    15,    16,     6,    49,    19,    20,
      21,    51,    52,    55,     7,   190,     9,   139,   139,    50,
       5,     9,    15,    57,   139,    54,   147,    52,    13,   147,
      55,    16,   147,    18,    19,    20,    54,     7,    49,     9,
     139,    54,    33,    13,    55,    15,     0,   142,   147,     3,
       4,    21,     1,    34,   176,   176,    10,    53,     7,    48,
       9,    51,    11,     5,    49,    52,     9,   182,    55,   190,
      52,   186,   190,   188,    16,   209,    53,    19,    20,    17,
       1,   176,     3,     4,     0,     9,   185,     3,     4,   188,
      39,    40,    55,    14,    10,   190,    55,    46,    47,    52,
      27,    50,    29,    30,     3,     4,   240,    49,   242,    55,
       9,   233,    17,    40,   233,    50,    50,   251,    87,   214,
      89,    90,    91,    92,    93,    51,    51,   226,   243,     5,
      52,    58,    50,     9,    41,    42,    43,    13,    51,   138,
      16,     7,    18,    19,    20,    12,    22,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     1,   190,     3,     4,
       5,   178,   241,    49,     9,   176,   178,    -1,    13,    -1,
      -1,    16,    -1,    18,    19,    20,     1,    22,     3,     4,
       5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,    -1,
      -1,    16,    -1,    18,    19,    20,    -1,    22,    39,    40,
      41,    42,    43,     7,    49,     9,    -1,    11,   187,    -1,
      55,    -1,    -1,     0,     1,    -1,     3,     4,     5,    -1,
     199,    -1,    -1,    10,    49,    -1,    13,    -1,    -1,    16,
      55,    18,    19,    20,    -1,    39,    40,    -1,    -1,     7,
      -1,     9,    46,    47,    -1,    13,    50,    15,    -1,    -1,
      -1,    -1,    -1,    21,    37,    38,    39,    40,    41,    42,
      43,    24,    49,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    24,    58,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    24,    58,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43
};

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    14,    60,    61,    62,    77,     7,
       0,    61,    77,     1,    73,    81,    56,    74,    81,    56,
      62,    63,    66,    82,    84,    63,    84,    10,    78,     5,
      13,    16,    18,    19,    20,    49,    67,    85,    86,    89,
      97,    98,   107,     7,     9,    65,    73,    65,    65,     7,
      13,    15,    21,    65,    75,    76,   113,   114,   115,     9,
      74,    74,    65,    74,    74,    74,    74,    25,   106,     6,
      79,    62,    63,    33,    63,    57,    63,    65,    50,    68,
      99,    76,   108,    76,    87,    21,   115,    57,    11,    39,
      40,    46,    47,    50,    75,    90,     9,    69,    70,    54,
     100,    63,    54,   109,    54,    88,    33,    34,    90,    90,
      90,    90,    90,     1,    90,    48,    24,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    58,    53,    51,    52,   101,
       1,     9,    62,    64,   110,   111,   112,    80,   115,    58,
      51,    51,     9,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    17,    54,    71,    70,    62,    63,    66,    73,
     102,   103,   104,   115,   116,    52,   111,    53,    52,    55,
      62,    63,    66,    73,    83,    84,    91,    92,    38,    25,
      17,    72,   103,    55,    98,   105,   107,    56,    63,    64,
     110,    63,    90,     1,    62,    63,   110,    84,    92,    55,
      22,    64,    90,    52,    55,    74,    52,    55,    64,    50,
      17,   110,    50,    63,    93,    94,    95,    93,    96,   115,
      51,    52,    51,    64,     8,    74,    95,    74,    63,    50,
      93,    51,    74
};

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      80,    81,    81,    81,    82,    82,    82,    83,    83,    84,
      85,    85,    85,    85,    87,    86,    88,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      97,    97,    99,    98,   100,   101,   101,   102,   102,   103,
     103,   103,   104,   105,   105,   106,   106,   108,   107,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   115,   115,   115,   116,   116
};

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     1,     1,     1,     2,     0,     1,
       1,     1,     0,     2,     3,     0,     3,     1,     3,     3,
       1,     3,     1,     3,     2,     1,     0,     1,     1,     1,
       1,     3,     1,     3,     3,     2,     0,     2,     0,     2,
       2,     0,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     0,     5,     4,     3,     1,     1,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     2,     1,     1,     6,
       7,    10,     0,     1,     1,     3,     2,     3,     1,     1,
       1,     1,     0,     4,     4,     0,     2,     2,     1,     1,
       3,     2,     2,     1,     1,     3,     0,     0,     5,     3,
       5,     3,     1,     1,     3,     0,     1,     3,     3,     5,
       1,     4,     6,     5,     4,     2,     2,     2,     1,     2
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
yy_symbol_print (FILE *, int yytype, const yy::parser::semantic_type *yyvaluep, const yy::parser::location_type *yylocationp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  YYUSE (yyparser);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (scope);
  yyparser.yy_symbol_print_ (yytype, yyvaluep, yylocationp);
}


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Type, Value, Location, yyparser, scanner, ast, scope);        \
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
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, yyparser, scanner, ast, scope, yymsg);
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
yygetToken (int *yycharp, yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  yySymbol yytoken;
  YYUSE (yyparser);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (scope);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token: "));
#if YY_EXCEPTIONS
      try
        {
#endif // YY_EXCEPTIONS
          *yycharp = yylex (&yylval, &yylloc, scanner, ast, scope);
#if YY_EXCEPTIONS
        }
      catch (const yy::parser::syntax_error& yyexc)
        {
          YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
          yylloc = yyexc.location;
          yyerror (&yylloc, yyparser, scanner, ast, scope, yyexc.what ());
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
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (yyparser);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (scope);
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
  return yyerror (yylocp, yyparser, scanner, ast, scope, YY_("syntax error: cannot back up")),     \
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
#line 346 "system/tools/hidl/hidl-gen_y.yy"
      {
        ast->setHeader((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.docComment));
      }
#line 1577 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 4:
#line 353 "system/tools/hidl/hidl-gen_y.yy"
                  { ((*yyvalp).docComment) = new DocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast), CommentType::DOC_MULTILINE); }
#line 1583 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 5:
#line 354 "system/tools/hidl/hidl-gen_y.yy"
                        { ((*yyvalp).docComment) = new DocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast), CommentType::MULTILINE); }
#line 1589 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 6:
#line 358 "system/tools/hidl/hidl-gen_y.yy"
                  { ((*yyvalp).docComment) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docComment); }
#line 1595 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 7:
#line 360 "system/tools/hidl/hidl-gen_y.yy"
      {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment)->merge((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docComment));
        ((*yyvalp).docComment) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment);
      }
#line 1604 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 8:
#line 367 "system/tools/hidl/hidl-gen_y.yy"
                { ((*yyvalp).docComment) = nullptr; }
#line 1610 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 9:
#line 368 "system/tools/hidl/hidl-gen_y.yy"
                   { ast->addUnhandledComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docComment)); ((*yyvalp).docComment) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docComment); }
#line 1616 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 10:
#line 373 "system/tools/hidl/hidl-gen_y.yy"
      {
        std::string errorMsg;
        if (!isValidIdentifier((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), &errorMsg)) {
            std::cerr << "ERROR: " << errorMsg << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
            YYERROR;
        }
        ((*yyvalp).str) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str);
      }
#line 1629 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 11:
#line 385 "system/tools/hidl/hidl-gen_y.yy"
      {
        std::string errorMsg;
        if (!isValidTypeName((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), &errorMsg)) {
            std::cerr << "ERROR: " << errorMsg << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
            YYERROR;
        }
        ((*yyvalp).str) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str);
      }
#line 1642 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 12:
#line 397 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotations) = new std::vector<Annotation *>;
      }
#line 1650 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 13:
#line 401 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotations) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotations);
          ((*yyvalp).annotations)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotation));
      }
#line 1659 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 14:
#line 409 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotation) = new Annotation((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotationParams));
      }
#line 1667 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 15:
#line 416 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotationParams) = new AnnotationParamVector;
      }
#line 1675 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 16:
#line 420 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotationParams) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotationParams);
      }
#line 1683 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 17:
#line 427 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotationParams) = new AnnotationParamVector;
          ((*yyvalp).annotationParams)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotationParam));
      }
#line 1692 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 18:
#line 432 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotationParams) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.annotationParams);
          ((*yyvalp).annotationParams)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.annotationParam));
      }
#line 1701 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 19:
#line 440 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).annotationParam) = new StringAnnotationParam((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVec));
      }
#line 1709 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 20:
#line 447 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).stringVec) = new std::vector<std::string>;
          ((*yyvalp).stringVec)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
      }
#line 1718 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 21:
#line 451 "system/tools/hidl/hidl-gen_y.yy"
                                       { ((*yyvalp).stringVec) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.stringVec); }
#line 1724 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 22:
#line 456 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).stringVec) = new std::vector<std::string>;
          ((*yyvalp).stringVec)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
      }
#line 1733 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 23:
#line 461 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).stringVec) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVec);
          ((*yyvalp).stringVec)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
      }
#line 1742 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 24:
#line 469 "system/tools/hidl/hidl-gen_y.yy"
    {
      ((*yyvalp).str) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str);
      ast->addSyntaxError();
    }
#line 1751 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 26:
#line 478 "system/tools/hidl/hidl-gen_y.yy"
      {
          std::cerr << "ERROR: missing ; at " << (*yylocp) << "\n";
          ast->addSyntaxError();
      }
#line 1760 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 27:
#line 486 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).fqName) = new FQName();
          if(!FQName::parse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), ((*yyvalp).fqName))) {
              std::cerr << "ERROR: FQName '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str) << "' is not valid at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)
                        << ".\n";
              YYERROR;
          }
      }
#line 1774 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 28:
#line 496 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).fqName) = new FQName();
          if(!FQName::parse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), ((*yyvalp).fqName))) {
              std::cerr << "ERROR: FQName '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str) << "' is not valid at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)
                        << ".\n";
              YYERROR;
          }
      }
#line 1788 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 29:
#line 509 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName)->string(), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast));
      }
#line 1796 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 30:
#line 513 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast));
      }
#line 1804 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 31:
#line 520 "system/tools/hidl/hidl-gen_y.yy"
      {
          if (!ast->setPackage((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str))) {
              std::cerr << "ERROR: Malformed package identifier '"
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)
                        << "' at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)
                        << "\n";

              YYERROR;
          }
      }
#line 1820 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 32:
#line 532 "system/tools/hidl/hidl-gen_y.yy"
    {
      std::cerr << "ERROR: Package statement must be at the beginning of the file (" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << ")\n";
      ((*yyvalp).str) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str);
      ast->addSyntaxError();
    }
#line 1830 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 33:
#line 541 "system/tools/hidl/hidl-gen_y.yy"
      {
          if (!ast->addImport((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast))) {
              std::cerr << "ERROR: Unable to import '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str) << "' at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)
                        << "\n";
              ast->addSyntaxError();
          }
      }
#line 1842 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 34:
#line 549 "system/tools/hidl/hidl-gen_y.yy"
      {
          if (!ast->addImport((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast))) {
              std::cerr << "ERROR: Unable to import '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str) << "' at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)
                        << "\n";
              ast->addSyntaxError();
          }
      }
#line 1854 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 36:
#line 560 "system/tools/hidl/hidl-gen_y.yy"
                  { ((*yyvalp).referenceToType) = nullptr; }
#line 1860 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 37:
#line 561 "system/tools/hidl/hidl-gen_y.yy"
                     { ((*yyvalp).referenceToType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType); }
#line 1866 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 39:
#line 567 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isInterface());

          std::string errorMsg;
          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type) != nullptr && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->isNamedType() &&
              !isValidInterfaceField(static_cast<NamedType*>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type))->definedName().c_str(),
                    &errorMsg)) {
              std::cerr << "ERROR: " << errorMsg << " at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
              YYERROR;
          }
      }
#line 1883 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 40:
#line 580 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isInterface());

          std::string errorMsg;
          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method) != nullptr &&
              !isValidInterfaceField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method)->name().c_str(), &errorMsg)) {
              std::cerr << "ERROR: " << errorMsg << " at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
              YYERROR;
          }

          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method) != nullptr) {
            Interface *iface = static_cast<Interface*>(*scope);
            if (!ast->addMethod((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method), iface)) {
                std::cerr << "ERROR: Unable to add method '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method)->name()
                          << "' at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";

                YYERROR;
            }
          }
          // ignore if $2 is nullptr (from error recovery)
      }
#line 1910 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 44:
#line 612 "system/tools/hidl/hidl-gen_y.yy"
      {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->setDocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment));
      }
#line 1918 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 46:
#line 617 "system/tools/hidl/hidl-gen_y.yy"
      {
        // Import statements must be first. The grammar allows them later so that:
        // - there is a nice error if imports are later
        // - doc_comments can be factored out here to avoid shift/reduce conflicts
        if (!ast->getRootScope().getDefinedTypes().empty()) {
            std::cerr << "ERROR: import at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)
                      << " follows type definitions, but imports must come first" << std::endl;

            YYERROR;
        }
      }
#line 1934 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 47:
#line 637 "system/tools/hidl/hidl-gen_y.yy"
      {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->setDocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment));
        ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type);
      }
#line 1943 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 48:
#line 641 "system/tools/hidl/hidl-gen_y.yy"
                       { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type); }
#line 1949 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 49:
#line 646 "system/tools/hidl/hidl-gen_y.yy"
      {
          if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->isTypeDef()) {
              CHECK((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->isScope());
              static_cast<Scope*>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type))->setAnnotations((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotations));
          } else if (!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotations)->empty()) {
              // Since typedefs are always resolved to their target it makes
              // little sense to annotate them and have their annotations
              // impose semantics other than their target type.
              std::cerr << "ERROR: typedefs cannot be annotated at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)
                        << "\n";

              YYERROR;
          }
          ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type);
      }
#line 1969 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 50:
#line 664 "system/tools/hidl/hidl-gen_y.yy"
      { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type); }
#line 1975 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 51:
#line 665 "system/tools/hidl/hidl-gen_y.yy"
      { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type); }
#line 1981 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 52:
#line 666 "system/tools/hidl/hidl-gen_y.yy"
      { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type); }
#line 1987 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 53:
#line 667 "system/tools/hidl/hidl-gen_y.yy"
      { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type); }
#line 1993 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 54:
#line 672 "system/tools/hidl/hidl-gen_y.yy"
      {
          Reference<Type>* superType = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType);
          bool isIBase = ast->package().package() == gIBaseFqName.package();

          if (isIBase) {
              if (superType != nullptr) {
                  std::cerr << "ERROR: IBase must not extend any interface at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)
                        << "\n";

                  YYERROR;
              }
              superType = new Reference<Type>();
          } else {
              if (!ast->addImplicitImport(gIBaseFqName)) {
                  std::cerr << "ERROR: Unable to automatically import '"
                            << gIBaseFqName.string()
                            << "' at " << (*yylocp)
                            << "\n";
                  YYERROR;
              }

              if (superType == nullptr) {
                  superType = new Reference<Type>(gIBaseFqName.string(), gIBaseFqName, convertYYLoc((*yylocp), ast));
              }
          }

          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)[0] != 'I') {
              std::cerr << "ERROR: All interface names must start with an 'I' "
                        << "prefix at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc) << "\n";

              YYERROR;
          }

          if (*scope != &ast->getRootScope()) {
              std::cerr << "ERROR: All interface must declared in "
                        << "global scope at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc) << "\n";

              YYERROR;
          }

          Interface* iface = new Interface(
              (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), ast->makeFullName((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), *scope), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast),
              *scope, *superType, ast->getFileHash());

          enterScope(ast, scope, iface);
      }
#line 2044 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 55:
#line 719 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isInterface());

          Interface *iface = static_cast<Interface *>(*scope);
          CHECK(ast->addAllReservedMethodsToInterface(iface));

          leaveScope(ast, scope);
          ast->addScopedType(iface, *scope);
          ((*yyvalp).type) = iface;
      }
#line 2059 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 57:
#line 737 "system/tools/hidl/hidl-gen_y.yy"
      {
          // The reason we wrap the given type in a TypeDef is simply to suppress
          // emitting any type definitions later on, since this is just an alias
          // to a type defined elsewhere.
          TypeDef* typeDef = new TypeDef(
              (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), ast->makeFullName((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), *scope), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast), *scope, *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.referenceToType));
          ast->addScopedType(typeDef, *scope);
          ((*yyvalp).type) = typeDef;
      }
#line 2073 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 58:
#line 750 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).constantExpression) = LiteralConstantExpression::tryParse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));

          if (((*yyvalp).constantExpression) == nullptr) {
              std::cerr << "ERROR: Could not parse literal: "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str) << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << ".\n";
              YYERROR;
          }
      }
#line 2087 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 59:
#line 760 "system/tools/hidl/hidl-gen_y.yy"
      {
          if(!(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName)->isValidValueName()) {
              std::cerr << "ERROR: '" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName)->string()
                        << "' does not refer to an enum value at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << ".\n";
              YYERROR;
          }

          ((*yyvalp).constantExpression) = new ReferenceConstantExpression(
              Reference<LocalIdentifier>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName)->string(), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fqName)->string());
      }
#line 2103 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 60:
#line 772 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).constantExpression) = new AttributeConstantExpression(
              Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fqName)->string(), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fqName), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc), ast)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fqName)->string(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
      }
#line 2112 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 61:
#line 777 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).constantExpression) = new TernaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.constantExpression), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression));
      }
#line 2120 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 62:
#line 780 "system/tools/hidl/hidl-gen_y.yy"
                                        { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "||", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2126 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 63:
#line 781 "system/tools/hidl/hidl-gen_y.yy"
                                        { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "&&", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2132 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 64:
#line 782 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "|" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2138 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 65:
#line 783 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "^" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2144 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 66:
#line 784 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "&" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2150 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 67:
#line 785 "system/tools/hidl/hidl-gen_y.yy"
                                     { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "==", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2156 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 68:
#line 786 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "!=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2162 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 69:
#line 787 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "<" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2168 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 70:
#line 788 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), ">" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2174 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 71:
#line 789 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "<=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2180 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 72:
#line 790 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), ">=", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2186 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 73:
#line 791 "system/tools/hidl/hidl-gen_y.yy"
                                   { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "<<", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2192 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 74:
#line 792 "system/tools/hidl/hidl-gen_y.yy"
                                   { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), ">>", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2198 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 75:
#line 793 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "+" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2204 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 76:
#line 794 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "-" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2210 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 77:
#line 795 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "*" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2216 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 78:
#line 796 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "/" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2222 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 79:
#line 797 "system/tools/hidl/hidl-gen_y.yy"
                                { ((*yyvalp).constantExpression) = new BinaryConstantExpression((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.constantExpression), "%" , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2228 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 80:
#line 798 "system/tools/hidl/hidl-gen_y.yy"
                                       { ((*yyvalp).constantExpression) = new UnaryConstantExpression("+", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2234 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 81:
#line 799 "system/tools/hidl/hidl-gen_y.yy"
                                       { ((*yyvalp).constantExpression) = new UnaryConstantExpression("-", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2240 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 82:
#line 800 "system/tools/hidl/hidl-gen_y.yy"
                     { ((*yyvalp).constantExpression) = new UnaryConstantExpression("!", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2246 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 83:
#line 801 "system/tools/hidl/hidl-gen_y.yy"
                     { ((*yyvalp).constantExpression) = new UnaryConstantExpression("~", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression)); }
#line 2252 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 84:
#line 803 "system/tools/hidl/hidl-gen_y.yy"
      {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constantExpression)->surroundWithParens();
        ((*yyvalp).constantExpression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constantExpression);
      }
#line 2261 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 85:
#line 808 "system/tools/hidl/hidl-gen_y.yy"
      {
        ast->addSyntaxError();
        // to avoid segfaults
        ((*yyvalp).constantExpression) = ConstantExpression::Zero(ScalarType::KIND_INT32).release();
      }
#line 2271 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 86:
#line 817 "system/tools/hidl/hidl-gen_y.yy"
      {
        if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method) != nullptr) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method)->setDocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment));
        ((*yyvalp).method) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method);
      }
#line 2280 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 87:
#line 822 "system/tools/hidl/hidl-gen_y.yy"
      {
        ((*yyvalp).method) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.method);
      }
#line 2288 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 88:
#line 827 "system/tools/hidl/hidl-gen_y.yy"
                 { ((*yyvalp).method) = nullptr; }
#line 2294 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 89:
#line 829 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).method) = new Method((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str) /* name */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.typedVars) /* args */,
                          new std::vector<NamedReference<Type>*> /* results */,
                          false /* oneway */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.annotations) /* annotations */,
                          convertYYLoc((*yylocp), ast));
      }
#line 2307 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 90:
#line 838 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).method) = new Method((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str) /* name */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.typedVars) /* args */,
                          new std::vector<NamedReference<Type>*> /* results */,
                          true /* oneway */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.annotations) /* annotations */,
                          convertYYLoc((*yylocp), ast));
      }
#line 2320 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 91:
#line 847 "system/tools/hidl/hidl-gen_y.yy"
      {
          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.typedVars)->empty()) {
              std::cerr << "ERROR: generates clause used without result at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yyloc) << "\n";
              ast->addSyntaxError();
          }

          ((*yyvalp).method) = new Method((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.str) /* name */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.typedVars) /* args */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.typedVars) /* results */,
                          false /* oneway */,
                          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.annotations) /* annotations */,
                          convertYYLoc((*yylocp), ast));
      }
#line 2338 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 92:
#line 864 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVars) = new TypedVarVector();
      }
#line 2346 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 93:
#line 868 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVars) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVars);
      }
#line 2354 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 94:
#line 875 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVars) = new TypedVarVector();
          if (!((*yyvalp).typedVars)->add((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVar))) {
              std::cerr << "ERROR: duplicated argument or result name "
                  << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVar)->name() << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
              ast->addSyntaxError();
          }
      }
#line 2367 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 95:
#line 884 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVars) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.typedVars);
          if (!((*yyvalp).typedVars)->add((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVar))) {
              std::cerr << "ERROR: duplicated argument or result name "
                  << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVar)->name() << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
              ast->addSyntaxError();
          }
      }
#line 2380 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 96:
#line 895 "system/tools/hidl/hidl-gen_y.yy"
                                                { ((*yyvalp).typedVar) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.typedVar); }
#line 2386 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 97:
#line 900 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVar) = new NamedReference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.referenceToType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast));
      }
#line 2394 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 98:
#line 904 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).typedVar) = new NamedReference<Type>("", *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast));

          const std::string typeName = ((*yyvalp).typedVar)->isResolved()
              ? ((*yyvalp).typedVar)->get()->typeName() : ((*yyvalp).typedVar)->getLookupFqName().string();

          std::cerr << "ERROR: variable of type " << typeName
              << " is missing a variable name at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
          ast->addSyntaxError();
      }
#line 2409 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 99:
#line 918 "system/tools/hidl/hidl-gen_y.yy"
             { ((*yyvalp).compoundStyle) = CompoundType::STYLE_STRUCT; }
#line 2415 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 100:
#line 919 "system/tools/hidl/hidl-gen_y.yy"
            { ((*yyvalp).compoundStyle) = CompoundType::STYLE_UNION; }
#line 2421 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 101:
#line 920 "system/tools/hidl/hidl-gen_y.yy"
                 { ((*yyvalp).compoundStyle) = CompoundType::STYLE_SAFE_UNION; }
#line 2427 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 102:
#line 925 "system/tools/hidl/hidl-gen_y.yy"
      {
          CompoundType *container = new CompoundType(
              (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.compoundStyle), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), ast->makeFullName((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), *scope), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), ast), *scope);
          enterScope(ast, scope, container);
      }
#line 2437 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 103:
#line 931 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isCompoundType());
          CompoundType *container = static_cast<CompoundType *>(*scope);

          leaveScope(ast, scope);
          ast->addScopedType(container, *scope);
          ((*yyvalp).type) = container;
      }
#line 2450 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 104:
#line 942 "system/tools/hidl/hidl-gen_y.yy"
                                                     { ((*yyvalp).fields) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fields); }
#line 2456 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 105:
#line 946 "system/tools/hidl/hidl-gen_y.yy"
                  { ((*yyvalp).fields) = nullptr; }
#line 2462 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 106:
#line 948 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).fields) = nullptr;
      }
#line 2470 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 107:
#line 955 "system/tools/hidl/hidl-gen_y.yy"
    {
      if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docCommentable) != nullptr) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docCommentable)->setDocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.docComment));
      ((*yyvalp).docCommentable) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docCommentable);
    }
#line 2479 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 108:
#line 959 "system/tools/hidl/hidl-gen_y.yy"
                        { ((*yyvalp).docCommentable) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.docCommentable); }
#line 2485 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 109:
#line 962 "system/tools/hidl/hidl-gen_y.yy"
                 { ((*yyvalp).docCommentable) = nullptr; }
#line 2491 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 110:
#line 964 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isCompoundType());

          std::string errorMsg;
          CompoundType* compoundType = static_cast<CompoundType *>(*scope);
          auto style = compoundType->style();

          if (!isValidCompoundTypeField(style, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), &errorMsg)) {
              std::cerr << "ERROR: " << errorMsg << " at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc) << "\n";
              YYERROR;
          }

          NamedReference<Type>* field = new NamedReference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.referenceToType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast));
          compoundType->addField(field);
          ((*yyvalp).docCommentable) = field;
      }
#line 2513 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 111:
#line 982 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isCompoundType());

          std::string errorMsg;
          auto style = static_cast<CompoundType *>(*scope)->style();

          if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type) != nullptr && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type)->isNamedType() &&
              !isValidCompoundTypeField(style, static_cast<NamedType*>(
                        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type))->definedName().c_str(), &errorMsg)) {
              std::cerr << "ERROR: " << errorMsg << " at "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc) << "\n";
              YYERROR;
          }

          ((*yyvalp).docCommentable) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type);
      }
#line 2534 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 112:
#line 1002 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type)->isScope());
          static_cast<Scope*>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type))->setAnnotations((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.annotations));
          ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type);
      }
#line 2544 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 113:
#line 1010 "system/tools/hidl/hidl-gen_y.yy"
                                        { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type); }
#line 2550 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 114:
#line 1011 "system/tools/hidl/hidl-gen_y.yy"
                             { ((*yyvalp).type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.type); }
#line 2556 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 115:
#line 1015 "system/tools/hidl/hidl-gen_y.yy"
                                     { ((*yyvalp).referenceToType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.referenceToType); }
#line 2562 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 116:
#line 1016 "system/tools/hidl/hidl-gen_y.yy"
                  { ((*yyvalp).referenceToType) = nullptr; }
#line 2568 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 117:
#line 1021 "system/tools/hidl/hidl-gen_y.yy"
      {
          auto storageType = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType);

          if (storageType == nullptr) {
              std::cerr << "ERROR: Must explicitly specify enum storage type for "
                        << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str) << " at " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc) << "\n";
              ast->addSyntaxError();
              ScalarType* scalar = new ScalarType(ScalarType::KIND_INT64, *scope);
              storageType = new Reference<Type>(scalar->definedName(), scalar, convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast));
          }

          EnumType* enumType = new EnumType(
              (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), ast->makeFullName((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), *scope), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast), *storageType, *scope);
          enterScope(ast, scope, enumType);
      }
#line 2588 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 118:
#line 1037 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isEnum());
          EnumType* enumType = static_cast<EnumType*>(*scope);

          leaveScope(ast, scope);
          ast->addScopedType(enumType, *scope);
          ((*yyvalp).type) = enumType;
      }
#line 2601 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 119:
#line 1048 "system/tools/hidl/hidl-gen_y.yy"
                          { ((*yyvalp).enumValues) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.enumValues); }
#line 2607 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 120:
#line 1049 "system/tools/hidl/hidl-gen_y.yy"
                                                  { ((*yyvalp).enumValues) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.enumValues); }
#line 2613 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 121:
#line 1054 "system/tools/hidl/hidl-gen_y.yy"
      {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.enumValue)->setDocComment((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.docComment));
        ((*yyvalp).enumValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.enumValue);
      }
#line 2622 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 122:
#line 1058 "system/tools/hidl/hidl-gen_y.yy"
                 { ((*yyvalp).enumValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumValue); }
#line 2628 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 123:
#line 1063 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).enumValue) = new EnumValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str) /* name */, nullptr /* value */, convertYYLoc((*yylocp), ast));
      }
#line 2636 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 124:
#line 1067 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).enumValue) = new EnumValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str) /* name */, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.constantExpression) /* value */, convertYYLoc((*yylocp), ast));
      }
#line 2644 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 125:
#line 1074 "system/tools/hidl/hidl-gen_y.yy"
      { /* do nothing */ }
#line 2650 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 126:
#line 1076 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isEnum());
          static_cast<EnumType *>(*scope)->addValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumValue));
      }
#line 2659 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 127:
#line 1081 "system/tools/hidl/hidl-gen_y.yy"
      {
          CHECK((*scope)->isEnum());
          static_cast<EnumType *>(*scope)->addValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumValue));
      }
#line 2668 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 128:
#line 1086 "system/tools/hidl/hidl-gen_y.yy"
      {
          ast->addSyntaxError();

          CHECK((*scope)->isEnum());
          static_cast<EnumType *>(*scope)->addValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumValue));
      }
#line 2679 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 129:
#line 1093 "system/tools/hidl/hidl-gen_y.yy"
      {
          ast->addSyntaxError();

          CHECK((*scope)->isEnum());
          static_cast<EnumType *>(*scope)->addValue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.enumValue));
      }
#line 2690 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 130:
#line 1102 "system/tools/hidl/hidl-gen_y.yy"
             { ((*yyvalp).referenceToType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType); }
#line 2696 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 131:
#line 1104 "system/tools/hidl/hidl-gen_y.yy"
      {
          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType)->setElementType(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.referenceToType));
          ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc), ast));
      }
#line 2705 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 132:
#line 1109 "system/tools/hidl/hidl-gen_y.yy"
      {
          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType)->setElementType(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.referenceToType));
          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.templatedType)->setElementType(Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.templatedType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc), ast)));
          ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.templatedType)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.templatedType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yyloc), ast));
      }
#line 2715 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 133:
#line 1118 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).arrayType) = new ArrayType(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.referenceToType), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constantExpression), *scope);
      }
#line 2723 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 134:
#line 1122 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).arrayType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.arrayType);
          ((*yyvalp).arrayType)->appendDimension((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.constantExpression));
      }
#line 2732 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 135:
#line 1129 "system/tools/hidl/hidl-gen_y.yy"
                                          { ((*yyvalp).referenceToType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.referenceToType); }
#line 2738 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 136:
#line 1131 "system/tools/hidl/hidl-gen_y.yy"
      {
        ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.arrayType)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.arrayType), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast));
      }
#line 2746 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 137:
#line 1135 "system/tools/hidl/hidl-gen_y.yy"
      {
        // "interface" is a synonym of android.hidl.base@1.0::IBase
        ((*yyvalp).referenceToType) = new Reference<Type>("interface", gIBaseFqName, convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast));
      }
#line 2755 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 138:
#line 1142 "system/tools/hidl/hidl-gen_y.yy"
           { ((*yyvalp).referenceToType) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.referenceToType); }
#line 2761 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;

  case 139:
#line 1144 "system/tools/hidl/hidl-gen_y.yy"
      {
          ((*yyvalp).referenceToType) = new Reference<Type>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type)->definedName(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), convertYYLoc((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc), ast), true);
      }
#line 2769 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
    break;


#line 2773 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"

      default: break;
    }
#if YY_EXCEPTIONS
  }
  catch (const syntax_error& yyexc)
    {
      YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
      *yylocp = yyexc.location;
      yyerror (yylocp, yyparser, scanner, ast, scope, yyexc.what ());
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyparser);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (scope);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, yyparser, scanner, ast, scope);
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
            yydestroyGLRState (yymsg, yyrh, yyparser, scanner, ast, scope);
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
                 yyRuleNum yyrule, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , yyparser, scanner, ast, scope);
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
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule, yyparser, scanner, ast, scope));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, yyparser, scanner, ast, scope);
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
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, yyparser, scanner, ast, scope));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, yyparser, scanner, ast, scope);
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
             yybool yyforceEval, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, yyparser, scanner, ast, scope);
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
                                   yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, yyparser, scanner, ast, scope));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, yyparser, scanner, ast, scope));
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
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, yyparser, scanner, ast, scope);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, yyparser, scanner, ast, scope);
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
                           yystackp, yyvalp, yylocp, yyparser, scanner, ast, scope);
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
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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

  yyerror (yylocp, yyparser, scanner, ast, scope, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, yyparser, scanner, ast, scope);
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
                                  yystackp, yyparser, scanner, ast, scope);
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
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
              yyresolveLocations (yys, 1, yystackp, yyparser, scanner, ast, scope);
              return yyreportAmbiguity (yybest, yyp, yylocp, yyparser, scanner, ast, scope);
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
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, scanner, ast, scope);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, yyparser, scanner, ast, scope);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, yyparser, scanner, ast, scope);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, scanner, ast, scope);

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
yyresolveStack (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
                             , yyparser, scanner, ast, scope));
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
                   ptrdiff_t yyposn, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], yyparser, scanner, ast, scope);
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
          yySymbol yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, ast, scope);
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
                                    yyimmediate[*yyconflicts], yyparser, scanner, ast, scope);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, yyparser, scanner, ast, scope));
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
                                                yyimmediate[-yyaction], yyparser, scanner, ast, scope);
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
yyreportSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (&yylloc, yyparser, scanner, ast, scope, YY_("syntax error"));
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
      yyerror (&yylloc, yyparser, scanner, ast, scope, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, yyparser, scanner, ast, scope, YY_("syntax error"));
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
yyrecoverSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, yyparser, scanner, ast, scope, YY_NULLPTR);
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
                        yytoken, &yylval, &yylloc, yyparser, scanner, ast, scope);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, ast, scope);
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
      yyFail (yystackp, &yylloc, yyparser, scanner, ast, scope, YY_NULLPTR);
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
        yydestroyGLRState ("Error: popping", yys, yyparser, scanner, ast, scope);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, yyparser, scanner, ast, scope, YY_NULLPTR);
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
yyparse (yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope)
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
#line 211 "system/tools/hidl/hidl-gen_y.yy"
{
    // Initialize the initial location.
    yylloc.begin.filename = yylloc.end.filename =
        const_cast<std::string *>(&ast->getFilename());
}

#line 4243 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"


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
                  yyreportSyntaxError (&yystack, yyparser, scanner, ast, scope);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, yyparser, scanner, ast, scope));
            }
          else
            {
              yySymbol yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, ast, scope);
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
                    yyreportSyntaxError (&yystack, yyparser, scanner, ast, scope);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, yyparser, scanner, ast, scope));
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
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, yyparser, scanner, ast, scope));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, yyparser, scanner, ast, scope, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, yyparser, scanner, ast, scope));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, yyparser, scanner, ast, scope);
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
              YYCHK1 (yyresolveStack (&yystack, yyparser, scanner, ast, scope));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, yyparser, scanner, ast, scope);
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
  yyerror (&yylloc, yyparser, scanner, ast, scope, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, yyparser, scanner, ast, scope);

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
                      yydestroyGLRState ("Cleanup: popping", yys, yyparser, scanner, ast, scope);
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



#line 1149 "system/tools/hidl/hidl-gen_y.yy"


void yy::parser::error(
        const yy::parser::location_type &where,
        const std::string &errstr) {
    std::cerr << "ERROR: " << errstr << " at " << where << "\n";
}
#line 4539 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"

/*------------------.
| Report an error.  |
`------------------*/

static void
yyerror (const yy::parser::location_type *yylocationp, yy::parser& yyparser, void* scanner, android::AST* const ast, android::Scope** const scope, const char* msg)
{
  YYUSE (yyparser);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (scope);
  yyparser.error (*yylocationp, msg);
}


namespace yy {
#line 4557 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"

  /// Build a parser object.
  parser::parser (void* scanner_yyarg, android::AST* const ast_yyarg, android::Scope** const scope_yyarg)
    :
#if YYDEBUG
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      ast (ast_yyarg),
      scope (scope_yyarg)
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
    return ::yyparse (*this, scanner, ast, scope);
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
#line 4647 "out/soong/.intermediates/system/tools/hidl/libhidl-gen-ast/linux_glibc_x86_64_static/gen/yacc/system/tools/hidl/hidl-gen_y.cpp"
