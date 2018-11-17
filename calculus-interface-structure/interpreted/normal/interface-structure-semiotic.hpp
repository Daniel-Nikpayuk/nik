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

struct structure
{
	using kind						= module;

	using rtn						= structure;

/*
	error:
*/

	template<char...>
	struct error
	{
		using kind					= module;

		using rtn					= error;
	};

/*
	environment:
*/

	template<typename Variable, typename Value>
	struct binding
	{
		using kind					= module;

		using rtn					= binding;

		using variable					= Variable;

		using value					= Value;
	};

	template<typename... Bindings>
	struct frame
	{
		using kind					= module;

		using rtn					= frame;
	};

	template<typename... Frames>
	struct environment
	{
		using kind					= module;

		using rtn					= environment;
	};

/*
	quote:
*/

	template<typename>
	struct quote
	{
		using kind					= module;

		using rtn					= quote;
	};

/*
	lambda:
*/

	template<typename...>
	struct arguments
	{
		using kind					= module;

		using rtn					= arguments;
	};

	template<typename...>
	struct body
	{
		using kind					= module;

		using rtn					= body;
	};

	template<typename...>
	struct lambda
	{
		using kind					= module;

		using rtn					= lambda;
	};

	template<typename...>
	struct procedure
	{
		using kind					= module;

		using rtn					= procedure;
	};

/*
	definition:
*/

	template<typename...>
	struct define
	{
		using kind					= module;

		using rtn					= define;
	};

/*
	assignment:
*/

	template<typename Variable, typename Value>
	struct set
	{
		using kind					= module;

		using rtn					= set;

		using variable					= Variable;

		using value					= Value;
	};

/*
	if_:
*/

	template<typename...>
	struct if_
	{
		using kind					= module;

		using rtn					= if_;
	};

/*
	begin:
*/

	template<typename...>
	struct begin
	{
		using kind					= module;

		using rtn					= begin;
	};

/*
	cond:
*/

	template<typename...>
	struct cond
	{
		using kind					= module;

		using rtn					= cond;
	};

	template<typename...>
	struct try_
	{
		using kind					= module;

		using rtn					= try_;
	};

	template<typename...>
	struct else_
	{
		using kind					= module;

		using rtn					= else_;
	};

/*
	expression:
*/

	template<typename... Exps>
	struct expression
	{
		using kind					= module;

		using rtn					= expression;
	};
};

