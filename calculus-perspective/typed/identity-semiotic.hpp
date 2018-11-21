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

	using rtn		= identity;

/*
	is_list_type:
*/

	template<typename, typename>
	struct is_list_type
	{
		static constexpr bool value = false;
	};

	template<typename Type, Type... Exps, template<Type...> class ListType>
	struct is_list_type<Type, ListType<Exps...>>
	{
		static constexpr bool value = true;
	};

/*
	is_null:
*/

	template<typename, typename>
	struct is_null
	{
		static constexpr bool value = false;
	};

	template<typename Type, template<Type...> class ListType>
	struct is_null<Type, ListType<>>
	{
		static constexpr bool value = true;
	};

/*
	is_:
*/

	template<typename Type, template<Type...> class label>
	struct memoized_is_
	{
		template<typename Exp>
		struct type
		{
			static constexpr bool value = false;
		};

		template<Type... Exps>
		struct type<label<Exps...>>
		{
			static constexpr bool value = true;
		};
	};

	template<typename Type, typename Exp, template<Type...> class label>
	static constexpr bool is_ = memoized_is_<Type, label>::template type<Exp>;
};

