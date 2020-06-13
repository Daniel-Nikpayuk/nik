<<<BEGIN VALUES>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, typename Kind1,

						Kind0 (*Op)(Kind1, Type), Kind1... Args
					>
				using sf_vv_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Op(Args, Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, template<Kind0...> class ListKind0,

						typename Kind1, Kind0 (*Op)(Kind1, Type), Kind1... Args
					>
				using sf_vv_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind0, ListKind0, Op(Args, Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, typename Kind1,

						template<Kind1, typename> class Op, Kind1... Args
					>
				using sf_vt_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Kind1, Op<Args, Types>::template result<Kind1>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, template<Kind0...> class ListKind0,

						typename Kind1, template<Kind1, typename> class Op, Kind1... Args
					>
				using sf_vt_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind0, ListKind0, Kind1, Op<Args, Types>::template result<Kind1>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<typename, Type> class Op, typename... Args
					>
				using sf_vv_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						template<typename, Type> class Op, typename... Args
					>
				using sf_tv_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<typename, typename> class Op, typename... Args
					>
				using sf_tt_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						template<typename, typename> class Op, typename... Args
					>
				using sf_tt_zip_to_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind, Type> class Op, Kind... Args
					>
				using sf_vv_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						typename Kind, template<Kind, Type> class Op, Kind... Args
					>
				using sf_vv_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip value x type to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind, typename> class Op, Kind... Args
					>
				using sf_vt_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						typename Kind, template<Kind, typename> class Op, Kind... Args
					>
				using sf_vt_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename, Type> class Op, typename... Args
					>
				using sf_tv_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<typename, Type> class Op, typename... Args
					>
				using sf_tv_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip type x type to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename, typename> class Op, typename... Args
					>
				using sf_tt_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListName,

						template<typename, typename> class Op, typename... Args
					>
				using sf_tt_zip_to_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListName, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, typename Kind1,

						typename List, Kind0 (*Op)(Type, Kind1)
					>
				using s_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Type, ListType, Kind1, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, template<Kind0...> class ListKind0,

						typename Kind1, typename List,

						Kind0 (*Op)(Type, Kind1)
					>
				using s_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, Type, ListType, Kind1, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, typename Kind1,

						typename List, template<typename, Kind1> class Op
					>
				using s_tv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							ListName, Kind1, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind0, template<Kind0...> class ListKind0,

						typename Kind1, typename List,

						template<typename, Kind1> class Op
					>
				using s_tv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, ListName, Kind1, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List,

						template<Type, typename> class Op
					>
				using s_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, ListType, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename List, template<Type, typename> class Op
					>
				using s_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List,

						template<typename, typename> class Op
					>
				using s_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							ListName, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename List, template<typename, typename> class Op
					>
				using s_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, ListName, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List, template<Type, Kind> class Op
					>
				using s_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type, ListType, Kind, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename Kind, typename List, template<Type, Kind> class Op
					>
				using s_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, Kind, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List, template<typename, Kind> class Op
					>
				using s_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types,
							ListName, Kind, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename Kind, typename List, template<typename, Kind> class Op
					>
				using s_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, Kind, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename List, template<Type, typename> class Op
					>
				using s_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type, ListType, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename List, template<Type, typename> class Op
					>
				using s_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename List, template<typename, typename> class Op
					>
				using s_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types,
							ListName, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename List, template<typename, typename> class Op
					>
				using s_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, typename Kind1,

						Kind0 (*Op)(Kind1, Type), Kind1... Args
					>
				static constexpr Image af_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Op(Args, Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, template<Kind0...> class ListKind0,

						Image, typename Kind1, Kind0 (*Op)(Kind1, Type), Kind1... Args
					>
				static constexpr Image af_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, Op(Args, Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, typename Kind1,

						template<Kind1, typename> class Op, Kind1... Args
					Image, >
				static constexpr Image af_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Kind1, Op<Args, Types>::template result<Kind1>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, template<Kind0...> class ListKind0,

						Image, typename Kind1, template<Kind1, typename> class Op, Kind1... Args
					>
				static constexpr Image af_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, Kind1, Op<Args, Types>::template result<Kind1>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename, Type> class Op, typename... Args
					Image, >
				static constexpr Image af_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Image, template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename, typename> class Op, typename... Args
					Image, >
				static constexpr Image af_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Image, template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind, Type> class Op, Kind... Args
					Image, >
				static constexpr Image af_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						Image, typename Kind, template<Kind, Type> class Op, Kind... Args
					>
				static constexpr Image af_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip value x type to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind, typename> class Op, Kind... Args
					Image, >
				static constexpr Image af_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						Image, typename Kind, template<Kind, typename> class Op, Kind... Args
					>
				static constexpr Image af_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename, Type> class Op, typename... Args
					Image, >
				static constexpr Image af_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						Image, template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip type x type to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename, typename> class Op, typename... Args
					Image, >
				static constexpr Image af_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListName,

						Image, template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListName, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, typename Kind1,

						typename List, Kind0 (*Op)(Type, Kind1)
					>
				static constexpr Image a_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Image, Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							Type, ListType, Kind1, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, template<Kind0...> class ListKind0,

						Image, typename Kind1, typename List,

						Kind0 (*Op)(Type, Kind1)
					>
				static constexpr Image a_vv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, Type, ListType, Kind1, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, typename Kind1,

						typename List, template<typename, Kind1> class Op
					Image, >
				static constexpr Image a_tv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0,
							dependent_memoization<Kind0>::template pattern_match_values,
							ListName, Kind1, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind0, template<Kind0...> class ListKind0,

						Image, typename Kind1, typename List,

						template<typename, Kind1> class Op
					>
				static constexpr Image a_tv_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind0, ListKind0, ListName, Kind1, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List,

						template<Type, typename> class Op
					Image, >
				static constexpr Image a_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, ListType, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Image, typename List, template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List,

						template<typename, typename> class Op
					Image, >
				static constexpr Image a_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							ListName, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Image, typename List, template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_to_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, ListName, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List, template<Type, Kind> class Op
					Image, >
				static constexpr Image a_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type, ListType, Kind, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						Image, typename Kind, typename List, template<Type, Kind> class Op
					>
				static constexpr Image a_vv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, Kind, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List, template<typename, Kind> class Op
					Image, >
				static constexpr Image a_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types,
							ListName, Kind, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						Image, typename Kind, typename List, template<typename, Kind> class Op
					>
				static constexpr Image a_tv_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, Kind, List, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename List, template<Type, typename> class Op
					Image, >
				static constexpr Image a_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type, ListType, List, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						Image, typename List, template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, List, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename List, template<typename, typename> class Op
					Image, >
				static constexpr Image a_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types,
							ListName, List, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						Image, typename List, template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_to_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, List, Op, Types...
						>;

<<<END TYPES LIST>>>
