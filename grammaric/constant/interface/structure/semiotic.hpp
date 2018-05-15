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

template<typename Type, Type...> struct constant;

template<typename Type>
struct constant<Type>
{
	using type				= constant;

	using value_type			= Type;
};

template<typename Type, Type Value>
struct constant<Type, Value>
{
	using type				= constant;

	using value_type			= Type;

	static constexpr value_type value	= Value;
};

template<bool Value>
using boolean = constant<bool, Value>;

/*
	We include here a list of commonly used literal constants:
*/

//using min					= constant<size_type, limits::min>;
//using max					= constant<size_type, limits::max>;

//using is_unsigned				= constant<bool, !min>;

using zero					= constant<size_type, 0>;
using one					= constant<size_type, 1>;
using two					= constant<size_type, 2>;
using three					= constant<size_type, 3>;

using nibble					= constant<size_type, 4>;
using byte					= constant<size_type, 8>;

using length					= constant<size_type, byte * sizeof(size_type)>;
using order					= constant<size_type, length - 1>;

using tail					= constant<size_type, 0>;
using head					= constant<size_type, (size_type) 1 << order>;

struct half
{
	using length				= constant<size_type, space::length >> 1>;
	using order				= constant<size_type, space::order >> 1>;

	using max				= constant<size_type, ((size_type) 1 << length) - 1>;
	using min				= constant<size_type, -max - 1>;

	using tail				= constant<size_type, 0>;
	using head				= constant<size_type, (size_type) 1 << order>;
};

struct filter
{
	using low_pass				= constant<size_type, half::max>;
//	using high_pass				= constant<size_type, space::max & ~low_pass>;
};

struct overflow
{
	struct square
	{
		using upper			= constant<size_type, half::max + 1>;
//		using lower			= constant<size_type, space::max>;
	};
};

