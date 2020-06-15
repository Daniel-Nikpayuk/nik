<<<BEGIN VALUES>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Type1,

						Kind (*Op)(Type1, Type), Type1... Args
					>
				using sf_vv_zip_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Args, Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename Type1, Kind (*Op)(Type1, Type), Type1... Args
					>
				using sf_vv_zip_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op(Args, Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Type1,

						template<Type1, typename> class Op, Type1... Args
					>
				using sf_vt_zip_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				using sf_vt_zip_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op<Args, Types>::template result<Kind>...
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
				using sf_tv_zip_v_mutate_induct = typename Continuation::template result	// s_values
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
				using sf_tv_zip_v_mutate_induct = typename Continuation::template result	// s_values
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
				using sf_tt_zip_v_mutate_induct = typename Continuation::template result	// s_values
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
				using sf_tt_zip_v_mutate_induct = typename Continuation::template result	// s_values
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

						typename Type1, template<Type1, Type> class Op, Type1... Args
					>
				using sf_vv_zip_t_mutate_induct = typename Continuation::template result	// s_types
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

						template<typename...> class ListLabel,

						typename Type1, template<Type1, Type> class Op, Type1... Args
					>
				using sf_vv_zip_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip value x type to type mutate: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				using sf_vt_zip_t_mutate_induct = typename Continuation::template result	// s_types
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

						template<typename...> class ListLabel,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				using sf_vt_zip_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Args, Types>...
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
				using sf_tv_zip_t_mutate_induct = typename Continuation::template result	// s_types
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

						template<typename...> class ListLabel,

						template<typename, Type> class Op, typename... Args
					>
				using sf_tv_zip_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Args, Values>...
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
				using sf_tt_zip_t_mutate_induct = typename Continuation::template result	// s_types
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

						template<typename...> class ListLabel,

						template<typename, typename> class Op, typename... Args
					>
				using sf_tt_zip_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Args, Types>...
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

						typename Kind, typename Type2,

						typename List2, Kind (*Op)(Type, Type2)
					>
				using s_vv_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Type2, List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename Type2, typename List2,

						Kind (*Op)(Type, Type2)
					>
				using s_vv_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, Type2, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Type2,

						typename List2, template<typename, Type2> class Op
					>
				using s_tv_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types,
							Type2, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename Type2, typename List2,

						template<typename, Type2> class Op
					>
				using s_tv_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, ListName, Type2, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List2,

						template<Type, typename> class Op
					>
				using s_vt_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename List2, template<Type, typename> class Op
					>
				using s_vt_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename List2,

						template<typename, typename> class Op
					>
				using s_tt_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types,
							List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to value mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						typename List2, template<typename, typename> class Op
					>
				using s_tt_zip_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, ListName, List2, Op, Types...
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

						typename Type2, typename List2, template<Type, Type2> class Op
					>
				using s_vv_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Type2, List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename Type2, typename List2, template<Type, Type2> class Op
					>
				using s_vv_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, Type2, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Type2, typename List2, template<typename, Type2> class Op
					>
				using s_tv_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, pattern_match_types, Type2, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename Type2, typename List2, template<typename, Type2> class Op
					>
				using s_tv_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, Type2, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename List2, template<Type, typename> class Op
					>
				using s_vt_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename List2, template<Type, typename> class Op
					>
				using s_vt_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename List2, template<typename, typename> class Op
					>
				using s_tt_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, pattern_match_types, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to type mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						typename List2, template<typename, typename> class Op
					>
				using s_tt_zip_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Type1,

						Kind (*Op)(Type1, Type), Type1... Args
					>
				static constexpr Image af_vv_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Args, Values)...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Type1, Kind (*Op)(Type1, Type), Type1... Args
					>
				static constexpr Image af_vv_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op(Args, Values)...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Type1,

						template<Type1, typename> class Op, Type1... Args
					>
				static constexpr Image af_vt_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				static constexpr Image af_vt_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op<Args, Values>::template result<Kind>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to value mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op<Args, Types>::template result<Kind>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Type1, template<Type1, Type> class Op, Type1... Args
					>
				static constexpr Image af_vv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast value x value zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename Type1, template<Type1, Type> class Op, Type1... Args
					>
				static constexpr Image af_vv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip value x type to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				static constexpr Image af_vt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast value x type zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename Type1, template<Type1, typename> class Op, Type1... Args
					>
				static constexpr Image af_vt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Op<Args, Values>...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// fast type x value zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<typename, Type> class Op, typename... Args
					>
				static constexpr Image af_tv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Args, Values>...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// fast zip type x type to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, Op<Args, Types>...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// fast type x type zip to type mutate: no signature, but required to implement zip (signature).

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<typename, typename> class Op, typename... Args
					>
				static constexpr Image af_tt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Args, Types>...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Type2,

						typename List2, Kind (*Op)(Type, Type2)
					>
				static constexpr Image a_vv_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Type2, List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Type2, typename List2,

						Kind (*Op)(Type, Type2)
					>
				static constexpr Image a_vv_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Type2, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Type2,

						typename List2, template<typename, Type2> class Op
					>
				static constexpr Image a_tv_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types,
							Type2, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Type2, typename List2,

						template<typename, Type2> class Op
					>
				static constexpr Image a_tv_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, ListName, Type2, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List2,

						template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename List2, template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename List2,

						template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types,
							List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to value mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename List2, template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, ListName, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/
/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x value zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Type2, typename List2, template<Type, Type2> class Op
					>
				static constexpr Image a_vv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Type2, List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x value zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename Type2, typename List2, template<Type, Type2> class Op
					>
				static constexpr Image a_vv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Type, ListType, Type2, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x value zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Type2, typename List2, template<typename, Type2> class Op
					>
				static constexpr Image a_tv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, pattern_match_types, Type2, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x value zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename Type2, typename List2, template<typename, Type2> class Op
					>
				static constexpr Image a_tv_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, ListName, Type2, List2, Op, Types...
						>;

<<<END TYPES LIST>>>

/***********************************************************************************************************************/

<<<BEGIN VALUES>>>
			// value x type zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List2, template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							List2, Op, Values...
						>;

<<<END VALUES>>>
<<<BEGIN VALUES LIST>>>
			// value x type zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename List2, template<Type, typename> class Op
					>
				static constexpr Image a_vt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Type, ListType, List2, Op, Values...
						>;

<<<END VALUES LIST>>>
<<<BEGIN TYPES>>>
			// type x type zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List2, template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, pattern_match_types, List2, Op, Types...
						>;

<<<END TYPES>>>
<<<BEGIN TYPES LIST>>>
			// type x type zip to type mutate: zip.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						typename List2, template<typename, typename> class Op
					>
				static constexpr Image a_tt_zip_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, ListName, List2, Op, Types...
						>;

<<<END TYPES LIST>>>
