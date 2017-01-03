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

template<size_type current, size_type index, typename L1, typename L2, typename Null = typename L2::null>
struct erase
{
	using new_L1 = IF_THEN_ELSE
	<
		(current == index),
		L1,
		typename L1::template append<L2::car>

	>::rtn;

	using rtn = typename erase<current+1, index, new_L1, typename L2::cdr>::rtn;
};

template<size_type current, size_type index, typename L, typename Null>
struct erase<current, index, L, Null, Null>
{
	using rtn = L;
};

