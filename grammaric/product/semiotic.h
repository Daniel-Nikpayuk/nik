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
	template<typename SizeType>
	struct space<Branch::grammaric, Module::product, Permission::semiotic, SizeType>
	{
		using size_type		= SizeType;

		//

		using coproduct_s	= grammaric<Module::coproduct, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using coproduct		= typename coproduct_s::template coproduct<Type, access>;

		//

		using copair_s		= grammaric<Module::copair, Permission::semiotic, size_type>;

					  template<typename Type, Access access>
		using copair		= typename copair_s::template copair<Type, access>;

		//

		#include"interface/semiotic.hpp"

		//

//		#include"perspective/identity/semiotic.hpp"
//		#include"perspective/proximity/semiotic.hpp"
//		#include"perspective/shape/semiotic.hpp"
	};
}

