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

/*
	These constants are defined in such a way as to be robust against signed and unsigned integer types.

	Some of these computations are defined the way they are to avoid compiler warnings.
*/

static constexpr bool is_unsigned = !semiotic::min;

static constexpr size_type zero = 0;
static constexpr size_type one = 1;
static constexpr size_type two = 2;
static constexpr size_type three = 3;

static constexpr size_type nibble = 4;
static constexpr size_type byte = 8;

static constexpr size_type length = byte * sizeof(size_type) - bool(semiotic::min);
static constexpr size_type order = length - 1;

static constexpr size_type tail = is_unsigned ? 0 : (size_type) 2 << order;
static constexpr size_type head = (size_type) 1 << order;

struct half
{
	static constexpr size_type length = semiotic::length >> 1;
	static constexpr size_type order = semiotic::order >> 1;

	static constexpr size_type max = ((size_type) 1 << length) - 1;
	static constexpr size_type min = -max - 1;

	static constexpr size_type tail = is_unsigned ? 0 : (size_type) 2 << order;
	static constexpr size_type head = (size_type) 1 << order;
};

struct filter
{
	static constexpr size_type low_pass = half::max;
	static constexpr size_type high_pass = max & ~low_pass;
};

struct square
{
	class odd_max
	{
		static constexpr size_type p0 = (size_type) 1 << (length-1 >> 1);
		static constexpr size_type p1 = (size_type) 1 << (length-5 >> 1);
		static constexpr size_type p2 = (size_type) 1 << (length+3 >> 1);

		public: enum : size_type { value = p0 + p1 + p2/25 + bool(25 <= 2*p2%25) };
	};

	static constexpr size_type max = is_unsigned ? half::max : odd_max::value;
	static constexpr size_type min = is_unsigned ? 0 : -max;
};

