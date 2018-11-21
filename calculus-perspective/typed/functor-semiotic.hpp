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
*/

	template<typename Kind, typename Type, template<Type...> class eager, Type... Params>
	struct delay
	{
		static constexpr Kind value = eager<Params...>::value;
	};

	template<typename Type, template<Type...> class eager, Type... Params>
	struct delay<void, Type, eager, Params...>
	{
		using rtn = eager<Params...>;
	};

/*
	force:
*/

	template<typename Exp>
	struct memoized_force // includes delay<Kind, Type, eager, Params...>
	{
		using rtn = Exp;
	};

	template<typename Type, template<Type...> class eager, Type... Params>
	struct memoized_force<delay<void, Type, eager, Params...>>
	{
		using rtn = eager<Params...>;
	};

	template<typename Exp>
	using force = typename memoized_force<Exp>::rtn;

/*
	cons:
*/

	template<typename Type, typename> struct memoized_cons;

	template<typename Type, Type... Values, template<Type...> class ListType>
	struct memoized_cons<Type, ListType<Values...>>
	{
		template<Type Value>
		using type = ListType<Value, Values...>;
	};

	template<typename Type, Type Value, typename List>
	using cons = typename memoized_cons<Type, List>::template type<Value>;

/*
	projection:
*/

	template<typename, typename> struct memoized_projection;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct memoized_projection<Type, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;

		using rtn = ListType<Values...>;
	};

/*
	car:
*/

	template<typename Type, typename List>
	using car = memoized_projection<Type, List>;

/*
	cdr:
*/

	template<typename Type, typename List>
	using cdr = typename memoized_projection<Type, List>::rtn;
};

