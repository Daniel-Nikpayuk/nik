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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, copair, structure)

/*
	is_builtin_copair:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_builtin_copair = typename pattern_match_builtin_copair<Exp>::template match
	<
		Continuation
	>;

/*
	builtin_copair_is_left:
*/

	template<typename Continuation>
	struct cp_builtin_copair_is_left
	{
		template<bool Tag, typename Type, Type Value>
		using result = typename Continuation::template result<!Tag>;
	};

	template<typename Copair, typename Continuation = ch_bool_echo>
	using builtin_copair_is_left = typename pattern_match_builtin_copair<Copair>::template pop
	<
		cp_builtin_copair_is_left<Continuation>
	>;

/*
	builtin_copair_is_right:
*/

	template<typename Continuation>
	struct cp_builtin_copair_is_right
	{
		template<bool Tag, typename Type, Type Value>
		using result = typename Continuation::template result<Tag>;
	};

	template<typename Copair, typename Continuation = ch_bool_echo>
	using builtin_copair_is_right = typename pattern_match_builtin_copair<Copair>::template pop
	<
		cp_builtin_copair_is_right<Continuation>
	>;

/*
	is_typename_copair:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_typename_copair = typename pattern_match_typename_copair<Exp>::template match
	<
		Continuation
	>;

/*
	typename_copair_is_left:
*/

	template<typename Continuation>
	struct cp_typename_copair_is_left
	{
		template<bool Tag, typename Value>
		using result = typename Continuation::template result<!Tag>;
	};

	template<typename Copair, typename Continuation = ch_bool_echo>
	using typename_copair_is_left = typename pattern_match_typename_copair<Copair>::template pop
	<
		cp_typename_copair_is_left<Continuation>
	>;

/*
	typename_copair_is_right:
*/

	template<typename Continuation>
	struct cp_typename_copair_is_right
	{
		template<bool Tag, typename Value>
		using result = typename Continuation::template result<!Tag>;
	};

	template<typename Copair, typename Continuation = ch_bool_echo>
	using typename_copair_is_right = typename pattern_match_typename_copair<Copair>::template pop
	<
		cp_typename_copair_is_right<Continuation>
	>;
};

