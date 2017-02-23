/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#define STATIC_ASSERT													\
															\
	static_assert													\
	(														\
		Not<empty<E...>>::rtn::value,										\
		"block control flow does not end in a \"then\" statement."						\
	);

/***********************************************************************************************************************/

template<typename, typename> struct if_then { };
template<typename, typename> struct else_then { };
template<typename> struct then { };

/***********************************************************************************************************************/

template<typename...> struct sub_block;

template<typename P, typename E1, typename... E>
struct sub_block<else_then<P, E1>, E...>
{
	STATIC_ASSERT

	template<typename, typename, typename> struct strict;

	template<typename e1, typename... e>
	struct strict<boolean<true>, e1, sub_block<e...>>
	{
		using rtn = e1;
	};

	template<typename e1, typename... e>
	struct strict<boolean<true>, active<e1>, sub_block<e...>>
	{
		using rtn = typename e1::rtn;
	};

	template<typename e1, typename... e>
	struct strict<boolean<false>, e1, sub_block<e...>>
	{
		using rtn = typename sub_block<e...>::rtn;
	};

	using rtn = typename strict
	<
		typename P::rtn,
		E1,
		sub_block<E...>

	>::rtn;
};

template<typename E1>
struct sub_block<then<E1>>
{
	using rtn = E1;
};

template<typename E1>
struct sub_block<then<active<E1>>>
{
	using rtn = typename E1::rtn;
};

/***********************************************************************************************************************/

template<typename...> struct block;

template<typename P, typename E1, typename... E>
struct block<if_then<P, E1>, E...>
{
	STATIC_ASSERT

	template<typename, typename, typename> struct strict;

	template<typename e1, typename... e>
	struct strict<boolean<true>, e1, sub_block<e...>>
	{
		using rtn = e1;
	};

	template<typename e1, typename... e>
	struct strict<boolean<true>, active<e1>, sub_block<e...>>
	{
		using rtn = typename e1::rtn;
	};

	template<typename e1, typename... e>
	struct strict<boolean<false>, e1, sub_block<e...>>
	{
		using rtn = typename sub_block<e...>::rtn;
	};

	using rtn = typename strict
	<
		typename P::rtn,
		E1,
		sub_block<E...>

	>::rtn;
};

/***********************************************************************************************************************/

#undef STATIC_ASSERT

