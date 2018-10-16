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
	template<typename...> struct body_ { };

/*
	add:
*/

	template<typename, typename> struct add;

	template<typename Variable, typename Value, typename... Bindings>
	struct add<binding<Variable, Value>, frame<Bindings...>>
	{
		using rtn = frame<binding<Variable, Value>, Bindings...>;
	};

/*
	extend:
*/

	template<typename, typename, typename> struct extend;

	template<typename... Frames, typename Variables, typename Values>
	struct extend<environment<Frames...>, Variables, Values>
	{
		using Frame = typename make<Variables, Values>::rtn; // non-lazy evaluation.

		using rtn = environment<Frame, Frames...>;
	};

/*
	find:
*/

	template<typename, typename> struct find;

	template<typename Variable, typename Value, typename... Bindings, typename variable>
	struct find<frame<binding<Variable, Value>, Bindings...>, variable>
	{
		using rtn = typename conditional
		<
			equal<Variable, variable>,
			Value,
			act
			<
				find<frame<Bindings...>, variable>
			>

		>::rtn;
	};

	template<typename variable>
	struct find<null_frame, variable>
	{
		using rtn = undefined;
	};

/*
	lookup:
*/

	template<typename, typename> struct lookup;

	template<typename Frame, typename... Frames, typename variable>
	struct lookup<environment<Frame, Frames...>, variable>
	{
		using Value = typename find<Frame, variable>::rtn;

		using rtn = typename conditional
		<
			equal<Value, undefined>,
			act
			<
				lookup<environment<Frames...>, variable>
			>,
			Value

		>::rtn;
	};

	template<typename variable>
	struct lookup<null_environment, variable>
	{
		using rtn = undefined;
	};

/*
	make:
*/

	template<typename, typename> struct make;

// Assumes length<Variables> == length<Values>

	template<typename Variable, typename... Variables, typename Value, typename... Values>
	struct make<storage<Variable, Variables...>, storage<Value, Values...>>
	{
		using Frame = typename make<storage<Variables...>, storage<Values...>>::rtn;

		using rtn = typename add
		<
			binding<Variable, Value>,
			Frame

		>::rtn;
	};

	template<typename... Values>
	struct make<null_storage, storage<Values...>>
	{
		using rtn = null_frame;
	};

/*
	define:
*/

	template<typename...> struct define_;

	template<typename Variable, typename Value>
	struct define_<Variable, Value>
	{
		using rtn = environment
		<
			frame
			<
				binding<Variable, Value>
			>
		>;
	};

	template<typename Variable, typename Value, typename... Frames>
	struct define_<Variable, Value, environment<Frames...>>
	{
		using rtn = environment
		<
			frame
			<
				binding<Variable, Value>
			>,

			Frames...
		>;
	};
};

/*
	template<typename, typename Exp = null_expression, size_type Value = 0> struct parse;

	template<typename Variable, typename... Variables, typename... items, size_type Value>
	struct parse<expression<variable, vars...>, expression<items...>, Value>
	{
		using rtn = parse<expression<vars...>, expression<items..., index<variable, value>>>;

		using variables = typename rtn::variables;
		using body = typename rtn::body;
	};

	template<typename... exp, typename... items, size_type value>
	struct parse<expression<body_<exp...>>, expression<items...>, value>
	{
		using variables = expression<items...>;
		using body = body_<exp...>;
	};

	//

	struct analyze
	{
		using is_primitive = boolean<false>;

		using parsed = parse<expression<Expressions...>>;

		using variables = typename parsed::variables;
		using body = typename parsed::body;
	};
*/

