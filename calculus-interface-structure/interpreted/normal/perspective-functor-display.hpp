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

		using cont = continuation
		<
			expression
			<
				literal<'x'>,
				literal<'y'>
			>,

			expression
			<
				literal<'x'>,
				boolean<true>
			>
		>;

		using rtn = env;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	struct is_vertical
	{
		using rtn = typename or_else
		<
			is_<Exp, frame>,
			is_<Exp, environment>,
			is_<Exp, continuation>,
			is_<Exp, expression>

		>::rtn;

		static constexpr bool value = rtn::value;
	};

	template<typename Variable, typename Value>
	struct is_vertical<binding<Variable, Value>>
	{
		using rtn = typename or_else
		<
			is_vertical<Variable>,
			is_vertical<Value>

		>::rtn;

		static constexpr bool value = rtn::value;
	};

	template<typename Type, size_type margin, size_type padding>
	using Markup = if_then_else
	<
		is_vertical<Type>,

		vertical
		<
			Type,
			margin,
			padding,
			functor
		>,

		indent
		<
			Type,
			margin
		>

	>; // ::rtn call unnecessary

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

	template<typename Variable, typename Value>
	inline static void display(const binding<Variable, Value> &)
	{
		Dispatched::functor::display("<binding: (");
		Variable::kind::functor::display(Variable());
		Dispatched::functor::display("), (");
		Value::kind::functor::display(Value());
		Dispatched::functor::display(")>");
	}

	template<typename Variable, typename Value, size_type margin, size_type padding>
	inline static void display(const vertical<binding<Variable, Value>, margin, padding, functor> &)
	{
		static constexpr size_type width = margin + padding;

		using SafeVar = Markup<Variable, width, padding>;
		using SafeVal = Markup<Value, width, padding>;

		print(margin, "<binding:\n");
		SafeVar::kind::functor::display(SafeVar());

		Dispatched::functor::display(" ,\n");
		SafeVal::kind::functor::display(SafeVal());

		print(margin, ">");
	}

/*
	frame:
*/

	struct frame_markup
	{
		static constexpr const char *label	= "boolean";
		static constexpr const char *before	= ": ";
		static constexpr const char *front	= "";
		static constexpr const char *back	= "";
		static constexpr const char *after	= "";
	};

	template<typename... Bindings, size_type margin, size_type padding>
	inline static void display(const vertical<frame<Bindings...>, margin, padding, functor> &)
	{
		using Type = vertical<frame<Bindings...>, margin, padding, functor>;

		Dispatched::functor::display("[frame:\n");
		Type::kind::functor::display(Type());
		Dispatched::functor::display("\n]");
	}

	template<typename... Bindings>
	inline static void display(const frame<Bindings...> &)
	{
		display(vertical<frame<Bindings...>, 4, 4, functor>());
	}

/*
	environment:
*/

	struct frame_markup
	{
		static constexpr const char *label	= "boolean";
		static constexpr const char *before	= ": ";
		static constexpr const char *front	= "";
		static constexpr const char *back	= "";
		static constexpr const char *after	= "";
	};

	template<typename... Frames>
	inline static void display(const environment<Frames...> &)
	{
		using SafeEnv = vertical<environment<Frames...>, 4, 4, functor>;

		Dispatched::functor::display("{environment:\n");
		SafeEnv::kind::functor::display(SafeEnv());
		Dispatched::functor::display("\n}");
	}

/*
	continuation:
*/

/*
	template<size_type length, typename... Types>
	inline static void display(const indent<length, continuation<Types...>> & i)
	{
		print(length, "|<continuation:");
		vertical_display(i, ">|");
	}
*/

/*
	expression:
*/

/*
	template<size_type length, typename... Types>
	inline static void display(const indent<length, expression<Types...>> & i)
	{
		print(length, "((expression:");
		vertical_display(i, "))");
	}
*/

