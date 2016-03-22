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
	Is it better to have sublist as a member or to inherit? Aside from swap I see no reason not to inherit. Is swap really
	needed that badly? Just swap first and last! I've tested it and the memory required doesn't seem to be effected either way.
	As such, I have chosen to inherit.

	Two alternate designs have, either an "end" iterator, or, a null iterator signifying the end:

	An end iterator is less memory efficient not to mention the need to relink it, but is otherwise more
	compatible with iterators for subclassing---and thus more extensible.

	A null iterator signifier is more efficient but less extensible. On the otherhand, if you were to make
	the "last" iterator a legitimate iterator (not just signifier) then you have the best of both worlds,
	not to mention it becomes easier to append to the numeral list as you don't have to figure out what's
	second last (to be able to insert before last). It also fits with the application idea that a "numeral"
	should never actually be empty and should default to '0', but such a restriction should not be specified here.

	The final consideration, given that the numeric classes intended to be extended from here are
	additionally intended to be workhorse types for the whole library, and thus cpu efficiency is again
	privileged over memory. The constraint however remains that compromising memory remains limited to constant
	or linear increase. In anycase case, as comparison operators are a basic and repeatedly used test for
	these types, they must be as efficient as possible. In this case, it makes more sense to have
	constant-time access to the "order" of these polynomials (positional notation) as well as their leading
	coefficients for fast comparisons (==; !=; <; <=; >; >=).

	Test against self-assignment!
*/

#include"../../../context/topos/topos2.h"
#include"../../../context/numeric_limits/numeric_limits.h"
#include"../../../semiotic/list/list.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
/*
	list:
*/
	template<typename T, typename SizeType=size_t>
	class list : protected semiotic::list<T, SizeType>
	{
		protected:
			typedef context::topos2 method;
			typedef semiotic::list<T,SizeType> sublist;
		public:
			typedef typename sublist::value_type value_type;
			typedef typename sublist::reference reference;
			typedef typename sublist::const_reference const_reference;
			typedef typename sublist::iterator iterator;
			typedef typename sublist::const_iterator const_iterator;
			typedef typename sublist::size_type size_type;
		protected:
			size_type length;
		public:
			list() : sublist(0, 0), length(0) { }
		public:
				// element access:
			reference front() { return sublist::first->value; }
			const_reference front() const { return sublist::first->value; }
			reference back() { return sublist::last->edge0->value; }
			const_reference back() const { return sublist::last->edge0->value; }
				// iterators:
			iterator begin() { return sublist::first; }
			const_iterator begin() const { return sublist::first; }
			const_iterator cbegin() const { return sublist::first; }
			iterator end() { return sublist::last; }
			const_iterator end() const { return sublist::last; }
			const_iterator cend() const { return sublist::last; }
				// capacity:
			bool empty() const { return length == 0; }
			size_type size() const { return length; }
			size_type max_size() const { return context::numeric_limits<size_type>::max(); }
				// modifiers:
			void clear() { sublist::terminalize(0, 0); }
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
				if (it.current == sublist::first) return sublist::first=
					method::prepend(sublist::first, new typename sublist::node(value));
				else return method::impend(const_cast<typename iterator::address>(it.current),
					new typename sublist::node(value));
			}
			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it.current == sublist::first) return sublist::first=
					method::prepend(sublist::first, new typename sublist::node(value));
				else return method::impend(const_cast<typename iterator::address>(it.current),
					new typename sublist::node(value));
			}
	// should the const_cast be here ? or should I centralize it at the generic level ? probably here.
			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it.current == sublist::first) return sublist::first=method::rep0(sublist::first, count, value);
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
					if (it.current == sublist::first) return sublist::first=
						method::reverse_prepend_count(sublist::first, length, first, last);
					else return method::impend_count(
						const_cast<typename iterator::address>(it.current), length, first, last);
				}
			}
			iterator erase(const_iterator it)
			{
				if (sublist::first != sublist::last)
				{
					--length;
					if (it.current == sublist::first) return sublist::first=method::deject(sublist::first);
					else return method::eject(const_cast<typename iterator::address>(it.current));
				}
			}
/*
	As first and last *should be* iterators within the bounds of sublist::first and sublist::last, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase(const_iterator first, const_iterator last)
			{
				if (sublist::first != sublist::last && first != last)
				{
					if (first.current == sublist::first) return sublist::first=method::deject_count(length,
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
				if (sublist::first == sublist::last) sublist::first=
					method::prepend(sublist::first, new typename sublist::node(value));
				else method::attach(sublist::last, new typename sublist::node(value));
			}
			void push_back(value_type && value)
			{
				++length;
				if (sublist::first == sublist::last) sublist::first=
					method::prepend(sublist::first, new typename sublist::node(value));
				else method::attach(sublist::last, new typename sublist::node(value));
			}
			void pop_back()
			{
				if (sublist::first != sublist::last)
				{
					--length;
					if (sublist::first->edge1 == sublist::last) sublist::first=method::deject(sublist::first);
					else method::eject(sublist::last->edge0);
				}
			}
			void push_front(const value_type & value)
			{
				sublist::first=method::prepend(sublist::first, new typename sublist::node(value));
				++length;
			}
			void push_front(value_type && value)
			{
				sublist::first=method::prepend(sublist::first, new typename sublist::node(value));
				++length;
			}
			void pop_front()
			{
				if (sublist::first != sublist::last)
				{
					sublist::first=method::deject(sublist::first);
					--length;
				}
			}
/*
				void resize(size_type count)
				{
					size_type cap=sublist::size();
					if (count > cap) method::insert(sublist, sublist::last, count-cap, value_type());
					length=count;
				}
				void resize(size_type count, const value_type & value)
				{
					size_type cap=sublist::size();
					if (count > cap) method::insert(sublist, sublist::last, count-cap, value);
					length=count;
				}
*/
			void swap(list & other)
			{
				typename sublist::pointer first=other.first, last=other.last;
				other.first=sublist::first; other.last=sublist::last;
				sublist::first=first; sublist::last=last;

				size_type olength=other.length;
				other.length=length;
				length=olength;
			}
	};
  }
 }
}

#endif
