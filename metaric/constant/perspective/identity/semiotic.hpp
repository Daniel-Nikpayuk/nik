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
/*
	is equal:

	The implementation given here is in fact more powerful than identity applied to constants: It holds for all types.
*/

	template<typename Expression1, typename Expression2>
	struct is_equal
	{
		using rtn = boolean
		<
			Empty::identity::template is_equal<Expression1, Expression2>::value
		>;
	};

/*
	is constant:
*/

	template<typename>
	struct is_constant
	{
		using rtn = boolean<false>;
	};

	template<typename Type, Type... Value>
	struct is_constant<constant<Type, Value...>>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp>
	struct is_constant<act<Exp>>
	{
		using rtn = typename is_constant<typename Exp::rtn>::rtn;
	};
};

