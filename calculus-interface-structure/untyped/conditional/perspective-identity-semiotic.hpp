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
	Assumes no evaluation for all tests.
*/

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(calculus, untyped, conditional, structure)

/*
	is_if_then:
*/

	template<typename>
	struct is_if_then
	{
		static constexpr bool value = false;
	};

	template<typename Pred, typename Exp>
	struct is_if_then<if_then<Pred, Exp>>
	{
		static constexpr bool value = true;
	};

/*
	is_else_then:
*/

	template<typename>
	struct is_else_then
	{
		static constexpr bool value = false;
	};

	template<typename Pred, typename Exp>
	struct is_else_then<else_then<Pred, Exp>>
	{
		static constexpr bool value = true;
	};

/*
	is_then:
*/

	template<typename>
	struct is_then
	{
		static constexpr bool value = false;
	};

	template<typename Exp>
	struct is_then<then<Exp>>
	{
		static constexpr bool value = true;
	};
};

