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
		omit_assign,
		apply_assign,

		omit_count,
		apply_count,

		prototype,
		specialize
	};

	template<typename Filler>
	struct bounds<Manner::functor, Filler>
	{
		static constexpr size_type initial = omit_assign;
		static constexpr size_type terminal = apply_assign;
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


template<typename... params> struct _adverb { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct _adverb<L>
{
	using parameter_list = L;

	static constexpr size_type functor_enum		= AT<L, Manner::functor		>::rtn;
	static constexpr size_type tracer_enum		= AT<L, Manner::tracer		>::rtn;
	static constexpr size_type optimizer_enum	= AT<L, Manner::optimizer	>::rtn;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	_adverb() { }
};


/***********************************************************************************************************************/


template<size_type optimizerEnum>
using omit_omit = LIST<Connotation::omit_assign, Connotation::omit_count, optimizerEnum>;

template<size_type optimizerEnum, typename F>
struct _adverb<omit_omit<optimizerEnum>, F>
{
	using parameter_list = omit_omit<optimizerEnum>;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	F functor;

	_adverb(const F & f) : functor(f) { }
};

template<size_type optimizerEnum>
struct _adverb<omit_omit<optimizerEnum>>
{
	using parameter_list = omit_omit<optimizerEnum>;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::omit_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static _adverb<parameter_list, F> with(const F & f)
	{
		return _adverb<parameter_list, F>(f);
	}
};


/***********************************************************************************************************************/


template<size_type optimizerEnum>
using omit_apply = LIST<Connotation::omit_assign, Connotation::apply_count, optimizerEnum>;

template<size_type optimizerEnum, typename F>
struct _adverb<omit_apply<optimizerEnum>, F>
{
	using parameter_list = omit_apply<optimizerEnum>;

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
struct _adverb<omit_apply<optimizerEnum>>
{
	using parameter_list = omit_apply<optimizerEnum>;

	static constexpr size_type functor_enum		= Connotation::omit_assign;
	static constexpr size_type tracer_enum		= Connotation::apply_count;
	static constexpr size_type optimizer_enum	= optimizerEnum;

	static constexpr size_type functor_offset = Connotation::template bounds<Manner::functor>::initial;
	static constexpr size_type optimizer_offset = Connotation::template bounds<Manner::optimizer>::initial;

	template<typename F>
	static _adverb<parameter_list, F> with(const F & f, size_type c = 0)
	{
		return _adverb<parameter_list, F>(f, c);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using adverb = _adverb<SORTFILL<Connotation, params...>::rtn>;


