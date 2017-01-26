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

		template<typename L>
		using length = typename variadic<Orientation::functional, Interface::semiotic>::template length<L>;

		template<typename... params>
		using tuple = typename variadic<Orientation::structural, Interface::semiotic>::template tuple<params...>;

		template<size_type i, typename... params>
		using cases = typename variadic<Orientation::functional, Interface::media>::template cases<i, params...>;

		template<typename Field, typename Relation, Relation... params>
		using sortFill = typename variadic<Orientation::functional, Interface::media>::template sortFill<Field, Relation, params...>;

		//

		using enumerator = module<Module::enumerator, Orientation::structural, Interface::semiotic, size_type>;

		using EnumAssociation = typename enumerator::Association;

		template<EnumAssociation... params>
		using enum_list = typename parameter<EnumAssociation>::template list<params...>;

		using null_enum = enum_list<>;

		template<size_type mask, typename... params>
		using EnumAdjective = typename enumerator::template Adjective<mask, params...>;

		//

		template<Interface interface_enum>
		using structural = module<Module::iterator, Orientation::structural, interface_enum, size_type>;

		using Association = typename structural<Interface::semiotic>::Association;

		template<Association... params>
		using adj_list = typename parameter<Association>::template list<params...>;

		using null_adj = adj_list<>;

		using adj_bitmask = typename structural<Interface::semiotic>::bitmask;

		template<size_type mask>
		using adj_pattern = typename adj_bitmask::template pattern<mask>;

		template<size_type mask, typename... params>
		using adjective = typename structural<Interface::semiotic>::template adjective<mask, params...>;

		template<Association... params>
		using Adjective = typename structural<Interface::semiotic>::template Adjective<params...>;

		template<typename T, Association... params>
		using TAdjective = typename structural<Interface::semiotic>::template TAdjective<T, params...>;

		template<size_type mask>
		using adj_modifier = typename structural<Interface::semiotic>::template modifier<mask>;

		//

		#include"adverb/semiotic.hpp"

		template<Connotation... params>
		using adv_list = typename parameter<Connotation>::template list<params...>;

		using null_adv = adv_list<>;

		//

		#include"action/peek_action.hpp"
		#include"action/functor_action.hpp"
		#include"action/count_action.hpp"
		#include"action/iterate_action.hpp"
		#include"action/memory_action.hpp"

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

