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


#define ALLOCATE_SEGMENT	adj_list<sub_directionEnum, Association::allocate, Association::segment>

#define DEALLOCATE		adj_list<Association::deallocate>

#define DEALLOCATE_SEGMENT	adj_list<Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural<Interface::semiotic>::template trim<sub_pointer>::node::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


static inline void memory_action(const Adjective<null_list> & adj)
	{ }


/***********************************************************************************************************************/


// "adj" needs to be a reference value.

template
<
	typename T
>
static inline void memory_action(Adjective<DEALLOCATE_SEGMENT, T> & adj)
{
	delete [] adj.origin;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void memory_action(const pointer & p, const Adjective<null_list> & adj)
	{ }


/***********************************************************************************************************************/


// "origin" needs to be a reference value.

template
<
	typename sub_pointer,

	Association sub_directionEnum
>
static inline sub_pointer memory_action(sub_pointer & origin, const Adjective<ALLOCATE_SEGMENT> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + ((sub_directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset);
}


/***********************************************************************************************************************/


// "p" needs to be a reference value.

template
<
	typename pointer
>
static inline void memory_action(pointer & p, const Adjective<DEALLOCATE> & adj)
{
	delete p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ALLOCATE_SEGMENT

#undef DEALLOCATE

#undef DEALLOCATE_SEGMENT


/***********************************************************************************************************************/


#undef VALUE_TYPE


