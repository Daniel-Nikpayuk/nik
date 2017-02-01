/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
************************************************************************************************************************/

/*
	memory_action can be called on both "out" as well as "in" pointers, as well as "ob" adjectives alone.

	If you're using the bitmask approach:

	In the case one needs alternate dispatch defaults (see: Image, Not_Deallocate, Not_Allocate), it can be
	combinatorially shown one has 2^n-n possible values to choose from. Regarding infill extensibility,
	every context will be different. If 2^n-n is not enough, your design itself may be insufficient. If n is less
	than the bitsize one should have more possible values to choose from. One can also expand into using other
	Attributes/Manners, but this becomes a probabilistic game of collision. Regardless, how you decide enumerate such
	choices will inevitably suffer from complexity. However you decide to choose, document well.
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural::template trim<sub_pointer>::node::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


static inline void memory_action(const adjective<Image> & adj)
	{ }


/***********************************************************************************************************************/


// "adj" needs to be a reference value.

template
<
	typename T
>
static inline void memory_action(adjective<DeallocateSegment, T> & adj)
{
	delete [] adj.origin;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using valent_memory = typename dispatch
<
	mask,

	adjective<Image>

>::rtn;


template<size_type mask, typename T>
using valent_memory_T = typename dispatch
<
	mask,

	adjective<DeallocateSegment, T>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


static constexpr size_type Not_Deallocate = deduct<Image, Deallocate>::rtn;


template
<
	typename pointer
>
static inline void memory_action(const pointer & p, const adjective<Not_Deallocate> & adj)
	{ }


/***********************************************************************************************************************/


// "p" needs to be a reference value.

template
<
	typename pointer
>
static inline void memory_action(pointer & p, const adjective<Deallocate> & adj)
{
	delete p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using deallo_monovalent_memory = typename dispatch
<
	mask,

	adjective<Deallocate>,

	adjective<Not_Deallocate>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


static constexpr size_type Not_Allocate = deduct<Image, Allocate>::rtn;


template
<
	typename pointer
>
static inline void memory_action(const pointer & p, const adjective<Not_Allocate> & adj)
	{ }


/***********************************************************************************************************************/


/*
	"mask" cannot be deduced, and is supplied to determine forward or backward behaviour.

	"origin" needs to be a reference value.
*/

template
<
	size_type mask,

	typename sub_pointer
>
static inline sub_pointer memory_action(sub_pointer & origin, const adjective<AllocateSegment, size_type> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + bit::mask::template contains<mask, Association::forward>::rtn ?

			sub.offset :
			sub.length - 1 - sub.offset;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using allo_monovalent_memory = typename dispatch
<
	mask,

	adjective<AllocateSegment, size_type>,

	adjective<Not_Allocate>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef VALUE_TYPE


