/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#include nik_typedef(symbolic, calculus, list, structure)
	#include nik_typedef(symbolic, calculus, list, functor)

	#include nik_typedef(symbolic, lift, operate, structure)

/***********************************************************************************************************************/

/*
	length:
*/

				  template<typename List>
	using length		= builtin_length<register_type, List>;

/*
	cons:
*/

				  template<register_type Value, typename List>
	using cons		= builtin_cons<register_type, Value, List>;

/*
	push:
*/

				  template<register_type Value, typename List>
	using push		= builtin_push<register_type, Value, List>;

/*
	car:
*/

				  template<typename List, size_type index = 0>
	using car		= builtin_multicar<register_type, List, index>;

/*
	cdr:
*/

				  template<typename List, size_type index = 0>
	using cdr		= builtin_multicdr<register_type, List, index>;

/***********************************************************************************************************************/

/*
	#_apply:

	Relational operators require returing a bool value instead of their given Type.
*/

	template<typename, char>						struct char_unary;
	template<typename, char...>						struct char_binary;

	#define declare_single_char_unary(op_char, op_name)							\
														\
	template<typename Char>											\
	struct char_unary<Char, op_char>									\
	{													\
		template<typename Type>										\
		static constexpr Type value(const Type Value)							\
		{												\
			return (op_name Value);									\
		}												\
	};

	#define declare_single_char_binary(return_type, op_char, op_name)					\
														\
	template<typename Char>											\
	struct char_binary<Char, op_char>									\
	{													\
		template<typename Type>										\
		static constexpr return_type value(const Type Value1, const Type Value2)			\
		{												\
			return (Value1 op_name Value2);								\
		}												\
	};

	#define declare_double_char_binary(return_type, op_char1, op_char2, op_name)				\
														\
	template<typename Char>											\
	struct char_binary<Char, op_char1, op_char2>								\
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

/*
	unary:
*/

	template<typename Operator>
	using unary = char_unary
	<
		char, car<Operator>::value
	>;

/***********************************************************************************************************************/

/*
	binary:
*/

	struct ch_binary
	{
		template<typename Char, template<Char...> class ListType, typename List, size_type index, Char... Values>
		using result = char_binary<Char, Values...>;
	};

	template<typename Operator>
	using binary = typename pattern_match_builtin_list<char, Operator>::template push_front
	<
		ch_binary, filler, 0
	>;

/***********************************************************************************************************************/

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

};

