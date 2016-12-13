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
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and so I do not specify them explicitly.
	Strictly speaking this is bad design because I am relying on an implementation feature to enforce specification design,
	but in this case I'm allowing it. This might change in the future, but I doubt it.
*/


struct Connotation
{
	enum : size_type
	{
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
				LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.
*/


struct Manner
{
	enum : size_type
	{
		tracer,
		optimizer,

		dimension
	};

	using Relation = LIST
	<
		LIST<Connotation::omit_count, Connotation::apply_count>,	// tracer
		LIST<Connotation::prototype, Connotation::specialize>		// optimizer
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L, typename F = void> struct Adverb { };


#define OMIT	LIST<Connotation::omit_count, optimizerEnum>
#define APPLY	LIST<Connotation::apply_count, optimizerEnum>


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct Adverb<OMIT, F>
{
	using parameter_list = OMIT;

	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	F functor;

	Adverb(const F & f) : functor(f) { }
};

template<size_type optimizerEnum>
struct Adverb<OMIT, void>
{
	using parameter_list = OMIT;

	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static Adverb<OMIT, F> as(const F & f)
	{
		return Adverb<OMIT, F>(f);
	}
};


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct Adverb<APPLY, F>
{
	using parameter_list = APPLY;

	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	F functor;
	size_type count;

	Adverb(const F & f, size_type c) : functor(f), count(c) { }
};


template<size_type optimizerEnum>
struct Adverb<APPLY, void>
{
	using parameter_list = APPLY;

	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

//	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static Adverb<APPLY, F> as(const F & f, size_type c = 0)
	{
		return Adverb<APPLY, F>(f, c);
	}
};


/***********************************************************************************************************************/


#undef OMIT
#undef APPLY


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// void as default implies "omit_functor" connotation.


template<size_type... params>
using adverb = Adverb<SORTFILL<Manner, params...>::rtn, void>;


