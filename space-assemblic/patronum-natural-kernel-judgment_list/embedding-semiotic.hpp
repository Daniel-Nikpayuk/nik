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

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, navigator)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, identity)

	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

	// length:

		// symbolic:

		template<typename Continuation>
		struct cp_sf_grow_to_values_length
		{
			template<typename Type, template<Type...> class ListType, typename _Drop_, Type... Values>
			using result = typename Continuation::template result
			<
				Type, ListType, (Type) sizeof...(Values)
			>;
		};

		// assemblic:

		template<typename Continuation>
		using cp_af_grow_to_value_length = typename independent_memoization::template cp_af_grow_to_value_length<Continuation>;

	// zip:

		// symbolic:

		template<typename Continuation>
		using cp_sf_values_list_zip_induct = typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>;

		// assemblic:

		template<typename Continuation>
		using cp_af_values_list_zip_induct = typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>;

	// :

		// symbolic:

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_grow_to_values
		>
		using s_judgment_list_ = typename pattern_match_judgment_list_<Type, Exp>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;
*/

		// assemblic:

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_list_ = pattern_match_judgment_list_<Type, Exp>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;
*/

		// procedural:

		template<typename Continuation>
		struct cp_p_judgment_list_display1
		{
			template<typename Type, template<Type...> class ListType, void (*Display)(Type), Type Value, Type... Values>
			static constexpr void result()
			{
				Display(Value);
				if (bool(sizeof...(Values))) printf("%s", ", ");
				cp_p_judgment_list_display0<Continuation>::template result<Type, ListType, Display, Values...>();
			}
		};

		template<typename Continuation>
		struct cp_p_judgment_list_display0
		{
			template<typename Type, template<Type...> class ListType, void (*Display)(Type), Type... Values>
			static constexpr void (*result)() = if_then_else
			<
				bool(sizeof...(Values)), cp_p_judgment_list_display1<Continuation>, Continuation

			>::template result<Type, ListType, Display, Values...>;
		};

		template<typename Type, void (*Display)(Type), typename List, typename Continuation = ch_p_v_map_void_mutate_to_void>
		static constexpr void p_judgment_list_display()
		{
			dependent_memoization<Type>::template pattern_match_values_list<List>::template
			p_v_map_void_mutate_induct
			<
				cp_p_judgment_list_display0<Continuation>, Display

			>();
		}
};
