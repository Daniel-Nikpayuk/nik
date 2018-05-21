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

		using Pointer		= grammaric<Module::pointer, Permission::semiotic, size_type>;

		using Access		= typename Pointer::Access;

					  template<typename Type, Access access = Access::readwrite>
		using read_type		= typename Pointer::template read_type<Type, access>;

		//

		using Power		= grammaric<Module::power, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using copower		= typename Power::template copower<Type, access>;

					  template<typename Type, size_type length>
		using power		= typename Power::template power<Type, length>;

		using Interval		= typename Power::Interval;
		using Direction		= typename Power::Direction;

					  template<Interval interval, Direction direction>
		using object		= typename Power::template object<interval, direction>;

					  template<typename... Objects>
		using functor		= typename Power::template functor<Objects...>;

		//

		using Bit		= numeric<Module::bit, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using cobit		= typename Bit::template cobit<Type, access>;

					  template<typename RegType>
		using bit		= typename Bit::template bit<RegType>;

		//

		using Word		= numeric<Module::word, Permission::semiotic, size_type>;

					  template<typename Type, Access access = Access::readwrite>
		using coword		= typename Word::template coword<Type, access>;

					  template<typename BitType, size_type length>
		using word		= typename Word::template word<BitType, length>;

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
	};
}

