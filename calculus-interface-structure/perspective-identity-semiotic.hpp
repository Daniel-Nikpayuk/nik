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

	using type		= identity;

	#define safe_name

		#include nik_typedef(calculus, perspective, builtin, identity)

	#undef safe_name

	#include nik_typedef(calculus, builtin, list, structure)

	struct untyped_list
	{
		using kind					= module;

		using type					= untyped_list;

		using rtn					= untyped_list;
	};

	template<typename Type>
	struct typed_list
	{
		using kind					= module;

		using type					= typed_list;

		using rtn					= typed_list;

		using value_type				= Type;
	};

	struct not_a_list
	{
		using kind					= module;

		using type					= not_a_list;

		using rtn					= not_a_list;
	};

/*
	identify:
*/

	template<typename Type>
	struct identify
	{
		using rtn = typename evaluate
		<
			if_then
			<
				is_untyped_list<Exp>,
				untyped_list

			>, else_then
			<
				is_typed_list<bool, Exp>,
				typed_list<bool>

			>, else_then
			<
				is_typed_list<char, Exp>,
				typed_list<char>

			>, else_then
			<
				is_typed_list<unsigned char, Exp>,
				typed_list<unsigned char>

			>, else_then
			<
				is_typed_list<unsigned short, Exp>,
				typed_list<unsigned short>

			>, else_then
			<
				is_typed_list<unsigned int, Exp>,
				typed_list<unsigned int>

			>, else_then
			<
				is_typed_list<unsigned long, Exp>,
				typed_list<unsigned long>

			>, else_then
			<
				is_typed_list<unsigned long long, Exp>,
				typed_list<unsigned long long>

			>, else_then
			<
				is_typed_list<signed char, Exp>,
				typed_list<signed char>

			>, else_then
			<
				is_typed_list<signed short, Exp>,
				typed_list<signed short>

			>, else_then
			<
				is_typed_list<signed int, Exp>,
				typed_list<signed int>

			>, else_then
			<
				is_typed_list<signed long, Exp>,
				typed_list<signed long>

			>, else_then
			<
				is_typed_list<signed long long, Exp>,
				typed_list<signed long long>

			>, then
			<
				not_a_list
			>

		>::rtn;
	};

	template<typename Exp>
	struct identify<act<Exp>>
	{
		using rtn = identify<typename Exp::rtn>::rtn;
	};

/*
	is_list:
*/

	template<typename Exp>
	struct is_list
	{
		using ListType = typename identify<Exp>::rtn;

		static constexpr bool value = !is_equal<ListType, not_a_list>::value;
	};

	template<typename Exp>
	struct is_list<act<Exp>>
	{
		static constexpr bool value = is_list<typename Exp::rtn>::value;
	};

/*
	is_null:
*/

	template<typename List>
	struct is_null
	{
		using ListType = typename identify<List>::rtn;

		static constexpr bool value = typename if_then_else
		<
			is_equal<ListType, untyped_list>,
			is_untyped_null<List>,
			is_typed_null<ListType::value_type, List>

		>::rtn::value;
	};

	template<typename Exp>
	struct is_null<act<Exp>>
	{
		static constexpr bool value = is_null<typename Exp::rtn>::value;
	};
};

/*
	cons:

	There's no generic version of this function shared between untyped and typed lists.
*/

/*
	car:

	In the case of typed, it returns the typed call itself as it has no ::rtn (only ::value).
*/

	template<typename List> struct car
	{
		using ListType = typename identify<List>::rtn;

		using rtn = typename if_then_else
		<
			is_equal<ListType, untyped_list>,

			act
			<
				untyped_car<List>
			>,

			typed_car<ListType::value_type, List>

		>::rtn;
	};

	template<typename Exp>
	struct car<act<Exp>>
	{
		using rtn = typename car<typename Exp::rtn>::rtn;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename List> struct cdr
	{
		using ListType = typename identify<List>::rtn;

		using rtn = typename if_then_else
		<
			is_equal<info::list_type, untyped_list>,

			act
			<
				untyped_cdr<List>
			>,

			act
			<
				typed_cdr<ListType::value_type, List>
			>

		>::rtn;
	};

	template<typename Exp>
	struct cdr<act<Exp>>
	{
		using rtn = typename cdr<typename Exp::rtn>::rtn;
	};

/*
	catenate:
*/

	template<typename List1, typename List2, typename... Lists>
	struct catenate
	{
		using ListType = typename identify<List1>::rtn;

		using rtn = typename if_then_else
		<
			is_equal<ListType, untyped_list>,

			act
			<
				untyped_catenate<List1, List2, Lists...>
			>,

			act
			<
				typed_catenate<ListType::value_type, List1, List2, Lists...>
			>

		>::rtn;
	};

/*
	push:

	There's no generic version of this function shared between untyped and typed lists.
*/

/*
	at:

	In the case of typed, it returns the typed call itself as it has no ::rtn (only ::value).
*/

	template<size_type, typename> struct untyped_at;

	template<size_type index, typename List>
	struct at
	{
		using ListType = typename identify<List>::rtn;

		using rtn = typename if_then_else
		<
			is_equal<ListType, untyped_list>,

			act
			<
				untyped_at<index, List>
			>,

			typed_at<ListType::value_type, index, List>

		>::rtn;
	};

/*
	length:
*/

	template<typename List>
	struct length
	{
		using ListType = typename identify<List>::rtn;

		static constexpr size_type value = if_then_else
		<
			is_equal<ListType, untyped_list>,
			untyped_length<List>,
			typed_length<ListType::value_type, List>

		>::rtn::value;
	};

