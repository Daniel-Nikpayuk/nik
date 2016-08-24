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
	using global_size_type = size_t;

	enum Module : global_size_type
	{
		control_flow,
		identifier,
		variadic,

		boolean,
		uint,
		sint,

		iterator,
		module // filler
	};

	enum Orientation : global_size_type
	{
		structural,
		functional,
		procedural,
		orientation // filler
	};

	enum Interface : global_size_type
	{
		semiotic,
		media,
		interface // filler
	};

	namespace grammaric
	{
		template
		<
			global_size_type module_enum,
			global_size_type orientation_enum,
			global_size_type interface_enum,

			typename SizeType = global_size_type
		>
		struct module
		{
			static_assert
			(
				module_enum != control_flow		||
				module_enum != identifier		||
				module_enum != variadic			,
		
				"This module is not yet implemented!"
			);
		};
	}

	namespace numeric
	{
		template
		<
			global_size_type module_enum,
			global_size_type orientation_enum,
			global_size_type interface_enum,

			typename SizeType = global_size_type
		>
		struct module
		{
			static_assert
			(
				module_enum != iterator			,
		
				"This module is not yet implemented!"
			);
		};
	}
}

