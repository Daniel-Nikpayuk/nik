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
	In the context of this library, powers are the products of concurrent instances of the same type.
        The basic methods for the objects of this class are called as external static functions
	allowing for identity, proximity, and functor methods between various lengths.
*/

template<size_type N, typename Type, size_type length>
struct nested_power
{
	using type		= nested_power;
	using type_ptr		= type*;
	using type_ref		= type&;

	using value_type	= nested_power<N-1, Type, length>;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	using iterator		= nested_copower<N, value_type_ptr>;
	using const_iterator	= nested_copower<N, value_type_ptr, Access::readonly>;

//	using selector		= nested_dicopower<N, value_type_ptr>;
//	using const_selector	= nested_dicopower<N, value_type_ptr, Access::readonly>;

	value_type value[length];

		// type:

	nested_power() { }

	~nested_power() { }

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

/*
	selector range()
	{
		return selector(value, value + length);
	}

	const_selector range() const
	{
		return const_selector(value, value + length);
	}
*/
};

	// N = 0:

template<typename Type, size_type length>
struct nested_power<Zero::value, Type, length>
{
	using type		= nested_power;
	using type_ptr		= type*;
	using type_ref		= type&;

	using value_type	= Type;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	using iterator		= nested_copower<Zero::value, value_type_ptr>;
	using const_iterator	= nested_copower<Zero::value, value_type_ptr, Access::readonly>;

//	using selector		= nested_dicopower<Zero::value, value_type_ptr>;
//	using const_selector	= nested_dicopower<Zero::value, value_type_ptr, Access::readonly>;

	value_type value[length];

		// type:

	nested_power() { }

	~nested_power() { }

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

/*
	selector range()
	{
		return selector(value, value + length);
	}

	const_selector range() const
	{
		return const_selector(value, value + length);
	}
*/
};

/*
	The special case where N = 0 is used often in this library and gets its own alias:
*/

		template<typename Type, Access access = Access::readwrite>
using power = nested_power<Zero::value, Type, access>;

