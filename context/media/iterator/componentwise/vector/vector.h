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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_VECTOR_H
#define NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_VECTOR_H

#include"../../../../context/policy/policy.h"
#include"../../../../semiotic/iterator/componentwise/policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes an array pointer there is no need for these additional namespaces.

	Keep in mind any method categorized here specifically does not act on the dereferenced values of the pointer,
	only the pointer itself.
*/

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
    namespace componentwise
    {
	template<typename SizeType>
	struct vector
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<size_type> s_comp_policy;

		struct insert
		{
			// prepend:

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, ValueType value)
			{
				WVector tmp;
				*s_comp_policy::vtr::grow::before(out, tmp, 1)=value;
			}

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, size_type count, ValueType value)
			{
				WVector tmp;
				s_comp_policy::vtr::grow::before(out, tmp, count);
				s_comp_policy::fwd_over::repeat::no_return(out.initial, count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void prepend(WVector & out, RIterator in, ERIterator end)
			{
				WVector tmp;
				s_comp_policy::vtr::grow::before(out, tmp, end-in);
				s_comp_policy::fwd_over::assign::no_return(out.initial, in, end);
			}

			// append:

			// impend:

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, ValueType value)
			{
				WVector tmp;
				s_comp_policy::vtr::grow::between(out, tmp, 1, offset);
				*(out.initial+offset)=value;
			}

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, size_type count, ValueType value)
			{
				WVector tmp;
				s_comp_policy::vtr::grow::between(out, tmp, count, offset);
				s_comp_policy::fwd_over::repeat::no_return(out.initial+offset, count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void impend(WVector & out, size_type offset, RIterator in, ERIterator end)
			{
				WVector tmp;
				s_comp_policy::vtr::grow::between(out, tmp, end-in, offset);
				s_comp_policy::fwd_over::assign::no_return(out.initial+offset, in, end);
			}
		};

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

#endif
