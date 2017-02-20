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

template<typename E1>
struct length
{
	template<typename, typename = constant<size_type, 0>> struct strict;

	template<typename Expression, typename... Expressions, size_type count>
	struct strict<tuple<Expression, Expressions...>, constant<size_type, count>>
	{
		using rtn = typename strict<tuple<Expressions...>, constant<size_type, count+1>>::rtn;
	};

	template<size_type count>
	struct strict<null_tuple, constant<size_type, count>>
	{
		using rtn = constant<size_type, count>;
	};

	using rtn = typename strict
	<
		typename E1::rtn

	>::rtn;
};

