<<<BEGIN VALUES>>>
			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, pattern_match_values, List, Values..., Args...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, ListType, List, Values..., Args...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_types
						<
							pattern_match_types, List, Types..., Args...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_types
						<
							ListName, List, Types..., Args...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// back grow: multipush, push, multiunite, unite.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, pattern_match_values, List, Values..., Args...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// back grow: multipush, push, multiunite, unite.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, ListType, List, Values..., Args...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// back grow: multipush, push, multiunite, unite.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, List, Types..., Args...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// back grow: multipush, push, multiunite, unite.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result	// ?
						<
							Image, ListName, List, Types..., Args...
						>;

<<<END TYPES LIST>>>
