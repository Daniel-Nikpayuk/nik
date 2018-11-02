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

struct functor
{
	using kind		= module;

	using type		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, untyped, functor)

	#undef safe_name

	#include nik_typedef(calculus, constant, boolean, structure)
	#include nik_typedef(calculus, constant, number, structure)

	#include nik_typedef(calculus, constant, recursed, structure)
	#include nik_typedef(calculus, constant, recursed, identity)

/*
	if_then_else:
*/

	template<typename Pred, typename Ante, typename Conse>
	struct if_then_else
	{
		using rtn = typename if_then_else<typename Pred::rtn, Ante, Conse>::rtn;
	};

	template<typename Ante, typename Conse>
	struct if_then_else<boolean<true>, Ante, Conse>
	{
		using rtn = typename Ante::rtn;
	};

	template<typename Ante, typename Conse>
	struct if_then_else<boolean<false>, Ante, Conse>
	{
		using rtn = typename Conse::rtn;
	};

/*
	cons:
*/

	template<typename Value, typename List>
	struct cons
	{
		using rtn = typename perunf_cons
		<
			typename Value::rtn,
			typename List::rtn

		>::rtn;
	};

/*
	car:
*/

	template<typename List>
	struct car
	{
		using rtn = typename perunf_car
		<
			typename List::rtn

		>::rtn;
	};

/*
	cdr:
*/

	template<typename List>
	struct cdr
	{
		using rtn = typename perunf_cdr
		<
			typename List::rtn

		>::rtn;
	};

/*
	catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp1, typename Exp2>
	struct catenate<Exp1, Exp2>
	{
		using rtn = typename catenate
		<
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct catenate<Exp1, Exp2, Exp3, Exps...>
	{
		using rtn = typename catenate
		<
			typename catenate<Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	push:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp1, typename Exp2>
	struct push
	{
		using rtn = typename push<Exp1, typename Exp2::rtn>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct push<Exp, ListType<Values...>>
	{
		using rtn = ListType<Values..., typename Exp::rtn>;
	};

/*
	at:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp1, typename Exp2>
	struct at
	{
		using rtn = typename at<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

	template
	<
		size_type index,
		typename Value, typename... Values,
		template<size_type> class Number,
		template<typename...> class ListType
	>
	struct at<Number<index>, ListType<Value, Values...>>
	{
		using rtn = typename at<Number<index-1>, ListType<Values...>>::rtn;
	};

	template
	<
		typename Value, typename... Values,
		template<size_type> class Number,
		template<typename...> class ListType
	>
	struct at<Number<0>, ListType<Value, Values...>>
	{
		using rtn = Value;
	};

/*
	length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp1, typename Exp2 = number<0>>
	struct length
	{
		using rtn = typename length<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

	template
	<
		typename Value, typename... Values,
		size_type count,
		template<typename...> class ListType,
		template<size_type> class Number
	>
	struct length<ListType<Value, Values...>, Number<count>>
	{
		using rtn = typename length<ListType<Values...>, Number<count+1>>::rtn;
	};

	template
	<
		size_type count,
		template<typename...> class ListType,
		template<size_type> class Number
	>
	struct length<ListType<>, Number<count>>
	{
		using rtn = number
		<
			count
		>;
	};

/***********************************************************************************************************************/

/*
	sub_evaluate:
*/

	template<typename...> struct sub_evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct sub_evaluate
	<
		else_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred,
			Exp,

			sub_evaluate
			<
				Exps...
			>

		>::rtn;
	};

	template<typename Exp>
	struct sub_evaluate
	<
		then<Exp>
	>
	{
		using rtn = typename Exp::rtn;
	};

/*
	evaluate:
*/
	template<typename...> struct evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct evaluate
	<
		if_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred,
			Exp,

			sub_evaluate
			<
				Exps...
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Value, typename... Values, template<typename...> class ListType>
	inline static void display(const ListType<Value, Values...> &, const char *sep = " ")
	{
		using value_is_list		= typename is_list<Value>::rtn;
		using values_is_null		= typename is_null<ListType<Values...>>::rtn;

		static constexpr char l		= value_is_list::value ? '[' : '(';
		static constexpr char r		= value_is_list::value ? ']' : ')';

		Dispatched::functor::display(l);
		Value::kind::functor::display(Value());
		Dispatched::functor::display(r);

		if (!values_is_null::value) Dispatched::functor::display(sep);

		display(ListType<Values...>(), sep);
	}

	template<template<typename...> class ListType>
	inline static void display(const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

	template<typename Exp>
	inline static void display(const Exp &, const char *sep = " ")
	{
		display(typename Exp::rtn(), sep);
	}
};

