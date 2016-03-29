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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_ORDER_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_ORDER_H

#include"../../../../context/policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace extensionwise
    {
	template<typename SizeType>
	struct order
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

/*
	Reverses the order from [in, end), while maintaining method composability:
	The original "out" as input is the end pointer of the returned list.
	In practice this is usually a symbolic place-holding pointer.
*/
		struct reverse
		{
			template<typename WPointer, typename EWIterator>
			static void no_return(WPointer out, EWIterator end)
			{
				// does not destroy existing values held, only rearranges pointers relative to each other.
			}

			template<typename WPointer, typename EWIterator>
			static WPointer with_return(WPointer out, EWIterator end)
			{
				// does not destroy existing values held, only rearranges pointers relative to each other.

				return out;
			}

			template<typename WPointer, typename RIterator, typename ERIterator>
			static void no_return(WPointer out, RIterator in, ERIterator end)
			{
				while (in != end)
				{
					WPointer next=out;
					out=new WPointer();
					+out=next;
					*out=*in;
					++in;
				}
			}

			template<typename WPointer, typename RIterator, typename ERIterator>
			static WPointer with_return(WPointer out, RIterator in, ERIterator end)
			{
				while (in != end)
				{
					WPointer next=out;
					out=new WPointer();
					+out=next;
					*out=*in;
					++in;
				}

				return out;
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
