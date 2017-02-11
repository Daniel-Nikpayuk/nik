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

template<typename Tuple, typename expression>
struct has;

template<typename first, typename... params, typename expression>
struct has<tuple<first, params...>, expression>
{
	struct rtn
	{
		static constexpr bool value = (first::rtn::value == expression::rtn::value) ||
						has<tuple<params...>, expression>::rtn::value;
	};
};

template<typename expression>
struct has<null_tuple, expression>
{
	struct rtn
	{
		static constexpr bool value = false;
	};
};

