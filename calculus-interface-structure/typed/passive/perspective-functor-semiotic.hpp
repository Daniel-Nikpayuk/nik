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
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, category, passive, structure)

/***********************************************************************************************************************/

	template<typename...> struct evaluate;

/*
	if_then_else:
*/

	template<bool True, typename Ante, typename Conse>
	struct if_then_else
	{
		using rtn = typename evaluate<Ante>::rtn;
	};

	template<typename Ante, typename Conse>
	struct if_then_else<false, Ante, Conse>
	{
		using rtn = typename evaluate<Conse>::rtn;
	};

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
			Pred::value,
			Exp,

			act
			<
				sub_evaluate
				<
					Exps...
				>
			>

		>::rtn;
	};

	template<typename Exp>
	struct sub_evaluate
	<
		then<Exp>
	>
	{
		using rtn = typename evaluate<Exp>::rtn;
	};

/*
	evaluate:
*/

	template<typename Exp>
	struct evaluate<Exp>
	{
		using rtn = Exp;
	};

	template<typename Exp>
	struct evaluate<act<Exp>>
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Pred, typename Exp, typename... Exps>
	struct evaluate
	<
		if_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred::value,
			Exp,

			act
			<
				sub_evaluate
				<
					Exps...
				>
			>

		>::rtn;
	};

/***********************************************************************************************************************/

/*
	untyped_cons:
*/

	template<typename, typename> struct untyped_cons;

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct untyped_cons<Exp, ListType<Values...>>
	{
		using rtn = ListType<typename evaluate<Exp>::rtn, Values...>;
	};

	template<typename Exp1, typename Exp2>
	struct untyped_cons<Exp1, act<Exp2>>
	{
		using rtn = typename untyped_cons<Exp1, typename Exp2::rtn>::rtn;
	};

/*
	typed_cons:

	act<> cannot be applied to Type because of its dependent Value.
*/

	template<typename Type, Type, typename> struct typed_cons;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cons<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

	template<typename Type, Type Value, typename Exp>
	struct typed_cons<Type, Value, act<Exp>>
	{
		using rtn = typename typed_cons<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	untyped_car:
*/

	template<typename> struct untyped_car;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_car<ListType<Value, Values...>>
	{
		using rtn = Value;
	};

	template<typename Exp>
	struct untyped_car<act<Exp>>
	{
		using rtn = typename untyped_car<typename Exp::rtn>::rtn;
	};

/*
	typed_car:
*/

	template<typename Type, typename> struct typed_car;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_car<Type, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

	template<typename Exp0, typename Exp1>
	struct typed_car<Exp0, act<Exp1>>
	{
		using Type = typename evaluate<Exp0>::rtn;

		static constexpr Type value = typed_car<Type, typename Exp1::rtn>::value;
	};

/*
	untyped_cdr:
*/

	template<typename> struct untyped_cdr;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_cdr<ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

	template<typename Exp>
	struct untyped_cdr<act<Exp>>
	{
		using rtn = typename untyped_cdr<typename Exp::rtn>::rtn;
	};

/*
	typed_cdr:
*/

	template<typename Type, typename> struct typed_cdr;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cdr<Type, ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

	template<typename Exp0, typename Exp1>
	struct typed_cdr<Exp0, act<Exp1>>
	{
		using rtn = typename typed_cdr<typename evaluate<Exp0>::rtn, typename Exp1::rtn>::rtn;
	};

/*
	untyped_catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct untyped_catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct untyped_catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp1, typename Exp2>
	struct untyped_catenate<Exp1, Exp2>
	{
		using rtn = typename untyped_catenate
		<
			typename evaluate<Exp1>::rtn,
			typename evaluate<Exp2>::rtn

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
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp0, typename Exp1, typename Exp2>
	struct typed_catenate<Exp0, Exp1, Exp2>
	{
		using rtn = typename typed_catenate
		<
			typename evaluate<Exp0>::rtn,
			typename evaluate<Exp1>::rtn,
			typename evaluate<Exp2>::rtn

		>::rtn;
	};

	template<typename Exp0, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct typed_catenate<Exp0, Exp1, Exp2, Exp3, Exps...>
	{
		using rtn = typename typed_catenate
		<
			Exp0,
			typename typed_catenate<Exp0, Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	untyped_push:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename> struct untyped_push;

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct untyped_push<Exp, ListType<Values...>>
	{
		using rtn = ListType<Values..., typename evaluate<Exp>::rtn>;
	};

	template<typename Exp1, typename Exp2>
	struct untyped_push<Exp1, act<Exp2>>
	{
		using rtn = typename untyped_push<Exp1, typename Exp2::rtn>::rtn;
	};

/*
	typed_push:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Type, Type, typename> struct typed_push;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_push<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Values..., Value>;
	};

	template<typename Type, Type Value, typename Exp>
	struct typed_push<Type, Value, act<Exp>>
	{
		using rtn = typename typed_push<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	untyped_at:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<size_type, typename> struct untyped_at;

	template<size_type index, typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_at<index, ListType<Value, Values...>>
	{
		using rtn = typename untyped_at<index-1, ListType<Values...>>::rtn;
	};

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_at<0, ListType<Value, Values...>>
	{
		using rtn = Value;
	};

	template<size_type index, typename Exp>
	struct untyped_at<index, act<Exp>>
	{
		using rtn = typename untyped_at<index, typename Exp::rtn>::rtn;
	};

/*
	typed_at:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Type, size_type, typename> struct typed_at;

	template<typename Type, size_type index, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_at<Type, index, ListType<Value, Values...>>
	{
		static constexpr Type value = typed_at<Type, index-1, ListType<Values...>>::value;
	};

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_at<Type, 0, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

	template<typename Exp0, size_type index, typename Exp1>
	struct typed_at<Exp0, index, act<Exp1>>
	{
		using Type = typename evaluate<Exp0>::rtn;

		static constexpr Type value = typed_at<Type, index, typename Exp::rtn>::value;
	};

/*
	untyped_length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, size_type = 0> struct untyped_length;

	template<typename Value, typename... Values, size_type count, template<typename...> class ListType>
	struct untyped_length<ListType<Value, Values...>, count>
	{
		static constexpr size_type value = untyped_length<ListType<Values...>, count+1>::value;
	};

	template<size_type count, template<typename...> class ListType>
	struct untyped_length<ListType<>, count>
	{
		static constexpr size_type value = count;
	};

	template<typename Exp, size_type count>
	struct untyped_length<act<Exp>, count>
	{
		static constexpr size_type value = untyped_length<typename Exp::rtn, count>::value;
	};

/*
	typed_length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Type, typename, size_type = 0> struct typed_length;

	template<typename Type, Type Value, Type... Values, size_type count, template<Type...> class ListType>
	struct typed_length<Type, ListType<Value, Values...>, count>
	{
		static constexpr size_type value = typed_length<Type, ListType<Values...>, count+1>::value;
	};

	template<typename Type, size_type count, template<Type...> class ListType>
	struct typed_length<Type, ListType<>, count>
	{
		static constexpr size_type value = count;
	};

	template<typename Exp0, typename Exp1, size_type count>
	struct typed_length<Exp0, act<Exp1>, count>
	{
		static constexpr size_type value = typed_length<typename evaluate<Exp0>::rtn, typename Exp1::rtn, count>::value;
	};

/***********************************************************************************************************************/

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

/*
	untyped_display:
*/

	struct untyped
	{
		template<typename Exp, typename... Exps, template<typename...> class ListType>
		inline static void display(const ListType<Value, Values...> &, const char *sep = " ")
		{
			static constexpr bool value_is_list		= is_list<Value>::value;
			static constexpr bool values_is_null		= is_untyped_null<ListType<Values...>>::value;

			static constexpr char l				= value_is_list ? '[' : '(';
			static constexpr char r				= value_is_list ? ']' : ')';

			Builtin::functor::display(l);
			Value::kind::functor::display(Value());
			Builtin::functor::display(r);

			if (!values_is_null) Builtin::functor::display(sep);

			untyped_display(ListType<Values...>(), sep);
		}

		template<template<typename...> class ListType>
		inline static void display(const ListType<> &, const char *sep = " ")
		{
			// do nothing.
		}
	};

/*
	typed_display:
*/

	struct typed
	{
		template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
		inline static void display(const Type & t, const ListType<Value, Values...> &, const char *sep = " ")
		{
			Builtin::functor::display(sep);
			Builtin::functor::display(Value);

			typed_display(t, ListType<Values...>(), sep);
		}

		template<typename Type, template<Type...> class ListType>
		inline static void display(const Type &, const ListType<> &, const char *sep = " ")
		{
			// do nothing.
		}
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename List>
	inline static void display(const List & l, const char *sep = " ")
	{
		using ListType = typename identify<List>::rtn;

		if (is_equal<ListType, untyped_list>::value)	untyped_display(l);
		else						typed_display(ListType::value_type(), l);
	}

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	inline static void display(const Type & t, const ListType<Value, Values...> &, const char *sep = " ")
	{
		Kernel::functor::display(sep);
		Kernel::functor::display(Value);

		display(t, ListType<Values...>(), sep);
	}

	template<typename Type, template<Type...> class ListType>
	inline static void display(const Type &, const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

};

