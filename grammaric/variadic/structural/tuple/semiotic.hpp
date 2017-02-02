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

// empty:

template<typename... params>
struct tuple
{
	using parameters = tuple;

//		Navigational:

	using car = typename functional::template car<parameters>;

	using cdr = typename functional::template cdr<parameters>;

//		Generational:

	using null = tuple<>;

	template<typename Tuple>
	using prepend = typename functional::template catenate<Tuple, parameters>;

	template<typename Tuple>
	using append = typename functional::template catenate<parameters, Tuple>;

//		Existential:

	template<typename Tuple>
	using equals = typename identifier::template equal<parameters, Tuple>;

	using length = typename functional::template length<parameters>;

	//

	static void print() { functional::template printer<parameters>::print(); }
};

