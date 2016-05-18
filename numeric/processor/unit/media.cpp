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

static const size_type zero = 0;
static const size_type one = 1;
static const size_type two = 2;
static const size_type three = 3;

static const size_type nibble = 4;
static const size_type byte = 8;

static const size_type length = byte * sizeof(size_type);
static const size_type max_length = length - 1;
static const size_type half_length = length >> 1;

static const size_type size = 0;
static const size_type max_size = size - 1;
static const size_type half_size = 1 << half_length;

static const size_type power = 0;
static const size_type max_power = 1 << max_length;
static const size_type half_power = half_size;

struct half
{
	static const size_type length = unit::half_length;
	static const size_type max_length = length - 1;
	static const size_type half_length = length >> 1;

	static const size_type size = unit::half_size;
	static const size_type max_size = size - 1;
	static const size_type half_size = 1 << half_length;

	static const size_type power = unit::half_power;
	static const size_type max_power = 1 << max_length;
	static const size_type half_power = 1 << half_length;
};

struct filter
{
	static const size_type low_pass = half::max_size;
	static const size_type high_pass = low_pass << half::length;
};

