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

		#include nik_typedef(calculus, interpreted, frame, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, recursed, identity)
	#include nik_typedef(calculus, interpreted, recursed, functor)

	#include nik_typedef(calculus, interpreted, environment, structure)

/*
	add:
*/

	template<typename, typename = null_environment> struct add;

	template<typename Binding, typename... Frames>
	struct add<Binding, environment<Frames...>>
	{
		using rtn = environment
		<
			frame<Binding>,

			Frames...
		>;
	};

/*
	construct:
*/

	template<typename, typename, typename = null_environment> struct construct;

	template<typename Variables, typename Values, typename... Frames>
	struct construct<Variables, Values, environment<Frames...>>
	{
		using rtn = environment
		<
			typename intfrf_construct<Variables, Values>::rtn,

			Frames...
		>;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Variable, typename Frame, typename... Frames>
	struct lookup<Variable, environment<Frame, Frames...>>
	{
		using Binding = typename intfrf_lookup<Variable, Frame>::rtn;

		using rtn = typename if_then_else
		<
			is_null<Binding>,
			lookup<Variable, environment<Frames...>>,
			Binding

		>::rtn;
	};

	template<typename Variable>
	struct lookup<Variable, null_environment>
	{
		using rtn = null_binding;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Frame, typename... Frames>
	inline static void display(const environment<Frame, Frames...> & e)
	{
		using is_empty = typename is_null<environment<Frames...>>::rtn;

		Dispatched::functor::display("environment: ");
		Frame::kind::functor::display(Frame());

		if (!is_empty::value) Recursed::functor::display(environment<Frames...>(), ", ");
	}

	inline static void display(const null_environment &)
	{
		Dispatched::functor::display("environment: null");
	}
};

