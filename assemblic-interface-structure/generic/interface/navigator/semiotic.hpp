/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	In the context of this library, copowers are the disjoint union of alternative instances of the same type.
	At the grammaric level, register types and pointers are intended to be indistinguishable.
	Copowers are a grammatical class which represents both.

	When building more complex navigators out of simpler ones,
	the only reasons to reimplement copowers are as follows:

	1. Optimizing the method interface.
	2. Optimization by unraveling. This is necessary if the context
	   requires frequently moving between levels of navigational complexity.
*/

/*
	copower<RegType>	~:= RegType

	Within this initial specialization, RegType is arbitrary but intended for builtin register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	It is optimized as such. Finally, as a copower is otherwise meant to be a pointer,
	when taking in a reference it acts as a reference, meaning it only acts on external objects.
*/

template
<
	typename RegType,
	Access access = Access::readwrite

> struct copower
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<RegType, Access::readonly>;

	using value_type	= typename read_type<RegType, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type & focus;

		// type:

	copower() { }

	copower(value_type & f) : focus(f) { }

	copower(const type & c) : focus(c.focus) { }

	const type & operator = (const type & c)
	{
		focus = c.focus;
	}

	~copower() { }

	bool operator == (const type & c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type & c) const
	{
		return focus != c.focus;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	value_type_ref operator * () const
	{
		return focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}
};

/*
	Beyond register sizes, copowers are intended to be used as an alternative to pointers:

	copower<RegType>		~:= RegType*

	We optimize in our ability to dereference more directly.
*/

template
<
	typename RegType,
	Access access

> struct copower
<
	RegType*,
	access
>
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<RegType*, Access::readonly>;

	using value_type	= typename read_type<RegType, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type_ptr focus;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type & c) : focus(c.focus) { }

	const type & operator = (const type & c)
	{
		focus = c.focus;
	}

	~copower() { }

	bool operator == (const type & c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type & c) const
	{
		return focus != c.focus;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	value_type & operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type & c) const
	{
		return focus - c.focus;
	}
};

/*
	I haven't decided if I want to specialize for copowers of copowers.

	At the very least, copowers are intended to be the iterators of powers:
*/

template
<
	typename Type,
	size_type length,

	Access access

> struct copower
<
	power<Type, length>,
	access
>
{
	using type		= copower<power<Type, length>, access>;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<power<Type, length>, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type_ptr focus;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type & c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type & c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type & c) const
	{
		return focus != c.focus;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type & c) const
	{
		return focus - c.focus;
	}
};

