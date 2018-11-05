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

//

				  template<bool... Values>
	using b			= typename nik_module(boolean, constant, calculus, semiotic)::structure::template
				  boolean<Values...>;

				  template<char... Chars>
	using l			= typename nik_module(literal, constant, calculus, semiotic)::structure::template
				  literal<Chars...>;

				  template<SIZE_TYPE... Values>
	using n			= typename nik_module(number, constant, calculus, semiotic)::structure::template
				  number<Values...>;

				  template<char... Chars>
	using op		= typename nik_module(operate, constant, calculus, semiotic)::structure::template
				  operate<Chars...>;

				  template<typename Exp>
	using quote		= typename nik_module(quote, interpreted, calculus, semiotic)::structure::template
				  quote<Exp>;

				  template<typename Variable, typename Value>
	using set		= typename nik_module(assignment, interpreted, calculus, semiotic)::structure::template
				  set<Variable, Value>;

				  template<typename... Exps>
	using define		= typename nik_module(definition, interpreted, calculus, semiotic)::structure::template
				  define<Exps...>;

				  template<typename... Exps>
	using if_		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  if_<Exps...>;

				  template<typename... Exps>
	using cond		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  cond<Exps...>;

				  template<typename... Exps>
	using else_		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  else_<Exps...>;

				  template<typename... Exps>
	using function		= typename nik_module(lambda, interpreted, calculus, semiotic)::structure::template
				  arguments<Exps...>;

				  template<typename... Exps>
	using args		= typename nik_module(lambda, interpreted, calculus, semiotic)::structure::template
				  arguments<Exps...>;

				  template<typename... Exps>
	using body		= typename nik_module(lambda, interpreted, calculus, semiotic)::structure::template
				  body<Exps...>;

				  template<typename Args, typename Body>
	using lambda		= typename nik_module(lambda, interpreted, calculus, semiotic)::structure::template
				  lambda<Args, Body>;

				  template<typename... Exps>
	using begin		= typename nik_module(begin, interpreted, calculus, semiotic)::structure::template
				  begin<Exps...>;

				  template<typename... Exps>
	using expression	= typename nik_module(expression, interpreted, calculus, semiotic)::structure::template
				  expression<Exps...>;

				  template<typename... Exps>
	using e			= typename nik_module(expression, interpreted, calculus, semiotic)::structure::template
				  expression<Exps...>;

				  template<typename... Exps>
	using program		= typename nik_module(expression, interpreted, calculus, semiotic)::structure::template
				  expression<Exps...>;

	using null_expression	= typename nik_module(expression, interpreted, calculus, semiotic)::structure::template
				  expression<>;

//

#include"undef-size_type.h"

