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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, dispatch, if_then_else, structure)

/*
	re_evaluate:

	prevents ambiguity during template type resolution.
*/

	template<typename> struct re_evaluate;

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<true>, Exp1, Exp2>
	>
	{
		using rtn = Exp1;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<false>, Exp1, Exp2>
	>
	{
		using rtn = Exp2;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<false>, Exp1, act<Exp2>>
	>
	{
		using rtn = typename Exp2::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<true>, act<Exp1>, Exp2>
	>
	{
		using rtn = typename Exp1::rtn;
	};

/*
	evaluate:
*/

	template<typename> struct evaluate;

	template<typename Pred, typename Exp1, typename Exp2>
	struct evaluate
	<
		if_then_else<Pred, Exp1, Exp2>
	>
	{
		using rtn = typename re_evaluate
		<
			if_then_else<typename Pred::rtn, Exp1, Exp2>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Pred, typename Exp1, typename Exp2>
	inline static void display(const if_then_else<Pred, Exp1, Exp2> &)
	{
		Builtin::functor::display("if_then_else: ");

		Pred::kind::functor::display(Pred());
		Builtin::functor::display(" ? ");

		Exp1::kind::functor::display(Exp1());
		Builtin::functor::display(" : ");

		Exp2::kind::functor::display(Exp2());
	}
};

