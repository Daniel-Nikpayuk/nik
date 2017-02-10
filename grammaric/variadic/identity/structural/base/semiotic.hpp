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
struct base
{
	using type = base;

	using null = base<>;

//		Translational:

//		Navigational:

	using car = typename functional::template car<type>;

	using cdr = typename functional::template cdr<type>;

//		Existential:

	template<typename Base>
	using equals = typename identifier::template equal<type, typename Base::type>;

	using empty = typename identifier::template empty<params...>;

	using length = typename functional::template length<type>;

//		Generational:

	template<typename first>
	using cons = typename functional::template cons<first, base>;

	template<typename last>
	using push = typename functional::template push<base, last>;

	template<typename Base>
	using prepend = typename functional::template catenate<Base, base>;

	template<typename Base>
	using append = typename functional::template catenate<base, Base>;
};

