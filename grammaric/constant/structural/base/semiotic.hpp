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

template<typename Type, Type...> struct constant;

template<typename Type>
struct constant<Type>
{
	using rtn = constant;

	using type = Type;

	static void print() { Constant::FS::template printer<rtn>::print(); }
};

template<typename Type, Type Value>
struct constant<Type, Value>
{
	using rtn = constant;

	using type = Type;

	static constexpr Type value = Value;

	static void print() { Constant::FS::template printer<rtn>::print(); }
};

template<bool Value>
using boolean = constant<bool, Value>;

