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

static size_type min() { return semiotic::min; }
static size_type max() { return semiotic::max; }

static bool is_unsigned() { return semiotic::is_unsigned; }

static size_type zero() { return semiotic::zero; }
static size_type one() { return semiotic::one; }
static size_type two() { return semiotic::two; }
static size_type three() { return semiotic::three; }

static size_type nibble() { return semiotic::nibble; }
static size_type byte() { return semiotic::byte; }

static size_type length() { return semiotic::length; }
static size_type order() { return semiotic::order; }

static size_type tail() { return semiotic::tail; }
static size_type head() { return semiotic::head; }

struct half
{
	constexpr size_type min() { return semiotic::half::min; }
	constexpr size_type max() { return semiotic::half::max; }

	constexpr size_type length() { return semiotic::half::length; }
	constexpr size_type order() { return semiotic::half::order; }

	constexpr size_type tail() { return semiotic::half::tail; }
	constexpr size_type head() { return semiotic::half::head; }
};

struct filter
{
	constexpr size_type low_pass() { return semiotic::filter::low_pass; }
	constexpr size_type high_pass() { return semiotic::filter::high_pass; }
};

