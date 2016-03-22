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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_CHAIN_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_CHAIN_H

#include"../overload/overload.h"

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
/*
			chain:
				The minimal specification (axiomatic properties) of a chain are:
				typedefs:
					value_type;
					const_/reference;
					const_/pointer;
					const_/iterator; // chain iterators are random access (in grammar, not necessarily in cycles).
					size_type;
				constructors:
					chain(size_type, const value_type &);
				accessors:
					const_/iterator begin()/ const;
					const_/iterator end()/ const;
					size_type size() const;
*/
	struct chain
	{
/*
	constrain:
		Exists for situations where the interpreted chain does not have any natural conversion mechanisms.
*/
		template<typename Chain>
		static typename Chain::const_iterator constrain(Chain & l, typename Chain::iterator in)
			{ return l.cbegin()+(in-l.begin()); }
/*
	coerce:
		Exists for situations where the interpreted chain does not have any natural conversion mechanisms.
*/
		template<typename Chain>
		static typename Chain::iterator coerce(Chain & l, typename Chain::const_iterator in)
			{ return l.begin()+(in-l.cbegin()); }
/*
	shift_left:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename Chain>
		static typename Chain::iterator shift_left(Chain & l,
			typename Chain::const_iterator in, typename Chain::const_iterator end, typename Chain::size_type length)
				{ return bidirectional_iterator::assign(coerce(l, in)-length, in, end); }
/*
	shift_right:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename Chain>
		static typename Chain::iterator shift_right(Chain & l,
			typename Chain::const_iterator in, typename Chain::const_iterator end, typename Chain::size_type length)
				{ return bidirectional_iterator::reverse_assign(coerce(l, end)+length-1, end-1, in-1); }
/*
	grow:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename Chain>
		static typename Chain::iterator grow(Chain & l,
			typename Chain::const_iterator it, typename Chain::size_type length)
		{
			Chain u(l);
			typename Chain::const_iterator mid=u.begin()+(it-l.begin());
			l=Chain(l.size()+length);
			typename Chain::iterator rtn=bidirectional_iterator::assign(l.begin(), u.cbegin(), mid);
			bidirectional_iterator::assign(rtn+length, mid, u.cend());
			return rtn;
		}
/*
	shrink:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename Chain>
		static typename Chain::iterator shrink(Chain & l,
			typename Chain::const_iterator it, typename Chain::size_type length)
		{
			Chain u(l.size()-length);
			typename Chain::iterator mid=bidirectional_iterator::assign(u.begin(), l.cbegin(), it);
			bidirectional_iterator::assign(mid, it+length, l.cend());
			l=u;
			return l.begin()+(mid-u.begin());
		}
/*
	insert:
*/
		template<typename Chain>
		static typename Chain::iterator insert(Chain & l,
			typename Chain::const_iterator it, const typename Chain::value_type & value)
		{
			typename Chain::iterator rtn=grow(l, it, 1);
			*rtn=value;
			return rtn;
		}

		template<typename Chain>
		static typename Chain::iterator insert(Chain & l,
			typename Chain::const_iterator it, typename Chain::value_type && value)
		{
			typename Chain::iterator rtn=grow(l, it, 1);
			&*rtn=value;
			return rtn;
		}

		template<typename Chain>
		static typename Chain::iterator insert(Chain & l, typename Chain::const_iterator it,
			typename Chain::size_type count, const typename Chain::value_type & value)
		{
			typename Chain::iterator rtn=grow(l, it, count);
			bidirectional_iterator::repeat(rtn, rtn+count, value);
			return rtn;
		}

		template<typename InputIterator, typename Chain>
		static typename Chain::iterator insert(Chain & l,
			typename Chain::const_iterator it, InputIterator first, InputIterator last)
		{
			typename Chain::iterator rtn=grow(l, it, last-first);
			bidirectional_iterator::assign(rtn, first, last);
			return rtn;
		}
/*
	erase:
*/
		template<typename Chain>
		static typename Chain::iterator erase(Chain & l, typename Chain::const_iterator it)
			{ return shrink(l, it, 1); }

		template<typename Chain>
		static typename Chain::iterator erase(Chain & l,
			typename Chain::const_iterator first, typename Chain::const_iterator last)
				{ return shrink(l, first, last-first); }
	};
    }
   }
  }
 }
}

#endif
