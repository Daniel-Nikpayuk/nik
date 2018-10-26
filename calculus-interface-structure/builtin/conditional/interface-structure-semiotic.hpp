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

	using type						= structure;

	template<typename, typename, typename>
	struct if_then_else
	{
		using kind					= module;

		using type					= if_then_else;

		using rtn					= if_then_else;
	};

	template<typename, typename>
	struct if_then
	{
		using kind					= module;

		using type					= if_then;

		using rtn					= if_then;
	};

	template<typename, typename>
	struct else_then
	{
		using kind					= module;

		using type					= else_then;

		using rtn					= else_then;
	};

	template<typename>
	struct then
	{
		using kind					= module;

		using type					= then;

		using rtn					= then;
	};
};

