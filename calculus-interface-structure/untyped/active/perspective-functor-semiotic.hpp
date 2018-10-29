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

		#include nik_typedef(calculus, perspective, untyped, identity)
		#include nik_typedef(calculus, perspective, untyped, functor)
		#include nik_typedef(calculus, kernel, active, functor)

	#undef safe_name

	#include nik_typedef(calculus, kernel, active, structure)
	#include nik_typedef(calculus, untyped, conditional, structure)

/*
	cons:
*/

	template<typename Exp1, typename Exp2>
	struct cons
	{
		using rtn = typename perunf_cons
		<
			typename keracf_evaluate<Exp1>::rtn,
			typename keracf_evaluate<Exp2>::rtn

		>::rtn;
	};

/*
	car:
*/

	template<typename Exp>
	struct car
	{
		using rtn = typename perunf_car
		<
			typename keracf_evaluate<Exp>::rtn

		>::rtn;
	};

/*
	cdr:
*/

	template<typename Exp>
	struct cdr
	{
		using rtn = typename perunf_cdr
		<
			typename keracf_evaluate<Exp>::rtn

		>::rtn;
	};

/*
	catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct catenate<pass<ListType<Values1...>>, pass<ListType<Values2...>>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp1, typename Exp2>
	struct catenate<Exp1, Exp2>
	{
		using rtn = typename catenate
		<
			typename keracf_evaluate<Exp1>::rtn,
			typename keracf_evaluate<Exp2>::rtn

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
		using rtn = typename push<Exp1, pass<typename Exp2::rtn>>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct push<Exp, pass<ListType<Values...>>>
	{
		using rtn = ListType<Values..., typename keracf_evaluate<Exp>::rtn>;
	};

/*
	at:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<size_type index, typename Exp>
	struct at
	{
		using rtn = typename at<index, pass<typename Exp::rtn>>::rtn;
	};

	template<size_type index, typename Value, typename... Values, template<typename...> class ListType>
	struct at<index, pass<ListType<Value, Values...>>>
	{
		using rtn = typename at<index-1, pass<ListType<Values...>>>::rtn;
	};

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct at<0, pass<ListType<Value, Values...>>>
	{
		using rtn = Value;
	};

/*
	length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp, size_type count>
	struct length
	{
		static constexpr size_type value = length<pass<typename Exp::rtn>, count>::value;
	};

	template<typename Value, typename... Values, size_type count, template<typename...> class ListType>
	struct length<pass<ListType<Value, Values...>>, count>
	{
		static constexpr size_type value = length<pass<ListType<Values...>>, count+1>::value;
	};

	template<size_type count, template<typename...> class ListType>
	struct length<pass<ListType<>>, count>
	{
		static constexpr size_type value = count;
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
		using rtn = typename keracf_if_then_else
		<
			Pred::value,
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
		using rtn = typename keracf_evaluate<Exp>::rtn;
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
		using rtn = typename keracf_if_then_else
		<
			Pred::value,
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
	inline static void display(const pass<ListType<Value, Values...>> &, const char *sep = " ")
	{
		static constexpr bool value_is_list		= peruni_is_list<Value>::value;
		static constexpr bool values_is_null		= peruni_is_null<ListType<Values...>>::value;

		static constexpr char l				= value_is_list ? '[' : '(';
		static constexpr char r				= value_is_list ? ']' : ')';

		Kernel::functor::display(l);
		Value::kind::functor::display(Value());
		Kernel::functor::display(r);

		if (!values_is_null) Kernel::functor::display(sep);

		display(pass<ListType<Values...>>(), sep);
	}

	template<template<typename...> class ListType>
	inline static void display(const pass<ListType<>> &, const char *sep = " ")
	{
		// do nothing.
	}

	template<typename Exp>
	inline static void display(const Exp &)
	{
		display(typename Exp::rtn());
	}
};

