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

#define ONE_BYTE	8 << 0
#define TWO_BYTES	8 << 1
#define FOUR_BYTES	8 << 2
#define EIGHT_BYTES	8 << 3

#define ONE_BYTE_TYPE		unsigned char
#define TWO_BYTES_TYPE		unsigned short
#define FOUR_BYTES_TYPE		unsigned int
#define EIGHT_BYTES_TYPE	unsigned long

template<typename Filler>
struct identity<word<bit<boolean>, ONE_BYTES, Filler>>
{
	typedef identity type;
	typedef type* type_ptr;
	typedef type& type_ref;

	typedef word<bit<boolean>, ONE_BYTES, Filler> word_type;
	typedef word_type* word_type_ptr;
	typedef word_type& word_type_ref;

	typedef bit<boolean> bit_type;
	typedef bit_type* bit_type_ptr;
	typedef bit_type& bit_type_ref;

	typedef typename bit_type::binary_type binary_type;
	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;


	// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		return (u.bit_array == v.bit_array);
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		return (u.bit_array != v.bit_array);
	}
};

#undef ONE_BYTE
#undef TWO_BYTES
#undef FOUR_BYTES
#undef EIGHT_BYTES

#undef ONE_BYTE_TYPE
#undef TWO_BYTES_TYPE
#undef FOUR_BYTES_TYPE
#undef EIGHT_BYTES_TYPE

