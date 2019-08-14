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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, product, structure)
	#include nik_typedef(symbolic, calculus, product, functor)

/*
	is_builtin_copair:
*/

	template<typename Continuation>
	struct cp_is_builtin_copair
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = typename Continuation::template result
		<
			bool,

			is_equal<TypeX, bool>::value &&
			
		>;
	};

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_builtin_copair = typename Continuation::template result
	<
		bool,

		is_builtin_builtin_pair<Exp>::value &&

		is_equal
		<
			builtin_builtin_left_type<Exp>,
			bool
		>
	>;

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_builtin_copair = typename memoized_builtin_builtin_pair<Exp>::template pop
	<
		cp_is_builtin_copair<Continuation>
	>;

/*
	builtin_copair_is_left:
*/

	template<typename Type, typename Copair, typename Continuation = ch_bool_echo>
	using builtin_copair_is_left = typename memoized_builtin_builtin_pair<bool, Type, Copair>::template pop
	<
		cp_builtin_builtin_car<cp_negate<Continuation>>
	>;

/*
	builtin_copair_is_right:
*/

	template<typename Type, typename Copair, typename Continuation = ch_bool_echo>
	using builtin_copair_is_right = typename memoized_builtin_builtin_pair<bool, Type, Copair>::template pop
	<
		cp_builtin_builtin_car<Continuation>
	>;

/*
	is_typename_copair:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_typename_copair = typename memoized_builtin_typename_pair<bool, Exp>::template match
	<
		Continuation
	>;

/*
	typename_copair_is_left:
*/

	template<typename Copair, typename Continuation = ch_bool_echo>
	using typename_copair_is_left = typename memoized_builtin_typename_pair<bool, Copair>::template pop
	<
		cp_builtin_typename_car<cp_negate<Continuation>>
	>;

/*
	typename_copair_is_right:
*/

	template<typename Copair, typename Continuation = ch_bool_echo>
	using typename_copair_is_right = typename memoized_builtin_typename_pair<bool, Copair>::template pop
	<
		cp_builtin_typename_car<Continuation>
	>;
};

