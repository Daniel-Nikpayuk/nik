<<<BEGIN VALUES>>>
			// fast value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using sf_v_map_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using sf_v_map_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op(Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<typename> class Op
					>
				using sf_t_map_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				using sf_t_map_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op<Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<Type> class Op
					>
				using sf_v_map_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							independent_memoization::template pattern_match_types,
							Op<Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<Type> class Op
					>
				using sf_v_map_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using sf_t_map_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							pattern_match_types,
							Op<Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<typename> class Op
					>
				using sf_t_map_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using s_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, ListType, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using s_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using s_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, ListType, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<typename> class Op
					>
				using s_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, ListType, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<Type> class Op
					>
				using s_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type, ListType, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<Type> class Op
					>
				using s_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, Type, ListType, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using s_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, ListType, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<typename> class Op
					>
				using s_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, ListType, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image af_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image af_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind, ListKind, Op(Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename> class Op
					>
				static constexpr Image af_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				static constexpr Image af_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind, ListKind, Op<Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<Type> class Op
					>
				static constexpr Image af_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Op<Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						template<Type> class Op
					>
				static constexpr Image af_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListName, Op<Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename> class Op
					>
				static constexpr Image af_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, pattern_match_types,
							Op<Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						template<typename> class Op
					>
				static constexpr Image af_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListName, Op<Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image a_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, ListType, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image a_v_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename> class Op
					>
				static constexpr Image a_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, pattern_match_types, ListType, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						template<typename> class Op
					>
				static constexpr Image a_t_map_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListName, ListType, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<Type> class Op
					>
				static constexpr Image a_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Type, ListType, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						template<Type> class Op
					>
				static constexpr Image a_v_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListName, Type, ListType, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename> class Op
					>
				static constexpr Image a_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, pattern_match_types, ListType, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						template<typename> class Op
					>
				static constexpr Image a_t_map_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListName, ListType, Op, Types...
						>;

<<<END TYPES LIST>>>
