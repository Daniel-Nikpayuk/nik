<<<BEGIN VALUES>>>
			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, pattern_match_values, List, Args..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, pattern_match_values, List, Args..., Values...
						>;
<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, ListType, List, Args..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image, // template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, ListType, List, Args..., Values...
						>;
<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						typename List, typename... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_types
						<
							pattern_match_types, List, Args..., Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, typename... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, filler, pattern_match_types, List, Args..., Types...
						>;
<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
<<<END TYPES LIST>>>
