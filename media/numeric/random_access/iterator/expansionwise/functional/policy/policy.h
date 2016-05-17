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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXPANSIONWISE_FUNCTIONAL_POLICY_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXPANSIONWISE_FUNCTIONAL_POLICY_H

//#include"../arithmetic/arithmetic.h"
//#include"../order/order.h"
#include"../discrete/discrete.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
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
     namespace expansionwise
     {
      namespace functional
      {
/*
*/
	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;
/*
	forward:
*/
/*
		overload:
*/
			using fwd_over=forward::overload<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using fwd_over_unroll=typename fwd_over::template unroll<N, M, L>;
/*
		arithmetic:
			using fwd_arit=forward::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using fwd_arit_unroll=typename fwd_arit::template unroll<N, M, L>;
*/
/*
		discrete:
*/
			using fwd_disc=forward::discrete<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using fwd_disc_unroll=typename fwd_disc::template unroll<N, M, L>;
/*
	backward:
*/
/*
		overload:
*/
			using bwd_over=backward::overload<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bwd_over_unroll=typename bwd_over::template unroll<N, M, L>;
/*
		arithmetic:
			using bwd_arit=backward::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bwd_arit_unroll=typename bwd_arit::template unroll<N, M, L>;
*/
/*
		discrete:
*/
			using bwd_disc=backward::discrete<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bwd_disc_unroll=typename bwd_disc::template unroll<N, M, L>;
/*
	bidirectional:
*/
/*
		overload:
*/
			using bid_over=bidirectional::overload<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bid_over_unroll=typename bid_over::template unroll<N, M, L>;
/*
		arithmetic:
			using bid_arit=bidirectional::arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bid_arit_unroll=typename bid_arit::template unroll<N, M, L>;
*/
/*
		discrete:
*/
			using bid_disc=bidirectional::discrete<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using bid_disc_unroll=typename bid_disc::template unroll<N, M, L>;
	};
      }
     }
    }
   }
  }
 }
}

#endif
