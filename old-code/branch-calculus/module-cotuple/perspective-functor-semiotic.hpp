/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(symbolic, core, kernel, identity)

		#include nik_typedef(symbolic, calculus, boolean, functor)		// prevents if_then collision.

	#undef safe_name

	#include nik_typedef(symbolic, calculus, list, module)
	#include nik_typedef(symbolic, calculus, list, functor)

/*
	if_then:
*/

	template<typename Predicate, typename Expression>
	using if_then = calbof_if_then_else
	<
		Predicate::value,
		Expression,
		filler
	>;

/*
	else_then:
*/

	template<typename Predicate, typename Expression>
	using else_then = calbof_if_then_else
	<
		Predicate::value,
		Expression,
		filler
	>;

/*
	then:
*/

	template<typename Expression>
	using then = Expression;

/*
	cases: (typename_colist)

	Not grammatically safe.
*/

	struct is_not_filler
	{
		template<typename Exp>
		using result = corkei_is_not_filler<Exp>;
	};

	template<typename Exp0, typename Exp1, typename... Exps>
	using cases = typename List::functor::template cp_typename_find
	<
		typename List::functor::ch_typename_list_to_ping

	>::template result
	<
		typename_filler, filler, is_not_filler, 0, filler, Exp0, Exp1, Exps...
	>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

};

