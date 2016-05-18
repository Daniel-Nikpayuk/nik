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

#ifndef NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_FUNCTIONAL_DISCRETE_H
#define NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_FUNCTIONAL_DISCRETE_H

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.
*/

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
   namespace iterator
   {
    namespace extensionwise
    {
     namespace functional
     {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		#include"media.cpp"
	};
     }
    }
   }
  }
 }
}

#endif
