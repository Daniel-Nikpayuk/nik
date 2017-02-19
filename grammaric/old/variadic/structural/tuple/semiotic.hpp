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
struct tuple
{
	using base = module::base<params...>;

	using rtn = tuple;

	using null = tuple<>;

	//

	template<typename expression>
	struct entuple
	{
		template<typename Base> struct coerce;

		template<typename... args>
		struct coerce<module::base<args...>>
		{
			using rtn = tuple<args...>;
		};

		using rtn = typename coerce<typename expression::rtn>::rtn;
	};

//		Navigational:

	using car = typename base::car;

	using cdr = entuple<typename base::cdr>;

//		Existential:

	template<typename Tuple>
	using equals = typename base::template equals<typename Tuple::base>;

	using empty = typename base::empty;

	using length = typename base::length;

//		Generational:

	template<typename first>
	using cons = entuple<typename base::template cons<first>>;

	template<typename last>
	using push = entuple<typename base::template push<last>>;

	template<typename Tuple>
	using prepend = entuple<typename base::template prepend<Tuple>>;

	template<typename Tuple>
	using append = entuple<typename base::template append<Tuple>>;

//		Translational:

	static void print() { functional::template meta_printer<base>::print(); }
};

using null_tuple = tuple<>;

