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

struct Boolean
{
/*
	Not:
*/

	template<typename> struct Not;

	template<bool Value>
	struct Not<boolean<Value>>
	{
		using rtn = boolean<!Value>;
	};

/*
	And:
*/

	template<typename, typename...> struct And;

	template<bool Value>
	struct And<constant<bool, Value>>
	{
		using rtn = boolean<Value>;
	};

	template<typename Exp, typename... Exps>
	struct And<boolean<false>, Exp, Exps...>
	{
		using rtn = boolean<false>;
	};

	template<typename Exp, typename... Exps>
	struct And<boolean<true>, Exp, Exps...>
	{
		using rtn = typename And<Exp, Exps...>::rtn;
	};

	template<typename Exp, typename... Exps>
	struct And<act<Exp>, Exps...>
	{
		using rtn = typename And<typename Exp::rtn, Exps...>::rtn;
	};

/*
	Or:
*/

	template<typename, typename...> struct Or;

	template<bool Value>
	struct Or<constant<bool, Value>>
	{
		using rtn = boolean<Value>;
	};

	template<typename Exp, typename... Exps>
	struct Or<boolean<true>, Exp, Exps...>
	{
		using rtn = boolean<true>;
	};

	template<typename Exp, typename... Exps>
	struct Or<boolean<false>, Exp, Exps...>
	{
		using rtn = typename Or<Exp, Exps...>::rtn;
	};

	template<typename Exp, typename... Exps>
	struct Or<act<Exp>, Exps...>
	{
		using rtn = typename Or<typename Exp::rtn, Exps...>::rtn;
	};
};

