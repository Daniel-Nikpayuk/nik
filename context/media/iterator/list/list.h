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

#ifndef CONTEXT_MEDIA_ITERATOR_LIST_H
#define CONTEXT_MEDIA_ITERATOR_LIST_H

#include"../functional/functional.h"

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
/*
			list:
				The minimal specification (axiomatic properties) of a list are:
				typedefs:
					value_type;
					const_/reference;
					const_/pointer;
					const_/iterator; // list iterators are random access (in grammar, not necessarily in cycles).
					size_type;
				constructors:
					list(size_type, const value_type &);
				accessors:
					const_/iterator begin()/ const;
					const_/iterator end()/ const;
					size_type size() const;
*/
	struct list
	{
/*
	constrain:
		Exists for situations where the interpreted list does not have any natural conversion mechanisms.
*/
		template<typename List>
		static typename List::const_iterator constrain(List & l, typename List::iterator in)
			{ return l.cbegin()+(in-l.begin()); }
/*
	coerce:
		Exists for situations where the interpreted list does not have any natural conversion mechanisms.
*/
		template<typename List>
		static typename List::iterator coerce(List & l, typename List::const_iterator in)
			{ return l.begin()+(in-l.cbegin()); }
/*
	shift_left:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename List>
		static typename List::iterator shift_left(List & l,
			typename List::const_iterator in, typename List::const_iterator end, typename List::size_type length)
				{ return bidirectional_iterator::assign(coerce(l, in)-length, in, end); }
/*
	shift_right:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename List>
		static typename List::iterator shift_right(List & l,
			typename List::const_iterator in, typename List::const_iterator end, typename List::size_type length)
				{ return bidirectional_iterator::reverse_assign(coerce(l, end)+length-1, end-1, in-1); }
/*
	grow:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename List>
		static typename List::iterator grow(List & l,
			typename List::const_iterator it, typename List::size_type length)
		{
			List u(l);
			typename List::const_iterator mid=u.begin()+(it-l.begin());
			l=List(l.size()+length);
			typename List::iterator rtn=bidirectional_iterator::assign(l.begin(), u.cbegin(), mid);
			bidirectional_iterator::assign(rtn+length, mid, u.cend());
			return rtn;
		}
/*
	shrink:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename List>
		static typename List::iterator shrink(List & l,
			typename List::const_iterator it, typename List::size_type length)
		{
			List u(l.size()-length);
			typename List::iterator mid=bidirectional_iterator::assign(u.begin(), l.cbegin(), it);
			bidirectional_iterator::assign(mid, it+length, l.cend());
			l=u;
			return l.begin()+(mid-u.begin());
		}
/*
	insert:
*/
		template<typename List>
		static typename List::iterator insert(List & l,
			typename List::const_iterator it, const typename List::value_type & value)
		{
			typename List::iterator rtn=grow(l, it, 1);
			*rtn=value;
			return rtn;
		}

/*
	The "&&" is a "move constructor". This function originally interpreted "&&" differently and needs to be changed.
*/
		template<typename List>
		static typename List::iterator insert(List & l,
			typename List::const_iterator it, typename List::value_type && value)
		{
			typename List::iterator rtn=grow(l, it, 1);
			&*rtn=value;
			return rtn;
		}

		template<typename List>
		static typename List::iterator insert(List & l, typename List::const_iterator it,
			typename List::size_type count, const typename List::value_type & value)
		{
			typename List::iterator rtn=grow(l, it, count);
			bidirectional_iterator::repeat(rtn, rtn+count, value);
			return rtn;
		}

		template<typename InputIterator, typename List>
		static typename List::iterator insert(List & l,
			typename List::const_iterator it, InputIterator first, InputIterator last)
		{
			typename List::iterator rtn=grow(l, it, last-first);
			bidirectional_iterator::assign(rtn, first, last);
			return rtn;
		}
/*
	erase:
*/
		template<typename List>
		static typename List::iterator erase(List & l, typename List::const_iterator it)
			{ return shrink(l, it, 1); }

		template<typename List>
		static typename List::iterator erase(List & l,
			typename List::const_iterator first, typename List::const_iterator last)
				{ return shrink(l, first, last-first); }
	};
   }
  }
 }
}

#endif
