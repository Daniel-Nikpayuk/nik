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

using zero					= constant<size_type, 0>;
using one					= constant<size_type, 1>;
using two					= constant<size_type, 2>;
using three					= constant<size_type, 3>;

using nibble					= constant<size_type, 4>;
using byte					= constant<size_type, 8>;

