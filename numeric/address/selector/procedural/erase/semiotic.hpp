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
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Erase
{
	enum struct Manner : size_type
	{
		jector,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::reject, Connotation::deject, Connotation::eject>		// jector
	>;

	template<Connotation... params>
	using verb = Adverb<typename sortFill<Selection, Connotation, params...>::rtn>;

	enum struct Attribute : size_type
	{
		interval,

		dimension
	};

	using Arrangement = tuple
	<
		adj_list<Association::closing, Association::closed, Association::opening, Association::open>	// interval
	>;

	template<Association... params>
	using noun = Adjective<typename sortFill<Arrangement, Association, params...>::rtn>;
};


/***********************************************************************************************************************/


#define SUB_ADJ_PARAMETERS_POINTER											\
															\
	typename sub_pointer


/***********************************************************************************************************************/


#define SUB_POINTER_PARAMETERS												\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_JECTOR(jector)												\
															\
	Adverb<adv_list<Connotation::jector>>


/***********************************************************************************************************************/


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<Association::interval>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/



/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/

template<SUB_POINTER_PARAMETERS>
static void erase(const ADV_JECTOR(deject) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub)
{
	++out;
	delete -out;
	-out=0;
}

/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/

template<SUB_POINTER_PARAMETERS>
static void erase(const ADV_JECTOR(deject) & ad,

			sub_pointer out, sub_pointer end, const SUB_ADJ_INTERVAL(closing) & sub)
{
	-last=0;
	while ((first=+first) != last) delete (-first);
	delete (-first);
}

/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
*/

template<SUB_POINTER_PARAMETERS>
static void erase(const ADV_JECTOR(reject) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub)
{
	t=-t;
	delete (+t);
	+t=0;
}

/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
*/

template<SUB_POINTER_PARAMETERS>
static void erase(const ADV_JECTOR(reject) & ad,

			sub_pointer out, sub_pointer end, const SUB_ADJ_INTERVAL(closing) & sub)
{
	RPointer rtn=-first;
	+rtn=0;
	while ((first=+first) != last) delete (-first);
	delete (-first);
	delete first;
}

/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/

template<SUB_POINTER_PARAMETERS>
static void erase(const ADV_JECTOR(reject, apply_count) & ad,

			sub_pointer out, sub_pointer end, const SUB_ADJ_INTERVAL(closing) & sub)
{
	RPointer rtn=-first;
	+rtn=0;
	for (--count; (first=+first) != last; --count) delete (-first);
	delete (-first);
	delete first;
}

template<SUB_POINTER_PARAMETERS>
static WPointer erase(const ADV_JECTOR & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub)
{
	WPointer in=+(+out);
	delete +out;
	+out=in;

	return in;
}

template<SUB_POINTER_PARAMETERS>
static WPointer erase(const ADV_JECTOR & ad,

			sub_pointer out, sub_pointer end, const SUB_ADJ_INTERVAL(closing) & sub)
{
	typename IterProcSem::Repeat::template verb<> identity;
	typename IterProcSem::Repeat::template subject<IterAssoc::open, IterAssoc::deallocate, IterAssoc::hook> deallocate;

	+out=repeat(identity, out, end, deallocate);

	return end;
}

