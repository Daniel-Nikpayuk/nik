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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, handle, functor)
	#include nik_typedef(symbolic, calculus, boolean, functor)
	#include nik_typedef(symbolic, calculus, recurse, functor)

	#include nik_typedef(symbolic, calculus, colist, structure)

/*
	if_then:
*/

	template<typename Predicate, typename Expression>
	using if_then = if_then_else
	<
		Predicate::value,
		Expression,
		skip
	>;

/*
	else_then:
*/

	template<typename Predicate, typename Expression>
	using else_then = if_then_else
	<
		Predicate::value,
		Expression,
		skip
	>;

/*
	then:
*/

	template<typename Expression>
	using then = Expression;

/***********************************************************************************************************************/

/*
	cases: (typename_colist)

	Assumes non-empty, in order: if_then, else_then, then.

	"skip" is a reserved keyword.

	Not grammatically safe.

	This current implementation memoizes more than I'd like, but I yet figured out how to get faster
	versions accepted by the compiler.

	Reimplement using list find ?
*/

	template<typename, typename...> struct colist;

	template<typename Exp1, typename Exp2, typename... Exps>
	struct colist<Exp1, Exp2, Exps...>
	{
		using rtn = head_if_then_else
		<
			is_equal<Exp1, skip>::value,

			colist<Exp2, Exps...>,

			Exp1
		>;
	};

	template<typename Exp>
	struct colist<Exp>
	{
		using rtn = Exp;
	};

	template<typename Exp, typename... Exps>
	using cases = call<colist<Exp, Exps...>>;

/***********************************************************************************************************************/

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

};
