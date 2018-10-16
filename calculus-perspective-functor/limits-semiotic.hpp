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

/***********************************************************************************************************************/

template<typename RegType, typename SizeType = global_size_type> struct limits;

/*
	unsigned:
*/

	// char:

template<typename SizeType>
struct limits<unsigned char, SizeType>
{
	using reg_type					= unsigned char;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) 0;
	static constexpr size_type max			= (size_type) UCHAR_MAX;
};

	// short:

template<typename SizeType>
struct limits<unsigned short, SizeType>
{
	using reg_type					= unsigned short;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) 0;
	static constexpr size_type max			= (size_type) USHRT_MAX;
};

	// int:

template<typename SizeType>
struct limits<unsigned int, SizeType>
{
	using reg_type					= unsigned int;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) 0;
	static constexpr size_type max			= (size_type) UINT_MAX;
};

	// long:

template<typename SizeType>
struct limits<unsigned long, SizeType>
{
	using reg_type					= unsigned long;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) 0;
	static constexpr size_type max			= (size_type) ULONG_MAX;
};

	// long long:

template<typename SizeType>
struct limits<unsigned long long, SizeType>
{
	using reg_type					= unsigned long long;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) 0;
	static constexpr size_type max			= (size_type) ULLONG_MAX;
};

/*
	signed:
*/

	// char:

template<typename SizeType>
struct limits<signed char, SizeType>
{
	using reg_type					= signed char;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) SCHAR_MIN;
	static constexpr size_type max			= (size_type) SCHAR_MAX;
};

	// short:

template<typename SizeType>
struct limits<signed short, SizeType>
{
	using reg_type					= signed short;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) SHRT_MIN;
	static constexpr size_type max			= (size_type) SHRT_MAX;
};

	// int:

template<typename SizeType>
struct limits<signed int, SizeType>
{
	using reg_type					= signed int;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) INT_MIN;
	static constexpr size_type max			= (size_type) INT_MAX;
};

	// long:

template<typename SizeType>
struct limits<signed long, SizeType>
{
	using reg_type					= signed long;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) LONG_MIN;
	static constexpr size_type max			= (size_type) LONG_MAX;
};

	// long long:

template<typename SizeType>
struct limits<signed long long, SizeType>
{
	using reg_type					= signed long long;

	using size_type					= SizeType;

	static constexpr size_type min			= (size_type) LLONG_MIN;
	static constexpr size_type max			= (size_type) LLONG_MAX;
};

