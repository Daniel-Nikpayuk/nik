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
namespace numeric	{

	template<typename SizeType>
	struct module<Module::iterator, Orientation::procedural, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using bit = grammaric::module<Module::bit, Orientation::structural, Interface::media, size_type>;

		//

		template<Orientation orientation_enum, Interface interface_enum>
		using variadic = grammaric::module<Module::variadic, orientation_enum, interface_enum, size_type>;

		template<typename enum_type>
		using parameter = typename variadic<Orientation::structural, Interface::semiotic>::template parameter<enum_type>;

		//

		using enumerator = module<Module::enumerator, Orientation::structural, Interface::semiotic, size_type>;

		//

		using structural = module<Module::iterator, Orientation::structural, Interface::semiotic, size_type>;

		//

		#include"adverb/semiotic.hpp"
		#include"dispatch/semiotic.hpp"

		//

		#include"action/peek_action.hpp"
		#include"action/functor_action.hpp"
		#include"action/count_action.hpp"
		#include"action/iterate_action.hpp"
		#include"action/memory_action.hpp"

		//

		#include"repeat/semiotic.hpp"
//		#include"morph/semiotic.hpp"
//		#include"map/semiotic.hpp"

//		#include"noderize/semiotic.hpp"
//		#include"catenate/semiotic.hpp"
//		#include"grow/semiotic.hpp"
//		#include"shrink/semiotic.hpp"
//		#include"split/semiotic.hpp"
//		#include"strip/semiotic.hpp"

//		#include"discourse/semiotic.hpp"
	};

}}

