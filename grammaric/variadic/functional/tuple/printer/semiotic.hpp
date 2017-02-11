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

template<typename Tuple, typename Filler = void>
struct tuple_printer;

template<typename first, typename... params, typename Filler>
struct tuple_printer<tuple<first, params...>, Filler>
{
	static void print()
	{
		identifier::template printer<first::rtn::type>::print(", ");
		tuple_printer<tuple<params...>>::print();
	}
};

template<typename Filler>
struct tuple_printer<null_tuple, Filler>
{
	static void print()
	{
		builtin_printer::print('\n');
	}
};

