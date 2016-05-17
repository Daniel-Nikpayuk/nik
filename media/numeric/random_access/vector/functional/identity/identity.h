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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_VECTOR_FUNCTIONAL_IDENTITY_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_VECTOR_FUNCTIONAL_IDENTITY_H

#include"../../../../../../semiotic/policy/policy.h"

/*
	There is higher entropy in letting the compiler type-deduce things like "ValueType" even though
	they may be determined by the given Vector type itself. It is assumed during compile-time these
	will be aligned to match up.
*/

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace vector
    {
     namespace functional
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef semiotic::policy<size_type>::nricf snricf_policy;
		typedef semiotic::policy<size_type>::nrvf snrvf_policy;

		struct insert
		{
			// prepend:

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, ValueType value)
				{ *snrvf_policy::iden::grow::before::with_return(out, WVector(), 1)=value; }

			template<typename WVector, typename ValueType>
			static void prepend(WVector & out, size_type count, ValueType value)
			{
				snrvf_policy::iden::grow::before::no_return(out, WVector(), count);
				snricf_policy::fwd_over::repeat::no_return(out.initial, count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void prepend(WVector & out, RIterator in, ERIterator end)
			{
				snrvf_policy::iden::grow::before::no_return(out, WVector(), end-in);
				snricf_policy::fwd_over::assign::no_return(out.initial, in, end);
			}

			// append:

			// impend:

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, ValueType value)
			{
				snrvf_policy::iden::grow::between::with_return(out, WVector(), 1, offset)=value;
			}

			template<typename WVector, typename ValueType>
			static void impend(WVector & out, size_type offset, size_type count, ValueType value)
			{
				snricf_policy::fwd_over::repeat::no_return(
					snrvf_policy::iden::grow::between::with_return(out, WVector(), count, offset),
					count, value);
			}

			template<typename WVector, typename RIterator, typename ERIterator>
			static void impend(WVector & out, size_type offset, RIterator in, ERIterator end)
			{
				snricf_policy::fwd_over::assign::no_return(
					snrvf_policy::iden::grow::between::with_return(out, WVector(), end-in, offset),
					in, end);
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
