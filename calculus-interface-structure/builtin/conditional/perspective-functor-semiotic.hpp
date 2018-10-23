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

	#include nik_typedef(calculus, perspective, builtin, functor)

	#include nik_typedef(calculus, builtin, conditional, structure)

/*
	sub_evaluate:
*/

	template<typename...> struct sub_evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct sub_evaluate
	<
		else_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred::value,
			Exp,

			act
			<
				sub_evaluate
				<
					Exps...
				>
			>

		>::rtn;
	};

	template<typename Exp>
	struct sub_evaluate
	<
		then<Exp>
	>
	{
		using rtn = Exp;
	};

	template<typename Exp>
	struct sub_evaluate
	<
		then<act<Exp>>
	>
	{
		using rtn = typename Exp::rtn;
	};

/***********************************************************************************************************************/

/*
	evaluate:
*/

	template<typename...> struct evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct evaluate
	<
		if_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred::value,
			Exp,

			act
			<
				sub_evaluate
				<
					Exps...
				>
			>

		>::rtn;
	};
};

