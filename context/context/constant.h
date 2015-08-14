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

#define ZERO 0
#define ONE 1
#define TWO 2

#define BYTE_LENGTH 8

namespace nik
{
	namespace context
	{
		namespace meta
		{
			template<typename SizeType>
			struct constant
			{
				static const SizeType register_length = (BYTE_LENGTH*sizeof(SizeType));
				static const SizeType half_length = (register_length>>ONE);

				static const SizeType low_pass = (((SizeType) ONE<<half_length)-ONE);
				static const SizeType high_pass = (low_pass<<half_length);

				static const SizeType half_max = (ONE<<half_length);

				static const SizeType max_binary_power = (ONE<<(register_length-ONE));
			};
		}
	}
}

#undef BYTE_LENGTH
#undef TWO
#undef ONE
#undef ZERO

#endif
