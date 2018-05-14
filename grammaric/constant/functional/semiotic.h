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
	struct module<Module::constant, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		nik_using(grammaric, Constant)

		#include"alias/semiotic.hpp"

		//

		#include"empty/semiotic.hpp"
		#include"is_constant/semiotic.hpp"

		#include"equal/semiotic.hpp"
		#include"less_than/semiotic.hpp"
		#include"less_than_or_equal/semiotic.hpp"
		#include"greater_than/semiotic.hpp"
		#include"greater_than_or_equal/semiotic.hpp"

		#include"Not/semiotic.hpp"
		#include"And/semiotic.hpp"
		#include"Or/semiotic.hpp"

		#include"printer/semiotic.hpp"
	};

}}

