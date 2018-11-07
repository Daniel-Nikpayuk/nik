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
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

	#include nik_typedef(calculus, interpreted, lambda, structure)

/*
	make_lambda:
*/

	template<typename Args, typename Body>
	struct make_lambda
	{
		template<typename> struct strict;

		template<typename... Exps, template<typename...> class Sequence>
		struct strict<Sequence<Exps...>>
		{
			using rtn = lambda<Exps...>;
		};

		using rtn = typename cons
		<
			typename Args::rtn,

			strict
			<
				typename Body::rtn
			>

		>::rtn;
	};

/*
	procedure_arguments:
*/

	template<typename Exp>
	struct procedure_arguments
	{
		using rtn = typename Exp::rtn::arguments;
	};

/*
	procedure_body:
*/

	template<typename Exp>
	struct procedure_body
	{
		using rtn = typename Exp::rtn::body;
	};

/*
	procedure_environment:
*/

	template<typename Exp>
	struct procedure_environment
	{
		using rtn = typename Exp::rtn::environment;
	};

/*
	procedure_functor:
*/

	template<typename Exp>
	struct procedure_functor
	{
		using rtn = typename Exp::rtn::functor;
	};

/*
	make_procedure:
*/

	template<typename Args, typename Body, typename Env, typename Func>
	struct make_procedure
	{
		using rtn = procedure
		<
			typename Args::rtn,
			typename Body::rtn,
			typename Env::rtn,
			typename Func::rtn
		>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Type, typename... Types>
	inline static void display(const arguments<Type, Types...> & a)
	{
		using is_empty = typename is_null<arguments<Types...>>::rtn;

		Dispatched::functor::display("arguments: ");
		Recursed::functor::display(arguments<Type, Types...>(), ", ");
	}

	inline static void display(const null_arguments &)
	{
		Dispatched::functor::display("arguments: null");
	}

	template<typename Type, typename... Types>
	inline static void display(const body<Type, Types...> & a)
	{
		using is_empty = typename is_null<body<Types...>>::rtn;

		Dispatched::functor::display("body: ");
		Recursed::functor::display(body<Type, Types...>(), ", ");
	}

	inline static void display(const null_body &)
	{
		Dispatched::functor::display("body: null");
	}

	template<typename Type, typename... Types>
	inline static void display(const lambda<Type, Types...> & a)
	{
		using is_empty = typename is_null<lambda<Types...>>::rtn;

		Dispatched::functor::display("lambda: ");
		Recursed::functor::display(lambda<Type, Types...>(), ", ");
	}

	inline static void display(const lambda<> &)
	{
		Dispatched::functor::display("lambda: null");
	}

	template<typename Args, typename Body, typename Env, typename Func>
	inline static void display(const procedure<Args, Body, Env, Func> &)
	{
		Dispatched::functor::display("procedure:\n  ");
		Args::kind::functor::display(Args());
		Dispatched::functor::display(",\n  ");
		Body::kind::functor::display(Body());
		Dispatched::functor::display(",\n  ");
		Env::kind::functor::display(Env());
	}
};

