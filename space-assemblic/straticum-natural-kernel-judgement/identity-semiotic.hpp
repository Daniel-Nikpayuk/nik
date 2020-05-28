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

struct identity
{
	#include nik_assemblic_typedef(patronum, kernel, builtin, inductor)
	#include nik_assemblic_typedef(straticum, kernel, builtin, inductor)

	// builtin types:

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_bool)() = ch_inductor<bool>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_char)() = ch_inductor<char>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_unsigned_char)() = ch_inductor<unsigned char>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_signed_char)() = ch_inductor<signed char>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_wchar_t)() = ch_inductor<wchar_t>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_char16_t)() = ch_inductor<char16_t>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_char32_t)() = ch_inductor<char32_t>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_unsigned_short)() = ch_inductor<unsigned short>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_signed_short)() = ch_inductor<signed short>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_unsigned_int)() = ch_inductor<unsigned int>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_signed_int)() = ch_inductor<signed int>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_unsigned_long)() = ch_inductor<unsigned long>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_signed_long)() = ch_inductor<signed long>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_unsigned_long_long)() = ch_inductor<unsigned long long>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	template<typename Exp, typename Continuation>
	static constexpr bool (*is_signed_long_long)() = ch_inductor<signed long long>::template memoized_type<Exp>::template match
	<
		Continuation
	>;

	// void_ptr values:

	template<auto Exp, typename Continuation>
	static constexpr bool (*is_void_ptr)() = memoized_void_ptr<Exp>::template match
	<
		Continuation
	>;
};

