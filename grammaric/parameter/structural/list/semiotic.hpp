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

template<typename parameter_type = size_type>
struct parameter
{
	// empty:

	template<parameter_type... params>
	struct list
	{
		typedef parameter_type enum_type;

		using null = list<>;

		template<enum_type... args>
		using prepend = list<args...>;

		template<enum_type... args>
		using append = list<args...>;

		static void print() { }
	};

	template<parameter_type first, parameter_type... params>
	struct list<first, params...>
	{
		typedef parameter_type enum_type;

		using null = list<>;

		static constexpr enum_type car = first;

		using cdr = list<params...>;

		template<enum_type... args>
		using prepend = list<args..., first, params...>;

		template<enum_type... args>
		using append = list<first, params..., args...>;

		static void print() { parameter_printer::template unroll<enum_type, first, params...>::print(); }
	};

	template<parameter_type first>
	struct list<first>
	{
		typedef parameter_type enum_type;

		using null = list<>;

		static constexpr enum_type car = first;

		using cdr = null;

		template<enum_type... args>
		using prepend = list<args..., first>;

		template<enum_type... args>
		using append = list<first, args...>;

		static void print() { parameter_printer::template unroll<enum_type, first>::print(); }
	};
};

