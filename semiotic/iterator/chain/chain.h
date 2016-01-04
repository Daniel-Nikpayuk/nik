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

#ifndef SEMIOTIC_ITERATOR_CHAIN_H
#define SEMIOTIC_ITERATOR_CHAIN_H

#include"../topos/topos.h"

namespace nik
{
	namespace semiotic
	{
		namespace iterator
		{
/*
	chain:
		Basic intuitive members are first (pointer), last (pointer), and length (size_type). Any one can be determined
		from the other two. For consistency of narrative (and method efficiency), first and last have been chosen.
		Assumes an iterator class to navigate its memory space (which is really just a renaming of the topos_pointer type).

		My original thinking was---given the preexisting narrative of the array pointer for vectors---that it makes
		the most sense to design a pointer class that actually also holds the memory module it is meant to iterate over.
		Unfortunately, I do not know how to do that with this language (if it's even possible) in a minimalist and efficient way.

		As such, adhering to a weak/strong version of lists/vectors seems best with pointers and iterators attached.
		As the purpose of having a weak class is the likelihood of reuse, it makes sense to make it as minimalist and efficient
		as possible; as such I do not make use here in this code of the existing iterator class for the base constructors
		and accessors. Such a design does not follow the memory saving specification of the library as a whole.  Regardless,
		I still include the iterator class as it might reasonably be used in extensions other than the strong version.

		With regards to vector, initialize() is a shortform for "new T[n]" (as well as setting up "last"), and terminalize()
		is a shortform for deallocation. As such, it should be parallelled here---with the necessary recontextualization.
		The only additional consideration is that deallocation for a pointer array is all or nothing in C++, and so a complete
		purge is necessary. Here though---with lists---it is possible to reinterpret the role of terminalize() to deallocate
		everything but the "last" node. The deciding consideration would be: Is a complete purge ever necessary when working
		with a list ?

		Though it breaks the design slightly, for these very important base classes cpu cycle efficiency matters just as much,
		and so it is not allowed to call from the generic context topos methods, if there's redundancy of code, that's okay.

		*I tested whether to include function calls to initialize() within and it actually does take up more memory,*
		*I tested whether compact code that makes additional initializations
			(while (n--) first=first->edge0=new node(v, 0, first);)
		uses more or less cpu cycles than expanded code that makes less and it seems the compact code is actually better.
		Again, at the low lever as cpu cycles are privileged, compact code is privileged.

		Policy I've decided on:

			If you can declare uninstantiated (and you should be able to), you should also be able to "reset"
			to an uninstantiated state. Additionally, it is often convenient to initialize, as well as terminalize
			(reduce to an initialized state) as seperate operations (not to mention the convenience roles they play
			within the constructors and destructors).
*/
			template<typename T, typename SizeType>
			struct chain
			{
				typedef topos2<T> node;
				typedef typename node::value_type value_type;
				typedef typename node::reference reference;
				typedef typename node::value_type const & const_reference;
				typedef node* pointer;
				typedef node const * const_pointer;
				typedef typename topos2<T, SizeType>::pointer iterator;
				typedef typename topos2<T, SizeType>::const_pointer const_iterator;
				typedef SizeType size_type;

				pointer first;
				pointer last;
/*
		The empty constructor is useful as this is a weak class, meaning as few assumptions as possible are made
		about its use. first and last are initialized for general safety.
*/
				chain() { }
/*
		Note as last == first the chain is technically empty.
*/
				void initialize() { first=last=new node(); }
				void initialize(pointer f, pointer l) { first=last=new node(f, l); }
/*
		Worth having ?
*/
				chain(const value_type & v)
				{
					initialize(0, 0);
					first=first->edge0=new node(v, 0, first);
				}
/*
		Breaks for n < 0.
*/
				chain(size_type n, const value_type & v)
				{
					initialize(0, 0);
					while (n--) first=first->edge0=new node(v, 0, first);
				}
/*
	copy:
		Defining pointers relative to 'l' is intentional---fewer assumptions
		made about "this" chain makes such a function more portable for outside use.

		Assumes first and last as well as l.first and l.last are already instantiated.
*/
				void copy(const chain & l)
				{
					for (const_pointer k(l.first); k != l.last; k=k->edge1)
					{
						last->value=k->value;
						last=last->edge1=new node(last, 0);
					}
				}
				chain(const chain & l)
				{
					initialize(0, 0);
					copy(l);
				}

				void terminalize()
				{
					while (first != last)
					{
						first=first->edge1;
						delete first->edge0;
					}
				}
				void terminalize(pointer f, pointer l)
				{
					terminalize();
					first->edge0=f;
					last->edge1=l;
				}
				const chain & operator = (const chain & l)
				{
					terminalize(0, 0);
					copy(l);
					return *this;
				}

				void destroy()
				{
					terminalize();
					delete last;
				}
				~chain() { destroy(); }

				iterator begin() { return first; }
				const_iterator cbegin() const { return first; }
				iterator end() { return last; }
				const_iterator cend() const { return last; }

				size_type size() const
				{
					size_type n(0);
					for (pointer f(first); f != last; ++n) f=f->edge1;
					return n;
				}
			};
		}
	}
}

#endif
