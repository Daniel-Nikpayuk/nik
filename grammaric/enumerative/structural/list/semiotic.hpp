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
	using base_type = base<params...>;

	using null = list<>;

//		Translational:

	template<typename Base> struct enlist;

	template<Parameter... args>
	struct enlist<base<args...>>
	{
		using type = list<args...>;
	};

	template<typename List> struct modify;

	template<Parameter... args>
	struct modify<base<args...>>
	{
		using type = typename parameter::template modifier<args...>;
	};

	using modified = modify<typename f_parameter::template quickSort<base_type>::type>;

//		Navigational:

	using car = typename base_type::car;

	using cdr = enlist<typename base_type::cdr::type>;

//		Existential:

	using empty = typename base_type::empty;

	using length = typename base_type::length;

	template<typename List>
	using equals = typename base_type::template equals<typename List::base_type>;

//		Generational:

	template<Parameter p>
	using cons = enlist<typename f_parameter::template cons<p, base_type>::type>;

	template<Parameter p>
	using push = enlist<typename f_parameter::template push<base_type, p>::type>;

	template<typename List>
	using prepend = enlist<typename f_parameter::template catenate<typename List::base_type, base_type>::type>;

	template<typename List>
	using append = enlist<typename f_parameter::template catenate<base_type, typename List::base_type>::type>;

	using sorted = enlist<typename f_parameter::template quickSort<base_type>::type>;

	//

	static void print() { base_type::print(); }
};

