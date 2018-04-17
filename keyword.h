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

#include<stdio.h>
//#include<stddef.h>

namespace nik
{
	using global_size_type = size_t;

	constexpr void *null_ptr=0; // use builtin "nullptr" instead!

	constexpr char endl='\n';

	enum struct Access : global_size_type
	{
		readonly,
		readwrite,

		dimension // filler
	};

	template<typename Type, Access = Access::readwrite>
	struct read_type
		{ using rtn = Type; };

	template<typename Type>
	struct read_type<Type const, Access::readwrite>
		{ using rtn = Type; };

	template<typename Type>
	struct read_type<Type, Access::readonly>
		{ using rtn = Type const; };

	template<typename Type>
	struct read_type<Type const, Access::readonly>
		{ using rtn = Type const; };
}

