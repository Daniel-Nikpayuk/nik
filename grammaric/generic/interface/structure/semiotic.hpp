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
	I prefer to use template template pattern matching in implementing,
	but GCC has given me an internal compiler error. As such, I default back to predeclarations:
*/

template
<
	typename Type,
	size_type length

> struct power;

/*
	In the context of this library, powers are the products of concurrent instances of the same type.
        The basic methods for the objects of this class are called as external static functions
	allowing for identity, proximity, and functor methods between various lengths.

	The general case:
*/

template
<
	typename Type,
	size_type length

> struct power
{
	using type				= power;
	using type_ref				= type&;
	using type_ptr				= type*;

	using value_type			= Type;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using iterator				= copower<type>;
	using const_iterator			= copower<type, Access::readonly>;

	value_type value[length];

		// type:

	power() { }

	~power() { }

		// value:

		// navigator:

	iterator begin()
	{
		return value;
	}

	const_iterator begin() const
	{
		return value;
	}

	iterator end()
	{
		return value + length;
	}

	const_iterator end() const
	{
		return value + length;
	}
};

