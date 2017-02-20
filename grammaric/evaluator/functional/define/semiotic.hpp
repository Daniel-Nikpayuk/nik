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

template<typename...> struct BODY;

//

template<typename... expressions>
struct DEFINE
{
	template<typename Variables, typename Tuple = null_tuple, size_type value = 0>
	struct parse;

	template<typename variable, typename... vars, typename... items, size_type value>
	struct parse<tuple<variable, vars...>, tuple<items...>, value>
	{
		using rtn = parse<tuple<vars...>, tuple<items..., index<variable, value>>>;

		using variables = typename rtn::variables;
		using body = typename rtn::body;
	};

	template<typename... exp, typename... items, size_type value>
	struct parse<tuple<BODY<exp...>>, tuple<items...>, value>
	{
		using variables = tuple<items...>;
		using body = BODY<exp...>;
	};

	//

	struct analyze
	{
		using parsed = parse<tuple<expressions...>>;

		using variables = typename parsed::variables;
		using body = typename parsed::body;
	};
};

