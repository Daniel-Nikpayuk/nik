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

	A bit is a copower of RegType.

	Although the template parameter allows for arbitrary types, cobit is meant specifically for the register size:

	2 << 0, bool
*/

template
<
	typename RegType,
	typename Filler

> struct bit
{
	using type				= bit;
	using type_ref				= type&;
	using type_ptr				= type*;

	using value_type			= RegType;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

		// In this special case, the iterator
		// of the grammatical construct is itself.

	using iterator				= copower<value_type>;
	using const_iterator			= copower<value_type, Access::readonly>;

	using navigator				= cobit<type>;
	using const_navigator			= cobit<type, Access::readonly>;

	value_type value;

		// type:

	bit() : value(Zero::value) { }

	~bit() { }

		// value:

		// navigator:

	navigator begin()
	{
		return value;
	}

	const_navigator begin() const
	{
		return value;
	}

	navigator end()
	{
		return value = One::value;
	}

	const_navigator end() const
	{
		return value = One::value;
	}
};

