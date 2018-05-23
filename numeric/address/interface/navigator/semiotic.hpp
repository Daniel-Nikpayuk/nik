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

/*
	Design specifications privilege modularization. Only in specializations do we unpack and optimize.
*/

enum struct Depth : size_type
{
	bit,
	word,
	address,

	dimension
};

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
	template<class, size_type> typename Word,

	size_type length,
	template<class, size_type> typename Address,

	Access access

> struct coaddress
<
	Address<Word<BitType, word_length>, length>,
	access
>
{
	using type				= coaddress;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= coaddress<Address<Word<BitType, word_length>, length>, Access::readonly>;

	using bit_type				= typename read_type<BitType, access>::rtn;
	using bit_type_ref			= bit_type&;
	using bit_type_ptr			= bit_type*;

	using word_type				= Word<bit_type, word_length>;
	using word_type_ref			= word_type&;
	using word_type_ptr			= word_type*;

	using address_type			= Address<word_type, length>;
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

