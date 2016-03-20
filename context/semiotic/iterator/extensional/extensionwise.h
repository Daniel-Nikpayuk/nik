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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_H
#define CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_H

// overhead dependencies:

#include"extensionwise_macro.h"

#include"../../../context/policy/policy.h"

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename SizeType, SizeType N>
	struct extensionwise
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		struct repeat
		{
			no_return_0(=)

			with_return_0(=)
		};

		struct assign
		{
/*
*/
			template<typename WPointer, typename RIterator, typename ERIterator>
			static void no_return(WPointer out, RIterator in, ERIterator end)
			{
				while (in != end)
				{
					out=+out=WPointer::new_pointer();
					*out=*in;
					++out; ++in;
				}
			}

			template<typename WPointer, typename RIterator, typename ERIterator>
			static WPointer with_return(WPointer out, RIterator in, ERIterator end)
			{
				while (in != end)
				{
					out=+out=WPointer::new_pointer();
					*out=*in;
					++out; ++in;
				}

				return out;
			}
		};
	};
    }

/************************************************************************************************************************/

    namespace backward
    {
	template<typename SizeType>
	struct extensionwise
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		struct repeat
		{
		};

		struct assign
		{
		};
	};
    }

/************************************************************************************************************************/

    namespace bidirectional
    {
	template<typename SizeType>
	struct extensionwise
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
    }

/************************************************************************************************************************/

    namespace random_access
    {
	template<typename SizeType>
	struct extensionwise
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
    }
   }
  }
 }
}

#undef CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_MACRO_H

#endif
