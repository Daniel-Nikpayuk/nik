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

	#include nik_typedef(calculus, variable, label, module)
	#include nik_typedef(calculus, variable, label, structure)

	#define safe_name

		#include nik_typedef(calculus, variable, label, identity)

	#undef safe_name

	#include nik_typedef(calculus, variable, frame, module)
	#include nik_typedef(calculus, variable, frame, structure)
	#include nik_typedef(calculus, variable, frame, alias)
	#include nik_typedef(calculus, variable, frame, identity)

/*
	push:

	There is no implementation of act<...> here because these functions
	are intended to be internal to the environment interface.
*/

	template<typename, typename> struct push;

	template<typename Label, typename Value, typename... Bindings>
	struct push<binding<Label, Value>, frame<Bindings...>>
	{
		using rtn = frame<binding<Label, Value>, Bindings...>;
	};

/*
	construct:	Takes a list of labels as well as a list of values and creates
			a frame of bindings. This implementation assumes the value list
			is at least as long as the label list.
*/

	template<typename, typename> struct construct;

	template<typename Variable, typename... Variables, typename Value, typename... Values>
	struct construct<lambda<Variable, Variables...>, list<Value, Values...>>
	{
		using Frame = typename construct<lambda<Variables...>, list<Values...>>::rtn;

		using rtn = typename push
		<
			binding<Variable, Value>,
			Frame

		>::rtn;
	};

	template<typename... Values>
	struct construct<null_lambda, list<Values...>>
	{
		using rtn = null_frame;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Variable, typename Label, typename Value, typename... Bindings>
	struct lookup<Variable, frame<binding<Label, Value>, Bindings...>>
	{
		using rtn = typename evaluate
		<
			if_then_else
			<
				varlai_is_equal<Variable, Label>,
				binding<Label, Value>,

				act
				<
					lookup<Variable, frame<Bindings...>>
				>
			>

		>::rtn;
	};

	template<typename Variable>
	struct lookup<Variable, null_frame>
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
		using remainder_is_null = typename is_null<frame<Bindings...>>::rtn;

		printf("%s", "frame: ");
		Binding::kind::functor::display(Binding());
		if (!remainder_is_null::value) printf("%c", '\n');

		frame_print(f);
	}

	inline static void display(const null_frame & t)
	{
		printf("%s", "frame: null\n");
	}

	template<typename Binding, typename... Bindings>
	inline static void frame_print(const frame<Binding, Bindings...> &)
	{
		using remainder_is_null = typename is_null<frame<Bindings...>>::rtn;

		printf("%s", "       ");
		Binding::kind::functor::display(Binding());
		if (!remainder_is_null::value) printf("%c", '\n');

		frame_print(frame<Bindings...>());
	}

	inline static void frame_print(const null_frame &)
	{
		// do nothing.
	}
};

