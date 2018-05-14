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

#define define_word_navigator(int_length, int_type)									\
															\
template<Access access>													\
struct word_navigator<bit<boolean>, (int_length), access>								\
{															\
	using type			= word_navigator;								\
	using type_ptr			= type*;									\
	using type_ref			= type&;									\
															\
	using const_type		= word_navigator<bit<boolean>, (int_length), Access::readonly>;			\
															\
	using sub_navigator		= coproduct<Bit, access>;							\
	using sub_navigator_ptr		= sub_navigator*;								\
	using sub_navigator_ref		= sub_navigator&;								\
															\
	using bit_type			= typename read_type<bit<boolean>, access>::rtn;				\
	using bit_type_ptr		= bit_type*;									\
	using bit_type_ref		= bit_type&;									\
															\
	using byte_type			= typename read_type<int_type, access>::rtn;					\
															\
	byte_type location;												\
	byte_type *name;												\
															\
	word_navigator(byte_type l, byte_type & n) : location(l)							\
	{														\
		name = &n;												\
	}														\
															\
	~word_navigator() { }												\
															\
	operator const_type () const											\
	{														\
		return (const_type) this;										\
	}														\
															\
	const bit_type operator * () const										\
	{														\
		return *name & location;										\
	}														\
															\
	void operator + ()												\
	{														\
		*name ^= location;											\
	}														\
															\
	void operator - ()												\
	{														\
		*name &= ~location;											\
	}														\
															\
	type_ref operator ++ ()												\
	{														\
		location<<=1;												\
															\
		return *this;												\
	}														\
															\
	type operator ++ (int)												\
	{														\
		return word_navigator(location<<1, name);								\
	}														\
															\
	type_ref operator += (byte_type n)										\
	{														\
		location<<=n;												\
															\
		return *this;												\
	}														\
															\
	type operator + (byte_type n) const										\
	{														\
		return word_navigator(location<<n, name);								\
	}														\
															\
	type_ref operator -- ()												\
	{														\
		location>>=1;												\
															\
		return *this;												\
	}														\
															\
	type operator -- (int)												\
	{														\
		return word_navigator(location>>1, name);								\
	}														\
															\
	type_ref operator -= (byte_type n)										\
	{														\
		location>>=n;												\
															\
		return *this;												\
	}														\
															\
	type operator - (byte_type n) const										\
	{														\
		return word_navigator(location>>n, name);								\
	}														\
};															\


define_word_navigator(8 << 0, unsigned char)
define_word_navigator(8 << 1, unsigned short)
define_word_navigator(8 << 2, unsigned int)
define_word_navigator(8 << 3, unsigned long)


#undef define_word_navigator

