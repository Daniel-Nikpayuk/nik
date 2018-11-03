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

	#define safe_name

		#include nik_typedef(calculus, interpreted, binding, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, frame, structure)

/*
	construct:	Takes a list of variables as well as a list of values and creates
			a frame of bindings. This implementation assumes the variable
			and value lists are the same size.
*/

	template<typename Exp1, typename Exp2>
	struct construct
	{
		using VariableList	= typename Exp1::rtn;
		using ValueList		= typename Exp2::rtn;

		using rtn		= typename if_then_else
		<
			is_null<VariableList>,
			null_frame,
			cons
			<
				intbif_construct // binding
				<
					car<VariableList>,
					car<ValueList>
				>,

				construct
				<
					cdr<VariableList>,
					cdr<ValueList>
				>
			>

		>::rtn;
	};

/*
	split:
*/

	template<typename Exp1, typename Exp2, typename Exp3>
	struct split
	{
		using Variable	= typename Exp1::rtn;
		using Frame1	= typename Exp2::rtn;
		using Frame2	= typename Exp3::rtn;

		template<typename SubExp1, typename SubExp2>
		struct recurse
		{
			using frame_car	= typename SubExp1::rtn;
			using frame_cdr	= typename SubExp2::rtn;

			using rtn	= typename if_then_else
			<
				is_equal
				<
					Variable,
					intbif_binding_variable<frame_car>
				>,

				list<frame_car, Frame1, frame_cdr>,

				split
				<
					Variable,
					push<Frame1, frame_car>,
					frame_cdr
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Frame2>,
			list<unbound, Frame1, null_frame>,

			recurse
			<
				car<Frame2>,
				cdr<Frame2>
			>

		>::rtn;
	};

/*
	lookup:
*/

	template<typename Variable, typename Frame>
	struct lookup
	{
		using rtn = typename car
		<
			split
			<
				Variable,
				null_frame,
				Frame
			>

		>::rtn;
	};

/*
	set:
*/

	template<typename Exp1, typename Exp2, typename Frame>
	struct set
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;

		using Triple	= typename split
		<
			Variable,
			null_frame,
			Frame

		>::rtn;

		using rtn = typename if_then_else
		<
			is_equal
			<
				car<Triple>,
				unbound
			>,

			unbound,

			catenate
			<
				at<one, Triple>,

				cons
				<
					binding<Variable, Value>,
					at<two, Triple>
				>
			>

		>::rtn;
	};

/*
	define:
*/

	template<typename Exp1, typename Exp2, typename Frame>
	struct define
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;

		using Triple	= typename split
		<
			Variable,
			null_frame,
			Frame

		>::rtn;

		using rtn = typename if_then_else
		<
			is_equal
			<
				car<Triple>,
				unbound
			>,

			cons
			<
				binding<Variable, Value>,
				at<one, Triple>
			>,

			catenate
			<
				at<one, Triple>,

				cons
				<
					binding<Variable, Value>,
					at<two, Triple>
				>
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	template<typename Binding, typename... Bindings>
	inline static void display(const frame<Binding, Bindings...> & f)
	{
		using is_empty = typename is_null<frame<Bindings...>>::rtn;

		Dispatched::functor::display("frame: ");
		Binding::kind::functor::display(Binding());

		if (!is_empty::value) Recursed::functor::display(frame<Bindings...>(), ", ");
	}

	inline static void display(const null_frame &)
	{
		Dispatched::functor::display("frame: null");
	}
*/
};

