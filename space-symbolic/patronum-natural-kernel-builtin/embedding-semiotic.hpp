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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// type literal:

		// symbolic:

		template<typename Continuation, const char* string_literal>
		struct cp_s_type_to_string_literal
		{
			template<typename Inductor, typename Type>
			using result = typename Continuation::template result
			<
				Inductor, const char*, string_literal
			>;
		};

		template<typename Type, const char* string_literal, typename Continuation = ch_symbolic_values>
		using s_type_literal = typename dependent_memoization<Type>::template pattern_match_type<Type>::template
		symbolic_induct
		<
			cp_s_type_to_string_literal<Continuation, string_literal>
		>;

		// assemblic:

		template<typename Continuation, const char* string_literal>
		struct cp_a_type_to_string_literal
		{
			template<typename Inductor, typename Type>
			static constexpr Inductor result = Continuation::template result
			<
				Inductor, const char*, string_literal
			>;
		};

		template<typename Type, const char* string_literal, typename Continuation = ch_assemblic_value>
		static constexpr const char* a_type_literal = dependent_memoization<Type>::template pattern_match_type<Type>::template
		assemblic_induct
		<
			cp_a_type_to_string_literal<Continuation, string_literal>
		>;
};

