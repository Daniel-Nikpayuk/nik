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
	assignment_variable:
*/

	template<typename Exp>
	struct assignment_variable
	{
		using rtn = typename Exp::rtn::variable;
	};

/*
	assignment_value:
*/

	template<typename Exp>
	struct assignment_value
	{
		using rtn = typename Exp::rtn::value;
	};

/*
	evaluate_assignment:
*/

	template<typename Expression, typename Environment, typename Functor>
	struct evaluate_assignment
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename environment_set
		<
			assignment_variable<Exp>,

			typename Func::template eval
			<
				assignment_value<Exp>,
				Env
			>,

			Env

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp1, typename Exp2>
	inline static void display(const set<Exp1, Exp2> &)
	{
		Dispatched::functor::display("set: ");
		Exp1::kind::functor::display(Exp1());
		Dispatched::functor::display(" as ");
		Exp2::kind::functor::display(Exp2());
	}

