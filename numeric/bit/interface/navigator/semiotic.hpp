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

	binary type assumes operators: &, *;

	Navigators may be optimized in their methods as they have limited perspectives.
*/

template<typename Binary, Access access = Access::readwrite>
struct bit_navigator
{
	using type			= bit_navigator;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= bit_navigator<Binary, Access::readonly>;

	using sub_navigator		= typename coproduct_s::template coproduct_navigator<typename Binary::type, access>;
	using sub_navigator_ptr		= sub_navigator*;
	using sub_navigator_ref		= sub_navigator&;

	using binary_type		= typename read_type<typename Binary::type, access>::rtn;
	using binary_type_ptr		= binary_type*;
	using binary_type_ref		= binary_type&;

	sub_navigator location;

		// type:

	bit_navigator(sub_navigator_ref l) : location(*l) { }

	~bit_navigator() { }

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

		// navigator:

	void operator - ()
	{
		*location.focus = Binary::f;
	}

	void operator + ()
	{
		*location.focus = Binary::t;
	}

		// value:

	const binary_type_ref operator * () const
	{
		return *location;
	}
};

