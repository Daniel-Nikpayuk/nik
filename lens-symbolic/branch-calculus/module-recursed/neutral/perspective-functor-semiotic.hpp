/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

		#include nik_typedef(calculus, perspective, untyped, functor)

		#include nik_typedef(calculus, constant, boolean, functor)
		#include nik_typedef(calculus, constant, number, functor)

	#undef safe_name

	#include nik_typedef(calculus, constant, recursed, structure)
	#include nik_typedef(calculus, constant, recursed, identity)

/*
	relabel:
*/

	template<typename Exp, template<typename...> class Label>
	struct relabel
	{
		template<typename> struct strict;

		template<typename... Exps, template<typename...> class InitialLabel>
		struct strict<InitialLabel<Exps...>>
		{
			using rtn = Label<Exps...>;
		};

		using rtn = typename strict
		<
			typename Exp::rtn

		>::rtn;
	};

/*
	size_of:
*/

	template<typename Expression>
	struct size_of
	{
		template<typename> struct strict;

		template<typename Exp>
		struct strict<type<Exp>>
		{
			using rtn = number
			<
				sizeof(Exp)
			>;
		};

		using rtn = typename strict
		<
			typename Expression::rtn

		>::rtn;
	};

/*
	memoize_if_then_else:
*/

	template<typename, typename Filler = filler> struct memoize_if_then_else;

	template<typename Filler>
	struct memoize_if_then_else<boolean<true>, Filler>
	{
		template<typename Exp1, typename Exp2>
		using type = Exp1;
	};

	template<typename Filler>
	struct memoize_if_then_else<boolean<false>, Filler>
	{
		template<typename Exp1, typename Exp2>
		using type = Exp2;
	};

/*
	if_then_else:
*/

	template<typename Pred, typename Ante, typename Conse>
	using if_then_else = typename memoize_if_then_else
	<
		typename Pred::rtn

	>::template type<Ante, Conse>;

/*
	template<typename Exp0, typename Exp1, typename Exp2>
	struct if_then_else
	{
		template<typename, typename, typename> struct strict;

		template<typename Ante, typename Conse>
		struct strict<boolean<true>, Ante, Conse>
		{
			using rtn = typename Ante::rtn;
		};

		template<typename Ante, typename Conse>
		struct strict<boolean<false>, Ante, Conse>
		{
			using rtn = typename Conse::rtn;
		};

		using rtn = typename strict
		<
			typename Exp0::rtn,
			Exp1,
			Exp2

		>::rtn;
	};
*/

/*
	cons:
*/

	template<typename Value, typename List>
	struct cons
	{
		using rtn = typename perunf_cons
		<
			typename Value::rtn,
			typename List::rtn

		>::rtn;
	};

/*
	cdr:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename...> struct cdr;

	template<typename Exp>
	struct cdr<Exp>
	{
		using rtn = typename perunf_cdr
		<
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct cdr<Exp1, Exp2>
	{
		using List	= typename cdr<Exp1>::rtn;
		using Index	= typename Exp2::rtn;

		using rtn = typename if_then_else
		<
			is_equal<Index, zero>,

			List,

			cdr
			<
				List,
				connuf_decrement<Index>
			>

		>::rtn;
	};

/*
	car:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename...> struct car;

	template<typename Exp>
	struct car<Exp>
	{
		using rtn = typename perunf_car
		<
			typename Exp::rtn

		>::rtn;
	};

	template<typename Exp1, typename Exp2>
	struct car<Exp1, Exp2>
	{
		using Index = typename Exp2::rtn;

		using rtn = typename car
		<
			if_then_else
			<
				is_equal<Index, zero>,
				Exp1,

				cdr
				<
					Exp1,
					connuf_decrement<Index>
				>
			>

		>::rtn;
	};

/*
	push:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp1, typename Exp2>
	struct push
	{
		using rtn = typename push<Exp1, typename Exp2::rtn>::rtn;
	};

	template<typename Exp, typename... Values, template<typename...> class ListType>
	struct push<Exp, ListType<Values...>>
	{
		using rtn = ListType<Values..., typename Exp::rtn>;
	};

/*
	length:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename Exp1, typename Exp2 = number<0>>
	struct length
	{
		using List	= typename Exp1::rtn;
		using Count	= typename Exp2::rtn;

		using rtn = typename if_then_else
		<
			is_null<List>,

			Count,

			length
			<
				cdr<List>,
				connuf_increment<Count>
			>

		>::rtn;

	};

/*
	catenate:

	This implementation is optimized using partial specialization pattern matching.
*/

	template<typename, typename, typename...> struct catenate;

	template<typename... Values1, typename... Values2, template<typename...> class ListType>
	struct catenate<ListType<Values1...>, ListType<Values2...>>
	{
		using rtn = ListType<Values1..., Values2...>;
	};

	template<typename Exp1, typename Exp2>
	struct catenate<Exp1, Exp2>
	{
		using rtn = typename catenate
		<
			typename Exp1::rtn,
			typename Exp2::rtn

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename Exp3, typename... Exps>
	struct catenate<Exp1, Exp2, Exp3, Exps...>
	{
		using rtn = typename catenate
		<
			typename catenate<Exp1, Exp2>::rtn,
			Exp3,

			Exps...

		>::rtn;
	};

/*
	unite:

	Convenience function which is common enough to place here.
	Pre-evaluation is passed to the composing methods as it is otherwise redundant.
*/

	template<typename List1, typename Value, typename List2>
	struct unite
	{
		using rtn = typename catenate
		<
			List1,

			cons
			<
				Value,
				List2
			>

		>::rtn;
	};

/***********************************************************************************************************************/

/*
	sub_evaluate:
*/

	template<typename...> struct sub_evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct sub_evaluate
	<
		else_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred,
			Exp,

			sub_evaluate
			<
				Exps...
			>

		>::rtn;
	};

	template<typename Exp>
	struct sub_evaluate
	<
		then<Exp>
	>
	{
		using rtn = typename Exp::rtn;
	};

/*
	evaluate:
*/

	template<typename...> struct evaluate;

	template<typename Pred, typename Exp, typename... Exps>
	struct evaluate
	<
		if_then<Pred, Exp>,
		Exps...
	>
	{
		using rtn = typename if_then_else
		<
			Pred,
			Exp,

			sub_evaluate
			<
				Exps...
			>

		>::rtn;
	};

/*
//	memoize_evaluate:

	template<size_type, typename Filler = filler> struct memoize_evaluate;

	template<typename Filler>
	struct memoize_evaluate<1, Filler> // else_then<Pred, Exp>
	{
		template<typename Else_Then, typename Next, typename... Rest>
		using type = if_then_else
		<
			typename Else_Then::predicate,
			typename Else_Then::expression,

			typename memoize_evaluate
			<
				is_else_then<Next>::value,
				Filler

			>::template type<Next, Rest...>
		>;
	};

	template<typename Filler>
	struct memoize_evaluate<0, Filler> // then<Exp>
	{
		template<typename Then, typename... Rest>
		using type = typename Then::expression;
	};

//	No safety checks are done.

	template<typename... Expressions>
	struct evaluate
	{
		using rtn = typename memoize_evaluate<1>::template type<Expressions...>::rtn;
	};

//	The compiler has difficulty with these.

	template<typename... Expressions> // if_then as else_then
	using evaluate = typename memoize_evaluate<1>::template type<Expressions...>;

	template<typename First, typename... Rest> // if_then as else_then
	using evaluate = if_then_else
	<
		is_if_then<First>,
		typename First
		typename memoize_evaluate<1>::template type<Expressions...>,
		void // return as error<> ?
	>;
*/

/*
	not_the_case:
*/

	template<typename Exp>
	struct not_the_case
	{
		using rtn = typename conbof_apply
		<
			operate<'!'>,

			typename Exp::rtn

		>::rtn;
	};

/*
	or_else:
*/

	template<typename...> struct or_else;

	template<typename Exp>
	struct or_else<Exp>
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Exp1, typename Exp2, typename... Exps>
	struct or_else<Exp1, Exp2, Exps...>
	{
		using rtn = typename if_then_else
		<
			typename Exp1::rtn,

			boolean<true>,

			or_else
			<
				Exp2,

				Exps...
			>

		>::rtn;
	};

/*
	and_then:
*/

	template<typename...> struct and_then;

	template<typename Exp>
	struct and_then<Exp>
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Exp1, typename Exp2, typename... Exps>
	struct and_then<Exp1, Exp2, Exps...>
	{
		using rtn = typename if_then_else
		<
			typename Exp1::rtn,

			and_then
			<
				Exp2,

				Exps...
			>,

			boolean<false>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const Exp &)
	{
		using Type = typename Exp::rtn;
	
		Type::kind::functor::display(Type());
	}
};

