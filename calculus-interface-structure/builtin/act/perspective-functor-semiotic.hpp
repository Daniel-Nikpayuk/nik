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

		#include nik_typedef(calculus, perspective, builtin, functor)

	#undef safe_name

	#include nik_typedef(calculus, builtin, act, structure)

/*
	dereference:
*/

	template<typename> struct dereference;

	template<typename Exp>
	struct dereference<act<Exp>>
	{
		using rtn = typename perbuf_dereference<typename Exp::rtn>::rtn;
	};

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Value, typename Exp>
	struct cons<Value, act<Exp>>
	{
		using rtn = typename perbuf_cons<Value, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Value>
	struct cons<act<Exp>, Value>
	{
		using rtn = typename perbuf_cons<typename Exp::rtn, Value>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct cons<act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_cons<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	typed_cons:
*/

	template<typename Type, Type, typename> struct typed_cons;

	template<typename Type, Type Value, typename Exp>
	struct typed_cons<Type, Value, act<Exp>>
	{
		using rtn = typename perbuf_typed_cons<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	car:
*/

	template<typename> struct car;

	template<typename Exp>
	struct car<act<Exp>>
	{
		using rtn = typename perbuf_car<typename Exp::rtn>::rtn;
	};

/*
	typed_car:
*/

	template<typename Type, typename> struct typed_car;

	template<typename Type, typename Exp>
	struct typed_car<Type, act<Exp>>
	{
		static constexpr Type value = perbuf_typed_car<Type, typename Exp::rtn>::value;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename Exp>
	struct cdr<act<Exp>>
	{
		using rtn = typename perbuf_cdr<typename Exp::rtn>::rtn;
	};

/*
	typed_cdr:
*/

	template<typename Type, typename> struct typed_cdr;

	template<typename Type, typename Exp>
	struct typed_cdr<Type, act<Exp>>
	{
		using rtn = typename perbuf_typed_cdr<Type, typename Exp::rtn>::rtn;
	};

/*
	catenate:
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = typename perbuf_catenate
		<
			ListType<Values1...>,
			ListType<Values2...>

		>::rtn;
	};

	template<typename... Values, typename Exp, template<typename...> class ListType>
	struct catenate<ListType<Values...>, act<Exp>>
	{
		using rtn = typename perbuf_catenate
		<
			ListType<Values...>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct catenate<act<Exp>, ListType<Values...>>
	{
		using rtn = typename perbuf_catenate
		<
			typename Exp::rtn,
			ListType<Values...>

		>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct catenate<act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_catenate
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
	typed_catenate:
*/

	template<typename Type, typename, typename, typename...> struct typed_catenate;

	template<typename Type, Type... Values1, Type... Values2, template<Type...> class ListType>
	struct typed_catenate<Type, ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = typename perbuf_typed_catenate
		<
			Type,
			ListType<Values1...>,
			ListType<Values2...>

		>::rtn;
	};

	template<typename Type, Type... Values, typename Exp, template<Type...> class ListType>
	struct typed_catenate<Type, ListType<Values...>, act<Exp>>
	{
		using rtn = typename perbuf_typed_catenate
		<
			Type,
			ListType<Values...>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Type, typename Exp, Type... Values, template<Type...> class ListType>
	struct typed_catenate<Type, act<Exp>, ListType<Values...>>
	{
		using rtn = typename perbuf_typed_catenate
		<
			Type,
			typename Exp::rtn,
			ListType<Values...>

		>::rtn;
	};

	template<typename Type, typename Exp1, typename Exp2>
	struct typed_catenate<Type, act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_typed_catenate
		<
			Type,
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Type, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct typed_catenate<Type, Exp1, Exp2, Exp3, Exps...>
	{
		using rtn = typename typed_catenate
		<
			Type,
			typename typed_catenate<Type, Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename Value, typename Exp>
	struct push<Value, act<Exp>>
	{
		using rtn = typename perbuf_push<Value, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct push<act<Exp>, ListType<Values...>>
	{
		using rtn = typename perbuf_push<typename Exp::rtn, ListType<Values...>>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct push<act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_push<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	typed_push:
*/

	template<typename Type, Type, typename> struct typed_push;

	template<typename Type, Type Value, typename Exp>
	struct typed_push<Type, Value, act<Exp>>
	{
		using rtn = typename perbuf_typed_push<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	at:
*/

	template<size_type, typename> struct at;

	template<size_type index, typename Exp>
	struct at<index, act<Exp>>
	{
		using rtn = typename perbuf_at<index, typename Exp::rtn>::rtn;
	};

/*
	typed_at:
*/

	template<typename Type, size_type, typename> struct typed_at;

	template<typename Type, size_type index, typename Exp>
	struct typed_at<Type, index, act<Exp>>
	{
		static constexpr Type value = perbuf_typed_at<Type, index, typename Exp::rtn>::value;
	};

/*
	length:
*/

	template<typename, size_type = 0> struct length;

	template<typename Exp, size_type count>
	struct length<act<Exp>, count>
	{
		static constexpr size_type value = perbuf_length<typename Exp::rtn, count>::value;
	};

/*
	typed_length:
*/

	template<typename Type, typename, size_type = 0> struct typed_length;

	template<typename Type, typename Exp, size_type count>
	struct typed_length<Type, act<Exp>, count>
	{
		static constexpr size_type value = perbuf_typed_length<Type, typename Exp::rtn, count>::value;
	};

/*
	apply:
*/

	template<typename Type, typename Op, typename Exp>
	struct apply<Type, Op, act<Exp>>
	{
		using rtn = typename apply<Type, Op, typename Exp::rtn>::rtn;
	};

	template
	<
		typename Type,
		typename Op,
		Type Value,
		typename Exp,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		Op,
		number_list<Value>,
		act<Exp>
	>
	{
		using rtn = typename apply
		<
			Type,
			Op,
			number_list<Value>,
			typename Exp::rtn

		>::rtn;
	};

	template
	<
		typename Type,
		typename Op,
		typename Exp,
		Type Value,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		Op,
		act<Exp>,
		number_list<Value>
	>
	{
		using rtn = typename apply
		<
			Type,
			Op,
			typename Exp::rtn,
			number_list<Value>

		>::rtn;
	};

	template
	<
		typename Type,
		typename Op,
		typename Exp1,
		typename Exp2
	>
	struct apply
	<
		Type,
		Op,
		act<Exp1>,
		act<Exp2>
	>
	{
		using rtn = typename apply
		<
			Type,
			Op,
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const act<Exp> &)
	{
		using Type = typename Exp::rtn;

		Type::kind::functor::display(Type());
	}
};

