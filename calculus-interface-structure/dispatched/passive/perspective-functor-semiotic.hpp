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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, dispatched, functor)

	#undef safe_name

	#include nik_typedef(calculus, dispatched, passive, structure)

/*
	call:
*/

	template<typename Exp>
	struct call
	{
		using rtn = Exp;
	};

	template<typename Exp>
	struct call<act<Exp>>
	{
		using rtn = typename Exp::rtn;
	};

/*
	dereference:
*/

	template<typename Exp>
	using dereference = perdif_dereference<typename call<Exp>::rtn>;

/*
	if_then_else:
*/

	template<bool Pred, typename Ante, typename Conse>
	using if_then_else = perdif_if_then_else
	<
		Pred,
		typename call<Ante>::rtn,
		typename call<Conse>::rtn
	>;
};

