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
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, perspective, typed, functor)

/*
	apply##:

	The postfix numerals are the arities of char, Type, respectively.

	Relational operators require returing a bool value instead of their given Type.
*/

	template<typename Type, char, Type>			struct apply11;
	template<typename Type, char, char, Type>		struct apply21;
	template<typename Type, char, Type, Type>		struct apply12;
	template<typename Type, char, char, Type, Type>		struct apply22;

#define declare_apply11(op_char, op_name)										\
															\
	template<typename Type, Type Value>										\
	struct apply11<Type, op_char, Value>										\
	{														\
		static constexpr Type value = (op_name Value);								\
	};

#define declare_apply21(op1_char, op2_char, op_name)									\
															\
	template<typename Type, Type Value>										\
	struct apply21<Type, op1_char, op2_char, Value>									\
	{														\
		static constexpr Type value = (op_name Value);								\
	};

#define declare_apply12(op_char, op_name)										\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply12<Type, op_char, Value1, Value2>									\
	{														\
		static constexpr Type value = (Value1 op_name Value2);							\
	};

#define declare_apply22(op1_char, op2_char, op_name)									\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply22<Type, op1_char, op2_char, Value1, Value2>							\
	{														\
		static constexpr Type value = (Value1 op_name Value2);							\
	};

#define declare_apply12b(op_char, op_name)										\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply12<Type, op_char, Value1, Value2>									\
	{														\
		static constexpr bool value = (Value1 op_name Value2);							\
	};

#define declare_apply22b(op1_char, op2_char, op_name)									\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply22<Type, op1_char, op2_char, Value1, Value2>							\
	{														\
		static constexpr bool value = (Value1 op_name Value2);							\
	};

/***********************************************************************************************************************/

/*
	Operator reference: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
*/

/*
	Arithmetic operators

	+ (addition)
	- (subtraction)
	* (multiplication)
	/ (division)
	% (modulus)
*/

	declare_apply12('+', +)
	declare_apply12('-', -)
	declare_apply12('*', *)
	declare_apply12('/', /)
	declare_apply12('%', %)

/*
	Bitwise operators

	^ (XOR)
	| (OR)
	& (AND)
	~ (complement)
	<< (shift left, insertion to stream)
	>> (shift right, extraction from stream)
*/

	declare_apply12('^', ^)
	declare_apply12('|', |)
	declare_apply12('&', &)
	declare_apply11('~', ~)
	declare_apply22('<', '<', <<)
	declare_apply22('>', '>', >>)

/*
	Relational operators

	== (equality)
	!= (inequality)
	> (greater-than)
	< (less-than)
	>= (greater-than-or-equal-to)
	<= (less-than-or-equal-to)
*/

	declare_apply22b('=', '=', ==)
	declare_apply22b('!', '=', !=)
	declare_apply12b('>', >)
	declare_apply12b('<', <)
	declare_apply22b('>', '=', >=)
	declare_apply22b('<', '=', <=)

/*
	Logical operators

	! (NOT)
	&& (AND)
	|| (OR)
*/

	declare_apply11('!', !)
	declare_apply22('&', '&', &&)
	declare_apply22('|', '|', ||)

/***********************************************************************************************************************/

#undef declare_apply11
#undef declare_apply21
#undef declare_apply12
#undef declare_apply22
#undef declare_apply12b
#undef declare_apply22b

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	apply:
*/

	template<typename Type, typename...> struct apply;

/*
	apply11:
*/

	template
	<
		typename Type,
		char op_char,
		Type Value1, Type Value2, Type... Values,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op_char>,

		number_list<Value1, Value2, Values...>
	>
	{
		using rtn = typename cons
		<
			Type,
			apply11<Type, op_char, Value1>::value,

			typename apply
			<
				Type,
				op_list<op_char>,

				number_list<Value2, Values...>

			>::rtn

		>::rtn;
	};

	template
	<
		typename Type,
		char op_char,
		Type Value,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op_char>,

		number_list<Value>
	>
	{
		using rtn = number_list
		<
			apply11<Type, op_char, Value>::value
		>;
	};

	template
	<
		typename Type,
		char op_char,
		typename NumList1, typename NumList2, typename... NumLists,
		template<char...> class op_list
	>
	struct apply
	<
		Type,
		op_list<op_char>,
		NumList1, NumList2, NumLists...
	>
	{
		using rtn = typename apply
		<
			Type,
			op_list<op_char>,
			typename apply<Type, op_list<op_char>, NumList1>::rtn,
			NumList2, NumLists...

		>::rtn;
	};

/*
	apply12:
*/

	template
	<
		typename Type,
		char op_char,
		Type Value11, Type Value12, Type... Values1,
		Type Value21, Type Value22, Type... Values2,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op_char>,

		number_list<Value11, Value12, Values1...>,
		number_list<Value21, Value22, Values2...>
	>
	{
		using rtn = typename cons
		<
			Type,
			apply12<Type, op_char, Value11, Value21>::value,

			typename apply
			<
				Type,
				op_list<op_char>,

				number_list<Value12, Values1...>,
				number_list<Value22, Values2...>

			>::rtn

		>::rtn;
	};

	template
	<
		typename Type,
		char op_char,
		Type Value1, Type Value2,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op_char>,

		number_list<Value1>,
		number_list<Value2>
	>
	{
		using rtn = number_list
		<
			apply12<Type, op_char, Value1, Value2>::value
		>;
	};

/*
	apply21:
*/

	template
	<
		typename Type,
		char op1_char, char op2_char,
		Type Value1, Type Value2, Type... Values,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op1_char, op2_char>,

		number_list<Value1, Value2, Values...>
	>
	{
		using rtn = typename cons
		<
			Type,
			apply21<Type, op1_char, op2_char, Value1>::value,

			typename apply
			<
				Type,
				op_list<op1_char, op2_char>,

				number_list<Value2, Values...>

			>::rtn

		>::rtn;
	};

	template
	<
		typename Type,
		char op1_char, char op2_char,
		Type Value,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op1_char, op2_char>,

		number_list<Value>
	>
	{
		using rtn = number_list
		<
			apply21<Type, op1_char, op2_char, Value>::value
		>;
	};

	template
	<
		typename Type,
		char op1_char, char op2_char,
		typename NumList1, typename NumList2, typename... NumLists,
		template<char...> class op_list
	>
	struct apply
	<
		Type,
		op_list<op1_char, op2_char>,
		NumList1, NumList2, NumLists...
	>
	{
		using rtn = typename apply
		<
			Type,
			op_list<op1_char, op2_char>,
			typename apply<Type, op_list<op1_char, op2_char>, NumList1>::rtn,
			NumList2, NumLists...

		>::rtn;
	};

	// multiple is implemented in apply22.

/*
	apply22:
*/

	template
	<
		typename Type,
		char op1_char, char op2_char,
		Type Value11, Type Value12, Type... Values1,
		Type Value21, Type Value22, Type... Values2,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op1_char, op2_char>,

		number_list<Value11, Value12, Values1...>,
		number_list<Value21, Value22, Values2...>
	>
	{
		using rtn = typename cons
		<
			Type,
			apply22<Type, op1_char, op2_char, Value11, Value21>::value,

			typename apply
			<
				Type,
				op_list<op1_char, op2_char>,

				number_list<Value12, Values1...>,
				number_list<Value22, Values2...>

			>::rtn

		>::rtn;
	};

	template
	<
		typename Type,
		char op1_char, char op2_char,
		Type Value1, Type Value2,
		template<char...> class op_list,
		template<Type...> class number_list
	>
	struct apply
	<
		Type,
		op_list<op1_char, op2_char>,

		number_list<Value1>,
		number_list<Value2>
	>
	{
		using rtn = number_list
		<
			apply22<Type, op1_char, op2_char, Value1, Value2>::value
		>;
	};

	template
	<
		typename Type,
		typename Op,
		typename NumList1, typename NumList2, typename NumList3, typename... NumLists
	>
	struct apply
	<
		Type,
		Op, NumList1, NumList2, NumList3, NumLists...
	>
	{
		using rtn = typename apply
		<
			Type,
			Op,
			typename apply<Type, Op, NumList1, NumList2>::rtn,
			NumList3, NumLists...

		>::rtn;
	};
};

