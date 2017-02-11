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

template<typename... params>
struct list
{
	using tuple = module::tuple<params...>;

	using rtn = list;

	using null = list<>;

	//

	template<typename expression>
	struct enlist
	{
		template<typename Tuple> struct coerce;

		template<typename... args>
		struct coerce<module::tuple<args...>>
		{
			using rtn = list<args...>;
		};

		using rtn = typename coerce<typename expression::rtn>::rtn;
	};

	//

	template<typename Parameter, Parameter... args>
	struct parameter
	{
		template<typename P, P...>
		struct coerce;

		template<typename P, P first, P... a>
		struct coerce<P, first, a...>
		{
			using rtn = typename functional::template catenate
			<
				module::tuple<typename identifier::template parameter<P>::template constant<first>>,
				coerce<P, a...>

			>::rtn;
		};

		template<typename P>
		struct coerce<P>
		{
			using rtn = null_tuple;
		};

		using rtn = typename enlist<coerce<Parameter, args...>>::rtn;
	};

//		Navigational:

	using car = typename tuple::car;

	using cdr = enlist<typename tuple::cdr>;

//		Existential:

	using empty = typename tuple::empty; 
	using length = typename tuple::length;

	template<typename List>
	using equals = typename tuple::template equals<typename List::tuple>;

//		Generational:

	template<typename x>
	using cons = enlist<typename tuple::template cons<x>>;

	template<typename x>
	using push = enlist<typename tuple::template push<x>>;

	template<typename List>
	using prepend = enlist<typename tuple::template prepend<typename List::tuple>>;

	template<typename List>
	using append = enlist<typename tuple::template append<typename List::tuple>>;

	using sort = enlist<typename functional::template quickSort<tuple>>;

//		Translational:

	static void print() { functional::template list_printer<rtn>::print(); }
};

using null_list = list<>;

