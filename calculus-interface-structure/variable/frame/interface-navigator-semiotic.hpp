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
	Justification for catenate being the only navigator:

	It is both sufficient and minimal to have a "successor" operator,
	which catenates a singleton tuple to other arbitrary tuples.
	As there is more than one singleton tuple, this navigational
	problem reduces to navigating all singleton tuples.

	Singleton tuples are constructed as containing constants
	or other tuples. Without loss of generality, we can reduce
	this navigational problem to navigating all constant singleton
	tuples.

	As there is no universal navigator for constants, we must
	assume random access. As such, when this is generalized,
	we are left with manual construction (random access),
	combined with a general catenate operator.
*/

struct navigator
{
	#include nik_typedef(calculus, parameter, tuple, module)
	#include nik_typedef(calculus, parameter, tuple, structure)

	template<typename, typename, typename...> struct catenate;

	template<typename... Exps1, typename... Exps2, typename Exp, typename... Exps3>
	struct catenate<tuple<Exps1...>, tuple<Exps2...>, Exp, Exps3...>
	{
		using rtn = typename catenate
		<
			tuple<Exps1..., Exps2...>,
			Exp,
			Exps3...

		>::rtn;
	};

	template<typename... Exps1, typename Exp, typename... Exps2>
	struct catenate<tuple<Exps1...>, act<Exp>, Exps2...>
	{
		using rtn = typename catenate
		<
			tuple<Exps1...>,
			typename Exp::rtn,
			Exps2...

		>::rtn;
	};

	template<typename Exp, typename... Exps1, typename... Exps2>
	struct catenate<act<Exp>, tuple<Exps1...>, Exps2...>
	{
		using rtn = typename catenate
		<
			typename Exp::rtn,
			tuple<Exps1...>,
			Exps2...

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename... Exps>
	struct catenate<act<Exp1>, act<Exp2>, Exps...>
	{
		using rtn = typename catenate
		<
			typename Exp1::rtn,
			typename Exp2::rtn,
			Exps...

		>::rtn;
	};

	template<typename... Exps1, typename... Exps2>
	struct catenate<tuple<Exps1...>, tuple<Exps2...>>
	{
		using rtn = tuple<Exps1..., Exps2...>;
	};
};

