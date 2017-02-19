/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	enum struct Module : global_size_type
	{
		constant,
		branch,
		tuple,
		environment,
		evaluator,

		boolean,
		uint,
		sint,

		range,
		iterator, // iterative ?
		list,

		dimension // filler
	};

	enum struct Orientation : global_size_type
	{
		structural,
		functional,
		procedural,

		dimension // filler
	};

	enum struct Interface : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};

	namespace grammaric
	{
		template
		<
			Module module_enum,
			Orientation orientation_enum,
			Interface interface_enum,

			typename SizeType = global_size_type
		>
		struct module
		{
			static_assert
			(
				module_enum != Module::constant		||
				module_enum != Module::branch		||
				module_enum != Module::tuple		||
				module_enum != Module::environment	||
				module_enum != Module::evaluator	,

				"This module is not yet implemented!"
			);
		};
	}

	namespace numeric
	{
		template
		<
			Module module_enum,
			Orientation orientation_enum,
			Interface interface_enum,

			typename SizeType = global_size_type
		>
		struct module
		{
			static_assert
			(
				module_enum != Module::range		||
				module_enum != Module::iterator		||
				module_enum != Module::list		,

				"This module is not yet implemented!"
			);
		};
	}
}

