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

#include<stdio.h>

namespace nik
{
	using global_size_type = signed long long; //size_t;

	constexpr void *null_ptr = 0; // use builtin "nullptr" instead ?

	// endl was here, but will instead be a unicode static const object.

	//

	enum struct Module : global_size_type
	{

	// kernel:

		core,

	// calculus:

		product,
		coproduct,
		power,
		copower,

	// lift:

		operate,

		boolean,
		literal,
		number,

		natural8,
		natural16,
		natural32,
		natural64,

		integer8,
		integer16,
		integer32,
		integer64,

	// scheme:

		normal,
		lazy,

	// kin:

		concept,
		instance,
		type,
		judgement,

	// generic:

		pointer,
//		power,

	// numeric:

		bit,
		word,
		address,

	// graphic:

		printer,

		dimension // filler
	};

	enum struct Branch : global_size_type
	{

	// perspective:

		kernel,

	// symbolic:

//		kernel,
		calculus,
		lift,
		scheme,
		kin,

	// assemblic:

		generic,
		numeric,
		literic,
		graphic,
		phonetic,
		kinetic,
		interic,

		dimension // filler
	};

	enum struct Lens : global_size_type
	{
		symbolic,
		assemblic,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};
}

