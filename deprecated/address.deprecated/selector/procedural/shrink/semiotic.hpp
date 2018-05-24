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
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Shrink
{
	enum struct Manner : size_type
	{
		fixer,
		racer,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::after, Connotation::before, Connotation::between>,		// fixer
		adv_list<Connotation::mean, Connotation::fast>						// racer
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


#define ADV_PARAMETERS_RACER_ONLY											\
															\
	size_type racerEnum,


/***********************************************************************************************************************/


#define SUB_ADJ_PARAMETERS_LIST												\
															\
	typename sub_list


#define SUB_ADJ_PARAMETERS_POINTER											\
															\
	typename sub_pointer


/***********************************************************************************************************************/


#define OB_ADJ_PARAMETERS_POINTER											\
															\
	typename ob_pointer


/***********************************************************************************************************************/


#define SUB_LIST_PARAMETERS												\
															\
	ADV_PARAMETERS_RACER_ONLY											\
															\
	SUB_ADJ_PARAMETERS_LIST


/***********************************************************************************************************************/


#define SUB_LIST_OB_POINTER_PARAMETERS											\
															\
	ADV_PARAMETERS_RACER_ONLY											\
															\
	SUB_ADJ_PARAMETERS_LIST,											\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/


#define SUB_POINTER_PARAMETERS												\
															\
	ADV_PARAMETERS_RACER_ONLY											\
															\
	SUB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_FIXER(fixer)												\
															\
	Adverb<adv_list<Connotation::fixer, racerEnum>>


#define ADV_RACER(fixer, racer)												\
															\
	Adverb<adv_list<Connotation::fixer, Connotation::racer>>


/***********************************************************************************************************************/


#define ADJ_INTERVAL(interval)												\
															\
	Adjective<adv_list<Association::interval>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
	
template<SUB_LIST_PARAMETERS>
static void shrink(const ADV_FIXER(before) & ad,

			sub_list & out, const ADJ_INTERVAL(closing) & sub)

	{ delete out.initial++; }

template<SUB_LIST_OB_POINTER_PARAMETERS>
static void shrink(const ADV_FIXER(before) & ad,

			sub_list & out, const ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	typename IterProcSem::Repeat::template verb<> identity;
	typename IterProcSem::Repeat::template subject<IterAssoc::deallocate, IterAssoc::hook> deallocate;

	out.intial=IterProcSem::repeat(identity, out.initial, in, deallocate);
}
	
template<SUB_LIST_OB_POINTER_PARAMETERS>
static void shrink(const ADV_FIXER(after) & ad,

			sub_list & out, const ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	typename IterProcSem::Repeat::template verb<> identity;
	typename IterProcSem::Repeat::template subject<IterAssoc::open, IterAssoc::deallocate, IterAssoc::hook> deallocate;

	delete IterProcSem::repeat(identity, in, out.terminal, deallocate);
	out.terminal=in;
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static void shrink(const ADV_RACER(after, fast) & ad,

			sub_list & out, const ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	delete out.terminal;
	out.terminal=in;
}

/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/

template<SUB_POINTER_PARAMETERS>
static void shrink(const ADV_FIXER(between) & ad,

			sub_pointer out)
{
	sub_pointer in=+(+out);
	delete +out;
	+out=in;
}

template<SUB_POINTER_PARAMETERS>
static void shrink(const ADV_FIXER(between) & ad,

			sub_pointer out, sub_pointer end, const ADJ_INTERVAL(closing) & sub)
{
	typename IterProcSem::Repeat::template verb<> identity;
	typename IterProcSem::Repeat::template subject<IterAssoc::open, IterAssoc::deallocate, IterAssoc::hook> deallocate;

	+out=IterProcSem::repeat(identity, out, end, deallocate);
}


