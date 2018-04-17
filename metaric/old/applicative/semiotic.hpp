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

template<typename, typename...>
struct applicative;

template<typename function, typename first, typename... params>
struct applicative<function, first, params...>
{
	struct partial
	{
		template<typename... args>
		using lambda = typename function::template lambda<first::rtn, args...>;
	};

	using rtn = typename applicative<partial, params...>::rtn;
};

template<typename function>
struct applicative<function>
{
	using rtn = typename function::template lambda<>::rtn;
};

