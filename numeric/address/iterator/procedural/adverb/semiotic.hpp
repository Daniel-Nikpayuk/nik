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
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and it is tempting to minimize,
	but 1) This is bad design because I would be relying on an implementation feature to enforce specification design,
	2) Without explicitly specifying them, the compiler cannot distinguish the partial specializations below.
*/



enum struct Connotation : size_type
{
	omit_functor,
	apply_functor,

	omit_count,
	apply_count,

	after,
	before,
	between,

	prototype,
	specialize,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Connotation... params>
using adv_list = typename parameter<Connotation>::template list<params...>;

using null_adv = adv_list<>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params>
struct Adverb { static_assert(true, "this variant is not implemented."); };


/************************************************************************************************************************
							1
***********************************************************************************************************************/


template<typename F>
struct Adverb< adv_list<Connotation::apply_functor>, F>
{
	F functor;

	Adverb(const F & f) : functor(f) { }
};


/***********************************************************************************************************************/


template<typename EnumStruct>
struct Adverb<typename parameter<Connotation>::template list<EnumStruct::apply_count>>
{
	size_type count;
};


/************************************************************************************************************************
							2
***********************************************************************************************************************/


/************************************************************************************************************************
							3
***********************************************************************************************************************/


template<Connotation optimizerEnum>
using OMIT_OMIT = adv_list<Connotation::omit_functor, Connotation::omit_count, optimizerEnum>;

template<Connotation optimizerEnum>
using OMIT_APPLY = adv_list<Connotation::omit_functor, Connotation::apply_count, optimizerEnum>;

template<Connotation optimizerEnum>
using APPLY_OMIT = adv_list<Connotation::apply_functor, Connotation::omit_count, optimizerEnum>;

template<Connotation optimizerEnum>
using APPLY_APPLY = adv_list<Connotation::apply_functor, Connotation::apply_count, optimizerEnum>;


/***********************************************************************************************************************/


template<Connotation optimizerEnum, typename F>
struct Adverb<APPLY_OMIT<optimizerEnum>, F> :

		public Adverb< adv_list<Connotation::apply_functor>, F>,
		public Adverb< null_adv >
{
	using parameter_list = APPLY_OMIT<optimizerEnum>;

	static constexpr Connotation functor_enum		= Connotation::apply_functor;
	static constexpr Connotation tracer_enum		= Connotation::omit_count;
	static constexpr Connotation optimizer_enum		= optimizerEnum;

	Adverb(const F & f) : Adverb< adv_list<Connotation::apply_functor>, F>(f) { }
};


template<Connotation optimizerEnum>
struct Adverb<OMIT_OMIT<optimizerEnum>, void> :

		public Adverb< adv_list<Connotation::omit_functor> >,
		public Adverb< null_adv >
{
	using parameter_list = OMIT_OMIT<optimizerEnum>;

	static constexpr Connotation functor_enum		= Connotation::omit_functor;
	static constexpr Connotation tracer_enum		= Connotation::omit_count;
	static constexpr Connotation optimizer_enum		= optimizerEnum;

//	Type coersion:

	template<typename F>
	static Adverb<APPLY_OMIT<optimizer_enum>, F> as(const F & f)
	{
		return Adverb<APPLY_OMIT<optimizer_enum>, F>(f);
	}
};


/***********************************************************************************************************************/


template<Connotation optimizerEnum, typename F>
struct Adverb<APPLY_APPLY<optimizerEnum>, F> :

		public Adverb< adv_list<Connotation::apply_functor>, F>,
		public Adverb< adv_list<Connotation::apply_count> >
{
	using parameter_list = APPLY_APPLY<optimizerEnum>;

	static constexpr Connotation functor_enum		= Connotation::apply_functor;
	static constexpr Connotation tracer_enum		= Connotation::apply_count;
	static constexpr Connotation optimizer_enum		= optimizerEnum;

	Adverb(const F & f, size_type c) :	Adverb< adv_list<Connotation::apply_functor>, F>(f),
						Adverb< adv_list<Connotation::apply_count> >::count(c) { }
};


template<Connotation optimizerEnum>
struct Adverb<OMIT_APPLY<optimizerEnum>, void> :

		public Adverb< adv_list<Connotation::omit_functor> >,
		public Adverb< adv_list<Connotation::apply_count> >
{
	using parameter_list = OMIT_APPLY<optimizerEnum>;

	static constexpr Connotation functor_enum		= Connotation::omit_functor;
	static constexpr Connotation tracer_enum		= Connotation::apply_count;
	static constexpr Connotation optimizer_enum		= optimizerEnum;

//	Type coersion:

	template<typename F>
	static Adverb<APPLY_APPLY<optimizerEnum>, F> as(const F & f, size_type c = 0)
	{
		return Adverb<APPLY_APPLY<optimizerEnum>, F>(f, c);
	}
};


/***********************************************************************************************************************/


