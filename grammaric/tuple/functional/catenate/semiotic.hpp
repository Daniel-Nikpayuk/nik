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

/*
template<typename... expressions>
struct catenate
{
	using rtn = typename block
	<
		if_then
		<
			empty<expressions...>,
			null_s

		>, else_then
		<
			singleton<expressions...>,
			expressions...

		>, then
		<

		>

	>::rtn;
};
*/

template<typename E1, typename E2, typename... E>
struct catenate
{
	template<typename, typename, typename...> struct strict;

	template<typename... constants1, typename... constants2, typename e3, typename... e>
	struct strict<t<constants1...>, t<constants2...>, e3, e...>
	{
		using rtn = typename strict
		<
			t<constants1...>,
			strict<t<constants2...>, typename e3::rtn, e...>

		>::rtn;
	};

	template<typename... constants1, typename... constants2>
	struct strict<t<constants1...>, t<constants2...>>
	{
		using rtn = t<constants1..., constants2...>;
	};

	using rtn = typename strict
	<
		typename E1::rtn,
		typename E2::rtn,
		E...

	>::rtn;
};

