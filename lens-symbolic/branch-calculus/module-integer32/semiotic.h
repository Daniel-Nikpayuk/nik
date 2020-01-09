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

namespace nik
{
	template<typename SizeType>
	struct module<Module::integer32, Branch::lift, Lens::symbolic, Permission::semiotic, SizeType>
	{
		using rtn		= module;

		using size_type		= SizeType;

		using register_type	= typename Deductional::functor::template signed_type<32>::rtn;

		//

		#include"interface-structure-semiotic.hpp"

		//

//		#include"perspective-identity-semiotic.hpp"
		#include"perspective-functor-semiotic.hpp"
	};
}

