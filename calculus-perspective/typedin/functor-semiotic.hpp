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

	using type		= functor;

	#include nik_unpack(../.., calculus, perspective, kernel, identity)

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct cons<Exp, ListType<Exps...>>
	{
		using rtn = ListType<Exp, Exps...>;
	};

	template<typename Exp1, typename Exp2>
	struct cons<Exp1, act<Exp2>>
	{
		using rtn = typename cons<Exp1, typename Exp2::rtn>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct cons<act<Exp1>, Exp2>
	{
		using rtn = typename cons<typename Exp1::rtn, Exp2>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct cons<act<Exp1>, act<Exp2>>
	{
		using rtn = typename cons<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	car:
*/

	template<typename> struct car;

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct car<ListType<Exp, Exps...>>
	{
		using rtn = Exp;
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

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct cdr<ListType<Exp, Exps...>>
	{
		using rtn = ListType<Exps...>;
	};

	template<typename Exp>
	struct cdr<act<Exp>>
	{
		using rtn = typename cdr<typename Exp::rtn>::rtn;
	};

/*
	catenate:
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Exps1, typename... Exps2, template<typename...> class ListType>
	struct catenate<ListType<Exps1...>, ListType<Exps2...>>
	{
		using rtn = ListType<Exps1..., Exps2...>;
	};

	template<typename... Exps, typename Exp, template<typename...> class ListType>
	struct catenate<ListType<Exps...>, act<Exp>>
	{
		using rtn = typename catenate
		<
			ListType<Exps...>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct catenate<act<Exp>, ListType<Exps...>>
	{
		using rtn = typename catenate
		<
			typename Exp::rtn,
			ListType<Exps...>

		>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct catenate<act<Exp1>, act<Exp2>>
	{
		using rtn = typename catenate
		<
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename List1, typename List2, typename List3, typename... Lists>
	struct catenate<List1, List2, List3, Lists...>
	{
		using rtn = typename catenate
		<
			act
			<
				catenate<List1, List2>
			>,

			List3,
			Lists...

		>::rtn;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct push<Exp, ListType<Exps...>>
	{
		using rtn = ListType<Exps..., Exp>;
	};

	template<typename Exp1, typename Exp2>
	struct push<Exp1, act<Exp2>>
	{
		using rtn = typename push<Exp1, typename Exp2::rtn>::rtn;
	};

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct push<act<Exp>, ListType<Exps...>>
	{
		using rtn = typename push<typename Exp::rtn, ListType<Exps...>>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct push<act<Exp1>, act<Exp2>>
	{
		using rtn = typename push<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	at:
*/

	template<size_type, typename> struct at;

	template<size_type index, typename Exp, typename... Exps, template<typename...> class ListType>
	struct at<index, ListType<Exp, Exps...>>
	{
		using rtn = typename at<index-1, ListType<Exps...>>::rtn;
	};

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	struct at<0, ListType<Exp, Exps...>>
	{
		using rtn = Exp;
	};

	template<size_type index, typename Exp>
	struct at<index, act<Exp>>
	{
		using rtn = typename at<index, typename Exp::rtn>::rtn;
	};

/*
	length:
*/

	template<typename, size_type = 0> struct length;

	template<typename Exp, typename... Exps, size_type count, template<typename...> class ListType>
	struct length<ListType<Exp, Exps...>, count>
	{
		static constexpr size_type value = length<ListType<Exps...>, count+1>::value;
	};

	template<size_type count, template<typename...> class ListType>
	struct length<ListType<>, count>
	{
		static constexpr size_type value = count;
	};

	template<typename Exp, size_type count>
	struct length<act<Exp>, count>
	{
		static constexpr size_type value = length<typename Exp::rtn, count>::value;
	};

/*
	display:

	Assumes list elements are coded within module::structure.
*/

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	inline static void display(const ListType<Exp, Exps...> &, const char *str = " ")
	{
		static constexpr bool expression_is_list	= is_list<Exp>::value;
		static constexpr bool remainder_is_null		= is_null<ListType<Exps...>>::value;

		static constexpr char l				= expression_is_list ? '[' : '(';
		static constexpr char r				= expression_is_list ? ']' : ')';

		printf("%c", l);
		Exp::kind::functor::display(Exp());
		printf("%c", r);

		if (!remainder_is_null) printf("%s", str);

		display(ListType<Exps...>(), str);
	}

	template<template<typename...> class ListType>
	inline static void display(const ListType<> &, const char *str = " ")
	{
		// do nothing.
	}
};

