<<<BEGIN VALUES>>>
			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result		// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type, Type), Type... Args
					>
				static constexpr Image af_zip_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Args, Values)...
						>;

			// zip mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type, Type), typename List
					>
				static constexpr Image a_zip_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op, List, Values...
						>;
<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result		// s_value
						<
							Kind, ListKind, Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), Type... Args
					>
				static constexpr Image af_zip_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Op(Args, Values)...
						>;

			// zip mutate: zip, map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), typename List
					>
				static constexpr Image a_zip_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, List, Values...
						>;
<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
<<<END TYPES LIST>>>
