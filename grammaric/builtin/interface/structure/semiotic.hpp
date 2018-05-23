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
	bit info taken from:	https://en.wikipedia.org/wiki/C_data_types
	limit info taken from:	http://en.cppreference.com/w/cpp/types/numeric_limits

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned long
	8 << 3, unsigned long long
*/

enum struct Sign : size_type
{
	natural,
	integer,

	dimension // filler
};

template
<
	size_type N,
	Sign sign = Sign::natural,
	typename Filler = void

> struct builtin;

/*
	8 << 0
*/

template
<
	typename Filler

> struct builtin
<
	Byte::value << Zero::value, // 8
	Sign::natural,
	Filler
>
{
	using rtn = unsigned char;

	using min					= constant<size_type, Zero::value>;
	using max					= constant<size_type, (size_type) UCHAR_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<size_type, Byte::value * sizeof(rtn)>;
	using order					= constant<size_type, length::value - One::value>;

	using tail					= constant<size_type, Zero::value>;
	using head					= constant<size_type, One::value << order::value>;

	// half implementation does not exist.
};

template
<
	typename Filler

> struct builtin
<
	Byte::value << Zero::value, // 8
	Sign::integer,
	Filler
>
{
	// not properly implemented yet! Notably, size_type is unsigned which invalidates minimum values.

	using rtn = signed char;

	using min					= constant<size_type, (size_type) SCHAR_MIN>;
	using max					= constant<size_type, (size_type) SCHAR_MAX>;
};

/*
	8 << 1
*/

template
<
	typename Filler

> struct builtin
<
	Byte::value << One::value, // 16
	Sign::natural,
	Filler
>
{
	using rtn = unsigned short;

	using min					= constant<size_type, Zero::value>;
	using max					= constant<size_type, (size_type) USHRT_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<size_type, Byte::value * sizeof(rtn)>;
	using order					= constant<size_type, length::value - One::value>;

	using tail					= constant<size_type, Zero::value>;
	using head					= constant<size_type, One::value << order::value>;

	using half					= builtin<Byte::value << Zero::value, Sign::natural>;

	using low_pass					= constant<size_type, half::max::value>;
	using high_pass					= constant<size_type, max::value & ~low_pass::value>;

	using upper					= constant<size_type, half::max::value + One::value>;
	using lower					= constant<size_type, max::value>;
};

template
<
	typename Filler

> struct builtin
<
	Byte::value << One::value, // 16
	Sign::integer,
	Filler
>
{
	// not properly implemented yet! Notably, size_type is unsigned which invalidates minimum values.

	using rtn = signed short;

	using min					= constant<size_type, (size_type) SHRT_MIN>;
	using max					= constant<size_type, (size_type) SHRT_MAX>;
};

/*
	8 << 2
*/

template
<
	typename Filler

> struct builtin
<
	Byte::value << Two::value, // 32
	Sign::natural,
	Filler
>
{
	using rtn = unsigned long;

	using min					= constant<size_type, Zero::value>;
	using max					= constant<size_type, (size_type) ULONG_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<size_type, Byte::value * sizeof(rtn)>;
	using order					= constant<size_type, length::value - One::value>;

	using tail					= constant<size_type, Zero::value>;
	using head					= constant<size_type, One::value << order::value>;

	using half					= builtin<Byte::value << One::value, Sign::natural>;

	using low_pass					= constant<size_type, half::max::value>;
	using high_pass					= constant<size_type, max::value & ~low_pass::value>;

	using upper					= constant<size_type, half::max::value + One::value>;
	using lower					= constant<size_type, max::value>;
};

template
<
	typename Filler

> struct builtin
<
	Byte::value << Two::value, // 32
	Sign::integer,
	Filler
>
{
	// not properly implemented yet! Notably, size_type is unsigned which invalidates minimum values.

	using rtn = signed long;

	using min					= constant<size_type, (size_type) LONG_MIN>;
	using max					= constant<size_type, (size_type) LONG_MAX>;
};

/*
	8 << 3
*/

template
<
	typename Filler

> struct builtin
<
	Byte::value << Three::value, // 64
	Sign::natural,
	Filler
>
{
	using rtn = unsigned long long;

	using min					= constant<size_type, Zero::value>;
	using max					= constant<size_type, (size_type) ULLONG_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<size_type, Byte::value * sizeof(rtn)>;
	using order					= constant<size_type, length::value - One::value>;

	using tail					= constant<size_type, Zero::value>;
	using head					= constant<size_type, One::value << order::value>;

	using half					= builtin<Byte::value << Two::value, Sign::natural>;

	using low_pass					= constant<size_type, half::max::value>;
	using high_pass					= constant<size_type, max::value & ~low_pass::value>;

	using upper					= constant<size_type, half::max::value + One::value>;
	using lower					= constant<size_type, max::value>;
};

template
<
	typename Filler

> struct builtin
<
	Byte::value << Three::value, // 64
	Sign::integer,
	Filler
>
{
	// not properly implemented yet! Notably, size_type is unsigned which invalidates minimum values.

	using rtn = signed long long;

	using min					= constant<size_type, (size_type) LLONG_MIN>;
	using max					= constant<size_type, (size_type) LLONG_MAX>;
};

/*
*/

		  template<size_type N, Sign sign = Sign::natural>
using byte_type = builtin<N, sign>;

