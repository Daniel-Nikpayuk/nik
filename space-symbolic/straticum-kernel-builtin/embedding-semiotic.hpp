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

struct embedding
{
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)

	// builtin to string literal:

	template<typename, typename = filler> struct builtin_to_string;

	template<typename Filler>
	struct builtin_to_string<bool, Filler>				{ static constexpr const char literal[] = "bool"; };

	template<typename Filler>
	struct builtin_to_string<char, Filler>				{ static constexpr const char literal[] = "char"; };

	template<typename Filler>
	struct builtin_to_string<unsigned char, Filler>			{ static constexpr const char literal[] = "unsigned char"; };

	template<typename Filler>
	struct builtin_to_string<signed char, Filler>			{ static constexpr const char literal[] = "signed char"; };

	template<typename Filler>
	struct builtin_to_string<wchar_t, Filler>			{ static constexpr const char literal[] = "wchar_t"; };

	template<typename Filler>
	struct builtin_to_string<char16_t, Filler>			{ static constexpr const char literal[] = "char16_t"; };

	template<typename Filler>
	struct builtin_to_string<char32_t, Filler>			{ static constexpr const char literal[] = "char32_t"; };

	template<typename Filler>
	struct builtin_to_string<unsigned short, Filler>		{ static constexpr const char literal[] = "unsigned short"; };

	template<typename Filler>
	struct builtin_to_string<signed short, Filler>			{ static constexpr const char literal[] = "signed short"; };

	template<typename Filler>
	struct builtin_to_string<unsigned int, Filler>			{ static constexpr const char literal[] = "unsigned int"; };

	template<typename Filler>
	struct builtin_to_string<signed int, Filler>			{ static constexpr const char literal[] = "signed int"; };

	template<typename Filler>
	struct builtin_to_string<unsigned long, Filler>			{ static constexpr const char literal[] = "unsigned long"; };

	template<typename Filler>
	struct builtin_to_string<signed long, Filler>			{ static constexpr const char literal[] = "signed long"; };

	template<typename Filler>
	struct builtin_to_string<unsigned long long, Filler>		{ static constexpr const char literal[] = "unsigned long long"; };

	template<typename Filler>
	struct builtin_to_string<signed long long, Filler>		{ static constexpr const char literal[] = "signed long long"; };

	// builtin types literal:

		// It would be preferrable to pass the string literals directly as a template parameter then to specialize
		// each type_to_string_literal directly (it would fit this library narrative design better), but only
		// C++20 and greater allow for it.

	template<typename Continuation>
	struct cp_type_to_string_literal
	{
		template<typename Type>
		using result = typename Continuation::template result
		<
			dependent_memoization<const char*>, const char*, builtin_to_string<Type>::literal
		>;
	};

	// builtin type literal:

	template<typename Continuation = ch_judgement_value>
	using bool_literal =
	typename dependent_memoization<bool>::template memoized_type<bool>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using char_literal =
	typename dependent_memoization<char>::template memoized_type<char>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using unsigned_char_literal =
	typename dependent_memoization<unsigned char>::template memoized_type<unsigned char>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using signed_char_literal =
	typename dependent_memoization<signed char>::template memoized_type<signed char>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using wchar_t_literal =
	typename dependent_memoization<wchar_t>::template memoized_type<wchar_t>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using char16_t_literal =
	typename dependent_memoization<char16_t>::template memoized_type<char16_t>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using char32_t_literal =
	typename dependent_memoization<char32_t>::template memoized_type<char32_t>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using unsigned_short_literal =
	typename dependent_memoization<unsigned short>::template memoized_type<unsigned short>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using signed_short_literal =
	typename dependent_memoization<signed short>::template memoized_type<signed short>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using unsigned_int_literal =
	typename dependent_memoization<unsigned int>::template memoized_type<unsigned int>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using signed_int_literal =
	typename dependent_memoization<signed int>::template memoized_type<signed int>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using unsigned_long_literal =
	typename dependent_memoization<unsigned long>::template memoized_type<unsigned long>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using signed_long_literal =
	typename dependent_memoization<signed long>::template memoized_type<signed long>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using unsigned_long_long_literal =
	typename dependent_memoization<unsigned long long>::template memoized_type<unsigned long long>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;

	template<typename Continuation = ch_judgement_value>
	using signed_long_long_literal =
	typename dependent_memoization<signed long long>::template memoized_type<signed long long>::template type_induct
	<
		type_to_string_literal<Continuation>, dependent_memoization<const char*>
	>;
};

