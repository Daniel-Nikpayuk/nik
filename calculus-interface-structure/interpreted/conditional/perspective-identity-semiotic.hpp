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

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(calculus, interpreted, conditional, structure)

/*
	is_true:
*/

	template<typename Exp>
	struct is_true
	{
		template<typename Type, typename Filler = void>
		struct strict
		{
			using rtn = boolean<true>;
		};

		template<typename Filler>
		struct strict<boolean<false>, Filler>
		{
			using rtn = boolean<false>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_if_:
*/

	template<typename Exp>
	struct is_if_
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<if_<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_cond:
*/

	template<typename Exp>
	struct is_cond
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<cond<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_else_:
*/

	template<typename Exp>
	struct is_else_
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<else_<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};
};
