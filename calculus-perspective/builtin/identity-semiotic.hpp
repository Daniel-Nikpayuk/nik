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
	using kind	= branch;

	using type	= identity;

/*
	is_equal:
*/

	template<typename Type, Type Value1, Type Value2>
	struct is_equal
	{
		static constexpr bool value = false;
	};

	template<typename Type, Type Value>
	struct is_equal<Type, Value, Value>
	{
		static constexpr bool value = true;
	};

/*
	is list:
*/

	template<typename, typename>
	struct is_list
	{
		static constexpr bool value = false;
	};

	template<typename Type, Type... Exps, template<Type...> class ListType>
	struct is_list<Type, ListType<Exps...>>
	{
		static constexpr bool value = true;
	};

	template<typename Type, typename Exp>
	struct is_list<Type, act<Exp>>
	{
		static constexpr bool value = is_list<Type, typename Exp::rtn>::value;
	};

/*
	is_null:
*/

	template<typename, typename> struct is_null;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct is_null<Type, ListType<Exp, Exps...>>
	{
		static constexpr bool value = false;
	};

	template<typename Type, template<Type...> class ListType>
	struct is_null<Type, ListType<>>
	{
		static constexpr bool value = true;
	};

	template<typename Type, typename Exp>
	struct is_null<Type, act<Exp>>
	{
		static constexpr bool value = is_null<Type, typename Exp::rtn>::value;
	};
};

