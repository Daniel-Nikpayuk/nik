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

/*
	Ideally define the pointer before the structure, and define the memory structure in terms of the pointer,
	but given the constraints of C++ grammar it seems it must be done this way.

	Derivations of const_iterator from this codepoint require the container to be constant (this implicitly includes
	its value references as well as its linkages, depending on the data structure). The iterator itself is not constant.
	Regarding methods such as "insert" and "erase" that take const_iterators in the STL standard, the reason being is that
	the iterator itself might be intended to not modify the container, but passing it---and even calling in the first
	place---to methods such as "insert" imply the container itself is intended to be modifiable. In which case, the
	interpretation which is privileged is that the iterator serves as nothing more than communicating a position within
	the container (mediator). This is why "insert" and "erase" accept const_iterator.
*/

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
   namespace separator
   {
	template<typename SizeType>
	struct topos
	{
		typedef SizeType size_type;

		struct semiotic
		{
			#include"semiotic.cpp"
		};
	};
   }
  }
 }
}

