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

	#include nik_typedef(calculus, interpreted, definition, structure)

/*
	is_definition:
*/

	template<typename Exp>
	struct is_definition
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<define<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_value_definition:
*/

	template<typename Expression>
	struct is_value_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename and_then
		<
			is_definition<Exp>,

			is_literal
			<
				car<Exp>
			>

		>::rtn;
	};

/*
	is_compound_definition:
*/

	template<typename Expression>
	struct is_compound_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename and_then
		<
			is_definition<Exp>,

			not_the_case
			<
				is_literal
				<
					car<Exp>
				>
			>

		>::rtn;
	};
};

