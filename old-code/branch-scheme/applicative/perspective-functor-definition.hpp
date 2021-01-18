/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	definition_define_value:

	Assumes the "define" tag has been removed.
*/

	template<typename Expression, typename Environment, typename Functor>
	struct definition_define_value
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename environment_define
		<
			car<Exp>,		// definition_variable

			trampoline_eval
			<
				car<Exp, one>,	// definition_value
				Env,
				Func,
				stack_depth,
				stack_depth
			>,

			Env

		>::rtn;
	};

/*
	definition_frame_define:

	We store the procedure definitions as continuations
	to signal that whenever they're looked up they are
	continuations.

	Assumes the "define" tag has been removed.
*/

	template<typename Expression1, typename Expression2>
	struct definition_frame_define
	{
		using Exp	= typename Expression1::rtn;
		using Frame	= typename Expression2::rtn;

		using Params	= typename car<Exp>::rtn;

		using rtn = typename cons
		<
			binding_make
			<
				car<Params>,		// definition_variable

				continuation_make
				<
					cdr<Params>,	// lambda_arguments
					cdr<Exp>	// lambda_body
				>
			>,

			Frame

		>::rtn;
	};

/*
	definition_define_compound:

	Assumes the "define" tag has been removed.
*/

	template<typename Expression, typename Environment>
	struct definition_define_compound
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;

		using Params	= typename car<Exp>::rtn;

		using rtn = typename environment_define
		<
			car<Params>,		// definition_variable

			procedure_make
			<
				cdr<Params>,	// lambda_arguments
				cdr<Exp>,	// lambda_body
				Env
			>,

			Env

		>::rtn;
	};

/*
	definition_scan_scope:
*/

	template<typename Exps1, typename Exps2 = null_frame>
	struct definition_scan_scope
	{
		using Scope	= typename Exps1::rtn;
		using Frame	= typename Exps2::rtn;

		template<typename Exp1, typename Exp2>
		struct recurse
		{
			using first = typename Exp1::rtn;

			using rtn = typename definition_scan_scope
			<
				Exp2, // rest

				if_then_else
				<
					is_compound_definition<first>,

					definition_frame_define
					<
						cdr<first>,
						Frame
					>,

					Frame
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Scope>,

			Frame,

			recurse
			<
				car<Scope>,
				cdr<Scope>
			>

		>::rtn;
	};

