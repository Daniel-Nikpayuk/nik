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

		//

		template<Orientation orientation_enum, Interface interface_enum>
		using variadic = grammaric::module<Module::variadic, orientation_enum, interface_enum, size_type>;

		template<typename enum_type>
		using parameter = typename variadic<Orientation::structural, Interface::semiotic>::template parameter<enum_type>;

		template<typename... params>
		using tuple = typename variadic<Orientation::structural, Interface::semiotic>::template tuple<params...>;

		template<typename Field, typename Relation, Relation... params>
		using sortFill = typename variadic<Orientation::functional, Interface::media>::template sortFill<Field, Relation, params...>;

		//

		using uint = module<Module::uint, Orientation::structural, Interface::semiotic, size_type>;

		using UIntAssociation = typename uint::Association;

		template<UIntAssociation... params>
		using uint_list = typename uint::template adj_list<params...>;

		template<typename L>
		using UIntAdjective = typename uint::template Adjective<L>;

		//

		template<Interface interface_enum>
		using structural = module<Module::iterator, Orientation::structural, interface_enum, size_type>;

		using Association = typename structural<Interface::semiotic>::Association;

		template<Association... params>
		using adj_list = typename structural<Interface::semiotic>::template adj_list<params...>;

		using null_adj = typename structural<Interface::semiotic>::null_adj;

		template<typename... params>
		using Adjective = typename structural<Interface::semiotic>::template Adjective<params...>;

		//

		#include"adverb/semiotic.hpp"

		#include"call/peek_action.hpp"
		#include"call/functor_action.hpp"
		#include"call/count_action.hpp"
		#include"call/iterate_action.hpp"
		#include"call/memory_action.hpp"

		#include"repeat/semiotic.hpp"
		#include"morph/semiotic.hpp"
		#include"map/semiotic.hpp"

		#include"discourse/semiotic.hpp"
	};

}}

