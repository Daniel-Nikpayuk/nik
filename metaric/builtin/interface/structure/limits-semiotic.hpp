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
	limit info taken from:	http://en.cppreference.com/w/cpp/types/numeric_limits

	(un)signed char
	(un)signed short
	(un)signed int
	(un)signed long
	(un)signed long long
*/

/***********************************************************************************************************************/

template<typename RegType, typename Filler = void> struct limits;

/*
	unsigned:
*/

	// char:

template<typename Filler>
struct limits<unsigned char, Filler>
{
	using reg_type					= unsigned char;

	static constexpr reg_type min			= (reg_type) 0;
	static constexpr reg_type max			= (reg_type) UCHAR_MAX;
};

	// short:

template<typename Filler>
struct limits<unsigned short, Filler>
{
	using reg_type					= unsigned short;

	static constexpr reg_type min			= (reg_type) 0;
	static constexpr reg_type max			= (reg_type) USHRT_MAX;
};

	// int:

template<typename Filler>
struct limits<unsigned int, Filler>
{
	using reg_type					= unsigned int;

	static constexpr reg_type min			= (reg_type) 0;
	static constexpr reg_type max			= (reg_type) UINT_MAX;
};

	// long:

template<typename Filler>
struct limits<unsigned long, Filler>
{
	using reg_type					= unsigned long;

	static constexpr reg_type min			= (reg_type) 0;
	static constexpr reg_type max			= (reg_type) ULONG_MAX;
};

	// long long:

template<typename Filler>
struct limits<unsigned long long, Filler>
{
	using reg_type					= unsigned long long;

	static constexpr reg_type min			= (reg_type) 0;
	static constexpr reg_type max			= (reg_type) ULLONG_MAX;
};

/*
	signed:
*/

	// char:

template<typename Filler>
struct limits<signed char, Filler>
{
	using reg_type					= signed char;

	static constexpr reg_type min			= (reg_type) SCHAR_MIN;
	static constexpr reg_type max			= (reg_type) SCHAR_MAX;
};

	// short:

template<typename Filler>
struct limits<signed short, Filler>
{
	using reg_type					= signed short;

	static constexpr reg_type min			= (reg_type) SHRT_MIN;
	static constexpr reg_type max			= (reg_type) SHRT_MAX;
};

	// int:

template<typename Filler>
struct limits<signed int, Filler>
{
	using reg_type					= signed int;

	static constexpr reg_type min			= (reg_type) INT_MIN;
	static constexpr reg_type max			= (reg_type) INT_MAX;
};

	// long:

template<typename Filler>
struct limits<signed long, Filler>
{
	using reg_type					= signed long;

	static constexpr reg_type min			= (reg_type) LONG_MIN;
	static constexpr reg_type max			= (reg_type) LONG_MAX;
};

	// long long:

template<typename Filler>
struct limits<signed long long, Filler>
{
	using reg_type					= signed long long;

	static constexpr reg_type min			= (reg_type) LLONG_MIN;
	static constexpr reg_type max			= (reg_type) LLONG_MAX;
};

