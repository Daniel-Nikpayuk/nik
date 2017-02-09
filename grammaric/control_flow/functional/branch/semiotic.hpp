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
		!tuple<statements...>::empty::value,									\
		"branch control flow does not end in a \"then\" statement."						\
	);

/***********************************************************************************************************************/

template<typename... statements> struct sub_branch;

template<typename predicate, typename expression, typename... statements>
struct sub_branch<else_then<predicate, expression>, statements...>
{
	STATIC_ASSERT

	static constexpr Parameter value = condition
	<
		predicate::value,

		expression,

		sub_branch<statements...>

	>::value;
};

template<typename expression>
struct sub_branch<then<expression>>
{
	static constexpr Parameter value = expression::value;
};

/***********************************************************************************************************************/

template<typename... statements> struct branch;

template<typename predicate, typename expression, typename... statements>
struct branch<if_then<predicate, expression>, statements...>
{
	STATIC_ASSERT

	static constexpr Parameter value = condition
	<
		predicate::value,

		expression,

		sub_branch<statements...>

	>::value;
};

/***********************************************************************************************************************/

#undef STATIC_ASSERT

