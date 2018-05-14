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


struct Insert
{
	enum struct Manner : size_type
	{
		fixer,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::after, Connotation::before, Connotation::between>		// fixer
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
	Adverb<adv_list<Connotation::fixer>>


/***********************************************************************************************************************/


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<Association::interval>>


/***********************************************************************************************************************/


#define OB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<Association::interval>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(prepend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_int value)
{
	typename Grow::template verb<Connotation::before> before;

	*grow(before, out, new typename sub_list::node) = value;

	return out.initial;
}

/*
	n >= 1.
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(prepend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				size_type n, ob_int value)
{
	typename Grow::template verb<Connotation::before> before;
	typename Repeat::template verb<> identity;

	sub_pointer in=new typename sub_list::node;
	*in=value;

	return grow(before, out, in, repeat(identity, in, n-1, value));
}

/*
	in != end
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(prepend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	typename Grow::template verb<Connotation::before> before;
	typename Map::template verb<> assign;

	sub_pointer tmp=new typename sub_list::node;

	return grow(before, out, tmp, map(assign, tmp, in, end));
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(append) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_int value)
{
	typename Grow::template verb<> after;

	*grow(after, out, new typename sub_list::node) = value;

	return out.terminal;
}

/*
	n >= 1.
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(append) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				size_type n, ob_int value)
{
	typename Grow::template verb<> after;
	typename Repeat::template verb<> identity;

	sub_pointer in=new typename sub_list::node;
	*in=value;

	return grow(after, out, in, repeat(identity, in, n-1, value));
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(append) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & ob)
{
	typename Grow::template verb<> after;
	typename Map::template verb<> assign;

	sub_pointer tmp=new typename sub_list::node;

	return grow(after, out, tmp, map(assign, tmp, in, end));
}

/*
	in != end
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(append) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing, prepost) & ob)
{
	typename Grow::template verb<> after;
	typename Map::template verb<> assign;

	sub_pointer tmp=new typename sub_list::node;

	return grow(after, out, tmp, map(assign, tmp, in, end));
}

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(impend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_int value)
{
	typename Grow::template verb<Connotation::between> between;

	*grow(between, out, new typename sub_list::node) = value;

	return out.initial;
}

/*
	n >= 1.
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(impend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				size_type n, ob_int value)
{
	typename Grow::template verb<Connotation::between> between;
	typename Repeat::template verb<> identity;

	sub_pointer in=new typename sub_list::node;
	*in=value;

	return grow(between, out, in, repeat(identity, in, n-1, value));
}

/*
	in != end
*/

template<SUB_LIST_OB_POINTER_PARAMETERS>
static sub_pointer insert(const ADV_PENDER(impend) & ad,

				sub_list & out, const SUB_ADJ_INTERVAL(closing) & sub,

				ob_pointer in, ob_pointer end, const OB_ADJ_INTERVAL(closing) & sub)
{
	typename Grow::template verb<Connotation::between> between;
	typename Map::template verb<> assign;

	sub_pointer tmp=new typename sub_list::node;

	return grow(between, out, tmp, map(assign, tmp, in, end));
}

