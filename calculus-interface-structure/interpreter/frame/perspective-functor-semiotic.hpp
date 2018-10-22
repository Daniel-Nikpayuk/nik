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

	using type		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, kernel, functor)

	#undef safe_name

	#include nik_typedef(calculus, builtin, boolean, identity)
	#include nik_typedef(calculus, dispatch, if_then_else, functor)

	#include nik_typedef(calculus, variable, frame, structure)

/*
	construct:	Takes a list of variables as well as a list of values and creates
			a frame of bindings. This implementation assumes the variable
			and value lists are the same size.
*/

	template<typename, typename> struct construct;

	template
	<
		typename Variable, typename... Variables,
		typename Value, typename... Values,
		template<typename...> class ListType
	>
	struct construct
	<
		ListType<Variable, Variables...>,
		ListType<Value, Values...>
	>
	{
		using rtn = typename perkef_cons
		<
			binding<Variable, Value>,

			act
			<
				construct
				<
					ListType<Variables...>,
					ListType<Values...>
				>
			>

		>::rtn;
	};

	template<template<typename...> class ListType>
	struct construct<ListType<>, ListType<>>
	{
		using rtn = null_frame;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Name, typename Variable, typename... Values, typename... Bindings>
	struct lookup<Name, frame<binding<Variable, Values...>, Bindings...>>
	{
		using rtn = typename evaluate
		<
			if_then_else
			<
				is_equal<Name, Variable>,
				binding<Variable, Values...>,

				act
				<
					lookup<Name, frame<Bindings...>>
				>
			>

		>::rtn;
	};

	template<typename Name>
	struct lookup<Name, null_frame>
	{
		using rtn = null_binding;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Binding, typename... Bindings>
	inline static void display(const frame<Binding, Bindings...> & f)
	{
		using is_empty = typename is_null<frame<Bindings...>>::rtn;

		Builtin::functor::display("frame: ");
		Binding::kind::functor::display(Binding());

		if (!is_empty::value) Kernel::functor::display(frame<Bindings...>(), ", ");
	}

	inline static void display(const null_frame &)
	{
		Builtin::functor::display("frame: null");
	}
};

