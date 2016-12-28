/************************************************************************************************************************
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
************************************************************************************************************************/

/*
	memory_action can be called on "out".
*/


/***********************************************************************************************************************/


#define FULL			LIST<esub_directionEnum, esub_intervalEnum, esub_imageEnum, esub_iteratorEnum>

#define ALLOCATE_SEGMENT	LIST<esub_directionEnum, esub_intervalEnum, Association::allocate, Association::segment>

#define DEALLOCATE_SEGMENT	LIST<esub_directionEnum, esub_intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural<nik::semiotic>::template trim<esub_pointer>::pointer::value_type


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	size_type esub_directionEnum,
	size_type esub_intervalEnum,
	size_type esub_imageEnum,
	size_type esub_iteratorEnum
>
static inline void memory_action(const ESubjectAdjective<FULL> & esub)
	{ }


/***********************************************************************************************************************/


// "origin" needs to be a reference value.

template
<
	typename esub_pointer,

	size_type esub_directionEnum,
	size_type esub_intervalEnum
>
static inline esub_pointer memory_action(esub_pointer & origin, const ESubjectAdjective<ALLOCATE_SEGMENT> & esub)
{
	origin = new VALUE_TYPE[esub.length];

	return origin + ((esub_directionEnum == Association::forward) ? esub.offset : esub.length - 1 - esub.offset);
}


/***********************************************************************************************************************/


// "esub" needs to be a reference value.

template
<
	size_type esub_directionEnum,
	size_type esub_intervalEnum,
	typename T
>
static inline void memory_action(ESubjectAdjective<DEALLOCATE_SEGMENT, T> & esub)
{
	delete [] esub.origin;
}


/***********************************************************************************************************************/


#undef FULL

#undef ALLOCATE_SEGMENT

#undef DEALLOCATE_SEGMENT


/***********************************************************************************************************************/


#undef VALUE_TYPE


