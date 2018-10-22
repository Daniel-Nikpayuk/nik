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

	template<typename...>
	struct binding
	{
		using kind					= module;

		using type					= binding;

		using rtn					= binding;
	};

	template<typename Variable, typename Value>
	struct binding<Variable, Value>
	{
		using kind					= module;

		using type					= binding;

		using rtn					= binding;

		using variable					= Variable;

		using value					= Value;
	};

	template<typename Variable, typename Value1, typename Value2>
	struct binding<Variable, Value1, Value2>
	{
		using kind					= module;

		using type					= binding;

		using rtn					= binding;

		using variable					= Variable;

		using first_value				= Value1;

		using second_value				= Value2;
	};
};

