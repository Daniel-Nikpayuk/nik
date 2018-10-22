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

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, typedin, boolean, identity)

	#define safe_name

		#include nik_typedef(calculus, typedin, if_then, functor)
		#include nik_typedef(calculus, evaltin, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, evaltin, expression, structure)

/*
*/

/*
	evaluate:
*/

	template<typename Exp, typename Env = null_environment>
	struct evaluate
	{
/*
		using rtn = typename disiftf_evaluate
		<
			if_then
			<
				is_self_evaluating<Exp>,
				Exp

			>, else_then
			<
				is_variable<Exp>,
				act
				<
					lookup<Env, Exp>
				>

			>, then
			<
				undefined
			>

		>::rtn;
*/
	};

	template<typename Env>
	struct evaluate<null_expression, Env>
	{
		using rtn = null_expression;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const expression<Exp, Exps...> & e)
	{
		using is_empty = typename is_null<expression<Exps...>>::rtn;

		Builtin::functor::display("expression: ");
		Exp::kind::functor::display(Exp());

		if (!is_empty::value) Kernel::functor::display(expression<Exps...>(), ", ");
		Builtin::functor::display('\n');
	}

	inline static void display(const null_expression &)
	{
		Builtin::functor::display("expression: null\n");
	}
};

