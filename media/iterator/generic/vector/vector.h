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

#ifndef NIK_MEDIA_ITERATOR_GENERIC_VECTOR_H
#define NIK_MEDIA_ITERATOR_GENERIC_VECTOR_H

#include"../../context/vector/vector.h"
#include"../../context/iterator/random_access_iterator.h"
#include"../../context/numeric_limits/numeric_limits.h"
#include"../../semiotic/vector/vector.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
   namespace generic
   {
/*
	vector:
		Things need fixing: const_cast instead of relying on (begin()+(n-begin())) in the generic context methods.

		change typedef from subvector to weakvector, and current to subvector.

		subvector iterator probably needs updating to reflect that topos0_pointer no longer exists.
*/
	template<typename T, typename SizeType>
	class vector
	{
		protected:
			typedef context::vector method;
//			friend method; doesn't look like it's needed.

			typedef context::random_access_iterator subiterator;

			typedef semiotic::vector<T,SizeType> subvector;
			subvector current;
		public:
			typedef typename subvector::value_type value_type;
			typedef typename subvector::reference reference;
			typedef typename subvector::const_reference const_reference;
			typedef typename subvector::size_type size_type;
			typedef typename subvector::iterator iterator;
			typedef typename subvector::const_iterator const_iterator;
		private:
			size_type length;
		public:
			vector() : current(0), length(0) { }
		public:
				// element access:
			reference at(size_type pos)
			{
				try
				{
					if (0 <= pos && pos < length) return current[pos];
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}
			const_reference at(size_type pos) const
			{
				try
				{
					if (0 <= pos && pos < length) return current[pos];
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}
			reference operator [] (size_type pos) { return current[pos]; }
			const_reference operator [] (size_type pos) const { return current[pos]; }
			reference front() { return *current.first; }
			const_reference front() const { return *current.first; }
			reference back() { return *(current.first+length-1); }
			const_reference back() const { return *(current.first+length-1); }
				// iterators:
			iterator begin() { return current.first; }
			const_iterator begin() const { return current.first; }
			const_iterator cbegin() const { return current.first; }
			iterator end() { return current.first+length; }
			const_iterator end() const { return current.first+length; }
			const_iterator cend() const { return current.first+length; }
				// capacity:
			bool empty() const { return length == 0; }
			size_type size() const { return length; }
			size_type max_size() const { return context::numeric_limits<size_type>::max(); }
			void reserve(size_type new_cap)
			{
				size_type cap=current.size();
				if (new_cap > cap) method::grow(current, current.last, new_cap-cap);
			}
			size_type capacity() const { return current.size(); }
			void shrink_to_fit()
			{
				return method::shrink(current, current.last, current.size()-length);
			}
				// modifiers:
			void clear() { length=0; } // sufficient ?
/*
	Is not well defined when it is past last.
	It is of const_iterator type, uses "begin+(it-begin)" to coerce type. Is it worth it though?
*/
			iterator insert(const_iterator it, const value_type & value)
			{
				if (current.first+length+1 < current.last)
					*method::shift_right(current, it, current.first+(++length), 1)=value;
				else method::insert(current, it, value);
			}
			iterator insert(const_iterator it, value_type && value)
			{
				if (current.first+length+1 < current.last)
					*method::shift_right(current, it, current.first+(++length), 1)=value;
				else method::insert(current, it, value);
			}
			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				if (current.first+length+count < current.last)
				{
					typename subvector::iterator
						i=method::shift_right(current, it, current.first+(++length), count);
					subiterator::repeat(i, i+count, value);
				}
				else method::insert(current, it, count, value);
			}
			template<typename InputIterator>
			iterator insert(const_iterator it, InputIterator first, InputIterator last)
			{
				size_type n=InputIterator::category_tag::size(first, last);
				if (current.first+length+n < current.last)
				{
					typename subvector::iterator
						i=method::shift_right(current, it, current.first+(++length), n);
					subiterator::assign(i, first, last);
				}
				else method::insert(current, it, first, last);
			}
			iterator erase(const_iterator it)
				{ method::shift_left(current, it+1, current.first+(length--), 1); }
			iterator erase(const_iterator first, const_iterator last)
			{
				size_type n=last-first;
				method::shift_left(current, first+n, current.first+(length--), n);
			}
			void push_back(const value_type & value)
			{
				if (current.size() > length)
					current[length++]=value;
				else method::insert(current, current.first+(length++), value);
			}
			void push_back(value_type && value)
			{
					// not right, has to do with "&&" ?
				if (current.size() > length)
					current[length++]=value;
				else method::insert(current, current.first+(length++), value);
			}
			void pop_back() { --length; }
			void resize(size_type count)
			{
				size_type cap=current.size();
				if (count > cap) method::insert(current, current.last, count-cap, value_type());
				length=count;
			}
			void resize(size_type count, const value_type & value)
			{
				size_type cap=current.size();
				if (count > cap) method::insert(current, current.last, count-cap, value);
				length=count;
			}
			void swap(vector & other)
			{
				subvector &tmp=other.current;
				&other.current=&current;
				&current=&tmp;
			}
	};
   }
  }

	template<typename T, typename SizeType=size_t>
	using vector=iterator::generic::vector<T, SizeType>;
 }
}

#endif
