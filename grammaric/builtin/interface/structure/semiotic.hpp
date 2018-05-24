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

#include"limits/semiotic.hpp"

enum struct Sign : size_type
{
	natural,
	integer,

	dimension // filler
};

/*
*/

template<typename RegType>
struct builtin
{
	using reg_type					= RegType;

	//

	using zero					= typename Constant::template zero<reg_type>;
	using one					= typename Constant::template one<reg_type>;

	using byte					= typename Constant::template byte<reg_type>;

	//

	using min					= constant<reg_type, limits<reg_type>::min>;
	using max					= constant<reg_type, limits<reg_type>::max>;

	using length					= constant<reg_type, byte::value * sizeof(reg_type)>;
	using sign					= constant<Sign, !min::value ? Sign::natural : Sign::integer>;
};

/*
*/

template
<
	size_type N,
	Sign sign = Sign::natural

> struct byte_type;

/*
	unsigned:
*/

template
<
	size_type N

> struct byte_type
<
	N,
	Sign::natural
>
{
	using builtin_type				= typename if_then
							<
								builtin<unsigned char>::length::value == N, unsigned char,

							>::rtn;

	using reg_type					= typename builtin_type::reg_type;
	using half_type					= byte_type<(N >> One::value), Sign::natural>;

	//

	using zero					= typename builtin_type::zero;
	using one					= typename builtin_type::one;

	using byte					= typename builtin_type::byte;

	//

	using min					= typename builtin_type::min;
	using max					= typename builtin_type::max;

	using length					= typename builtin_type::length;
	using sign					= typename builtin_type::sign;

	//

	using order					= constant<reg_type, length::value - one::value>;

	using tail					= constant<reg_type, zero::value>;
	using head					= constant<reg_type, one::value << order::value>;

	using low_pass					= constant<reg_type, half_type::max>;
	using high_pass					= constant<reg_type, max::value & ~low_pass::value>;

	using upper					= constant<reg_type, half_type::max + one::value>;
	using lower					= constant<reg_type, max::value>;
};

