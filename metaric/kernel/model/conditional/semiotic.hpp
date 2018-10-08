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

struct expression
{
	#include nik_unpack_typedef(module)
	#include nik_unpack_typedef(structure)

	template<typename...> struct sub_re_evaluate;
	template<typename...> struct sub_evaluate;
	template<typename...> struct re_evaluate;
	template<typename...> struct evaluate;

/*
	sub_re_evaluate:

	prevents ambiguity during template type resolution.
*/

	template<typename Exp, typename... Exps>
	struct sub_re_evaluate
	<
		else_then<boolean<true>, Exp>,
		Exps...

	> { using rtn = Exp; };

	template<typename Exp, typename... Exps>
	struct sub_re_evaluate
	<
		else_then<boolean<false>, Exp>,
		Exps...

	> { using rtn = typename sub_evaluate<Exps...>::rtn; };

	template<typename Exp, typename... Exps>
	struct sub_re_evaluate
	<
		else_then<boolean<true>, act<Exp>>,
		Exps...

	> { using rtn = typename Exp::rtn; };

/***********************************************************************************************************************/

/*
	sub_evaluate:
*/

	template<typename Pred, typename Exp, typename... Exps>
	struct sub_evaluate
	<
		else_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename sub_re_evaluate
		<
			else_then<typename Pred::rtn, Exp>,
			Exps...

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
/***********************************************************************************************************************/

/*
	re_evaluate:

	prevents ambiguity during template type resolution.
*/

	template<typename Exp, typename... Exps>
	struct re_evaluate
	<
		if_then<boolean<true>, Exp>,
		Exps...

	> { using rtn = Exp; };

	template<typename Exp, typename... Exps>
	struct re_evaluate
	<
		if_then<boolean<false>, Exp>,
		Exps...

	> { using rtn = typename sub_evaluate<Exps...>::rtn; };

	template<typename Exp, typename... Exps>
	struct re_evaluate
	<
		if_then<boolean<true>, act<Exp>>,
		Exps...

	> { using rtn = typename Exp::rtn; };

/***********************************************************************************************************************/

/*
	evaluate:
*/

	template<typename Pred, typename Exp, typename... Exps>
	struct evaluate
	<
		if_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename re_evaluate
		<
			if_then<typename Pred::rtn, Exp>,
			Exps...

		>::rtn;
	};
};

