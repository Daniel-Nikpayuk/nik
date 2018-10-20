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
	Operator reference: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
*/


/*
	apply:

	The postfix numerals are the arities of char, Type, respectively.
*/

	template<char, typename Type, Type>			struct apply11;
	template<char, typename Type, Type, Type>		struct apply12;
	template<char, char, typename Type, Type>		struct apply21;
	template<char, char, typename Type, Type, Type>		struct apply22;

#define declare_apply11(op_char, op_name)										\
															\
	template<typename Type, Type Value>										\
	struct apply11<op_char, Type, Value>										\
	{														\
		static constexpr Type value = (op_name Value);								\
	};

#define declare_apply12(op_char, op_name)										\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply12<op_char, Type, Value1, Value2>									\
	{														\
		static constexpr Type value = (Value1 op_name Value2);							\
	};

#define declare_apply21(op1_char, op2_char, op_name)									\
															\
	template<typename Type, Type Value>										\
	struct apply21<op1_char, op2_char, Type, Value>									\
	{														\
		static constexpr Type value = (op_name Value);								\
	};

#define declare_apply22(op1_char, op2_char, op_name)									\
															\
	template<typename Type, Type Value1, Type Value2>								\
	struct apply22<op1_char, op2_char, Type, Value1, Value2>							\
	{														\
		static constexpr Type value = (Value1 op_name Value2);							\
	};

/***********************************************************************************************************************/

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

	declare_apply22('=', '=', ==)
	declare_apply22('!', '=', !=)
	declare_apply12('>', >)
	declare_apply12('<', <)
	declare_apply22('>', '=', >=)
	declare_apply22('<', '=', <=)

/*
	Increment and decrement operators

	++ (increment)
	-- (decrement)
*/

	declare_apply21('+', '+', ++)
	declare_apply21('-', '-', --)

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
#undef declare_apply12
#undef declare_apply21
#undef declare_apply22

/***********************************************************************************************************************/
/***********************************************************************************************************************/

template<typename...> struct apply;

/*
	apply11:
*/

	template
	<
		typename register_type,
		char op_char,
		register_type Value1, register_type Value2, register_type... Values,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op_char>,

		number_list<Value1, Value2, Values...>
	>
	{
		using rtn = typename builtin_cons
		<
			register_type,
			apply11<op_char, register_type, Value1>::value,

			act
			<
				apply
				<
					register_type,
					op_list<op_char>,

					number_list<Value2, Values...>
				>
			>

		>::rtn;
	};

	template
	<
		typename register_type,
		char op_char,
		register_type Value,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op_char>,

		number_list<Value>
	>
	{
		using rtn = number_list
		<
			apply11<op_char, register_type, Value>::value
		>;
	};

/*
	apply12:
*/

	template
	<
		typename register_type,
		char op_char,
		register_type Value11, register_type Value12, register_type... Values1,
		register_type Value21, register_type Value22, register_type... Values2,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op_char>,

		number_list<Value11, Value12, Values1...>,
		number_list<Value21, Value22, Values2...>
	>
	{
		using rtn = typename builtin_cons
		<
			register_type,
			apply12<op_char, register_type, Value11, Value21>::value,

			act
			<
				apply
				<
					register_type,
					op_list<op_char>,

					number_list<Value12, Values1...>,
					number_list<Value22, Values2...>
				>
			>

		>::rtn;
	};

	template
	<
		typename register_type,
		char op_char,
		register_type Value1, register_type Value2,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op_char>,

		number_list<Value1>,
		number_list<Value2>
	>
	{
		using rtn = number_list
		<
			apply12<op_char, register_type, Value1, Value2>::value
		>;
	};

/*
	apply21:
*/

	template
	<
		typename register_type,
		char op1_char, char op2_char,
		register_type Value1, register_type Value2, register_type... Values,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op1_char, op2_char>,

		number_list<Value1, Value2, Values...>
	>
	{
		using rtn = typename builtin_cons
		<
			register_type,
			apply21<op1_char, op2_char, register_type, Value1>::value,

			act
			<
				apply
				<
					register_type,
					op_list<op1_char, op2_char>,

					number_list<Value2, Values...>
				>
			>

		>::rtn;
	};

	template
	<
		typename register_type,
		char op1_char, char op2_char,
		register_type Value,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op1_char, op2_char>,

		number_list<Value>
	>
	{
		using rtn = number_list
		<
			apply21<op1_char, op2_char, register_type, Value>::value
		>;
	};

/*
	apply22:
*/

	template
	<
		typename register_type,
		char op1_char, char op2_char,
		register_type Value11, register_type Value12, register_type... Values1,
		register_type Value21, register_type Value22, register_type... Values2,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op1_char, op2_char>,

		number_list<Value11, Value12, Values1...>,
		number_list<Value21, Value22, Values2...>
	>
	{
		using rtn = typename builtin_cons
		<
			register_type,
			apply22<op1_char, op2_char, register_type, Value11, Value21>::value,

			act
			<
				apply
				<
					register_type,
					op_list<op1_char, op2_char>,

					number_list<Value12, Values1...>,
					number_list<Value22, Values2...>
				>
			>

		>::rtn;
	};

	template
	<
		typename register_type,
		char op1_char, char op2_char,
		register_type Value1, register_type Value2,
		template<char...> class op_list,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		op_list<op1_char, op2_char>,

		number_list<Value1>,
		number_list<Value2>
	>
	{
		using rtn = number_list
		<
			apply22<op1_char, op2_char, register_type, Value1, Value2>::value
		>;
	};

/*
	with act:
*/

	template
	<
		typename register_type,
		typename Op,
		typename Exp
	>
	struct apply
	<
		register_type,
		Op,
		act<Exp>
	>
	{
		using rtn = typename apply
		<
			register_type,
			Op,
			typename Exp::rtn

		>::rtn;
	};

	template
	<
		typename register_type,
		typename Op,
		register_type Value,
		typename Exp,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		Op,
		number_list<Value>,
		act<Exp>
	>
	{
		using rtn = typename apply
		<
			register_type,
			Op,
			number_list<Value>,
			typename Exp::rtn

		>::rtn;
	};

	template
	<
		typename register_type,
		typename Op, typename Exp,
		register_type Value,
		template<register_type...> class number_list
	>
	struct apply
	<
		register_type,
		Op,
		act<Exp>,
		number_list<Value>
	>
	{
		using rtn = typename apply
		<
			register_type,
			Op,
			typename Exp::rtn,
			number_list<Value>

		>::rtn;
	};

	template
	<
		typename register_type,
		typename Op, typename Exp1, typename Exp2
	>
	struct apply
	<
		register_type,
		Op, act<Exp1>, act<Exp2>
	>
	{
		using rtn = typename apply
		<
			register_type,
			Op,
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template
	<
		typename register_type,
		typename Op, typename Exp1, typename Exp2, typename Exp3, typename... Exps
	>
	struct apply
	<
		register_type,
		Op, Exp1, Exp2, Exp3, Exps...
	>
	{
		using rtn = typename apply
		<
			register_type,
			Op,
			typename apply<register_type, Op, Exp1, Exp2>::rtn,
			Exp3, Exps...

		>::rtn;
	};

