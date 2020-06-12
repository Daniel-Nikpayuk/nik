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

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				static constexpr Image a_shrink_induct = Continuation::template result	// ?
						<
							Image, Kind,
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

						typename Op_Cond, size_type count, Kind... Moment
					>
				using s_shrink_induct = typename Continuation::template result		// ?
						<
							Kind, ListKind, Type, ListType, Op_Cond, count, Moment..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Op_Cond, size_type count, Kind... Moment
					>
				static constexpr Image a_shrink_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op_Cond, count, Moment..., Values...
						>;
<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
<<<END TYPES LIST>>>
