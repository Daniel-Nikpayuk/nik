<<<BEGIN FALSE>>>
			// match: id.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind
					>
				using s_match_induct = typename Continuation::template result		// s_match_to_values
						<
							Kind, ListKind, bool, false
						>;

<<<END FALSE>>>
<<<BEGIN TRUE>>>
			// match: id.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind
					>
				using s_match_induct = typename Continuation::template result		// s_match_to_values
						<
							Kind, ListKind, bool, true
						>;

<<<END TRUE>>>

/***********************************************************************************************************************/

<<<BEGIN FALSE>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result	// a_match_to_value
						<
							Image, bool, false
						>;
<<<END FALSE>>>
<<<BEGIN TRUE>>>
				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result	// a_match_to_value
						<
							Image, bool, true
						>;
<<<END TRUE>>>
