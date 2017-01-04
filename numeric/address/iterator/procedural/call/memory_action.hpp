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


#define SUB_FULL		adj_list<sub_directionEnum, sub_intervalEnum, sub_imageEnum, sub_iteratorEnum>

#define OB_FULL			adj_list<ob_directionEnum, ob_intervalEnum, ob_imageEnum, ob_iteratorEnum>

#define ALLOCATE_SEGMENT	adj_list<sub_directionEnum, sub_intervalEnum, Association::allocate, Association::segment>

#define DEALLOCATE		adj_list<directionEnum, intervalEnum, Association::deallocate, iteratorEnum>

#define DEALLOCATE_SEGMENT	adj_list<directionEnum, intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural<Interface::semiotic>::template trim<sub_pointer>::node::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	Association sub_directionEnum,
	Association sub_intervalEnum,
	Association sub_imageEnum,
	Association sub_iteratorEnum
>
static inline void memory_action(const Adjective<SUB_FULL> & sub)
	{ }


/***********************************************************************************************************************/


template
<
	typename sub_pointer,

	Association sub_directionEnum,
	Association sub_intervalEnum,
	Association sub_imageEnum,
	Association sub_iteratorEnum
>
static inline void memory_action(const sub_pointer & out, const Adjective<SUB_FULL> & sub)
	{ }


/***********************************************************************************************************************/


template
<
	typename ob_pointer,

	Association ob_directionEnum,
	Association ob_intervalEnum,
	Association ob_imageEnum,
	Association ob_iteratorEnum,
	typename T
>
static inline void memory_action(const ob_pointer & in, const Adjective<OB_FULL, T> & ob)
	{ }


/***********************************************************************************************************************/


template
<
	Association ob_directionEnum,
	Association ob_intervalEnum,
	Association ob_imageEnum,
	Association ob_iteratorEnum,
	typename T
>
static inline void memory_action(const Adjective<OB_FULL, T> & ob)
	{ }


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// "origin" needs to be a reference value.

template
<
	typename sub_pointer,

	Association sub_directionEnum,
	Association sub_intervalEnum
>
static inline sub_pointer memory_action(sub_pointer & origin, const Adjective<ALLOCATE_SEGMENT> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + ((sub_directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset);
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// "adj" needs to be a reference value.

template
<
	Association directionEnum,
	Association intervalEnum,
	typename T
>
static inline void memory_action(Adjective<DEALLOCATE_SEGMENT, T> & adj)
{
	delete [] adj.origin;
}


/***********************************************************************************************************************/


// "p" needs to be a reference value.

template
<
	typename pointer,

	Association directionEnum,
	Association intervalEnum,
	Association iteratorEnum,
	typename T
>
static inline void memory_action(pointer & p, const Adjective<DEALLOCATE, T> & adj)
{
	delete p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef FULL

#undef ALLOCATE_SEGMENT

#undef DEALLOCATE

#undef DEALLOCATE_SEGMENT


/***********************************************************************************************************************/


#undef VALUE_TYPE


