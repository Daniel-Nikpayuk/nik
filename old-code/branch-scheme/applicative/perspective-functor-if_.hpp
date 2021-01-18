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
	if__alternative:

	Assumes the "if_" tag has been removed.
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
	if__make:
*/

	template<typename, typename, typename...> struct if__make;

	template<typename Predicate, typename Consequent>
	struct if__make<Predicate, Consequent>
	{
		using rtn = expression
		<
			if_,
			typename Predicate::rtn,
			typename Consequent::rtn
		>;
	};

	template<typename Predicate, typename Consequent, typename Alternative>
	struct if__make<Predicate, Consequent, Alternative>
	{
		using rtn = expression
		<
			if_,
			typename Predicate::rtn,
			typename Consequent::rtn,
			typename Alternative::rtn
		>;
	};

/*
	if__eval:

	Assumes the "if_" tag has been removed.
*/

	template<typename Expression, typename Environment, typename Functor>
	struct if__eval
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename trampoline_eval
		<
			if_then_else
			<
				is_true
				<
					trampoline_eval
					<
						car<Exp>,		// if__predicate
						Env,
						Func,
						stack_depth,
						stack_depth
					>
				>,

				car<Exp, one>,				// if__consequent

				if__alternative<Exp>
			>,

			Env,
			Func,

			stack_depth,
			stack_depth

		>::rtn;
	};

