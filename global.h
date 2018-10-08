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

namespace nik
{
	using global_size_type = size_t;

	constexpr void *null_ptr = 0; // use builtin "nullptr" instead ?

	// endl will be a unicode type.

	//

	enum struct Branch : global_size_type
	{
		grammaric,
		graphic,
		interic,
		kinetic,
		literic,

		metaric,
		numeric,
		phonetic,

		dimension // filler
	};

	enum struct Module : global_size_type
	{
		address,
		bit,
		constant,

		generic,
		kernel,
		pointer,
		power,
		printer,

		tuple,
		word,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		media,
		semiotic,

		dimension // filler
	};

	//

//	template<typename, typename SizeType = global_size_type> struct appendix;
}

