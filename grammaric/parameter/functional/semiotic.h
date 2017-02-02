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

		using control_flow = module<Module::control_flow, Orientation::functional, Interface::media, size_type>;

		template<bool t, typename f, typename s>
		using if_then_else = typename control_flow::template if_then_else<t, f, s>;

		// Both:

		#include"isNull/semiotic.hpp"
		#include"length/semiotic.hpp"
		#include"catenate/semiotic.hpp"
		#include"filter/semiotic.hpp"

		// Tuple:

		#include"cases/semiotic.hpp"

		// List:

		#include"isMember/semiotic.hpp"
		#include"compare/semiotic.hpp"
		#include"enum_cast/semiotic.hpp"

		#include"at/semiotic.hpp"
		#include"erase/semiotic.hpp"
		#include"sort/semiotic.hpp"
		#include"fill/semiotic.hpp"

		#include"sortFill/semiotic.hpp"
	};

}}

