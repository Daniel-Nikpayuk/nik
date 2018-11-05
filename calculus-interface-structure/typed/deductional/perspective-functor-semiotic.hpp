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

#include<climits>

/*
	limit info taken from:	http://en.cppreference.com/w/cpp/types/numeric_limits

	(un)signed char
	(un)signed short
	(un)signed int
	(un)signed long
	(un)signed long long
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, dispatched, identity)
		#include nik_typedef(calculus, perspective, typed, functor)

	#undef safe_name

	#include nik_typedef(calculus, untyped, passive, functor)

	#include nik_typedef(calculus, typed, deductional, structure)
	#include nik_typedef(calculus, typed, deductional, identity)

/*
	min:
*/

	template<typename RegType>
	struct min
	{
		static constexpr size_type value = evaluate
		<
			if_then
			<
				perdii_is_equal<RegType, unsigned char>,
				typed_list<size_type, 0>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned short>,
				typed_list<size_type, 0>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned int>,
				typed_list<size_type, 0>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned long>,
				typed_list<size_type, 0>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned long long>,
				typed_list<size_type, 0>

			>, else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SCHAR_MIN)>

			>, else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SHRT_MIN)>

			>, else_then
			<
				perdii_is_equal<RegType, signed int>,
				typed_list<size_type, size_type(INT_MIN)>

			>, else_then
			<
				perdii_is_equal<RegType, signed long>,
				typed_list<size_type, size_type(LONG_MIN)>

			>, else_then
			<
				perdii_is_equal<RegType, signed long long>,
				typed_list<size_type, size_type(LLONG_MIN)>

			>, then
			<
				typed_list<size_type, 0>
			>

		>::rtn::value;
	};

/*
	max:
*/

	template<typename RegType>
	struct max
	{
		static constexpr size_type value = evaluate
		<
			if_then
			<
				perdii_is_equal<RegType, unsigned char>,
				typed_list<size_type, size_type(UCHAR_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned short>,
				typed_list<size_type, size_type(USHRT_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned int>,
				typed_list<size_type, size_type(UINT_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned long>,
				typed_list<size_type, size_type(ULONG_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, unsigned long long>,
				typed_list<size_type, size_type(ULLONG_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SCHAR_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SHRT_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, signed int>,
				typed_list<size_type, size_type(INT_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, signed long>,
				typed_list<size_type, size_type(LONG_MAX)>

			>, else_then
			<
				perdii_is_equal<RegType, signed long long>,
				typed_list<size_type, size_type(LLONG_MAX)>

			>, then
			<
				typed_list<size_type, size_type(SCHAR_MAX)>
			>

		>::rtn::value;
	};

/*
	unsigned_type:
*/

	template<size_type N>
	struct unsigned_type
	{
		using rtn = typename evaluate
		<
			if_then
			<
				at_most<N, unsigned char>,
				unsigned char

			>, else_then
			<
				at_most<N, unsigned short>,
				unsigned short

			>, else_then
			<
				at_most<N, unsigned int>,
				unsigned int

			>, else_then
			<
				at_most<N, unsigned long>,
				unsigned long

			>, then
			<
//				at_most<N, unsigned long long>,
				unsigned long long
			>

		>::rtn;
	};

/*
	signed_type:
*/

	template<size_type N>
	struct signed_type
	{
		using rtn = typename evaluate
		<
			if_then
			<
				at_most<N, unsigned char>,
				signed char

			>, else_then
			<
				at_most<N, unsigned short>,
				signed short

			>, else_then
			<
				at_most<N, unsigned int>,
				signed int

			>, else_then
			<
				at_most<N, unsigned long>,
				signed long

			>, then
			<
//				at_most<N, unsigned long long>,
				signed long long
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.

	This can be rewritten using C++20 string literal parameters.
*/

	inline static void display(const typed_list<bool> &)
	{
		Dispatched::functor::display("typed list: bool");
	}

	inline static void display(const typed_list<char> &)
	{
		Dispatched::functor::display("typed list: char");
	}

	inline static void display(const typed_list<wchar_t> &)
	{
		Dispatched::functor::display("typed list: wchar_t");
	}

	inline static void display(const typed_list<char16_t> &)
	{
		Dispatched::functor::display("typed list: char16_t");
	}

	inline static void display(const typed_list<char32_t> &)
	{
		Dispatched::functor::display("typed list: char32_t");
	}

	inline static void display(const typed_list<unsigned char> &)
	{
		Dispatched::functor::display("typed list: unsigned char");
	}

	inline static void display(const typed_list<unsigned short> &)
	{
		Dispatched::functor::display("typed list: unsigned short");
	}

	inline static void display(const typed_list<unsigned int> &)
	{
		Dispatched::functor::display("typed list: unsigned int");
	}

	inline static void display(const typed_list<unsigned long> &)
	{
		Dispatched::functor::display("typed list: unsigned long");
	}

	inline static void display(const typed_list<unsigned long long> &)
	{
		Dispatched::functor::display("typed list: unsigned long long");
	}

	inline static void display(const typed_list<signed char> &)
	{
		Dispatched::functor::display("typed list: signed char");
	}

	inline static void display(const typed_list<signed short> &)
	{
		Dispatched::functor::display("typed list: signed short");
	}

	inline static void display(const typed_list<signed int> &)
	{
		Dispatched::functor::display("typed list: signed int");
	}

	inline static void display(const typed_list<signed long> &)
	{
		Dispatched::functor::display("typed list: signed long");
	}

	inline static void display(const typed_list<signed long long> &)
	{
		Dispatched::functor::display("typed list: signed long long");
	}

	inline static void display(const other_type &)
	{
		Dispatched::functor::display("other type");
	}
};

