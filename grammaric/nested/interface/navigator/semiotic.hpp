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

#include"recursive/semiotic.hpp"

/*
	In the context of this library, copowers are the disjoint union of alternative instances of the same type.

	When building more complex navigators out of simpler ones,
	the only reasons to reimplement copowers are as follows:

	1. Optimizing the method interface.
	2. Optimization by unraveling. This is necessary if the context
	   requires frequently moving between levels of navigational complexity.
*/

template<size_type N, typename Type, Access access = Access::readwrite>
struct nested_copower
{
	using type			= nested_copower;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= nested_copower<N, Type, Access::readonly>;

	using value_type		= typename read_type<Type, access>::rtn;
	using value_type_ptr		= value_type*;
	using value_type_ref		= value_type&;

	using base_copower_type		= recursive_copower<0, Type, access>;
	using base_copower_type_ptr	= base_copower_type*;
	using base_copower_type_ref	= base_copower_type&;

		// defined as an array of pointers of the initial (N = 0) recursive copower,
		// as this allows for dynamic polymorphism.

	base_copower_type_ptr path[N+1];

	base_copower_type_ptr *location;

		// type:

	nested_copower() : location(path) { }

	~nested_copower()
	{
		// deallocate location componentwise.
	}

	bool operator == (const type_ref c) const
	{
		return *location == *c.location;
	}

	bool operator != (const type_ref c) const
	{
		return *location != *c.location;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	base_copower_type_ptr & operator * () const
	{
		return *location;
	}

		// meta:

	void operator + ()
	{
		++location;
	}
	
	void operator - ()
	{
		--location;
	}

		// navigator:

	type_ref operator ++ ()
	{
		(*location)->operator++();

		return *this;
	}

	type operator ++ (int int_value)
	{
		return (*location)->operator++(int_value);
	}

	type_ref operator += (size_type n)
	{
		(*location)->operator+=(n);

		return *this;
	}

	type operator + (size_type n) const
	{
		return (*location)->operator+(n);
	}

	type_ref operator -- ()
	{
		(*location)->operator--();

		return *this;
	}

	type operator -- (int int_value)
	{
		return (*location)->operator--(int_value);
	}

	type_ref operator -= (size_type n)
	{
		(*location)->operator-=(n);

		return *this;
	}

	type operator - (size_type n) const
	{
		return (*location)->operator-(n);
	}

	size_type operator - (const type_ref c) const
	{
		return *location - *c.location;
	}
};

