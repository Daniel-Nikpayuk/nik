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
				relabel<Exps, begin>
			>

		>::rtn;
	};

/*
	re_evaluate_sequence:

	Side-effects are still possible within the sequence
	of residual evaluations as they might still include assignment.
*/

	template<typename Expressions1, typename Functor, typename Environment, typename Expressions2>
	struct re_evaluate_sequence
	{
		using Exps	= typename Expressions1::rtn;
		using Func	= typename Functor::rtn;
		using Env0	= typename Environment::rtn;
		using Frame	= typename Expressions2::rtn;

		using First	= typename car<Exps>::rtn;

		using Evaluated	= typename if_then_else
		<
			is_compound_definition<First>,

			evaluate_compound_definition
			<
				First,
				Func,
				Env0,
				Frame
			>,

			typename Func::template eval
			<
				First,
				Env0
			>

		>::rtn;

		using rtn = typename if_then_else
		<
			is_last<Exps>,
			Evaluated,

			re_evaluate_sequence
			<
				cdr<Exps>, // rest

				Func,

				if_then_else
				<
					is_environment<Evaluated>,
					Evaluated,
					Env0
				>,

				Frame
			>

		>::rtn;
	};

/*
	evaluate_sequence:
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct evaluate_sequence
	{
		using Exps	= typename Expressions::rtn;
		using Func	= typename Functor::rtn;

		using Frame = typename evaluate_compound_definitions
		<
			Exps,
			Func

		>::rtn;

		using rtn = typename if_then_else
		<
			is_null<Exps>,
			error_null_sequence,

			re_evaluate_sequence
			<
				Exps,
				Func,
				Environment,
				Frame
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const begin<Exp, Exps...> & e)
	{
		using is_empty = typename is_null<begin<Exps...>>::rtn;

		Dispatched::functor::display("begin: ");
		Exp::kind::functor::display(Exp());

		if (!is_empty::value) Recursed::functor::display(begin<Exps...>(), ", ");
		Dispatched::functor::display('\n');
	}

	inline static void display(const begin<> &)
	{
		Dispatched::functor::display("begin: null\n");
	}

