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

	using rtn		= functor;

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

	#include nik_typedef(calculus, interpreted, environment, identity)

	#include nik_typedef(calculus, interpreted, begin, structure)
	#include nik_typedef(calculus, interpreted, begin, identity)

/*
	make_begin:
*/

	template<typename Exp>
	struct make_begin
	{
		template<typename> struct strict;

		template<typename... Exps, template<typename...> class Sequence>
		struct strict<Sequence<Exps...>>
		{
			using rtn = begin<Exps...>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	sequence_to_expression:
*/

	template<typename Expressions>
	struct sequence_to_expression
	{
		using Exps = typename Expressions::rtn;

		using rtn = typename evaluate
		<
			if_then
			<
				is_null<Exps>,
				Exps

			>, else_then
			<
				is_last<Exps>,
				car<Exps>

			>, then
			<
				make_begin<Exps>
			>

		>::rtn;
	};

/*
	evaluate_sequence:

	Side-effects are possible within the sequence of evaluations.
	The only effects necessary in considering are ones which change
	the environment as it is applicable further down the sequence.
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct evaluate_sequence
	{
		using Exps	= typename Expressions::rtn;
		using Env0	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using First = typename Func::template evaluate
		<
			car<Exps>, // first_exp
			Env0

		>::rtn;

		using rtn = typename if_then_else
		<
			is_last<Exps>,
			First,

			evaluate_sequence
			<
				cdr<Exps>, // rest_exps

				if_then_else
				<
					is_environment<First>,
					First,
					Env0
				>,

				Func
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const begin<Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
};

