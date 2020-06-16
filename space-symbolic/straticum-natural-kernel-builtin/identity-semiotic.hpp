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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, identity)

	// bool types:

		// symbolic:

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_bool = s_is_equal<bool, Exp, Continuation, Kind, ListKind>;

		// assemblic:

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_bool = a_is_equal<bool, Exp, Continuation, Image>;

	// int types:

		// symbolic:

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned char,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_char = s_is_equal<unsigned char, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = signed char,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_signed_char = s_is_equal<signed char, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_short = s_is_equal<unsigned short, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = signed short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_signed_short = s_is_equal<signed short, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_int = s_is_equal<unsigned int, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_signed_int = s_is_equal<signed int, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_long = s_is_equal<unsigned long, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = signed long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_signed_long = s_is_equal<signed long, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_long_long = s_is_equal<unsigned long long, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = signed long long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_signed_long_long = s_is_equal<signed long long, Exp, Continuation, Kind, ListKind>;

		// assemblic:

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_char = a_is_equal<unsigned char, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_signed_char = a_is_equal<signed char, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_short = a_is_equal<unsigned short, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_signed_short = a_is_equal<signed short, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_int = a_is_equal<unsigned int, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_signed_int = a_is_equal<signed int, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_long = a_is_equal<unsigned long, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_signed_long = a_is_equal<signed long, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_long_long = a_is_equal<unsigned long long, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_signed_long_long = a_is_equal<signed long long, Exp, Continuation, Image>;

	// char types:

		// symbolic:

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = char,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_char = s_is_equal<char, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = wchar_t,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_wchar_t = s_is_equal<wchar_t, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = char16_t,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_char16_t = s_is_equal<char16_t, Exp, Continuation, Kind, ListKind>;

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = char32_t,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_char32_t = s_is_equal<char32_t, Exp, Continuation, Kind, ListKind>;

		// assemblic:

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_char = a_is_equal<char, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_wchar_t = a_is_equal<wchar_t, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_char16_t = a_is_equal<char16_t, Exp, Continuation, Image>;

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_char32_t = a_is_equal<char32_t, Exp, Continuation, Image>;
};
