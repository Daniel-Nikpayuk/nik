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
			template<typename Memoizer, typename Type>
			using result = typename Continuation::template result
			<
				Memoizer, const char*, string_literal
			>;
		};

		template
		<
			typename Type, const char* string_literal,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_type_literal = typename dependent_memoization<Type>::template pattern_match_types<>::template
		s_induct
		<
			cp_s_type_to_string_literal<Continuation, string_literal>, Memoizer
		>;

		// assemblic:

		template<typename Continuation, const char* string_literal>
		struct cp_a_type_to_string_literal
		{
			template<typename Image, typename Type>
			static constexpr Image result = Continuation::template result
			<
				Image, const char*, string_literal
			>;
		};

		template
		<
			typename Type, const char* string_literal,
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_type_literal = dependent_memoization<Type>::template pattern_match_types<>::template
		a_induct
		<
			cp_a_type_to_string_literal<Continuation, string_literal>, Image
		>;
};
