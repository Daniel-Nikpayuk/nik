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

/*
	Lazy policy:

	If you don't have to evaluate it (::rtn), don't.
*/

template<typename P, typename E1, typename E2>
struct conditional
{
	template<typename, typename, typename> struct strict;

	template<typename e1, typename e2>
	struct strict<boolean<true>, e1, e2>
	{
		using rtn = e1;
	};

	template<typename e1, typename e2>
	struct strict<boolean<true>, act<e1>, e2>
	{
		using rtn = typename e1::rtn;
	};

	template<typename e1, typename e2>
	struct strict<boolean<false>, e1, e2>
	{
		using rtn = e2;
	};

	template<typename e1, typename e2>
	struct strict<boolean<false>, e1, act<e2>>
	{
		using rtn = typename e2::rtn;
	};

	using rtn = typename strict
	<
		typename P::rtn,
		E1,
		E2

	>::rtn;
};

