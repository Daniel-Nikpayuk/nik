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

#ifndef NIK_MEDIA_ITERATOR_GENERIC_LIST_H
#define NIK_MEDIA_ITERATOR_GENERIC_LIST_H

/*
	Given the unsafe nature of semiotic::list, policy here is designed for composability instead of inheritance.

	Test against self-assignment!
*/

#include"../../../../context/context/argument/policy/policy.h"
#include"../../../../context/context/parameter/policy/policy.h"

#include"../../../../context/semiotic/iterator/extensionwise/list/policy/policy.h"
#include"../../../../context/media/iterator/extensionwise/list/policy/policy.h"

#include"../../../../semiotic/iterator/list/list.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
   namespace generic
   {
/*
	list:
*/
	template<typename T, typename SizeType>
	class list
	{
		protected:
			typedef context::context::argument::policy<SizeType> ca_policy;
			typedef context::context::parameter::policy<SizeType> cp_policy;

			typedef context::media::iterator::extensionwise::list::policy<SizeType> sitl_policy;
			typedef context::media::iterator::extensionwise::list::policy<SizeType> mitl_policy;

			typedef semiotic::iterator::list<T,SizeType> weaklist;
		public:
			typedef typename weaklist::value_type value_type;
			typedef typename weaklist::reference reference;
			typedef typename weaklist::const_reference const_reference;
			typedef typename weaklist::node node;
			typedef typename weaklist::iterator iterator;
			typedef typename weaklist::const_iterator const_iterator;
			typedef typename weaklist::size_type size_type;
		protected:
				// sublist.initial is interpreted to be "before initial".
				// sublist.terminal is interpreted to be "this terminal".
			weaklist sublist;

			void initialize()
			{
				sublist.terminal=new node;
				sublist.initial=new node;
				+sublist.initial=sublist.terminal;
			}
		public:
			list() { initialize(); }

			list(const list & l)
			{
				initialize();
				sublist.terminal=sitl_policy::fwd_over::assign::template
					with_return<node>(sublist.terminal, +l.sublist.initial, l.sublist.terminal);
			}

			~list() { sublist.terminalize(); }
		public:
				// element access:
			reference front() { return *+sublist.initial; }
			const_reference front() const { return *+sublist.initial; }
				// iterators:
			iterator before_begin() { return sublist.initial; }
			const_iterator before_begin() const { return sublist.initial; }
			const_iterator cbefore_begin() const { return sublist.initial; }
			iterator begin() { return +sublist.initial; }
			const_iterator begin() const { return +sublist.initial; }
			const_iterator cbegin() const { return +sublist.initial; }
			iterator end() { return sublist.terminal; }
			const_iterator end() const { return sublist.terminal; }
			const_iterator cend() const { return sublist.terminal; }
				// capacity:
			bool empty() const { return +sublist.initial == sublist.terminal; }
			size_type max_size() const { return cp_policy::nume::max(); }
				// modifiers:
			void clear()
			{
				sitl_policy::ptr::clear::no_return(sublist.initial+size_type(1), sublist.terminal);
				+sublist.initial=sublist.terminal;
			}

			iterator insert_after(const_iterator it, const value_type & value)
			{
				return mitl_policy::ptr::impend::template
					with_return<node>(ca_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert_after(const_iterator it, value_type && value)
			{
				return mitl_policy::ptr::impend::template
					with_return<node>(ca_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert_after(const_iterator it, size_type count, const value_type & value)
			{
				return mitl_policy::ptr::impend::template
					with_return<node>(ca_policy::meta::template recast<iterator>(it), count, value);
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
				return mitl_policy::ptr::impend::template
					with_return<node>(ca_policy::meta::template recast<iterator>(it), first, last);
			}

			iterator erase_after(const_iterator it)
			{
				if (+sublist.initial != sublist.terminal)
					return mitl_policy::ptr::eject::with_return(ca_policy::meta::template recast<iterator>(it));
			}
/*
	As first and last *should be* iterators within the bounds of sublist.initial and sublist.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase_after(const_iterator first, const_iterator last)
			{
				if (+sublist.initial != sublist.terminal)
					return mitl_policy::ptr::eject::with_return(
						ca_policy::meta::template recast<iterator>(first),
						ca_policy::meta::template recast<iterator>(last));
			}

			void push_front(const value_type & value)
				{ mitl_policy::ptr::impend::template no_return<node>(sublist.initial, value); }

			void push_front(value_type && value)
				{ mitl_policy::ptr::impend::template no_return<node>(sublist.initial, value); }

			void pop_front()
			{
				if (+sublist.initial != sublist.terminal)
					mitl_policy::ptr::eject::no_return(sublist.initial);
			}

/*
			void resize(size_type count)
			{
				size_type cap=sublist::size();
				if (count > cap) mitl_policy::insert(sublist, sublist.terminal, count-cap, value_type());
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=sublist::size();
				if (count > cap) mitl_policy::insert(sublist, sublist.terminal, count-cap, value);
			}
*/

			void swap(list & other)
			{
				iterator oinitial=other.sublist.initial, oterminal=other.sublist.terminal;
				other.sublist.initial=sublist.initial; other.sublist.terminal=sublist.terminal;
				sublist.initial=oinitial; sublist.terminal=oterminal;
			}
	};
   }
  }

	template<typename T, typename SizeType=size_t>
	using list=iterator::generic::list<T, SizeType>;
 }
}

#endif
