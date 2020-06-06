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

	// judgment type:

			// optimized to assume Judgment is in fact a judgment.

		// symbolic:

		template<typename Continuation>
		struct cp_s_judgment_type
		{
			template<typename Type, template<Type...> class ListType, Type... Values>
			using result = typename Continuation::template result
			<
				Type
			>;
		};

		template<typename Type, typename Judgment, typename Continuation = ch_symbolic_type>
		using s_judgment_type = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template symbolic_induct
		<
			cp_s_judgment_type<Continuation>
		>;

	// judgment value:

			// optimized to assume Judgment is in fact a judgment.

		// symbolic:

		template<typename Continuation, typename Inductor = pnkb_inductor_ss>
		struct cp_s_judgment_value
		{
			template<typename Type, template<Type...> class ListType, Type... Values>
			using result = typename Continuation::template result
			<
				Inductor, Type, Values...
			>;
		};

		template<typename Type, typename Judgment, typename Continuation = ch_symbolic_values>
		using s_judgment_value = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template symbolic_induct
		<
			cp_s_judgment_value<Continuation>
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_a_judgment_value
		{
			template<typename OutType, typename Type, template<Type...> class ListType, Type Value, Type... Values>
			static constexpr OutType result = Continuation::template result
			<
				OutType, Type, Value
			>;
		};

		template<typename Type, typename Judgment, typename Continuation = ch_assemblic_value>
		static constexpr Type a_judgment_value = dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template assemblic_induct
		<
			cp_a_judgment_value<Continuation>, Type
		>;

	// dependent judgment type:

			// optimized to assume Judgment is in fact a judgment.

		// symbolic:

		template<typename Continuation>
		struct cp_s_dependent_judgment_type
		{
			template<typename Inductor, typename Type, Type... Values>
			using result = typename Continuation::template result
			<
				Type
			>;
		};

		template<typename Type, typename Judgment, typename Continuation = ch_symbolic_type>
		using s_dependent_judgment_type = typename Judgment::template
		symbolic_induct
		<
			cp_s_dependent_judgment_type<Continuation>
		>;

	// dependent judgment value:

			// optimized to assume Judgment is in fact a judgment.

		// symbolic:

		template<typename Type, typename Judgment, typename Continuation = ch_symbolic_values>
		using s_dependent_judgment_value = typename Judgment::template
		symbolic_induct
		<
			Continuation
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_a_dependent_judgment_value
		{
			template<typename OutType, typename Type, Type Value, Type... Values>
			static constexpr OutType result = Continuation::template result
			<
				OutType, Type, Value
			>;
		};

		template<typename Type, typename Judgment, typename Continuation = ch_assemblic_value>
		static constexpr Type a_dependent_judgment_value = Judgment::template
		assemblic_induct
		<
			cp_a_dependent_judgment_value<Continuation>, Type
		>;
};

