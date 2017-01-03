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


struct Shrink
{
	struct Manner
	{
		enum : size_type
		{
			fixor,
			racer,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Connotation::after, Connotation::before, Connotation::between>,		// fixor
			LIST<Connotation::mean, Connotation::fast>					// racer
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


/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
	
template<typename WList>
static void shrink(<before>, WList & out, <closing>)
	{ delete out.initial++; }

template<typename WList, typename WPointer>
static void shrink(<before>, WList & out, <closing>, WPointer end)
{
	ief_policy::disc::clear::no_return(out.initial, end);
	out.initial=end;
}
	
template<typename WList, typename WPointer>
static void shrink(<after>, WList & out, <closing>, WPointer in)
{
	ief_policy::disc::clear::no_return(+in, out.terminal);
	delete out.terminal;
	out.terminal=in;
}

template<typename WList, typename WPointer>
static void shrink(<after, fast>, WList & out, <closing>, WPointer in)
{
	delete out.terminal;
	out.terminal=in;
}

/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/

template<typename WList>
static void shrink(<between>, typename WList::iterator out)
{
	typename WList::iterator in=+(+out);
	delete +out;
	+out=in;
}

template<typename WList, typename WPointer>
static void shrink(<between>, typename WList::iterator out, WPointer end, <closing>)
{
	ief_policy::disc::clear::no_return(+out, end);
	+out=end;
}


