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
	#include nik_symbolic_typedef(patronum, natural, kernel, judgement, identity)

	// is judgement:

		// symbolic:

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_bool_judgement = s_is_judgement<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char_judgement = s_is_judgement<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_char_judgement = s_is_judgement<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_char_judgement = s_is_judgement<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_wchar_t_judgement = s_is_judgement<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char16_t_judgement = s_is_judgement<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_char32_t_judgement = s_is_judgement<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_short_judgement = s_is_judgement<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_short_judgement = s_is_judgement<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_int_judgement = s_is_judgement<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_int_judgement = s_is_judgement<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_judgement = s_is_judgement<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_judgement = s_is_judgement<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_long_judgement = s_is_judgement<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_long_judgement = s_is_judgement<signed long long, Exp, Continuation>;

		// assemblic:

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_bool_judgement = a_is_judgement<bool, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char_judgement = a_is_judgement<char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_char_judgement = a_is_judgement<unsigned char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_char_judgement = a_is_judgement<signed char, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_wchar_t_judgement = a_is_judgement<wchar_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char16_t_judgement = a_is_judgement<char16_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_char32_t_judgement = a_is_judgement<char32_t, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_short_judgement = a_is_judgement<unsigned short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_short_judgement = a_is_judgement<signed short, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_int_judgement = a_is_judgement<unsigned int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_int_judgement = a_is_judgement<signed int, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_judgement = a_is_judgement<unsigned long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_judgement = a_is_judgement<signed long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_unsigned_long_long_judgement = a_is_judgement<unsigned long long, Exp, Continuation>;

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_signed_long_long_judgement = a_is_judgement<signed long long, Exp, Continuation>;
};

