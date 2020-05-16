/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	The main intention in defining these functions are for grammatical formalization, though some
	of them will be used regularly in practice.

	Continuation passing grammar is secondary here, and is not part of the grammatical formalization.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, functor)

/*
	pose: ( builtin  --> builtin  ) x builtin  --> builtin
*/

	template<typename Kind, typename Handle, typename Type, Type Value, typename Continuation = ch_echo>
	using pose = typename Continuation::template result<Kind, Handle::value(Value)>;

/*
	turn: ( typename --> builtin  ) x typename --> builtin
*/

	template<typename Type, typename Handle, typename Continuation = ch_echo>
	using turn = typename Continuation::template result<Type, Handle::value>;

/*
	moiz: ( builtin  --> typename ) x builtin  --> typename
*/

	template<typename Type, template<typename, Type> class Handle, Type Value>
	using moiz = Handle<Type, Value>;

/*
	call: ( typename --> typename ) x typename --> typename
*/

	template<typename Handle>
	using call = typename Handle::rtn;

/*
	It would be ideal to create a grammatical "compose" operator as a shortform for f . transit, but
	there are too many variations which are entirely dependent upon the signature of the grammar point f.
*/
};

