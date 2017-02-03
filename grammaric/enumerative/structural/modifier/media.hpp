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

struct mask
{
	template<typename L>
	using cast = typename functional::template cast<L>;

	template<size_type m>
	struct pattern
	{
		template<size_type l>
		using contains = typename functional::template contains<m, l>;

		template<size_type l>
		using complement = typename functional::template complement<m, l>;

		template<size_type n>
		using apply = typename functional::template apply<m, n>;

		template<size_type l>
		using deduct = typename functional::template deduct<m, l>;

		template<size_type... params>
		using match = typename functional::template match<m, params...>;

		template<typename... params>
		using dispatch = typename functional::template dispatch<m, params...>;
	};
};

