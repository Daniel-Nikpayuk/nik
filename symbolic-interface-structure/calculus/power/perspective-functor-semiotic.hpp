/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	I've considered refactoring the redundant pattern

		memoized_*<...>::template op<signature, ....>

	but it actually slows compile times down significantly enough
	to warrant leaving as is (though I might use macros).
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, perspective, kernel, structure)
	#include nik_typedef(symbolic, perspective, calculus, structure)
	#include nik_typedef(symbolic, perspective, calculus, functor)

	#include nik_typedef(symbolic, kernel, core, functor)

	#include nik_typedef(symbolic, calculus, product, structure)
	#include nik_typedef(symbolic, calculus, product, identity)

	// recurse:

	template<bool True, typename Filler = void>
	struct recurse
	{
		// list:

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_list_car = typename recurse<(count > 1)>::template builtin_list_car<Type, ListType, count-1, Values...>;

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_list_cdr = typename recurse<(count > 1)>::template builtin_list_cdr<Type, ListType, count-1, Values...>;

		template<typename Type, typename Op, Type Result, size_type count, Type Value, Type... Values>
		using builtin_list_fold = typename recurse<(count > 1)>::template builtin_list_fold
		<
			Type, Op,
			Op::value(Result, Value),
			count-1, Values...
		>;

		// chain:

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_list_car = typename recurse<(count > 1)>::template typename_list_car<ListType, count-1, Values...>;

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_list_cdr = typename recurse<(count > 1)>::template typename_list_cdr<ListType, count-1, Values...>;

		template<typename Op, typename Result, size_type count, typename Value, typename... Values>
		using typename_list_fold = typename recurse<(count > 1)>::template typename_list_fold
		<
			Op,
			typename Op::template instance<Result, Value>,
			count-1, Values...
		>;
	};

	template<typename Filler>
	struct recurse<false, Filler>
	{
		// list:

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_list_car = memoized_value<Type, Value>;

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_list_cdr = ListType<Values...>;

		template<typename Type, typename Op, Type Result, size_type count, Type... Values>
		using builtin_list_fold = memoized_value<Type, Result>;

		// chain:

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_list_car = Value;

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_list_cdr = ListType<Values...>;

		template<typename Op, typename Result, size_type count, typename... Values>
		using typename_list_fold = Result;
	};

	// list:

	template<typename Type, template<Type...> class ListType, Type... Values>
	using builtin_list_cons = ListType<Values...>;

	template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
	using builtin_list_car = memoized_value<Type, Value>;

	template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
	using builtin_list_cdr = ListType<Values...>;

	template<typename Type, template<Type...> class ListType, Type... Values>
	using builtin_list_null = ListType<>;

	template<typename Type, template<Type...> class ListType, Type... Values>
	using builtin_list_length = memoized_value<size_type, sizeof...(Values)>;

	template<typename Type, typename List, Type... Values>
	using builtin_list_catenate = typename structure::template builtin_list<Type, List>::template push_front<builtin_list_cons, Values...>;

	template<typename Type, template<Type...> class ListType0, template<Type...> class ListType1, Type... Values>
	using builtin_list_rename = ListType0<Values...>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, Type... Values>
	using builtin_list_map = ListKind<Op::value(Values)...>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List, Type... Values>
	using builtin_list_zip = typename structure::template builtin_list<Type, List>::template bimap<Kind, ListKind, Op, Values...>;

	// chain:

	template<template<typename...> class ListType, typename... Values>
	using typename_list_cons = ListType<Values...>;

	template<template<typename...> class ListType, typename Value, typename... Values>
	using typename_list_car = Value;

	template<template<typename...> class ListType, typename Value, typename... Values>
	using typename_list_cdr = ListType<Values...>;

	template<template<typename...> class ListType, typename... Values>
	using typename_list_null = ListType<>;

	template<template<typename...> class ListType, typename... Values>
	using typename_list_length = memoized_value<size_type, sizeof...(Values)>;

	template<typename List, typename... Values>
	using typename_list_catenate = typename structure::template typename_list<List>::template push_front<typename_list_cons, Values...>;

	template<template<typename...> class ListType0, template<typename...> class ListType1, typename... Values>
	using typename_list_rename = ListType0<Values...>;

	template<template<typename...> class ListType, typename Op, typename... Values>
	using typename_list_map = ListType<typename Op::template instance<Values>...>;

	template<template<typename...> class ListKind, typename Op, typename List, typename... Values>
	using typename_list_zip = typename structure::template typename_list<List>::template bimap<ListKind, Op, Values...>;

	template<bool True, typename Filler = void>
	struct recurse
	{
		template<size_type index, typename Value, typename... Values>
		using closure_at = typename recurse<bool(index > 1)>::template closure_at<index-1, Values...>;

		template
		<
			size_type index, typename ContList,
			typename Type, template<Type...> class ListType, Type... Values

		> using lexical_continuation = typename car<ContList>::template apply<index-1, cdr<ContList>, Type, ListType, Values...>;

		template
		<
			size_type index, template<size_type> class ContList,
			typename Type, template<Type...> class ListType, Type... Values

		> using lexical_continuation = typename ContList<index>::template apply<index-1, ContList, Type, ListType, Values...>;
	};

	template<typename Filler>
	struct recurse<false, Filler>
	{
		template<size_type index, typename Value, typename... Values>
		using closure_at = Value;

		template
		<
			size_type index, template<size_type> class ContList,
			typename Type, template<Type...> class ListType, Type... Values

		> using lexical_continuation = ListType<Values...>;
	};

// main operators defined for continuation passing:

	struct Cons
	{
		template
		<
			size_type index, template<size_type> class ContList,
			typename Type, template<Type...> class ListType, Type... Values

		> using apply = typename recurse<bool(index)>::template continuation<index, ContList, Type, ListType, Values...>;
	};

	struct Car
	{
		template
		<
			size_type index, template<size_type> class ContList,
			typename Type, template<Type...> class ListType, Type Value, Type... Values

		> using apply = typename recurse<bool(index)>::template continuation<index, ContList, Type, ListType, Value>;
	};

	struct Cdr
	{
		template
		<
			size_type index, template<size_type> class ContList,
			typename Type, template<Type...> class ListType, Type Value, Type... Values

		> using apply = typename recurse<bool(index)>::template continuation<index, ContList, Type, ListType, Values...>;
	};


	// automated "mostly" only really makes sense at the list/chain grammar level. Not at the pair/copair level.

/*
	mostly_reflex:

	(act<Exp> --> Exp::rtn)

	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

/*
	template<typename Exp>
	using recall = typename memoized_chain<Exp>::template wrap
	<
		chain_rename, call
	>;
*/

	template<typename Exp>
	using recall = typename generic::template chain_wrap
	<
		Exp, chain_rename, call
	>;

	template<typename Exp>
	using mostly_reflex = typename memoized_conditional
	<
		is_act<Exp>::value

	>::template left_inject
	<
		recall, Exp,
		Exp
	>;

/*
	mostly_transit:

	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:

	(pass<Exp> --> Exp)
*/

	template<typename Exp>
	using mostly_transit = typename memoized_conditional
	<
		is_pass<Exp>::value

	>::template coinject
	<
		reflex_chain_car,
		call,
		Exp
	>;

/*
	transit:
*/

	template<template<typename> class Op0, template<typename> class Op1, typename Exp>
	using transit_unary = Op0
	<
		Op1<Exp>
	>;

	template<template<typename, typename> class Op0, template<typename> class Op1, typename Exp1, typename Exp2>
	using transit_binary = Op0
	<
		Op1<Exp1>,
		Op1<Exp2>
	>;

/*
	list:
*/

	// cons:

	template<typename Type, Type Value, typename List>
	using reflex_list_cons = typename memoized_list<Type, List>::template push_front
	<
		list_cons, Value
	>;

	template<typename Type, typename Value, typename List>
	using transit_list_cons = reflex_list_cons
	<
		call<Type>,
		Value::value,
		call<List>
	>;

	// car:

	template<typename Type, typename List>
	using reflex_list_car = typename memoized_list<Type, List>::template push_front
	<
		list_car
	>;

	template<typename Type, typename List>
	using transit_list_car = transit_binary
	<
		reflex_list_car,

		call, Type, List
	>;

	// cdr:

	template<typename Type, typename List>
	using reflex_list_cdr = typename memoized_list<Type, List>::template push_front
	<
		list_cdr
	>;

	template<typename Type, typename List>
	using transit_list_cdr = transit_binary
	<
		reflex_list_cdr,

		call, Type, List
	>;

	// push:

	template<typename Type, Type Value, typename List>
	using reflex_list_push = typename memoized_list<Type, List>::template push_back
	<
		list_cons, Value
	>;

	template<typename Type, typename Value, typename List>
	using transit_list_push = reflex_list_push
	<
		call<Type>,
		Value::value,
		call<List>
	>;

/*
	chain:
*/

	// cons:

	template<typename Value, typename Chain>
	using reflex_chain_cons = typename memoized_chain<Chain>::template push_front
	<
		chain_cons, Value
	>;

	template<typename Value, typename Chain>
	using transit_chain_cons = transit_binary
	<
		reflex_chain_cons,

		call, Value, Chain
	>;

	// car:

	template<typename Chain>
	using reflex_chain_car = typename memoized_chain<Chain>::template push_front
	<
		chain_car
	>;

	template<typename Chain>
	using transit_chain_car = transit_unary
	<
		reflex_chain_car,

		call, Chain
	>;

	// cdr:

	template<typename Chain>
	using reflex_chain_cdr = typename memoized_chain<Chain>::template push_front
	<
		chain_cdr
	>;

	template<typename Chain>
	using transit_chain_cdr = transit_unary
	<
		reflex_chain_cdr,

		call, Chain
	>;

	// push:

	template<typename Value, typename Chain>
	using reflex_chain_push = typename memoized_chain<Chain>::template push_back
	<
		chain_cons, Value
	>;

	template<typename Value, typename Chain>
	using transit_chain_push = transit_binary
	<
		reflex_chain_push,

		call, Value, Chain
	>;

/*
	list:
*/

	// cons:

	template<typename Type, typename List, Type... Values>
	using reflex_list_cons = typename memoized_list<Type, List>::template push_front
	<
		list_cons, Values...
	>;

	// car:

	template<typename Type, typename List, size_type index = 0>
	using reflex_list_car = typename memoized_list<Type, List>::template pop
	<
		recurse<bool(index)>::template list_car, index
	>;

	// cdr:

	template<typename Type, typename List, size_type index = 0>
	using reflex_list_cdr = typename memoized_list<Type, List>::template pop
	<
		recurse<bool(index)>::template list_cdr, index
	>;

	// null:

	template<typename Type, typename List>
	using reflex_list_null = typename memoized_list<Type, List>::template push_front
	<
		list_null
	>;

	// push:

	template<typename Type, typename List, Type... Values>
	using reflex_list_push = typename memoized_list<Type, List>::template push_back
	<
		list_cons, Values...
	>;

	// catenate:

	template<typename Type, typename List1, typename List2>
	using reflex_list_catenate = typename memoized_list<Type, List1>::template join_front
	<
		list_catenate, List2
	>;

/*
	template<typename Type, size_type count, typename List1, typename List2, typename... Lists>
	using let_multicatenate = typename structure::template recurse<bool(count)>::template multicatenate
	<
		Type, count, List1, List2, Lists...
	>;

	template<typename Type, typename List1, typename List2, typename... Lists>
	using multicatenate = let_multicatenate<Type, sizeof...(Lists), List1, List2, Lists...>;
*/

	// unite:

	template<typename Type, typename List1, Type Value, typename List2>
	using reflex_list_unite = typename memoized_list<Type, List1>::template join_back
	<
		list_catenate,

		List2, Value
	>;

	template<typename Type, typename List1, typename List2, Type... Values>
	using reflex_list_multiunite = typename memoized_list<Type, List1>::template join_back
	<
		list_catenate,

		List2, Values...
	>;

	// relabel:

	template<typename Type, typename List, template<Type...> class name>
	using reflex_list_rename = typename memoized_list<Type, List>::template wrap
	<
		list_rename, Type, name
	>;

	// length:

	template<typename Type, typename List>
	using reflex_list_length = typename memoized_list<Type, List>::template push_front
	<
		list_length
	>;

	// map:

/*
	template<typename Type, typename Op, typename List>
	using map = typename structure::template memoized_list<Type, List>::template map<Op>;

	template
	<
		typename Kind, template<Kind...> class ListKind,
		typename Type, template<Type...> class ListType,

		typename Op, List, size_type length
	>
	using let_map = typename structure::template memoized_list<Type, List>::template recursive_binary_fapply
	<
		structure::template recurse<bool(length)>::template map,

		Kind, ListKind, Op, length
	>;

	template
	<
		typename Kind, template<Kind...> class ListKind,
		typename Type, template<Type...> class ListType,
		typename Op, typename List1, typename List2
	>
	using map = let_map
	<
		Kind, ListKind, Type, ListType,

		typename structure::template memoized_operator<Op>::apply,

		ListKind<>, List1, List2,

		length<Type, List1>::value
	>;
*/

	// zip:

/*
	template<size_type length, typename Type, typename Op, typename List1, typename List2, typename... Lists>
	using let_apply = typename structure::template recurse<Type, bool(length)>::template apply<length, Op, List1, List2, Lists...>;

	template<typename Type, typename Op, typename List1, typename List2, typename... Lists>
	using apply = let_apply<sizeof...(Lists), Type, Op, List1, List2, Lists...>;
*/

/*
	template<typename Kind, typename Type, typename Op, typename List0, typename List1, typename List2, size_type length>
	using let_apply = typename structure::template memoized_list<Type, List1>::template recursive_binary_packwise
	<
		structure::template recurse<bool(length)>::template apply,

		Kind, Op, List0, List2, length
	>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List1, typename List2>
	using apply = let_apply
	<
		Kind, Type,

		typename structure::template memoized_operator<Op>::apply,

		ListKind<>, List1, List2,

		length<Type, List1>::value
	>;
*/

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List1, typename List2>
	using reflex_list_zip = typename memoized_list<Type, List1>::template zip
	<
		list_zip,

		Kind, ListKind, Op,

		List2
	>;

	// fold:

	template<typename Type, typename Op, typename List, Type seed, size_type length>
	using let_list_fold = typename memoized_list<Type, List>::template fold
	<
		recurse<bool(length)>::template list_fold,

		Op,

		seed, length
	>;

	template<typename Type, typename Op, typename List, Type seed>
	using reflex_list_fold = let_list_fold<Type, Op, List, seed, length<Type, List>::value>;

/*
	chain:
*/

	// cons:

	template<typename Chain, typename... Values>
	using reflex_chain_cons = typename memoized_chain<Chain>::template push_front
	<
		chain_cons, Values...
	>;

	// car:

	template<typename Chain, size_type index = 0>
	using reflex_chain_car = typename memoized_chain<Chain>::template pop
	<
		recurse<bool(index)>::template chain_car, index
	>;

	// cdr:

	template<typename Chain, size_type index = 0>
	using reflex_chain_cdr = typename memoized_chain<Chain>::template pop
	<
		recurse<bool(index)>::template chain_cdr, index
	>;

	// null:

	template<typename Chain>
	using reflex_chain_null = typename memoized_chain<Chain>::template push_front
	<
		chain_null
	>;

	// push:

	template<typename Chain, typename... Values>
	using reflex_chain_push = typename memoized_chain<Chain>::template push_back
	<
		chain_cons, Values...
	>;

	// catenate:

	template<typename Chain1, typename Chain2>
	using reflex_chain_catenate = typename memoized_chain<Chain1>::template join_front
	<
		chain_catenate, Chain2
	>;

/*
	template<size_type count, typename Chain1, typename Chain2, typename... Chains>
	using let_multicatenate = typename structure::template recurse<bool(count)>::template multicatenate
	<
		count, Chain1, Chain2, Chains...
	>;

	template<typename Chain1, typename Chain2, typename... Chains>
	using multicatenate = let_multicatenate<sizeof...(Chains), Chain1, Chain2, Chains...>;
*/

	// unite:

	template<typename Chain1, typename Value, typename Chain2>
	using reflex_chain_unite = typename memoized_chain<Chain1>::template join_back
	<
		chain_catenate,

		Chain2, Value
	>;

	template<typename Chain1, typename Chain2, typename... Values>
	using reflex_chain_multiunite = typename memoized_chain<Chain1>::template join_back
	<
		chain_catenate,

		Chain2, Values...
	>;

	// relabel:

	template<typename Chain, template<typename...> class name>
	using reflex_chain_rename = typename memoized_chain<Chain>::template wrap
	<
		chain_rename, name
	>;

	// length:

	template<typename Chain>
	using reflex_chain_length = typename memoized_chain<Chain>::template push_front
	<
		chain_length
	>;

	// map:

/*
	template<typename Op, typename Chain>
	using map = typename structure::template memoized_chain<Chain>::template map<Op>;

	template
	<
		template<typename...> class ChainKind,
		template<typename...> class ChainType,

		typename Op, Chain, size_type length
	>
	using let_map = typename structure::template memoized_chain<Chain>::template recursive_binary_fapply
	<
		structure::template recurse<bool(length)>::template map,

		ChainKind, Op, length
	>;

	template
	<
		template<typename...> class ChainKind,
		template<typename...> class ChainType,
		typename Op, typename Chain1, typename Chain2
	>
	using map = let_map
	<
		ChainKind, ChainType,

		typename structure::template memoized_operator<Op>::apply,

		ChainKind<>, Chain1, Chain2,

		length<Chain1>::value
	>;
*/

	// zip:

/*
	template<size_type length, typename Op, typename Chain1, typename Chain2, typename... Chains>
	using let_apply = typename structure::template recurse<bool(length)>::template apply<length, Op, Chain1, Chain2, Chains...>;

	template<typename Op, typename Chain1, typename Chain2, typename... Chains>
	using apply = let_apply<sizeof...(Chains), Op, Chain1, Chain2, Chains...>;
*/

/*
	template<typename Op, typename Chain0, typename Chain1, typename Chain2, size_type length>
	using let_apply = typename structure::template memoized_chain<Chain1>::template recursive_binary_packwise
	<
		structure::template recurse<bool(length)>::template apply,

		Op, Chain0, Chain2, length
	>;

	template<template<typename...> class ChainKind, typename Op, typename Chain1, typename Chain2>
	using apply = let_apply
	<
		typename structure::template memoized_operator<Op>::apply,

		ChainKind<>, Chain1, Chain2,

		length<Chain1>::value
	>;
*/

	template<template<typename...> class ChainKind, typename Op, typename Chain1, typename Chain2>
	using reflex_chain_zip = typename memoized_chain<Chain1>::template zip
	<
		chain_zip,

		ChainKind, Op,

		Chain2
	>;

	// fold:

	template<typename Op, typename Chain, typename seed, size_type length>
	using let_chain_fold = typename memoized_chain<Chain>::template fold
	<
		recurse<bool(length)>::template chain_fold,

		Op,

		seed, length
	>;

	template<typename Op, typename Chain, typename seed>
	using reflex_chain_fold = let_chain_fold<Op, Chain, seed, length<Chain>::value>;

/***********************************************************************************************************************/

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
		display(dispaf_call<Exp0>(), dispaf_call<Exp1>(), sep);
	}

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
		display(disacf_call<Exp0>(), disacf_call<Exp1>(), sep);
	}
};

