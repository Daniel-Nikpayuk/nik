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

/*
	identify:
*/

	template<typename Exp>
	struct identify
	{
		using rtn = typename evaluate
		<
			if_then
			<
				is_untyped_list<Exp>,
				list_info<true, untyped>

			>, else_then
			<
				is_typed_list<bool, Exp>,
				list_info<true, bool>

			>, else_then
			<
				is_typed_list<char, Exp>,
				list_info<true, char>

			>, else_then
			<
				is_typed_list<unsigned char, Exp>,
				list_info<true, unsigned char>

			>, else_then
			<
				is_typed_list<unsigned short, Exp>,
				list_info<true, unsigned short>

			>, else_then
			<
				is_typed_list<unsigned int, Exp>,
				list_info<true, unsigned int>

			>, else_then
			<
				is_typed_list<unsigned long, Exp>,
				list_info<true, unsigned long>

			>, else_then
			<
				is_typed_list<unsigned long long, Exp>,
				list_info<true, unsigned long long>

			>, else_then
			<
				is_typed_list<signed char, Exp>,
				list_info<true, signed char>

			>, else_then
			<
				is_typed_list<signed short, Exp>,
				list_info<true, signed short>

			>, else_then
			<
				is_typed_list<signed int, Exp>,
				list_info<true, signed int>

			>, else_then
			<
				is_typed_list<signed long, Exp>,
				list_info<true, signed long>

			>, else_then
			<
				is_typed_list<signed long long, Exp>,
				list_info<true, signed long long>

			>, then
			<
				list_info<false>
			>

		>::rtn;
	};

	template<typename Exp>
	struct identify<act<Exp>>
	{
		using rtn = identify<typename Exp::rtn>::rtn;
	};
};

