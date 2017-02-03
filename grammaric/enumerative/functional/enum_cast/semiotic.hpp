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

template<typename L, typename L::enum_type x, size_type i = 0, typename Null = typename L::null>
struct enum_cast
{
        static constexpr size_type rtn = (x == L::car) ? i : enum_cast<typename L::cdr, x, i+1>::rtn;
};

template<typename Null, typename Null::enum_type x, size_type i>
struct enum_cast<Null, x, i, Null>
{
        static constexpr size_type rtn = i;
};

