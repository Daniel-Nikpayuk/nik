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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_FUNCTIONAL_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_FUNCTIONAL_H

#include"../../../context/policy/policy.h"

/*
	I haven't fully decided what to do with this class just yet.
	I'm sure I need it as a generic iterator overhead class,
	but until I actually apply it in practice, the code won't become stabalized.

	For iterators in general, references are a derived type,
	but for compatibility with pointers no specific instance of a derived type is assumed.

	Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
	entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
*/

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
	template<typename SizeType>
	struct functional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

/************************************************************************************************************************/
//	forward iterator

/*
	increments out by n times.

	Breaks semantically for n < 0.

	Admittedly the most natural application is as reference by default, but as the (++) method could be user defined
	for side effects of some shared internal state, it's problematic to constrain this generic method unnecessarily.
*/
		struct left_increment
		{
			template<typename Iterator>
			static void no_return(Iterator out, size_type n)
			{
				while (n)
				{
					++out;
					--n;
				}
			}

			template<typename Iterator>
			static Iterator with_return(Iterator out, size_type n)
			{
				while (n)
				{
					++out;
					--n;
				}

				return out;
			}
		};
/*
	increments out by n times.

	Breaks semantically for n < 0.
*/
		template<typename WIterator, typename RIterator>
		static RIterator right_increment(WIterator out, RIterator in, size_type n)
		{
			while (n)
			{
				out++;
				--n;
			}

			return in;
		}
/*
	size:

		Returns the distance between in and end.
*/
		template<typename RIterator, typename EIterator>
		static size_type size(RIterator in, EIterator end, size_type length)
		{
			while (in != end)
			{
				++length;
				++in;
			}

			return length;
		}
	};
    }

/************************************************************************************************************************/
//	backward iterator

    namespace backward
    {
	template<typename SizeType>
	struct functional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	decrements out by n times.

	Breaks semantically for n < 0.

	Admittedly the most natural application is as reference by default, but as the (++) method could be user defined
	for side effects of some shared internal state, it's problematic to constrain this generic method unnecessarily.
*/
		template<typename Iterator>
		static void decrement(Iterator out, size_type n)
		{
			while (n)
			{
				--out;
				--n;
			}
		}
/*
	decrements out by n times.

	Breaks semantically for n < 0.

	Alternative is to code as "while (--n) --out; return --out;" which optimizes better but breaks for n <= 0.
*/
		template<typename Iterator>
		static Iterator left_decrement(Iterator out, size_type n) { while (n--) --out; return out; }
/*
	decrements out by n times.

	Breaks semantically for n < 0.
*/
		template<typename WIterator, typename RIterator>
		static RIterator right_decrement(WIterator out, RIterator in, size_type n)
			{ while (n--) --out; return in; }
/*
	size:

		Returns the distance between in and end.
*/
		template<typename RIterator, typename EIterator>
		static size_type size(RIterator in, EIterator end, size_type length)
			{ while (in-- != end) ++length; return length; }
	};
    }

/************************************************************************************************************************/
//	bidirectional iterator

    namespace bidirectional
    {
	template<typename SizeType>
	struct functional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
    }

/************************************************************************************************************************/
//	random access iterator

    namespace random_access
    {
	template<typename SizeType>
	struct functional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	size:
		Returns the distance between in and end.

		Breaks for end < in.
*/
		template<typename RIterator, typename EIterator>
		static size_type size(RIterator in, EIterator end) { return end-in; }
	};
    }
   }
  }
 }
}

#endif
