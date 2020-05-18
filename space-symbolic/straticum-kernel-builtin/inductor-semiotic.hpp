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

/***********************************************************************************************************************/

	// void_ptr values:

/*
	void_ptr values aren't generally considered meaningful as template parameters,
	this inductor is only here to maintain the narrative design of this library.
*/

	template<auto>
	struct memoized_void_ptr
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<void_ptr Value>
	struct memoized_void_ptr<Value>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			Value
		>;
	};
};

