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

	#define safe_name

		#include nik_typedef(calculus, constant, recursed, identity)
		#include nik_typedef(calculus, constant, recursed, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, normal, structure)

/*
	error:
*/

	template<typename Exp>
	struct is_error
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<char... Chars>
		struct strict<error<Chars...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	environment:
*/

	template<typename Exp>
	struct is_binding
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename Variable, typename Value>
		struct strict<binding<Variable, Value>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_tagged:
*/

	template<typename Exp, typename Tag>
	struct is_tagged
	{
		using rtn = typename conref_and_then
		<
			conrei_is_list_type<Exp>,

			conrei_is_equal
			<
				conref_car<Exp>,
				Tag
			>

		>::rtn;
	};

/*
	quote:
	lambda:
*/

/*
	definition:
*/

	template<typename Expression>
	struct is_value_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename conref_and_then
		<
			is_tagged<Exp, define>,

			conrei_is_literal
			<
				conref_car<Exp, one>
			>

		>::rtn;
	};

	template<typename Expression>
	struct is_compound_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename conref_and_then
		<
			is_tagged<Exp, define>,

			conref_not_the_case
			<
				conrei_is_literal
				<
					conref_car<Exp, one>
				>
			>

		>::rtn;
	};

/*
	assignment:
*/

/*
	if_
*/

	template<typename Exp>
	struct is_true
	{
		template<typename Type, typename Filler = void>
		struct strict
		{
			using rtn = boolean<true>;
		};

		template<typename Filler>
		struct strict<boolean<false>, Filler>
		{
			using rtn = boolean<false>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	begin:
*/

	template<typename Exps>
	struct is_last
	{
		using rtn = typename conrei_is_null
		<
			conref_cdr<Exps>

		>::rtn;
	};

/*
	cond:
*/

/*
	application:
*/

	template<typename Expression>
	struct is_application
	{
		using Exp = typename Expression::rtn;

		template<typename SubExp>
		struct type_match
		{
			using first = typename SubExp::rtn;

			using rtn = typename conref_or_else
			<
				conrei_is_operate<first>,
				conrei_is_literal<first>

			>::rtn;
		};

		using rtn = typename conref_and_then
		<
			conrei_is_list_type<Exp>,

			conref_not_the_case
			<
				conrei_is_null<Exp>
			>,

			type_match
			<
				conref_car<Exp>
			>

		>::rtn;
	};

/*
	expression:
*/

	template<typename Expression>
	struct is_self_evaluating
	{
		using Exp = typename Expression::rtn;

		using rtn = typename conref_or_else
		<
			conrei_is_number<Exp>,
//			conrei_is_string<Exp>,
			conrei_is_boolean<Exp>,

			conrei_is_type<Exp>,
			conrei_is_list<Exp>

		>::rtn;
	};
};

