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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONAL_H
#define CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONAL_H

// overhead dependencies:

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
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

			template<typename WPointer, typename RPointer>
			static RPointer* reverse(RPointer t, const RPointer e)
			{
				*t=*e;
				while (e=+e) t=new RPointer(*e, t);
				return t;
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename RPointer>
			static void purge(RPointer t)
			{
				while (t)
				{
					RPointer p(t);
					t=+t;
					p.terminal();
				}
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename RPointer>
			static RPointer* terminalize(RPointer t)
			{
				while (+t)
				{
					RPointer p(t);
					t=+t;
					p.terminal();
				}
				return t;
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename RPointer>
			static RPointer* terminalize(RPointer t, const typename RPointer::value_type & v)
			{
				while (+t)
				{
					RPointer p(t);
					t=+t;
					p.terminal();
				}
				*t=v;
				return t;
			}

		struct repeat
		{
/*
*/
			template<typename WPointer, typename ValueType>
			static void no_return(WPointer out, size_type n, ValueType v)
			{
				while (n)
				{
					out=+out=WPointer::new_pointer();
					*out=v;
					--n;
				}
			}
/*
*/
			template<typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, size_type n, ValueType v)
			{
				while (n)
				{
					out=+out=WPointer::new_pointer();
					*out=v;
					--n;
				}

				return out;
			}
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
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	Convenience function. Type deduction fails with size_type.
*/
			template<typename size_type, typename RPointer>
			static size_type size(const RPointer first, const RPointer last)
			{
				size_type n(0);
				while ((first=+first) != last) ++n;
				return n;
			}
/*
	Attaches e to t in the following order: e -- t.

	Assumes 't' is existing "front", in which case -t is assumed '0'. nothing is assumed of +e
	before it is replaced---this leaves potential for memory leaks; burden is on coder.
*/
			template<typename WPointer, typename RPointer>
			static void attach0(RPointer t, RPointer e)
			{
				-t=e;
				+e=t;
			}
/*
	Attaches e to t in the following order: t -- e.

	Assumes 't' is existing "back", in which case +t is assumed '0'. nothing is assumed of -e
	before it is replaced---this leaves potential for memory leaks; burden is on coder.
*/
			template<typename WPointer, typename RPointer>
			static void attach1(RPointer t, RPointer e)
			{
				+t=e;
				-e=t;
			}
/*
	Attaches e to t as an "insert" operation---assumes -t != 0.
*/
			template<typename WPointer, typename RPointer>
			static void attach(RPointer t, RPointer e)
			{
				-+t=e;
				-e=-t;
				+e=t;
				-t=e;
			}
/*
	Swaps and returns what was originally there. May be useful in the future.
	Does not detach 't' from what was originally there resulting in a dangling pointer.

			template<typename RPointer>
			static RPointer* prepend(RPointer t, RPointer e)
			{
				+e=t;
				t=-t;
				+-t=e;
				return t;
			}

			template<typename RPointer>
			static RPointer* append(RPointer t, RPointer e)
			{
				-e=t;
				t=+t;
				t->+edge0=e;
				return t;
			}
*/
/*
		Construct the repeat value 'n' times in the direction of edge0.

		Notice it repeats before topos 't' (not including; prepend).
		Behaviour is undefined for n < 0 (more accurately it is an infinite loop).
		Different from topos1 version in that it has to bidirectionally link two nodes when adding new ones.
*/
			template<typename RPointer>
			static RPointer* rep0(RPointer t, size_type n, const typename RPointer::value_type & v)
			{
				while (n--) t=-t=new RPointer(v, 0, t);
				return t;
			}
/*
		Construct the repeat value 'n' times in the direction of edge1.

		Notice it repeats after topos 't' (not including; append).
		Behaviour is undefined for n < 0 (more accurately it is an infinite loop).
*/
			template<typename RPointer>
			static RPointer* rep1(RPointer t, size_type n, const typename RPointer::value_type & v)
			{
				while (n--) t=+t=new RPointer(v, t, 0);
				return t;
			}
/*
	Prepends 'e' to 't' (similar to attach0) but returns 'e' for convenience.

	Makes no assumptions about anything 't' or 'e' were previously attached to---potentially resulting in memory leaks.
*/
			template<typename WPointer, typename RPointer>
			static RPointer* prepend(RPointer t, RPointer e)
			{
				-t=e;
				+e=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then prepends to 't' while returning the new beginning of the chain.
	Makes use of first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename RPointer, typename Iterator>
			static RPointer* prepend(RPointer t, Iterator first, Iterator last)
			{
				RPointer initial=new RPointer(*first++,0,0), *current=initial;
				while (first != last) current=+current=new RPointer(*first++, current, 0);
				prepend(t, current);
				return initial;
			}
/*
	Same as above prepend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename RPointer, typename Iterator>
			static RPointer* prepend_count(RPointer t, size_type & count, Iterator first, Iterator last)
			{
				RPointer initial=new RPointer(*first++,0,0), *current=initial;
				for (++count; first != last; ++count) current=+current=new RPointer(*first++, current, 0);
				prepend(t, current);
				return initial;
			}
/*
	Creates a chain generated (deep copied) from first to last, then prepends to 't' while returning the new beginning of the chain.
	Different from the above in efficiency as it prepends directly to 't'. This requires last as a bidirectional iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename RPointer, typename Iterator>
			static RPointer* reverse_prepend(RPointer t, Iterator first, Iterator last)
			{
				while (last != first) t=-t=new RPointer(*--last, 0, t);
				return t;
			}
/*
	Same as above reverse_prepend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename RPointer, typename Iterator>
			static RPointer* reverse_prepend_count(RPointer t, size_type & count, Iterator first, Iterator last)
			{
				while (last != first)
				{
					t=-t=new RPointer(*--last, 0, t);
					++count;
				}
				return t;
			}
/*
	Appends 'e' to 't' (similar to attach1) but returns 'e' for convenience.

	Makes no assumptions about anything 't' or 'e' were previously attached to---potentially resulting in memory leaks.
*/
			template<typename WPointer, typename RPointer>
			static RPointer* append(RPointer t, RPointer e)
			{
				+t=e;
				-e=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then appends to 't' while returning the new end of the chain.
	This requires first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename RPointer, typename Iterator>
			static RPointer* append(RPointer t, Iterator first, Iterator last)
			{
				while (first != last) t=+t=new RPointer(*first++, t, 0);
				return t;
			}
/*
	Same as above append, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename RPointer, typename Iterator>
			static RPointer* append_count(RPointer t, size_type & count, Iterator first, Iterator last)
			{
				while (first != last)
				{
					t=+t=new RPointer(*first++, t, 0);
					++count;
				}
				return t;
			}
/*
	Inserts 'e' before 't' and returns 'e' as convenience.

	Assumes -t != 0. Nothing is assumed about +t or -e or +e. Potential for memory leaks.
*/
			template<typename WPointer, typename RPointer>
			static RPointer* impend(RPointer t, RPointer e)
			{
				t->+edge0=e;
				-e=-t;
				-t=e;
				+e=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then inserts before 't' while returning the new pointer to where 't'
	original was. This requires first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename RPointer, typename Iterator>
			static RPointer* impend(RPointer t, Iterator first, Iterator last)
			{
				RPointer initial=-t, *current=initial;
				while (first != last) current=+current=new RPointer(*first++, current, 0);
				attach1(current, t);
				return +initial;
			}
/*
	Same as above impend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename RPointer, typename Iterator>
			static RPointer* impend_count(RPointer t, size_type & count, Iterator first, Iterator last)
			{
				RPointer initial=-t, *current=initial;
				while (first != last)
				{
					current=+current=new RPointer(*first++, current, 0);
					++count;
				}
				attach1(current, t);
				return +initial;
			}
/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/
			template<typename RPointer>
			static RPointer* deject(RPointer t)
			{
				t=+t;
				(-t).terminal();
				-t=0;
				return t;
			}
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename RPointer>
			static RPointer* deject(RPointer first, RPointer last)
			{
				-last=0;
				while ((first=+first) != last) (-first).terminal();
				(-first).terminal();
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename RPointer>
			static RPointer* deject_count(size_type & count, RPointer first, RPointer last)
			{
				for (--count; (first=+first) != last; --count) (-first).terminal();
				(-first).terminal();
				-last=0;
				return last;
			}
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename RPointer>
			static RPointer* reverse_deject(RPointer first, RPointer last)
			{
				RPointer current=last;
				while (current=-current != first) (+current).terminal();
				current.terminal();
				-last=0;
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename RPointer>
			static RPointer* reverse_deject_count(size_type & count, RPointer first, RPointer last)
			{
				RPointer current=last;
				for (--count; current=-current != first; --count) (+current).terminal();
				current.terminal();
				-last=0;
				return last;
			}
/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
*/
			template<typename RPointer>
			static RPointer* reject(RPointer t)
			{
				t=-t;
				(+t).terminal();
				+t=0;
				return t;
			}
/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename RPointer>
			static RPointer* reject(RPointer first, RPointer last)
			{
				RPointer rtn=-first;
				+rtn=0;
				while ((first=+first) != last) (-first).terminal();
				(-first).terminal();
				first.terminal();
				return rtn;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename RPointer>
			static RPointer* reject_count(size_type & count, RPointer first, RPointer last)
			{
				RPointer rtn=-first;
				+rtn=0;
				for (--count; (first=+first) != last; --count) (-first).terminal();
				(-first).terminal();
				first.terminal();
				return rtn;
			}
/*
	Erases at location of 't' and returns the new pointer at that same location.

	Assumes -t != 0 and +t != 0.
*/
			template<typename RPointer>
			static RPointer* eject(RPointer t)
			{
				RPointer rtn=+t;
				t->+edge0=rtn;
				-rtn=-t;
				t.terminal();
				return rtn;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename RPointer>
			static RPointer* eject(RPointer first, RPointer last)
			{
				RPointer initial=-first;
				while ((first=+first) != last) (-first).terminal();
				(-first).terminal();
				attach1(initial, last);
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename RPointer>
			static RPointer* eject_count(size_type & count, RPointer first, RPointer last)
			{
				RPointer initial=-first;
				for (--count; (first=+first) != last; --count) (-first).terminal();
				(-first).terminal();
				attach1(initial, last);
				return last;
			}

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
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
    }

/************************************************************************************************************************/

    namespace random_access
    {
	template<typename SizeType>
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
    }
   }
  }
 }
}

#endif
