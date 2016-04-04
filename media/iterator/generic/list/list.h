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
	Given the unsafe nature of semiotic::list policy here is composability instead of inheritance.

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
			typedef typename weaklist::iterator iterator;
			typedef typename weaklist::const_iterator const_iterator;
			typedef typename weaklist::size_type size_type;
		protected:
			weaklist sublist; 

			size_type length;
		public:
			list() : length(0) { sublist.initialize(); }
			~list() { sublist.terminalize(); }
		public:
				// element access:
			reference front() { return *sublist.initial; }
			const_reference front() const { return *sublist.initial; }
			reference back() { return *-sublist.terminal; }
			const_reference back() const { return *-sublist.terminal; }
				// iterators:
			iterator begin() { return sublist.initial; }
			const_iterator begin() const { return (const_iterator) sublist.initial; }
			const_iterator cbegin() const { return (const_iterator) sublist.initial; }
			iterator end() { return sublist.terminal; }
			const_iterator end() const { return (const_iterator) sublist.terminal; }
			const_iterator cend() const { return (const_iterator) sublist.terminal; }
				// capacity:
			bool empty() const { return length; }
			size_type size() const { return length; }
			size_type max_size() const { return c_policy::par_num::max(); }
				// modifiers:
			void clear() { sublist.shrink(); }

// needs to be "const_iterator it"
			iterator insert(iterator it, const value_type & value)
			{
				++length;
				if (it == sublist.initial)
					return sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
				else return m_exte_policy::lst_ptr::impend::with_return(it, value);
			}

			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it == sublist.initial)
					return sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
				else return m_exte_policy::lst_ptr::impend::with_return(it, value);
			}

// needs to be "const_iterator it"
			iterator insert(iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it == sublist.initial)
					return sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, count, value);
				else return m_exte_policy::lst_ptr::impend::with_return(it, count, value);
			}
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
// needs to be "const_iterator it"
			iterator insert(iterator it, int count, const value_type & value)
				{ return insert(it, (size_type) count, value); }
/*
			template<typename RIterator, typename ERIterator>
			iterator insert(const_iterator it, InputIterator first, InputIterator last)
			{
				if (first != last)
				{
					if (it == sublist.initial)
					{
						-sublist.initial=new weaklist::iterator();
						return sublist.initial=m_exte_policy::lst_ptr::
							prepend::count::with_return(length, -sublist.initial, first, last);
					}
					else return m_exte_policy::lst_ptr::impend::count::with_return(length, it, first, last);
				}
			}

			iterator erase(const_iterator it)
			{
				if (sublist.initial != sublist.terminal)
				{
					--length;
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
						m_exte_policy::lst_ptr::deject::count::with_return(length, first, last);
					else return m_exte_policy::lst_ptr::eject::count::with_return(length, first, last);
				}
			}

			void push_back(const value_type & value)
			{
				++length;
				if (sublist.initial == sublist.terminal)
					sublist.initial=m_exte_policy::lst_ptr::append::with_return(sublist.initial, value);
				else m_exte_policy::lst_ptr::append::no_return(sublist.terminal, value);
			}

			void push_back(value_type && value)
			{
				++length;
				if (sublist.initial == sublist.terminal)
					sublist.initial=m_exte_policy::lst_ptr::append::with_return(sublist.initial, value);
				else m_exte_policy::lst_ptr::append::no_return(sublist.terminal, value);
			}

			void pop_back()
			{
				if (sublist.initial != sublist.terminal)
				{
					--length;
					if (+sublist.initial == sublist.terminal)
						sublist.initial=m_exte_policy::lst_ptr::deject::with_return(sublist.initial);
					else m_exte_policy::lst_ptr::eject::no_return(-sublist.terminal);
				}
			}

			void push_front(const value_type & value)
			{
				++length;
				sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
			}

			void push_front(value_type && value)
			{
				++length;
				sublist.initial=m_exte_policy::lst_ptr::prepend::with_return(sublist.initial, value);
			}

			void pop_front()
			{
				if (sublist.initial != sublist.terminal)
				{
					--length;
					sublist.initial=m_exte_policy::lst_ptr::deject::with_return(sublist.initial);
				}
			}

			void resize(size_type count)
			{
				size_type cap=sublist::size();
				if (count > cap) m_exte_policy::insert(sublist, sublist.terminal, count-cap, value_type());
				length=count;
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=sublist::size();
				if (count > cap) m_exte_policy::insert(sublist, sublist.terminal, count-cap, value);
				length=count;
			}

			void swap(list & other)
			{
				weaklist::iterator oinitial=other.initial, oterminal=other.terminal;
				other.initial=sublist.initial; other.terminal=sublist.terminal;
				sublist.initial=oinitial; sublist.terminal=oterminal;

				size_type olength=other.length;
				other.length=length;
				length=olength;
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
