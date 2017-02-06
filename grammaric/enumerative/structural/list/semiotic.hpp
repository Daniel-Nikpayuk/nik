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
	using base = parameter::base<params...>;

	using type = list;

	using null = list<>;

//		Translational:

	template<typename Base> struct enlist;

	template<Parameter... args>
	struct enlist<parameter::base<args...>>
	{
		using type = list<args...>;
	};

	template<typename List> struct modify;

	template<Parameter... args>
	struct modify<parameter::base<args...>>
	{
		using type = typename parameter::template modifier<args...>;
	};

	using modified = modify<typename f_parameter::template quickSort<base>::type>;

//		Navigational:

	using car = typename base::car;

	using cdr = enlist<typename base::cdr::type>;

//		Existential:

	using empty = typename base::empty;

	using length = typename base::length;

	template<typename List>
	using equals = typename base::template equals<typename List::base>;

//		Generational:

	template<Parameter p>
	using cons = enlist<typename f_parameter::template cons<p, base>::type>;

	template<Parameter p>
	using push = enlist<typename f_parameter::template push<base, p>::type>;

	template<typename List>
	using prepend = enlist<typename f_parameter::template catenate<typename List::base, base>::type>;

	template<typename List>
	using append = enlist<typename f_parameter::template catenate<base, typename List::base>::type>;

	using sorted = enlist<typename f_parameter::template quickSort<base>::type>;

	//

	static void print() { base::print(); }
};

