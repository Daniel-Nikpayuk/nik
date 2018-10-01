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

template<typename E1>
struct is_tuple
{
	template<typename>
	struct strict
	{
		using rtn = boolean<false>;
	};

	template<typename... Expressions>
	struct strict<tuple<Expressions...>>
	{
		using rtn = boolean<true>;
	};

	using rtn = typename strict
	<
		typename E1::rtn

	>::rtn;
};

struct identity
{
/*
	is equal:
*/
	template<typename Type1, typename Type2>
	struct is_equal
	{
		using rtn = boolean<false>;
	};

	template<typename Type>
	struct is_equal<Type, Type>
	{
		using rtn = boolean<true>;
	};

	//

	template<typename Type, typename Exp>
	struct is_equal<Type, act<Exp>>
	{
		using rtn = typename is_equal<Type, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Type>
	struct is_equal<act<Exp>, Type>
	{
		using rtn = typename is_equal<typename Exp::rtn, Type>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct is_equal<act<Exp1>, act<Exp2>>
	{
		using rtn = typename is_equal<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	is constant:
*/

	template<typename>
	struct is_constant
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type... Value>
	struct is_constant<constant<Type, Value...>>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp>
	struct is_constant<act<Exp>>
	{
		using rtn = typename is_constant<typename Exp::rtn>::rtn;
	};

/*
	is empty:
*/

	template<typename...>
	struct empty
	{
		using rtn = boolean<true>;
	};

	template<typename Exp, typename... Exps>
	struct empty<Exp, Exps...>
	{
		using rtn = boolean<false>;
	};
};

