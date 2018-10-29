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

	template<typename Type, Type...>
	struct typed_list
	{
		using kind					= module;

		using type					= typed_list;

		using rtn					= typed_list;

		using value_type				= Type;
	};

	template<typename Type, Type Value>
	struct typed_list<Type, Value>
	{
		using kind					= module;

		using type					= typed_list;

		using rtn					= typed_list;

		using value_type				= Type;

		static constexpr value_type value		= Value;
	};

	struct other_type
	{
		using kind					= module;

		using type					= other_type;

		using rtn					= other_type;
	};
};

