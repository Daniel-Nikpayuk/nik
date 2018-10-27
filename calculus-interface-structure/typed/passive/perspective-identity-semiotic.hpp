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

	#include nik_typedef(calculus, perspective, typed, identity)
	#include nik_typedef(calculus, kernel, passive, functor)
	#include nik_typedef(calculus, untyped, conditional, structure)

	#include nik_typedef(calculus, typed, passive, structure)

/*
	is_list:
*/

	template<typename Exp0, typename Exp1>
	struct is_list
	{
		static constexpr bool value = pertyi_is_list
		<
			typename typpaf_evaluate<Exp0>::rtn,
			typename typpaf_evaluate<Exp1>::rtn

		>::value;
	};

/*
	is_null:
*/

	template<typename Exp0, typename Exp1>
	struct is_null
	{
		static constexpr bool value = pertyi_is_null
		<
			typename typpaf_evaluate<Exp0>::rtn,
			typename typpaf_evaluate<Exp1>::rtn

		>::value;
	};

/*
	identify:
*/

	template<typename Exp>
	struct identify
	{
		using Type = typename evaluate<Exp>::rtn;

		using rtn = typename untpaf_evaluate
		<
			if_then
			<
				pertyf_is_list<bool, Type>,
				typed_list<bool>

			>, else_then
			<
				pertyf_is_list<char, Type>,
				typed_list<char>

			>, else_then
			<
				pertyf_is_list<char, Type>,
				typed_list<wchar_t>

			>, else_then
			<
				pertyf_is_list<char, Type>,
				typed_list<char16_t>

			>, else_then
			<
				pertyf_is_list<char, Type>,
				typed_list<char32_t>

			>, else_then
			<
				pertyf_is_list<unsigned char, Type>,
				typed_list<unsigned char>

			>, else_then
			<
				pertyf_is_list<unsigned short, Type>,
				typed_list<unsigned short>

			>, else_then
			<
				pertyf_is_list<unsigned int, Type>,
				typed_list<unsigned int>

			>, else_then
			<
				pertyf_is_list<unsigned long, Type>,
				typed_list<unsigned long>

			>, else_then
			<
				pertyf_is_list<unsigned long long, Type>,
				typed_list<unsigned long long>

			>, else_then
			<
				pertyf_is_list<signed char, Type>,
				typed_list<signed char>

			>, else_then
			<
				pertyf_is_list<signed short, Type>,
				typed_list<signed short>

			>, else_then
			<
				pertyf_is_list<signed int, Type>,
				typed_list<signed int>

			>, else_then
			<
				pertyf_is_list<signed long, Type>,
				typed_list<signed long>

			>, else_then
			<
				pertyf_is_list<signed long long, Type>,
				typed_list<signed long long>

			>, then
			<
				other_type
			>

		>::rtn;
	};
};

