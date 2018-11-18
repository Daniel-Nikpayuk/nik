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

	#include nik_typedef(calculus, perspective, typed, identity)
	#include nik_typedef(calculus, untyped, conditional, structure)
	#include nik_typedef(calculus, untyped, passive, functor)

	#include nik_typedef(calculus, typed, deductional, structure)

/*
	at_most:
*/

#define EIGHT 8

	template<size_type N, typename RegType>
	struct at_most
	{
		static constexpr bool value = (N <= size_type(EIGHT) * sizeof(RegType));
	};

#undef EIGHT

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
				is_list_type<bool, Type>,
				typed_list<bool>

			>, else_then
			<
				is_list_type<char, Type>,
				typed_list<char>

			>, else_then
			<
				is_list_type<wchar_t, Type>,
				typed_list<wchar_t>

			>, else_then
			<
				is_list_type<char16_t, Type>,
				typed_list<char16_t>

			>, else_then
			<
				is_list_type<char32_t, Type>,
				typed_list<char32_t>

			>, else_then
			<
				is_list_type<unsigned char, Type>,
				typed_list<unsigned char>

			>, else_then
			<
				is_list_type<unsigned short, Type>,
				typed_list<unsigned short>

			>, else_then
			<
				is_list_type<unsigned int, Type>,
				typed_list<unsigned int>

			>, else_then
			<
				is_list_type<unsigned long, Type>,
				typed_list<unsigned long>

			>, else_then
			<
				is_list_type<unsigned long long, Type>,
				typed_list<unsigned long long>

			>, else_then
			<
				is_list_type<signed char, Type>,
				typed_list<signed char>

			>, else_then
			<
				is_list_type<signed short, Type>,
				typed_list<signed short>

			>, else_then
			<
				is_list_type<signed int, Type>,
				typed_list<signed int>

			>, else_then
			<
				is_list_type<signed long, Type>,
				typed_list<signed long>

			>, else_then
			<
				is_list_type<signed long long, Type>,
				typed_list<signed long long>

			>, then
			<
				other_type
			>

		>::rtn;
	};
};

