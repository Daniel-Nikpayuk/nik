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

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct module<Module::enumerative, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using control_flow = module<Module::control_flow, Orientation::functional, Interface::media, size_type>;
		using identifier = module<Module::identifier, Orientation::functional, Interface::semiotic, size_type>;
		using structural = module<Module::enumerative, Orientation::structural, Interface::semiotic, size_type>;

		//

		template<typename Parameter = size_type>
		struct parameter
		{
			#include"alias/semiotic.hpp"

			// List:

				// Navigational:

				#include"car/semiotic.hpp"
				#include"cdr/semiotic.hpp"

				// Generational:

				#include"catenate/semiotic.hpp"

				// Existential:

//				#include"empty/semiotic.hpp"
//				#include"length/semiotic.hpp"

//				#include"filter/semiotic.hpp"

//				#include"contains/semiotic.hpp"
//				#include"compare/semiotic.hpp"
//				#include"enum_cast/semiotic.hpp"

//				#include"at/semiotic.hpp"
//				#include"erase/semiotic.hpp"
//				#include"sort/semiotic.hpp"
//				#include"fill/semiotic.hpp"

				#include"printer/semiotic.hpp"

			// Modifier:
		};
	};

}}

