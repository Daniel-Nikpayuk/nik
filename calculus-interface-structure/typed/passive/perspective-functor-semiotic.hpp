/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Although it is at this point straightforward to include type deducing versions of the following methods,
	they should be classified and coded as part of the media space, not the semiotic space.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, typed, functor)
		#include nik_typedef(calculus, dispatched, passive, functor)

	#undef safe_name

	#include nik_typedef(calculus, untyped, conditional, structure)

/*
	cons:
*/

	template<typename Type, Type Value, typename Exp>
	struct cons
	{
		using rtn = typename pertyf_cons
		<
			Type,
			Value,
			typename dispaf_evaluate<Exp>::rtn

		>::rtn;
	};

/*
	cdr:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp0, typename Exp1, size_type index = 0>
	struct cdr
	{
		using rtn = typename cdr
		<
			typename dispaf_evaluate<Exp0>::rtn,
			typename dispaf_evaluate<Exp1>::rtn,
			index

		>::rtn;
	};

	template<typename Type, Type Value, Type... Values, size_type index, template<Type...> class ListType>
	struct cdr<Type, ListType<Value, Values...>, index>
	{
		using rtn = typename cdr<Type, ListType<Values...>, index-1>::rtn;
	};

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct cdr<Type, ListType<Value, Values...>, 0>
	{
		using rtn = ListType<Values...>;
	};

/*
	car:
*/

	template<typename Exp0, typename Exp1, size_type index = 0>
	struct car
	{
		using Type = typename dispaf_evaluate<Exp0>::rtn;

		static constexpr Type value = pertyf_car
		<
			Type,
			typename cdr<Type, Exp1, index-1>::rtn

		>::value;
	};

	template<typename Exp0, typename Exp1>
	struct car<Exp0, Exp1, 0>
	{
		using Type = typename dispaf_evaluate<Exp0>::rtn;

		static constexpr Type value = pertyf_car
		<
			Type,
			typename dispaf_evaluate<Exp1>::rtn

		>::value;
	};

/*
	catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct catenate;

	template<typename Type, Type... Values1, Type... Values2, template<Type...> class ListType>
	struct catenate<Type, ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp0, typename Exp1, typename Exp2>
	struct catenate<Exp0, Exp1, Exp2>
	{
		using rtn = typename catenate
		<
			typename dispaf_evaluate<Exp0>::rtn,
			typename dispaf_evaluate<Exp1>::rtn,
			typename dispaf_evaluate<Exp2>::rtn

		>::rtn;
	};

	template<typename Exp0, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct catenate<Exp0, Exp1, Exp2, Exp3, Exps...>
	{
		using Type = typename dispaf_evaluate<Exp0>::rtn;

		using rtn = typename catenate
		<
			Type,
			typename catenate<Type, Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	push:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Type, Type, typename> struct push;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct push<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Values..., Value>;
	};

	template<typename Type, Type Value, typename Exp>
	struct push<Type, Value, act<Exp>>
	{
		using rtn = typename push<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Type, typename, size_type = 0> struct length;

	template<typename Type, Type Value, Type... Values, size_type count, template<Type...> class ListType>
	struct length<Type, ListType<Value, Values...>, count>
	{
		static constexpr size_type value = length<Type, ListType<Values...>, count+1>::value;
	};

	template<typename Type, size_type count, template<Type...> class ListType>
	struct length<Type, ListType<>, count>
	{
		static constexpr size_type value = count;
	};

	template<typename Exp0, typename Exp1, size_type count>
	struct length<Exp0, act<Exp1>, count>
	{
		static constexpr size_type value = length<typename dispaf_evaluate<Exp0>::rtn, typename Exp1::rtn, count>::value;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	inline static void display(const Type & t, const ListType<Value, Values...> &, const char *sep = " ")
	{
		Dispatched::functor::display(sep);
		Dispatched::functor::display(Value);

		display(t, ListType<Values...>(), sep);
	}

	template<typename Type, template<Type...> class ListType>
	inline static void display(const Type &, const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

	template<typename Exp0, typename Exp1>
	inline static void display(const Exp0 &, const Exp1 &, const char *sep = " ")
	{
		display(typename dispaf_evaluate<Exp0>::rtn(), typename dispaf_evaluate<Exp1>::rtn(), sep);
	}
};

