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

struct structure
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, structure)

	// builtin judgements:

		// symbolic:

		template<bool Value, typename Continuation = ch_symbolic_values>
		using s_bool_to_judgement = s_to_judgement<bool, Value, Continuation>;

		template<char Value, typename Continuation = ch_symbolic_values>
		using s_char_to_judgement = s_to_judgement<char, Value, Continuation>;

		template<unsigned char Value, typename Continuation = ch_symbolic_values>
		using s_unsigned_char_to_judgement = s_to_judgement<unsigned char, Value, Continuation>;

		template<signed char Value, typename Continuation = ch_symbolic_values>
		using s_signed_char_to_judgement = s_to_judgement<signed char, Value, Continuation>;

		template<wchar_t Value, typename Continuation = ch_symbolic_values>
		using s_wchar_t_to_judgement = s_to_judgement<wchar_t, Value, Continuation>;

		template<char16_t Value, typename Continuation = ch_symbolic_values>
		using s_char16_t_to_judgement = s_to_judgement<char16_t, Value, Continuation>;

		template<char32_t Value, typename Continuation = ch_symbolic_values>
		using s_char32_t_to_judgement = s_to_judgement<char32_t, Value, Continuation>;

		template<unsigned short Value, typename Continuation = ch_symbolic_values>
		using s_unsigned_short_to_judgement = s_to_judgement<unsigned short, Value, Continuation>;

		template<signed short Value, typename Continuation = ch_symbolic_values>
		using s_signed_short_to_judgement = s_to_judgement<signed short, Value, Continuation>;

		template<unsigned int Value, typename Continuation = ch_symbolic_values>
		using s_unsigned_int_to_judgement = s_to_judgement<unsigned int, Value, Continuation>;

		template<signed int Value, typename Continuation = ch_symbolic_values>
		using s_signed_int_to_judgement = s_to_judgement<signed int, Value, Continuation>;

		template<unsigned long Value, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_to_judgement = s_to_judgement<unsigned long, Value, Continuation>;

		template<signed long Value, typename Continuation = ch_symbolic_values>
		using s_signed_long_to_judgement = s_to_judgement<signed long, Value, Continuation>;

		template<unsigned long long Value, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_long_to_judgement = s_to_judgement<unsigned long long, Value, Continuation>;

		template<signed long long Value, typename Continuation = ch_symbolic_values>
		using s_signed_long_long_to_judgement = s_to_judgement<signed long long, Value, Continuation>;

		// assemblic:

		template<typename Type, bool Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_bool_to_judgement = a_to_judgement<Type, bool, Value, Continuation>;

		template<typename Type, char Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_char_to_judgement = a_to_judgement<Type, char, Value, Continuation>;

		template<typename Type, unsigned char Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_unsigned_char_to_judgement = a_to_judgement<Type, unsigned char, Value, Continuation>;

		template<typename Type, signed char Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_signed_char_to_judgement = a_to_judgement<Type, signed char, Value, Continuation>;

		template<typename Type, wchar_t Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_wchar_t_to_judgement = a_to_judgement<Type, wchar_t, Value, Continuation>;

		template<typename Type, char16_t Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_char16_t_to_judgement = a_to_judgement<Type, char16_t, Value, Continuation>;

		template<typename Type, char32_t Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_char32_t_to_judgement = a_to_judgement<Type, char32_t, Value, Continuation>;

		template<typename Type, unsigned short Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_unsigned_short_to_judgement = a_to_judgement<Type, unsigned short, Value, Continuation>;

		template<typename Type, signed short Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_signed_short_to_judgement = a_to_judgement<Type, signed short, Value, Continuation>;

		template<typename Type, unsigned int Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_unsigned_int_to_judgement = a_to_judgement<Type, unsigned int, Value, Continuation>;

		template<typename Type, signed int Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_signed_int_to_judgement = a_to_judgement<Type, signed int, Value, Continuation>;

		template<typename Type, unsigned long Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_unsigned_long_to_judgement = a_to_judgement<Type, unsigned long, Value, Continuation>;

		template<typename Type, signed long Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_signed_long_to_judgement = a_to_judgement<Type, signed long, Value, Continuation>;

		template<typename Type, unsigned long long Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_unsigned_long_long_to_judgement = a_to_judgement<Type, unsigned long long, Value, Continuation>;

		template<typename Type, signed long long Value, typename Continuation = ch_assemblic_value>
		static constexpr Type a_signed_long_long_to_judgement = a_to_judgement<Type, signed long long, Value, Continuation>;
};
