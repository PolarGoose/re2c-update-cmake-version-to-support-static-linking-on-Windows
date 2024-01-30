/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_CONF_SRC_PARSE_CONF_PARSER_H_INCLUDED
# define YY_CONF_SRC_PARSE_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef CONF_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CONF_DEBUG 1
#  else
#   define CONF_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CONF_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CONF_DEBUG */
#if CONF_DEBUG
extern int conf_debug;
#endif

/* Token kinds.  */
#ifndef CONF_TOKENTYPE
# define CONF_TOKENTYPE
  enum conf_tokentype
  {
    CONF_EMPTY = -2,
    CONF_EOF = 0,                  /* "end of file"  */
    CONF_error = 256,              /* error  */
    CONF_UNDEF = 257,              /* "invalid token"  */
    CONF_NUMBER = 258,             /* CONF_NUMBER  */
    CONF_STRING = 259,             /* CONF_STRING  */
    CONF_OPTION = 260              /* CONF_OPTION  */
  };
  typedef enum conf_tokentype conf_token_kind_t;
#endif

/* Value type.  */
#if ! defined CONF_STYPE && ! defined CONF_STYPE_IS_DECLARED
union CONF_STYPE
{
#line 22 "../src/parse/conf_parser.ypp"

    const char* str;
    int32_t num;
    bool bln;
    std::vector<std::string>* list;

#line 84 "src/parse/conf_parser.h"

};
typedef union CONF_STYPE CONF_STYPE;
# define CONF_STYPE_IS_TRIVIAL 1
# define CONF_STYPE_IS_DECLARED 1
#endif




int conf_parse (re2c::Input& in);


#endif /* !YY_CONF_SRC_PARSE_CONF_PARSER_H_INCLUDED  */
