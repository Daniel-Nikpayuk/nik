/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	using rtn		= functor;

	#include nik_typedef(calculus, dispatched, active, structure)
	#include nik_typedef(calculus, dispatched, active, functor)

	#include nik_typedef(calculus, untyped, neutral, structure)

/*
	if_then:
*/

	template<typename Predicate, typename Expression>
	using if_then = if_then_else
	<
		Predicate::value,
		Expression,
		skip
	>;

/*
	else_then:
*/

	template<typename Predicate, typename Expression>
	using else_then = if_then_else
	<
		Predicate::value,
		Expression,
		skip
	>;

/*
	then:
*/

	template<typename Expression>
	using then = Expression;

/***********************************************************************************************************************/

/*
	cases:

	Assumes non-empty, in order: if_then, else_then, then.
	Conditionals do not call<>.

	Not grammatically safe.
*/

	template<typename...> struct memoized_cases;

	template<typename Exp1, typename Exp2, typename... Exps>
	struct memoized_cases<Exp1, Exp2, Exps...>
	{
		using rtn = dispaf_if_then_else
		<
			is_skip<Exp1>::value,

			act
			<
				memoized_cases<Exp2, Exps...>
			>,

			Exp1
		>;
	};

	template<typename Exp>
	struct memoized_cases<Exp>
	{
		using rtn = dispaf_call<Exp>;
	};

	template<typename... Exps>
	using cases = typename memoized_cases<Exps...>::rtn;

/***********************************************************************************************************************/

/*
	cases:

	Assumes non-empty, in order: if_then, else_then, then.
	Conditionals do not call<>.

	Not grammatically safe.
*/

	template<typename...> struct memoized_cases;

	template<typename Exp1, typename Exp2, typename... Exps>
	struct memoized_cases<Exp1, Exp2, Exps...>
	{
		using rtn = disacf_if_then_else
		<
			is_skip<Exp1>::value,

			memoized_cases<Exp2, Exps...>,

			Exp1
		>;
	};

	template<typename Exp>
	struct memoized_cases<Exp>
	{
		using rtn = disacf_call<Exp>;
	};

	template<typename... Exps>
	using cases = typename memoized_cases<Exps...>::rtn;

/***********************************************************************************************************************/

/*
	limit info taken from:	http://en.cppreference.com/w/cpp/types/numeric_limits

	(un)signed char
	(un)signed short
	(un)signed int
	(un)signed long
	(un)signed long long
*/

/*
	min:
*/

	template<typename RegType>
	struct min
	{
		static constexpr size_type value = untpaf_evaluate
		<
			untpaf_if_then
			<
				perdii_is_equal<RegType, unsigned char>,
				typed_list<size_type, 0>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned short>,
				typed_list<size_type, 0>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned int>,
				typed_list<size_type, 0>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned long>,
				typed_list<size_type, 0>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned long long>,
				typed_list<size_type, 0>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SCHAR_MIN)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SHRT_MIN)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed int>,
				typed_list<size_type, size_type(INT_MIN)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed long>,
				typed_list<size_type, size_type(LONG_MIN)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed long long>,
				typed_list<size_type, size_type(LLONG_MIN)>

			>, untpaf_then
			<
				typed_list<size_type, 0>
			>

		>::value;
	};

/*
	max:
*/

	template<typename RegType>
	struct max
	{
		static constexpr size_type value = untpaf_evaluate
		<
			untpaf_if_then
			<
				perdii_is_equal<RegType, unsigned char>,
				typed_list<size_type, size_type(UCHAR_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned short>,
				typed_list<size_type, size_type(USHRT_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned int>,
				typed_list<size_type, size_type(UINT_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned long>,
				typed_list<size_type, size_type(ULONG_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, unsigned long long>,
				typed_list<size_type, size_type(ULLONG_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SCHAR_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed short>,
				typed_list<size_type, size_type(SHRT_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed int>,
				typed_list<size_type, size_type(INT_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed long>,
				typed_list<size_type, size_type(LONG_MAX)>

			>, untpaf_else_then
			<
				perdii_is_equal<RegType, signed long long>,
				typed_list<size_type, size_type(LLONG_MAX)>

			>, untpaf_then
			<
				typed_list<size_type, size_type(SCHAR_MAX)>
			>

		>::value;
	};

/*
	unsigned_type:
*/

	template<size_type N>
	using unsigned_type = untpaf_evaluate
	<
		untpaf_if_then
		<
			at_most<N, unsigned char>,
			unsigned char

		>, untpaf_else_then
		<
			at_most<N, unsigned short>,
			unsigned short

		>, untpaf_else_then
		<
			at_most<N, unsigned int>,
			unsigned int

		>, untpaf_else_then
		<
			at_most<N, unsigned long>,
			unsigned long

		>, untpaf_then
		<
//			at_most<N, unsigned long long>,
			unsigned long long
		>
	>;

/*
	signed_type:
*/

	template<size_type N>
	using signed_type = untpaf_evaluate
	<
		untpaf_if_then
		<
			at_most<N, unsigned char>,
			signed char

		>, untpaf_else_then
		<
			at_most<N, unsigned short>,
			signed short

		>, untpaf_else_then
		<
			at_most<N, unsigned int>,
			signed int

		>, untpaf_else_then
		<
			at_most<N, unsigned long>,
			signed long

		>, untpaf_then
		<
//			at_most<N, unsigned long long>,
			signed long long
		>
	>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	inline static void display(const False &)
	{
		Kernel::functor::display("False");
	}

	inline static void display(const True &)
	{
		Kernel::functor::display("True");
	}

/***********************************************************************************************************************/

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.

	This can be rewritten using C++20 string literal parameters.
*/

	inline static void display(const typed_list<bool> &)
	{
		Dispatched::functor::display("typed list: bool");
	}

	inline static void display(const typed_list<char> &)
	{
		Dispatched::functor::display("typed list: char");
	}

	inline static void display(const typed_list<wchar_t> &)
	{
		Dispatched::functor::display("typed list: wchar_t");
	}

	inline static void display(const typed_list<char16_t> &)
	{
		Dispatched::functor::display("typed list: char16_t");
	}

	inline static void display(const typed_list<char32_t> &)
	{
		Dispatched::functor::display("typed list: char32_t");
	}

	inline static void display(const typed_list<unsigned char> &)
	{
		Dispatched::functor::display("typed list: unsigned char");
	}

	inline static void display(const typed_list<unsigned short> &)
	{
		Dispatched::functor::display("typed list: unsigned short");
	}

	inline static void display(const typed_list<unsigned int> &)
	{
		Dispatched::functor::display("typed list: unsigned int");
	}

	inline static void display(const typed_list<unsigned long> &)
	{
		Dispatched::functor::display("typed list: unsigned long");
	}

	inline static void display(const typed_list<unsigned long long> &)
	{
		Dispatched::functor::display("typed list: unsigned long long");
	}

	inline static void display(const typed_list<signed char> &)
	{
		Dispatched::functor::display("typed list: signed char");
	}

	inline static void display(const typed_list<signed short> &)
	{
		Dispatched::functor::display("typed list: signed short");
	}

	inline static void display(const typed_list<signed int> &)
	{
		Dispatched::functor::display("typed list: signed int");
	}

	inline static void display(const typed_list<signed long> &)
	{
		Dispatched::functor::display("typed list: signed long");
	}

	inline static void display(const typed_list<signed long long> &)
	{
		Dispatched::functor::display("typed list: signed long long");
	}

	inline static void display(const other_type &)
	{
		Dispatched::functor::display("other type");
	}

};

	#define safe_name

		#include nik_typedef(calculus, perspective, untyped, identity)
		#include nik_typedef(calculus, perspective, untyped, functor)

		#include nik_typedef(calculus, dispatched, passive, functor)

		#include nik_typedef(calculus, untyped, neutral, functor)

	#undef safe_name

	#include nik_typedef(calculus, untyped, neutral, structure)
	#include nik_typedef(calculus, untyped, neutral, identity)

/*
	recurse:
*/

	template<bool, typename = filler> struct recurse;

	template<typename Filler>
	struct recurse<true, Filler>
	{
		template<size_type index, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
		using catenate = typename recurse<(index > 1)>::template catenate
		<
			index-1,
			untnef_catenate<dispaf_call<Exp1>, dispaf_call<Exp2>>,
			Exp3,
			Exps...
		>;
	};

	template<typename Filler>
	struct recurse<false, Filler>
	{
		template<size_type index, typename Exp1, typename Exp2, typename... Exps>
		using catenate = untnef_catenate<dispaf_call<Exp1>, dispaf_call<Exp2>>;
	};

/*
	cons:
*/

	template<typename Exp1, typename Exp2>
	using cons = untnef_cons<dispaf_call<Exp1>, dispaf_call<Exp2>>;

/*
	car:
*/

	template<typename Exp, size_type index = 0>
	using car = untnef_car<dispaf_call<Exp>, index>;

/*
	cdr:
*/

	template<typename Exp, size_type index = 0>
	using cdr = untnef_cdr<dispaf_call<Exp>, index>;

/*
	push:
*/

	template<typename Exp1, typename Exp2>
	using push = untnef_push<dispaf_call<Exp1>, dispaf_call<Exp2>>;

/*
	length:
*/

	template<typename Exp>
	using length = untnef_length<dispaf_call<Exp>>;

/*
	catenate:

	Can do better?
*/

	template<size_type length, typename Exp1, typename Exp2, typename... Exps>
	using let_catenate = typename recurse<bool(length)>::template catenate<length, Exp1, Exp2, Exps...>;

	template<typename Exp1, typename Exp2, typename... Exps>
	using catenate = let_catenate<sizeof...(Exps), Exp1, Exp2, Exps...>;

/***********************************************************************************************************************/

/*
	evaluate:

	Assumes non-empty, in order: if_then, else_then, then.
	Conditionals do not call<>.

	Not grammatically safe.
*/

	template<typename...> struct memoized_evaluate;

	template<typename Exp1, typename Exp2, typename... Exps>
	struct memoized_evaluate<Exp1, Exp2, Exps...>
	{
		using rtn = dispaf_if_then_else
		<
			is_skip<Exp1>::value,

			act
			<
				memoized_evaluate<Exp2, Exps...>
			>,

			Exp1
		>;
	};

	template<typename Exp>
	struct memoized_evaluate<Exp>
	{
		using rtn = dispaf_call<Exp>;
	};

	template<typename... Exps>
	using evaluate = typename memoized_evaluate<Exps...>::rtn;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Value, typename... Values, template<typename...> class ListType>
	inline static void display(const ListType<Value, Values...> &, const char *sep = " ")
	{
		static constexpr bool value_is_list_type	= peruni_is_list_type<Value>::value;
		static constexpr bool values_is_null		= peruni_is_null_type<ListType<Values...>>::value;

		static constexpr char l				= value_is_list_type ? '[' : '(';
		static constexpr char r				= value_is_list_type ? ']' : ')';

		Dispatched::functor::display(l);
		Value::kind::functor::display(Value());
		Dispatched::functor::display(r);

		if (!values_is_null) Dispatched::functor::display(sep);

		display(ListType<Values...>(), sep);
	}

	template<template<typename...> class ListType>
	inline static void display(const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

	template<typename Exp>
	inline static void display(const act<Exp> &, const char *sep = " ")
	{
		display(typename Exp::rtn(), sep);
	}

	// active:


	#define safe_name

		#include nik_typedef(calculus, perspective, untyped, identity)
		#include nik_typedef(calculus, perspective, untyped, functor)

		#include nik_typedef(calculus, dispatched, active, functor)

		#include nik_typedef(calculus, untyped, neutral, functor)

	#undef safe_name

	#include nik_typedef(calculus, untyped, neutral, structure)
	#include nik_typedef(calculus, untyped, neutral, identity)

	template<template<typename...> class eager, typename... Params>
	struct memoized_call<perunf_delay<void, eager, Params...>>
	{
		using rtn = eager<Params...>;
	};

	template<typename Type, template<Type...> class eager, Type... Params>
	struct memoized_call<pertyf_delay<void, Type, eager, Params...>>
	{
		using rtn = eager<Params...>;
	};

/*
	recurse:
*/

	template<bool, typename = filler> struct recurse;

	template<typename Filler>
	struct recurse<true, Filler>
	{
		template<size_type index, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
		using catenate = typename recurse<(index > 1)>::template catenate
		<
			index-1,
			untnef_catenate<disacf_call<Exp1>, disacf_call<Exp2>>,
			Exp3,
			Exps...
		>;
	};

	template<typename Filler>
	struct recurse<false, Filler>
	{
		template<size_type index, typename Exp1, typename Exp2, typename... Exps>
		using catenate = untnef_catenate<disacf_call<Exp1>, disacf_call<Exp2>>;
	};

/*
	cons:
*/

	template<typename Exp1, typename Exp2>
	using cons = untnef_cons<disacf_call<Exp1>, disacf_call<Exp2>>;

/*
	car:
*/

	template<typename Exp, size_type index = 0>
	using car = untnef_car<disacf_call<Exp>, index>;

/*
	cdr:
*/

	template<typename Exp, size_type index = 0>
	using cdr = untnef_cdr<disacf_call<Exp>, index>;

/*
	push:
*/

	template<typename Exp1, typename Exp2>
	using push = untnef_push<disacf_call<Exp1>, disacf_call<Exp2>>;

/*
	length:
*/

	template<typename Exp>
	using length = untnef_length<disacf_call<Exp>>;

/*
	catenate:
*/

	template<size_type length, typename Exp1, typename Exp2, typename... Exps>
	using let_catenate = typename recurse<bool(length)>::template catenate<length, Exp1, Exp2, Exps...>;

	template<typename Exp1, typename Exp2, typename... Exps>
	using catenate = let_catenate<sizeof...(Exps), Exp1, Exp2, Exps...>;

/***********************************************************************************************************************/

/*
	evaluate:

	Assumes non-empty, in order: if_then, else_then, then.
	Conditionals do not call<>.

	Not grammatically safe.
*/

	template<typename...> struct memoized_evaluate;

	template<typename Exp1, typename Exp2, typename... Exps>
	struct memoized_evaluate<Exp1, Exp2, Exps...>
	{
		using rtn = disacf_if_then_else
		<
			is_skip<Exp1>::value,

			memoized_evaluate<Exp2, Exps...>,

			Exp1
		>;
	};

	template<typename Exp>
	struct memoized_evaluate<Exp>
	{
		using rtn = disacf_call<Exp>;
	};

	template<typename... Exps>
	using evaluate = typename memoized_evaluate<Exps...>::rtn;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Value, typename... Values, template<typename...> class ListType>
	inline static void display(const pass<ListType<Value, Values...>> &, const char *sep = " ")
	{
		static constexpr bool value_is_list_type	= peruni_is_list_type<Value>::value;
		static constexpr bool values_is_null		= peruni_is_null_type<ListType<Values...>>::value;

		static constexpr char l				= value_is_list_type ? '[' : '(';
		static constexpr char r				= value_is_list_type ? ']' : ')';

		Dispatched::functor::display(l);
		Value::kind::functor::display(Value());
		Dispatched::functor::display(r);

		if (!values_is_null) Dispatched::functor::display(sep);

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


