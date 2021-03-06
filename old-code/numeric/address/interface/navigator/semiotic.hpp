/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Design specifications privilege modularization. Only in specializations do we unpack and optimize.
*/

template
<
	typename AddressType,
	Access access = Access::readwrite

> struct coaddress;

/*
	Navigators may be optimized in their methods as they have limited perspectives.
*/

template
<
	typename BitType, size_type word_length,
	size_type length,
	Access access

> struct coaddress
<
	address<word<BitType, word_length>, length>,
	access
>
{
	using type				= coaddress;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= coaddress<address<word<BitType, word_length>, length>, Access::readonly>;

	using bit_type				= typename read_type<BitType, access>::rtn;
	using bit_type_ref			= bit_type&;
	using bit_type_ptr			= bit_type*;

	using word_type				= word<bit_type, word_length>;
	using word_type_ref			= word_type&;
	using word_type_ptr			= word_type*;

	using address_type			= address<word_type, length>;
	using address_type_ref			= address_type&;
	using address_type_ptr			= address_type*;

	using bit_iterator			= typename bit_type::iterator;
	using const_bit_iterator		= typename bit_type::const_iterator;

	using word_iterator			= typename word_type::iterator;
	using const_word_iterator		= typename word_type::const_iterator;

	using address_iterator			= typename address_type::iterator;
	using const_address_iterator		= typename address_type::const_iterator;

	Depth depth;

	address_iterator address_focus;
	word_iterator word_focus;
	bit_iterator bit_focus;

		// type:

	coaddress(power<word_type, length> & l) : depth(Depth::address), address_focus(l.value) { }

	~coaddress() { }

	bool operator == (const type & c) const
	{
		if (depth == Depth::address)	return address_focus == c.address_focus;
		else if (depth == Depth::word)	return word_focus == c.word_focus;
		else				return bit_focus == c.bit_focus;
	}

	bool operator != (const type & c) const
	{
		if (depth == Depth::address)	return address_focus != c.address_focus;
		else if (depth == Depth::word)	return word_focus != c.word_focus;
		else				return bit_focus != c.bit_focus;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	bit_type_ref operator * () const
	{
		return *bit_focus;
	}

		// navigator:

	void operator + ()
	{
		depth = (depth == Depth::address) ?
			Depth::word :
			Depth::bit;
	}

	void operator - ()
	{
		depth = (depth == Depth::bit) ?
			Depth::word :
			Depth::address;
	}

	type_ref operator ++ ()
	{
		if (depth == Depth::address)	++address_focus;
		else if (depth == Depth::word)	++word_focus;
		else				++bit_focus;

		return *this;
	}

	type_ref operator += (size_type n)
	{
		if (depth == Depth::address)	address_focus += n;
		else if (depth == Depth::word)	word_focus += n;
		else				bit_focus += n;

		return *this;
	}

	type_ref operator -- ()
	{
		if (depth == Depth::address)	--address_focus;
		else if (depth == Depth::word)	--word_focus;
		else				--bit_focus;

		return *this;
	}

	type_ref operator -= (size_type n)
	{
		if (depth == Depth::address)	address_focus -= n;
		else if (depth == Depth::word)	word_focus -= n;
		else				bit_focus -= n;

		return *this;
	}
};


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
define_coword(8 << 2, unsigned int)
define_coword(8 << 3, unsigned long)


#undef define_coword

