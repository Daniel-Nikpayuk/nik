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
		struct type_match
		{
			using first = typename SubExp::rtn;

			using rtn = typename or_else
			<
				is_operate<first>,
				is_literal<first>

			>::rtn;
		};

		using rtn = typename and_then
		<
			is_list<Exp>,

			not_the_case
			<
				is_null<Exp>
			>,

			type_match
			<
				car<Exp>
			>

		>::rtn;
	};
};

