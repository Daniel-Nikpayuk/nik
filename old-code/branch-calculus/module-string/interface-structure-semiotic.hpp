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

	template<register_type...>
	struct string
	{
		using kind					= module;

		using rtn					= literal;
	};
};

/*
	I've wanted to add an "array" thinking it might be useful,
	but as of yet, I have not had need to use it.

	template<char... params>
	struct array
	{
		static constexpr size_type size = length<list<char...>>::rtn::value;
		static constexpr char names[size] { params... };
	};
*/

