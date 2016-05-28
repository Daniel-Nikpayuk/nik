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

static constexpr size_type zero = 0;
static constexpr size_type one = 1;
static constexpr size_type two = 2;
static constexpr size_type three = 3;

static constexpr size_type nibble = 4;
static constexpr size_type byte = 8;

static constexpr size_type length = byte * sizeof(size_type) - bool(media::min);
static constexpr size_type order = length - 1;

static constexpr size_type tail = media::min ? (size_type) 2 << order : 0;
static constexpr size_type head = (size_type) 1 << order;

struct half
{
	static constexpr size_type min = media::min >> 1;
	static constexpr size_type max = media::max >> 1;

	static constexpr size_type length = media::length >> 1;
	static constexpr size_type order = media::order >> 1;

	static constexpr size_type tail = media::tail >> 1;
	static constexpr size_type head = media::head >> 1;
};

struct filter
{
	static constexpr size_type low_pass = ((size_type) 1 << half::length) - 1;
	static constexpr size_type high_pass = max & ~low_pass;
};

