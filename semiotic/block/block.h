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

#ifndef SEMIOTIC_BLOCK_H
#define SEMIOTIC_BLOCK_H

#include"../../context/block/block.h"

namespace nik
{
	namespace semiotic
	{
/*
	block_traits:
			Such generalized traits might be cleaved in future versions if not being used.
*/
		template<typename T, typename SizeType>
		struct block_traits
		{
			typedef T value_type;
			typedef T& reference;
			typedef T const & const_reference;
			typedef T* pointer;
			typedef T const * const_pointer;
			typedef T* iterator;
			typedef T const * const_iterator;
			typedef SizeType size_type;
		};
/*
	block:
		Basic intuitive members are first (pointer), last (pointer), and length (size_type). Any one can be determined
		from the other two. For consistency of narrative (and method efficiency), first and last have been chosen.
		Assumes an iterator class to navigate its memory space (which is really just a renaming of the pointer type).

		Note, given the definitions of iterator and const_iterator (as builtin array pointers) there is no automatic conversion
		(templated class constructor) from iterator to const_iterator. This provides motivation for the definitions of
		cbegin and cend to allow for type deduction to succeed.
*/
		template<typename T, typename SizeType, SizeType N>
		struct block
		{
			typedef block_traits<T,SizeType> traits;
			typedef typename traits::value_type value_type;
			typedef typename traits::reference reference;
			typedef typename traits::const_reference const_reference;
			typedef typename traits::pointer pointer;
			typedef typename traits::const_pointer const_pointer;
			typedef typename traits::iterator iterator;
			typedef typename traits::const_iterator const_iterator;
			typedef typename traits::size_type size_type;

			pointer array;

			void initialize() { array=new value_type[N]; }
			block() { initialize(); }
/*
	copy:
		Defining pointers in reference to 'v' is intentional---fewer assumptions
		made about "this" makes this function more portable for outside use.
*/
			void copy(const block & v) { context::block<value_type, N>::copy(array, v.array); }
			block(const block & v)
			{
				initialize();
				copy(v);
			}
/*
	terminalize:
		Terminalizing is about freeing up memory. In the case of an array, it's all or nothing, meaning the only
		real option is to deallocate the memory of the whole array.
*/
			void terminalize() { delete [] array; }
			const block & operator = (const block & v)
			{
				terminalize();
				initialize();
				copy(v);
				return *this;
			}
			~block() { terminalize(); }

			reference operator [] (size_type pos) { return array[pos]; }
			const_reference operator [] (size_type pos) const { return array[pos]; }

			size_type size() const { return N; }
			size_type bit_size() const { return 8*sizeof(T)*N; }
		};
	}
}

#endif
