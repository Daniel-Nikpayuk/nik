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

	#include nik_typedef(calculus, constant, recursed, functor)

	#include nik_typedef(calculus, interpreted, , structure)

/*
	list_of_values:
*/

	template<typename Exps, typename Env, typename Functor>
	struct list_of_values
	{
		using rtn = typename if_then_else
		<
			is_null<Exps>, // has_no_operands
			null_list,

			cons
			<
				typename Functor::template evaluate
				<
					car<Exps>, // first operand
					Env
				>,

				list_of_values
				<
					cdr<Exps>, // rest_operands
					Env,
					Functor
				>
			>

		>::rtn;
	};

/*
	apply:
*/

	template<typename Procedure, typename Arguments>
	struct apply
	{
		using rtn = typename evaluate
		<
			if_then
			<
				is_operate<Procedure>, // is_primitive
				apply_primitive_procedure<Procedure, Arguments>

			>, else_then
			<
				is_compound_procedure<Procedure>,

				evaluate_sequence
				<
					procedure_body<Procedure>,

					extend_environment
					<
						procedure_parameters<Procedure>,
						Arguments,
						procedure_environment<Procedure>
					>,

					procedure_functor<Procedure>
				>

			>, then
			<
				undefined
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const <Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
};

