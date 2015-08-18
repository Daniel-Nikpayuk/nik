/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_ITERATOR_FUNCTIONAL_H
#define CONTEXT_ITERATOR_FUNCTIONAL_H

/*
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
		namespace iterator
		{
			namespace forward
			{
				template<typename size_type>
				struct functional
				{

/************************************************************************************************************************/
//	forward iterator

/*
	Breaks for n < 0.

	Admittedly the most natural application is as reference by default, but as the (++) method could be user defined
	for side effects of some shared internal state, it's problematic to constrain this generic method unnecessarily.
*/
					template<typename Iterator>
					static void increment(Iterator out, size_type n)
						{ while (n--) ++out; }
/*
	Breaks for n < 0.

	Alternative is to code as "while (--n) ++out; return ++out;" which optimizes better but breaks for n <= 0.
*/
					template<typename Iterator>
					static Iterator left_increment(Iterator out, size_type n)
					{
						while (n--) ++out;
						return out;
					}
/*
	Breaks for n < 0.
*/
					template<typename Iterator>
					static Iterator right_increment(Iterator out, size_type n)
					{
						Iterator rtn(out);
						while (n--) ++out;
						return rtn;
					}
/*
	size:
*/
					template<typename InputIterator, typename TerminalIterator>
					static size_type size(InputIterator in, TerminalIterator end)
					{
						size_type length(0);
						while (in++ != end) ++length;
						return length;
					}
				};
			}

/************************************************************************************************************************/
//	backward iterator

			namespace backward
			{
				template<typename size_type>
				struct functional
				{
/*
	Breaks for n < 0.

	Admittedly the most natural application is as reference by default, but as the (++) method could be user defined
	for side effects of some shared internal state, it's problematic to constrain this generic method unnecessarily.
*/
					template<typename Iterator>
					static void decrement(Iterator out, size_type n)
						{ while (n--) --out; }
/*
	Breaks for n < 0.

	Alternative is to code as "while (--n) --out; return --out;" which optimizes better but breaks for n <= 0.
*/
					template<typename Iterator>
					static Iterator left_decrement(Iterator out, size_type n)
					{
						while (n--) --out;
						return out;
					}
/*
	Breaks for n < 0.
*/
					template<typename Iterator>
					static Iterator right_decrement(Iterator out, size_type n)
					{
						Iterator rtn(out);
						while (n--) --out;
						return rtn;
					}
/*
	size:
*/
					template<typename InputIterator, typename TerminalIterator>
					static size_type size(InputIterator in, TerminalIterator end)
					{
						size_type length(0);
						while (in-- != end) ++length;
						return length;
					}
				};
			}

/************************************************************************************************************************/
//	bidirectional iterator

			namespace bidirectional
			{
				template<typename size_type>
				struct functional
				{
				};
			}

/************************************************************************************************************************/
//	random access iterator

			namespace random_access
			{
				template<typename size_type>
				struct functional
				{
/*
	size:
		Breaks for end < in.
*/
					template<typename InputIterator, typename TerminalIterator>
					static size_type size(InputIterator in, TerminalIterator end)
						{ return end-in; }
				};
			}
		}
	}
}

#endif
