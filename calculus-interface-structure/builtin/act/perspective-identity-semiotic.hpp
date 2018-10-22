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
	using kind		= branch;

	using type		= identity;

	#define safe_name

		#include nik_typedef(calculus, perspective, builtin, identity)

	#undef safe_name

	#include nik_typedef(calculus, builtin, act, structure)

/*
	is_equal:
*/

	template<typename, typename> struct is_equal;

	template<typename Type, typename Exp>
	struct is_equal<Type, act<Exp>>
	{
		static constexpr bool value = perbui_is_equal<Type, typename Exp::rtn>::value;
	};

	template<typename Exp, typename Type>
	struct is_equal<act<Exp>, Type>
	{
		static constexpr bool value = perbui_is_equal<typename Exp::rtn, Type>::value;
	};

	template<typename Exp1, typename Exp2>
	struct is_equal<act<Exp1>, act<Exp2>>
	{
		static constexpr bool value = perbui_is_equal<typename Exp1::rtn, typename Exp2::rtn>::value;
	};

/*
	is list:
*/

	template<typename, typename...> struct is_list;

	template<typename Exp>
	struct is_list<act<Exp>>
	{
		static constexpr bool value = perbui_is_list<typename Exp::rtn>::value;
	};

	template<typename Type, typename Exp>
	struct is_list<Type, act<Exp>>
	{
		static constexpr bool value = perbui_is_list<Type, typename Exp::rtn>::value;
	};

/*
	is_null:
*/

	template<typename, typename...> struct is_null;

	template<typename Exp>
	struct is_null<act<Exp>>
	{
		static constexpr bool value = perbui_is_null<typename Exp::rtn>::value;
	};

	template<typename Type, typename Exp>
	struct is_null<Type, act<Exp>>
	{
		static constexpr bool value = perbui_is_null<Type, typename Exp::rtn>::value;
	};
};

