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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, alias)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, embedding)

	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, embedding)
	#include nik_assemblic_typedef(patronum, natural, kernel, function, embedding)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_stem, inductor)

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, inductor)
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

	// v map v shrink v:

		// cp fold break:

			// symbolic:

			template<typename Continuation>
			struct cp_s_v_map_v_combine_v_to_values_fold_break
			{
				template
				<
					typename Kind, template<Kind...> class ListKind,
					typename Aspect,
					typename Type, template<Type...> class ListType,

					bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
					bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
					bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
					bool (*After_Combine)(Kind),

					Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
					size_type depth, size_type count,
					Kind Instance, Aspect Moment, Type... Values
				>
				using result = typename Continuation::template result
				<
					Kind, ListKind, Instance
				>;
			};

		// cr fold:

			// symbolic:

			template<typename Continuation>
			struct cr_s_v_map_v_combine_v_fold
			{
				template
				<
					typename Kind, template<Kind...> class ListKind,
					typename Aspect,
					typename Type, template<Type...> class ListType,

					bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
					bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
					bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
					bool (*After_Combine)(Kind),

					Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
					size_type depth, size_type count,
					Kind Instance, Aspect Moment, Type... Values
				>
				using result = typename cp_s_judgment_stem_v_map_v_combine_v
				<
					ch_a_v_map_v_combine_v_to_value_is_empty,
					cp_s_v_map_v_combine_v_to_values_fold_break<Continuation>,
					cp_s_v_map_v_combine_v_apply_identity_map_then_combine
					<
						cr_s_v_map_v_combine_v_fold
					>

				>::template result
				<
					Kind, ListKind, Aspect, Type, ListType,
					Before_Depth, Before_Count, Before_Map, After_Map,
					Before_Left_Combine, Before_Right_Combine, After_Combine,
					Combine, Map, depth, count, Instance, Moment, Values...
				>;
			};

		// fold:

			// symbolic:

			template
			<
				typename Type, typename Aspect, typename Kind,
				Aspect Moment, Kind Instance,
				Kind (*Combine)(Kind, Aspect),
				typename List,

				template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
				typename Continuation = ch_s_values
			>
			using s_judgment_list_v_map_v_combine_v_fold = typename dependent_memoization<Type>::template
			pattern_match_values_list<List>::template
			s_v_map_v_combine_v_induct
			<
				cr_s_v_map_v_combine_v_fold<Continuation>, Kind, ListKind, Aspect,

				p_function_zero<bool, size_type>, p_function_zero<bool, size_type>,	// before depth, before count
				p_function_zero<bool, Type>, p_function_zero<bool, Aspect>,		// before act, after act
				p_function_zero<bool, Kind>, p_function_zero<bool, Aspect>,		// before left combine,
													// before right combine
				p_function_zero<bool, Kind>,						// after combine

				Combine, p_function_zero<Aspect, Type>,
				default_depth, default_count, Instance, Moment
			>;

		// monoid fold:

			// symbolic:

			template
			<
				typename Type, Type Instance, Type (*Monoid)(Type, Type), typename List,

				template<Type...> class ListType = dependent_memoization<Type>::template pattern_match_values,
				typename Continuation = ch_s_values
			>
			using s_judgment_list_monoid_fold = typename dependent_memoization<Type>::template
			pattern_match_values_list<List>::template
			s_v_map_v_combine_v_induct
			<
				cr_s_v_map_v_combine_v_fold<Continuation>, Type, ListType, Type,

				p_function_zero<bool, size_type>, p_function_zero<bool, size_type>,	// before depth, before count
				p_function_zero<bool, Type>, p_function_zero<bool, Type>,		// before act, after act
				p_function_zero<bool, Type>, p_function_zero<bool, Type>,		// before left combine,
													// before right combine
				p_function_zero<bool, Type>,						// after combine

				Monoid, p_function_zero<Type, Type>,
				default_depth, default_count, Instance, af_judgment_filler<Type>
			>;

	// v map t shrink v:

		// fold break:

			// assemblic:

			template<typename Continuation>
			struct cp_a_v_map_t_combine_v_to_value_fold_break
			{
				template
				<
					typename Image,
					typename Kind, template<Kind...> class ListKind,
					typename Type, template<Type...> class ListType,

					bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
					bool (*Before_Map)(Type), template<typename> class After_Map,
					bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
					bool (*After_Combine)(Kind),

					template<Kind, typename> class Combine, template<Type> class Map,
					size_type depth, size_type count,
					Kind Instance, typename Moment, Type... Values
				>
				static constexpr Image result = Continuation::template result
				<
					Image, Kind, ListKind, Instance
				>;
			};

		// cr fold:

			// assemblic:

			template<typename Continuation>
			struct cr_a_v_map_t_combine_v_fold
			{
				template
				<
					typename Image,
					typename Kind, template<Kind...> class ListKind,
					typename Type, template<Type...> class ListType,

					bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
					bool (*Before_Map)(Type), template<typename> class After_Map,
					bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
					bool (*After_Combine)(Kind),

					template<Kind, typename> class Combine, template<Type> class Map,
					size_type depth, size_type count,
					Kind Instance, typename Moment, Type... Values
				>
				static constexpr Image result = cp_a_judgment_stem_v_map_t_combine_v
				<
					ch_a_v_map_t_combine_v_to_value_is_empty,
					cp_a_v_map_t_combine_v_to_value_fold_break<Continuation>,
					cp_a_v_map_t_combine_v_apply_map
					<
						cp_a_v_map_t_combine_v_apply_combine
						<
							cr_a_v_map_t_combine_v_fold
						>
					>

				>::template result
				<
					Image, Kind, ListKind, Type, ListType,
					Before_Depth, Before_Count, Before_Map, After_Map,
					Before_Left_Combine, Before_Right_Combine, After_Combine,
					Combine, Map, depth, count, Instance, Moment, Values...
				>;
			};

		// map combine:

			// assemblic:

			template
			<
				typename Type, typename Kind,
				typename Moment, Kind Instance,
				template<Type> class Map,
				template<Kind, typename> class Combine,
				typename List,

				template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
				typename Continuation = ch_a_to_value,
				typename Image = Kind
			>
			static constexpr Image a_judgment_list_v_map_t_combine_v = dependent_memoization<Type>::template
			pattern_match_values_list<List>::template
			a_v_map_t_combine_v_induct
			<
				cr_a_v_map_t_combine_v_fold<Continuation>, Image, Kind, ListKind,

				p_function_zero<bool, size_type>, p_function_zero<bool, size_type>,	// before depth, before count
				p_function_zero<bool, Type>, s_identity,				// before act, after act
				p_function_zero<bool, Kind>, s_identity,				// before left combine,
													// before right combine
				p_function_zero<bool, Kind>,						// after combine

				Combine, Map,
				default_depth, default_count, Instance, Moment
			>;

/*
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
		struct cp_a_judgment_list_fold0
		{
			template
			<
				typename Image,
				typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,
				Kind (*Op)(Kind, Type), size_type count, Kind... Moment, Type... Values
			>
			static constexpr void (*result)() = if_then_else
			<
				bool(sizeof...(Values)), cp_p_judgment_list_display1<Continuation>, Continuation

			>::template result<Type, ListType, Display, Values...>;
		};

		template
		<
			typename Type, typename List,
			typename Continuation = ch_a_vv_v_shrink_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			Kind (*Op)(Kind, Type) = p_left_identity,
			typename Image = Kind
		>
		static constexpr Image a_judgment_list_fold = dependent_memoization<Type>::template
		pattern_match_values_list<List>::template
		a_vv_v_shrink_induct
		<
			cp_a_judgment_list_fold0<Continuation>, Image, Kind, ListKind, Op, count, Moment...
		>;
*/

	// display:

		// assemblic:

/*
		template<typename Type>
		struct dependent_display
		{
			template<Type Value>
			struct map
			{
				static constexpr void result()
				{
					printf("%lld", Value);
					printf("%s", ", ");
				}
			};

			template<Type Instance, typename Map>
			struct combine
			{
				static constexpr void let_result()
				{
					Instance();
					Map::result();
				}

				template<typename Kind>
				static constexpr Kind result = let_result;
			};
		};
*/

		template<typename Type>
		struct dependent_display
		{
			template<Type Value>
			struct map
			{
				static constexpr Type result = Value;
			};

			template<Type Instance, typename Map>
			struct combine
			{
				static constexpr void let_result()
				{
					Instance();
					printf("%lld", Map::result);
					printf("%s", ", ");
				}

				template<typename Kind>
				static constexpr Kind result = let_result;
			};
		};

		template
		<
			typename Type, typename List,

			typename Kind = void (*)(),
			Kind Instance = ch_p_void::result,
			template<Type> class Map = dependent_display<Type>::template map,
			template<Kind, typename> class Combine = dependent_display<Kind>::template combine,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Continuation = ch_a_to_value,
			typename Image = Kind
		>
		static constexpr Image a_judgment_list_display = a_judgment_list_v_map_t_combine_v
		<
			Type, Kind, filler, Instance, Map, Combine, List, ListKind, Continuation, Image
		>;

		// version 1:

/*
		template<typename Continuation>
		struct memoized_functions
		{
			template<typename Image, >
			static constexpr Image result = dependent_memoization<Type>::template
			pattern_match_values_list<List>::template
			af_v_map_t_mutate_induct
			<
				Continuation, Image, ListLabel, Op//<Type>
			>;

							Image, ListLabel, Op<Values>...
		};

		template
		<
			typename Type, typename List,

			typename Kind = void (*)(),
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Continuation = ch_a_to_value,
			typename Image = Kind
		>
		static constexpr Image a_judgment_list_display =

		template
		<
			typename Type, typename List,

			typename Kind = void (*)(),
			Kind Instance = ch_p_void::result,
			template<Type> class Map = dependent_display<Type>::template map,
			template<Kind, typename> class Combine = dependent_display<Kind>::template combine,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Continuation = ch_a_to_value,
			typename Image = Kind
		>
		static constexpr Image a_judgment_list_display = a_judgment_list_v_map_t_combine_v
		<
			Type, Kind, filler, Instance, Map, Combine, List, ListKind, Continuation, Image
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
