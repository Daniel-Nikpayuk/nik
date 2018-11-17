/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

//	quote:

							  template<typename Exp>
	using quote					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  quote<Exp>;

//	lambda:

							  template<typename... Exps>
	using function					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  arguments<Exps...>;

							  template<typename... Exps>
	using arguments					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  arguments<Exps...>;

							  template<typename... Exps>
	using args					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  arguments<Exps...>;

							  template<typename... Exps>
	using body					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  body<Exps...>;

							  template<typename... Exps>
	using lambda					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  lambda<Exps...>;

//	definition:

							  template<typename... Exps>
	using define					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  define<Exps...>;

//	assignment:

							  template<typename Variable, typename Value>
	using set					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  set<Variable, Value>;

//	if_:

							  template<typename... Exps>
	using if_					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  if_<Exps...>;

//	begin:

							  template<typename... Exps>
	using begin					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  begin<Exps...>;

//	cond:

							  template<typename... Exps>
	using cond					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  cond<Exps...>;

							  template<typename... Exps>
	using try_					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  try_<Exps...>;

							  template<typename... Exps>
	using else_					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  else_<Exps...>;

//	expression:

							  template<typename... Exps>
	using expression				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

	using null_expression				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<>;

							  template<typename... Exps>
	using e						= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

							  template<typename... Exps>
	using program					= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
							  expression<Exps...>;

//	evaluators:

							  template
							  <
								typename Exp, typename Env = typename
								nik_module(normal, interpreted, calculus, semiotic)::structure::template
								environment<>
							  >
	using nik_safe(PREFIX, eval)			= typename nik_module(normal, interpreted, calculus, semiotic)::functor::template
							  eval<Exp, Env>;

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

