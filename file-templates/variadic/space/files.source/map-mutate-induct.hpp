<<<BEGIN VALUES>>>
			// fast map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using sf_map_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using sf_map_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op(Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using sf_map_mutate_induct = typename Continuation::template result	// s_types
						<
							pattern_match_types, Op<Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using s_map_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image af_map_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image af_map_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Op(Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename> class Op
					>
				static constexpr Image af_map_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Types>::result...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image a_map_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op, Values...
						>;
<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image a_map_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, Values...
						>;
<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename> class Op
					>
				static constexpr Image a_map_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op, Types...
						>;
<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
<<<END TYPES LIST>>>
