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
	current status: experimental.

	Copower ranges are a convenience class. They allow for greater expressivity when interacting with powers.
	As a convenience class, they are most portable as numeric values, which in application would be used
	to relocate pointers.
*/

template
<
	typename Type,
	Access access = Access::readwrite

> struct copower_range
{
	using type		= copower_range;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower_range<Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type initial;
	value_type terminal;

		// type:

	copower_range() { }

	copower_range(value_type i, value_type t) : initial(i), terminal(t) { }

	~copower_range() { }

	bool operator == (const type & c) const
	{
		return initial == c.initial && terminal == c.terminal;
	}

	bool operator != (const type & c) const
	{
		return initial != c.initial || terminal != c.terminal;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// meta:

	value_type_ref operator + () const
	{
		return terminal;
	}

	value_type_ref operator - () const
	{
		return initial;
	}

		// value:

		// navigator:

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return type(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return type(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return type(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return type(initial - n, terminal - n);
	}
};

