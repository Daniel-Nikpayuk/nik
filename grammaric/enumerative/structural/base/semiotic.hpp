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
struct base
{
	using type = base;

	using null = base<>;

//		Translational:

//		Navigational:

	using car = typename f_parameter::template car<type>;

	using cdr = typename f_parameter::template cdr<type>;

//		Existential:

	using empty = typename f_parameter::template empty<type>;

	using length = typename f_parameter::template length<type>;

	template<typename Base>
	using equals = typename identifier::template equal<type, typename Base::type>;

//		Generational:

	//

	static void print() { f_parameter::template printer<type>::print(); }
};

