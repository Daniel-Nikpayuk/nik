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


template<typename ValueType>
struct type
{
	typedef ValueType value_type;

	template<typename L> struct Iterator;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Traits
	{
		static constexpr size_type arity_enum = at<L, Mod::arity>::rtn;
		static constexpr size_type direction_enum = at<L, Mod::direction>::rtn;
		static constexpr size_type interval_enum = at<L, Mod::interval>::rtn;
		static constexpr size_type image_enum = at<L, Mod::image>::rtn;
		static constexpr size_type iterator_enum = at<L, Mod::iterator>::rtn;

		static constexpr size_type iterator_offset = ModIterator::template bounds<Mod::iterator>::initial;

		using iteratorTypes = typename gvs_semiotic::template tuple
		<
			segment<value_type>,
			hook<value_type>,
			link<value_type>
		>;

		using iterator_type = cases<(iterator_enum - iterator_offset), iteratorTypes>;
		using pointer_type = typename iterator_type::pointer;

		using mutate_type = Iterator< list<arity_enum, direction_enum, interval_enum, ModIterator::mutate, iterator_enum> >;
		using allocate_type = Iterator< list<arity_enum, direction_enum, interval_enum, ModIterator::allocate, iterator_enum> >;
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Interval
	{
		using traits = Traits<L>;

		value_type initial;
		value_type terminal;

		Interval() { }
		Interval(value_type i, value_type t) : initial(i), terminal(t) { }
		Interval(const Interval & i) : initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


	template<size_type directionEnum, size_type intervalEnum, size_type imageEnum, size_type iteratorEnum>
	struct Interval< list<ModIterator::binary, directionEnum, intervalEnum, imageEnum, iteratorEnum> >
	{
		using traits = Traits< list<ModIterator::binary, directionEnum, intervalEnum, imageEnum, iteratorEnum> >;

		value_type first;
		value_type last;

		value_type initial;
		value_type terminal;

		Interval() { }
		Interval(value_type f, value_type l, value_type i, value_type t) : first(f), last(l), initial(i), terminal(t) { }
		Interval(const Interval & i) : first(i.first), last(i.last), initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


	template<size_type... params>
	using interval = Interval< sortFill<ModIterator, params...> >;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L> struct Iterator { };


/***********************************************************************************************************************/


	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::hook> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::hook> >;

		typedef typename traits::pointer_type pointer;

		pointer initial;
		pointer terminal;

		Iterator() { terminal = initial = new typename traits::iterator_type; }
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};


	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::hook> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::hook> >;

		typedef typename traits::pointer_type pointer;

		pointer initial;
		pointer terminal;

		Iterator(const typename traits::allocate_type & i) : initial(i.initial), terminal(i.terminal) { }
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


//	redundant, but required to resolve deductiion ambiguity.

	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::link> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::link> >;

		typedef typename traits::pointer_type pointer;

		pointer initial;
		pointer terminal;

		Iterator() { terminal = initial = new typename traits::iterator_type; }
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};


	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::link> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::link> >;

		typedef typename traits::pointer_type pointer;

		pointer initial;
		pointer terminal;

		Iterator(const typename traits::allocate_type & i) : initial(i.initial), terminal(i.terminal) { }
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::segment> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::allocate, ModIterator::segment> >;

		typedef typename traits::pointer_type pointer;

		size_type length;
		size_type offset;

		Iterator(size_type l, size_type o = 0) : length(l), offset(o) { }
		Iterator(const Iterator & i) : length(i.length), offset(i.offset) { }
	};


	template<size_type directionEnum, size_type intervalEnum>
	struct Iterator< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::segment> >
	{
		using traits = Traits< list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, ModIterator::segment> >;

		typedef typename traits::pointer_type pointer;

		pointer initial;
		pointer terminal;

		Iterator(const typename traits::allocate_type & i)
		{
			initial = new value_type[i.length];
			terminal = initial + i.offset;
		}
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


	template<size_type directionEnum, size_type intervalEnum, size_type imageEnum, size_type iteratorEnum>
	struct Iterator< list<ModIterator::binary, directionEnum, intervalEnum, imageEnum, iteratorEnum> >
	{
		using traits = Traits< list<ModIterator::binary, directionEnum, intervalEnum, imageEnum, iteratorEnum> >;

		using unary_mutate = list<ModIterator::unary, directionEnum, intervalEnum, ModIterator::mutate, iteratorEnum>;

		typedef typename traits::pointer_type pointer;

		pointer first;
		pointer last;

		pointer initial;
		pointer terminal;

		Iterator(const unary_mutate & i1, const unary_mutate & i2)
			: first(i1.initial), last(i1.terminal), initial(i2.initial), terminal(i2.terminal) { }
		Iterator(const Iterator & i) : first(i.first), last(i.last), initial(i.initial), terminal(i.terminal) { }
	};


/***********************************************************************************************************************/


	template<size_type... params>
	using iterator = Iterator< sortFill<ModIterator, params...> >;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Policy
	{
		static constexpr size_type functor_enum = at<L, Mod::tracer>::rtn;
		static constexpr size_type tracer_enum = at<L, Mod::tracer>::rtn;
		static constexpr size_type optimizer_enum = at<L, Mod::optimizer>::rtn;
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Optimizer
	{
		using policy = Policy<L>;

		Optimizer() { }
		Optimizer(const Optimizer & o) { }
	};


/***********************************************************************************************************************/


	template<size_type optimizerEnum>
	struct Optimizer< list<ModOptimizer::apply_count, optimizerEnum> >
	{
		using policy = Policy< list<ModOptimizer::apply_count, optimizerEnum> >;

		size_type count;

		Optimizer(size_type c = 0) : count(c) { }
		Optimizer(const Optimizer & o) : count(o.count) { }
	};


/***********************************************************************************************************************/


	template<size_type... params>
	using optimizer = Optimizer<sortFill<ModOptimizer, params...> >;
};


