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
	struct module<Module::bit, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using control_flow = module<Module::control_flow, Orientation::functional, Interface::media, size_type>;

		//

		template<Orientation orientation_enum, Interface interface_enum>
		using variadic = grammaric::module<Module::variadic, orientation_enum, interface_enum, size_type>;

		template<typename enum_type>
		using parameter = typename variadic<Orientation::structural, Interface::semiotic>::template parameter<enum_type>;

		template<size_type... params>
		using list = typename parameter<size_type>::template list<params...>;

		//

		#include"contains/semiotic.hpp"
		#include"complement/semiotic.hpp"
		#include"apply/semiotic.hpp"
		#include"deduct/semiotic.hpp"

		#include"cast/semiotic.hpp"
		#include"match/semiotic.hpp"
		#include"dispatch/semiotic.hpp"
	};

}}

