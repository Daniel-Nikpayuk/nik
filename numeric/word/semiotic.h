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
	struct space<Branch::numeric, Module::word, Permission::semiotic, SizeType>
	{
		using size_type		= SizeType;

		//

		#include nik_unpack(constant)
		#include nik_unpack(builtin)
		#include nik_unpack(pointer)
		#include nik_unpack(power)

		#include nik_unpack(bit)

		//

		#include"interface/adjective/semiotic.hpp"
		#include"interface/navigator/semiotic.hpp"
//		#include"interface/navigator/boolean/semiotic.hpp"
		#include"interface/structure/semiotic.hpp"
//		#include"interface/structure/boolean/semiotic.hpp"

		//

		#include"perspective/adjective/semiotic.hpp"
		#include"perspective/uint/semiotic.hpp"
	};
}

