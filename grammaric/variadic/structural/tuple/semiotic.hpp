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

	using type = tuple;

	using null = tuple<>;

//		Translational:

	template<typename Base> struct entuple;

	template<typename... args>
	struct entuple<module::base<args...>>
	{
		using type = tuple<args...>;
	};

//		Navigational:

	using car = typename base::car;

	using cdr = entuple<typename base::cdr::type>;

//		Existential:

	using empty = typename base::empty;

	using length = typename base::length;

	template<typename Tuple>
	using equals = typename base::template equals<typename Tuple::base>;

//		Generational:

	template<typename Tuple>
	using prepend = entuple<typename functional::template catenate<typename Tuple::base, base>::type>;

	template<typename Tuple>
	using append = entuple<typename functional::template catenate<base, typename Tuple::base>::type>;

	//

	static void print() { base::print(); }
};

