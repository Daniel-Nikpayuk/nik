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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_FUNCTIONAL_DISCRETE_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_FUNCTIONAL_DISCRETE_H

#include"../../../../../../../semiotic/numeric/random_access/iterator/extensionwise/functional/policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.

	Keep in mind any method categorized here specifically does not act on the dereferenced values of the pointer,
	only the pointer itself.
*/

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
      namespace functional
      {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::numeric::random_access::iterator::extensionwise::functional::policy<SizeType> snritf_policy;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
		};
	};
      }
     }
    }
   }
  }
 }
}

#endif
