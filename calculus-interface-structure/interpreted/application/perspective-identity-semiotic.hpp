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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

/*
	is_application:
*/

	template<typename Expression>
	struct is_application
	{
		using Exp = typename Expression::rtn;

		template<typename SubExp>
		struct local
		{
			using first = typename SubExp::rtn;

			using rtn = typename evaluate
			<
				if_then
				<
					is_operate<first>,
					boolean<true>

				>, else_then
				<
					is_literal<first>,
					boolean<true>

				>, then
				<
					boolean<false>
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Exp>,
			boolean<false>,

			local
			<
				car<Exp>
			>

		>::rtn;
	};
};

