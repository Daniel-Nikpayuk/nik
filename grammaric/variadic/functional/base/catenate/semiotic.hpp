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

template<typename... expressions>
struct catenate;

template<typename first, typename second, typename third, typename... expressions>
struct catenate<first, second, third, expressions...>
{
	using rtn = typename catenate<first, catenate<second, third, expressions...>>::rtn;
};

template<typename first, typename second>
struct catenate<first, second>
{
	template<typename... Bases>
	struct strict;

	template<typename... params1, typename... params2>
	struct strict
	<
		base<params1...>,
		base<params2...>

	> { using rtn = base<params1..., params2...>; };

	using rtn = typename strict
	<
		typename first::rtn,
		typename second::rtn

	>::rtn;
};

