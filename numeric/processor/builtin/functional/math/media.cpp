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

/*
	Terms:

	max=unit::semiotic::square::max

	Constraints:

	{ x < -max, -max <= x <= max, x > max }

	Dispatch:

	[2]	(x < max || x > max)	->	0
	[1]	(-max <= x <= max)	->	square
*/

template<size_type x>
class square
{
	static constexpr size_type sx = x < -unit::semiotic::square::max
					|| x > unit::semiotic::square::max ? 0 : x;

	public: enum : size_type
	{
		value = x < -unit::semiotic::square::max
				|| x > unit::semiotic::square::max ? 0 :
			x*x
	};
};

/*
	Incomplete dispatch analysis.
*/

template<size_type base, size_type exponent>
class exp
{
	static constexpr size_type sbase=(base == 1) ? 0 : base;
	static constexpr size_type sexponent=(exponent == 0) ? 0 : exponent;

	public: enum : size_type
	{
		value = base == 1 || !exponent ? 1
			: semiotic::template exp<sbase, sexponent>::value
	};
};

