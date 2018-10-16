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

enum struct Sign : global_size_type
{
	natural,
	integer,

	dimension // filler
};

/***********************************************************************************************************************/

template<typename RegType, typename Filler = void> struct sign;

/*
	unsigned:
*/

template<typename Filler>
struct sign<unsigned char, Filler>
{
	static constexpr Sign value		= Sign::natural;
};

template<typename Filler>
struct sign<unsigned short, Filler>
{
	static constexpr Sign value		= Sign::natural;
};

template<typename Filler>
struct sign<unsigned int, Filler>
{
	static constexpr Sign value		= Sign::natural;
};

template<typename Filler>
struct sign<unsigned long, Filler>
{
	static constexpr Sign value		= Sign::natural;
};

template<typename Filler>
struct sign<unsigned long long, Filler>
{
	static constexpr Sign value		= Sign::natural;
};

/*
	signed:
*/

template<typename Filler>
struct sign<signed char, Filler>
{
	static constexpr Sign value		= Sign::integer;
};

template<typename Filler>
struct sign<signed short, Filler>
{
	static constexpr Sign value		= Sign::integer;
};

template<typename Filler>
struct sign<signed int, Filler>
{
	static constexpr Sign value		= Sign::integer;
};

template<typename Filler>
struct sign<signed long, Filler>
{
	static constexpr Sign value		= Sign::integer;
};

template<typename Filler>
struct sign<signed long long, Filler>
{
	static constexpr Sign value		= Sign::integer;
};

