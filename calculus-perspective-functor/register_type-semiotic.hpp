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

#define EIGHT 8

template
<
	global_size_type N,
	typename reg_type = unsigned char,

	bool = (N <= global_size_type(EIGHT) * sizeof(reg_type))

> struct register_type;

#undef EIGHT

/***********************************************************************************************************************/

/*
	char:
*/

template<global_size_type N>
struct register_type<N, unsigned char, true>
{
	using rtn = unsigned char;
};

template<global_size_type N>
struct register_type<N, unsigned char, false>
{
	using rtn = typename register_type<N, unsigned short>::rtn;
};

/*
	short:
*/

template<global_size_type N>
struct register_type<N, unsigned short, true>
{
	using rtn = unsigned short;
};

template<global_size_type N>
struct register_type<N, unsigned short, false>
{
	using rtn = typename register_type<N, unsigned int>::rtn;
};

/*
	int:
*/

template<global_size_type N>
struct register_type<N, unsigned int, true>
{
	using rtn = unsigned int;
};

template<global_size_type N>
struct register_type<N, unsigned int, false>
{
	using rtn = typename register_type<N, unsigned long>::rtn;
};

/*
	long:
*/

template<global_size_type N>
struct register_type<N, unsigned long, true>
{
	using rtn = unsigned long;
};

template<global_size_type N>
struct register_type<N, unsigned long, false>
{
	using rtn = typename register_type<N, unsigned long long>::rtn;
};

/*
	long long:
*/

template<global_size_type N>
struct register_type<N, unsigned long long, true>
{
	using rtn = unsigned long long;
};

template<global_size_type N>
struct register_type<N, unsigned long long, false>
{
	using rtn = unsigned long long; // default
};

