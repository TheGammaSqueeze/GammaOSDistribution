// A Bison parser, made by GNU Bison 3.5.

// Skeleton interface for Bison GLR parsers in C++

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

// C++ GLR parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_OUT_SOONG_TEMP_SBOX_751B4A5581F25745E025435F464E2FD0F61484B9_OUT_FRAMEWORKS_COMPILE_MCLINKER_LIB_SCRIPT_SCRIPTPARSER_H_INCLUDED
# define YY_YY_OUT_SOONG_TEMP_SBOX_751B4A5581F25745E025435F464E2FD0F61484B9_OUT_FRAMEWORKS_COMPILE_MCLINKER_LIB_SCRIPT_SCRIPTPARSER_H_INCLUDED
// "%code requires" blocks.
#line 28 "frameworks/compile/mclinker/lib/Script/ScriptParser.yy"

#include "mcld/Script/StrToken.h"
#include "mcld/Script/StringList.h"
#include "mcld/Script/OutputSectDesc.h"
#include "mcld/Script/InputSectDesc.h"
#include <llvm/Support/DataTypes.h>

using namespace mcld;


#line 53 "out/soong/.intermediates/frameworks/compile/mclinker/lib/Script/libmcldScript/android_arm64_armv8-a_static/gen/yacc/frameworks/compile/mclinker/lib/Script/ScriptParser.h"

#include <iostream>
#include <stdexcept>
#include <string>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


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

// This skeleton is based on C, yet compiles it as C++.
// So expect warnings about C style casts.
#if defined __clang__ && 306 <= __clang_major__ * 100 + __clang_minor__
# pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined __GNUC__ && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

// On MacOS, PTRDIFF_MAX is defined as long long, which Clang's
// -pedantic reports as being a C++11 extension.
#if defined __APPLE__ && YY_CPLUSPLUS < 201103L && 4 <= __clang_major__
# pragma clang diagnostic ignored "-Wc++11-long-long"
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 48 "frameworks/compile/mclinker/lib/Script/ScriptParser.yy"
namespace mcld {
#line 194 "out/soong/.intermediates/frameworks/compile/mclinker/lib/Script/libmcldScript/android_arm64_armv8-a_static/gen/yacc/frameworks/compile/mclinker/lib/Script/ScriptParser.h"




  /// A Bison parser.
  class ScriptParser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
#line 68 "frameworks/compile/mclinker/lib/Script/ScriptParser.yy"

  const std::string* string;
  uint64_t integer;
  RpnExpr* rpn_expr;
  StrToken* str_token;
  StringList* str_tokens;
  OutputSectDesc::Prolog output_prolog;
  OutputSectDesc::Type output_type;
  OutputSectDesc::Constraint output_constraint;
  OutputSectDesc::Epilog output_epilog;
  WildcardPattern* wildcard;
  InputSectDesc::Spec input_spec;

#line 221 "out/soong/.intermediates/frameworks/compile/mclinker/lib/Script/libmcldScript/android_arm64_armv8-a_static/gen/yacc/frameworks/compile/mclinker/lib/Script/ScriptParser.h"

    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        STRING = 258,
        LNAMESPEC = 259,
        INTEGER = 260,
        LINKER_SCRIPT = 261,
        DEFSYM = 262,
        VERSION_SCRIPT = 263,
        DYNAMIC_LIST = 264,
        ENTRY = 265,
        INCLUDE = 266,
        INPUT = 267,
        GROUP = 268,
        AS_NEEDED = 269,
        OUTPUT = 270,
        SEARCH_DIR = 271,
        STARTUP = 272,
        OUTPUT_FORMAT = 273,
        TARGET = 274,
        ASSERT = 275,
        EXTERN = 276,
        FORCE_COMMON_ALLOCATION = 277,
        INHIBIT_COMMON_ALLOCATION = 278,
        INSERT = 279,
        NOCROSSREFS = 280,
        OUTPUT_ARCH = 281,
        LD_FEATURE = 282,
        HIDDEN = 283,
        PROVIDE = 284,
        PROVIDE_HIDDEN = 285,
        SECTIONS = 286,
        MEMORY = 287,
        PHDRS = 288,
        ABSOLUTE = 289,
        ADDR = 290,
        ALIGN = 291,
        ALIGNOF = 292,
        BLOCK = 293,
        DATA_SEGMENT_ALIGN = 294,
        DATA_SEGMENT_END = 295,
        DATA_SEGMENT_RELRO_END = 296,
        DEFINED = 297,
        LENGTH = 298,
        LOADADDR = 299,
        MAX = 300,
        MIN = 301,
        NEXT = 302,
        ORIGIN = 303,
        SEGMENT_START = 304,
        SIZEOF = 305,
        SIZEOF_HEADERS = 306,
        CONSTANT = 307,
        MAXPAGESIZE = 308,
        COMMONPAGESIZE = 309,
        EXCLUDE_FILE = 310,
        COMMON = 311,
        KEEP = 312,
        SORT_BY_NAME = 313,
        SORT_BY_ALIGNMENT = 314,
        SORT_NONE = 315,
        SORT_BY_INIT_PRIORITY = 316,
        BYTE = 317,
        SHORT = 318,
        LONG = 319,
        QUAD = 320,
        SQUAD = 321,
        FILL = 322,
        DISCARD = 323,
        CREATE_OBJECT_SYMBOLS = 324,
        CONSTRUCTORS = 325,
        NOLOAD = 326,
        DSECT = 327,
        COPY = 328,
        INFO = 329,
        OVERLAY = 330,
        AT = 331,
        SUBALIGN = 332,
        ONLY_IF_RO = 333,
        ONLY_IF_RW = 334,
        ADD_ASSIGN = 335,
        SUB_ASSIGN = 336,
        MUL_ASSIGN = 337,
        DIV_ASSIGN = 338,
        AND_ASSIGN = 339,
        OR_ASSIGN = 340,
        LS_ASSIGN = 341,
        RS_ASSIGN = 342,
        LOGICAL_OR = 343,
        LOGICAL_AND = 344,
        EQ = 345,
        NE = 346,
        LE = 347,
        GE = 348,
        LSHIFT = 349,
        RSHIFT = 350,
        UNARY_PLUS = 351,
        UNARY_MINUS = 352
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;


    /// Build a parser object.
    ScriptParser (const class LinkerConfig& m_LDConfig_yyarg, class ScriptFile& m_ScriptFile_yyarg, class ScriptScanner& m_ScriptScanner_yyarg, class ObjectReader& m_ObjectReader_yyarg, class ArchiveReader& m_ArchiveReader_yyarg, class DynObjReader& m_DynObjReader_yyarg, class GroupReader& m_GroupReader_yyarg);
    virtual ~ScriptParser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

# if YYDEBUG
  public:
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
                                         const semantic_type* yyvaluep,
                                         const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
                                   const semantic_type* yyvaluep,
                                   const location_type* yylocationp);
  private:
    // Debugging.
    std::ostream* yycdebug_;
#endif


    // User arguments.
    const class LinkerConfig& m_LDConfig;
    class ScriptFile& m_ScriptFile;
    class ScriptScanner& m_ScriptScanner;
    class ObjectReader& m_ObjectReader;
    class ArchiveReader& m_ArchiveReader;
    class DynObjReader& m_DynObjReader;
    class GroupReader& m_GroupReader;
  };



#ifndef YYSTYPE
# define YYSTYPE mcld::ScriptParser::semantic_type
#endif
#ifndef YYLTYPE
# define YYLTYPE mcld::ScriptParser::location_type
#endif

#line 48 "frameworks/compile/mclinker/lib/Script/ScriptParser.yy"
} // mcld
#line 439 "out/soong/.intermediates/frameworks/compile/mclinker/lib/Script/libmcldScript/android_arm64_armv8-a_static/gen/yacc/frameworks/compile/mclinker/lib/Script/ScriptParser.h"



#endif // !YY_YY_OUT_SOONG_TEMP_SBOX_751B4A5581F25745E025435F464E2FD0F61484B9_OUT_FRAMEWORKS_COMPILE_MCLINKER_LIB_SCRIPT_SCRIPTPARSER_H_INCLUDED
