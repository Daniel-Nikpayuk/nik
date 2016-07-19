/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

template<typename L, typename Null = typename L::null>
struct quickSort
{
	using ltoe		= typename media::template lessThanOrEqual<L::car>;
	using leftFiltered	= typename media::template filter<ltoe, typename L::cdr>::rtn;
	using leftSorted	= typename quickSort<leftFiltered>::rtn;

	using gtoe		= typename media::template greaterThanOrEqual<L::car>;
	using rightFiltered	= typename media::template filter<gtoe, typename L::cdr>::rtn;
	using rightSorted	= typename quickSort<rightFiltered>::rtn;

	using rtn = typename catenate<leftSorted, typename rightSorted::template prepend<L::car> >::rtn;
};

template<typename Null>
struct quickSort<Null, Null>
{
	using rtn = Null;
};

