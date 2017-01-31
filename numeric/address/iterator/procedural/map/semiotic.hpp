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
	size_type sub_mask,												\
	typename... T,													\
															\
	typename ob_pointer,												\
	size_type ob_mask,												\
	typename... A


#define ALLOCATE_SEGMENT_PARAMETERS											\
															\
	size_type verb_mask,												\
	typename... F,													\
															\
	typename sub_pointer,												\
	size_type sub_mask,												\
	typename... T,													\
															\
	typename ob_pointer,												\
	size_type ob_mask,												\
	size_type ob_base,												\
	typename... A


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Map
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
	using sub_base = match
	<
		mask,

		AllocateSegment,

		Closing,
		Closed,
		Opening,
		Open
	>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct sub_adjective;

	template<size_type mask, typename T>
	struct sub_adjective
	<
		mask,
		sub_base<mask>::rtn,
		T
	> :

			public iterate<mask>,
			public memory_T<mask, T>

	{
		sub_adjective(T *o) : memory_T<mask, T>(o) { }
	};


	template<size_type mask>
	struct sub_adjective
	<
		mask,
		sub_base<mask>::rtn
	> :

			public iterate<mask>,
			public memory<mask>

	{
		sub_adjective() : memory<mask>() { }
		sub_adjective(size_type l, size_type o) : memory<mask>(l, o) { }
	};

/***********************************************************************************************************************/

	template<size_type mask>
	using mutate_adjective = sub_adjective<mutate_cast<mask>::rtn, sub_base<mask>::rtn>;

	template<size_type mask, size_type base>
	static mutate_adjective<mask> mutate(const sub_adjective<mask, base> &)
	{
		return mutate_adjective<mask>();
	}

/***********************************************************************************************************************/

	template<size_type mask>
	using allocate_adjective = sub_adjective<allocate_cast<mask>::rtn, sub_base<mask>::rtn>;

	template<size_type mask, size_type base>
	static allocate_adjective<mask> allocate_segment(const sub_adjective<mask, base> &, size_type l, size_type o = 0)
	{
		return allocate_adjective<mask>(l, o);
	}

/***********************************************************************************************************************/

	template<size_type mask, typename T>
	using deallocate_adjective = sub_adjective<deallocate_cast<mask>::rtn, sub_base<mask>::rtn, T>;

	template<size_type mask, size_type base, typename T>
	static deallocate_adjective<mask, T> deallocate_segment(const sub_adjective<mask, base> &, T *o)
	{
		return deallocate_adjective<mask, T>(o);
	}

/***********************************************************************************************************************/

	template<Association... params>
	using subject = sub_adjective
	<
		mask<SubjectArrangement, Association, params...>::rtn,
		sub_base<mask<SubjectArrangement, Association, params...>::rtn>::rtn
	>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	using ObjectArrangement = tuple
	<
		adj_list<Association::forward, Association::backward>,						// direction
		adj_list<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		adj_list<Association::immutate, Association::deallocate>,					// image
		adj_list<Association::segment, Association::hook, Association::link>				// iterator
	>;

	template<size_type mask>
	using ob_base = match
	<
		mask,

		DeallocateSegment,

		Closing,
		Closed,
		Opening,
		Open
	>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct ob_adjective;

	template<size_type mask, typename T>
	struct ob_adjective
	<
		mask,
		ob_base<mask>::rtn,
		T
	> :

			public iterate<mask>,
			public memory_T<mask, T>

		{ };


	template<size_type mask>
	struct ob_adjective
	<
		mask,
		ob_base<mask>::rtn
	> :

			public iterate<mask>,
			public memory<mask>

		{ };

/***********************************************************************************************************************/

	template<Association... params>
	using object = ob_adjective
	<
		mask<ObjectArrangement, Association, params...>::rtn,
		ob_base<mask<ObjectArrangement, Association, params...>::rtn>::rtn
	>;
};


template<size_type mask, size_type base, typename... params>
using MapVerb = typename Map::template adverb<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MapSubject = typename Map::template sub_adjective<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MapObject = typename Map::template ob_adjective<mask, base, params...>;


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
static sub_pointer map(ADV_TYPE(specialize) & ad,

			sub_pointer out, const SUB_ADJ_FULL & sub,

			ob_pointer in, ob_pointer end, OB_ADJ_FULL & ob);
*/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closing, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closing, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	memory_action(ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closing, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closed, A...> & ob)
{
//	STATIC_ASSERT

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
	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closing, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningImmutate, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
	}

	memory_action(ob);

	return out;
}
*/


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closing, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningDeallocate, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());

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
	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closing, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Open, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	memory_action(ob);

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
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closed, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closing, A...> & ob)
{
//	STATIC_ASSERT

	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	iterate_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closed, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closed, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closed, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Opening, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Closed, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Open, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());

	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in, ob);
	count_action(ad);

	iterate_action(in, ob);

	memory_action(ob);

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
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Opening, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closing, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(in, ob);
	}

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Opening, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closed, A...> & ob)
{
//	STATIC_ASSERT

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

	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Opening, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningImmutate, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);
	}

	memory_action(ob);

	return out;
}
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Opening, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningDeallocate, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());
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

	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Opening, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Open, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(in, ob);
	}

	memory_action(ob);

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
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Open, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closing, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Open, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Closed, A...> & ob)
{
//	STATIC_ASSERT

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
	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Open, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningImmutate, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in, ob);
		count_action(ad);
	}

	iterate_action(out, sub);

	memory_action(ob);

	return out;
}
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Open, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, OpeningDeallocate, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());
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
	memory_action(in, ob);

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


/*
template<PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MapSubject<sub_mask, Open, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, Open, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in, ob);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	memory_action(ob);

	return out;
}
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<ALLOCATE_SEGMENT_PARAMETERS>
static sub_pointer map(MapVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, const MapSubject<sub_mask, AllocateSegment, T...> & sub,

			ob_pointer in, ob_pointer end, const MapObject<ob_mask, ob_base, A...> & ob)
{
	auto sub_mutate = Map::mutate(sub);

	return map(ad, memory_action(origin, sub), sub_mutate, in, end, ob);
}
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef STATIC_ASSERT


