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
	typename ob_value_type,												\
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
	typename ob_value_type,												\
	size_type ob_mask,												\
	size_type ob_base,												\
	typename... A


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

			public enum_divalent_functor_F<mask, F>,
			public count<mask>

	{
		adverb(const F & f) : enum_divalent_functor_F<mask, F>(f) { }
	};

	template<size_type mask>
	struct adverb
	<
		mask,
		core<mask>::rtn
	> :

			public enum_divalent_functor<mask>,
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

			public iterate<mask>
			// no deallocation.

		{ };


	template<size_type mask>
	struct sub_adjective
	<
		mask,
		sub_base<mask>::rtn
	> :

			public iterate<mask>,
			// no deallocation.
			public allo_monovalent_memory<mask>

	{
		sub_adjective() : allo_monovalent_memory<mask>() { }
		sub_adjective(size_type l, size_type o) : allo_monovalent_memory<mask>(l, o) { }
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
		enum_list<EnumAssociation::succeed, EnumAssociation::accede>,							// increment
		enum_list<EnumAssociation::forward, EnumAssociation::backward>,							// direction
		enum_list<EnumAssociation::closing, EnumAssociation::closed, EnumAssociation::opening, EnumAssociation::open>	// interval
	>;

	template<size_type mask>
	using ob_base = match
	<
		mask,

		EnumClosing,
		EnumClosed,
		EnumOpening,
		EnumOpen
	>;

/***********************************************************************************************************************/

	template<size_type mask, size_type base, typename... params>
	struct ob_adjective;

	template<size_type mask, typename A>
	struct ob_adjective
	<
		mask,
		ob_base<mask>::rtn,
		A
	> :

			public enum_iterate_A<mask, A>

		{ };


	template<size_type mask>
	struct ob_adjective
	<
		mask,
		ob_base<mask>::rtn
	> :

			public enum_iterate<mask>

		{ };

/***********************************************************************************************************************/

	template<EnumAssociation... params>
	using object = ob_adjective
	<
		mask<ObjectArrangement, EnumAssociation, params...>::rtn,
		ob_base<mask<ObjectArrangement, EnumAssociation, params...>::rtn>::rtn
	>;
};


template<size_type mask, size_type base, typename... params>
using MorphVerb = typename Morph::template adverb<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MorphSubject = typename Morph::template sub_adjective<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using MorphObject = typename Morph::template ob_adjective<mask, base, params...>;


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


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closing, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosing, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in);
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


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closing, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosed, A...> & ob)
{
//	STATIC_ASSERT

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

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closing, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpening, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closing, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpen, A...> & ob)
{
//	STATIC_ASSERT

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


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closed, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosing, A...> & ob)
{
//	STATIC_ASSERT

	while (in < end)
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


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closed, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosed, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closed, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpening, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Closed, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpen, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, ob);

	while (in < end)
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


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Opening, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosing, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Opening, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosed, A...> & ob)
{
//	STATIC_ASSERT

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

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Opening, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpening, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Opening, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpen, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, ob);

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Open, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosing, A...> & ob)
{
//	STATIC_ASSERT

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


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Open, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumClosed, A...> & ob)
{
//	STATIC_ASSERT

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

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Open, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpening, A...> & ob)
{
//	STATIC_ASSERT

	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	iterate_action(out, sub);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


template<PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, const MorphSubject<sub_mask, Open, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, EnumOpen, A...> & ob)
{
//	STATIC_ASSERT

	iterate_action(in, ob);
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


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<ALLOCATE_SEGMENT_PARAMETERS>
static sub_pointer morph(MorphVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, const MorphSubject<sub_mask, AllocateSegment, T...> & sub,

			ob_value_type in, ob_value_type end, const MorphObject<ob_mask, ob_base, A...> & ob)
{
	auto sub_mutate = Morph::mutate(sub);

	return morph(ad, memory_action(origin, sub), sub_mutate, in, end, ob);
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef ALLOCATE_SEGMENT_PARAMETERS
#undef STATIC_ASSERT


