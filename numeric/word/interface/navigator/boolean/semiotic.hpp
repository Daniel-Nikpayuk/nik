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

#define define_coword(int_length, int_type)										\
															\
template														\
<															\
	template<class, size_type> typename Word,									\
															\
	Access access													\
															\
> struct coword														\
<															\
	Word<bit<bool>, (int_length)>,											\
	access														\
>															\
{															\
	using type				= coword;								\
	using type_ref				= type&;								\
	using type_ptr				= type*;								\
															\
	using const_type			= coword<Word<bit<bool>, (int_length)>, Access::readonly>;		\
															\
	using value_type			= typename read_type<typename Word<bit<bool>, length>::value_type>::rtn;\
	using value_type_ref			= value_type&;								\
	using value_type_ptr			= value_type*;								\
															\
	using bit_iterator			= typename bit<bool>::iterator;						\
	using const_bit_iterator		= typename bit<bool>::const_iterator;					\
															\
	using word_iterator			= typename Word<bit<bool>, length>::iterator;				\
	using const_word_iterator		= typename Word<bit<bool>, length>::const_iterator;			\
															\
	Depth depth;													\
															\
	bit_iterator bit_focus;												\
															\
	word_iterator word_focus;											\
															\
	byte_type location;												\
	byte_type *name;												\
															\
	coword(byte_type l, byte_type & n) : location(l)								\
	{														\
		name = &n;												\
	}														\
															\
	~coword() { }													\
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
		return coword(location<<1, name);									\
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
		return coword(location<<n, name);									\
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
		return coword(location>>1, name);									\
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
		return coword(location>>n, name);									\
	}														\
};															\


define_coword(8 << 0, unsigned char)
define_coword(8 << 1, unsigned short)
define_coword(8 << 2, unsigned long)
define_coword(8 << 3, unsigned long long)


#undef define_coword

