/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct structure
{
	using kind		= module;

	using rtn		= structure;

	#include nik_typedef(symbolic, calculus, product, structure)

/*
	memoized_builtin_copair:
*/

	template<typename Type, typename Exp>
	using memoized_builtin_copair = memoized_builtin_builtin_pair<bool, Type, Exp>;

/*
	memoized_typename_copair:
*/

	template<typename Exp>
	using memoized_typename_copair = memoized_builtin_typename_pair<bool, Exp>;
};

