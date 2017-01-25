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


using DeallocateSegment = typename structural<Interface::semiotic>::DeallocateSegment;
using AllocateSegment = typename structural<Interface::semiotic>::AllocateSegment;

using Adjective_Deallocate = typename structural<Interface::semiotic>::Adjective_Deallocate;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural<Interface::semiotic>::template trim<sub_pointer>::node::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	size_type mask
>
static inline void memory_action(const Adjective_Coarse<mask> & adj)
	{ }


/***********************************************************************************************************************/


// "adj" needs to be a reference value.

template
<
	size_type mask,
	typename T
>
static inline void memory_action(Adjective<mask, DeallocateSegment, T> & adj)
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
static inline void memory_action(const pointer & p, const Adjective_Coarse<mask> & adj)
	{ }


/***********************************************************************************************************************/

template<size_type mask, Association... params>
using contains = typename adj_pattern<adj_bit::template list_cast<params...>::rtn>::template in<mask>;

template<size_type mask, bool>
struct dispatch
{
	static size_type offset(const Adjective<mask, AllocateSegment> & sub)
	{
		return sub.offset;
	};
};

template<size_type mask>
struct dispatch<mask, false>
{
	static size_type offset(const Adjective<mask, AllocateSegment> & sub)
	{
		return sub.length - 1 - sub.offset;
	};
};

// "origin" needs to be a reference value.

template
<
	typename sub_pointer,

	size_type mask
>
static inline sub_pointer memory_action(sub_pointer & origin, const Adjective<mask, AllocateSegment> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + dispatch<mask, contains<mask, Association::forward>::rtn>::offset(sub);
}


/***********************************************************************************************************************/


// "p" needs to be a reference value.

template
<
	typename pointer
>
static inline void memory_action(pointer & p, const Adjective_Deallocate & adj)
{
	delete p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef VALUE_TYPE


