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

template<typename Tuple, typename Filler = void>
struct quickSort;

template<typename first, typename... params, typename Filler>
struct quickSort<tuple<first, params...>, Filler>
{
	using ltoe		= typename compare::template lessThanOrEqual<first>;
	using leftFiltered	= filter<ltoe, tuple<params...>>;
	using leftSorted	= quickSort<leftFiltered>;

	using gtoe		= typename compare::template greaterThanOrEqual<first>;
	using rightFiltered	= filter<gtoe, tuple<params...>>;
	using rightSorted	= quickSort<rightFiltered>;

	using rtn = typename catenate<leftSorted, tuple<first>, rightSorted>::rtn;
};

template<typename Filler>
struct quickSort<null_tuple, Filler>
{
	using rtn = null_tuple;
};

