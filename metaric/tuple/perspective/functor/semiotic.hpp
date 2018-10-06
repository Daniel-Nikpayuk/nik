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

struct functor
{
/*
	car:
*/

	template<typename> struct car;

	template<typename Expression, typename... Expressions>
	struct car<tuple<Expression, Expressions...>>
	{
		using rtn = Expression;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename Expression, typename... Expressions>
	struct cdr<tuple<Expression, Expressions...>>
	{
		using rtn = tuple<Expressions...>;
	};

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Expression, typename... Expressions>
	struct cons<Expression, tuple<Expressions...>>
	{
		using rtn = tuple<Expression, Expressions...>;
	};

/*
	at:
*/

	template<typename, typename> struct at;

	template<typename Expression, typename... Expressions, typename Type, Type index>
	struct at<tuple<Expression, Expressions...>, constant<Type, index>>
	{
		using rtn = typename strict<tuple<Expressions...>, constant<Type, index-1>>::rtn;
	};

	template<typename Expression, typename... Expressions, typename Type>
	struct at<tuple<Expression, Expressions...>, constant<Type, 0>>
	{
		using rtn = Expression;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename... Expressions, typename Expression>
	struct push<tuple<Expressions...>, Expression>
	{
		using rtn = tuple<Expressions..., Expression>;
	};

/*
	length:
*/

	template<typename, typename = constant<size_type, 0>> struct length;

	template<typename Expression, typename... Expressions, size_type count>
	struct length<tuple<Expression, Expressions...>, constant<size_type, count>>
	{
		using rtn = typename strict<tuple<Expressions...>, constant<size_type, count+1>>::rtn;
	};

	template<size_type count>
	struct length<null_tuple, constant<size_type, count>>
	{
		using rtn = constant<size_type, count>;
	};
};

