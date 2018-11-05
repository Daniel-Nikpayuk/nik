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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(calculus, constant, operate, identity)
	#include nik_typedef(calculus, constant, boolean, identity)
	#include nik_typedef(calculus, constant, boolean, functor)

	#include nik_typedef(calculus, constant, number, identity)

/*
	is_self_evaluating:
*/

	template<typename Expression>
	struct is_self_evaluating
	{
		using Exp = typename Expression::rtn;

		using rtn = apply
		<
			operate<'|', '|'>,

			is_number<Exp>,
//			is_string<Exp>,
			is_operate<Exp>,
			is_boolean<Exp>

		>::rtn;
	};
};

