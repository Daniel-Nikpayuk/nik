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

#ifndef NIK_MEDIA_ITERATOR_LIST_H
#define NIK_MEDIA_ITERATOR_LIST_H

/*
	Is it better to have subchain as a member or to inherit? Aside from swap I see no reason not to inherit. Is swap really
	needed that badly? Just swap first and last! I've tested it and the memory required doesn't seem to be effected either way.
	As such, I have chosen to inherit.
*/

#include"../../../context/topos/topos2.h"
#include"../../../context/numeric_limits/numeric_limits.h"
#include"../../../semiotic/chain/chain.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
/*
	chain:
*/
	template<typename T, typename SizeType=size_t>
	class chain : protected semiotic::chain<T, SizeType>
	{
		protected:
			typedef context::topos2 method;
			typedef semiotic::chain<T,SizeType> subchain;
		public:
			typedef typename subchain::value_type value_type;
			typedef typename subchain::reference reference;
			typedef typename subchain::const_reference const_reference;
			typedef typename subchain::iterator iterator;
			typedef typename subchain::const_iterator const_iterator;
			typedef typename subchain::size_type size_type;
		protected:
			size_type length;
		public:
			chain() : subchain(0, 0), length(0) { }
		public:
				// element access:
			reference front() { return subchain::first->value; }
			const_reference front() const { return subchain::first->value; }
			reference back() { return subchain::last->edge0->value; }
			const_reference back() const { return subchain::last->edge0->value; }
				// iterators:
			iterator begin() { return subchain::first; }
			const_iterator begin() const { return subchain::first; }
			const_iterator cbegin() const { return subchain::first; }
			iterator end() { return subchain::last; }
			const_iterator end() const { return subchain::last; }
			const_iterator cend() const { return subchain::last; }
				// capacity:
			bool empty() const { return length == 0; }
			size_type size() const { return length; }
			size_type max_size() const { return context::numeric_limits<size_type>::max(); }
				// modifiers:
			void clear() { subchain::terminalize(0, 0); }
/*
	Is not well defined when it is past last.
	In this case the faster algorithm would be to copy the edges as pointers rather than navigating the topoi, probably.
*/
				// more of this code can be refactored into the method template class.
				// write the code first, for this and what's below, then figure out how
				// best to refactor.
			iterator insert(const_iterator it, const value_type & value)
			{
				++length;
				if (it.current == subchain::first) return subchain::first=
					method::prepend(subchain::first, new typename subchain::node(value));
				else return method::impend(const_cast<typename iterator::address>(it.current),
					new typename subchain::node(value));
			}
			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it.current == subchain::first) return subchain::first=
					method::prepend(subchain::first, new typename subchain::node(value));
				else return method::impend(const_cast<typename iterator::address>(it.current),
					new typename subchain::node(value));
			}
	// should the const_cast be here ? or should I centralize it at the generic level ? probably here.
			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it.current == subchain::first) return subchain::first=method::rep0(subchain::first, count, value);
				else
				{
					typename iterator::address i(const_cast<typename iterator::address>(it.current));
					return method::prepend(i, method::rep1(i->edge0, count, value))->edge1;
				}
			}
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
			iterator insert(const_iterator it, int count, const value_type & value)
				{ return insert(it, (size_type) count, value); }
/*
*/
			template<typename InputIterator>
			iterator insert(const_iterator it, InputIterator first, InputIterator last)
			{
				if (first != last)
				{
					if (it.current == subchain::first) return subchain::first=
						method::reverse_prepend_count(subchain::first, length, first, last);
					else return method::impend_count(
						const_cast<typename iterator::address>(it.current), length, first, last);
				}
			}
			iterator erase(const_iterator it)
			{
				if (subchain::first != subchain::last)
				{
					--length;
					if (it.current == subchain::first) return subchain::first=method::deject(subchain::first);
					else return method::eject(const_cast<typename iterator::address>(it.current));
				}
			}
/*
	As first and last *should be* iterators within the bounds of subchain::first and subchain::last, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase(const_iterator first, const_iterator last)
			{
				if (subchain::first != subchain::last && first != last)
				{
					if (first.current == subchain::first) return subchain::first=method::deject_count(length,
						const_cast<typename iterator::address>(first.current),
							const_cast<typename iterator::address>(last.current));
					else return method::eject_count(length,
						const_cast<typename iterator::address>(first.current),
							const_cast<typename iterator::address>(last.current));
				}
			}
			void push_back(const value_type & value)
			{
				++length;
				if (subchain::first == subchain::last) subchain::first=
					method::prepend(subchain::first, new typename subchain::node(value));
				else method::attach(subchain::last, new typename subchain::node(value));
			}
			void push_back(value_type && value)
			{
				++length;
				if (subchain::first == subchain::last) subchain::first=
					method::prepend(subchain::first, new typename subchain::node(value));
				else method::attach(subchain::last, new typename subchain::node(value));
			}
			void pop_back()
			{
				if (subchain::first != subchain::last)
				{
					--length;
					if (subchain::first->edge1 == subchain::last) subchain::first=method::deject(subchain::first);
					else method::eject(subchain::last->edge0);
				}
			}
			void push_front(const value_type & value)
			{
				subchain::first=method::prepend(subchain::first, new typename subchain::node(value));
				++length;
			}
			void push_front(value_type && value)
			{
				subchain::first=method::prepend(subchain::first, new typename subchain::node(value));
				++length;
			}
			void pop_front()
			{
				if (subchain::first != subchain::last)
				{
					subchain::first=method::deject(subchain::first);
					--length;
				}
			}
/*
				void resize(size_type count)
				{
					size_type cap=subchain::size();
					if (count > cap) method::insert(subchain, subchain::last, count-cap, value_type());
					length=count;
				}
				void resize(size_type count, const value_type & value)
				{
					size_type cap=subchain::size();
					if (count > cap) method::insert(subchain, subchain::last, count-cap, value);
					length=count;
				}
*/
			void swap(chain & other)
			{
				typename subchain::pointer first=other.first, last=other.last;
				other.first=subchain::first; other.last=subchain::last;
				subchain::first=first; subchain::last=last;

				size_type olength=other.length;
				other.length=length;
				length=olength;
			}
	};
  }
 }
}

#endif
