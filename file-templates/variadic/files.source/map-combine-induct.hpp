<<<BEGIN VALUES>>>
			// map_combine: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Op_Cond, size_type count, Kind... Aspect
					>
				using s_map_combine_induct = typename Continuation::template result		// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op_Cond, count, Aspect..., Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value map value combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,
						typename Aspect,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
						bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
						bool (*After_Combine)(Kind),

						Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
						size_type depth, size_type count,
						Kind Instance, Aspect Moment
					>
				using s_v_map_v_combine_v_induct = typename Continuation::template result		// ?
						<
							Kind, ListKind, Aspect, Type, ListType,
							Before_Depth, Before_Count, Before_Map, After_Map,
							Before_Left_Combine, Before_Right_Combine, After_Combine,
							Combine, Map, depth, count, Instance, Moment, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES LIST>>>
			// value map value combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Kind, Type), size_type count, Kind... Aspect
					>
				static constexpr Image a_v_map_v_combine_v_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, count, Aspect..., Values...
						>;

<<<END VALUES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES LIST>>>
			// value map type combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), template<typename> class After_Map,
						bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
						bool (*After_Combine)(Kind),

						template<Kind, typename> class Combine, template<Type> class Map,
						size_type depth, size_type count,
						Kind Instance, typename Moment
					>
				static constexpr Image a_v_map_t_combine_v_induct = Continuation::template result		// ?
						<
							Image, Kind, ListKind, Type, ListType,
							Before_Depth, Before_Count, Before_Map, After_Map,
							Before_Left_Combine, Before_Right_Combine, After_Combine,
							Combine, Map, depth, count, Instance, Moment, Values...
						>;

<<<END VALUES LIST>>>
