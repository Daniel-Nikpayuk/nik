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

	#include nik_typedef(calculus, variable, frame, module)
	#include nik_typedef(calculus, variable, frame, structure)
	#include nik_typedef(calculus, variable, frame, alias)
	#include nik_typedef(calculus, variable, frame, identity)

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

