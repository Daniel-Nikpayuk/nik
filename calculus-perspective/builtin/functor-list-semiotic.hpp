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

	template<typename Type, Type, typename> struct cons;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct cons<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

	template<typename Type, Type Value, typename Exp>
	struct cons<Type, Value, act<Exp>>
	{
		using rtn = typename cons<Type, Value, typename Exp::rtn>::rtn;
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

	template<typename Type, typename Exp>
	struct car<Type, act<Exp>>
	{
		static constexpr Type value = car<Type, typename Exp::rtn>::value;
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

	template<typename Type, typename Exp>
	struct cdr<Type, act<Exp>>
	{
		using rtn = typename cdr<Type, typename Exp::rtn>::rtn;
	};

/*
	catenate:
*/

	template<typename Type, typename, typename, typename...> struct catenate;

	template<typename Type, Type... Values1, Type... Values2, template<Type...> class ListType>
	struct catenate<Type, ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Type, Type... Values, typename Exp, template<Type...> class ListType>
	struct catenate<Type, ListType<Values...>, act<Exp>>
	{
		using rtn = typename catenate
		<
			Type,
			ListType<Values...>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Type, typename Exp, Type... Values, template<Type...> class ListType>
	struct catenate<Type, act<Exp>, ListType<Values...>>
	{
		using rtn = typename catenate
		<
			Type,
			typename Exp::rtn,
			ListType<Values...>

		>::rtn;
	};

	template<typename Type, typename Exp1, typename Exp2>
	struct catenate<Type, act<Exp1>, act<Exp2>>
	{
		using rtn = typename catenate
		<
			Type,
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Type, typename List1, typename List2, typename List3, typename... Lists>
	struct catenate<Type, List1, List2, List3, Lists...>
	{
		using rtn = typename catenate
		<
			Type,

			act
			<
				catenate<Type, List1, List2>
			>,

			List3, Lists...

		>::rtn;
	};

/*
	push:
*/

	template<typename Type, Type, typename> struct push;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct push<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Values..., Value>;
	};

	template<typename Type, Type Value, typename Exp>
	struct push<Type, Value, act<Exp>>
	{
		using rtn = typename push<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	at:
*/

	template<typename Type, size_type, typename> struct at;

	template<typename Type, size_type index, Type Value, Type... Values, template<Type...> class ListType>
	struct at<Type, index, ListType<Value, Values...>>
	{
		static constexpr Type value = at<Type, index-1, ListType<Values...>>::value;
	};

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct at<Type, 0, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

	template<typename Type, size_type index, typename Exp>
	struct at<Type, index, act<Exp>>
	{
		static constexpr Type value = at<Type, index, typename Exp::rtn>::value;
	};

/*
	length:
*/

	template<typename Type, typename, size_type = 0> struct length;

	template<typename Type, Type Value, Type... Values, size_type count, template<Type...> class ListType>
	struct length<Type, ListType<Value, Values...>, count>
	{
		static constexpr size_type value = length<Type, ListType<Values...>, count+1>::value;
	};

	template<typename Type, size_type count, template<Type...> class ListType>
	struct length<Type, ListType<>, count>
	{
		static constexpr size_type value = count;
	};

	template<typename Type, typename Exp, size_type count>
	struct length<Type, act<Exp>, count>
	{
		static constexpr size_type value = length<Type, typename Exp::rtn, count>::value;
	};

