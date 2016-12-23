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


#define ADV_SPECIALIZE		Adverb<LIST<functorEnum, tracerEnum, Connotation::specialize>, F>


/************************************************************************************************************************/


#define SUB_ADJ_CLOSING		SubjectAdjective<LIST<sub_directionEnum, Association::closing, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_CLOSED		SubjectAdjective<LIST<sub_directionEnum, Association::closed, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_OPENING		SubjectAdjective<LIST<sub_directionEnum, Association::opening, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_OPEN		SubjectAdjective<LIST<sub_directionEnum, Association::open, sub_imageEnum, sub_iteratorEnum>>


/***********************************************************************************************************************/


#define OB_ADJ_CLOSING		ObjectAdjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_CLOSED		ObjectAdjective<LIST<ob_directionEnum, Association::closed, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_OPENING		ObjectAdjective<LIST<ob_directionEnum, Association::opening, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_OPEN		ObjectAdjective<LIST<ob_directionEnum, Association::open, ob_imageEnum, ob_iteratorEnum>, T>


/************************************************************************************************************************/
/************************************************************************************************************************/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum,
	typename T
>
static sub_pointer map(ADV_SPECIALIZE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, OB_ADJ_CLOSING & ob);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#include"body/peek_action.hpp"
#include"body/functor_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_action.hpp"
#include"body/memory_action.hpp"


/***********************************************************************************************************************/


#define ADV_PROTOTYPE													\
		Adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F>


/***********************************************************************************************************************/


#define SUB_ADJ_CLOSING_MUTATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closing, Association::mutate, Association::segment>	\
		>

#define SUB_ADJ_CLOSING_ALLOCATE_SEGMENT										\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closing, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/

#define SUB_ADJ_CLOSED_ALLOCATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closed, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define SUB_ADJ_OPENING_ALLOCATE_SEGMENT										\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::opening, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define SUB_ADJ_OPEN_ALLOCATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::open, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define OB_ADJ_CLOSING_IMMUTATE_SEGMENT											\
		ObjectAdjective												\
		<													\
			LIST<ob_directionEnum, Association::closing, Association::immutate, Association::segment>,	\
			T												\
		>

#define OB_ADJ_CLOSING_DEALLOCATE_SEGMENT										\
		ObjectAdjective												\
		<													\
			LIST<ob_directionEnum, Association::closing, Association::deallocate, Association::segment>,	\
			T												\
		>


/***********************************************************************************************************************/


/***********************************************************************************************************************/






/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum,
	typename T
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	memory_action(ob);

	return out;
}


/*
	allocate, segment:
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum,
	typename T
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer & origin, const SUB_ADJ_CLOSING_ALLOCATE_SEGMENT & sub,

			ob_pointer in, ob_pointer end, OB_ADJ_CLOSING & ob)

	{ return map(ad, memory_action(origin, sub), SUB_ADJ_CLOSING_MUTATE_SEGMENT(), in, end, ob); }


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}
*/


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate<sub_adjective>::apply(out);
			iterate<ob_adjective, Association::deallocate>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate<sub_adjective>::apply(out);
		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}
*/


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(in, ob<mutate>);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(in, ob<mutate>);

	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(in, ob);

	return out;
}
*/


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		iterate_action(in, ob<mutate>);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	return out;
}
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate<ob_adjective, Association::mutate>::apply(variables);
		iterate<sub_adjective>::apply(out);

		while (in != end)
		{
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate<sub_adjective>::apply(out);
			iterate<ob_adjective, Association::deallocate>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(in, ob<mutate>);

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}
*/


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		iterate_action(in, ob<mutate>);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	iterate_action(out, sub);

	return out;
}
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate<ob_adjective, Association::mutate>::apply(variables);
		iterate<sub_adjective>::apply(out);

		while (in != end)
		{
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate<sub_adjective>::apply(out);
			iterate<ob_adjective, Association::deallocate>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		iterate<sub_adjective>::apply(out);
		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


/*
template
<
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	iterate_action(in, ob<mutate>);
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}
*/


