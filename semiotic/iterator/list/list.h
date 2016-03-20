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

#ifndef SEMIOTIC_ITERATOR_LIST_H
#define SEMIOTIC_ITERATOR_LIST_H

#include"../traits/traits.h"
#include"../pointer/pointer.h"

/*
	list:
		Choice of the word "list" was hard to settle on. Was tempted to use the word "cascade" as "list"
		is overused, but I've decided on it in the sense of a LISP list. In that sense it is a singly linked list.

		The policy here has taken into consideration two alternate designs: Have an "end" iterator,
		or a null iterator signifying the end.

		An end iterator is less memory efficient not to mention the need to relink it, but is otherwise more
		compatible with iterators for subclassing---and thus more extensible.

		A null iterator signifier is more efficient but less extensible. On the otherhand, if you were to make
		the "last" iterator a legitimate iterator (not just signifier) then you have the best of both worlds,
		not to mention it becomes easier to append to the list as you don't have to figure out what's
		second last (to be able to insert before last).
*/

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
/*
	list:
*/
	template<typename T, typename SizeType=size_t>
	struct list
	{
		typedef traits::container<list, T, SizeType> attributes;
		typedef typename attributes::value_type value_type;
		typedef typename attributes::reference reference;
		typedef typename attributes::const_reference const_reference;
		typedef pointer<T, SizeType, 2> iterator;
		typedef const_pointer<T, SizeType, 2> const_iterator;
		typedef SizeType size_type;

		iterator initial;
		iterator terminal;
/*
	Leaving this constructor empty has higher entropy as other classes that use this might want to custom initialize.
*/
		list() { }

		void initialize() { terminal=initial=iterator::new_pointer(0); }
		void initialize(const value_type & v)
		{
//			terminal=initial=iterator::new_pointer(0);
//			*initial=v;
			terminal=initial=new iterator();
			*initial=v;
			+initial=0;
		}

		list(const value_type & v) { initialize(v); }
/*
	copy:
		Defining iterators relative to 'n' is intentional---fewer assumptions
		made about "this" list makes such a function more portable for outside use.

		Assumes initial and n.initial are already instantiated.
*/
		void copy(const list & n)
		{
			for (const_iterator k=n.initial; k; k=+k)
			{
				*terminal=*k;
				terminal=+terminal=iterator::new_pointer();
			}

			+terminal=0;
		}
/*
	Assumes n.initial is already instantiated.
*/
		list(const list & n)
		{
			initialize();
			copy(n);
		}

		void terminalize()
		{
			iterator previous=initial;
			while (initial)
			{
				initial=+initial;
				previous.terminalize();
				previous=initial;
			}
		}

		const list & operator = (const list & n)
		{
			terminalize();
			initialize();
			copy(n);

			return *this;
		}

		~list() { terminalize(); }

		iterator begin() { return initial; }
		const_iterator cbegin() const { return initial; }
		iterator end() { return 0; }
		const_iterator cend() const { return 0; }
	};
  }
 }
}

#endif
