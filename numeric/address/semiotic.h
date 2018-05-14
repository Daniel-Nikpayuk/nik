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
	struct space<Branch::numeric, Module::address, Permission::semiotic, SizeType>
	{
		using size_type		= SizeType;

		//

		using Coproduct		= grammaric<Module::coproduct, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using coproduct		= typename Coproduct::template coproduct<Type, access>;

		using Copair		= grammaric<Module::copair, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using copair		= typename Copair::template copair<Type, access>;

		using Product		= grammaric<Module::product, Permission::semiotic, size_type>;

					  template<typename Type, size_type length>
		using product		= typename Product::template product<Type, length>;

		//

		using Bit		= numeric<Module::bit, Permission::semiotic, size_type>;

		using boolean		= typename Bit::boolean;

					  template<typename Binary>
		using bit		= typename Bit::template bit<Binary>;

		using Word		= numeric<Module::word, Permission::semiotic, size_type>;

		//

		#include"interface/navigator/semiotic.hpp"
//		#include"interface/navigator/boolean/semiotic.hpp"

		#include"interface/structure/semiotic.hpp"
//		#include"interface/structure/boolean/semiotic.hpp"

		//

//		#include"perspective/identity/semiotic.hpp"
//		#include"perspective/identity/boolean/semiotic.hpp"

//		#include"perspective/proximity/semiotic.hpp"
//		#include"perspective/proximity/boolean/semiotic.hpp"

//		#include"perspective/logic/semiotic.hpp"
	};
}

