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

#define declare_is_null(value_type)											\
															\
	template<value_type Exp, value_type... Exps, template<value_type...> class ListType>				\
	struct is_null<ListType<Exp, Exps...>>										\
	{														\
		static constexpr bool value = false;									\
	};														\
															\
	template<template<value_type...> class ListType>								\
	struct is_null<ListType<>>											\
	{														\
		static constexpr bool value = true;									\
	};

	declare_is_null(typename)
	declare_is_null(bool)
	declare_is_null(char)

	declare_is_null(signed char)
	declare_is_null(wchar_t)
	declare_is_null(char16_t)
	declare_is_null(char32_t)
	declare_is_null(short)
	declare_is_null(unsigned short)
	declare_is_null(int)
	declare_is_null(unsigned int)
	declare_is_null(long)
	declare_is_null(unsigned long)
	declare_is_null(long long)
	declare_is_null(unsigned long long)

#undef declare_is_null

