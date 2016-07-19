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

template<typename L, typename FillerType = void>
struct quickSort { };

//

template<size_type current, typename FillerType, size_type... params>
struct quickSort<slist<current, params...>, FillerType>
{
	using cdr = slist<params...>;

	using ltoe = typename media::template lessThanOrEqual<current>;
	using leftFiltered = typename filter<ltoe, null_slist, cdr>::rtn;
	using leftSorted = typename quickSort<leftFiltered>::rtn;

	using gtoe = typename media::template greaterThanOrEqual<current>;
	using rightFiltered = typename filter<gtoe, null_slist, cdr>::rtn;
	using rightSorted = typename quickSort<rightFiltered>::rtn;

	using currentRight = typename cons<current, rightSorted>::rtn;
	using rtn = typename catenate<leftSorted, currentRight>::rtn;
};

template<typename FillerType>
struct quickSort<slist<>, FillerType>
{
	typedef slist<> rtn;
};

//

template<size_type current, typename FillerType, size_type... params>
struct quickSort<mlist<current, params...>, FillerType>
{
	using cdr = mlist<params...>;

	using ltoe = typename media::template lessThanOrEqual<current>;
	using leftFiltered = typename filter<ltoe, null_mlist, cdr>::rtn;
	using leftSorted = typename quickSort<leftFiltered>::rtn;

	using gtoe = typename media::template greaterThanOrEqual<current>;
	using rightFiltered = typename filter<gtoe, null_mlist, cdr>::rtn;
	using rightSorted = typename quickSort<rightFiltered>::rtn;

	using currentRight = typename cons<current, rightSorted>::rtn;
	using rtn = typename catenate<leftSorted, currentRight>::rtn;
};

template<typename FillerType>
struct quickSort<mlist<>, FillerType>
{
	typedef mlist<> rtn;
};

