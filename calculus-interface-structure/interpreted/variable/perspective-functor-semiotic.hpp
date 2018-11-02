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

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

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
};

