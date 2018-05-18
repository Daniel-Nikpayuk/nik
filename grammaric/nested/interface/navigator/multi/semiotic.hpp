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

	The specification is incomplete as I don't have any concrete applications to test against.
*/

template
<
	typename Type,
	Access access = Access::readwrite

> struct multi_copower;

/*
	Implementation lacks modularity:

	Is optimized to work directly with multi powers,
	which is to say it references the internals of the multi power specification.
*/

template
<
	typename Type,
	size_type length,
	size_type N,
	template<class, size_type, size_type> typename Power,

	Access access

> struct multi_copower
<
	Power<Type, length, N>,
	access
>
{
	using type				= multi_copower;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= multi_copower<Power<Type, length, N>, Access::readonly>;

	using value_type			= typename read_type<Power<Type, length, N>, access>::rtn;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using copower_type			= copower<value_type, Orientation::multi, access>;
	using copower_type_ref			= copower_type&;
	using copower_type_ptr			= copower_type*;

	using polymorphic_type			= copower<Power<Type, length, One::value>, Orientation::multi, access>;
	using polymorphic_type_ref		= polymorphic_type&;
	using polymorphic_type_ptr		= polymorphic_type*;

		// defined as an array of pointers of the initial (N = 0) recursive copower,
		// as this allows for dynamic polymorphism.

	copower_type focus;

	polymorphic_type_ptr path[N];

	polymorphic_type_ptr *location;

		// type:

	multi_copower() { }

		// initialize location to the initial position in the array.
		// this aligns with the use of operators +,-  ().

	multi_copower(value_type_ptr p) : focus(p), location(path)
	{
		*location = &focus;
	}

		// Destructor: Does nothing. Iterators can (de)allocate,
		// but otherwise default to passive interaction.

	~multi_copower() { }

		// identity comparisons are applied to copowers,
		// and otherwise stay within the local level of complexity.

	bool operator == (const type_ref c) const
	{
		return **location == **c.location;
	}

	bool operator != (const type_ref c) const
	{
		return **location != **c.location;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

		// Here multi_copowers return copower pointers instead of dereferences.
		// This is valuable as different copower specializations return different types.

	polymorphic_type_ptr & operator * () const
	{
		return *location;
	}

		// meta:

	void operator + ()
	{
		(*location)->location = (*location)->focus->value;
		*(location+1) = (*location)->location;
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

