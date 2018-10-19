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

/*
	is_null:
*/

template<typename> struct is_null;

/*
	typename:
*/

template<typename Exp, typename... Exps, template<typename...> class ListType>
struct is_null<ListType<Exp, Exps...>>
{
	static constexpr bool value = false;
};

template<template<typename...> class ListType>
struct is_null<ListType<>>
{
	static constexpr bool value = true;
};

/*
	bool:
*/

template<bool Exp, bool... Exps, template<bool...> class ListType>
struct is_null<ListType<Exp, Exps...>>
{
	static constexpr bool value = false;
};

template<template<bool...> class ListType>
struct is_null<ListType<>>
{
	static constexpr bool value = true;
};

/*
	char:
*/

template<char Exp, char... Exps, template<char...> class ListType>
struct is_null<ListType<Exp, Exps...>>
{
	static constexpr bool value = false;
};

template<template<char...> class ListType>
struct is_null<ListType<>>
{
	static constexpr bool value = true;
};

