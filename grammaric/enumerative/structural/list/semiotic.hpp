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

	template<typename Base> struct coerce;

	template<Parameter... args>
	struct coerce<base<args...>>
	{
		using type = list<args...>;
	};

/*
	using keyword is lazy. Required if normal evaluation fails on methods such as cdr with a null list.

	template<typename Method>
	struct safe
	{
		using type = coerce<typename Method::type>::type;
	};
*/

//		Navigational:

	using car = typename base_type::car;

	using cdr = coerce<typename base_type::cdr::type>;

//		Existential:

	using empty = typename f_parameter::template empty<base_type>;

	using length = typename f_parameter::template length<base_type>;

	template<typename List>
	using equals = typename identifier::template equal<base_type, typename List::base_type>;

//		Generational:

	template<typename List>
	using prepend = coerce<typename f_parameter::template catenate<typename List::base_type, base_type>::type>;

	template<typename List>
	using append = coerce<typename f_parameter::template catenate<base_type, typename List::base_type>::type>;

	using sorted = coerce<typename f_parameter::template quickSort<base_type>::type>;

	//

	static void print() { base_type::print(); }
};

