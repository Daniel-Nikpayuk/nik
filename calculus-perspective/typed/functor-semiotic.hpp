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
	using kind		= branch;

	using type		= functor;

/*
	cons:
*/

	template<typename Type, Type, typename> struct cons;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct cons<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	car:
*/

	template<typename Type, typename> struct car;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct car<Type, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

/*
	cdr:
*/

	template<typename Type, typename> struct cdr;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct cdr<Type, ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};
};

