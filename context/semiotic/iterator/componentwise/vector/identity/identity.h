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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_VECTOR_IDENTITY_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_VECTOR_IDENTITY_H

#include"../../pointer/policy/policy.h"

/*
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
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

		typedef pointer::policy<size_type> sicp_policy;

/*
	This method would have higher entropy without calling additional methods within [namely initialize()],
	unfortunately the nature of array allocation requires such additional calls.
*/
		struct copy
		{
/*
	Assumes out is uninitialized.
*/
			template<typename WVector, typename RVector>
			static void no_return(WVector & out, const RVector & in)
			{
				out.initialize(in.length);
				sicp_policy::fwd_over::assign::no_return(out.initial, in.initial, in.end());
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void no_return(WVector & out, RIterator in, ERIterator end)
			{
				out.initialize(end-in);
				sicp_policy::fwd_over::assign::no_return(out.initial, in, end);
			}

			struct shallow
			{
				template<typename WVector, typename RVector>
				static void no_return(WVector & out, const RVector & in)
				{
					out.initial=in.initial;
					out.length=in.length;
				}
			};
		};
/*
	Similar to resize but optimized to increase the size, and copy the existing array starting at pos.

	Assumes in is uninitialized.
*/
		struct grow
		{
			template<typename WVector>
			static void before(WVector & out, WVector & in, size_type length)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length+length);
				sicp_policy::fwd_over::assign::no_return(out.initial+length, in.initial, in.end());
				in.terminalize();
			}

			template<typename WVector>
			static void after(WVector & out, WVector & in, size_type length)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length+length);
				sicp_policy::fwd_over::assign::no_return(out.initial, in.initial, in.end());
				in.terminalize();
			}

			template<typename WVector>
			static void between(WVector & out, WVector & in, size_type length, size_type offset)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length+length);
				typename WVector::iterator out_middle, in_middle=in.initial+offset;
				out_middle=sicp_policy::fwd_over::assign::with_return(out.initial, in.initial, in_middle);
				sicp_policy::fwd_over::assign::no_return(out_middle+length, in_middle, in.end());
				in.terminalize();
			}
		};
/*
	Similar to resize but optimized to decrease the size, and copy the existing array starting at pos.

	Assumes in is uninitialized.
*/
		struct shrink
		{
			template<typename WVector>
			static void before(WVector & out, WVector & in, size_type length)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length-length);
				sicp_policy::fwd_over::assign::no_return(out.initial, in.initial+length, in.end());
				in.terminalize();
			}

			template<typename WVector>
			static void after(WVector & out, WVector & in, size_type length)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length-length);
				sicp_policy::fwd_over::assign::no_return(out.initial, in.initial, in.initial+out.length);
				in.terminalize();
			}

			template<typename WVector>
			static void between(WVector & out, WVector & in, size_type length, size_type offset)
			{
				copy::shallow::no_return(in, out);
				out.initialize(in.length-length);
				typename WVector::iterator out_middle, in_middle=in.initial+offset;
				out_middle=sicp_policy::fwd_over::assign::with_return(out.initial, in.initial, in_middle);
				sicp_policy::fwd_over::assign::no_return(out_middle, in_middle+length, in.end());
				in.terminalize();
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
