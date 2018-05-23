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
	Sign sign = natural,
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
	using rtn = signed char;
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
	using rtn = signed short;
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
	using rtn = unsigned int;
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
	using rtn = signed int;
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
	using rtn = unsigned long;

	using is_unsigned				= constant<bool, !min>;

	using min					= constant<size_type, limits::min>;
	using max					= constant<size_type, limits::max>;

	using length					= constant<size_type, byte::value * sizeof(size_type)>;
	using order					= constant<size_type, length::value - 1>;

	using tail					= constant<size_type, 0>;
	using head					= constant<size_type, (size_type) 1 << order::value>;

	struct half
	{
		using length				= constant<size_type, (space::length::value >> 1)>;
		using order				= constant<size_type, (space::order::value >> 1)>;

		using max				= constant<size_type, ((size_type) 1 << length::value) - 1>;
		using min				= constant<size_type, -max::value - 1>;

		using tail				= constant<size_type, 0>;
		using head				= constant<size_type, (size_type) 1 << order::value>;
	};

	struct filter
	{
		using low_pass				= constant<size_type, half::max::value>;
		using high_pass				= constant<size_type, space::max & ~low_pass>;
	};

	struct overflow
	{
		struct square
		{
			using upper			= constant<size_type, half::max::value + 1>;
			using lower			= constant<size_type, space::max>;
		};
	};
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
	using rtn = signed long;
};

/*
*/

		  template<size_type N, Sign sign = Sign::natural>
using byte_type = builtin<N, sign>;

