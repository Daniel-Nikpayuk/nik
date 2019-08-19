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

	#include nik_typedef(symbolic, calculus, boolean, structure)

/*
	is_False:
*/

/*
	template<typename Exp>
	using is_False = is_equal
	<
		Exp,
		False
	>;
*/

/*
	is_True:
*/

/*
	template<typename Exp>
	using is_True = is_equal
	<
		Exp,
		True
	>;
*/

/*
	is_boolean:
*/

	template<typename Exp, typename Continuation = ch_bool_echo>
	using is_boolean = typename pattern_match_boolean<Exp>::template match
	<
		Continuation
	>;
};

