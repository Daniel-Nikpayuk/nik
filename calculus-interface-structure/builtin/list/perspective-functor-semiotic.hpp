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
	#include nik_typedef(calculus, builtin, list, module)
	#include nik_typedef(calculus, builtin, list, structure)
	#include nik_typedef(calculus, builtin, list, alias)
	#include nik_typedef(calculus, builtin, list, identity)

/*
	car:
*/

	template<typename> struct car;

	template<typename Exp, typename... Exps>
	struct car<list<Exp, Exps...>>
	{
		using rtn = Exp;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename Exp, typename... Exps>
	struct cdr<list<Exp, Exps...>>
	{
		using rtn = list<Exps...>;
	};

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Exp, typename... Exps>
	struct cons<Exp, list<Exps...>>
	{
		using rtn = list<Exp, Exps...>;
	};

/*
	at:

	Having access to "dispatch" grammar, it's better style to use it with car, cdr.
	I have chosen to reimplement these grammars directly to optimize.
*/

	template<typename, typename> struct at;

	template<typename Exp, typename... Exps, typename Type, Type index>
	struct at<list<Exp, Exps...>, constant<Type, index>>
	{
		using rtn = typename at<list<Exps...>, constant<Type, index-1>>::rtn;
	};

	template<typename Exp, typename... Exps, typename Type>
	struct at<list<Exp, Exps...>, constant<Type, 0>>
	{
		using rtn = Exp;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename... Exps, typename Exp>
	struct push<list<Exps...>, Exp>
	{
		using rtn = list<Exps..., Exp>;
	};

/*
	length:

	Having access to "dispatch" grammar, it's better style to use it with car, cdr.
	I have chosen to reimplement these grammars directly to optimize.
*/

	template<typename, typename = constant<size_type, 0>> struct length;

	template<typename Exp, typename... Exps, size_type count>
	struct length<list<Exp, Exps...>, constant<size_type, count>>
	{
		using rtn = typename length<list<Exps...>, constant<size_type, count+1>>::rtn;
	};

	template<size_type count>
	struct length<null_list, constant<size_type, count>>
	{
		using rtn = constant<size_type, count>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const list<Exp, Exps...> & t)
	{
		printf("%s", "list: ");

		list_print(t);
	}

	inline static void display(const null_list & t)
	{
		printf("%s", "list: null\n");
	}

	template<typename Exp, typename... Exps>
	inline static void list_print(const list<Exp, Exps...> &)
	{
		using expression_is_list = typename is_list<Exp>::rtn;
		using remainder_is_null = typename is_null<list<Exps...>>::rtn;

		char l = expression_is_list::value ? '[' : '(';
		char r = expression_is_list::value ? ']' : ')';

		printf("%c", l);
		Exp::kind::functor::display(Exp());
		printf("%c", r);

		if (!remainder_is_null::value) printf("%s", "  ");

		list_print(list<Exps...>());
	}

	inline static void list_print(const null_list &)
	{
		// do nothing.
	}
};

