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

template<typename P, typename E1, typename E2>
struct conditional
{
	template<bool, typename, typename> struct strict;

	template<typename Type1, Type1... v1, typename Type2, Type2... v2>
	struct strict<true, c<Type1, v1...>, c<Type2, v2...>>
	{
		using rtn = c<Type1, v1...>;
	};

	template<typename Type1, Type1... v1, typename Type2, Type2... v2>
	struct strict<false, c<Type1, v1...>, c<Type2, v2...>>
	{
		using rtn = c<Type2, v2...>;
	};

	using rtn = typename strict
	<
		P::rtn::value,
		typename E1::rtn,
		typename E2::rtn

	>::rtn;
};

