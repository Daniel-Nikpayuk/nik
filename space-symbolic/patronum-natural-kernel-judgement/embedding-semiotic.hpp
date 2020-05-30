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

	// judgement type:

			// optimized to assume Judgement is in fact a judgement.

		// symbolic:

		template<typename Continuation>
		struct cp_s_judgement_type
		{
			template<typename Type, template<Type...> class ListType, Type... Values>
			using result = typename Continuation::template result
			<
				Type
			>;
		};

		template<typename Type, typename Judgement, typename Continuation = ch_symbolic_type>
		using s_judgement_type = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgement>::template symbolic_induct
		<
			cp_s_judgement_type<Continuation>
		>;

	// judgement value:

			// optimized to assume Judgement is in fact a judgement.

		// symbolic:

		template<typename Continuation, typename Inductor = pnkb_inductor_ss>
		struct cp_s_judgement_value
		{
			template<typename Type, template<Type...> class ListType, Type... Values>
			using result = typename Continuation::template result
			<
				Inductor, Type, Values...
			>;
		};

		template<typename Type, typename Judgement, typename Continuation = ch_symbolic_values>
		using s_judgement_value = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgement>::template symbolic_induct
		<
			cp_s_judgement_value<Continuation>
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_a_judgement_value
		{
			template<typename OutType, typename Type, template<Type...> class ListType, Type Value, Type... Values>
			static constexpr OutType result = Continuation::template result
			<
				OutType, Type, Value
			>;
		};

		template<typename Type, typename Judgement, typename Continuation = ch_assemblic_value>
		static constexpr Type a_judgement_value = dependent_memoization<Type>::template
		pattern_match_values_list<Judgement>::template assemblic_induct
		<
			cp_a_judgement_value<Continuation>, Type
		>;

	// dependent judgement type:

			// optimized to assume Judgement is in fact a judgement.

		// symbolic:

		template<typename Continuation>
		struct cp_s_dependent_judgement_type
		{
			template<typename Inductor, typename Type, Type... Values>
			using result = typename Continuation::template result
			<
				Type
			>;
		};

		template<typename Type, typename Judgement, typename Continuation = ch_symbolic_type>
		using s_dependent_judgement_type = typename Judgement::template
		symbolic_induct
		<
			cp_s_dependent_judgement_type<Continuation>
		>;

	// dependent judgement value:

			// optimized to assume Judgement is in fact a judgement.

		// symbolic:

		template<typename Type, typename Judgement, typename Continuation = ch_symbolic_values>
		using s_dependent_judgement_value = typename Judgement::template
		symbolic_induct
		<
			Continuation
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_a_dependent_judgement_value
		{
			template<typename OutType, typename Type, Type Value, Type... Values>
			static constexpr OutType result = Continuation::template result
			<
				OutType, Type, Value
			>;
		};

		template<typename Type, typename Judgement, typename Continuation = ch_assemblic_value>
		static constexpr Type a_dependent_judgement_value = Judgement::template
		assemblic_induct
		<
			cp_a_dependent_judgement_value<Continuation>, Type
		>;
};

