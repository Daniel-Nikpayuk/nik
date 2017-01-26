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


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural<Interface::semiotic>::template trim<pointer>::node


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & p, const Adjective<Association::forward> & adj)
	{ ++p; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::forward, Association::allocate, Association::hook> & adj)

	{ out = +out = new NODE_TYPE; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::forward, Association::allocate, Association::link> & adj)
{
	+out = new NODE_TYPE;
	-+out = out;
	++out;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::forward, Association::deallocate, Association::hook> & adj)
	{ delete out++; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::forward, Association::deallocate, Association::link> & adj)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::backward> & adj)
	{ --out; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::backward, Association::allocate, Association::hook> & adj)
{
	pointer tmp = out;
	out = new NODE_TYPE;
	+out = tmp;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::backward, Association::allocate, Association::link> & adj)
{
	-out = new NODE_TYPE;
	+-out = out;
	--out;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<Association::backward, Association::deallocate, Association::link> & adj)
	{ delete +--out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template
<
	typename value_type,

	size_type mask,
	typename A
>
static inline void iterate_action(value_type & in, const EnumAdjective<mask, Accede, A> & ob)
	{ ob.accessor(in); }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const EnumAdjective<ENUM_DIRECTION(forward)> & ob)
	{ ++in; }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const EnumAdjective<ENUM_DIRECTION(backward)> & ob)
	{ --in; }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef NODE_TYPE


