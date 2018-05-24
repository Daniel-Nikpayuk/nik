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

template
<
	typename WordType,
	Access access = Access::readwrite

> struct coword;

/*
	Navigators may be optimized in their methods as they have limited perspectives.
*/

template
<
	typename BitType,
	size_type length,

	Access access

> struct coword
<
	word<BitType, length>,
	access
>
{
	using type				= coword;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= coword<word<BitType, length>, Access::readonly>;

	using bit_type				= typename read_type<BitType, access>::rtn;
	using bit_type_ref			= bit_type&;
	using bit_type_ptr			= bit_type*;

	using word_type				= word<bit_type, length>;
	using word_type_ref			= word_type&;
	using word_type_ptr			= word_type*;

	using bit_iterator			= typename BitType::iterator;
	using const_bit_iterator		= typename BitType::const_iterator;

	using word_iterator			= typename word<BitType, length>::iterator;
	using const_word_iterator		= typename word<BitType, length>::const_iterator;

	Depth depth;

	word_iterator word_focus;
	bit_iterator bit_focus;

		// type:

	coword(power<bit_type, length> & l) : depth(Depth::word), word_focus(l.value) { }

	~coword() { }

	bool operator == (const type & c) const
	{
		if (depth == Depth::word)	return word_focus == c.word_focus;
		else				return bit_focus == c.bit_focus;
	}

	bool operator != (const type & c) const
	{
		if (depth == Depth::word)	return word_focus != c.word_focus;
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
		depth = Depth::bit;
	}

	void operator - ()
	{
		depth = Depth::word;
	}

	type_ref operator ++ ()
	{
		if (depth == Depth::word)	++word_focus;
		else				++bit_focus;

		return *this;
	}

	type_ref operator += (size_type n)
	{
		if (depth == Depth::word)	word_focus += n;
		else				bit_focus += n;

		return *this;
	}

	type_ref operator -- ()
	{
		if (depth == Depth::word)	--word_focus;
		else				--bit_focus;

		return *this;
	}

	type_ref operator -= (size_type n)
	{
		if (depth == Depth::word)	word_focus -= n;
		else				bit_focus -= n;

		return *this;
	}
};

