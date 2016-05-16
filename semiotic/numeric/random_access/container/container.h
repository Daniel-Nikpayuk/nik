/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_CONTAINER_H
#define NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_CONTAINER_H

namespace nik
{
 namespace semiotic
 {
  namespace numeric
  {
   namespace random_access
   {
	template<typename ContainerType, typename ValueType, typename SizeType>
	struct container
	{
		typedef ContainerType type;
		typedef ContainerType* address;

		typedef ValueType value_type;
		typedef ValueType& reference;
		typedef ValueType const & const_reference;
		typedef ValueType* pointer;
		typedef ValueType const * const_pointer;

		typedef SizeType size_type;
	};
   }
  }
 }
}

#endif
