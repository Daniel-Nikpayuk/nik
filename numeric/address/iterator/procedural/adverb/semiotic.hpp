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

/*
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and it is tempting to minimize,
	but 1) This is bad design because I would be relying on an implementation feature to enforce specification design,
	2) Without explicitly specifying them, the compiler cannot distinguish the partial specializations below.
*/


struct Connotation
{
	enum : size_type
	{
		omit_functor,
		apply_functor,

		omit_count,
		apply_count,

		prototype,
		specialize,

		dimension
	};
};


/***********************************************************************************************************************/


/*
	Manner Adverbs:
				TUPLE/LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.
*/


struct Manner
{
	enum : size_type
	{
		functor,
		tracer,
		optimizer,

		dimension
	};

	using Relation = TUPLE
	<
		LIST<Connotation::omit_functor, Connotation::apply_functor>,	// functor
		LIST<Connotation::omit_count, Connotation::apply_count>,	// tracer
		LIST<Connotation::prototype, Connotation::specialize>		// optimizer
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L, typename F = void> struct Adverb { };


#define OMIT_OMIT	LIST<Connotation::omit_functor, Connotation::omit_count, optimizerEnum>
#define OMIT_APPLY	LIST<Connotation::omit_functor, Connotation::apply_count, optimizerEnum>

#define APPLY_OMIT	LIST<Connotation::apply_functor, Connotation::omit_count, optimizerEnum>
#define APPLY_APPLY	LIST<Connotation::apply_functor, Connotation::apply_count, optimizerEnum>


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct Adverb<APPLY_OMIT, F>
{
	using parameter_list = APPLY_OMIT;

	static constexpr size_type functor_enum		= Connotation::apply_functor;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	F functor;

	Adverb(const F & f) : functor(f) { }
};


template<size_type optimizerEnum>
struct Adverb<OMIT_OMIT, void>
{
	using parameter_list = OMIT_OMIT;

	static constexpr size_type functor_enum		= Connotation::omit_functor;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	Type coersion:

	template<typename F>
	static Adverb<APPLY_OMIT, F> as(const F & f)
	{
		return Adverb<APPLY_OMIT, F>(f);
	}
};


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct Adverb<APPLY_APPLY, F>
{
	using parameter_list = APPLY_APPLY;

	static constexpr size_type functor_enum		= Connotation::apply_functor;
	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	F functor;
	size_type count;

	Adverb(const F & f, size_type c) : functor(f), count(c) { }
};


template<size_type optimizerEnum>
struct Adverb<OMIT_APPLY, void>
{
	using parameter_list = OMIT_APPLY;

	static constexpr size_type functor_enum		= Connotation::omit_functor;
	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	Type coersion:

	template<typename F>
	static Adverb<APPLY_APPLY, F> as(const F & f, size_type c = 0)
	{
		return Adverb<APPLY_APPLY, F>(f, c);
	}
};


/***********************************************************************************************************************/


#undef OMIT_OMIT
#undef OMIT_APPLY

#undef APPLY_OMIT
#undef APPLY_APPLY


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using adverb = Adverb<SORTFILL<Manner, params...>::rtn, void>;


