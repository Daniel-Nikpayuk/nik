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

#include"../../../../context/context/policy/policy.h"
#include"../../../../context/media/iterator/extensionwise/policy/policy.h"
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
			typedef context::context::policy<SizeType> c_policy;
			typedef context::media::iterator::extensionwise::policy<SizeType> m_exte_policy;
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
			weaklist sublist;

			iterator before;
		public:
			list()
			{
				before=new node();
				sublist.initialize();
				+before=sublist.initial;
			}
			~list()
			{
				sublist.terminalize();
				delete before;
			}
		public:
				// element access:
			reference front() { return *sublist.initial; }
			const_reference front() const { return *sublist.initial; }
				// iterators:
			iterator before_begin() { return before; }
			const_iterator before_begin() const { return before; }
			const_iterator cbefore_begin() const { return before; }
			iterator begin() { return sublist.initial; }
			const_iterator begin() const { return sublist.initial; }
			const_iterator cbegin() const { return sublist.initial; }
			iterator end() { return sublist.terminal; }
			const_iterator end() const { return sublist.terminal; }
			const_iterator cend() const { return sublist.terminal; }
				// capacity:
			bool empty() const { return sublist.initial == sublist.terminal; }
			size_type max_size() const { return c_policy::par_num::max(); }
				// modifiers:
			void clear()
			{
				sublist.shrink();
				+before=sublist.terminal;
			}

			iterator insert_after(const_iterator it, const value_type & value)
			{
				iterator out=m_exte_policy::lst_ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), value);
				if (it == before) +before=sublist.initial=out;

				return out;
			}

			iterator insert_after(const_iterator it, value_type && value)
			{
				iterator out=m_exte_policy::lst_ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), value);
				if (it == before) +before=sublist.initial=out;

				return out;
			}

			iterator insert_after(const_iterator it, size_type count, const value_type & value)
			{
				iterator out=m_exte_policy::lst_ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), count, value);
				if (it == before) +before=sublist.initial=out;

				return out;
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
				if (first != last)
				{
					iterator out=m_exte_policy::lst_ptr::impend::template
						with_return<node>(c_policy::arg_met::template recast<iterator>(it), first, last);
					if (it == before) +before=sublist.initial=out;

					return out;
				}
			}

/*
			iterator erase(const_iterator it)
			{
				if (sublist.initial != sublist.terminal)
				{
					if (it == sublist.initial)
						return sublist.initial=m_exte_policy::lst_ptr::deject::with_return(sublist.initial);
					else return m_exte_policy::lst_ptr::eject::with_return(it);
				}
			}
*/
/*
	As first and last *should be* iterators within the bounds of sublist.initial and sublist.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
/*
			iterator erase(const_iterator first, const_iterator last)
			{
				if (sublist.initial != sublist.terminal && first != last)
				{
					if (first == sublist.initial) return sublist.initial=
						m_exte_policy::lst_ptr::deject::with_return(first, last);
					else return m_exte_policy::lst_ptr::eject::with_return(first, last);
				}
			}

			void push_back(const value_type & value)
			{
				if (sublist.initial == sublist.terminal)
					sublist.initial=m_exte_policy::lst_ptr::append::with_return(sublist.initial, value);
				else m_exte_policy::lst_ptr::append::no_return(sublist.terminal, value);
			}

			void push_back(value_type && value)
			{
				if (sublist.initial == sublist.terminal)
					sublist.initial=m_exte_policy::lst_ptr::append::with_return(sublist.initial, value);
				else m_exte_policy::lst_ptr::append::no_return(sublist.terminal, value);
			}

			void pop_back()
			{
				if (sublist.initial != sublist.terminal)
				{
					if (+sublist.initial == sublist.terminal)
						sublist.initial=m_exte_policy::lst_ptr::deject::with_return(sublist.initial);
					else m_exte_policy::lst_ptr::eject::no_return(-sublist.terminal);
				}
			}

			void push_front(const value_type & value)
			{
				sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
			}

			void push_front(value_type && value)
			{
				sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
			}

			void pop_front()
			{
				if (sublist.initial != sublist.terminal)
				{
					sublist.initial=m_exte_policy::lst_ptr::deject::with_return(sublist.initial);
				}
			}

			void resize(size_type count)
			{
				size_type cap=sublist::size();
				if (count > cap) m_exte_policy::insert(sublist, sublist.terminal, count-cap, value_type());
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=sublist::size();
				if (count > cap) m_exte_policy::insert(sublist, sublist.terminal, count-cap, value);
			}

			void swap(list & other)
			{
				weaklist::iterator oinitial=other.initial, oterminal=other.terminal;
				other.initial=sublist.initial; other.terminal=sublist.terminal;
				sublist.initial=oinitial; sublist.terminal=oterminal;
			}
*/
	};
   }
  }

	template<typename T, typename SizeType=size_t>
	using list=iterator::generic::list<T, SizeType>;
 }
}

#endif
