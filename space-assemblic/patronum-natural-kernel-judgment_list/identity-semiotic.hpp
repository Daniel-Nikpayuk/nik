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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, alias)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// continuation passers:

		template<typename Continuation>
		struct cp_a_values_to_value_is_empty
		{
			template<typename Image, typename Type, template<Type...> class ListType, Type... Values>
			static constexpr Image result = Continuation::template result
			<
				Image, (Image) !bool(sizeof...(Values))
			>;
		};

	// is empty:

		// symbolic:

		// assemblic

		using ch_a_v_map_v_combine_v_to_value_is_empty = typename pnk_builtin_ss::inductor::template
		cp_a_v_map_v_combine_v_to_values
		<
			cp_a_values_to_value_is_empty<ch_a_value>
		>;

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_judgment_list_empty = typename dependent_memoization<Type>::template pattern_match_values_list<Exp>::template
		s_match_induct
		<
			Continuation, Kind, ListKind
		>;
*/

		// assemblic:

		template<typename Continuation>
		using cp_a_grow_to_value_is_empty = typename pnk_builtin_ss::inductor::template cp_a_grow_to_values
		<
			cp_a_values_to_value_is_empty<Continuation>
		>;

		template
		<
			typename Type, typename List,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_judgment_list_is_empty = dependent_memoization<Type>::template
		pattern_match_values_list<List>::template
		a_front_grow_induct
		<
			cp_a_grow_to_value_is_empty<Continuation>, Image, filler
		>;

		// procedural:

/*
		template<typename Type>
		static constexpr Type p_judgment_list_(Type v) { return v; }
*/

/*
	// is judgment list:

		// symbolic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_judgment_list = typename pattern_match_judgment_list_<Type, Exp>::template
		s_match_induct
		<
			Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_judgment_list = pattern_match_judgment_list_<Type, Exp>::template
		a_match_induct
		<
			Continuation, Image
		>;

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_list_(Type v) { return v; }
*/
};
