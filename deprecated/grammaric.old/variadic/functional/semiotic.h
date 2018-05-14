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
namespace grammaric	{

	template<typename SizeType>
	struct module<Module::variadic, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using identifier = module<Module::identifier, Orientation::functional, Interface::semiotic, size_type>;
		using control_flow = module<Module::control_flow, Orientation::functional, Interface::semiotic, size_type>;
		using structural = module<Module::variadic, Orientation::structural, Interface::semiotic, size_type>;

		//

		#include"alias/semiotic.hpp"

		// base:

			// Navigational:

				#include"base/car/semiotic.hpp"
				#include"base/cdr/semiotic.hpp"

////				#include"base/at/semiotic.hpp"

			// Existential:

				#include"base/length/semiotic.hpp"

			// Generational:

////				#include"base/copy/semiotic.hpp"
////				#include"base/sifter/semiotic.hpp"

////				#include"base/erase/semiotic.hpp"
				#include"base/filter/semiotic.hpp"

				#include"base/cons/semiotic.hpp"
				#include"base/push/semiotic.hpp"
				#include"base/catenate/semiotic.hpp"

////				#include"base/decatenate/semiotic.hpp"
////				#include"base/decons/semiotic.hpp"
////				#include"base/pop/semiotic.hpp"

			// Translational:

				#include"base/parameter/semiotic.hpp"

		// tuple:

			// Navigational:

			// Existential:

//				#include"list/holds/semiotic.hpp"

			// Generational:

			// Translational:

				#include"tuple/printer/semiotic.hpp"

		// list:

			// Navigational:

			// Existential:

				#include"list/compare/semiotic.hpp"
				#include"list/has/semiotic.hpp"

			// Generational:

				#include"list/sort/semiotic.hpp"

			// Translational:

				#include"list/printer/semiotic.hpp"

		// modifier:

			// Navigational:

			// Existential:

//				#include"modifier/contains/semiotic.hpp"
//				#include"modifier/covers/semiotic.hpp"
//				#include"modifier/match/semiotic.hpp"
//				#include"modifier/dispatch/semiotic.hpp"

			// Generational:

//				#include"modifier/adjoin/semiotic.hpp"
//				#include"modifier/add/semiotic.hpp"
//				#include"modifier/cross/semiotic.hpp"
//				#include"modifier/subtract/semiotic.hpp"

//				#include"modifier/fill/semiotic.hpp"

			// Translational:

	};

}}

