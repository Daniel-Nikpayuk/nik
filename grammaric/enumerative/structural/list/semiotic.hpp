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

/*
	lazy type resolution:
*/

	template<typename Method>
	struct enlist
	{
		template<typename Base> struct coerce;

		template<Parameter... args>
		struct coerce<parameter::base<args...>>
		{
			using type = list<args...>;
		};

		using type = typename coerce<typename Method::type>::type;
	};

	template<typename Method>
	struct modify
	{
		template<typename Base> struct coerce;

		template<Parameter... args>
		struct coerce<parameter::base<args...>>
		{
			using type = modifier<args...>;
		};

		using type = typename coerce<typename Method::type>::type;
	};

	using modified = modify<typename f_parameter::template quickSort<base>>;

//		Navigational:

	using car = typename base::car;

	using cdr = enlist<typename base::cdr>;

//		Existential:

	using empty = typename base::empty;

	using length = typename base::length;

	template<typename List>
	using equals = typename base::template equals<typename List::base>;

//		Generational:

	template<Parameter p>
	using cons = enlist<typename f_parameter::template cons<p, base>>;

	template<Parameter p>
	using push = enlist<typename f_parameter::template push<base, p>>;

	template<typename List>
	using prepend = enlist<typename f_parameter::template catenate<typename List::base, base>>;

	template<typename List>
	using append = enlist<typename f_parameter::template catenate<base, typename List::base>>;

	using sorted = enlist<typename f_parameter::template quickSort<base>>;

	//

	static void print() { base::print(); }
};

