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

/*
template<Parameter... params> struct list;
template<Parameter... params> struct modifier;

	// empty:

template<Parameter... params>
struct base
{
	using this_type = base;

        using null = list<>;

        template<enum_type... args>
        using prepend = list<args...>;

        template<enum_type... args>
        using append = list<args...>;

        static void print() { }
};

template<Parameter first, Parameter... params>
struct base<first, params...>
{
};
*/

template<Parameter... params>
struct base
{
	using this_type = base;

	using null = base<>;

//		Navigational:

	using car = typename f_parameter::template car<this_type>;

	using cdr = typename f_parameter::template cdr<this_type>;

//		Existential:

	using empty = typename f_parameter::template empty<this_type>;

	using length = typename f_parameter::template length<this_type>;

	template<typename Base>
	using equals = typename identifier::template equal<this_type, typename Base::this_type>;

//		Generational:

	template<typename Base>
	using prepend = typename f_parameter::template catenate<typename Base::this_type, this_type>;

	template<typename Base>
	using append = typename f_parameter::template catenate<this_type, typename Base::this_type>;

	using sorted = typename f_parameter::template quickSort<this_type>;

//		Translational:

/*
	using list = parameter::list<params...>;

	using modifier = parameter::modifier<params...>;
*/

	//

	static void print() { f_parameter::template printer<this_type>::print(); }
};

