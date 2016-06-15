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

#ifndef NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_COMPONENTWISE_FUNCTIONAL_DISCRETE_H
#define NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_COMPONENTWISE_FUNCTIONAL_DISCRETE_H

#include"../../../policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes an array pointer there is no need for these additional namespaces.

	Keep in mind any method categorized here specifically does not act on the dereferenced values of the pointer,
	only the pointer itself.
*/

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
   namespace iterator
   {
    namespace componentwise
    {
     namespace functional
     {
      namespace forward
      {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::policy<SizeType>::nricf snricf_policy;

		struct semiotic
		{
			#include"forward_semiotic.cpp"
		};
	};
      }

      namespace backward
      {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::policy<SizeType>::nricf snricf_policy;

		struct semiotic
		{
			#include"backward_semiotic.cpp"
		};
	};
      }

      namespace bidirectional
      {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::policy<SizeType>::nricf snricf_policy;

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

      namespace random_access
      {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::policy<SizeType>::nricf snricf_policy;

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
