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
	#include nik_typedef(calculus, builtin, list, module)
	#include nik_typedef(calculus, builtin, list, structure)
	#include nik_typedef(calculus, builtin, list, alias)

/*
	is equal:

	The implementation given here is in fact more powerful than identity applied to lists: It holds for all types.
*/

	template<typename Expression1, typename Expression2>
	struct is_equal
	{
		using rtn = boolean
		<
			is_equal_structure<Expression1, Expression2>::value
		>;
	};

/*
	is list:
*/

	template<typename>
	struct is_list
	{
		using rtn = boolean<false>;
	};

	template<typename... Exps>
	struct is_list<list<Exps...>>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp>
	struct is_list<act<Exp>>
	{
		using rtn = typename is_list<typename Exp::rtn>::rtn;
	};

/*
	is null:
*/

	template<typename, typename Filler = void>
	struct is_null
	{
		using rtn = boolean<false>;
	};

	template<typename Filler>
	struct is_null<null_list, Filler>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp, typename Filler>
	struct is_null<act<Exp>, Filler>
	{
		using rtn = typename is_null<typename Exp::rtn, Filler>::rtn;
	};
};
