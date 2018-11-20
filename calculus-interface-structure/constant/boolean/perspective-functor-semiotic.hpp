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

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(calculus, dispatched, active, functor)
		#include nik_typedef(calculus, typed, passive, functor)
		#include nik_typedef(calculus, constant, operate, functor)

	#undef safe_name

	#include nik_typedef(calculus, constant, boolean, structure)
	#include nik_typedef(calculus, constant, boolean, identity)

/*
	cons:
*/

				  template<register_type Value, typename Exp>
	using cons		= typpaf_cons<register_type, Value, Exp>;

/*
	car:
*/

				  template<typename Exp, size_type index = 0>
	using car		= typpaf_car<register_type, Exp, index>;

/*
	cdr:
*/

				  template<typename Exp, size_type index = 0>
	using cdr		= typpaf_cdr<register_type, Exp, index>;

/*
	catenate:
*/

				  template<typename Exp1, typename Exp2, typename... Exps>
	using catenate		= typpaf_catenate<register_type, Exp1, Exp2, Exps...>;

/*
	push:
*/

				  template<register_type Value, typename Exp>
	using push		= typpaf_push<register_type, Value, Exp>;

/*
	length:
*/

				  template<typename Exp>
	using length		= typpaf_length<register_type, Exp>;

/*
	apply:

	Redefined for short-circuit optimization.
*/

	template<typename... Exps>
	struct apply
	{
		using rtn = typename conopf_apply<register_type, Exps...>::rtn;
	};

	template<bool Value>
	struct apply<operate<'|', '|'>, boolean<Value>>
	{
		using rtn = boolean<Value>;
	};

	template<bool Value, typename Boolean, typename... Booleans>
	struct apply
	<
		operate<'|', '|'>,
		boolean<Value>, Boolean, Booleans...
	>
	{
		using rtn = typename disacf_if_then_else
		<
			Value,

			boolean<true>,

			apply
			<
				operate<'|', '|'>,
				Boolean, Booleans...
			>

		>::rtn;
	};

	template<bool Value>
	struct apply<operate<'&', '&'>, boolean<Value>>
	{
		using rtn = boolean<Value>;
	};

	template<bool Value, typename Boolean, typename... Booleans>
	struct apply
	<
		operate<'&', '&'>,
		boolean<Value>, Boolean, Booleans...
	>
	{
		using rtn = typename disacf_if_then_else
		<
			Value,

			apply
			<
				operate<'&', '&'>,
				Boolean, Booleans...
			>,

			boolean<false>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	struct markup
	{
		static constexpr const char *label	= "boolean";
		static constexpr const char *before	= ": ";
		static constexpr const char *front	= "";
		static constexpr const char *back	= "";
		static constexpr const char *after	= "";
	};

	template<register_type... Values>
	inline static void display(const boolean<Values...> & b)
	{
		static constexpr bool is_empty = is_null<boolean<Values...>>::value;

		Dispatched::functor::display("boolean:");

		if (is_empty)	Dispatched::functor::display(" null");
		else		Passive::functor::display(register_type(), b);
	}
};

