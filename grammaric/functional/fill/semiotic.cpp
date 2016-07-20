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

template<size_type k, size_type n, typename intervals, typename out, typename in>
struct fill
{
	static constexpr size_type b = intervals::template initial<k>::value;
	static constexpr size_type e = intervals::template terminal<k>::value;

	using new_out = typename media::template
			if_then_else
			<
				(b <= in::car && in::car <= e),
				typename out::template append<in::car>,
				typename out::template append<b>

			>::return_type;

	using cdr_in = typename media::template
			if_then_else
			<
				isNull<typename in::cdr>::rtn,
				in,
				typename in::cdr

			>::return_type;

	using new_in = typename media::template
			if_then_else
			<
				(b <= in::car && in::car <= e),
				cdr_in,
				in

			>::return_type;

	using rtn = typename fill<k+1, n, intervals, new_out, new_in>::rtn;
};

template<size_type n, typename intervals, typename out, typename in>
struct fill<n, n, intervals, out, in>
{
	using rtn = out;
};

