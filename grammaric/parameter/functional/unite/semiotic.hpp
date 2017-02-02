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

template<typename outL, typename inL1, typename inL2, typename Null = typename inL2::null>
struct unite
{
	static constexpr bool L1_lt_L2 = inL1::car < inL2::car;

	using new_outL = if_then_else
	<
		L1_lt_L2,

		if_then_else
		<
			inL1,

		>::rtn,

		if_then_else
		<
			inL2

		>::rtn

	>::rtn;

	using rtn = unite<new_outL, new_inL1, new_inL2>::rtn;
};

template<typename outL, typename inL1, typename Null>
struct unite<outL, inL1, Null, Null>
{
	using rtn = catenate<outL, inL1>::rtn;
};

template<typename outL, typename Null, typename inL2>
struct unite<outL, Null, inL2, Null>
{
	using rtn = catenate<outL, inL2>::rtn;
};

