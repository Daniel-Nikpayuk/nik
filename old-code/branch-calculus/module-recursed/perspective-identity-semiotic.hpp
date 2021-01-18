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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#define safe_name

		#include nik_typedef(calculus, perspective, dispatched, identity)
		#include nik_typedef(calculus, perspective, untyped, identity)

		#include nik_typedef(calculus, constant, operate, identity)
		#include nik_typedef(calculus, constant, boolean, identity)
		#include nik_typedef(calculus, constant, literal, identity)
		#include nik_typedef(calculus, constant, number, identity)
		#include nik_typedef(calculus, constant, integer32, identity)

	#undef safe_name

	#include nik_typedef(calculus, constant, recursed, structure)

/*
	is_equal:
*/

	template<typename Exp1, typename Exp2>
	using is_equal = boolean
	<
		perdii_is_equal<disacf_call<Exp1>, disacf_call<Exp2>>::value
	>;

/*
	is_list_type:
*/

	template<typename Exp>
	using is_list_type = boolean
	<
		peruni_is_list_type<disacf_call<Exp>>::value
	>;

/*
	is_null_type:
*/

	template<typename Exp>
	using is_null_type = boolean
	<
		peruni_is_null_type<disacf_call<Exp>>::value
	>;

/*
	is_struct_type:
*/

	template<typename Exp, template<typename...> class label>
	using is_struct_type = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>>::value
	>;

/*
	is_type:
*/

	template<typename Exp>
	using is_type = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, type>::value
	>;

/*
	is_list:
*/

	template<typename Exp>
	using is_list = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, list>::value
	>;

/*
	is_operate:
*/

	template<typename Exp>
	using is_operate = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, operate>::value
	>;

/*
	is_boolean:
*/

	template<typename Exp>
	using is_boolean = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, boolean>::value
	>;


/*
	is_literal:
*/

	template<typename Exp>
	using is_literal = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, literal>::value
	>;


/*
	is_number:
*/

	template<typename Exp>
	using is_number = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, number>::value
	>;


/*
	is_integer32:
*/

	template<typename Exp>
	using is_integer32 = boolean
	<
		peruni_is_struct_type<disacf_call<Exp>, integer32>::value
	>;

};

