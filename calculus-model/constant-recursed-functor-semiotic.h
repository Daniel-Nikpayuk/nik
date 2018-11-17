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

	#define PREFIX		conref_

#else

	#define PREFIX

#endif

//

							  template<typename Exp, template<typename...> class Label>
	using nik_safe(PREFIX, relabel)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  relabel<Exp, Label>;

//

							  template<typename Type>
	using nik_safe(PREFIX, size_of)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  size_of<Type>;

//

							  template<typename Pred, typename Ante, typename Conse>
	using nik_safe(PREFIX, if_then_else)		= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  if_then_else<Pred, Ante, Conse>;

//

							  template<typename Exp1, typename Exp2>
	using nik_safe(PREFIX, cons)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  cons<Exp1, Exp2>;

							  template
							  <
								typename Exp, typename Index = typename
								nik_module(number, constant, calculus, semiotic)::structure::template
								number<0>
							  >
	using nik_safe(PREFIX, car)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  car<Exp, Index>;

							  template
							  <
								typename Exp, typename Index = typename
								nik_module(number, constant, calculus, semiotic)::structure::template
								number<0>
							  >
	using nik_safe(PREFIX, cdr)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  cdr<Exp, Index>;

							  template<typename Exp1, typename Exp2, typename... Exps>
	using nik_safe(PREFIX, catenate)		= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  catenate<Exp1, Exp2, Exps...>;

							  template<typename Exp1, typename Exp2>
	using nik_safe(PREFIX, push)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  push<Exp1, Exp2>;

							  template<typename List1, typename Value, typename List2>
	using nik_safe(PREFIX, unite)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  unite<List1, Value, List2>;

							  template<typename Exp>
	using nik_safe(PREFIX, length)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  length<Exp>;

//

							  template<typename... Exps>
	using nik_safe(PREFIX, evaluate)		= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  evaluate<Exps...>;

							  template<typename Exp>
	using nik_safe(PREFIX, not_the_case)		= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  not_the_case<Exp>;

							  template<typename... Exps>
	using nik_safe(PREFIX, or_else)			= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  or_else<Exps...>;

							  template<typename... Exps>
	using nik_safe(PREFIX, and_then)		= typename nik_module(recursed, constant, calculus, semiotic)::functor::template
							  and_then<Exps...>;

//

#undef PREFIX

#include"undef-size_type.h"

