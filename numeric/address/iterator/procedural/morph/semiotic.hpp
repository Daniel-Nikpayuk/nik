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
	The adverb as well as object-adjective arguments are strictly non-const reference values, meaning one cannot
	pass non-reference arguments to them. Although this code is meant to provide a clean narrative interface,
	given its low-level, I have decided against adding any wrappers for user-friendly dispatch cases.

	Though not the intention, this also forces the low-level coder to create a single type-info object to pass
	which is actually good for memory/space efficiency.

	Note:	This collection does not interpret the combination [sub,ob]_adj<backward, [mutate,deallocate], hook>
		and leaves it undefined.
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define PARAMETERS													\
															\
	size_type verb_mask,												\
	typename... F,													\
															\
	typename sub_pointer,												\
															\
	size_type sub_mask,												\
	typename... T


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	tuple/list data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Morph
{
	using Selection = tuple
	<
		adv_list<Connotation::omit_functor, Connotation::apply_functor>,	// functor
		adv_list<Connotation::omit_count, Connotation::apply_count>,		// tracer
		adv_list<Connotation::prototype, Connotation::specialize>		// optimizer
	>;

	template<size_type mask>
	using core = match
	<
		mask,

		Prototype,
		Specialize
	>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct adverb;

	template<size_type mask, typename F>
	struct adverb
	<
		mask,
		core<mask>::rtn,
		F
	> :

			public functor_F<mask, F>,
			public count<mask>

	{
		adverb(const F & f) : functor_F<mask, F>(f) { }
	};

	template<size_type mask>
	struct adverb
	<
		mask,
		core<mask>::rtn
	> :

			public functor<mask>,
			public count<mask>

		{ };

/***********************************************************************************************************************/

	template<size_type mask, typename F>
	using functor_adverb = adverb<functor_cast<mask>::rtn, core<mask>::rtn, F>;

	template<size_type mask, size_type base, typename F>
	static functor_adverb<mask, F> apply_functor(const adverb<mask, base> &, const F & f)
	{
		return functor_adverb<mask, F>(f);
	}

	template<size_type mask>
	using tracer_adverb = adverb<tracer_cast<mask>::rtn, core<mask>::rtn>;

	template<size_type mask, size_type base>
	static tracer_adverb<mask> apply_count(const adverb<mask, base> &, const size_type & c)
	{
		return tracer_adverb<mask>(c);
	}

/***********************************************************************************************************************/

	template<Connotation... params>
	using verb = adverb
	<
		mask<Selection, Connotation, params...>::rtn,
		core<mask<Selection, Connotation, params...>::rtn>::rtn
	>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	using SubjectArrangement = tuple
	<
		adj_list<Association::forward, Association::backward>,						// direction
		adj_list<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		adj_list<Association::mutate, Association::allocate>,						// image
		adj_list<Association::segment, Association::hook, Association::link>				// iterator
	>;

	template<size_type mask>
	using base = match
	<
		mask,

		Closing,
		Closed,
		Opening,
		Open
	>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct adjective;

	template<size_type mask, typename T>
	struct adjective
	<
		mask,
		base<mask>::rtn,
		T
	> :

			public iterate<mask>,
			public memory_T<mask, T>

	{
		adjective(T *o) : memory_T<mask, T>(o) { }
	};


	template<size_type mask>
	struct adjective
	<
		mask,
		base<mask>::rtn
	> :

			public iterate<mask>,
			public memory<mask>

	{
		adjective() : memory<mask>() { }
		adjective(size_type l, size_type o) : memory<mask>(l, o) { }
	};

/***********************************************************************************************************************/

	template<size_type mask>
	using allocate_adjective = adjective<allocate_cast<mask>::rtn, base<mask>::rtn>;

	template<size_type mask, size_type base>
	static allocate_adjective<mask> allocate_segment(const adjective<mask, base> &, size_type l, size_type o = 0)
	{
		return allocate_adjective<mask>(l, o);
	}

/***********************************************************************************************************************/

	template<size_type mask, typename T>
	using deallocate_adjective = adjective<deallocate_cast<mask>::rtn, base<mask>::rtn, T>;

	template<size_type mask, size_type base, typename T>
	static deallocate_adjective<mask, T> deallocate_segment(const adjective<mask, base> &, T *o)
	{
		return deallocate_adjective<mask, T>(o);
	}

/***********************************************************************************************************************/

	template<Association... params>
	using subject = adjective
	<
		mask<SubjectArrangement, Association, params...>::rtn,
		base<mask<SubjectArrangement, Association, params...>::rtn>::rtn
	>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	using ObjectArrangement = tuple
	<
		enum_list<EnumAssociation::succeed, EnumAssociation::accede>,							// increment
		enum_list<EnumAssociation::forward, EnumAssociation::backward>,							// direction
		enum_list<EnumAssociation::closing, EnumAssociation::closed, EnumAssociation::opening, EnumAssociation::open>	// interval
	>;

	template<size_type mask>
	using enum_base = base<mask>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct enum_adjective;

	template<size_type mask, typename T>
	struct enum_adjective
	<
		mask,
		enum_base<mask>::rtn,
		T
	> :

			public iterate<mask>

		{ };


	template<size_type mask>
	struct enum_adjective
	<
		mask,
		enum_base<mask>::rtn
	> :

			public iterate<mask>

		{ };

/***********************************************************************************************************************/

	template<EnumAssociation... params>
	using object = enum_adjective
	<
		mask<ObjectArrangement, EnumAssociation, params...>::rtn,
		base<mask<ObjectArrangement, EnumAssociation, params...>::rtn>::rtn
	>;
};


template<size_type mask, size_type base, typename... params>
using MorphVerb = typename Morph::template adverb<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MorphSubject = typename Morph::template adjective<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MorphObject = typename Morph::template enum_adjective<mask, base, params...>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define STATIC_ASSERT													\
															\
	static_assert													\
	(														\
		sub_directionEnum != Association::backward				||				\
		sub_imageEnum != Association::mutate					||				\
		sub_iteratorEnum != Association::hook					,				\
															\
		"\n\nmap is undefined for Subject<backward, mutate, hook>.\n"						\
	);


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<FULL_PARAMETERS>
static sub_pointer morph(ADV_TYPE(specialize) & ad,

			sub_pointer out, const SUB_ADJ_FULL & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_FULL & ob);
*/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		functor_action<ob>(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	iterate_action(out, sub);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_value_type in, ob_value_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	STATIC_ASSERT

	while (in < end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(opening) & ob)
{
	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	STATIC_ASSERT

	iterate_action(in, ob);

	while (in < end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	STATIC_ASSERT

	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_value_type in, ob_value_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);
	}

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	STATIC_ASSERT

	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
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
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	STATIC_ASSERT

	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	iterate_action(out, sub);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_value_type in, ob_value_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);
	}

	iterate_action(out, sub);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


/*
template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	STATIC_ASSERT

	iterate_action(in, ob);
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ALLOCATE_SEGMENT_MORPH(sub_interval, ob_interval)								\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static sub_pointer morph(ADV_TYPE(prototype) & ad,									\
															\
			sub_pointer & origin, const SUB_ADJ_IMAGE(sub_interval, allocate) & sub,			\
															\
			ob_value_type in, ob_value_type end, const OB_ADJ_INTERVAL(ob_interval) & ob)			\
															\
	{ return morph(ad, memory_action(origin, sub), SUB_ADJ_IMAGE(sub_interval, mutate)(), in, end, ob); }


/***********************************************************************************************************************/


/*
ALLOCATE_SEGMENT_MORPH(closing, closing)
ALLOCATE_SEGMENT_MORPH(closing, closed)
ALLOCATE_SEGMENT_MORPH(closing, opening)
ALLOCATE_SEGMENT_MORPH(closing, open)

ALLOCATE_SEGMENT_MORPH(closed, closing)
ALLOCATE_SEGMENT_MORPH(closed, closed)
ALLOCATE_SEGMENT_MORPH(closed, opening)
ALLOCATE_SEGMENT_MORPH(closed, open)

ALLOCATE_SEGMENT_MORPH(opening, closing)
ALLOCATE_SEGMENT_MORPH(opening, closed)
ALLOCATE_SEGMENT_MORPH(opening, opening)
ALLOCATE_SEGMENT_MORPH(opening, open)

ALLOCATE_SEGMENT_MORPH(open, closing)
ALLOCATE_SEGMENT_MORPH(open, closed)
ALLOCATE_SEGMENT_MORPH(open, opening)
ALLOCATE_SEGMENT_MORPH(open, open)
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef STATIC_ASSERT
#undef ALLOCATE_SEGMENT_MORPH


