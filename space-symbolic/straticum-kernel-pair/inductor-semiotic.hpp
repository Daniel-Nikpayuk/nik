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

struct inductor
{
	// builtin types:

	template<typename, typename = filler>
	struct memoized_builtin
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<typename Filler>
	struct memoized_builtin<bool, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			bool
		>;
	};

	template<typename Filler>
	struct memoized_builtin<char, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char
		>;
	};

	template<typename Filler>
	struct memoized_builtin<unsigned char, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned char
		>;
	};

	template<typename Filler>
	struct memoized_builtin<signed char, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed char
		>;
	};

	template<typename Filler>
	struct memoized_builtin<wchar_t, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			wchar_t
		>;
	};

	template<typename Filler>
	struct memoized_builtin<char16_t, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char16_t
		>;
	};

	template<typename Filler>
	struct memoized_builtin<char32_t, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char32_t
		>;
	};

	template<typename Filler>
	struct memoized_builtin<unsigned short, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned short
		>;
	};

	template<typename Filler>
	struct memoized_builtin<signed short, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed short
		>;
	};

	template<typename Filler>
	struct memoized_builtin<unsigned int, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned int
		>;
	};

	template<typename Filler>
	struct memoized_builtin<signed int, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed int
		>;
	};

	template<typename Filler>
	struct memoized_builtin<unsigned long, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned long
		>;
	};

	template<typename Filler>
	struct memoized_builtin<signed long, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed long
		>;
	};

	template<typename Filler>
	struct memoized_builtin<unsigned long long, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned long long
		>;
	};

	template<typename Filler>
	struct memoized_builtin<signed long long, Filler>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed long long
		>;
	};

	//

	struct ch_builtin_type
	{
		template<typename Builtin, Builtin Value>
		using result = Builtin;
	};

/***********************************************************************************************************************/

	// builtin values:

	// bool:

	template<auto>
	struct memoized_bool
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<bool Value>
	struct memoized_bool<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			bool, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<char Value>
	struct memoized_builtin<char, Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<unsigned char Value>
	struct memoized_unsigned char<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned char, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<signed char Value>
	struct memoized_signed char<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed char, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<wchar_t Value>
	struct memoized_wchar_t<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			wchar_t, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<char16_t Value>
	struct memoized_char16_t<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char16_t, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<char32_t Value>
	struct memoized_char32_t<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			char32_t, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<unsigned short Value>
	struct memoized_unsigned short<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned short, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<signed short Value>
	struct memoized_signed short<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed short, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<unsigned int Value>
	struct memoized_unsigned int<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned int, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<signed int Value>
	struct memoized_signed int<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed int, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<unsigned long Value>
	struct memoized_unsigned long<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned long, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<signed long Value>
	struct memoized_signed long<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed long, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<unsigned long long Value>
	struct memoized_unsigned long long<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			unsigned long long, Value
		>;
	};

	// bool:

	template<auto>
	struct memoized_
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<signed long long Value>
	struct memoized_signed long long<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			signed long long, Value
		>;
	};

	//

	struct ch_value
	{
		template<typename Builtin, Builtin Value>
		static constexpr Builtin result = Value;
	};

};

