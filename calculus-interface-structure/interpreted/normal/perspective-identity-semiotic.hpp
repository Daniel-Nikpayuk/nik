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
	((generic)) is_:
*/

	template<typename Exp, template<typename...> class label>
	struct is_
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<label<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

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

	template<typename Exp>
	using is_frame = is_<Exp, frame>;

	template<typename Exp>
	using is_environment = is_<Exp, environment>;

/*
	quote:
*/

	template<typename Exp>
	struct is_quote
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename SubExp>
		struct strict<quote<SubExp>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	lambda:
*/

	template<typename Exp>
	using is_lambda = is_<Exp, lambda>;

	template<typename Exp>
	using is_compound = is_<Exp, procedure>;

/*
	definition:
*/

	template<typename Exp>
	using is_definition = is_<Exp, define>;

	template<typename Expression>
	struct is_value_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename conref_and_then
		<
			is_definition<Exp>,

			conrei_is_literal
			<
				conref_car<Exp>
			>

		>::rtn;
	};

	template<typename Expression>
	struct is_compound_definition
	{
		using Exp = typename Expression::rtn;

		using rtn = typename conref_and_then
		<
			is_definition<Exp>,

			conref_not_the_case
			<
				conrei_is_literal
				<
					conref_car<Exp>
				>
			>

		>::rtn;
	};

/*
	assignment:
*/

	template<typename Exp>
	struct is_assignment
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename Variable, typename Value>
		struct strict<set<Variable, Value>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

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

	template<typename Exp>
	using is_if_ = is_<Exp, if_>;

/*
	begin:
*/

	template<typename Exp>
	using is_begin = is_<Exp, begin>;

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

	template<typename Exp>
	struct is_cond
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<cond<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp>
	struct is_else_
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<else_<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

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
			conrei_is_list<Exp>,

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
			conrei_is_list_type<Exp>

		>::rtn;
	};
};

