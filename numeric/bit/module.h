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
	struct module<Module::bit, SizeType>
	{
		typedef SizeType size_type;

		#include"interface/navigator.hpp"
		#include"interface/structure.hpp"

		//

		template<Permission permission_enum, typename Filler = void>
		struct perspective // <Permission::semiotic, Filler>
		{
//			#include"perspective//semiotic.hpp"
		};

		template<typename Filler>
		struct perspective<Permission::media, Filler>
		{
//			#include"perspective//media.hpp"
		};

		//

		template<Permission permission_enum, typename Filler = void>
		struct instance // <Permission::semiotic, Filler>
		{
			#include"instance/boolean/semiotic.hpp"
		};

		template<typename Filler>
		struct instance<Permission::media, Filler>
		{
//			#include"instance/boolean/media.hpp"
		};
	};

}}

