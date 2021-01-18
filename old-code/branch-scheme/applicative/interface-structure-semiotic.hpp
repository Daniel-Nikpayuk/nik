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
	continuation:
*/

	template<typename... Exps>
	struct continuation
	{
		using kind					= module;

		using rtn					= continuation;
	};

/*
	quote:
*/

	using quote		= literal<'q', 'u', 'o', 't', 'e'>;

/*
	lambda:
*/

	using lambda		= literal<'l', 'a', 'm', 'b', 'd', 'a'>;
	using procedure		= literal<'p', 'r', 'o', 'c', 'e', 'd', 'u', 'r', 'e'>;

/*
	definition:
*/

	using define 		= literal<'d', 'e', 'f', 'i', 'n', 'e'>;

/*
	assignment:
*/

	using set 		= literal<'s', 'e', 't'>;

/*
	if_:
*/

	using if_ 		= literal<'i', 'f', '_'>;

/*
	begin:
*/

	using begin 		= literal<'b', 'e', 'g', 'i', 'n'>;

/*
	cond:
*/

	using cond 		= literal<'c', 'o', 'n', 'd'>;
	using else_ 		= literal<'e', 'l', 's', 'e', '_'>;

/*
	expression:
*/

	template<typename... Exps>
	struct expression
	{
		using kind					= module;

		using rtn					= expression;
	};

/*
	space:
*/

	template<size_type length, typename Type>
	struct space
	{
		using kind					= module;

		using rtn					= space;
	};
};

