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
	These constants are defined in such a way as to be robust against signed and unsigned integer types.

	Some of these computations are defined the way they are to avoid compiler warnings.
*/

struct unit
{
	static constexpr size_type min = limits::min;
	static constexpr size_type max = limits::max;
	
	static constexpr bool is_signed = min;

	static constexpr size_type zero = 0;
	static constexpr size_type one = 1;
	static constexpr size_type two = 2;
	static constexpr size_type three = 3;

	static constexpr size_type nibble = 4;
	static constexpr size_type byte = 8;

	static constexpr size_type length = byte * sizeof(size_type) - 1;
	static constexpr size_type order = length - 1;

	static constexpr size_type tail = (size_type) 2 << order;
	static constexpr size_type head = (size_type) 1 << order;

	struct half
	{
		static constexpr size_type length = unit::length >> 1;
		static constexpr size_type order = unit::order >> 1;

		static constexpr size_type max = ((size_type) 1 << length) - 1;
		static constexpr size_type min = -max - 1;

		static constexpr size_type tail = -(size_type) 2 << order;
		static constexpr size_type head = (size_type) 1 << order;
	};

	struct filter
	{
		static constexpr size_type low_pass = half::max;
		static constexpr size_type high_pass = unit::max & ~low_pass;
	};

	struct overflow
	{
		struct square
		{
			struct odd_square_domain
			{
				template<size_type m>
				struct test
				{
					static constexpr size_type l = m % half::head;
					static constexpr size_type r = half::head - l;

					enum : bool { value = bool(2*l*l < r*r) };
				};
			};

			static constexpr size_type upper = 
				meta::template midpoint<odd_square_domain, half::head, 2*half::head>::value + 1;
			static constexpr size_type lower = -upper;
		};
	};
};

