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

#define define_word(int_length, int_type)										\
															\
template<typename Filler>												\
struct word<bit<boolean>, (int_length), Filler>										\
{															\
	using type		= word;											\
	using type_ref		= type&;										\
	using type_ptr		= type*;										\
															\
	using iterator		= word_navigator<bit<boolean>, (int_length)>;						\
	using const_iterator	= word_navigator<bit<boolean>, (int_length), Access::readonly>;				\
															\
	using byte_type		= int_type;										\
															\
	byte_type product;												\
															\
	word() { }													\
															\
	~word() { }													\
															\
	iterator begin()												\
	{														\
		return iterator(1, product);										\
	}														\
															\
	iterator end()													\
	{														\
		return iterator(1 << (int_length), product);								\
	}														\
};															\


define_word(8 << 0, unsigned char)
define_word(8 << 1, unsigned short)
define_word(8 << 2, unsigned int)
define_word(8 << 3, unsigned long)


#undef define_word

