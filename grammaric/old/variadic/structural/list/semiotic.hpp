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

template<typename... params>
struct list
{
	using base = module::base<params...>;

	using rtn = list;

	using null = list<>;

	//

	template<typename expression>
	struct enlist
	{
		template<typename Base> struct coerce;

		template<typename... args>
		struct coerce<module::base<args...>>
		{
			using rtn = list<args...>;
		};

		using rtn = typename coerce<typename expression::rtn>::rtn;
	};

//		Navigational:

	using car = typename base::car;

	using cdr = enlist<typename base::cdr>;

//		Existential:

	template<typename List>
	using equals = typename base::template equals<List>;

	using empty = typename base::empty; 

	using length = typename base::length;

//		Generational:

	template<typename first>
	using cons = enlist<typename base::template cons<first>>;

	template<typename last>
	using push = enlist<typename base::template push<last>>;

	template<typename List>
	using prepend = enlist<typename base::template prepend<List>>;

	template<typename List>
	using append = enlist<typename base::template append<List>>;

	using sort = enlist<typename functional::template quickSort<base>>;

//		Translational:

	template<typename Parameter, Parameter... args>
	using parameter = enlist<typename base::template parameter<Parameter, args...>>;

	//

	static void print() { functional::template printer<base>::print(); }
};

using null_list = list<>;

