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

#include"../topos/topos.h"

/*
	list:
		As many of the numbers defined in the "numeric" module will have natural number representation components,
		it makes sense to have a weak class here of such "numeral" elements. A numeral of course is represented relative
		to a given base.

		Regarding the informal namespace: According Wikipedia (on "positional notation") a numeral is a sequence of digits.

		Two alternate designs have, either an "end" digit (node), or, a null pointer signifying the end:

			An end digit is less memory efficient not to mention the need to relink it, but is otherwise more
			compatible with iterators for subclassing---and thus more extensible.

			A null pointer signifier is more efficient but less extensible. On the otherhand, if you were to make
			the "last" pointer a legitimate digit (not just signifier) then you have the best of both worlds,
			not to mention it becomes easier to append to the numeral list as you don't have to figure out what's
			second last (to be able to insert before last). It also fits with the idea that a "numeral" should
			never actually be empty and should default to '0', but such a restriction should not be specified here.

			The final consideration, given that the numeric classes intended to be extended from numeral here are
			additionally intended to be workhorse types for the whole library, and thus cpu efficiency is again
			privileged over memory. The constraint however remains that compromising memory remains limited to constant
			or linear increase. In anycase case, as comparison operators are a basic and repeatedly used test for
			these types, they must be as efficient as possible. In this case, it makes more sense to have
			constant-time access to the "order" of these polynomials (positional notation) as well as their leading
			coefficients for fast comparisons (==; !=; <; <=; >; >=).
*/

namespace nik
{
	namespace semiotic
	{
		namespace iterator
		{
/*
	list:
			rename "digit" to "block"
*/
			template<typename SizeType>
			struct list
			{
				typedef topos1<SizeType, SizeType> digit;
				typedef typename digit::value_type value_type;
				typedef typename digit::reference reference;
				typedef typename digit::value_type const & const_reference;
				typedef digit* pointer;
				typedef digit const * const_pointer;
				typedef typename topos1<SizeType, SizeType>::pointer iterator;
				typedef typename topos1<SizeType, SizeType>::const_pointer const_iterator;
				typedef SizeType size_type;

				pointer initial;
				pointer terminal;

				list() { }

				void initialize() { terminal=initial=new digit(); }
				void initialize(const value_type & v) { terminal=initial=new digit(v, 0); }

				list(const value_type & v) { initialize(v); }
				list(const value_type & v, size_type n)
				{
					initialize(v);
					while (--n) terminal=terminal->edge0=new digit(v, 0);
				}
/*
	copy:
		Defining pointers relative to 'n' is intentional---fewer assumptions
		made about "this" list makes such a function more portable for outside use.

	Assumes initial and n.initial are already instantiated.
*/
				void copy(const list & n)
				{
					for (const_pointer k(n.initial->edge0); k; k=k->edge0)
						terminal=terminal->edge0=new digit(k->value, 0);
				}
/*
	Assumes n.initial is already instantiated.
*/
				list(const list & n)
				{
					initialize(n.initial->value);
					copy(n);
				}

				void terminalize()
				{
					pointer previous;
					while (initial->edge0)
					{
						previous=initial;
						initial=initial->edge0;
						delete previous;
					}
				}
				void terminalize(const value_type & v)
				{
					terminalize();
					initial->value=v;
				}
				const list & operator = (const list & n)
				{
					terminalize(n.initial->value);
					copy(n);
					return *this;
				}

				void destroy()
				{
					terminalize();
					delete terminal;
				}
				~list() { destroy(); }

				iterator begin() { return initial; }
				const_iterator cbegin() const { return initial; }
				iterator end() { return 0; }
				const_iterator cend() const { return 0; }

				size_type size() const
				{
					size_type count(0);
					for (pointer current(initial); current; current=current->edge0) ++count;
					return count;
				}
			};
		}
	}
}

#endif
