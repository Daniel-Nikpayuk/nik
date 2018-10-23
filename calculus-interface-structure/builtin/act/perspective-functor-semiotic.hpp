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
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, builtin, functor)

	#undef safe_name

	#include nik_typedef(calculus, builtin, act, structure)

/*
	dereference:
*/

	template<typename> struct dereference;

	template<typename Exp>
	struct dereference<act<Exp>>
	{
		using rtn = typename perbuf_dereference<typename Exp::rtn>::rtn;
	};

/*
	if_then_else:
*/

	template<bool, typename, typename> struct if_then_else;

	template<typename Ante, typename Exp>
	struct if_then_else<false, Ante, act<Exp>>
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Exp, typename Conse>
	struct if_then_else<true, act<Exp>, Conse>
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct if_then_else<false, act<Exp1>, act<Exp2>>
	{
		using rtn = typename Exp2::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct if_then_else<true, act<Exp1>, act<Exp2>>
	{
		using rtn = typename Exp1::rtn;
	};

/*
	untyped_cons:
*/

	template<typename, typename> struct untyped_cons;

	template<typename Value, typename Exp>
	struct untyped_cons<Value, act<Exp>>
	{
		using rtn = typename perbuf_untyped_cons<Value, typename Exp::rtn>::rtn;
	};

	template<typename Exp, typename Value>
	struct untyped_cons<act<Exp>, Value>
	{
		using rtn = typename perbuf_untyped_cons<typename Exp::rtn, Value>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct untyped_cons<act<Exp1>, act<Exp2>>
	{
		using rtn = typename perbuf_untyped_cons<typename Exp1::rtn, typename Exp2::rtn>::rtn;
	};

/*
	typed_cons:
*/

	template<typename Type, Type, typename> struct typed_cons;

	template<typename Type, Type Value, typename Exp>
	struct typed_cons<Type, Value, act<Exp>>
	{
		using rtn = typename perbuf_typed_cons<Type, Value, typename Exp::rtn>::rtn;
	};

/*
	untyped_car:
*/

	template<typename> struct untyped_car;

	template<typename Exp>
	struct untyped_car<act<Exp>>
	{
		using rtn = typename perbuf_untyped_car<typename Exp::rtn>::rtn;
	};

/*
	typed_car:
*/

	template<typename Type, typename> struct typed_car;

	template<typename Type, typename Exp>
	struct typed_car<Type, act<Exp>>
	{
		static constexpr Type value = perbuf_typed_car<Type, typename Exp::rtn>::value;
	};

/*
	untyped_cdr:
*/

	template<typename> struct untyped_cdr;

	template<typename Exp>
	struct untyped_cdr<act<Exp>>
	{
		using rtn = typename perbuf_untyped_cdr<typename Exp::rtn>::rtn;
	};

/*
	typed_cdr:
*/

	template<typename Type, typename> struct typed_cdr;

	template<typename Type, typename Exp>
	struct typed_cdr<Type, act<Exp>>
	{
		using rtn = typename perbuf_typed_cdr<Type, typename Exp::rtn>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const act<Exp> &)
	{
		using Type = typename Exp::rtn;

		Type::kind::functor::display(Type());
	}
};

