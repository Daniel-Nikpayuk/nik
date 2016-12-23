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


#define DEFAULT			LIST<directionEnum, intervalEnum, imageEnum, iteratorEnum>

#define ALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::allocate, Association::segment>

#define DEALLOCATE		LIST<directionEnum, intervalEnum, Association::deallocate, iteratorEnum>

#define DEALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type directionEnum,
	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum
>
static void memory_action(const pointer & out, const SubjectAdjective<DEFAULT> & sub)
	{ }


/***********************************************************************************************************************/


#define VALUE_TYPE	typename structural<nik::semiotic>::template trim<pointer>::pointer::value_type

// "origin" needs to be a reference.

template
<
	typename pointer,

	size_type directionEnum,
	size_type intervalEnum
>
static pointer memory_action(pointer & origin, const SubjectAdjective<ALLOCATE_SEGMENT> & sub)
{
	origin = new VALUE_TYPE[sub.length];

	return origin + ((directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset);
}


#undef VALUE_TYPE


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type directionEnum,
	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum,
	typename T
>
static void memory_action(const pointer & in, const ObjectAdjective<DEFAULT, T> & ob)
	{ }


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type directionEnum,
	size_type intervalEnum,
	size_type iteratorEnum,
	typename T
>
static void memory_action(pointer in, const ObjectAdjective<DEALLOCATE, T> & ob)
{
	delete in;
}


/***********************************************************************************************************************/


template
<
	size_type directionEnum,
	size_type intervalEnum,
	typename T
>
static void memory_action(ObjectAdjective<DEALLOCATE_SEGMENT, T> & ob)
{
	delete [] ob.origin;
}


/***********************************************************************************************************************/


#undef DEFAULT

#undef ALLOCATE_SEGMENT

#undef DEALLOCATE

#undef DEALLOCATE_SEGMENT


