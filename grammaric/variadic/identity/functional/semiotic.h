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
	struct module<Module::variadic, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using structural = module<Module::variadic, Orientation::structural, Interface::semiotic, size_type>;

		//

		#include"alias/semiotic.hpp"

			// Navigational:

		#include"car/semiotic.hpp"
		#include"cdr/semiotic.hpp"

////		#include"at/semiotic.hpp"

			// Existential:

		#include"length/semiotic.hpp"

			// Generational:

////		#include"copy/semiotic.hpp"
////		#include"sifter/semiotic.hpp"

////		#include"erase/semiotic.hpp"
//		#include"filter/semiotic.hpp"

		#include"cons/semiotic.hpp"
		#include"push/semiotic.hpp"
		#include"catenate/semiotic.hpp"

////		#include"decatenate/semiotic.hpp"
////		#include"decons/semiotic.hpp"
////		#include"pop/semiotic.hpp"

			// Translational:
	};

}}

