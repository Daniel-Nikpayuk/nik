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


#define FORWARD		LIST<Association::forward, intervalEnum, imageEnum, iteratorEnum>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum
>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD> & adj)
{
	++p;
}


/***********************************************************************************************************************/


#define FORWARD_ALLOCATE_HOOK		LIST<Association::forward, intervalEnum, Association::allocate, Association::hook>
#define FORWARD_ALLOCATE_LINK		LIST<Association::forward, intervalEnum, Association::allocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_ALLOCATE_HOOK> & adj)
{
	p = +p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
}


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_ALLOCATE_LINK> & adj)
{
	+p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	-+p = p;
	++p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define BACKWARD		LIST<Association::backward, intervalEnum, imageEnum, iteratorEnum>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum
>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD> & adj)
{
	--p;
}


/***********************************************************************************************************************/


#define BACKWARD_ALLOCATE_HOOK		LIST<Association::backward, intervalEnum, Association::allocate, Association::hook>
#define BACKWARD_ALLOCATE_LINK		LIST<Association::backward, intervalEnum, Association::allocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_ALLOCATE_HOOK> & adj)
{
	pointer tmp = p;
	p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+p = tmp;
}


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_ALLOCATE_LINK> & adj)
{
	-p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+-p = p;
	--p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum,
	typename T
>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD, T> & adj)
{
	++p;
}


/***********************************************************************************************************************/


#define FORWARD_DEALLOCATE_HOOK		LIST<Association::forward, intervalEnum, Association::deallocate, Association::hook>
#define FORWARD_DEALLOCATE_LINK		LIST<Association::forward, intervalEnum, Association::deallocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum, size_type iteratorEnum, typename T>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD_DEALLOCATE_HOOK, T> & adj)
{
	delete p++;
}


template<typename pointer, size_type intervalEnum, size_type iteratorEnum, typename T>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD_DEALLOCATE_LINK, T> & adj)
{
	delete -++p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum,
	typename T
>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD, T> & adj)
{
	--p;
}


/***********************************************************************************************************************/


#define BACKWARD_DEALLOCATE_HOOK	LIST<Association::backward, intervalEnum, Association::deallocate, Association::hook>
#define BACKWARD_DEALLOCATE_LINK	LIST<Association::backward, intervalEnum, Association::deallocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum, size_type iteratorEnum, typename T>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD_DEALLOCATE_HOOK, T> & adj)
{
	delete p--;
}


template<typename pointer, size_type intervalEnum, size_type iteratorEnum, typename T>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD_DEALLOCATE_LINK, T> & adj)
{
	delete +--p;
}


