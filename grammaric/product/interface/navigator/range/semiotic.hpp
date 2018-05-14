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
	Although the template parameter allows for arbitrary types, dicoproduct is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	8 << 3, void*

	In the context of this library, dicoproducts are pairs of disjoint unions of alternative instances of the same type.
	They are intended to represent ranges. As this generic code is only intended for a fixed number of similar types,
	the basic methods for the objects of this class are builtin rather than being called as external static functions.

	When building more complex navigators out of simpler ones,
	the only reasons to reimplement dicoproducts are as follows:

	1. Optimizing the method interface.
	2. Optimization by unrolling. This is necessary if the context
	   requires frequently moving between levels of navigational complexity.
*/

template<typename Type, Access access = Access::readwrite>
struct dicoproduct
{
	using type		= dicoproduct;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= dicoproduct<Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type initial;
	value_type terminal;

		// type:

	dicoproduct(const value_type_ref i, const value_type_ref t) : initial(i), terminal(t) { }

	~dicoproduct() { }

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

		// navigator:

	value_type_ref operator - () const
	{
		return initial;
	}

	value_type_ref operator + () const
	{
		return terminal;
	}

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return dicoproduct(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return dicoproduct(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return dicoproduct(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return dicoproduct(initial - n, terminal - n);
	}
};

