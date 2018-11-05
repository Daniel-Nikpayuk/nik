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

	#include nik_typedef(calculus, interpreted, lambda, structure)

/*
	lambda_arguments:
*/

	template<typename Exp>
	struct lambda_arguments
	{
		using rtn = typename Exp::rtn::arguments;
	};

/*
	lambda_body:
*/

	template<typename Exp>
	struct lambda_body
	{
		using rtn = typename Exp::rtn::body;
	};

/*
	make_lambda:
*/

	template<typename Args, typename Body>
	struct make_lambda
	{
		using rtn = lambda
		<
			typename Args::rtn,
			typename Body::rtn
		>;
	};

/*
	procedure_arguments:
*/

	template<typename Exp>
	struct procedure_arguments
	{
		using rtn = typename Exp::rtn::arguments;
	};

/*
	procedure_body:
*/

	template<typename Exp>
	struct procedure_body
	{
		using rtn = typename Exp::rtn::body;
	};

/*
	procedure_environment:
*/

	template<typename Exp>
	struct procedure_environment
	{
		using rtn = typename Exp::rtn::environment;
	};

/*
	make_procedure:
*/

	template<typename Args, typename Body, typename Env>
	struct make_procedure
	{
		using rtn = procedure
		<
			typename Args::rtn,
			typename Body::rtn,
			typename Env::rtn
		>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	template<typename Exp>
	inline static void display(const procedure<Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
*/
};

