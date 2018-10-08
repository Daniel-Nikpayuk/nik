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

/*
	Assumes Type has an implicit equals operator.
*/

struct proximity
{
	#include nik_unpack_typedef(module)
	#include nik_unpack_typedef(structure)
	#include nik_unpack_typedef(alias)

/*
	less than:
*/

	template<typename, typename>
	struct less_than
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct less_than
	<
		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = boolean<(Value1 < Value2)>;
	};

	template<typename Constant, typename Exp>
	struct less_than<Constant, act<Exp>>
	{
		using rtn = typename less_than<Constant, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Constant>
	struct less_than<act<Exp>, Constant>
	{
		using rtn = typename less_than<typename Exp::rtn, Constant>::rtn;
	};

/*
	less than or equal:
*/

	template<typename, typename>
	struct less_than_or_equal
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct less_than_or_equal
	<
		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = boolean<(Value1 <= Value2)>;
	};

	template<typename Constant, typename Exp>
	struct less_than_or_equal<Constant, act<Exp>>
	{
		using rtn = typename less_than_or_equal<Constant, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Constant>
	struct less_than_or_equal<act<Exp>, Constant>
	{
		using rtn = typename less_than_or_equal<typename Exp::rtn, Constant>::rtn;
	};

/*
	greater than:
*/

	template<typename, typename>
	struct greater_than
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct greater_than
	<
		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = boolean<(Value1 > Value2)>;
	};

	template<typename Constant, typename Exp>
	struct greater_than<Constant, act<Exp>>
	{
		using rtn = typename greater_than<Constant, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Constant>
	struct greater_than<act<Exp>, Constant>
	{
		using rtn = typename greater_than<typename Exp::rtn, Constant>::rtn;
	};

/*
	greater than or equal:
*/

	template<typename, typename>
	struct greater_than_or_equal
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct greater_than_or_equal
	<
		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = boolean<(Value1 >= Value2)>;
	};

	template<typename Constant, typename Exp>
	struct greater_than_or_equal<Constant, act<Exp>>
	{
		using rtn = typename greater_than_or_equal<Constant, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Constant>
	struct greater_than_or_equal<act<Exp>, Constant>
	{
		using rtn = typename greater_than_or_equal<typename Exp::rtn, Constant>::rtn;
	};

	//

};

