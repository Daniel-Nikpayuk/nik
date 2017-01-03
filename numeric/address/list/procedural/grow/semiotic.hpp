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
			fixer,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Connotation::after, Connotation::before, Connotation::between>		// fixer
		>;
	};

	template<size_type... params>
	using verb = Adverb<SORTFILL<Manner, params...>::rtn>;

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


#define SUB_ADJ_PARAMETERS_LIST												\
															\
	typename sub_list,


#define SUB_ADJ_PARAMETERS_POINTER											\
															\
	typename sub_pointer,


/***********************************************************************************************************************/


#define OB_ADJ_PARAMETERS_POINTER											\
															\
	typename ob_pointer


/***********************************************************************************************************************/


#define SUB_LIST_OB_POINTER_PARAMETERS											\
															\
	SUB_ADJ_PARAMETERS_LIST												\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/


#define SUB_POINTER_OB_POINTER_PARAMETERS										\
															\
	SUB_ADJ_PARAMETERS_POINTER											\
															\
	OB_ADJ_PARAMETERS_POINTER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_TYPE(fixer)													\
															\
	Adverb<LIST<Connotation::fixer>>


/***********************************************************************************************************************/


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<LIST<Association::interval>>


/***********************************************************************************************************************/


#define OB_ADJ_INTERVAL(interval)											\
															\
	Adjective<LIST<Association::interval>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	+in=out.initial;
	out.initial=in;

	return in;
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(before) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=out.initial;
	out.initial=in;

	return in;
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(after) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	out.terminal=+out.terminal=in;

	return in;
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(after) & ad,

			sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+out.terminal=in;
	out.terminal=end;

	return end;
}

/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/

template<SUB_POINTER_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(between) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in)
{
	+in=+out;
	+out=in;

	return in;
}

template<SUB_POINTER_OB_POINTER_PARAMETERS>
static ob_pointer grow(const ADV_TYPE(between) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	+end=+out;
	+out=in;

	return in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef SUB_ADJ_PARAMETERS_LIST
#undef SUB_ADJ_PARAMETERS_POINTER
#undef OB_ADJ_PARAMETERS_POINTER
#undef SUB_LIST_OB_POINTER_PARAMETERS
#undef SUB_POINTER_OB_POINTER_PARAMETERS
#undef ADV_TYPE
#undef SUB_ADJ_INTERVAL
#undef OB_ADJ_INTERVAL


