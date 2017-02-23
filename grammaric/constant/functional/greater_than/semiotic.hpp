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

// Assumes "Type" has an implicit equals operator:

template<typename Exp1, typename Exp2>
struct greater_than
{
	template<typename, typename> struct strict;

	template<typename Type, Type Value1, Type Value2>
	struct strict<constant<Type, Value1>, constant<Type, Value2>>
	{
		using rtn = boolean<(Value1 > Value2)>;
	};

	using rtn = typename strict
	<
		typename Exp1::rtn,
		typename Exp2::rtn

	>::rtn;
};

