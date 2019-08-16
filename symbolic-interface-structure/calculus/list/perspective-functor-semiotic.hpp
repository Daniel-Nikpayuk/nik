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

		pattern_match_*<...>::template op<signature, ....>

	but it actually slows compile times down significantly enough
	to warrant leaving as is (though I might at a future date use macros).
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, functor)

	#include nik_typedef(symbolic, calculus, list, structure)

	// dispatch:

	template<bool True, typename Filler = void>
	struct dispatch
	{
		// builtin:

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_car = typename dispatch<(count > 1)>::template builtin_car<Type, ListType, count-1, Values...>;

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_cdr = typename dispatch<(count > 1)>::template builtin_cdr<Type, ListType, count-1, Values...>;

		// typename:

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_car = typename dispatch<(count > 1)>::template typename_car<ListType, count-1, Values...>;

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_cdr = typename dispatch<(count > 1)>::template typename_cdr<ListType, count-1, Values...>;
	};

	template<typename Filler>
	struct dispatch<false, Filler>
	{
		// builtin:

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_car = memoized_value<Type, Value>;

		template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
		using builtin_cdr = ListType<Values...>;

		// typename:

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_car = Value;

		template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
		using typename_cdr = ListType<Values...>;
	};

/*
	builtin:
*/

	// cons:

	struct ch_builtin_cons
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<Values...>;
	};

	template<typename Type, Type Value, typename List>
	using builtin_cons = typename pattern_match_builtin_list<List>::template push_front
	<
		ch_builtin_cons, Value
	>;

	// car:

	template<typename Continuation>
	struct cp_builtin_car
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename List, typename Continuation = ch_echo>
	using builtin_car = typename pattern_match_builtin_list<List>::template push_front
	<
		cp_builtin_car<Continuation>
	>;

	// car ? :

	template<typename Continuation>
	struct cp_builtin_car
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename Continuation::template result
		<
			Type,

			typename pattern_match_typename_list<Chain>::template pop
			<
				dispatch<bool(index)>::template chain_car, index

			>::value
		>;
	};

	template<typename List, size_type index = 0, typename Continuation = ch_echo>
	using builtin_car = typename pattern_match_builtin_list<List>::template pop
	<
		cp_builtin_car<Continuation>, index
	>;

	// cdr:

	struct ch_builtin_cdr
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = ListType<Values...>;
	};

	template<typename List>
	using builtin_cdr = typename pattern_match_builtin_list<List>::template push_front
	<
		ch_builtin_cdr
	>;
};

