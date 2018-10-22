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

	using type		= identity;

	#define safe_name

		#include nik_typedef(calculus, perspective, builtin, identity)

	#undef safe_name

	#include nik_typedef(calculus, builtin, literal, structure)

/*
	is literal:
*/

	template<typename>
	struct is_literal
	{
		using rtn = boolean<false>;
	};

	template<register_type... Values>
	struct is_literal<literal<Values...>>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp>
	struct is_literal<act<Exp>>
	{
		using rtn = typename is_literal<typename Exp::rtn>::rtn;
	};

/*
	is null:
*/

	template<typename ListType>
	struct is_null
	{
		using rtn = boolean
		<
			perbui_is_null<register_type, ListType>::value
		>;
	};
};

