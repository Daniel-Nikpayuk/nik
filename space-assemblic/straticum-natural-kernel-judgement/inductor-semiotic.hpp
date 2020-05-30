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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

		// The following bool value pattern matcher is here as its induction operator requires its own specialization.

	template<auto, typename = filler>
	struct pattern_match_bool_value
	{
		template<typename Continuation = ch_symbolic_values, typename Inductor = pnkb_inductor_ss>
		using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

		//

		template<typename Continuation = ch_assemblic_value, typename OutType = bool>
		static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
	};

	template<typename Filler>
	struct pattern_match_bool_value<true, Filler>
	{
		template<typename Continuation = ch_symbolic_values, typename Inductor = pnkb_inductor_ss>
		using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

		template<typename Continuation, typename Antecedent, typename Consequent>
		using symbolic_induct = typename Continuation::template result
		<
			Antecedent
		>;

		//

		template<typename Continuation = ch_assemblic_value, typename OutType = bool>
		static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;

			// assemblic_induct is not implemented as it's better to use the native C++ ( ? : ) grammar.
	};

	template<typename Filler>
	struct pattern_match_bool_value<false, Filler>
	{
		template<typename Continuation = ch_symbolic_values, typename Inductor = pnkb_inductor_ss>
		using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

		template<typename Continuation, typename Antecedent, typename Consequent>
		using symbolic_induct = typename Continuation::template result
		<
			Consequent
		>;

		//

		template<typename Continuation = ch_assemblic_value, typename OutType = bool>
		static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;

			// assemblic_induct is not implemented as it's better to use the native C++ ( ? : ) grammar.
	};

	// implemented at a lower level for performance:

	template<auto Value> using pattern_match_char_value			= typename dependent_memoization<char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_char_value		= typename dependent_memoization<unsigned char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_char_value		= typename dependent_memoization<signed char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_wchar_t_value			= typename dependent_memoization<wchar_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_char16_t_value			= typename dependent_memoization<char16_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_char32_t_value			= typename dependent_memoization<char32_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_short_value		= typename dependent_memoization<unsigned short>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_short_value		= typename dependent_memoization<signed short>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_int_value		= typename dependent_memoization<unsigned int>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_int_value		= typename dependent_memoization<signed int>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_long_value		= typename dependent_memoization<unsigned long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_long_value		= typename dependent_memoization<signed long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_long_long_value	= typename dependent_memoization<unsigned long long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_long_long_value		= typename dependent_memoization<signed long long>::template
										  pattern_match_values<Value>;
};
