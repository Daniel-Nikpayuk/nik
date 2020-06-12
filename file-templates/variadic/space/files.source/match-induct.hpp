<<<BEGIN FALSE>>>
			// match: id.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, template<Kind0...> class ListKind0
					>
				using s_match_induct = typename Continuation::template result		// s_match_to_values
						<
							Kind0, ListKind0, bool, false
						>;

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
