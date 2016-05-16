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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_BASE_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_BASE_H

#include"../../../../../../semiotic/numeric/processor/argument/policy/policy.h"
#include"../../../../../../semiotic/numeric/processor/parameter/policy/policy.h"

#include"../../../../../../semiotic/numeric/random_access/vector/structural/traits.h"
#include"../../../../../../semiotic/numeric/random_access/vector/functional/policy.h"

/*
	Given the unsafe nature of semiotic::vector policy here is composability instead of inheritance.

	Test against self-assignment!
*/

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace list
    {
     namespace structural
     {
/*
	base:
*/
	template<typename T, typename SizeType>
	class base
	{
		protected:
			typedef semiotic::numeric::processor::argument::policy<SizeType> snpa_policy;
			typedef semiotic::numeric::processor::parameter::policy<SizeType> snpp_policy;

			typedef semiotic::numeric::random_access::vector::structural::traits<SizeType> snrvs_traits;
			typedef semiotic::numeric::random_access::vector::functional::policy<SizeType> snrvf_policy;

			typedef typename snrvs_traits::base<T,SizeType> weakbase;
		public:
			typedef typename weakbase::value_type value_type;
			typedef typename weakbase::reference reference;
			typedef typename weakbase::const_reference const_reference;
			typedef typename weakbase::value_type node;
			typedef typename weakbase::iterator iterator;
			typedef typename weakbase::const_iterator const_iterator;
			typedef typename weakbase::size_type size_type;
		protected:
				// subbase.length represents the capacity.
			weakbase subbase; 

			size_type length; // length represents the existing length.
		public:
			base() : length(0) { subbase.initialize(0); }
			base(const base & v) : length(v.length)
				{ subbase.copy_initialize(v.subbase.initial, v.subbase.length); }
			~base() { subbase.terminalize(); }
		public:
				// element access:
			reference at(size_type pos)
			{
				try
				{
					if (0 <= pos && pos < length) return *(subbase.initial+pos);
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}

			const_reference at(size_type pos) const
			{
				try
				{
					if (0 <= pos && pos < length) return *(subbase.initial+pos);
					else throw;
				}
				catch(...)
				{ } // haven't yet defined "nik::error"
			}

				// terminal != end

			reference operator [] (size_type pos) { return *(subbase.initial+pos); }
			const_reference operator [] (size_type pos) const { return *(subbase.initial+pos); }
			reference front() { return *subbase.initial; }
			const_reference front() const { return *subbase.initial; }
			reference back() { return *(subbase.initial+length-1); }
			const_reference back() const { return *(subbase.initial+length-1); }
				// iterators:
			iterator begin() { return subbase.initial; }
			const_iterator begin() const { return subbase.initial; }
			const_iterator cbegin() const { return subbase.initial; }
			iterator end() { return subbase.initial+length; }
			const_iterator end() const { return subbase.initial+length; }
			const_iterator cend() const { return subbase.initial+length; }
				// capacity:
			bool empty() const { return !length; }
			size_type size() const { return length; }
			size_type max_size() const { return snpp_policy::nume::max(); }

			void reserve(size_type new_cap)
			{
				if (new_cap > subbase.length)
				{
					weakbase tmp;
					sicv_policy::iden::grow::after(subbase, tmp, new_cap-subbase.length);
				}
			}

			size_type capacity() const { return subbase.length; }

			void shrink_to_fit()
			{
				if (subbase.length > length)
				{
					weakbase tmp;
					sicv_policy::iden::shrink::after(subbase, tmp, subbase.length-length);
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
				iterator in=snpa_policy::meta::template recast<iterator>(it);

				if (length < subbase.length)
				{
					iterator end=subbase.initial+length;
					sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else snrvf_policy::iden::insert::impend(subbase, in-subbase.initial, value);

				++length;

				return in;
			}

			iterator insert(const_iterator it, value_type && value)
			{
				iterator in=snpa_policy::meta::template recast<iterator>(it);

				if (length < subbase.length)
				{
					iterator end=subbase.initial+length;
					sisnpp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					*in=value;
				}
				else snrvf_policy::iden::insert::impend(subbase, in-subbase.initial, value);

				++length;

				return in;
			}

			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				iterator in=snpa_policy::meta::template recast<iterator>(it);

				size_type new_length=length+count;
				if (new_length <= subbase.length)
				{
					iterator end=subbase.initial+new_length-1;
					sisnpp_policy::bwd_over::assign::no_return(end, end-1, in-1);
					sisnpp_policy::fwd_over::repeat::no_return(in, count, value);
				}
				else snrvf_policy::iden::insert::impend(subbase, in-subbase.initial, count, value);

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
					iterator in=snpa_policy::meta::template recast<iterator>(it);

					size_type count=last-first;
					size_type new_length=length+count;
					if (new_length <= subbase.length)
					{
						iterator end=subbase.initial+new_length-1;
						sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
						sicv_policy::fwd_over::assign::no_return(in, first, last);
					}
					else snrvf_policy::iden::insert::impend(subbase, in-subbase.initial, first, last);

					length=new_length;
				}
			}

			iterator erase(const_iterator it)
			{
				if (length)
				{
					iterator in=snpa_policy::meta::template recast<iterator>(it);

					sicv_policy::fwd_over::assign::no_return(in, in+1, subbase.initial+length);
					--length;
				}
			}
/*
	As first and last *should be* iterators within the bounds of subbase.initial and subbase.terminal, a comparative approach (<=)
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
						iterator in=snpa_policy::meta::template recast<iterator>(first);
						iterator end=snpa_policy::meta::template recast<iterator>(last);

						sisnpp_policy::fwd_over::assign::no_return(in, end, end+count);
						length-=count;
					}
				}
			}

/*
			void push_back(const value_type & value)
			{
				if (length < subbase.length) *(subbase.initial+length)=value;
				else
				{
					subbase.initial=snrvf_policy::ptr::append::template
						with_return<node>(subbase.initial, subbase.length, value);

					++subbase.length;
				}

				++length;

				return in;

				++length;
				snrvf_policy::ptr::impend::template no_return<node>(subbase.terminal, value);
			}
			void push_back(const value_type & value)
			{
				if (subbase.size() > length)
					subbase[length++]=value;
				else snrvf_policy::insert(subbase, subbase.initial+(length++), value);
			}
*/

/*
			void push_back(value_type && value)
			{
			}

			void pop_back() { if (length) --length; }

			void push_front(const value_type & value)
			{

					if (in == subbase.initial)
						subbase.initial=snrvf_policy::ptr::prepend::template
							with_return<node>(subbase.initial, subbase.length, value);
				++length;
				subbase.initial=snrvf_policy::ptr::prepend::template with_return<node>(subbase.initial, value);
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
				size_type cap=subbase::size();
				if (count > cap) snrvf_policy::insert(subbase, subbase.terminal, count-cap, value_type());
			}
			void resize(size_type count)
			{
				size_type cap=subbase.size();
				if (count > cap) snrvf_policy::insert(subbase, subbase.terminal, count-cap, value_type());
				length=count;
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subbase::size();
				if (count > cap) snrvf_policy::insert(subbase, subbase.terminal, count-cap, value);
			}
			void resize(size_type count, const value_type & value)
			{
				size_type cap=subbase.size();
				if (count > cap) snrvf_policy::insert(subbase, subbase.terminal, count-cap, value);
				length=count;
			}

*/

/*
			void swap(base & other)
			{
				iterator oinitial=other.subbase.initial, oterminal=other.subbase.terminal;
				size_type olength=other.length;

				other.subbase.initial=subbase.initial; other.subbase.terminal=subbase.terminal;
				other.length=length;

				subbase.initial=oinitial; subbase.terminal=oterminal;
				length=olength;
			}
			void swap(base & other)
			{
				weakbase &tmp=other.subbase;
				&other.subbase=&subbase;
				&subbase=&tmp;
			}

*/
	};
     }
    }
   }
  }
 }
}

#endif
