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

	#include nik_typedef(calculus, dispatch, conditional, functor)

	#define safe_name

		#include nik_typedef(calculus, variable, binding, identity)
		#include nik_typedef(calculus, variable, frame, functor)

	#undef safe_name

	#include nik_typedef(calculus, variable, environment, module)
	#include nik_typedef(calculus, variable, environment, structure)
	#include nik_typedef(calculus, variable, environment, alias)
	#include nik_typedef(calculus, variable, environment, identity)

/*
	push:
*/

	template<typename, typename = null_environment> struct push;

	template<typename Binding, typename... Frames>
	struct push<Binding, environment<Frames...>>
	{
		using rtn = environment
		<
			frame
			<
				Binding
			>,

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
		using Frame = typename varfrf_construct<Variables, Values>::rtn;

		using rtn = environment<Frame, Frames...>;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Variable, typename Frame, typename... Frames>
	struct lookup<Variable, environment<Frame, Frames...>>
	{
		using Binding = typename varfrf_lookup<Variable, Frame>::rtn;

		using rtn = typename evaluate
		<
			if_then_else
			<
				varbii_is_null<Binding>,

				act
				<
					lookup<Variable, environment<Frames...>>
				>,

				typename Binding::value
			>

		>::rtn;
	};

	template<typename Variable>
	struct lookup<Variable, null_environment>
	{
		using rtn = undefined;
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

