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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_LIST_STRUCTURAL_BASE_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_LIST_STRUCTURAL_BASE_H

#include"../../../../../../semiotic/numeric/processor/argument/policy/policy.h"
#include"../../../../../../semiotic/numeric/processor/parameter/policy/policy.h"

#include"../../../../../../semiotic/numeric/random_access/list/structural/traits.h"
#include"../../../../../../semiotic/numeric/random_access/list/functional/policy.h"

/*
	Given the unsafe nature of semiotic::list, policy here is designed for composability instead of inheritance.

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

			typedef semiotic::numeric::random_access::list::structural::traits<SizeType> snrls_traits;
			typedef semiotic::numeric::random_access::list::functional::policy<SizeType> snrlf_policy;

			typedef typename snrls_traits::base<T,SizeType> weakbase;
		public:
			typedef typename weakbase::value_type value_type;
			typedef typename weakbase::reference reference;
			typedef typename weakbase::const_reference const_reference;
			typedef typename weakbase::node node;
			typedef typename weakbase::iterator iterator;
			typedef typename weakbase::const_iterator const_iterator;
			typedef typename weakbase::size_type size_type;
		protected:
				// subbase.initial is interpreted to be "before initial".
				// subbase.terminal is interpreted to be "this terminal".
			weakbase subbase;
		public:
			base() { sitl_policy::iden::initialize::no_return(subbase); }

			base(const base & l) { sitl_policy::iden::copy::no_return(subbase, l); }

			~base() { subbase.terminalize(); }
		public:
				// element access:
			reference front() { return *+subbase.initial; }
			const_reference front() const { return *+subbase.initial; }
				// iterators:
			iterator before_begin() { return subbase.initial; }
			const_iterator before_begin() const { return subbase.initial; }
			const_iterator cbefore_begin() const { return subbase.initial; }
			iterator begin() { return +subbase.initial; }
			const_iterator begin() const { return +subbase.initial; }
			const_iterator cbegin() const { return +subbase.initial; }
			iterator end() { return subbase.terminal; }
			const_iterator end() const { return subbase.terminal; }
			const_iterator cend() const { return subbase.terminal; }
				// capacity:
			bool empty() const { return +subbase.initial == subbase.terminal; }
			size_type max_size() const { return snpp_policy::nume::max(); }
				// modifiers:
			void clear()
			{
				sitl_policy::ptr::clear::no_return(subbase.initial+size_type(1), subbase.terminal);
				+subbase.initial=subbase.terminal;
			}

			iterator insert_after(const_iterator it, const value_type & value)
			{
				return snrlf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert_after(const_iterator it, value_type && value)
			{
				return snrlf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert_after(const_iterator it, size_type count, const value_type & value)
			{
				return snrlf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), count, value);
			}
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
			iterator insert_after(const_iterator it, int count, const value_type & value)
				{ return insert_after(it, (size_type) count, value); }

			template<typename RIterator, typename ERIterator>
			iterator insert_after(const_iterator it, RIterator first, ERIterator last)
			{
				return snrlf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), first, last);
			}

			iterator erase_after(const_iterator it)
			{
				if (+subbase.initial != subbase.terminal)
					return snrlf_policy::ptr::eject::with_return(snpa_policy::meta::template recast<iterator>(it));
			}
/*
	As first and last *should be* iterators within the bounds of subbase.initial and subbase.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase_after(const_iterator first, const_iterator last)
			{
				if (+subbase.initial != subbase.terminal)
					return snrlf_policy::ptr::eject::with_return(
						snpa_policy::meta::template recast<iterator>(first),
						snpa_policy::meta::template recast<iterator>(last));
			}

			void push_front(const value_type & value)
				{ snrlf_policy::ptr::impend::template no_return<node>(subbase.initial, value); }

			void push_front(value_type && value)
				{ snrlf_policy::ptr::impend::template no_return<node>(subbase.initial, value); }

			void pop_front()
			{
				if (+subbase.initial != subbase.terminal)
					snrlf_policy::ptr::eject::no_return(subbase.initial);
			}

/*
			void resize(size_type count)
			{
				size_type cap=subbase::size();
				if (count > cap) snrlf_policy::insert(subbase, subbase.terminal, count-cap, value_type());
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subbase::size();
				if (count > cap) snrlf_policy::insert(subbase, subbase.terminal, count-cap, value);
			}
*/

			void swap(base & other)
			{
				iterator oinitial=other.subbase.initial, oterminal=other.subbase.terminal;
				other.subbase.initial=subbase.initial; other.subbase.terminal=subbase.terminal;
				subbase.initial=oinitial; subbase.terminal=oterminal;
			}
	};
     }
    }
   }
  }
 }
}

#endif
