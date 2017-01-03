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


struct Grow
{
	struct Manner
	{
		enum : size_type
		{
			fixor,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Connotation::after, Connotation::before, Connotation::between>		// fixor
		>;
	};

	template<size_type... params>
	using verb = Adverb<SORTFILL<Manner, params...>::rtn, void>;

	struct Attribute
	{
		enum : size_type
		{
			interval,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Association::closing, Association::closed, Association::opening, Association::open>	// interval
		>;
	};

	template<size_type... params>
	using noun = Adjective<SORTFILL<Attribute, params...>::rtn>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename WList, typename WPointer>
static WPointer grow(<before>, WList & out, <closing>, WPointer in)
{
	+in=out.initial;
	out.initial=in;

	return in;
}

template<typename WList, typename WPointer>
static WPointer grow(<before>, WList & out, <closing>, WPointer in, WPointer end)
{
	+end=out.initial;
	out.initial=in;

	return in;
}

template<typename WList, typename WPointer>
static WPointer grow(<after>, WList & out, <closing>, WPointer in)
{
	out.terminal=+out.terminal=in;

	return in;
}

template<typename WList, typename WPointer>
static WPointer grow(<after>, WList & out, <closing>, WPointer in, WPointer end, <closing>)
{
	+out.terminal=in;
	out.terminal=end;

	return end;
}

/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/

template<typename WList, typename WPointer>
static WPointer grow(<between>, typename WList::iterator out, <closing>, WPointer in)
{
	+in=+out;
	+out=in;

	return in;
}

template<typename WList, typename WPointer>
static WPointer grow(<between>, typename WList::iterator out, <closing>, WPointer in, WPointer end, <closing>)
{
	+end=+out;
	+out=in;

	return in;
}


