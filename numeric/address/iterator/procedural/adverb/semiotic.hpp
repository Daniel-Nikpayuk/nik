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


// Manner Adverbs:


struct Manner
{
	enum : size_type
	{
		functor,
		tracer,
		optimizer,
		dimension
	};
};


/***********************************************************************************************************************/


struct Connotation
{
	static constexpr size_type dimension = Manner::dimension;

	template<size_type, typename Filler = void> struct bounds;

	enum : size_type
	{
		omit_functor,
		apply_functor,

		omit_count,
		apply_count,

		prototype,
		specialize
	};

	template<typename Filler>
	struct bounds<Manner::functor, Filler>
	{
		static constexpr size_type initial = omit_functor;
		static constexpr size_type terminal = apply_functor;
	};

	template<typename Filler>
	struct bounds<Manner::tracer, Filler>
	{
		static constexpr size_type initial = omit_count;
		static constexpr size_type terminal = apply_count;
	};

	template<typename Filler>
	struct bounds<Manner::optimizer, Filler>
	{
		static constexpr size_type initial = prototype;
		static constexpr size_type terminal = specialize;
	};
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L, typename F = void> struct _adverb { };


#define OMIT_OMIT	LIST<Connotation::omit_functor, Connotation::omit_count, optimizerEnum>
#define OMIT_APPLY	LIST<Connotation::omit_functor, Connotation::apply_count, optimizerEnum>
#define APPLY_OMIT	LIST<Connotation::apply_functor, Connotation::omit_count, optimizerEnum>
#define APPLY_APPLY	LIST<Connotation::apply_functor, Connotation::apply_count, optimizerEnum>


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct _adverb<APPLY_OMIT, F>
{
	using parameter_list = APPLY_OMIT;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	F functor;

	_adverb(const F & f) : functor(f) { }
};

template<size_type optimizerEnum>
struct _adverb<OMIT_OMIT, void>
{
	using parameter_list = OMIT_OMIT;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static _adverb<APPLY_OMIT, F> as(const F & f)
	{
		return _adverb<APPLY_OMIT, F>(f);
	}
};


/***********************************************************************************************************************/


template<size_type optimizerEnum, typename F>
struct _adverb<APPLY_APPLY, F>
{
	using parameter_list = APPLY_APPLY;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	F functor;
	size_type count;

	_adverb(const F & f, size_type c) : functor(f), count(c) { }
};

template<size_type optimizerEnum>
struct _adverb<OMIT_APPLY, void>
{
	using parameter_list = OMIT_APPLY;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static _adverb<APPLY_APPLY, F> as(const F & f, size_type c = 0)
	{
		return _adverb<APPLY_APPLY, F>(f, c);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using adverb = _adverb<SORTFILL<Connotation, params...>::rtn, void>;


