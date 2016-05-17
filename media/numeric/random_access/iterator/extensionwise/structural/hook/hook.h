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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_STRUCTURAL_HOOK_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_STRUCTURAL_HOOK_H

#include"../../../../../../semiotic/traits/traits.h"

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace iterator
    {
     namespace extensionwise
     {
      namespace structural
      {
	#define HOOK_SIZE 2

	template<typename T, typename SizeType=size_t>
	using hook=typename semiotic::traits<SizeType>::nri::template node<T, HOOK_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_hook=typename semiotic::traits<SizeType>::nri::template const_node<T, HOOK_SIZE>;

	#undef HOOK_SIZE
      }
     }
    }
   }
  }
 }
}

#endif
