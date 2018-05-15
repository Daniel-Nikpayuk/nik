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
	In the context of this library, dicopowers are pairs of disjoint unions of alternative instances of the same type.
	They are intended to represent ranges.

	When building more complex navigators out of simpler ones,
	the only reasons to reimplement dicopowers are as follows:

	1. Optimizing the method interface.
	2. Optimization by unraveling. This is necessary if the context
	   requires frequently moving between levels of navigational complexity.
*/

template<size_type N, typename Type, Access access = Access::readwrite>
struct nested_dicopower
{
	using type		= nested_dicopower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= nested_dicopower<N, Type, Access::readonly>;

	using value_type	= multi_copower<N, Type, access>;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type initial;
	value_type terminal;

		// type:

	nested_dicopower() { }

	nested_dicopower(const value_type_ref i, const value_type_ref t) : initial(i), terminal(t) { }

	~nested_dicopower() { }

	bool operator == (const type_ref c) const
	{
		return initial == c.initial && terminal == c.terminal;
	}

	bool operator != (const type_ref c) const
	{
		return initial != c.initial || terminal != c.terminal;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// meta:

	void operator + ()
	{
		+initial;
		+terminal;
	}

	void operator - ()
	{
		-initial;
		-terminal;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return nested_dicopower(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return nested_dicopower(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return nested_dicopower(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return nested_dicopower(initial - n, terminal - n);
	}
};

/*
	N = 0, we partially specialize two variants:

	1. Non-pointer Types
	2. Pointer Types
*/

template<typename Type, Access access>
struct nested_dicopower<Zero::value, Type, access>
{
	using type		= nested_dicopower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= nested_dicopower<Zero::value, Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type initial;
	value_type terminal;

		// type:

	nested_dicopower() { }

	nested_dicopower(value_type i, value_type t) : initial(i), terminal(t) { }

	~nested_dicopower() { }

	bool operator == (const type_ref c) const
	{
		return initial == c.initial && terminal == c.terminal;
	}

	bool operator != (const type_ref c) const
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

		// navigator:

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return nested_dicopower(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return nested_dicopower(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return nested_dicopower(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return nested_dicopower(initial - n, terminal - n);
	}
};

/*
	Dicopowers are meant as an alternative to pairs of pointers. When instantiated with a pointer as parameter,
	they should be partially specialized to interface directly with their dereferenced value types.
*/

template<typename Type, Access access>
struct nested_dicopower<Zero::value, Type*, access>
{
	using type		= nested_dicopower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= nested_dicopower<Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type_ptr initial;
	value_type_ptr terminal;

		// type:

	nested_dicopower() { }

	nested_dicopower(value_type_ptr i, value_type_ptr t) : initial(i), terminal(t) { }

	~nested_dicopower() { }

	bool operator == (const type_ref c) const
	{
		return initial == c.initial && terminal == c.terminal;
	}

	bool operator != (const type_ref c) const
	{
		return initial != c.initial || terminal != c.terminal;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// meta:

	value_type_ptr & operator + () const
	{
		return terminal;
	}

	value_type_ptr & operator - () const
	{
		return initial;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return nested_dicopower(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return nested_dicopower(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return nested_dicopower(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return nested_dicopower(initial - n, terminal - n);
	}
};

