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
	using kind						= module;

	using type						= functor;

	#include nik_typedef(calculus, variable, environment, module)
	#include nik_typedef(calculus, variable, environment, structure)
	#include nik_typedef(calculus, variable, environment, alias)
	#include nik_typedef(calculus, variable, environment, identity)

/*
	extend:
*/

	template<typename, typename, typename> struct extend;

	template<typename... Frames, typename Variables, typename Values>
	struct extend<environment<Frames...>, Variables, Values>
	{
		using Frame = typename make<Variables, Values>::rtn; // non-lazy evaluation.

		using rtn = environment<Frame, Frames...>;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Frame, typename... Frames, typename variable>
	struct lookup<environment<Frame, Frames...>, variable>
	{
		using Value = typename find<Frame, variable>::rtn;

		using rtn = typename conditional
		<
			equal<Value, undefined>,
			act
			<
				lookup<environment<Frames...>, variable>
			>,
			Value

		>::rtn;
	};

	template<typename variable>
	struct lookup<null_environment, variable>
	{
		using rtn = undefined;
	};

/*
	make:
*/

	template<typename, typename> struct make;

// Assumes length<Variables> == length<Values>

	template<typename Variable, typename... Variables, typename Value, typename... Values>
	struct make<storage<Variable, Variables...>, storage<Value, Values...>>
	{
		using Frame = typename make<storage<Variables...>, storage<Values...>>::rtn;

		using rtn = typename add
		<
			binding<Variable, Value>,
			Frame

		>::rtn;
	};

	template<typename... Values>
	struct make<null_storage, storage<Values...>>
	{
		using rtn = null_frame;
	};

/*
	define:
*/

	template<typename...> struct define_;

	template<typename Variable, typename Value>
	struct define_<Variable, Value>
	{
		using rtn = environment
		<
			frame
			<
				binding<Variable, Value>
			>
		>;
	};

	template<typename Variable, typename Value, typename... Frames>
	struct define_<Variable, Value, environment<Frames...>>
	{
		using rtn = environment
		<
			frame
			<
				binding<Variable, Value>
			>,

			Frames...
		>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Frame, typename... Frames>
	inline static void display(const environment<Frame, Frames...> & f)
	{
		using remainder_is_null = typename is_null<environment<Frames...>>::rtn;

		printf("%s", "environment: ");
		Frame::kind::functor::display(Frame());
		if (!remainder_is_null::value) printf("%c", '\n');

		environment_print(f);
	}

	inline static void display(const null_environment & t)
	{
		printf("%s", "environment: null\n");
	}

	template<typename Frame, typename... Frames>
	inline static void environment_print(const environment<Frame, Frames...> &)
	{
		using remainder_is_null = typename is_null<environment<Frames...>>::rtn;

		printf("%s", "       ");
		Frame::kind::functor::display(Frame());
		if (!remainder_is_null::value) printf("%c", '\n');

		environment_print(environment<Frames...>());
	}

	inline static void environment_print(const null_environment &)
	{
		// do nothing.
	}
};

