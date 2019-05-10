/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(symbolic, kernel, core, structure)

/*
	id:
*/

	template<bool Value>
	using memoized_bool = memoized_value<bool, Value>;

/*
	is_equal:
*/

	template<typename Type1, typename Type2>
	using is_equal = typename memoized_equality<Type1, Type2>::template match
	<
		memoized_bool
	>;

/*
	is_pointer:
*/

	template<typename Type>
	using is_pointer = typename memoized_pointer<Type>::template match
	<
		memoized_bool
	>;
};

