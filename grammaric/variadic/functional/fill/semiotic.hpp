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

template<typename out, typename in, typename Relation, typename Null = typename Relation::null>
struct fill
{
	using set = typename Relation::car;

	//

	template<typename in1, typename Filler = void>
	struct safe_new_out
	{
		using rtn = IF_THEN_ELSE
		<
			isMember<in1::car, set>::rtn,
			typename out::template append<in1::car>,
			typename out::template append<set::car>

		>::rtn;
	};

	template<typename Filler>
	struct safe_new_out<typename in::null, Filler>
	{
		using rtn = typename out::template append<set::car>;
	};

	using new_out = typename safe_new_out<in>::rtn;

	//

	template<typename in1, typename Filler = void>
	struct safe_new_in
	{
		using rtn = IF_THEN_ELSE
		<
			isMember<in1::car, set>::rtn,
			typename in1::cdr,
			in1

		>::rtn;
	};

	template<typename Filler>
	struct safe_new_in<typename in::null, Filler>
	{
		using rtn = typename in::null;
	};

	using new_in = typename safe_new_in<in>::rtn;

	//

	using rtn = typename fill<new_out, new_in, typename Relation::cdr>::rtn;

};

template<typename out, typename in, typename Null>
struct fill<out, in, Null, Null>
{
	using rtn = out;
};

