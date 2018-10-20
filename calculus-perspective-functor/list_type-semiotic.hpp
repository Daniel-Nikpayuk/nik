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

#include nik_unpack(.., calculus, kernel, act, structure)

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
	builtin cons:
*/

	template<typename Type, Type, typename> struct builtin_cons;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct builtin_cons<Type, Exp, ListType<Exps...>>
	{
		using rtn = ListType<Exp, Exps...>;
	};

	template<typename Type, Type Exp1, typename Exp2>
	struct builtin_cons<Type, Exp1, act<Exp2>>
	{
		using rtn = typename builtin_cons<Type, Exp1, typename Exp2::rtn>::rtn;
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
	builtin car:
*/

	template<typename Type, typename> struct builtin_car;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct builtin_car<Type, ListType<Exp, Exps...>>
	{
		static constexpr Type value		= Exp;
	};

	template<typename Type, typename Exp>
	struct builtin_car<Type, act<Exp>>
	{
		using rtn = typename builtin_car<Type, typename Exp::rtn>::rtn;
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
	builtin cdr:
*/

	template<typename Type, typename> struct builtin_cdr;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct builtin_cdr<Type, ListType<Exp, Exps...>>
	{
		using rtn = ListType<Exps...>;
	};

	template<typename Type, typename Exp>
	struct builtin_cdr<Type, act<Exp>>
	{
		using rtn = typename builtin_cdr<Type, typename Exp::rtn>::rtn;
	};

