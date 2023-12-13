/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 177 "out/soong/.intermediates/external/selinux/checkpolicy/checkpolicy/linux_glibc_x86_64/gen/yacc/external/selinux/checkpolicy/policy_parse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_OUT_SOONG_TEMP_SBOX_288F4549ADF4444E35FCFFAF10E314760461EC2F_OUT_EXTERNAL_SELINUX_CHECKPOLICY_POLICY_PARSE_H_INCLUDED  */
