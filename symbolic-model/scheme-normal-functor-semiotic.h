/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik.
**
** nik is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** nik is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik. If not, see
** <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#include"define-size_type.h"

#ifdef safe_name

	#define PREFIX		intnof_

#else

	#define PREFIX

#endif

//	constants:

							  template<bool... Values>
	using boolean					= typename nik_module(boolean, constant, calculus, semiotic)::structure::template
							  boolean<Values...>;

							  template<bool... Values>
	using b						= typename nik_module(boolean, constant, calculus, semiotic)::structure::template
							  boolean<Values...>;

							  template<char... Chars>
	using literal					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<Chars...>;

							  template<char... Chars>
	using l						= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<Chars...>;

							  template<SIZE_TYPE... Values>
	using number					= typename nik_module(number, constant, calculus, semiotic)::structure::template
							  number<Values...>;

							  template<SIZE_TYPE... Values>
	using n						= typename nik_module(number, constant, calculus, semiotic)::structure::template
							  number<Values...>;

							  template<typename Type>
	using type					= typename nik_module(recursed, constant, calculus, semiotic)::structure::template
							  type<Type>;

							  template<typename Type>
	using t						= typename nik_module(recursed, constant, calculus, semiotic)::structure::template
							  type<Type>;

							  template<typename... Types>
	using list					= typename nik_module(recursed, constant, calculus, semiotic)::structure::template
							  list<Types...>;

							  template<char... Chars>
	using op					= typename nik_module(operate, constant, calculus, semiotic)::structure::template
							  operate<Chars...>;

//	keywords:

	using quote					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  quote;

	using lambda					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  lambda;

	using procedure					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  procedure;

	using define					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  define;

	using set					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  set;

	using if_					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  if_;

	using begin					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  begin;

	using cond					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  cond;

	using else_					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::
							  else_;

//

	using size_of					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<'s', 'i', 'z', 'e', '_', 'o', 'f'>;

	using is_null					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<'i', 's', '_', 'n', 'u', 'l', 'l'>;

	using cons					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<'c', 'o', 'n', 's'>;

	using car					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<'c', 'a', 'r'>;

	using cdr					= typename nik_module(literal, constant, calculus, semiotic)::structure::template
							  literal<'c', 'd', 'r'>;

//	expression:

							  template<typename... Exps>
	using expression				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

	using null_expression				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<>;

							  template<typename... Exps>
	using program					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

							  template<typename... Exps>
	using exp					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

							  template<typename... Exps>
	using e						= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

//	interpeter:

							  template
							  <
								typename Prog, typename Env = typename
								nik_module(normal, interpreted, calculus, semiotic)::structure::template
								environment<>
							  >
	using nik_safe(PREFIX, interpret)		= typename nik_module(normal, interpreted, calculus, semiotic)::functor::template
							  interpret<Prog, Env>;

//

#undef PREFIX

#include"undef-size_type.h"

