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

template<Parameter... params>
struct list
{
	using parameters = list;

//		Navigational:

	using car = typename f_parameter::template car<parameters>;

	using cdr = typename f_parameter::template cdr<parameters>;

//		Generational:

	using null = list<>;

	template<typename List>
	using prepend = typename f_parameter::template catenate<List, parameters>;

	template<typename List>
	using append = typename f_parameter::template catenate<parameters, List>;

//		Existential:

//	using empty = typename functional::template empty<parameters>;

//	using length = typename functional::template length<parameters>;

//	template<typename List>
//	using equals = typename identifier::template equal<parameters, List>;

	//

	static void print() { f_parameter::template printer<parameters>::print(); }
};

