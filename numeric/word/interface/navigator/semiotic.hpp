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

enum struct Depth
{
	bit,
	word,

	dimension
};

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
	template<class, size_type> typename Word,

	Access access

> struct coword
<
	Word<BitType, length>,
	access
>
{
	using type				= coword;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= coword<Word<BitType, length>, Access::readonly>;

	using value_type			= typename read_type<typename Word<BitType, length>::value_type>::rtn;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using bit_iterator			= typename BitType::iterator;
	using const_bit_iterator		= typename BitType::const_iterator;

	using word_iterator			= typename Word<BitType, length>::iterator;
	using const_word_iterator		= typename Word<BitType, length>::const_iterator;

	Depth depth;

	bit_iterator bit_focus;

	word_iterator word_focus;

		// type:

	coword(power<BitType, length> & l) : depth(Depth::word), word_focus(l.value) { }

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

	typename BitType::value_type_ref operator * () const
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

