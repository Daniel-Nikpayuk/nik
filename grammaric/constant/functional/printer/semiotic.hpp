/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename Exp>
struct printer
{
	template<typename> struct strict;

	template<typename Type>
	struct strict<constant<Type>>
	{
		static void print()
		{
			type_printer<Type>::print();
		};
	};

	template<typename Type, Type Value>
	struct strict<constant<Type, Value>>
	{
		static void print()
		{
			type_printer<Type>::print();
			builtin_printer::print(": ");
			builtin_printer::print(Value);
		};
	};

	static void print()
	{
		strict<typename Exp::rtn>::print();
	}
};

