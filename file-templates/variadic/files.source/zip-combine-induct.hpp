<<<BEGIN VALUES>>>
			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_zip_combine_induct = typename Continuation::template result		// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op_Cond, count, List0, List1, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_zip_combine_induct = typename Continuation::template result		// ?
						<
							Kind, ListKind, Type, ListType, Op_Cond, count, List0, List1, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

