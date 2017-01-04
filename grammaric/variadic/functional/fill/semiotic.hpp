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

template<typename inL, typename Relation, typename outL = typename inL::null, typename Null = typename Relation::null>
struct fill
{
	using set = typename Relation::car;

	//

	template<typename in, typename inNull = typename in::null>
	struct safe_new_out
	{
		using rtn = typename if_then_else
		<
			isMember<set, in::car>::rtn,
			typename outL::template append<in::car>,
			typename outL::template append<set::car>

		>::rtn;
	};

	template<typename inNull>
	struct safe_new_out<inNull, inNull>
	{
		using rtn = typename outL::template append<set::car>;
	};

	using new_outL = typename safe_new_out<inL>::rtn;

	//

	template<typename in, typename inNull = typename in::null>
	struct safe_new_in
	{
		using rtn = typename if_then_else
		<
			isMember<set, in::car>::rtn,
			typename in::cdr,
			in

		>::rtn;
	};

	template<typename inNull>
	struct safe_new_in<inNull, inNull>
	{
		using rtn = inNull;
	};

	using new_inL = typename safe_new_in<inL>::rtn;

	//

	using rtn = typename fill<new_inL, typename Relation::cdr, new_outL>::rtn;
};

template<typename inL, typename Null, typename outL>
struct fill<inL, Null, outL, Null>
{
	using rtn = outL;
};

