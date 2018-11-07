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

	using rtn		= functor;

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

		using rtn = typename if_then_else
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
			using first	= typename SubExp1::rtn;
			using rest	= typename SubExp2::rtn;

			using rtn = typename if_then_else
			<
				is_equal
				<
					Variable,
					intbif_binding_variable<first>
				>,

				list<first, Frame1, rest>,

				split
				<
					Variable,
					push<first, Frame1>,
					rest
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Frame2>,

			list
			<
				error<'u', 'n', 'b', 'o', 'u', 'n', 'd', ' ', 'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e'>,
				Frame1,
				null_frame
			>,

			recurse
			<
				car<Frame2>,
				cdr<Frame2>
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Binding, typename... Bindings>
	inline static void display(const frame<Binding, Bindings...> & f)
	{
		using is_empty = typename is_null<frame<Bindings...>>::rtn;

		Dispatched::functor::display("frame:\n ");
		Recursed::functor::display(frame<Binding, Bindings...>(), ", ");
	}

	inline static void display(const null_frame &)
	{
		Dispatched::functor::display("frame: null");
	}
};

