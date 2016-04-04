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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_POINTER_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_POINTER_H

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
	struct pointer
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		struct clear
		{
			template<typename WPointer, typename ERPointer>
			static void no_return(WPointer out, ERPointer end)
				{ while (out != end) delete out++; }
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
			struct clear
			{
				template<typename WPointer, typename ERPointer>
				static void no_return(WPointer out, ERPointer end)
				{
					delete out++;
					unroll<N-1>::clear::no_return(out, end);
				}
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
			struct clear
			{
				template<typename WPointer, typename ERPointer>
				static void no_return(WPointer out, ERPointer end)
					{ }
			};
		};
	};

	template<typename SizeType>
	struct list_pointer
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
		};
	};

	template<typename SizeType>
	struct chain_pointer
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

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