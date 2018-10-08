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
	#include nik_typedef(metaric, tuple)

/*
	car:
*/

	template<typename> struct car;

	template<typename Exp, typename... Exps>
	struct car<tuple<Exp, Exps...>>
	{
		using rtn = Exp;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename Exp, typename... Exps>
	struct cdr<tuple<Exp, Exps...>>
	{
		using rtn = tuple<Exps...>;
	};

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Exp, typename... Exps>
	struct cons<Exp, tuple<Exps...>>
	{
		using rtn = tuple<Exp, Exps...>;
	};

/*
	at:
*/

	template<typename, typename> struct at;

	template<typename Exp, typename... Exps, typename Type, Type index>
	struct at<tuple<Exp, Exps...>, constant<Type, index>>
	{
		using rtn = typename strict<tuple<Exps...>, constant<Type, index-1>>::rtn;
	};

	template<typename Exp, typename... Exps, typename Type>
	struct at<tuple<Exp, Exps...>, constant<Type, 0>>
	{
		using rtn = Exp;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename... Exps, typename Exp>
	struct push<tuple<Exps...>, Exp>
	{
		using rtn = tuple<Exps..., Exp>;
	};

/*
	length:
*/

	template<typename, typename = constant<size_type, 0>> struct length;

	template<typename Exp, typename... Exps, size_type count>
	struct length<tuple<Exp, Exps...>, constant<size_type, count>>
	{
		using rtn = typename strict<tuple<Exps...>, constant<size_type, count+1>>::rtn;
	};

	template<size_type count>
	struct length<null_tuple, constant<size_type, count>>
	{
		using rtn = constant<size_type, count>;
	};
};

