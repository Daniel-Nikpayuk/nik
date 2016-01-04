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

#ifndef CONTEXT_MEDIA_ITERATOR_VECTOR_H
#define CONTEXT_MEDIA_ITERATOR_VECTOR_H

#include"../functional/functional.h"

/*
	As far as I've read, when defined inside a class declaration, member functions are given the inline hint by default.
	As such I have not included it in addition to the static keyword.
*/

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
/*
			vector:
				The minimal specification (axiomatic properties) of a vector are:
				typedefs:
					value_type;
					const_/reference;
					const_/pointer;
					const_/iterator; // vector iterators are random access.
					size_type;
				constructors:
					vector(size_type); // effectively an abstraction of "new array[n]"
				accessors:
					vector[size_type];
					const_/iterator begin()/ const;
					const_/iterator end()/ const;
					size_type size() const;
*/
	struct vector
	{
/*
	constrain:
		Exists for situations where the interpreted vector does not have any natural conversion mechanisms.
*/
		template<typename Vector>
		static typename Vector::const_iterator constrain(Vector & v, typename Vector::iterator in)
			{ return v.cbegin()+(in-v.begin()); }
/*
	coerce:
		Exists for situations where the interpreted vector does not have any natural conversion mechanisms.

		Try const_cast<>() as a potentially less expensive alternative.
*/
		template<typename Vector>
		static typename Vector::iterator coerce(Vector & v, typename Vector::const_iterator in)
			{ return v.begin()+(in-v.cbegin()); }
/*
	shift_left:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename Vector>
		static typename Vector::iterator shift_left(Vector & v,
			typename Vector::const_iterator in, typename Vector::const_iterator end,
				typename Vector::size_type length)
					{ return bidirectional_iterator::
						assign(const_cast<typename Vector::iterator>(in)-length, in, end); }
//				{ return bidirectional_iterator::assign(coerce(v, in)-length, in, end); }
/*
	shift_right:
		As per policy, does not check against contextual safeties or optimizations.
		The counterintuitive redundancy is to convert const_iterator to iterator.
*/
		template<typename Vector>
		static typename Vector::iterator shift_right(Vector & v,
			typename Vector::const_iterator in, typename Vector::const_iterator end,
				typename Vector::size_type length)
					{ return bidirectional_iterator::reverse_assign(
						const_cast<typename Vector::iterator>(end)+length-1, end-1, in-1); }
//			{ return bidirectional_iterator::reverse_assign(coerce(v, end)+length-1, end-1, in-1); }
/*
	grow:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename Vector>
		static typename Vector::iterator grow(Vector & v,
			typename Vector::const_iterator it, typename Vector::size_type length)
		{
			Vector u(v);
			typename Vector::const_iterator mid=u.begin()+(it-v.begin());
			v=Vector(v.size()+length);
			typename Vector::iterator rtn=bidirectional_iterator::assign(v.begin(), u.cbegin(), mid);
			bidirectional_iterator::assign(rtn+length, mid, u.cend());
			return rtn;
		}
/*
	shrink:
		As per policy, does not check against contextual safeties or optimizations.
*/
		template<typename Vector>
		static typename Vector::iterator shrink(Vector & v,
			typename Vector::const_iterator it, typename Vector::size_type length)
		{
			Vector u(v.size()-length);
			typename Vector::iterator mid=bidirectional_iterator::assign(u.begin(), v.cbegin(), it);
			bidirectional_iterator::assign(mid, it+length, v.cend());
			v=u;
			return v.begin()+(mid-u.begin());
		}
/*
	insert:
*/
		template<typename Vector>
		static typename Vector::iterator insert(Vector & v,
			typename Vector::const_iterator it, const typename Vector::value_type & value)
		{
			typename Vector::iterator rtn=grow(v, it, 1);
			*rtn=value;
			return rtn;
		}

/*
	The "&&" is a "move constructor". This function originally interpreted "&&" differently and needs to be changed.
*/
		template<typename Vector>
		static typename Vector::iterator insert(Vector & v,
			typename Vector::const_iterator it, typename Vector::value_type && value)
		{
			typename Vector::iterator rtn=grow(v, it, 1);
			&*rtn=value;
			return rtn;
		}

		template<typename Vector>
		static typename Vector::iterator insert(Vector & v, typename Vector::const_iterator it,
			typename Vector::size_type count, const typename Vector::value_type & value)
		{
			typename Vector::iterator rtn=grow(v, it, count);
			bidirectional_iterator::repeat(rtn, rtn+count, value);
			return rtn;
		}

		template<typename InputIterator, typename Vector>
		static typename Vector::iterator insert(Vector & v,
			typename Vector::const_iterator it, InputIterator first, InputIterator last)
		{
			typename Vector::iterator rtn=grow(v, it, last-first);
			bidirectional_iterator::assign(rtn, first, last);
			return rtn;
		}
/*
	erase:
*/
		template<typename Vector>
		static typename Vector::iterator erase(Vector & v, typename Vector::const_iterator it)
			{ return shrink(v, it, 1); }

		template<typename Vector>
		static typename Vector::iterator erase(Vector & v,
			typename Vector::const_iterator first, typename Vector::const_iterator last)
				{ return shrink(v, first, last-first); }
	};
   }
  }
 }
}

#endif
