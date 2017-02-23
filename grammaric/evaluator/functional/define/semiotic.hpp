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

template<typename...> struct body { };
struct Define { };

//

template<typename... Expressions>
struct DEFINE
{
/*
	template<typename, typename Tuple = null_expression, size_type Value = 0> struct parse;

	template<typename Variable, typename... Variables, typename... items, size_type Value>
	struct parse<expression<variable, vars...>, expression<items...>, Value>
	{
		using rtn = parse<expression<vars...>, expression<items..., index<variable, value>>>;

		using variables = typename rtn::variables;
		using body = typename rtn::body;
	};

	template<typename... exp, typename... items, size_type value>
	struct parse<expression<BODY<exp...>>, expression<items...>, value>
	{
		using variables = expression<items...>;
		using body = BODY<exp...>;
	};

	//

	struct analyze
	{
		using is_primitive = boolean<false>;

		using parsed = parse<expression<Expressions...>>;

		using variables = typename parsed::variables;
		using body = typename parsed::body;
	};
*/
};

