/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#include<stddef.h>

namespace nik
{
	enum Module : size_t
	{
		control_flow,
		identifier,
		variadic,

		boolean,
		uint,
		sint,

		iterator
	};

	enum Orientation : size_t
	{
		structural,
		functional,
		procedural
	};

	enum Interface : size_t
	{
		semiotic,
		media
	};

	template<size_t module_enum, size_t orientation_enum, size_t interface_enum, typename SizeType = size_t>
	struct module
	{
		static_assert
		(
			module_enum != control_flow		||
			module_enum != variadic			||
			module_enum != iterator			,

			"This module is not yet implemented!"
		);
	};
}

