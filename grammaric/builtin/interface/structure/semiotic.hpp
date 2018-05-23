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

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned long
	8 << 3, unsigned long long

	This code has been tested for GCC.
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
	using rtn					= unsigned char;

							// half implementation does not exist.

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, zero::value>;
	using max					= constant<rtn, (rtn) UCHAR_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<rtn, byte::value * sizeof(rtn)>;
	using order					= constant<rtn, length::value - one::value>;

	using tail					= constant<rtn, zero::value>;
	using head					= constant<rtn, one::value << order::value>;
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
	using rtn					= signed char;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, (rtn) SCHAR_MIN>;
	using max					= constant<rtn, (rtn) SCHAR_MAX>;

	// not yet implemented!
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
	using rtn					= unsigned short;

							// constants are size_type for builtin.

	using half					= builtin<Byte::value << Zero::value, Sign::natural>;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, zero::value>;
	using max					= constant<rtn, (rtn) USHRT_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<rtn, byte::value * sizeof(rtn)>;
	using order					= constant<rtn, length::value - one::value>;

	using tail					= constant<rtn, zero::value>;
	using head					= constant<rtn, one::value << order::value>;

	using low_pass					= constant<rtn, half::max::value>;
	using high_pass					= constant<rtn, max::value & ~low_pass::value>;

	using upper					= constant<rtn, half::max::value + one::value>;
	using lower					= constant<rtn, max::value>;
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
	using rtn					= signed short;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, (rtn) SHRT_MIN>;
	using max					= constant<rtn, (rtn) SHRT_MAX>;

	// not yet implemented!
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
	using rtn					= unsigned int;

							// constants are size_type for builtin.

	using half					= builtin<Byte::value << One::value, Sign::natural>;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, zero::value>;
	using max					= constant<rtn, (rtn) UINT_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<rtn, byte::value * sizeof(rtn)>;
	using order					= constant<rtn, length::value - one::value>;

	using tail					= constant<rtn, zero::value>;
	using head					= constant<rtn, one::value << order::value>;

	using low_pass					= constant<rtn, half::max::value>;
	using high_pass					= constant<rtn, max::value & ~low_pass::value>;

	using upper					= constant<rtn, half::max::value + one::value>;
	using lower					= constant<rtn, max::value>;
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
	using rtn					= signed long;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, (rtn) INT_MIN>;
	using max					= constant<rtn, (rtn) INT_MAX>;

	// not yet implemented!
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
	using rtn					= unsigned long;

							// constants are size_type for builtin.

	using half					= builtin<Byte::value << Two::value, Sign::natural>;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, zero::value>;
	using max					= constant<rtn, (rtn) ULONG_MAX>;

	using is_natural				= constant<bool, !min::value>;

	using length					= constant<rtn, byte::value * sizeof(rtn)>;
	using order					= constant<rtn, length::value - one::value>;

	using tail					= constant<rtn, zero::value>;
	using head					= constant<rtn, one::value << order::value>;

	using low_pass					= constant<rtn, half::max::value>;
	using high_pass					= constant<rtn, max::value & ~low_pass::value>;

	using upper					= constant<rtn, half::max::value + one::value>;
	using lower					= constant<rtn, max::value>;
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
	using rtn					= signed long;

	//

	using zero					= typename grammaric<Module::constant, Permission::semiotic, rtn>::zero;
	using one					= typename grammaric<Module::constant, Permission::semiotic, rtn>::one;

	using byte					= typename grammaric<Module::constant, Permission::semiotic, rtn>::byte;

	//

	using min					= constant<rtn, (rtn) LONG_MIN>;
	using max					= constant<rtn, (rtn) LONG_MAX>;

	// not yet implemented!
};

/*
*/

		  template<size_type N, Sign sign = Sign::natural>
using byte_type = builtin<N, sign>;

