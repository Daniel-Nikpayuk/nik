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
	The main intention in defining these functions are for grammatical
	formalization, though some of them will be used regularly in practice.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, structure)

/*
	echo:
*/

	struct echo
	{
		template<typename Type>
		static constexpr Type value(const Type Value)
		{
			return Value;
		}
	};

/*
	ping:
*/

	template<typename Type>
	using ping = Type;

/*
	pose:

	A constexpr function should be used for intermediate function composition.

	On the one hand, pose is an extension of moiz as it reads builtin --> typename,
	on the other hand it implies there's no ideal direct way to compose builtin
	valued functions without eventually passing them off to a typename.
*/

	template<typename Continuation, typename Op, typename Type, Type Value>
	using pose = typename Continuation::template result<Type, Op::value(Value)>;

/*
	turn:
*/

	template<typename Continuation, typename Type, typename Dual>
	using turn = typename Continuation::template result<Type, Dual::value>;

/*
	moiz:
*/

	struct moiz
	{
		template<typename Type, Type Value>
		using result = memoized_value<Type, Value>;
	};

/*
	call:
*/

	template<typename Dual>
	using call = typename Dual::rtn;

/*
	dereference:
*/

	template<typename Type>
	using dereference = typename memoized_pointer<Type>::template pop
	<
		ping
	>;
};

