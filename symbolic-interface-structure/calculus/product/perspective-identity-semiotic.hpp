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

	#include nik_typedef(symbolic, perspective, kernel, structure)
	#include nik_typedef(symbolic, perspective, calculus, structure)
	#include nik_typedef(symbolic, perspective, calculus, identity)

	#include nik_typedef(symbolic, calculus, product, structure)

	// act:

	template<typename Exp>
	using act_id = typename memoized_chain<Exp>::template wrap
	<
		chain_name, act
	>;

	// pass:

	template<typename Exp>
	using pass_id = typename memoized_chain<Exp>::template wrap
	<
		chain_name, pass
	>;

/*
	is_name:
*/

	template<typename Exp, template<typename> class name_id>
	using is_name = typename memoized_conditional
	<
		memoized_chain<Exp>::template match<chain_id>::value

	>::template left_inject
	<
		name_id, Exp,

		memoized_value<bool, false>
	>;

/*
	is_act:
*/

	template<typename Exp>
	using is_act = is_name<Exp, act_id>;

/*
	is_pass:
*/

	template<typename Exp>
	using is_pass = is_name<Exp, pass_id>;

/*
	Passive/active comparisons would only be provided
	for convenience if they were used often enough.
*/
};

