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
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural::template trim<sub_pointer>::node::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	size_type mask
>
static inline void memory_action(const adjective<mask> & adj)
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


template
<
	typename pointer,
	size_type mask
>
static inline void memory_action(const pointer & p, const adjective<mask> & adj)
	{ }


/***********************************************************************************************************************/

/*
template<size_type mask, Association... params>
using contains = typename adj_pattern<mask>::template contains
<
	adj_bit::template list_cast<params...>::rtn

>;

template<bool, typename Filler = void>
struct dispatch
{
	static size_type offset(const adjective<AllocateSegment, void> & sub)
	{
		return sub.offset;
	};
};

template<typename Filler>
struct dispatch<false, Filler>
{
	static size_type offset(const adjective<AllocateSegment, void> & sub)
	{
		return sub.length - 1 - sub.offset;
	};
};

// "origin" needs to be a reference value.

template
<
	typename sub_pointer
>
static inline sub_pointer memory_action(sub_pointer & origin, const adjective<AllocateSegment, void> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + dispatch<contains<sub::mask, Association::forward>::rtn>::offset(sub);
}
*/


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
/***********************************************************************************************************************/


template<size_type mask>
using memory = typename dispatch
<
	mask,

	adjective<AllocateSegment, size_type>,
	adjective<Segment>,

	adjective<Iterator>

>::rtn;


template<size_type mask, typename T>
using memory_T = typename dispatch
<
	mask,

	adjective<DeallocateSegment, T>,

	adjective<Iterator>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef VALUE_TYPE


