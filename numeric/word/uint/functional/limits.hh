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

/*
	limits: (taken from: http://en.cppreference.com/w/cpp/types/limits)

	unsigned char
	unsigned short
	unsigned int
	unsigned long
	unsigned long long
*/

/*
	default:
*/

template<typename IntType, typename Filler=void>
struct limits
{
	typedef IntType int_type;

	static constexpr int_type min=-1;
	static constexpr int_type max=-1;
};

/*
	specializations:
*/

template<typename Filler>
struct limits<unsigned char, Filler>
{
	typedef unsigned char int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UCHAR_MAX;
};

template<typename Filler>
struct limits<unsigned short, Filler>
{
	typedef unsigned short int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=USHRT_MAX;
};

template<typename Filler>
struct limits<unsigned int, Filler>
{
	typedef unsigned int int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=UINT_MAX;
};

template<typename Filler>
struct limits<unsigned long, Filler>
{
	typedef unsigned long int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=ULONG_MAX;
};

template<typename Filler>
struct limits<unsigned long long, Filler>
{
	typedef unsigned long long int_type;

	static constexpr int_type min=0;
	static constexpr int_type max=ULLONG_MAX;
};

