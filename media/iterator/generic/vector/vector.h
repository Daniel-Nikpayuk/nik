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

/*
	Given the unsafe nature of semiotic::vector policy here is composability instead of inheritance.

	Test against self-assignment!
*/

#include"../../../../context/context/policy/policy.h"
#include"../../../../context/media/iterator/componentwise/policy/policy.h"
#include"../../../../semiotic/iterator/vector/vector.h"

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
		Things need fixing: const_cast instead of relying on (begin()+(n-begin())) in the generic context m_ethods.
*/
	template<typename T, typename SizeType>
	class vector
	{
		protected:
			typedef context::context::policy<SizeType> c_policy;
			typedef context::media::iterator::componentwise::policy<SizeType> m_comp_policy;
			typedef semiotic::iterator::vector<T,SizeType> weakvector;
		public:
			typedef typename weakvector::value_type value_type;
			typedef typename weakvector::reference reference;
			typedef typename weakvector::const_reference const_reference;
			typedef typename weakvector::value_type node;
			typedef typename weakvector::iterator iterator;
			typedef typename weakvector::const_iterator const_iterator;
			typedef typename weakvector::size_type size_type;

			typedef typename weakvector::s_comp_policy s_comp_policy;
		protected:
				// subvector.length represents the capacity.
			weakvector subvector; 

			size_type length; // length represents the existing length.
		public:
			vector() : length(0) { subvector.initialize(0); }
			vector(const vector & v) : length(v.length)
				{ subvector.copy_initialize(v.subvector.initial, v.subvector.length); }
			~vector() { subvector.terminalize(); }
		public:
				// element access:
			reference at(size_type pos)
			{
				try
				{
					if (0 <= pos && pos < length) return *(subvector.initial+pos);
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}

			const_reference at(size_type pos) const
			{
				try
				{
					if (0 <= pos && pos < length) return *(subvector.initial+pos);
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}

				// terminal != end

			reference operator [] (size_type pos) { return *(subvector.initial+pos); }
			const_reference operator [] (size_type pos) const { return *(subvector.initial+pos); }
			reference front() { return *subvector.initial; }
			const_reference front() const { return *subvector.initial; }
			reference back() { return *(subvector.initial+length-1); }
			const_reference back() const { return *(subvector.initial+length-1); }
				// iterators:
			iterator begin() { return subvector.initial; }
			const_iterator begin() const { return subvector.initial; }
			const_iterator cbegin() const { return subvector.initial; }
			iterator end() { return subvector.initial+length; }
			const_iterator end() const { return subvector.initial+length; }
			const_iterator cend() const { return subvector.initial+length; }
				// capacity:
			bool empty() const { return !length; }
			size_type size() const { return length; }
			size_type max_size() const { return c_policy::par_num::max(); }

			void reserve(size_type new_cap)
			{
				if (new_cap > subvector.length)
				{
					subvector.initial=m_comp_policy::ptr::upsize::template
						with_return<node>(subvector.initial, length, new_cap, 0);
					subvector.length=new_cap;
				}
			}

			size_type capacity() const { return subvector.length; }

			void shrink_to_fit()
			{
				subvector.initial=m_comp_policy::ptr::downsize::template
					with_return<node>(subvector.initial, length, 0);
				subvector.length=length;
			}
				// modifiers:
			void clear() // sufficient ?
			{
				shrink_to_fit();
				length=0;
			}

			iterator insert(const_iterator it, const value_type & value)
			{
				iterator in=c_policy::arg_met::template recast<iterator>(it);
				if (length < subvector.length)
				{
					iterator end=subvector.initial+length;
					s_comp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else // length == subvector.length
				{
					if (in == subvector.initial)
						subvector.initial=m_comp_policy::ptr::prepend::template
							with_return<node>(subvector.initial, length, value);
					else subvector.initial=m_comp_policy::ptr::impend::template
						with_return<node>(subvector.initial, length, in-subvector.initial, value);

					++subvector.length;
				}

				++length;

				return in;
			}

			iterator insert(const_iterator it, value_type && value)
			{
				iterator in=c_policy::arg_met::template recast<iterator>(it);
				if (length < subvector.length)
				{
					iterator end=subvector.initial+length;
					s_comp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else // length == subvector.length
				{
					if (in == subvector.initial)
						subvector.initial=m_comp_policy::ptr::prepend::template
							with_return<node>(subvector.initial, length, value);
					else subvector.initial=m_comp_policy::ptr::impend::template
						with_return<node>(subvector.initial, length, in-subvector.initial, value);

					++subvector.length;
				}

				++length;

				return in;
			}

/*
			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it == subvector.initial)
					return subvector.initial=m_comp_policy::ptr::prepend::template
						with_return<node>(subvector.initial, count, value);
				else return m_comp_policy::ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), count, value);
			}
			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				if (subvector.initial+length+count < subvector.terminal)
				{
					iterator i=m_comp_policy::shift_right(subvector, it, subvector.initial+(++length), count);
					subiterator::repeat(i, i+count, value);
				}
				else m_comp_policy::insert(subvector, it, count, value);
			}

*/
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
/*
			iterator insert(const_iterator it, int count, const value_type & value)
				{ return insert(it, (size_type) count, value); }

			template<typename RIterator, typename ERIterator>
			iterator insert(const_iterator it, RIterator first, ERIterator last)
			{
				if (it == subvector.initial)
					return subvector.initial=m_comp_policy::ptr::prepend::count::template
						with_return<node>(length, subvector.initial, first, last);
				else return m_comp_policy::ptr::impend::count::template
					with_return<node>(length, c_policy::arg_met::template recast<iterator>(it), first, last);
			}
			template<typename InputIterator>
			iterator insert(const_iterator it, InputIterator initial, InputIterator terminal)
			{
				size_type n=InputIterator::category_tag::size(initial, terminal);
				if (subvector.initial+length+n < subvector.terminal)
				{
					iterator i=m_comp_policy::shift_right(subvector, it, subvector.initial+(++length), n);
					subiterator::assign(i, initial, terminal);
				}
				else m_comp_policy::insert(subvector, it, initial, terminal);
			}

			iterator erase(const_iterator it)
			{
				if (subvector.initial != subvector.terminal)
				{
					--length;
					if (it == subvector.initial)
						return subvector.initial=m_comp_policy::ptr::deject::
							with_return(subvector.initial);
					else return m_comp_policy::ptr::eject::
						with_return(c_policy::arg_met::template recast<iterator>(it));
				}
			}
			iterator erase(const_iterator it)
				{ m_comp_policy::shift_left(subvector, it+1, subvector.initial+(length--), 1); }

*/
/*
	As first and last *should be* iterators within the bounds of subvector.initial and subvector.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
/*
			iterator erase(const_iterator first, const_iterator last)
			{
				if (subvector.initial != subvector.terminal)
					if (first == subvector.initial)
						return subvector.initial=m_comp_policy::ptr::deject::count::with_return(length,
							c_policy::arg_met::template recast<iterator>(first),
							c_policy::arg_met::template recast<iterator>(last));
					else return m_comp_policy::ptr::eject::count::with_return(length,
						c_policy::arg_met::template recast<iterator>(first),
						c_policy::arg_met::template recast<iterator>(last));
			}
			iterator erase(const_iterator initial, const_iterator terminal)
			{
				size_type n=terminal-initial;
				m_comp_policy::shift_left(subvector, initial+n, subvector.initial+(length--), n);
			}

			void push_back(const value_type & value)
			{
				++length;
				m_comp_policy::ptr::impend::template no_return<node>(subvector.terminal, value);
			}
			void push_back(const value_type & value)
			{
				if (subvector.size() > length)
					subvector[length++]=value;
				else m_comp_policy::insert(subvector, subvector.initial+(length++), value);
			}

			void push_back(value_type && value)
			{
				++length;
				m_comp_policy::ptr::impend::template no_return<node>(subvector.terminal, value);
			}
			void push_back(value_type && value)
			{
					// not right, has to do with "&&" ?
				if (subvector.size() > length)
					subvector[length++]=value;
				else m_comp_policy::insert(subvector, subvector.initial+(length++), value);
			}

			void pop_back()
			{
				if (subvector.initial != subvector.terminal)
				{
					--length;
					m_comp_policy::ptr::eject::no_return(-subvector.terminal);
				}
			}
			void pop_back() { --length; }

			void push_front(const value_type & value)
			{
				++length;
				subvector.initial=m_comp_policy::ptr::prepend::template with_return<node>(subvector.initial, value);
			}

			void push_front(value_type && value)
			{
				++length;
				subvector.initial=m_comp_policy::ptr::prepend::template with_return<node>(subvector.initial, value);
			}

			void pop_front()
			{
				if (subvector.initial != subvector.terminal)
				{
					--length;
					subvector.initial=m_comp_policy::ptr::deject::with_return(subvector.initial);
				}
			}
*/

/*
			void resize(size_type count)
			{
				size_type cap=subvector::size();
				if (count > cap) m_comp_policy::insert(subvector, subvector.terminal, count-cap, value_type());
			}
			void resize(size_type count)
			{
				size_type cap=subvector.size();
				if (count > cap) m_comp_policy::insert(subvector, subvector.terminal, count-cap, value_type());
				length=count;
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subvector::size();
				if (count > cap) m_comp_policy::insert(subvector, subvector.terminal, count-cap, value);
			}
			void resize(size_type count, const value_type & value)
			{
				size_type cap=subvector.size();
				if (count > cap) m_comp_policy::insert(subvector, subvector.terminal, count-cap, value);
				length=count;
			}

*/

/*
			void swap(vector & other)
			{
				iterator oinitial=other.subvector.initial, oterminal=other.subvector.terminal;
				size_type olength=other.length;

				other.subvector.initial=subvector.initial; other.subvector.terminal=subvector.terminal;
				other.length=length;

				subvector.initial=oinitial; subvector.terminal=oterminal;
				length=olength;
			}
			void swap(vector & other)
			{
				weakvector &tmp=other.subvector;
				&other.subvector=&subvector;
				&subvector=&tmp;
			}

*/
	};
   }
  }

	template<typename T, typename SizeType=size_t>
	using vector=iterator::generic::vector<T, SizeType>;
 }
}

#endif
