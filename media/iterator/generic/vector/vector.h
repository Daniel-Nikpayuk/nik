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

#include"../../../../context/context/argument/policy/policy.h"
#include"../../../../context/context/parameter/policy/policy.h"

#include"../../../../context/semiotic/iterator/componentwise/pointer/policy/policy.h"
#include"../../../../context/semiotic/iterator/componentwise/vector/policy/policy.h"

#include"../../../../context/media/iterator/componentwise/vector/policy/policy.h"

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
*/
	template<typename T, typename SizeType>
	class vector
	{
		protected:
			typedef context::context::argument::policy<SizeType> ca_policy;
			typedef context::context::parameter::policy<SizeType> cp_policy;

			typedef context::semiotic::iterator::componentwise::pointer::policy<SizeType> sicp_policy;
			typedef context::semiotic::iterator::componentwise::vector::policy<SizeType> sicv_policy;

			typedef context::media::iterator::componentwise::vector::policy<SizeType> micv_policy;

			typedef semiotic::iterator::vector<T,SizeType> weakvector;
		public:
			typedef typename weakvector::value_type value_type;
			typedef typename weakvector::reference reference;
			typedef typename weakvector::const_reference const_reference;
			typedef typename weakvector::value_type node;
			typedef typename weakvector::iterator iterator;
			typedef typename weakvector::const_iterator const_iterator;
			typedef typename weakvector::size_type size_type;
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
			size_type max_size() const { return cp_policy::nume::max(); }

			void reserve(size_type new_cap)
			{
				if (new_cap > subvector.length)
				{
					weakvector tmp;
					sicv_policy::iden::grow::after(subvector, tmp, new_cap-subvector.length);
				}
			}

			size_type capacity() const { return subvector.length; }

			void shrink_to_fit()
			{
				if (subvector.length > length)
				{
					weakvector tmp;
					sicv_policy::iden::shrink::after(subvector, tmp, subvector.length-length);
				}
			}

				// modifiers:
			void clear() // sufficient ?
			{
				shrink_to_fit();
				length=0;
			}

			iterator insert(const_iterator it, const value_type & value)
			{
				iterator in=ca_policy::meta::template recast<iterator>(it);

				if (length < subvector.length)
				{
					iterator end=subvector.initial+length;
					sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else micv_policy::iden::insert::impend(subvector, in-subvector.initial, value);

				++length;

				return in;
			}

			iterator insert(const_iterator it, value_type && value)
			{
				iterator in=ca_policy::meta::template recast<iterator>(it);

				if (length < subvector.length)
				{
					iterator end=subvector.initial+length;
					sicp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else micv_policy::iden::insert::impend(subvector, in-subvector.initial, value);

				++length;

				return in;
			}

			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				iterator in=ca_policy::meta::template recast<iterator>(it);

				size_type new_length=length+count;
				if (new_length <= subvector.length)
				{
					iterator end=subvector.initial+new_length-1;
					sicp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					sicp_policy::fwd_over::repeat::no_return(in, count, value);
				}
				else micv_policy::iden::insert::impend(subvector, in-subvector.initial, count, value);

				length=new_length;
			}
/*
	Included to resolve type deduction when "count" and "value" are integer constants.
	Otherwise the template version below is privileged as a better match.
*/
			iterator insert(const_iterator it, int count, const value_type & value)
				{ return insert(it, (size_type) count, value); }

			template<typename RIterator, typename ERIterator>
			iterator insert(const_iterator it, RIterator first, ERIterator last)
			{
				if (first != last)
				{
					iterator in=ca_policy::meta::template recast<iterator>(it);

					size_type count=last-first;
					size_type new_length=length+count;
					if (new_length <= subvector.length)
					{
						iterator end=subvector.initial+new_length-1;
						sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
						sicv_policy::fwd_over::assign::no_return(in, first, last);
					}
					else micv_policy::iden::insert::impend(subvector, in-subvector.initial, first, last);

					length=new_length;
				}
			}

			iterator erase(const_iterator it)
			{
				if (length)
				{
					iterator in=ca_policy::meta::template recast<iterator>(it);

					sicv_policy::fwd_over::assign::no_return(in, in+1, subvector.initial+length);
					--length;
				}
			}
/*
	As first and last *should be* iterators within the bounds of subvector.initial and subvector.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase(const_iterator first, const_iterator last)
			{
				if (first != last)
				{
					size_type count=last-first;
					if (length >= count)
					{
						iterator in=ca_policy::meta::template recast<iterator>(first);
						iterator end=ca_policy::meta::template recast<iterator>(last);

						sicp_policy::fwd_over::assign::no_return(in, end, end+count);
						length-=count;
					}
				}
			}

/*
			void push_back(const value_type & value)
			{
				if (length < subvector.length) *(subvector.initial+length)=value;
				else
				{
					subvector.initial=micv_policy::ptr::append::template
						with_return<node>(subvector.initial, subvector.length, value);

					++subvector.length;
				}

				++length;

				return in;

				++length;
				micv_policy::ptr::impend::template no_return<node>(subvector.terminal, value);
			}
			void push_back(const value_type & value)
			{
				if (subvector.size() > length)
					subvector[length++]=value;
				else micv_policy::insert(subvector, subvector.initial+(length++), value);
			}
*/

/*
			void push_back(value_type && value)
			{
			}

			void pop_back() { if (length) --length; }

			void push_front(const value_type & value)
			{

					if (in == subvector.initial)
						subvector.initial=micv_policy::ptr::prepend::template
							with_return<node>(subvector.initial, subvector.length, value);
				++length;
				subvector.initial=micv_policy::ptr::prepend::template with_return<node>(subvector.initial, value);
			}

			void push_front(value_type && value)
			{
			}

			void pop_front()
			{
				if (length)
				{
					--length;
				}
			}
*/

/*
			void resize(size_type count)
			{
				size_type cap=subvector::size();
				if (count > cap) micv_policy::insert(subvector, subvector.terminal, count-cap, value_type());
			}
			void resize(size_type count)
			{
				size_type cap=subvector.size();
				if (count > cap) micv_policy::insert(subvector, subvector.terminal, count-cap, value_type());
				length=count;
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subvector::size();
				if (count > cap) micv_policy::insert(subvector, subvector.terminal, count-cap, value);
			}
			void resize(size_type count, const value_type & value)
			{
				size_type cap=subvector.size();
				if (count > cap) micv_policy::insert(subvector, subvector.terminal, count-cap, value);
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
