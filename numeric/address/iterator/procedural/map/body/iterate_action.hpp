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


#define FORWARD_MUTATE			LIST<Association::forward, Association::mutate, iteratorEnum>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type iteratorEnum
>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_MUTATE> & adj)
{
	++p;
}


/***********************************************************************************************************************/


#define FORWARD_ALLOCATE_SEGMENT	LIST<Association::forward, Association::allocate, Association::segment>
#define FORWARD_ALLOCATE_HOOK		LIST<Association::forward, Association::allocate, Association::hook>
#define FORWARD_ALLOCATE_LINK		LIST<Association::forward, Association::allocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_ALLOCATE_SEGMENT> & adj)
{
	++p;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_ALLOCATE_HOOK> & adj)
{
	p = +p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<FORWARD_ALLOCATE_LINK> & adj)
{
	+p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	-+p = p;
	++p;
}


/***********************************************************************************************************************/


#define FORWARD_DEALLOCATE_SEGMENT	LIST<Association::forward, Association::deallocate, Association::segment>
#define FORWARD_DEALLOCATE_HOOK		LIST<Association::forward, Association::deallocate, Association::hook>
#define FORWARD_DEALLOCATE_LINK		LIST<Association::forward, Association::deallocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD_DEALLOCATE_SEGMENT> & adj)
{
	++p;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD_DEALLOCATE_HOOK> & adj)
{
	delete p++;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<FORWARD_DEALLOCATE_LINK> & adj)
{
	delete -++p;
}


/***********************************************************************************************************************/


#define BACKWARD_MUTATE			LIST<Association::backward, Association::mutate, iteratorEnum>


/***********************************************************************************************************************/


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_MUTATE> & adj)
{
	--p;
}


/***********************************************************************************************************************/


#define BACKWARD_ALLOCATE_SEGMENT	LIST<Association::backward, Association::allocate, Association::segment>
#define BACKWARD_ALLOCATE_HOOK		LIST<Association::backward, Association::allocate, Association::hook>
#define BACKWARD_ALLOCATE_LINK		LIST<Association::backward, Association::allocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_ALLOCATE_SEGMENT> & adj)
{
	--p;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_ALLOCATE_HOOK> & adj)
{
	pointer tmp = p;
	p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+p = tmp;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const SubjectAdjective<BACKWARD_ALLOCATE_LINK> & adj)
{
	-p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+-p = p;
	--p;
}


/***********************************************************************************************************************/


#define BACKWARD_DEALLOCATE_SEGMENT	LIST<Association::backward, Association::deallocate, Association::segment>
#define BACKWARD_DEALLOCATE_HOOK	LIST<Association::backward, Association::deallocate, Association::hook>
#define BACKWARD_DEALLOCATE_LINK	LIST<Association::backward, Association::deallocate, Association::link>


/***********************************************************************************************************************/


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD_DEALLOCATE_SEGMENT> & adj)
{
	--p;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD_DEALLOCATE_HOOK> & adj)
{
	delete p--;
}


template<typename pointer, size_type iteratorEnum>
static void iterate_action(pointer & p, const ObjectAdjective<BACKWARD_DEALLOCATE_LINK> & adj)
{
	delete +--p;
}


