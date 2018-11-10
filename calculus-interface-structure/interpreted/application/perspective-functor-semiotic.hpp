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

	#define safe_name

		#include nik_typedef(calculus, interpreted, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, lambda, identity)
	#include nik_typedef(calculus, interpreted, lambda, functor)
	#include nik_typedef(calculus, interpreted, begin, identity)
	#include nik_typedef(calculus, interpreted, begin, functor)

	#include nik_typedef(calculus, interpreted, application, identity)

/*
	list_of_values:
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct list_of_values
	{
		using Exps	= typename Expressions::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename if_then_else
		<
			is_null<Exps>, // has_no_operands
			null_list,

			cons
			<
				typename Func::template evaluate
				<
					car<Exps>, // first operand
					Env
				>,

				list_of_values
				<
					cdr<Exps>, // rest_operands
					Env,
					Func
				>
			>

		>::rtn;
	};

/*
	apply_primitive:
*/

	template<typename Operate, typename ArgValues>
	struct apply_primitive
	{
		template<typename> struct strict;

		template<typename Value, typename... Values, template<typename...> class Sequence>
		struct strict<Sequence<Value, Values...>>
		{
			using rtn = typename Value::kind::functor::template apply
			<
				typename Operate::rtn,
				Value, Values...

			>::rtn;
		};

		using rtn = typename strict
		<
			typename ArgValues::rtn

		>::rtn;
	};

/*
	apply_compound:
*/

	template<typename Variable, typename ArgValues, typename Environment, typename Functor>
	struct apply_compound
	{
		using Var	= typename Variable::rtn;
		using Values	= typename ArgValues::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using Proc = typename Func::template evaluate
		<
			Var,
			Env

		>::rtn;

		using Residual = typename cdr<Proc, two>::rtn;

		using Compound = typename if_then_else
		<
			is_null<Residual>,

			push
			<
				Env,
				Proc
			>,

			make_procedure
			<
				car<Proc>, // ProcArgs
				car<Proc, one>, // ProcBody
				car<Proc, two>, // ProcFunc

				cons
				<
					car<Proc, four>, // ProcFrm
					car<Proc, three> // ProcEnv
				>
			>

		>::rtn;

		using rtn = typename evaluate_sequence
		<
			car<Compound, one>, // CompoundBody

			intenf_construct // extend_environment
			<
				car<Compound>, // CompoundArgs
				Values,
				car<Compound, three> // CompoundEnv
			>,

			car<Compound, two> // CompoundFunc

		>::rtn;
	};

/*
	evaluate_application:
*/

	template<typename Operator, typename Arguments, typename Environment, typename Functor>
	struct evaluate_application
	{
		using Method	= typename Operator::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using Values	= typename list_of_values
		<
			Arguments,
			Env,
			Func

		>::rtn;

		using rtn = typename if_then_else
		<
			is_operate<Method>, // is_primitive

			apply_primitive
			<
				Method,
				Values
			>,

			apply_compound
			<
				Method,
				Values,
				Env,
				Func
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	template<typename Exp>
	inline static void display(const <Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
*/
};

