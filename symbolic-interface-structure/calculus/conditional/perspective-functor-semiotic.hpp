/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	Narratively speaking, "conditional" is built from "cpr", but given its frequency of use
	it is optimized here.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, functor)

	#include nik_typedef(symbolic, calculus, conditional, structure)

/*
	echo:

	better to use (Pred ? Ante : Conse) grammar directly.
*/

	struct echo_if_then_else
	{
		template<typename Type>
		static constexpr Type value(bool Pred, Type Ante, Type Conse)
		{
			return (Pred ? Ante : Conse);
		}
	};

/*
	ping:
*/

	template<bool Pred, typename Ante, typename Conse>
	using ping_if_then_else = typename memoized_conditional<Pred>::template reflex
	<
		Ante, Conse
	>;

/*
	call:
*/

	template<bool Pred, typename Ante, typename Conse>
	using call_if_then_else = call
	<
		ping_if_then_else<Pred, Ante, Conse>
	>;

	template<bool Pred, typename Ante, typename Conse>
	using head_if_then_else = typename memoized_conditional<Pred>::template left_transit
	<
		call, Ante,
		Conse
	>;

	template<bool Pred, typename Ante, typename Conse>
	using tail_if_then_else = typename memoized_conditional<Pred>::template right_transit
	<
		Ante,
		call, Conse
	>;
};

