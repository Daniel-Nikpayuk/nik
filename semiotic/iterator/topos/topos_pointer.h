/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef SEMIOTIC_ITERATOR_TOPOS_POINTER_H
#define SEMIOTIC_ITERATOR_TOPOS_POINTER_H

/*
	The pointers here are more "refined" than you'd expect within the semiotic classification,
	they might not be generic enough relative to the specification of this library, but it does also
	have a symbiotic relationship with topoi to begin with.

	Keep in mind they fall under the category of weak classes (no real safety specifications).
	Strong uses of them would be implemented in the media classification.
	Additionally, though the nik library itself privileges memory efficiency over cpu cycles, given the
	heavy use of pointers the optimization is made here to privilege cpu cycles over memory.

	Due to parallel uses of topos1 and topos2, edge0 for both is considered "backward" (--) while edge1 for topos2
	is considered "forward" (++). This might be considered confusing by some at first, yet it is the less confusing
	of the alternatives. It's a simple enough adjustment to use "--" when working with topos0 iterators. The other
	design possibility was to create a second separate pointer class for both, but that seemed unnecessarily expensive
	for such a low level utility class.
*/

namespace nik
{
	namespace semiotic
	{
		namespace iterator
		{
/*
	topos_pointer_traits:
		const_cast_[...] is a hack allowing for the "toggling" of a type between it and its const version,
		which below allows for constructors which take both types. Both types are needed for conversion
		convenience in defining the list construct.
*/
			template<typename ToposType>
			struct topos_pointer_traits
			{
				typedef typename ToposType::value_type value_type;
				typedef typename ToposType::reference reference;
				typedef typename ToposType::topos_type topos_type;
				typedef typename ToposType::address address;
				typedef typename ToposType::value_type const const_cast_value_type;
				typedef typename ToposType::value_type const & const_cast_reference;
				typedef typename ToposType::topos_type const const_cast_topos_type;
				typedef typename ToposType::topos_type const * const_cast_address;
				typedef typename ToposType::size_type size_type;
			};

			template<typename ToposType>
			struct topos_pointer_traits<ToposType const>
			{
				typedef typename ToposType::value_type const value_type;
				typedef typename ToposType::value_type const & reference;
				typedef typename ToposType::topos_type const topos_type;
				typedef typename ToposType::topos_type const * address;
				typedef typename ToposType::value_type const_cast_value_type;
				typedef typename ToposType::reference const_cast_reference;
				typedef typename ToposType::topos_type const_cast_topos_type;
				typedef typename ToposType::address const_cast_address;
				typedef typename ToposType::size_type size_type;
			};

			template<typename ToposType>
			struct topos_pointer
			{
				typedef topos_pointer_traits<ToposType> traits;
				typedef typename traits::reference reference;
				typedef typename traits::address address;
				typedef typename traits::const_cast_address const_cast_address;
				typedef typename traits::size_type size_type;

				address current;

				topos_pointer() : current(0) { }
/*
	Might be an inefficient method every time "pointer p=0;" is declared in code. Then again, it may not be:
	I don't know the specification or compiler well enough; either might actually optimize.
*/
				topos_pointer(int n) : current(address(0)+n) { }
				topos_pointer(address c) : current(c) { }
				topos_pointer(const_cast_address c) : current(c) { }
//					Allows for the conversion from pointer to const_pointer.
				template<typename TPointer> topos_pointer(TPointer p) : current(p.current) { }
				topos_pointer(const topos_pointer & p) : current(p.current) { }
				const topos_pointer & operator = (const topos_pointer & p)
				{
					current=p.current;
					return *this;
				}
				~topos_pointer() { }

				bool operator == (const topos_pointer & i) { return current == i.current; }
				bool operator != (const topos_pointer & i) { return current != i.current; }

				address operator -> () { return current; }
				address operator & () { return current; }
				reference operator * () { return current->value; }

				topos_pointer operator - (size_type n) const // breaks for n < 0.
				{
					address c(current);
					while (n--) c=c->edge0;
					return c;
				}
				topos_pointer & operator -= (size_type n) // breaks for n < 0.
				{
					while (n--) current=current->edge0;
					return *this;
				}
				topos_pointer & operator -- ()
				{
					current=current->edge0;
					return *this;
				}
				topos_pointer operator -- (int)
				{
					topos_pointer p(current);
					current=current->edge0;
					return p;
				}

				topos_pointer operator + (size_type n) const // breaks for n < 0.
				{
					address c(current);
					while (n--) c=c->edge1;
					return c;
				}
				topos_pointer & operator += (size_type n) // breaks for n < 0.
				{
					while (n--) current=current->edge1;
					return *this;
				}
				topos_pointer & operator ++ ()
				{
					current=current->edge1;
					return *this;
				}
				topos_pointer operator ++ (int)
				{
					topos_pointer p(current);
					current=current->edge1;
					return p;
				}
			};
		}
	}
}

#endif
