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
	template<typename SizeType>
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
*/
			template<typename Topos>
			static void attach0(Topos *t, Topos *e) { t->edge0=e; }
/*
*/
			template<typename Topos>
			static Topos* append(Topos *t, Topos *e) { return t->edge0=e; }
/*
		Repeat by prepending to 't'.
		Behaviour is undefined for n < 0.
*/
			template<typename Topos, typename SizeType>
			static Topos* rep(Topos *t, SizeType n, const typename Topos::value_type & v)
			{
				while (n--) t=new Topos(v, t);
				return t;
			}
/*
		Repeat in the direction of edge0. Notice it repeats after topos 't' (not including).
		Behaviour is undefined for n < 0.
*/
			template<typename Topos, typename SizeType>
			static Topos* rep0(Topos *t, SizeType n, const typename Topos::value_type & v)
			{
				while (n--) t=t->edge0=new Topos(v, t);
				return t;
			}
/*
*/
			template<typename Topos>
			static Topos* reverse(Topos *t, const Topos *e)
			{
				t->value=e->value;
				while (e=e->edge0) t=new Topos(e->value, t);
				return t;
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename Topos>
			static void purge(Topos *t)
			{
				while (t)
				{
					Topos *p(t);
					t=t->edge0;
					delete p;
				}
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename Topos>
			static Topos* terminalize(Topos *t)
			{
				while (t->edge0)
				{
					Topos *p(t);
					t=t->edge0;
					delete p;
				}
				return t;
			}
/*
	I've used initialization and scope reducation to optimize.
*/
			template<typename Topos>
			static Topos* terminalize(Topos *t, const typename Topos::value_type & v)
			{
				while (t->edge0)
				{
					Topos *p(t);
					t=t->edge0;
					delete p;
				}
				t->value=v;
				return t;
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

    namespace backward
    {
	template<typename SizeType>
	struct extensional
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	Convenience function. Type deduction fails with SizeType.
*/
			template<typename SizeType, typename Topos>
			static SizeType size(const Topos *first, const Topos *last)
			{
				SizeType n(0);
				while ((first=first->edge1) != last) ++n;
				return n;
			}
/*
	Attaches e to t in the following order: e -- t.

	Assumes 't' is existing "front", in which case t->edge0 is assumed '0'. nothing is assumed of e->edge1
	before it is replaced---this leaves potential for memory leaks; burden is on coder.
*/
			template<typename Topos>
			static void attach0(Topos *t, Topos *e)
			{
				t->edge0=e;
				e->edge1=t;
			}
/*
	Attaches e to t in the following order: t -- e.

	Assumes 't' is existing "back", in which case t->edge1 is assumed '0'. nothing is assumed of e->edge0
	before it is replaced---this leaves potential for memory leaks; burden is on coder.
*/
			template<typename Topos>
			static void attach1(Topos *t, Topos *e)
			{
				t->edge1=e;
				e->edge0=t;
			}
/*
	Attaches e to t as an "insert" operation---assumes t->edge0 != 0.
*/
			template<typename Topos>
			static void attach(Topos *t, Topos *e)
			{
				t->edge0->edge1=e;
				e->edge0=t->edge0;
				e->edge1=t;
				t->edge0=e;
			}
/*
	Swaps and returns what was originally there. May be useful in the future.
	Does not detach 't' from what was originally there resulting in a dangling pointer.

			template<typename Topos>
			static Topos* prepend(Topos *t, Topos *e)
			{
				e->edge1=t;
				t=t->edge0;
				t->edge1->edge0=e;
				return t;
			}

			template<typename Topos>
			static Topos* append(Topos *t, Topos *e)
			{
				e->edge0=t;
				t=t->edge1;
				t->edge0->edge1=e;
				return t;
			}
*/
/*
		Construct the repeat value 'n' times in the direction of edge0.

		Notice it repeats before topos 't' (not including; prepend).
		Behaviour is undefined for n < 0 (more accurately it is an infinite loop).
		Different from topos1 version in that it has to bidirectionally link two nodes when adding new ones.
*/
			template<typename Topos, typename SizeType>
			static Topos* rep0(Topos *t, SizeType n, const typename Topos::value_type & v)
			{
				while (n--) t=t->edge0=new Topos(v, 0, t);
				return t;
			}
/*
		Construct the repeat value 'n' times in the direction of edge1.

		Notice it repeats after topos 't' (not including; append).
		Behaviour is undefined for n < 0 (more accurately it is an infinite loop).
*/
			template<typename Topos, typename SizeType>
			static Topos* rep1(Topos *t, SizeType n, const typename Topos::value_type & v)
			{
				while (n--) t=t->edge1=new Topos(v, t, 0);
				return t;
			}
/*
	Prepends 'e' to 't' (similar to attach0) but returns 'e' for convenience.

	Makes no assumptions about anything 't' or 'e' were previously attached to---potentially resulting in memory leaks.
*/
			template<typename Topos>
			static Topos* prepend(Topos *t, Topos *e)
			{
				t->edge0=e;
				e->edge1=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then prepends to 't' while returning the new beginning of the chain.
	Makes use of first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename Topos, typename Iterator>
			static Topos* prepend(Topos *t, Iterator first, Iterator last)
			{
				Topos *initial=new Topos(*first++,0,0), *current=initial;
				while (first != last) current=current->edge1=new Topos(*first++, current, 0);
				prepend(t, current);
				return initial;
			}
/*
	Same as above prepend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename Topos, typename SizeType, typename Iterator>
			static Topos* prepend_count(Topos *t, SizeType & count, Iterator first, Iterator last)
			{
				Topos *initial=new Topos(*first++,0,0), *current=initial;
				for (++count; first != last; ++count) current=current->edge1=new Topos(*first++, current, 0);
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
			template<typename Topos, typename Iterator>
			static Topos* reverse_prepend(Topos *t, Iterator first, Iterator last)
			{
				while (last != first) t=t->edge0=new Topos(*--last, 0, t);
				return t;
			}
/*
	Same as above reverse_prepend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename Topos, typename SizeType, typename Iterator>
			static Topos* reverse_prepend_count(Topos *t, SizeType & count, Iterator first, Iterator last)
			{
				while (last != first)
				{
					t=t->edge0=new Topos(*--last, 0, t);
					++count;
				}
				return t;
			}
/*
	Appends 'e' to 't' (similar to attach1) but returns 'e' for convenience.

	Makes no assumptions about anything 't' or 'e' were previously attached to---potentially resulting in memory leaks.
*/
			template<typename Topos>
			static Topos* append(Topos *t, Topos *e)
			{
				t->edge1=e;
				e->edge0=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then appends to 't' while returning the new end of the chain.
	This requires first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename Topos, typename Iterator>
			static Topos* append(Topos *t, Iterator first, Iterator last)
			{
				while (first != last) t=t->edge1=new Topos(*first++, t, 0);
				return t;
			}
/*
	Same as above append, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename Topos, typename SizeType, typename Iterator>
			static Topos* append_count(Topos *t, SizeType & count, Iterator first, Iterator last)
			{
				while (first != last)
				{
					t=t->edge1=new Topos(*first++, t, 0);
					++count;
				}
				return t;
			}
/*
	Inserts 'e' before 't' and returns 'e' as convenience.

	Assumes t->edge0 != 0. Nothing is assumed about t->edge1 or e->edge0 or e->edge1. Potential for memory leaks.
*/
			template<typename Topos>
			static Topos* impend(Topos *t, Topos *e)
			{
				t->edge0->edge1=e;
				e->edge0=t->edge0;
				t->edge0=e;
				e->edge1=t;
				return e;
			}
/*
	Creates a chain generated (deep copied) from first to last, then inserts before 't' while returning the new pointer to where 't'
	original was. This requires first as a forward iterator.

	Note: Regarding design decisions, you either check if first == last here, or in code calling this method.
	Given these low level generic methods privilege efficiency over safety checks, it makes more sense to assume first != last
	(otherwise you have to consider seperate cases, which is effectively a safety check from this specification.
*/
			template<typename Topos, typename Iterator>
			static Topos* impend(Topos *t, Iterator first, Iterator last)
			{
				Topos *initial=t->edge0, *current=initial;
				while (first != last) current=current->edge1=new Topos(*first++, current, 0);
				attach1(current, t);
				return initial->edge1;
			}
/*
	Same as above impend, but additionally "count"s the length between first and last as a side-effect (reference).
*/
			template<typename Topos, typename SizeType, typename Iterator>
			static Topos* impend_count(Topos *t, SizeType & count, Iterator first, Iterator last)
			{
				Topos *initial=t->edge0, *current=initial;
				while (first != last)
				{
					current=current->edge1=new Topos(*first++, current, 0);
					++count;
				}
				attach1(current, t);
				return initial->edge1;
			}
/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/
			template<typename Topos>
			static Topos* deject(Topos *t)
			{
				t=t->edge1;
				delete t->edge0;
				t->edge0=0;
				return t;
			}
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename Topos, typename SizeType>
			static Topos* deject(Topos *first, Topos *last)
			{
				last->edge0=0;
				while ((first=first->edge1) != last) delete first->edge0;
				delete first->edge0;
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename Topos, typename SizeType>
			static Topos* deject_count(SizeType & count, Topos *first, Topos *last)
			{
				for (--count; (first=first->edge1) != last; --count) delete first->edge0;
				delete first->edge0;
				last->edge0=0;
				return last;
			}
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename Topos, typename SizeType>
			static Topos* reverse_deject(Topos *first, Topos *last)
			{
				Topos *current=last;
				while (current=current->edge0 != first) delete current->edge1;
				delete current;
				last->edge0=0;
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename Topos, typename SizeType>
			static Topos* reverse_deject_count(SizeType & count, Topos *first, Topos *last)
			{
				Topos *current=last;
				for (--count; current=current->edge0 != first; --count) delete current->edge1;
				delete current;
				last->edge0=0;
				return last;
			}
/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
*/
			template<typename Topos>
			static Topos* reject(Topos *t)
			{
				t=t->edge0;
				delete t->edge1;
				t->edge1=0;
				return t;
			}
/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename Topos>
			static Topos* reject(Topos *first, Topos *last)
			{
				Topos *rtn=first->edge0;
				rtn->edge1=0;
				while ((first=first->edge1) != last) delete first->edge0;
				delete first->edge0;
				delete first;
				return rtn;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename Topos, typename SizeType>
			static Topos* reject_count(SizeType & count, Topos *first, Topos *last)
			{
				Topos *rtn=first->edge0;
				rtn->edge1=0;
				for (--count; (first=first->edge1) != last; --count) delete first->edge0;
				delete first->edge0;
				delete first;
				return rtn;
			}
/*
	Erases at location of 't' and returns the new pointer at that same location.

	Assumes t->edge0 != 0 and t->edge1 != 0.
*/
			template<typename Topos>
			static Topos* eject(Topos *t)
			{
				Topos *rtn=t->edge1;
				t->edge0->edge1=rtn;
				rtn->edge0=t->edge0;
				delete t;
				return rtn;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename Topos>
			static Topos* eject(Topos *first, Topos *last)
			{
				Topos *initial=first->edge0;
				while ((first=first->edge1) != last) delete first->edge0;
				delete first->edge0;
				attach1(initial, last);
				return last;
			}
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/
			template<typename Topos, typename SizeType>
			static Topos* eject_count(SizeType & count, Topos *first, Topos *last)
			{
				Topos *initial=first->edge0;
				for (--count; (first=first->edge1) != last; --count) delete first->edge0;
				delete first->edge0;
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
