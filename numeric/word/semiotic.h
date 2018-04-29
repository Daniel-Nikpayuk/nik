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

namespace nik		{
namespace numeric	{

	template<typename SizeType>
	struct module<Module::word, Permission::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using product_s = grammaric::module<Module::product, Permission::semiotic, size_type>;

		template<typename Type, size_type length>
		using product = typename product_s::template product<Type, length>;

		//

		using bit_s = module<Module::bit, Permission::semiotic, size_type>;

		using boolean = typename bit_s::boolean;

		template<typename Binary>
		using bit = typename bit_s::template bit<Binary>;

		//

		#include"interface/navigator/semiotic.hpp"
		#include"interface/navigator/boolean/semiotic.hpp"

		#include"interface/structure/semiotic.hpp"
		#include"interface/structure/boolean/semiotic.hpp"

		//

		#include"perspective/identity/semiotic.hpp"
		#include"perspective/identity/boolean/semiotic.hpp"

		#include"perspective/proximity/semiotic.hpp"
		#include"perspective/proximity/boolean/semiotic.hpp"

		#include"perspective/logic/semiotic.hpp"
	};

}}

