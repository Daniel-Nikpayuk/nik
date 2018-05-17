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
	bit type	:= 0 + 1;
	bit instance	:= s^1, s^2;

	A cobit is a copower of BinaryType. We reimplement as its method interface can be optimized.

	Although the template parameter allows for arbitrary types, cobit is meant specifically for register sizes:

	2 << 0, bool

	The binary type is assumed to have at least two instances, and basic arithmetic to navigate from one to the other.
*/

template<typename BinaryType, Access access = Access::readwrite>
struct cobit
{
	using type			= cobit;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= cobit<BinaryType, Access::readonly>;

	using binary_type		= typename BinaryType::builtin_type;
	using binary_type_ref		= binary_type&;
	using binary_type_ptr		= binary_type*;

	using copower_type		= copower<binary_type, access>;
	using copower_type_ref		= copower_type&;
	using copower_type_ptr		= copower_type*;

	copower_type location;

		// type:

	cobit() { }

	cobit(const binary_type_ref b) : location(b) { }

	~cobit() { }

	bool operator == (const type_ref n) const
	{
		return location == n.location;
	}

	bool operator != (const type_ref n) const
	{
		return location != n.location;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	const binary_type_ref operator * () const
	{
		return *location;
	}

		// navigator:

	void operator + ()
	{
		*location = BinaryType::t;
	}

	void operator - ()
	{
		*location = BinaryType::f;
	}
};

