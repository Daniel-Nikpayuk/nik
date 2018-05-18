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

	The general case:
*/

template
<
	typename Type,
	size_type length,
	size_type N = One::value

> struct power
{
	using type				= power;
	using type_ref				= type&;
	using type_ptr				= type*;

	using value_type			= power<Type, length, N-1>;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using iterator				= copower<value_type>;
	using const_iterator			= copower<value_type, Access::readonly>;

	using nested_iterator			= nested_copower<value_type>;
	using const_nested_iterator		= nested_copower<value_type, Access::readonly>;

/*
	using multi_iterator			= multi_copower<value_type>;
	using const_multi_iterator		= multi_copower<value_type, Access::readonly>;
*/

	value_type value[length];

		// type:

	power() { }

	~power() { }

		// value:

		// navigator:

		// iterator:

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

		// nested_iterator:

	nested_iterator nested_begin()
	{
		return value;
	}

	const_nested_iterator nested_begin() const
	{
		return value;
	}

	nested_iterator nested_end()
	{
		return value + length;
	}

	const_nested_iterator nested_end() const
	{
		return value + length;
	}
};

/*
	The initial case:
*/

template
<
	typename Type,
	size_type length

> struct power
<
	Type,
	length,
	One::value
>
{
	using type				= power;
	using type_ref				= type&;
	using type_ptr				= type*;

	using value_type			= Type;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using iterator				= copower<value_type>;
	using const_iterator			= copower<value_type, Access::readonly>;

	using nested_iterator			= nested_copower<value_type>;
	using const_nested_iterator		= nested_copower<value_type, Access::readonly>;

/*
	using multi_iterator			= multi_copower<value_type>;
	using const_multi_iterator		= multi_copower<value_type, Access::readonly>;
*/

	value_type value[length];

		// type:

	power() { }

	~power() { }

		// value:

		// navigator:

		// iterator:

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

		// nested_iterator:

	nested_iterator nested_begin()
	{
		return value;
	}

	const_nested_iterator nested_begin() const
	{
		return value;
	}

	nested_iterator nested_end()
	{
		return value + length;
	}

	const_nested_iterator nested_end() const
	{
		return value + length;
	}
};
