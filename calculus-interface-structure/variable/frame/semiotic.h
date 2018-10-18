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
	struct module<Name::frame, Branch::variable, Lens::calculus, Permission::semiotic, SizeType>
	{
		using type	= module;

		using size_type	= SizeType;

		//

		#include nik_typedef(calculus, kernel, act, module)
		#include nik_typedef(calculus, kernel, act, structure)

		#include nik_typedef(calculus, dispatch, conditional, module)
		#include nik_typedef(calculus, dispatch, conditional, structure)

		#include nik_typedef(calculus, variable, binding, module)
		#include nik_typedef(calculus, variable, binding, structure)
		#include nik_typedef(calculus, variable, binding, alias)

		//

		#include"interface-structure-semiotic.hpp"

		//

		#include"perspective-functor-semiotic.hpp"
	};
}

