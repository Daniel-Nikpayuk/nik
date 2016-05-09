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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_VECTOR_IDENTITY_H
#define NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_VECTOR_IDENTITY_H

#include"../../../../../semiotic/iterator/componentwise/pointer/policy/policy.h"
#include"../../../../../semiotic/iterator/componentwise/vector/policy/policy.h"

/*
	There is higher entropy in letting the compiler type-deduce things like "ValueType" even though
	they may be determined by the given Vector type itself. It is assumed during compile-time these
	will be aligned to match up.
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
     namespace vector
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef semiotic::iterator::componentwise::pointer::policy<size_type> sicp_policy;
		typedef semiotic::iterator::componentwise::vector::policy<size_type> sicv_policy;

		struct insert
		{
			// prepend:

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, ValueType value)
			{
				WVector tmp;
				*sicv_policy::iden::grow::before(out, tmp, 1)=value;
			}

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, size_type count, ValueType value)
			{
				WVector tmp;
				sicv_policy::iden::grow::before(out, tmp, count);
				sicp_policy::fwd_over::repeat::no_return(out.initial, count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void prepend(WVector & out, RIterator in, ERIterator end)
			{
				WVector tmp;
				sicv_policy::iden::grow::before(out, tmp, end-in);
				sicp_policy::fwd_over::assign::no_return(out.initial, in, end);
			}

			// append:

			// impend:

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, ValueType value)
			{
				WVector tmp;
				sicv_policy::iden::grow::between(out, tmp, 1, offset);
				*(out.initial+offset)=value;
			}

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, size_type count, ValueType value)
			{
				WVector tmp;
				sicv_policy::iden::grow::between(out, tmp, count, offset);
				sicp_policy::fwd_over::repeat::no_return(out.initial+offset, count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void impend(WVector & out, size_type offset, RIterator in, ERIterator end)
			{
				WVector tmp;
				sicv_policy::iden::grow::between(out, tmp, end-in, offset);
				sicp_policy::fwd_over::assign::no_return(out.initial+offset, in, end);
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
}

#endif
