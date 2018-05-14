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
	Optimizations make no assumptions about the specifications
	of their internal structures, only their external interfaces.
*/

template<Access access>
struct dicobit<boolean, access>
{
	using type			= dicobit;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= dicobit<boolean, Access::readonly>;

	using binary_type		= typename boolean::builtin_type;
	using binary_type_ptr		= binary_type*;
	using binary_type_ref		= binary_type&;

	using coproduct_type		= coproduct<binary_type, access>;
	using coproduct_type_ptr	= coproduct_type*;
	using coproduct_type_ref	= coproduct_type&;

	binary_type initial;
	binary_type terminal;

		// type:

	dicobit() { }

	dicobit(binary_type b) : value(b) { }

	dicobit(binary_type i, binary_type t) : initial(i), terminal(t) { }

	~dicobit() { }

	bool operator == (const type_ref c) const
	{
		return initial == c.initial && terminal == c.terminal;
	}

	bool operator != (const type_ref c) const
	{
		return initial != c.initial || terminal != c.terminal;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

		// navigator:

	coproduct_type_ref operator - () const
	{
		return initial;
	}

	coproduct_type_ref operator + () const
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

