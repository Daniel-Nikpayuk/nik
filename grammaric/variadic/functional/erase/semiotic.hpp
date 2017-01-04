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

template<size_type index, typename inL, typename outL= typename inL::null, size_type current = 0, typename Null = typename inL::null>
struct erase
{
	using new_outL = typename if_then_else
	<
		(current == index),
		outL,
		typename outL::template append<inL::car>

	>::rtn;

	using rtn = typename erase<index, typename inL::cdr, new_outL, current+1>::rtn;
};

template<size_type index, typename Null, typename outL, size_type current>
struct erase<index, Null, outL, current, Null>
{
	using rtn = outL;
};

