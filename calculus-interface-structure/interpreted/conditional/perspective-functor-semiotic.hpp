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

	#include nik_typedef(calculus, interpreted, begin, functor)

	#include nik_typedef(calculus, interpreted, conditional, structure)
	#include nik_typedef(calculus, interpreted, conditional, identity)

/*
	if__alternative:
*/

	template<typename Exp>
	struct if__alternative
	{
		using Alt = typename cdr<Exp, one>::rtn;

		using rtn = typename if_then_else
		<
			is_null<Alt>,
			boolean<false>,
			car<Alt>

		>::rtn;
	};

/*
	make_if_:
*/

	template<typename Predicate, typename Consequent, typename Alternative>
	struct make_if_
	{
		using rtn = if_
		<
			typename Predicate::rtn,
			typename Consequent::rtn,
			typename Alternative::rtn
		>;
	};

/*
	evaluate_if_:
*/

	template<typename Expression, typename Environment, typename Functor>
	struct evaluate_if_
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename if_then_else
		<
			is_true
			<
				typename Func::template evaluate
				<
					car<Exp>, // if__predicate
					Env
				>
			>,

			typename Func::template evaluate
			<
				car<Exp, one>, // if__consequent
				Env
			>,

			typename Func::template evaluate
			<
				if__alternative<Exp>,
				Env
			>

		>::rtn;
	};

/*
	cond_to_if_:
*/

	template<typename Expressions>
	struct cond_to_if_
	{
		using Clauses = typename Expressions::rtn;

		template<typename Exp1, typename Exp2>
		struct recurse
		{
			using first = typename Exp1::rtn;
			using rest = typename Exp2::rtn;

			using rtn = typename if_then_else
			<
				is_else_<first>,

				if_then_else
				<
					is_null<rest>,

					sequence_to_expression<first>,

					error<'e', 'l', 's', 'e', '_', ' ', 'c', 'l', 'a', 'u', 's', 'e',
						' ', 'i', 's', 'n', '\'', 't', ' ', 'l', 'a', 's', 't'>
				>,

				make_if_
				<
					car<first>, // cond_predicate

					sequence_to_expression
					<
						cdr<first> // cond_actions
					>,

					cond_to_if_<rest>
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Clauses>,
			boolean<false>,

			recurse
			<
				car<Clauses>,
				cdr<Clauses>
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const if_<Exp, Exps...> & i)
	{
		using is_empty = typename is_null<if_<Exps...>>::rtn;

		Dispatched::functor::display("if_: ");
		Exp::kind::functor::display(Exp());

		if (!is_empty::value) Recursed::functor::display(if_<Exps...>(), ", ");
	}

	inline static void display(const if_<> &)
	{
		Dispatched::functor::display("if_: null");
	}
};

