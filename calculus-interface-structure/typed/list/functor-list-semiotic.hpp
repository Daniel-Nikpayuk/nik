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

/*
	cons:
*/

	template<typename, typename> struct cons;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct cons<Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	typed_cons:
*/

	template<typename Type, Type, typename> struct typed_cons;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cons<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	car:
*/

	template<typename> struct car;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct car<ListType<Value, Values...>>
	{
		using rtn = Value;
	};

/*
	typed_car:
*/

	template<typename Type, typename> struct typed_car;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_car<Type, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

/*
	cdr:
*/

	template<typename> struct cdr;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct cdr<ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

/*
	typed_cdr:
*/

	template<typename Type, typename> struct typed_cdr;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cdr<Type, ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

/*
	catenate:
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename... Values1, typename... Values2, typename Values3, typename... Lists, template<typename...> class ListType>
	struct catenate<ListType<Values1...>, ListType<Values2...>, ListType<Values3...>, Lists...>
	{
		using rtn = typename catenate
		<
			ListType<Values1..., Values2...>,
			ListType<Values3...>,

			Lists...

		>::rtn;
	};

/*
	typed_catenate:
*/

	template<typename Type, typename, typename, typename...> struct typed_catenate;

	template<typename Type, Type... Values1, Type... Values2, template<Type...> class ListType>
	struct typed_catenate<Type, ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Type, Type... Values1, Type... Values2, Type... Values3, typename... Lists, template<Type...> class ListType>
	struct typed_catenate<Type, ListType<Values1...>, ListType<Values2...>, ListType<Values3...>, Lists...>
	{
		using rtn = typename typed_catenate
		<
			Type,
			ListType<Values1..., Values2...>,
			ListType<Values3...>,

			Lists...

		>::rtn;
	};

/*
	push:
*/

	template<typename, typename> struct push;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct push<Value, ListType<Values...>>
	{
		using rtn = ListType<Values..., Value>;
	};

/*
	typed_push:
*/

	template<typename Type, Type, typename> struct typed_push;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_push<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Values..., Value>;
	};

/*
	at:
*/

	template<size_type, typename> struct at;

	template<size_type index, typename Value, typename... Values, template<typename...> class ListType>
	struct at<index, ListType<Value, Values...>>
	{
		using rtn = typename at<index-1, ListType<Values...>>::rtn;
	};

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct at<0, ListType<Value, Values...>>
	{
		using rtn = Value;
	};

/*
	typed_at:
*/

	template<typename Type, size_type, typename> struct typed_at;

	template<typename Type, size_type index, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_at<Type, index, ListType<Value, Values...>>
	{
		static constexpr Type value = typed_at<Type, index-1, ListType<Values...>>::value;
	};

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_at<Type, 0, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

/*
	length:
*/

	template<typename, size_type = 0> struct length;

	template<typename Value, typename... Values, size_type count, template<typename...> class ListType>
	struct length<ListType<Value, Values...>, count>
	{
		static constexpr size_type value = length<ListType<Values...>, count+1>::value;
	};

	template<size_type count, template<typename...> class ListType>
	struct length<ListType<>, count>
	{
		static constexpr size_type value = count;
	};

/*
	typed_length:
*/

	template<typename Type, typename, size_type = 0> struct typed_length;

	template<typename Type, Type Value, Type... Values, size_type count, template<Type...> class ListType>
	struct typed_length<Type, ListType<Value, Values...>, count>
	{
		static constexpr size_type value = typed_length<Type, ListType<Values...>, count+1>::value;
	};

	template<typename Type, size_type count, template<Type...> class ListType>
	struct typed_length<Type, ListType<>, count>
	{
		static constexpr size_type value = count;
	};

