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

namespace nik
{
	enum struct Branch : global_size_type
	{
		grammaric,
		numeric,

		dimension // filler
	};

	enum struct Module : global_size_type
	{
		constant,
		conditional,
		tuple,
		environment,
		evaluator,
		product,

		bit,
		word,
		address,

		range,
		list,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};

	template
	<
		Branch branch_enum,
		Module module_enum,
		Permission permission_enum,

		typename SizeType = global_size_type
	>
	struct space { static_assert(true, "This module is not yet implemented!"); };

	//

				  template<Module module, Permission permission, typename SizeType = global_size_type>
	using grammaric		= space<Branch::grammaric, module, permission, SizeType>;

				  template<Module module, Permission permission, typename SizeType = global_size_type>
	using numeric		= space<Branch::numeric, module, permission, SizeType>;
}

