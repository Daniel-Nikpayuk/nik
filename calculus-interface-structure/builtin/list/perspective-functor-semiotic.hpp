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
	cons:

	There's no general cons between untyped and typed lists.
*/

/*
	car:
*/

	template<typename List> struct car
	{
		using info = typename identify<List>::rtn;

		using rtn = if_then_else
		<
			is_equal<info::list_type, untyped>,

			act
			<
				untyped_car<List>
			>,

			typed_car<info::list_type, List>

		>::rtn;
	};

	template<typename Exp>
	struct car<act<Exp>>
	{
		using rtn = typename car<typename Exp::rtn>::rtn;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename List> struct cdr
	{
		using info = typename identify<List>::rtn;

		using rtn = if_then_else
		<
			is_equal<info::list_type, untyped>,

			act
			<
				untyped_cdr<List>
			>,

			act
			<
				typed_cdr<info::list_type, List>
			>

		>::rtn;
	};

	template<typename Exp>
	struct cdr<act<Exp>>
	{
		using rtn = typename cdr<typename Exp::rtn>::rtn;
	};

/*
	untyped_catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct untyped_catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct untyped_catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = typename perbuf_untyped_catenate
		<
			ListType<Values1...>,
			ListType<Values2...>

		>::rtn;
	};

	template<typename... Values, typename Exp, template<typename...> class ListType>
	struct untyped_catenate<ListType<Values...>, act<Exp>>
	{
		using rtn = typename perbuf_untyped_catenate
		<
			ListType<Values...>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct untyped_catenate<act<Exp>, ListType<Values...>>
	{
		using rtn = typename perbuf_untyped_catenate
		<
			typename Exp::rtn,
			ListType<Values...>

		>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct untyped_catenate<act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_untyped_catenate
		<
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct untyped_catenate<Exp1, Exp2, Exp3, Exps...>
	{
		using rtn = typename untyped_catenate
		<
			typename untyped_catenate<Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	typed_catenate:

	This implementation is optimized using partial specialization pattern matching.
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
	catenate:
*/

	template<typename List1, typename List2, typename... Lists>
	struct catenate
	{
		using rtn = if_then_else
		<
			is_untyped_list<List1>::value,

			act
			<
				untyped_catenate<List1, List2, Lists...>
			>,

			act
			<
				typed_catenate
				<
					act
					<
						list_type<List1>
					>,

					List1, List2,

					Lists...
				>
			>

		>::rtn;
	};

/*
	push:

	This implementation is optimized using partial specialization pattern matching.
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

	This implementation is optimized using partial specialization pattern matching.
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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, builtin, if_then_else, structure)

/*
	re_evaluate:

	prevents ambiguity during template type resolution.
*/

	template<typename> struct re_evaluate;

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<true>, Exp1, Exp2>
	>
	{
		using rtn = Exp1;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<false>, Exp1, Exp2>
	>
	{
		using rtn = Exp2;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<false>, Exp1, act<Exp2>>
	>
	{
		using rtn = typename Exp2::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct re_evaluate
	<
		if_then_else<boolean<true>, act<Exp1>, Exp2>
	>
	{
		using rtn = typename Exp1::rtn;
	};

/*
	evaluate:
*/

	template<typename> struct evaluate;

	template<typename Pred, typename Exp1, typename Exp2>
	struct evaluate
	<
		if_then_else<Pred, Exp1, Exp2>
	>
	{
		using rtn = typename re_evaluate
		<
			if_then_else
			<
				constant<bool, typename Pred::value>,

				Exp1,
				Exp2
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Pred, typename Exp1, typename Exp2>
	inline static void display(const if_then_else<Pred, Exp1, Exp2> &)
	{
		Builtin::functor::display("if_then_else: ");

		Pred::kind::functor::display(Pred());
		Builtin::functor::display(" ? ");

		Exp1::kind::functor::display(Exp1());
		Builtin::functor::display(" : ");

		Exp2::kind::functor::display(Exp2());
	}
};

