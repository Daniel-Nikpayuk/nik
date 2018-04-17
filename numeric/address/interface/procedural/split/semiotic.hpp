/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Keep in mind the interpretation of open and closed ends of an interval have different structural interpretations
	than functional. Functional means: if open, don't act on that element, you can still navigate it; if closed,
	both act on it as well as navigate it. Structural means: if open, its content is not relevant, so if you're
	decatenating it, discard; if closed, its content is relevant, so if you're decatenating, keep.
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Split
{
	enum struct SubjectAttribute : size_type
	{
		interval,
		iterator,

		dimension
	};

	using SubjectArrangement = tuple
	<
		adj_list<Association::open, Association::closed>,						// interval
		adj_list<Association::hook, Association::link>							// iterator
	>;

	template<Association... params>
	using subject = Adjective<typename sortFill<SubjectArrangement, Association, params...>::rtn>;

	enum struct ObjectAttribute : size_type
	{
		interval,
		iterator,

		dimension
	};

	using ObjectArrangement = tuple
	<
		adj_list<Association::closed, Association::open>,						// interval
		adj_list<Association::hook, Association::link>							// iterator
	>;

	template<Association... params>
	using object = Adjective<typename sortFill<ObjectArrangement, Association, params...>::rtn>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define CLOSED_HOOK		adj_list<Association::closed, Association::hook>
#define OPEN_HOOK		adj_list<Association::open, Association::hook>

#define CLOSED_LINK		adj_list<Association::closed, Association::link>
#define OPEN_LINK		adj_list<Association::open, Association::link>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural<Interface::semiotic>::template trim<pointer>::node


/************************************************************************************************************************
							hook
************************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer & ps, const Adjective<OPEN_HOOK> & sub, pointer po, const Adjective<CLOSED_HOOK> & ob)
{
	ps = +ps = new NODE_TYPE;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer & ps, const Adjective<OPEN_HOOK> & sub, pointer & po, const Adjective<OPEN_HOOK> & ob)
{
	ps = +ps = new NODE_TYPE;
	pointer rtn = new NODE_TYPE;
	+rtn = po;
	po = rtn;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer ps, const Adjective<CLOSED_HOOK> & sub, pointer po, const Adjective<CLOSED_HOOK> & ob)
{
	+ps = 0;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer ps, const Adjective<CLOSED_HOOK> & sub, pointer po, const Adjective<OPEN_HOOK> & ob)
{
	+ps = 0;

	pointer rtn = new NODE_TYPE;
	+rtn = po;
	po = rtn;
}


/************************************************************************************************************************
							link
************************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer & ps, const Adjective<OPEN_LINK> & sub, pointer po, const Adjective<CLOSED_LINK> & ob)
{
	-po = 0;
	+ps = new NODE_TYPE;
	-+ps = ps;
	++ps;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer & ps, const Adjective<OPEN_LINK> & sub, pointer & po, const Adjective<OPEN_LINK> & ob)
{
	+ps = new NODE_TYPE;
	-+ps = ps;
	++ps;

	-po = new NODE_TYPE;
	+-po = po;
	--po;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer ps, const Adjective<CLOSED_LINK> & sub, pointer po, const Adjective<CLOSED_LINK> & ob)
{
	+ps = 0;
	-po = 0;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void split(pointer ps, const Adjective<CLOSED_LINK> & sub, pointer & po, const Adjective<OPEN_LINK> & ob)
{
	+ps = 0;

	-po = new NODE_TYPE;
	+-po = po;
	--po;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef CLOSED_HOOK
#undef OPEN_HOOK

#undef CLOSED_LINK
#undef OPEN_LINK


