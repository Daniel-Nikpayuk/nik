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

template<typename E1, typename E2, typename... E>
struct catenate
{
	template<typename, typename, typename...> struct strict;

	template<typename... Expressions1, typename... Expressions2, typename e3, typename... e>
	struct strict<tuple<Expressions1...>, tuple<Expressions2...>, e3, e...>
	{
		using rtn = typename strict
		<
			tuple<Expressions1..., Expressions2...>,
			typename e3::rtn,
			e...

		>::rtn;
	};

	template<typename... Expressions1, typename... Expressions2>
	struct strict<tuple<Expressions1...>, tuple<Expressions2...>>
	{
		using rtn = tuple<Expressions1..., Expressions2...>;
	};

	using rtn = typename strict
	<
		typename E1::rtn,
		typename E2::rtn,
		E...

	>::rtn;
};

