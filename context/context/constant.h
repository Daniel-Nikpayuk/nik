/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

#ifndef CONTEXT_META_CONSTANT_H
#define CONTEXT_META_CONSTANT_H

#include"pre_begin.h"

namespace nik
{
	namespace context
	{
		namespace meta
		{
			template<typename size_type>
			struct constant
			{
				static const size_type register_length = (BYTE_LENGTH*sizeof(size_type));
				static const size_type half_length = (register_length>>ONE);

				static const size_type low_pass = (((size_type) ONE<<half_length)-ONE);
				static const size_type high_pass = ((size_type) low_pass<<half_length);

				static const size_type half_max = ((size_type) ONE<<half_length);

				static const size_type max_binary_power = ((size_type) ONE<<(register_length-ONE));
			};
		}
	}
}

#include"pre_end.h"

#endif
