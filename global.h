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

	// endl was here, but will instead be a unicode static const object.

	//

	enum struct Name : global_size_type
	{
		undefined,
		act,

			boolean,
			conditional,

			constant,
			op,
			list,

			label,
			lambda,
			binding,
			frame,
			environment,

			begin,
			body,
			program,

		pointer,
		power,

			bit,
			word,
			address,

		printer,

		dimension // filler
	};

	enum struct Branch : global_size_type
	{
		kernel,
		dispatch,
		builtin,
		variable,
		interpret,

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
		calculus,
		hardware,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};
}

