/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

template<size_type x>
struct is_odd
	{ enum : size_type { value=x % 2 }; };

template<size_type x>
struct is_even
	{ enum : size_type { value=!(x % 2) }; };

template<size_type x>
struct is_negative
	{ enum : size_type { value=x < 0 }; };

template<size_type x>
struct is_positive
	{ enum : size_type { value=x > 0 }; };

template<size_type x>
struct abs
	{ enum : size_type { value=(x > 0) ? x : -x }; };

template<size_type x, size_type y>
struct min
	{ enum : size_type { value=(x < y) ? x : y }; };

template<size_type x, size_type y>
struct max
	{ enum : size_type { value=(x > y) ? x : y }; };

template<size_type x>
struct square
	{ enum : size_type { value=x*x }; };

template<size_type base, size_type exponent>
struct exp
{
	static constexpr size_type base1=(base == 1) ? 0 : base;
	static constexpr size_type exponent1=(exponent == 0) ? 0 : exponent;

	enum : size_type
	{
		value = base == 1 || !exponent ? 1
			: semiotic::template exp5<base1, exponent1>::value
	};
};

