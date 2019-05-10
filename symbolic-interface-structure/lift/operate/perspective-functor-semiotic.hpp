/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Narratively, the uses of cons<> in this implementation should be the typed recursive variety,
	but given the heavy use of apply in this library, it has been optimized to use the non-recursive
	variety instead.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(calculus, perspective, dispatched, functor)
	#include nik_typedef(calculus, perspective, typed, functor)

	#include nik_typedef(calculus, constant, operate, structure)
	#include nik_typedef(calculus, constant, operate, identity)

/***********************************************************************************************************************/

/*
	#_apply:

	Relational operators require returing a bool value instead of their given Type.
*/

	template<char, typename = void>			struct single_char_unary;
	template<char, typename = void>			struct single_char_binary;
	template<char, char, typename = void>		struct double_char_binary;

	#define declare_single_char_unary(op_char, op_name)							\
														\
	template<typename Filler>										\
	struct single_char_unary<op_char, Filler>								\
	{													\
		template<typename Type>										\
		static constexpr Type value(const Type Value)							\
		{												\
			return (op_name Value);									\
		}												\
	};

	#define declare_single_char_binary(return_type, op_char, op_name)					\
														\
	template<typename Filler>										\
	struct single_char_binary<op_char, Filler>								\
	{													\
		template<typename Type>										\
		static constexpr return_type value(const Type Value1, const Type Value2)			\
		{												\
			return (Value1 op_name Value2);								\
		}												\
	};

	#define declare_double_char_binary(return_type, op_char1, op_char2, op_name)				\
														\
	template<typename Filler>										\
	struct double_char_binary<op_char1, op_char2, Filler>							\
	{													\
		template<typename Type>										\
		static constexpr return_type value(const Type Value1, const Type Value2)			\
		{												\
			return (Value1 op_name Value2);								\
		}												\
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

	declare_single_char_unary('+', +)
	declare_single_char_unary('-', -)

	declare_single_char_binary(Type, '+', +)
	declare_single_char_binary(Type, '-', -)
	declare_single_char_binary(Type, '*', *)
	declare_single_char_binary(Type, '/', /)
	declare_single_char_binary(Type, '%', %)

/*
	Bitwise operators

	^ (XOR)
	| (OR)
	& (AND)
	~ (complement)
	<< (shift left, insertion to stream)
	>> (shift right, extraction from stream)
*/

	declare_single_char_unary('~', ~)

	declare_single_char_binary(Type, '^', ^)
	declare_single_char_binary(Type, '|', |)
	declare_single_char_binary(Type, '&', &)
	declare_double_char_binary(Type, '<', '<', <<)
	declare_double_char_binary(Type, '>', '>', >>)

/*
	Relational operators

	== (equality)
	!= (inequality)
	> (greater-than)
	< (less-than)
	>= (greater-than-or-equal-to)
	<= (less-than-or-equal-to)
*/

	declare_double_char_binary(bool, '=', '=', ==)
	declare_double_char_binary(bool, '!', '=', !=)
	declare_single_char_binary(bool, '>', >)
	declare_single_char_binary(bool, '<', <)
	declare_double_char_binary(bool, '>', '=', >=)
	declare_double_char_binary(bool, '<', '=', <=)

/*
	Logical operators

	! (NOT)
	&& (AND)
	|| (OR)
*/

	declare_single_char_unary('!', !)

	declare_double_char_binary(Type, '&', '&', &&)
	declare_double_char_binary(Type, '|', '|', ||)

/***********************************************************************************************************************/

	#undef declare_single_char_unary
	#undef declare_single_char_binary
	#undef declare_double_char_binary

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// memoized_operator:

	template<typename> struct memoized_operator;

	template<char op_char, template<char...> class op_list>
	struct memoized_operator<op_list<op_char>>
	{
		using unary = single_char_unary<op_char>;

		using binary = single_char_binary<op_char>;
	};

	template<char op_char1, char op_char2, template<char...> class op_list>
	struct memoized_operator<op_list<op_char1, op_char2>>
	{
		using binary = double_char_binary<op_char1, op_char2>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<register_type... Values>
	inline static void display(const operate<Values...> & o)
	{
		static constexpr bool is_empty = is_null<operate<Values...>>::value;

		Dispatched::functor::display("operate: ");

		if (is_empty)	Dispatched::functor::display(" null");
		else		Passive::functor::display(register_type(), o, "");
	}
};

