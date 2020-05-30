/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	To do ?	After extending the environment through pre-evaluation,
		remove those definitions from the list to be evaluated.
		If they exist in a recursive function definition,
		they will be processed each time for nothing.
*/

/*
	begin_sequence_to_expression:
*/

	template<typename Expressions>
	struct begin_sequence_to_expression
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
				cons
				<
					begin,
					Exps
				>
			>

		>::rtn;
	};

/*
	begin_sequence_eval:

	Side-effects are still possible within the sequence
	of residual evaluations as they might still include assignment.
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct begin_sequence_eval
	{
		using Exps		= typename Expressions::rtn;
		using Env		= typename Environment::rtn;
		using Func		= typename Functor::rtn;

		using First		= typename car<Exps>::rtn;

		using Current = typename if_then_else
		<
			is_compound_definition<First>,

			definition_define_compound
			<
				cdr<First>,
				Env
			>,

			trampoline_eval
			<
				First,
				Env,
				Func,
				stack_depth,	
				stack_depth
			>

		>::rtn;

		using rtn = typename if_then_else
		<
			is_last<Exps>,

			Current,

			begin_sequence_eval
			<
				cdr<Exps>, // rest

				if_then_else
				<
					is_<Current, environment>,
					Current,
					Env
				>,

				Func
			>

		>::rtn;
	};

/*
	begin_eval

	Assumes the "begin" tag has been removed.
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct begin_eval
	{
		using Exps	= typename Expressions::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename if_then_else
		<
			is_null<Exps>,

			error_null_sequence,

			begin_sequence_eval
			<
				Exps,

				cons
				<
					definition_scan_scope<Exps>,
					Environment
				>,

				Func
			>

		>::rtn;
	};

