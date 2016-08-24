/************************************************************************************************************************
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
************************************************************************************************************************/

template<size_type index, typename if_zero, typename if_one, typename... params>
struct cases
{
	using in = typename structural<nik::semiotic>::template tuple<params...>;

	using rtn = typename semiotic::template cases<in, index-2>::rtn;
};

template<typename if_zero, typename if_one, typename... params>
struct cases<0, if_zero, if_one, params...>
{
	using rtn = if_zero;
};

template<typename if_zero, typename if_one, typename... params>
struct cases<1, if_zero, if_one, params...>
{
	using rtn = if_one;
};

