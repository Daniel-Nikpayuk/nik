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
	using kind		= branch;

	using rtn		= functor;

/*
	delay:

	template template variables are currently not allowed.
	As such, this library requires eager aliases to return typenames.
*/

	template<typename Type, template<typename...> class eager, typename... Params>
	struct delay
	{
		static constexpr Type value = eager<Params...>::value;
	};

	template<template<typename...> class eager, typename... Params>
	struct delay<void, eager, Params...>
	{
		using rtn = eager<Params...>;
	};

/*
	force:
*/

	template<typename Exp>
	struct memoized_force // includes delay<Type, eager, Params...>
	{
		using rtn = Exp;
	};

	template<template<typename...> class eager, typename... Params>
	struct memoized_force<delay<void, eager, Params...>>
	{
		using rtn = eager<Params...>;
	};

	template<typename Exp>
	using force = typename memoized_force<Exp>::rtn;

/*
	cons:
*/

	template<typename> struct memoized_cons;

	template<typename... Values, template<typename...> class ListType>
	struct memoized_cons<ListType<Values...>>
	{
		template<typename Value>
		using type = ListType<Value, Values...>;
	};

	template<typename Value, typename List>
	using cons = typename memoized_cons<List>::template type<Value>;

/*
	projection:
*/

	template<typename> struct memoized_projection;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct memoized_projection<ListType<Value, Values...>>
	{
		using car = Value;

		using cdr = ListType<Values...>;
	};

/*
	car:
*/

	template<typename List>
	using car = typename memoized_projection<List>::car;

/*
	cdr:
*/

	template<typename List>
	using cdr = typename memoized_projection<List>::cdr;
};

