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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_POLICY_H
#define CONTEXT_SEMIOTIC_ITERATOR_POLICY_H

#include"../functional/functional.h"
#include"../componentwise/componentwise.h"
#include"../arithmetic/arithmetic.h"
//#include"../block/block.h"
//#include"../vector/vector.h"
//#include"../list/list.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the nested namespaces.
	2) in addition, if you look at the "fwd_arit_subroll" typedef ("using") declaration below for example,
		you will see it is also to ease the grammar constraints of C++ templates.
	3) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
/*
*/
	struct policy
	{
/*
	forward:
*/
/*
		functional:
*/
		template<typename SizeType>
		using fwd_func=forward::functional<SizeType>;
/*
		componentwise:
*/
		template<typename SizeType>
		using fwd_comp=forward::componentwise<SizeType>;

		template<typename SizeType, SizeType N>
		using fwd_comp_unroll=forward::componentwise<SizeType>::unroll<N>;
/*
		arithmetic:
*/
		template<typename SizeType>
		using fwd_arit=forward::arithmetic<SizeType>;

		template<typename SizeType, SizeType N>
		using fwd_arit_unroll=forward::arithmetic<SizeType>::unroll<N>;

		template<typename SizeType, SizeType N, SizeType M>
		using fwd_arit_subroll=typename forward::
			arithmetic<SizeType>::template unroll<N>::template subroll<M>;
/*
	backward:
*/
/*
		functional:
*/
		template<typename SizeType>
		using bwd_func=backward::functional<SizeType>;
/*
		componentwise:
*/
		template<typename SizeType>
		using bwd_comp=backward::componentwise<SizeType>;

		template<typename SizeType, SizeType N>
		using bwd_comp_unroll=backward::componentwise<SizeType>::unroll<N>;
/*
		arithmetic:
*/
		template<typename SizeType>
		using bwd_arit=backward::arithmetic<SizeType>;

		template<typename SizeType, SizeType N>
		using bwd_arit_unroll=backward::arithmetic<SizeType>::unroll<N>;
/*
	bidirectional:
*/
/*
		functional:
*/
		template<typename SizeType>
		using bid_func=bidirectional::functional<SizeType>;
/*
		componentwise:
*/
		template<typename SizeType>
		using bid_comp=bidirectional::componentwise<SizeType>;
/*
		arithmetic:
*/
		template<typename SizeType>
		using bid_arit=bidirectional::arithmetic<SizeType>;

		template<typename SizeType, SizeType N>
		using bid_arit_unroll=bidirectional::arithmetic<SizeType>::unroll<N>;

		template<typename SizeType, SizeType N, SizeType M>
		using bid_arit_subroll=typename bidirectional::
			arithmetic<SizeType>::template unroll<N>::template subroll<M>;
/*
	random_access:
*/
/*
		functional:
*/
		template<typename SizeType>
		using rnd_func=random_access::functional<SizeType>;
/*
		componentwise:
*/
/*
		recursive:
*/
/*
		arithmetic:
*/
	};
   }
  }
 }
}

#endif