/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename EnumStruct>
struct bit
{
	template<EnumStruct... params>
	using list = typename parameter<EnumStruct>::template list<params...>;

	template<typename L>
	using cast = typename functional::template cast<L>;

	template<EnumStruct... params>
	using list_cast = cast<list<params...>>;

	template<size_type b>
	struct pattern
	{
		template<size_type m>
		using in = typename functional::template in<b, m>;

		template<size_type m>
		using set = typename functional::template set<b, m>;

		template<size_type m>
		using tail = typename functional::template tail<b, m>;

		template<typename... params>
		using dispatch = typename functional::template dispatch<b, params...>;
	};
};

