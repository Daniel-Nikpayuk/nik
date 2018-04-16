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
struct word<bit<boolean>, ONE_BYTE, Filler>
{
	typedef word type;
	typedef type* type_ptr;
	typedef type& type_ref;

	typedef word_navigator<bit<boolean>, ONE_BYTE, Filler> iterator;

	typedef ONE_BYTE_TYPE byte_type;

	byte_type product;

	word() { }

	~word() { }

	iterator begin()
	{
		return iterator(1, product);
	}

	iterator end()
	{
		return iterator(1 << ONE_BYTE, product);
	}
};

template<typename Filler>
struct word<bit<boolean>, TWO_BYTES, Filler>
{
	typedef word type;
	typedef type* type_ptr;
	typedef type& type_ref;

	typedef word_navigator<bit<boolean>, TWO_BYTES, Filler> iterator;

	typedef TWO_BYTES_TYPE byte_type;

	byte_type product;

	word() { }

	~word() { }

	iterator begin()
	{
		return iterator(1, product);
	}

	iterator end()
	{
		return iterator(1 << TWO_BYTES, product);
	}
};

template<typename Filler>
struct word<bit<boolean>, FOUR_BYTES, Filler>
{
	typedef word type;
	typedef type* type_ptr;
	typedef type& type_ref;

	typedef word_navigator<bit<boolean>, FOUR_BYTES, Filler> iterator;

	typedef FOUR_BYTES_TYPE byte_type;

	byte_type product;

	word() { }

	~word() { }

	iterator begin()
	{
		return iterator(1, product);
	}

	iterator end()
	{
		return iterator(1 << FOUR_BYTES, product);
	}
};

template<typename Filler>
struct word<bit<boolean>, EIGHT_BYTES, Filler>
{
	typedef word type;
	typedef type* type_ptr;
	typedef type& type_ref;

	typedef word_navigator<bit<boolean>, EIGHT_BYTES, Filler> iterator;

	typedef EIGHT_BYTES_TYPE byte_type;

	byte_type product;

	word() { }

	~word() { }

	iterator begin()
	{
		return iterator(1, product);
	}

	iterator end()
	{
		return iterator(1 << EIGHT_BYTES, product);
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

