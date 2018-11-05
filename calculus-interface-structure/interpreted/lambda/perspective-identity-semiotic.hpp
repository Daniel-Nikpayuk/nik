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

	#include nik_typedef(calculus, interpreted, lambda, structure)

/*
	is_arguments:
*/

	template<typename Exp>
	struct is_arguments
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename... Exps>
		struct strict<arguments<Exps...>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_lambda:
*/

	template<typename Exp>
	struct is_lambda
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename Args, typename Body>
		struct strict<lambda<Args, Body>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	is_compound:
*/

	template<typename Exp>
	struct is_compound
	{
		template<typename Type>
		struct strict
		{
			using rtn = boolean<false>;
		};

		template<typename Args, typename Body, typename Env>
		struct strict<procedure<Args, Body, Env>>
		{
			using rtn = boolean<true>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};
};

