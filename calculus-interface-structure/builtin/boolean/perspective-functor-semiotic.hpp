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
	using kind					= module;

	using type					= functor;

	#define safe_name

		#include nik_lensdef(calculus, perspective, functor, semiotic)

	#undef safe_name

	#include nik_typedef(calculus, builtin, boolean, structure)

/*
	cons:
*/

	template<register_type, typename> struct cons;

	template<register_type Exp, register_type... Exps, template<register_type...> class ListType>
	struct cons<Exp, ListType<Exps...>>
	{
		using rtn = ListType<Exp, Exps...>;
	};

	template<register_type Exp1, typename Exp2>
	struct cons<Exp1, act<Exp2>>
	{
		using rtn = typename cons<Exp1, typename Exp2::rtn>::rtn;
	};

/*
	apply:
*/

	template<typename...> struct apply;

/*
	apply11:
*/

	template
	<
		char op_char,
		register_type Value1, register_type Value2, register_type... Values
	>
	struct apply
	<
		op<op_char>,

		integer32<Value1, Value2, Values...>
	>
	{
		using rtn = typename cons
		<
			calpef_apply11<op_char, register_type, Value1>::value,

			act
			<
				apply
				<
					op<op_char>,

					integer32<Value2, Values...>
				>
			>

		>::rtn;
	};

	template<char op_char, register_type Value>
	struct apply
	<
		op<op_char>,

		integer32<Value>
	>
	{
		using rtn = integer32<calpef_apply11<op_char, register_type, Value>::value>;
	};


/*
	display:
*/

	template<bool Value>
	inline static void display(const boolean<Value> &)
	{
		printf("%s", "boolean: ");
		printf("%s", Value ? "true" : "false");
	}
};

