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

struct unit
{
	static constexpr size_type min() { return semiotic::unit::min; }
	static constexpr size_type max() { return semiotic::unit::max; }

	static constexpr bool is_unsigned() { return semiotic::unit::is_unsigned; }

	static constexpr size_type zero() { return semiotic::unit::zero; }
	static constexpr size_type one() { return semiotic::unit::one; }
	static constexpr size_type two() { return semiotic::unit::two; }
	static constexpr size_type three() { return semiotic::unit::three; }

	static constexpr size_type nibble() { return semiotic::unit::nibble; }
	static constexpr size_type byte() { return semiotic::unit::byte; }

	static constexpr size_type length() { return semiotic::unit::length; }
	static constexpr size_type order() { return semiotic::unit::order; }

	static constexpr size_type tail() { return semiotic::unit::tail; }
	static constexpr size_type head() { return semiotic::unit::head; }

	struct half
	{
		static constexpr size_type min() { return semiotic::unit::half::min; }
		static constexpr size_type max() { return semiotic::unit::half::max; }

		static constexpr size_type length() { return semiotic::unit::half::length; }
		static constexpr size_type order() { return semiotic::unit::half::order; }

		static constexpr size_type tail() { return semiotic::unit::half::tail; }
		static constexpr size_type head() { return semiotic::unit::half::head; }
	};

	struct filter
	{
		static constexpr size_type low_pass() { return semiotic::unit::filter::low_pass; }
		static constexpr size_type high_pass() { return semiotic::unit::filter::high_pass; }
	};

	struct overflow
	{
		struct square
		{
			static constexpr size_type lower() { return semiotic::unit::overflow::square::lower; }
			static constexpr size_type upper() { return semiotic::unit::overflow::square::upper; }
		};
	};
};

