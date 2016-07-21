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

template<typename intervals, typename out, typename in, size_type k, size_type n>
struct fill
{
	static constexpr size_type b = intervals::template initial<k>::value;
	static constexpr size_type e = intervals::template terminal<k>::value;

	//

	template<typename in1, typename Filler = void>
	struct new_out_helper
	{
		using rtn = typename cfm_policy::template
			if_then_else
			<
				(b <= in1::car && in1::car <= e),
				typename out::template append<in1::car>,
				typename out::template append<b>

			>::return_type;
	};

	template<typename Filler>
	struct new_out_helper<typename in::null, Filler>
	{
		using rtn = typename out::template append<b>;
	};

	using new_out = typename new_out_helper<in>::rtn;

	//

	template<typename in1, typename Filler = void>
	struct new_in_helper
	{
		using rtn = typename cfm_policy::template
			if_then_else
			<
				(b <= in1::car && in1::car <= e),
				typename in1::cdr,
				in1

			>::return_type;
	};

	template<typename Filler>
	struct new_in_helper<typename in::null, Filler>
	{
		using rtn = typename in::null;
	};

	using new_in = typename new_in_helper<in>::rtn;

	//

	using rtn = typename fill<intervals, new_out, new_in, k+1, n>::rtn;
};

template<typename intervals, typename out, typename in, size_type n>
struct fill<intervals, out, in, n, n>
{
	using rtn = out;
};

