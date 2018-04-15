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

template<typename Base, typename Filler = void>
struct quickSort;

template<typename first, typename... params, typename Filler>
struct quickSort<base<first, params...>, Filler>
{
	using ltoe		= typename compare::template lessThanOrEqual<first>;
	using leftFiltered	= filter<ltoe, base<params...>>;
	using leftSorted	= quickSort<leftFiltered, Filler>;

	using gtoe		= typename compare::template greaterThanOrEqual<first>;
	using rightFiltered	= filter<gtoe, base<params...>>;
	using rightSorted	= quickSort<rightFiltered, Filler>;

	using rtn = typename catenate<leftSorted, base<first>, rightSorted>::rtn;
};

template<typename Filler>
struct quickSort<null_base, Filler>
{
	using rtn = null_base;
};

