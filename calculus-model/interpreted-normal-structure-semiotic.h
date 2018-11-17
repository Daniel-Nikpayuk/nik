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

//	error:

						  template<char... Message>
	using error				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  error<Message...>;

	using error_unbound_variable		= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  error<'u', 'n', 'b', 'o', 'u', 'n', 'd', '_', 'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e'>;

	using error_null_sequence		= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  error<'n', 'u', 'l', 'l', '_', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e'>;

	using error_unknown_expression_type	= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  error<'u', 'n', 'k', 'n', 'o', 'w', 'n', '_',
							'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', '_', 't', 'y', 'p', 'e'>;

//	environment:

						  template<typename Variable, typename Value>
	using binding				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  binding<Variable, Value>;

						  template<typename... Bindings>
	using frame				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  frame<Bindings...>;

	using null_frame			= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  frame<>;

						  template<typename... Frames>
	using environment			= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  environment<Frames...>;

	using null_environment			= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  environment<>;

//	quote:

						  template<typename Exp>
	using quote				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  quote<Exp>;

//	lambda:

						  template<typename... Exps>
	using arguments				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  arguments<Exps...>;

						  template<typename... Exps>
	using body				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  body<Exps...>;

						  template<typename... Exps>
	using lambda				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  lambda<Exps...>;

						  template<typename... Exps>
	using procedure				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  procedure<Exps...>;

//	definition:

						  template<typename... Exps>
	using define				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  define<Exps...>;

//	assignment:

						  template<typename Variable, typename Value>
	using set				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  set<Variable, Value>;

//	if_:

						  template<typename... Exps>
	using if_				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  if_<Exps...>;

//	begin:

						  template<typename... Exps>
	using begin				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  begin<Exps...>;

//	cond:

						  template<typename... Exps>
	using cond				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  cond<Exps...>;

						  template<typename... Exps>
	using try_				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  try_<Exps...>;

						  template<typename... Exps>
	using else_				= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  else_<Exps...>;

//	expression:

						  template<typename... Exps>
	using expression			= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  expression<Exps...>;

	using null_expression			= typename nik_module(normal, interpreted, calculus, semiotic)::structure::template
						  expression<>;

//

#include"undef-size_type.h"

