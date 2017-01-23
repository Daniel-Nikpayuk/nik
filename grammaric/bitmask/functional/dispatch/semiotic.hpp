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

template<size_type x, typename L, size_type i = 0, typename Null = typename L::null>
struct dispatch
{
	static constexpr size_type car = (size_type) L::car;

        static constexpr size_type rtn = ((car & x) == car) ? i : dispatch<x, typename L::cdr, i+1>::rtn;
};

template<size_type x, typename Null, size_type i>
struct dispatch<x, Null, i, Null>
{
        static constexpr size_type rtn = i;
};

