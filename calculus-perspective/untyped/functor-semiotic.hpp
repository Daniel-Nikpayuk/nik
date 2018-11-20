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

	template<template<typename...> class label, typename... Exps>
	struct delay
	{
		using force = label<Exps...>;
	};

/*
	cons:

	A memoized version either memoizes the value or the list,
	but as we need to pattern match the list, it cannot be used.
*/

/*
	template<typename> struct memoized_cons;

	template<typename... Values, template<typename...> class ListType>
	struct memoized_cons<ListType<Values...>>
	{
		template<typename Value>
		using type = ListType<Value, Values...>;
	};

	template<typename Value, typename List>
	using cons = typename memoized_cons<List>::template type<Value>;
*/

	template<typename, typename> struct cons;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct cons<Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	template<typename> struct memoized_projection;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct memoized_projection<ListType<Value, Values...>>
	{
		using car = Value;

		using cdr = ListType<Values...>;
	};
*/

/*
	car:
*/

/*
	template<typename List>
	using car = typename memoized_projection<List>::car;
*/

	template<typename> struct car;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct car<ListType<Value, Values...>>
	{
		using rtn = Value;
	};

/*
	cdr:
*/

/*
	template<typename List>
	using cdr = typename memoized_projection<List>::cdr;
*/

	template<typename> struct cdr;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct cdr<ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};
};

