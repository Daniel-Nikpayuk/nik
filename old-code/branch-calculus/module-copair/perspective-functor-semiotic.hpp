/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	This branch is the (near) untyped calculus. The only "types" are distinct grammatical
	forms, so "copair" in this context is only relevant if the input takes distinct
	grammatical forms.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, functor)
	#include nik_typedef(symbolic, calculus, pair, structure)

	#include nik_typedef(symbolic, calculus, copair, structure)

/*
	builtin_inject_left:
*/

	template<typename Type, Type Value>
	using builtin_inject_left = builtin_inl<Type, Value>;

/*
	builtin_inject_right:
*/

	template<typename Type, Type Value>
	using builtin_inject_right = builtin_inr<Type, Value>;

/*
	typename_inject_left:
*/

	template<typename Value>
	using typename_inject_left = typename_inl<Value>;

/*
	typename_inject_right:
*/

	template<typename Value>
	using typename_inject_right = typename_inr<Value>;

/*
	builtin_copair_value:
*/

	template<typename Continuation>
	struct cp_builtin_value
	{
		template<bool Tag, typename Type, Type Value>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Copair, typename Continuation = ch_echo>
	using builtin_value = typename pattern_match_builtin_copair<Copair>::template pop
	<
		cp_builtin_value<Continuation>
	>;

/*
	typename_copair_value:
*/

	struct ch_typename_value
	{
		template<bool Tag, typename Value>
		using result = Value;
	};

	template<typename Copair>
	using typename_value = typename pattern_match_typename_copair<Copair>::template pop
	<
		ch_typename_value
	>;

/*
	The following functions act on pair (not copairs), but are categorized here because from a formal
	perspective they can not properly be constructed without the copair type.

	Continuations are necessarily embedded into their respective projections.
*/

/*
	builtin_builtin_cpr:
*/

	template<typename Projection, typename Pair>
	using builtin_builtin_cpr = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		Projection
	>;

/*
	builtin_typename_cpr:
*/

	template<typename Projection, typename Pair>
	using builtin_typename_cpr = typename pattern_match_builtin_typename_pair<Pair>::template pop
	<
		Projection
	>;

/*
	typename_builtin_cpr:
*/

	template<typename Projection, typename Pair>
	using typename_builtin_cpr = typename pattern_match_typename_builtin_pair<Pair>::template pop
	<
		Projection
	>;

/*
	typename_typename_cpr:
*/

	template<typename Projection, typename Pair>
	using typename_typename_cpr = typename pattern_match_typename_typename_pair<Pair>::template pop
	<
		Projection
	>;
};

