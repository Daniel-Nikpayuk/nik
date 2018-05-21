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
	struct space<Branch::numeric, Module::bit, Permission::semiotic, SizeType>
	{
		using size_type		= SizeType;

		//

		using Constant		= grammaric<Module::constant, Permission::semiotic, size_type>;

		using Zero		= typename Constant::Zero;
		using One		= typename Constant::One;

		//

		using Pointer		= grammaric<Module::pointer, Permission::semiotic, size_type>;

		using Access		= typename Pointer::Access;

					  template<typename Type, Access access = Access::readwrite>
		using read_type		= typename Pointer::template read_type<Type, access>;

		//

		using Power		= grammaric<Module::power, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using copower		= typename Power::template copower<Type>;

		#include"interface/navigator/semiotic.hpp"

		#include"interface/structure/semiotic.hpp"
		#include"interface/structure/boolean/semiotic.hpp"
	};
}

