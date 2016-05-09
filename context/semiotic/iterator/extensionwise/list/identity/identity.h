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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H

#include"../../pointer/policy/policy.h"

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
     namespace list
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef pointer::policy<size_type> sitp_policy;
			
		struct initialize
		{
			struct after
			{
/*
	Assumes out is uninitialized.
*/
				template<typename WList>
				static void no_return(WList & out)
				{
					out.terminal=new typename WList::node;
					out.initial=new typename WList::node;
					+out.initial=out.terminal;
				}
			};
		};
/*
	These methods have higher entropy by calling fewer functions within, but for better composability
	it is better policy to assume out is uninitialized.
*/
		struct copy
		{
/*
	Assumes out is uninitialized.
*/
			template<typename WList, typename RList>
			static void no_return(WList & out, const RList & in)
			{
				out.initialize();
				out.terminal=sitp_policy::fwd_over::assign::template
					with_return<typename WList::node>(out.terminal, in.initial, in.terminal);
			}

			struct before
			{
/*
	Assumes out is uninitialized.
*/
				template<typename WList, typename RIterator, typename ERIterator>
				static void no_return(WList & out, RIterator in, ERIterator end)
				{
					out.initialize();
					out.terminal=sitp_policy::disc::copy::before::template
						with_return<typename WList::node>(out.terminal, in, end);
				}
			};

			struct after
			{
/*
	Assumes out is uninitialized.
*/
				template<typename WList, typename RList>
				static void no_return(WList & out, const RList & in)
				{
					initialize::after::no_return(out);
					out.terminal=sitp_policy::fwd_over::assign::template
						with_return<typename WList::node>(out.terminal, +in.initial, in.terminal);
				}
			};

			struct shallow
			{
				template<typename WList, typename RList>
				static void no_return(WList & out, const RList & in)
				{
					out.initial=in.initial;
					out.terminal=in.terminal;
				}
			};
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
