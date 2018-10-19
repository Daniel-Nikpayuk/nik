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

struct functor
{
	using kind						= module;

	using type						= functor;

	#include nik_typedef(calculus, builtin, op, module)
	#include nik_typedef(calculus, builtin, op, structure)

	template<typename...> struct apply;

/*
	Arithmetic operators

	+ (addition)
	- (subtraction)
	* (multiplication)
	/ (division)
	% (modulus)
*/

/*
	template<typename Type, Type Value1, Type Value2, template<Type...> class constant>
	struct apply
	<
		op<'+'>,

		constant<Value1>,
		constant<Value2>
	>
	{
		using rtn = constant<(Value1 + Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'-'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 - Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'*'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 * Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'/'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 / Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'%'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 % Value2)>;
	};
*/

/*
	Bitwise operators

	^ (XOR)
	| (OR)
	& (AND)
	~ (complement)
	<< (shift left, insertion to stream)
	>> (shift right, extraction from stream)
*/

/*
	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'^'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 ^ Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'|'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 | Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'&'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 & Value2)>;
	};

	template<typename Type, Type Value>
	struct apply
	<
		op<'~'>,

		constant<Type, Value>
	>
	{
		using rtn = constant<Type, (~ Value)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'<', '<'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 << Value2)>;
	};

	template<typename Type, Type Value1, Type Value2>
	struct apply
	<
		op<'>', '>'>,

		constant<Type, Value1>,
		constant<Type, Value2>
	>
	{
		using rtn = constant<Type, (Value1 >> Value2)>;
	};
*/

/*
	Relational operators

	== (equality)
	!= (inequality)
	> (greater-than)
	< (less-than)
	>= (greater-than-or-equal-to)
	<= (less-than-or-equal-to)
*/

/*
	template<bool Value1, bool Value2>
	struct apply
	<
		op<'=', '='>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 == Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'!', '='>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 != Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'>'>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 > Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'<'>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 < Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'>', '='>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 >= Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'<', '='>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 <= Value2)>;
	};
*/

/*
	Logical operators

	! (NOT)
	&& (AND)
	|| (OR)
*/

/*
	template<bool Value>
	struct apply
	<
		op<'!'>,

		constant<bool, Value>
	>
	{
		using rtn = constant<bool, (! Value)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'&', '&'>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 && Value2)>;
	};

	template<bool Value1, bool Value2>
	struct apply
	<
		op<'|', '|'>,

		constant<bool, Value1>,
		constant<bool, Value2>
	>
	{
		using rtn = constant<bool, (Value1 || Value2)>;
	};
*/

/*
	Increment and decrement operators

	++ (increment)
	-- (decrement)
*/

/*
	template<typename Type, Type Value>
	struct apply
	<
		op<'+', '+'>,

		constant<Type, Value>
	>
	{
		using rtn = constant<Type, (++ Value)>;
	};

	template<typename Type, Type Value>
	struct apply
	<
		op<'-', '-'>,

		constant<Type, Value>
	>
	{
		using rtn = constant<Type, (-- Value)>;
	};
*/

/*
	with act:
*/

/*
	template<typename Op, typename Exp>
	struct apply
	<
		Op,

		act<Exp>
	>
	{
		using rtn = typename apply
		<
			Op,

			typename Exp::rtn

		>::rtn;
	};

	template<typename Op, typename Type, Type Value, typename Exp>
	struct apply
	<
		Op,

		constant<Type, Value>,
		act<Exp>
	>
	{
		using rtn = typename apply
		<
			Op,

			constant<Type, Value>,
			typename Exp::rtn

		>::rtn;
	};

	template<typename Op, typename Exp, typename Type, Type Value>
	struct apply
	<
		Op,

		act<Exp>,
		constant<Type, Value>
	>
	{
		using rtn = typename apply
		<
			Op,

			typename Exp::rtn,
			constant<Type, Value>

		>::rtn;
	};

	template<typename Op, typename Exp1, typename Exp2>
	struct apply
	<
		Op,

		act<Exp1>,
		act<Exp2>
	>
	{
		using rtn = typename apply
		<
			Op,

			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Op, typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct apply
	<
		Op,

		Exp1,
		Exp2,
		Exp3,
		Exps...
	>
	{
		using rtn = typename apply
		<
			Op,

			typename apply<Op, Exp1, Exp2>::rtn,
			Exp3,
			Exps...

		>::rtn;
	};
*/
};

