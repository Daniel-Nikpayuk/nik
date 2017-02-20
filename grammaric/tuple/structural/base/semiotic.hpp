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

template<typename... Expressions>
struct tuple
{
	using rtn = tuple;

	using null = tuple<>;

//		Navigational:

	using car = module::car<rtn>;

	using cdr = module::cdr<rtn>;

//		Existential:

	template<typename Tuple>
	using equals = equal<rtn, Tuple>;

	using empty = module::empty<Expressions...>;

	using length = module::length<rtn>;

//		Generational:

	template<typename Expression>
	using cons = module::cons<Expression, rtn>;

	template<typename last>
	using push = module::push<rtn, last>;

	template<typename Tuple>
	using prepend = module::catenate<Tuple, rtn>;

	template<typename Tuple>
	using append = module::catenate<rtn, Tuple>;

//		Translational:

	template<typename Type, Type... Values>
	using parameter = module::parameter<Type, Values...>;

	static void print() { module::meta_printer<rtn>::print(); }
};

using null_tuple = tuple<>;

