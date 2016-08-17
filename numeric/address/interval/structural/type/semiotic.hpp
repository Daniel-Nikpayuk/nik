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

	template<typename L>
	struct Traits
	{
		static constexpr size_type interval_enum = at<L, Mod::interval>::rtn;
		static constexpr size_type range_enum = at<L, Mod::range>::rtn;
		static constexpr size_type image_enum = at<L, Mod::image>::rtn;
		static constexpr size_type iterator_enum = at<L, Mod::iterator>::rtn;

		using iteratorTypes = typename gvs_semiotic::template tuple
		<
			segment<value_type>,
			hook<value_type>,
			link<value_type>
		>;

		static constexpr size_type iterator_offset = ModIterator::template bounds<Mod::iterator>::initial;

		using iterator_type = cases<(iterator_enum - iterator_offset), iteratorTypes>;

		using pointer_type = if_then_else
		<
			(image_enum == ModIterator::allocate && iterator_enum == ModIterator::segment),
			size_type,
			typename iterator_type::pointer
		>;

		using return_type = Iterator< list<interval_enum, range_enum, ModIterator::mutate, iterator_enum> >;
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Range
	{
		typedef Traits<L> traits;

		value_type initial;
		value_type terminal;

		Range() { }
		Range(value_type i, value_type t) : initial(i), terminal(t) { }
		Range(const Range & r) : initial(r.initial), terminal(r.terminal) { }
	};

	template<size_type... params>
	using range = Range< sortFill<ModIterator, params...> >;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Iterator
	{
		typedef Traits<L> traits;

		typedef typename traits::iterator_type::pointer pointer;

		typename traits::pointer_type initial;
		typename traits::pointer_type terminal;

		Iterator() { }
		Iterator(typename traits::pointer_type i, typename traits::pointer_type t) : initial(i), terminal(t) { }
		Iterator(const Iterator & i) : initial(i.initial), terminal(i.terminal) { }
	};

	template<size_type... params>
	using iterator = Iterator< sortFill<ModIterator, params...> >;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template<typename L>
	struct Tracer
	{
		static constexpr size_type count_enum = at<L, Mod::tracer>::rtn;

		size_type count;

		Tracer(size_type c = 0) : count(c) { }
		Tracer(const Tracer & t) : count(t.count) { }
	};

	template<size_type... params>
	using tracer = Tracer< sortFill<ModTracer, params...> >;
};


