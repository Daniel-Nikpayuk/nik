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
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, identity)

	// is judgment:

		// symbolic:

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_bool_judgment = s_is_judgment<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char_judgment = s_is_judgment<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_char_judgment = s_is_judgment<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_char_judgment = s_is_judgment<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_wchar_t_judgment = s_is_judgment<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char16_t_judgment = s_is_judgment<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char32_t_judgment = s_is_judgment<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_short_judgment = s_is_judgment<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_short_judgment = s_is_judgment<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_int_judgment = s_is_judgment<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_int_judgment = s_is_judgment<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_judgment = s_is_judgment<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_judgment = s_is_judgment<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_long_judgment = s_is_judgment<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_long_judgment = s_is_judgment<signed long long, Exp, Continuation>;

		// assemblic:

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_bool_judgment = a_is_judgment<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char_judgment = a_is_judgment<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_char_judgment = a_is_judgment<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_char_judgment = a_is_judgment<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_wchar_t_judgment = a_is_judgment<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char16_t_judgment = a_is_judgment<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char32_t_judgment = a_is_judgment<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_short_judgment = a_is_judgment<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_short_judgment = a_is_judgment<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_int_judgment = a_is_judgment<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_int_judgment = a_is_judgment<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_judgment = a_is_judgment<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_judgment = a_is_judgment<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_long_judgment = a_is_judgment<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_long_judgment = a_is_judgment<signed long long, Exp, Continuation>;

	// is dependent judgment:

		// symbolic:

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_bool_dependent_judgment = s_is_dependent_judgment<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char_dependent_judgment = s_is_dependent_judgment<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_char_dependent_judgment = s_is_dependent_judgment<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_char_dependent_judgment = s_is_dependent_judgment<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_wchar_t_dependent_judgment = s_is_dependent_judgment<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char16_t_dependent_judgment = s_is_dependent_judgment<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char32_t_dependent_judgment = s_is_dependent_judgment<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_short_dependent_judgment = s_is_dependent_judgment<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_short_dependent_judgment = s_is_dependent_judgment<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_int_dependent_judgment = s_is_dependent_judgment<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_int_dependent_judgment = s_is_dependent_judgment<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_dependent_judgment = s_is_dependent_judgment<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_dependent_judgment = s_is_dependent_judgment<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_long_dependent_judgment = s_is_dependent_judgment<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_long_dependent_judgment = s_is_dependent_judgment<signed long long, Exp, Continuation>;

		// assemblic:

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_bool_dependent_judgment =
			a_is_dependent_judgment<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char_dependent_judgment =
			a_is_dependent_judgment<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_char_dependent_judgment =
			a_is_dependent_judgment<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_char_dependent_judgment =
			a_is_dependent_judgment<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_wchar_t_dependent_judgment =
			a_is_dependent_judgment<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char16_t_dependent_judgment =
			a_is_dependent_judgment<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char32_t_dependent_judgment =
			a_is_dependent_judgment<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_short_dependent_judgment =
			a_is_dependent_judgment<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_short_dependent_judgment =
			a_is_dependent_judgment<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_int_dependent_judgment =
			a_is_dependent_judgment<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_int_dependent_judgment =
			a_is_dependent_judgment<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_dependent_judgment =
			a_is_dependent_judgment<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_dependent_judgment =
			a_is_dependent_judgment<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_long_dependent_judgment =
			a_is_dependent_judgment<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_long_dependent_judgment =
			a_is_dependent_judgment<signed long long, Exp, Continuation>;
};

