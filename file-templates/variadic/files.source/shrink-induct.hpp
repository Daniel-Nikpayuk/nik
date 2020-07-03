<<<BEGIN VALUES>>>
			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				using s_shrink_induct = typename Continuation::template result		// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op_Cond, count, Moment..., Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,
						typename Moment,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Act)(Type), bool (*After_Act)(Moment),
						bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Moment),
						bool (*After_Combine)(Kind),

						Kind (*Combine)(Kind, Moment), Moment (*Act)(Type),
						size_type depth, size_type count,
						Kind Instance, Moment Snapshot
					>
				using s_v_map_v_fold_v_shrink_induct = typename Continuation::template result		// ?
						<
							Kind, ListKind, Moment, Type, ListType,

							Before_Depth, Before_Count, Before_Act, After_Act,
							Before_Left_Combine, Before_Right_Combine, After_Combine,

							Combine, Act, depth, count, Instance, Snapshot, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES LIST>>>
			// value x value to value shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Kind, Type), size_type count, Kind... Moment
					>
				static constexpr Image a_vv_v_shrink_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, count, Moment..., Values...
						>;

<<<END VALUES LIST>>>

