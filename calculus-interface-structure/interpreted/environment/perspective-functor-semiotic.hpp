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

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

	#include nik_typedef(calculus, interpreted, error, identity)

	#define safe_name

		#include nik_typedef(calculus, interpreted, frame, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, environment, structure)

/*
	construct:

	Parameters are evaluated in the methods to which they are passed.
*/

	template<typename VariableList, typename ValueList, typename Env = null_environment>
	struct construct
	{
		using rtn = typename cons
		<
			intfrf_construct
			<
				VariableList,
				ValueList
			>,

			Env

		>::rtn;
	};

/*
	split:
*/

	template<typename Exp1, typename Exp2, typename Exp3>
	struct split
	{
		using Variable	= typename Exp1::rtn;
		using Env1	= typename Exp2::rtn;
		using Env2	= typename Exp3::rtn;

		template<typename SubExp1, typename SubExp2>
		struct recurse
		{
			using env_car	= typename SubExp1::rtn;
			using env_cdr	= typename SubExp2::rtn;

			using result	= typename intfrf_split
			<
				Variable,
				null_frame,
				env_car

			>::rtn;

			using rtn	= typename if_then_else
			<
				is_error
				<
					car<result>
				>,

				split
				<
					Variable,
					push<Env1, env_car>,
					env_cdr
				>,

				catenate
				<
					result,
					list<Env1, env_cdr>
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Env2>,

			list
			<
				error<'u', 'n', 'b', 'o', 'u', 'n', 'd', ' ', 'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e'>,
				Env1,
				Env2
			>,

			recurse
			<
				car<Env2>,
				cdr<Env2>
			>

		>::rtn;
	};

/*
	lookup:
*/

	template<typename Variable, typename Env>
	struct lookup
	{
		using rtn = typename car
		<
			split
			<
				Variable,
				null_environment,
				Env
			>

		>::rtn;

		static_assert
		(
			is_error<rtn>::rtn::value,
			"variable lookup error!"
		);
	};

/*
	set:
*/

	template<typename Exp1, typename Exp2, typename Env>
	struct set
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;

		using Tuple	= typename split
		<
			Variable,
			null_environment,
			Env

		>::rtn;

		using Type	= typename car<Tuple>::rtn;

		using rtn	= typename if_then_else
		<
			is_error<Type>,

			Type,

			unite
			<
				at<three, Tuple>,

				unite
				<
					at<one, Tuple>,
					binding<Variable, Value>,
					at<two, Tuple>
				>,

				at<four, Tuple>
			>

		>::rtn;

		static_assert
		(
			is_error<rtn>::rtn::value,
			"variable assignment error!"
		);
	};

/*
	define:
*/

	template<typename Exp1, typename Exp2, typename Env>
	struct define
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;

		using Tuple	= typename intfrf_split
		<
			Variable,
			null_frame,
			car<Env>

		>::rtn;

		using rtn	= typename cons
		<
			if_then_else
			<
				is_error
				<
					car<Tuple>
				>,

				cons
				<
					binding<Variable, Value>,
					at<one, Tuple>
				>,

				unite
				<
					at<one, Tuple>,
					binding<Variable, Value>,
					at<two, Tuple>
				>
			>,

			cdr<Env>

		>::rtn;

		static_assert
		(
			is_error<rtn>::rtn::value,
			"variable assignment error!"
		);
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Frame, typename... Frames>
	inline static void display(const environment<Frame, Frames...> & e)
	{
		using is_empty = typename is_null<environment<Frames...>>::rtn;

		Dispatched::functor::display("environment: ");
		Frame::kind::functor::display(Frame());

		if (!is_empty::value) Recursed::functor::display(environment<Frames...>(), ", ");
	}

	inline static void display(const null_environment &)
	{
		Dispatched::functor::display("environment: null");
	}
};

