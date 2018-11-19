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
	temporary for debugging:
*/

	template<typename Program, typename Env = null_environment>
	struct interpret
	{
		using msg = error<'w', 'r', 'o', 'n', 'g', '!'>;

		using bind = binding
		<
			literal<'x'>,
			number<5>
		>;

		using frm = frame
		<
			bind
		>;

		using env = environment
		<
			frm
		>;

		using vert_bind = binding
		<
			literal<'j'>,
			env
		>;

		using rtn = vert_bind;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	using is_vertical = typename or_else
	<
		is_<Exp, frame>,
		is_<Exp, environment>,
		is_<Exp, continuation>,
		is_<Exp, expression>

	>::rtn;

	template<typename Variable, typename Value>
	using are_vertical = typename or_else
	<
		is_vertical<Variable>,
		is_vertical<Value>

	>::rtn;

	template<size_type length, typename Exp>
	using Safe = if_then_else
	<
		is_vertical<Exp>,
		indent<length, Exp>,
		Exp

	>;

	inline static void space(size_type length)
	{
		for (size_type k=0; k < length; ++k) Dispatched::functor::display(' ');
	}

	template<typename Type>
	inline static void print(size_type length, const Type & t)
	{
		space(length);
		Dispatched::functor::display(t);
	}

	template<typename Type>
	inline static void print(const Type & t, size_type length = 0)
	{
		Dispatched::functor::display(t);
		space(length);
	}

/*
	error:
*/

	template<char... Chars>
	inline static void display(const error<Chars...> &)
	{
		using msg = error<Chars...>;

		Dispatched::functor::display("nik error: ");

		if (is_null<msg>::rtn::value)	Dispatched::functor::display("null msg");
		else				Passive::functor::display(char(), msg(), "");
	}

/*
	 binding:
*/

	template<size_type length, typename Variable, typename Value>
	inline static void display(const indent<length, binding<Variable, Value>> &)
	{
		static constexpr size_type longer = length + 2;

		print(length, "<binding:");

		if (are_vertical<Variable, Value>::value)
		{
			print("\n\n", is_vertical<Variable>::rtn::value ? 0 : longer);
			Variable::kind::functor::display(Safe<longer, Variable>());
			Dispatched::functor::display(" ,");

			print("\n\n", is_vertical<Value>::rtn::value ? 0 : longer);
			Value::kind::functor::display(Safe<longer, Value>());

			print("\n\n", length);
			Dispatched::functor::display(">");
		}
		else
		{
			Dispatched::functor::display(" (");
			Variable::kind::functor::display(Variable());
			Dispatched::functor::display("), (");
			Value::kind::functor::display(Value());
			Dispatched::functor::display(")>");
		}
	}

/*
	frame:
*/

	template<size_type length, typename Binding, typename... Bindings>
	inline static void frame_display(const indent<length, frame<Binding, Bindings...>> &)
	{
		using Rest = frame<Bindings...>;

		display(indent<length + 2, Binding>());
		if (!is_null<Rest>::rtn::value) Dispatched::functor::display(" ,");
		print("\n\n");
		frame_display(indent<length, Rest>());
	}

	template<size_type length>
	inline static void frame_display(const indent<length, null_frame> &)
	{
		print(length, "]");
	}

	template<size_type length, typename... Bindings>
	inline static void display(const indent<length, frame<Bindings...>> & i)
	{
		print(length, "[frame:\n\n");
		frame_display(i);
	}

/*
	environment:
*/

	template<size_type length, typename Frame, typename... Frames>
	inline static void environment_display(const indent<length, environment<Frame, Frames...>> &)
	{
		using Rest = environment<Frames...>;

		display(indent<length + 2, Frame>());
		if (!is_null<Rest>::rtn::value) Dispatched::functor::display(" ,");
		print("\n\n");
		environment_display(indent<length, Rest>());
	}

	template<size_type length>
	inline static void environment_display(const indent<length, null_environment> &)
	{
		print(length, "}");
	}

	template<size_type length, typename... Frames>
	inline static void display(const indent<length, environment<Frames...>> & i)
	{
		print(length, "{environment:\n\n");
		environment_display(i);
	}

/*
	continuation:
*/

	template<typename Exp, typename... Exps>
	inline static void display_continuation(const continuation<Exp, Exps...> & f, size_type count)
	{
		space(count + 2);
		Exp::kind::functor::display(Exp());
		if (!is_null<continuation<Exps...>>::rtn::value) Dispatched::functor::display(" ,");
		Dispatched::functor::display("\n\n");
		display_continuation(continuation<Exps...>(), count);
	}

	inline static void display_continuation(const continuation<> &, size_type count)
	{
		space(count);
		Dispatched::functor::display(">|");
	}

	template<typename... Exps>
	inline static void display(const continuation<Exps...> & f, size_type count = 0)
	{
		space(count);
		Dispatched::functor::display("|<continuation:\n\n");
		display_continuation(f, count);
	}

/*
	expression:
*/

	template<typename Exp, typename... Exps>
	inline static void display_expression(const expression<Exp, Exps...> & f, size_type count)
	{
		space(count + 2);

		Exp::kind::functor::display(Exp());

		if (!is_null<expression<Exps...>>::rtn::value) Dispatched::functor::display(" ,");

		Dispatched::functor::display("\n\n");
		display_expression(expression<Exps...>(), count);
	}

	inline static void display_expression(const null_expression &, size_type count)
	{
		space(count);
		Dispatched::functor::display("))");
	}

	template<typename... Exps>
	inline static void display(const expression<Exps...> & f, size_type count = 0)
	{
		space(count);
		Dispatched::functor::display("((expression:\n\n");
		display_expression(f, count);
	}

/*
	default:
*/

	template<typename Type>
	inline static void display(const Type &)
	{
		display(indent<0, Type>());
	}

