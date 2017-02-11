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

template<typename first, typename second>
struct catenate<first, second>
{
	template<typename... Tuples>
	struct strict;

	template<typename... params1, typename... params2>
	struct strict
	<
		tuple<params1...>,
		tuple<params2...>

	> { using rtn = tuple<params1..., params2...>; };

	using rtn = typename strict
	<
		typename first::rtn,
		typename second::rtn

	>::rtn;
};

template<typename first, typename second, typename third>
struct catenate<first, second, third>
{
	template<typename... Tuples>
	struct strict;

	template<typename... params1, typename... params2, typename... params3>
	struct strict
	<
		tuple<params1...>,
		tuple<params2...>,
		tuple<params3...>

	> { using rtn = tuple<params1..., params2..., params3...>; };

	using rtn = typename strict
	<
		typename first::rtn,
		typename second::rtn,
		typename third::rtn

	>::rtn;
};

