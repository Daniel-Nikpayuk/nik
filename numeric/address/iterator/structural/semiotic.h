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
	struct module<Module::iterator, Orientation::structural, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		using enumerative = grammaric::module<Module::enumerative, Orientation::structural, Interface::semiotic, size_type>;

		//

		#include"alias/semiotic.hpp"
		#include"adjective/semiotic.hpp"

		//

		#include"node/semiotic.hpp"
		#include"segment/semiotic.hpp"
		#include"hook/semiotic.hpp"
		#include"link/semiotic.hpp"
		#include"trim/semiotic.hpp"
	};

}}

