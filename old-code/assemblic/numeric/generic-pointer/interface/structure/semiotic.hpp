/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*/

template<size_type N, typename Type, Access access = Access::readwrite>
struct pointer
{
	using rtn = typename pointer<N-1, Type, access>::rtn *;
};

/*
	N	= zero,
	access	= readwrite:

	1. Type
	2. Type const
	3. Type const *
*/

template<typename Type>
struct pointer<Zero::value, Type, Access::readwrite>
{
	using rtn = Type;
};

template<typename Type>
struct pointer<Zero::value, Type const, Access::readwrite>
{
	using rtn = Type;
};

template<typename Type>
struct pointer<Zero::value, Type const *, Access::readwrite>
{
	using rtn = Type*;
};

/*
	N	= zero,
	access	= readony:

	1. Type const --- special case of (3.) as (const const) == const
	2. Type*
	3. Type
*/

template<typename Type>
struct pointer<Zero::value, Type*, Access::readonly>
{
	using rtn = Type const *;
};

template<typename Type>
struct pointer<Zero::value, Type, Access::readonly>
{
	using rtn = Type const;
};

/*
	The zero case occurs often enough in this library to merit an alias
*/

		  template<typename Type, Access access = Access::readwrite>
using read_type = pointer<Zero::value, Type, access>;

