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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_POINTER_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_POINTER_H

#include"../overload/overload.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes an array pointer there is no need for these additional namespaces.
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
	template<typename SizeType>
	struct pointer
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		typedef forward::overload<size_type> fwd_over;
/*
	Not fully satisfied with the categorization or naming scheme within this library.
*/
		struct convert
		{
			template<typename WIterator, typename RIterator, typename EIterator>
			static void no_return(WIterator out, RIterator in, EIterator end)
			{
				while (in != end)
				{
					*out=(c_policy::unit::low_pass & *in);
					*++out=*in>>c_policy::unit::half::length;
					++out; ++in;
				}
			}

			template<typename WIterator, typename RIterator, typename EIterator>
			static WIterator with_return(WIterator out, RIterator in, EIterator end)
			{
				while (in != end)
				{
					*out=(c_policy::unit::low_pass & *in);
					*++out=*in>>c_policy::unit::half::length;
					++out; ++in;
				}

				return out;
			}

			struct half
			{
				template<typename WIterator, typename RIterator, typename EIterator>
				static void no_return(WIterator out, RIterator in, EIterator end)
				{
					while (in != end)
					{
						*out=*in;
						*out+=(*++in<<c_policy::unit::half::length);
						++out; ++in;
					}
				}

				template<typename WIterator, typename RIterator, typename EIterator>
				static WIterator with_return(WIterator out, RIterator in, EIterator end)
				{
					while (in != end)
					{
						*out=*in;
						*out+=(*++in<<c_policy::unit::half::length);
						++out; ++in;
					}

					return out;
				}
			};
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
/*
	Not fully satisfied with the categorization or naming scheme within this library.
*/
			struct convert
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
				{
					*out=(c_policy::unit::low_pass & *in);
					*++out=*in>>c_policy::unit::half::length;
					unroll<N-1>::convert::no_return(++out, ++in);
				}

				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
				{
					*out=(c_policy::unit::low_pass & *in);
					*++out=*in>>c_policy::unit::half::length;
					return unroll<N-1>::convert::with_return(++out, ++in);
				}

				struct half
				{
					template<typename WIterator, typename RIterator>
					static void no_return(WIterator out, RIterator in)
					{
						*out=*in;
						*out+=(*++in<<c_policy::unit::half::length);
						unroll<N-1>::convert::half::no_return(++out, ++in);
					}

					template<typename WIterator, typename RIterator>
					static WIterator with_return(WIterator out, RIterator in)
					{
						*out=*in;
						*out+=(*++in<<c_policy::unit::half::length);
						return unroll<N-1>::convert::half::with_return(++out, ++in);
					}
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
			struct convert
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
					{ }

				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
					{ return out; }

				struct half
				{
					template<typename WIterator, typename RIterator>
					static void no_return(WIterator out, RIterator in)
						{ }

					template<typename WIterator, typename RIterator>
					static WIterator with_return(WIterator out, RIterator in)
						{ return out; }
				};
			};
		};
	};
    }
   }
  }
 }
}

#endif
