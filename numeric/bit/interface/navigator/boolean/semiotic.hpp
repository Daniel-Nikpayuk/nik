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

struct boolean
{
	using builtin_type = bool;

	static constexpr builtin_type f = false;
	static constexpr builtin_type t = true;
};

//

template<Access access>
struct bit<boolean, access>
{
	using type			= bit;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= bit<boolean, Access::readonly>;

	using binary_type		= typename boolean::builtin_type;
	using binary_type_ptr		= binary_type*;
	using binary_type_ref		= binary_type&;

	using coproduct_type		= coproduct<binary_type, access>;
	using coproduct_type_ptr	= coproduct_type*;
	using coproduct_type_ref	= coproduct_type&;

	binary_type value;

		// type:

	bit() { }

	bit(binary_type b) : value(b) { }

	~bit() { }

	bool operator == (const type_ref n) const
	{
		return value == n.value;
	}

	bool operator != (const type_ref n) const
	{
		return value != n.value;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	const binary_type operator * () const
	{
		return value;
	}

		// navigator:

	void operator + ()
	{
		value = boolean::t;
	}

	void operator - ()
	{
		value = boolean::f;
	}
};

