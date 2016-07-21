/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

// empty:

template<size_type... params>
struct list
{
	using null = list<>;

	template<size_type... args>
	using prepend = list<args...>;

	template<size_type... args>
	using append = list<args...>;

	static void print() { }
};

template<size_type first, size_type... params>
struct list<first, params...>
{
	using null = list<>;

	static constexpr size_type car = first;

	using cdr = list<params...>;

	template<size_type... args>
	using prepend = list<args..., first, params...>;

	template<size_type... args>
	using append = list<first, params..., args...>;

	static void print() { parameter_printer::template unroll<size_type, first, params...>::print(); }
};

template<size_type first>
struct list<first>
{
	using null = list<>;

	static constexpr size_type car = first;

	using cdr = null;

	template<size_type... args>
	using prepend = list<args..., first>;

	template<size_type... args>
	using append = list<first, args...>;

	static void print() { parameter_printer::template unroll<size_type, first>::print(); }
};

