/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

#ifndef NIK_NUMERIC_WORD_UINT_FUNCTIONAL_UNIT_LIMITS_H
#define NIK_NUMERIC_WORD_UINT_FUNCTIONAL_UNIT_LIMITS_H

#include<stdint.h>

#include<climits>
#include<cfloat>

/*
	limits: (taken from: http://en.cppreference.com/w/cpp/types/limits)

	char
	signed char
	unsigned char
	wchar_t
	char16_t
	char32_t
	short
		signed short // redundant
	unsigned short
	int
		signed int // redundant
	unsigned int
	long
		signed long // redundant
	unsigned long
	long long
		signed long long // redundant
	unsigned long long
	float
	double
	long double
*/

/*
	default:
*/

template<typename IntType, typename Filler=void>
struct limits
{
	typedef IntType int_type;
};

/*
	specializations:
*/

template<typename Filler>
struct limits<char, Filler>
{
	typedef char int_type;

	static constexpr int_type min=CHAR_MIN;
	static constexpr int_type max=CHAR_MAX;
};

template<typename Filler>
struct limits<signed char, Filler>
{
	typedef signed char int_type;

	static constexpr int_type min=SCHAR_MIN;
	static constexpr int_type max=SCHAR_MAX;
};

template<typename Filler>
struct limits<unsigned char, Filler>
{
	typedef unsigned char int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UCHAR_MAX;
};

template<typename Filler>
struct limits<wchar_t, Filler>
{
	typedef wchar_t int_type;

	static constexpr int_type min=WCHAR_MIN;
	static constexpr int_type max=WCHAR_MAX;
};

template<typename Filler>
struct limits<char16_t, Filler>
{
	typedef char16_t int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UINT_LEAST16_MAX;
};

template<typename Filler>
struct limits<char32_t, Filler>
{
	typedef char32_t int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UINT_LEAST32_MAX;
};

template<typename Filler>
struct limits<short, Filler>
{
	typedef short int_type;

	static constexpr int_type min=SHRT_MIN;
	static constexpr int_type max=SHRT_MAX;
};

//	redundant: template<> struct limits<signed long long>;

template<typename Filler>
struct limits<unsigned short, Filler>
{
	typedef unsigned short int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=USHRT_MAX;
};

template<typename Filler>
struct limits<int, Filler>
{
	typedef int int_type;

	static constexpr int_type min=INT_MIN;
	static constexpr int_type max=INT_MAX;
};

//	redundant: template<> struct limits<signed long long>;

template<typename Filler>
struct limits<unsigned int, Filler>
{
	typedef unsigned int int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UINT_MAX;
};

template<typename Filler>
struct limits<long, Filler>
{
	typedef long int_type;

	static constexpr int_type min=LONG_MIN;
	static constexpr int_type max=LONG_MAX;
};

//	redundant: template<> struct limits<signed long long>;

template<typename Filler>
struct limits<unsigned long, Filler>
{
	typedef unsigned long int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=ULONG_MAX;
};

template<typename Filler>
struct limits<long long, Filler>
{
	typedef long long int_type;

	static constexpr int_type min=LLONG_MIN;
	static constexpr int_type max=LLONG_MAX;
};

//	redundant: template<> struct limits<signed long long>;

template<typename Filler>
struct limits<unsigned long long, Filler>
{
	typedef unsigned long long int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=ULLONG_MAX;
};

template<typename Filler>
struct limits<float, Filler>
{
	typedef float int_type;

	static constexpr int_type min=FLT_MIN;
	static constexpr int_type max=FLT_MAX;
};

template<typename Filler>
struct limits<double, Filler>
{
	typedef double int_type;

	static constexpr int_type min=DBL_MIN;
	static constexpr int_type max=DBL_MAX;
};

template<typename Filler>
struct limits<long double, Filler>
{
	typedef long double int_type;

	static constexpr int_type min=LDBL_MIN;
	static constexpr int_type max=LDBL_MAX;
};

#endif
