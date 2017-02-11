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
		!empty<statements...>::rtn::value,									\
		"block control flow does not end in a \"then\" statement."						\
	);

/***********************************************************************************************************************/

template<typename, typename> struct if_then { };
template<typename, typename> struct else_then { };
template<typename> struct then { };

/***********************************************************************************************************************/

template<typename... statements> struct sub_block;

template<typename predicate, typename expression, typename... statements>
struct sub_block<else_then<predicate, expression>, statements...>
{
	STATIC_ASSERT

	using rtn = typename conditional
	<
		predicate,
		expression,
		sub_block<statements...>

	>::rtn;
};

template<typename expression>
struct sub_block<then<expression>>
{
	using rtn = typename expression::rtn;
};

/***********************************************************************************************************************/

template<typename... statements> struct block;

template<typename predicate, typename expression, typename... statements>
struct block<if_then<predicate, expression>, statements...>
{
	STATIC_ASSERT

	using rtn = typename conditional
	<
		predicate,
		expression,
		sub_block<statements...>

	>::rtn;
};

/***********************************************************************************************************************/

#undef STATIC_ASSERT

