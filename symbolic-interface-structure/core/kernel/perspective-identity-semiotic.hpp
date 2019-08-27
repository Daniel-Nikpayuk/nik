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

	#include nik_typedef(symbolic, core, kernel, structure)

/*
	ch_bool_echo:
*/

	struct ch_bool_echo
	{
		template<bool Value>
		using result = memoized_value<bool, Value>;
	};

/*
	cp_negate:
*/

	template<typename Continuation>
	struct cp_negate
	{
		template<bool Value>
		using result = typename Continuation::template result<!Value>;
	};

/*
	is_equal:
*/

	template<typename Type1, typename Type2, typename Continuation = ch_bool_echo>
	using is_equal = typename memoized_comparison<Type1, Type2>::template match
	<
		Continuation
	>;

/*
	is_filler:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_filler = is_equal<Exp, filler, Continuation>;

/*
	is_not_filler:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_not_filler = is_equal<Exp, filler, cp_negate<Continuation>>;

/*
	is_pointer:
*/

	template<typename Type, typename Continuation = ch_bool_echo>
	using is_pointer = typename memoized_pointer<Type>::template match
	<
		Continuation
	>;
};

