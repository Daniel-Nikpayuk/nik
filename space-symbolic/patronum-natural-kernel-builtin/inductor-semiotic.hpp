/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik.
**
** nik is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** nik is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik. If not, see
** <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

	// Old note (bug seems to be fixed now), keeping it for reference:

	// For whatever reason if I put a template after Continuation
	// in the following it produces an internal compiler error.

struct inductor
{
	// continuation passers:

		// symbolic:

			// type:

				// grow:

				template<typename Continuation>
				struct cp_s_grow_to_types
				{
					template<template<typename...> class ListName, typename _Drop_, typename... Types>
					using result = typename Continuation::template result
					<
						ListName, Types...
					>;
				};

				using ch_s_grow_to_type			= cp_s_grow_to_types<ch_s_types_to_type>;
				using ch_s_grow_to_types		= cp_s_grow_to_types<ch_s_types>;

				// map mutate:

				template<typename Continuation>
				struct cp_s_t_map_t_mutate_to_grow
				{
					template
					<
						template<typename...> class ListLabel,
						template<typename...> class ListName,
						template<typename> class Op, typename... Types
					>
					using result = typename Continuation::template result
					<
						ListLabel, filler, Types...
					>;
				};

				using ch_s_t_map_t_mutate_to_type	= cp_s_t_map_t_mutate_to_grow<ch_s_grow_to_type>;
				using ch_s_t_map_t_mutate_to_types	= cp_s_t_map_t_mutate_to_grow<ch_s_grow_to_types>;

				// zip mutate:

				template<typename Continuation>
				struct cp_s_tt_zip_t_mutate_to_grow
				{
					template
					<
						template<typename...> class ListLabel,
						template<typename...> class ListName,
						typename List2, template<typename, typename> class Op, typename... Types
					>
					using result = typename Continuation::template result
					<
						ListLabel, filler, Types...
					>;
				};

				using ch_s_tt_zip_t_mutate_to_type	= cp_s_tt_zip_t_mutate_to_grow<ch_s_grow_to_type>;
				using ch_s_tt_zip_t_mutate_to_types	= cp_s_tt_zip_t_mutate_to_grow<ch_s_grow_to_types>;

			// value:

				// match:

				template<typename Continuation>
				struct cp_s_match_to_values
				{
					template<typename Kind, template<Kind...> class ListKind, typename Type, Type Value>
					using result = typename Continuation::template result
					<
						Kind, ListKind, (Kind) Value
					>;
				};

				using ch_s_match_to_values		= cp_s_match_to_values<ch_s_values>;
				using ch_s_match_to_value		= cp_s_match_to_values<ch_s_values>;	// library default.

				// grow:

				template<typename Continuation>
				struct cp_s_grow_to_values
				{
					template<typename Type, template<Type...> class ListType, typename _Drop_, Type... Values>
					using result = typename Continuation::template result
					<
						Type, ListType, Values...
					>;
				};

				using ch_s_grow_to_values		= cp_s_grow_to_values<ch_s_values>;

				// map mutate:

				template<typename Continuation>
				struct cp_s_v_map_v_mutate_to_grow
				{
					template
					<
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,
						Kind (*Op)(Type), Type... Values
					>
					using result = typename Continuation::template result
					<
						Type, ListType, filler, Values...
					>;
				};

				using ch_s_v_map_v_mutate_to_values	= cp_s_v_map_v_mutate_to_grow<ch_s_grow_to_values>;

				// zip mutate:

				template<typename Continuation>
				struct cp_s_vv_zip_v_mutate_to_grow
				{
					template
					<
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,
						typename Type2, typename List2, Kind (*Op)(Type, Type2), Type... Values
					>
					using result = typename Continuation::template result
					<
						Type, ListType, filler, Values...
					>;
				};

				using ch_s_vv_zip_v_mutate_to_values	= cp_s_vv_zip_v_mutate_to_grow<ch_s_grow_to_values>;

				// map combine:

				template<typename Continuation>
				struct cp_s_v_map_v_combine_v_to_values
				{
					template
					<
						typename Kind, template<Kind...> class ListKind,
						typename Aspect,
						typename Type, template<Type...> class ListType,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
						bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
						bool (*After_Combine)(Kind),

						Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
						size_type depth, size_type count,
						Kind Instance, Aspect Moment, Type... Values
					>
					using result = typename Continuation::template result
					<
						Type, ListType, Values...
					>;
				};

				template<typename Continuation>
				struct cp_s_v_map_t_combine_v_to_values
				{
					template
					<
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), template<typename> class After_Map,
						bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
						bool (*After_Combine)(Kind),

						template<Kind, typename> class Combine, template<Type> class Map,
						size_type depth, size_type count,
						Kind Instance, typename Moment, Type... Values
					>
					using result = typename Continuation::template result
					<
						Type, ListType, Values...
					>;
				};

		// assemblic:

			// value:

				// match:

				template<typename Continuation>
				struct cp_a_match_to_value
				{
					template<typename Image, typename Kind, template<Kind...> class ListKind, typename Type, Type Value>
					static constexpr Image result = Continuation::template result
					<
						Image, (Image) Value
					>;
				};

				using ch_a_match_to_value		= cp_a_match_to_value<ch_a_value>;

				// grow:

				template<typename Continuation>
				struct cp_a_grow_to_values
				{
					template
					<
						typename Image, typename Type,
							template<Type...> class ListType, typename _Drop_, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, Type, ListType, Values...
					>;
				};

				using ch_a_grow_to_value		= cp_a_grow_to_values<ch_a_values_to_value>;

				// map mutate:

				template<typename Continuation>
				struct cp_a_v_map_v_mutate_to_value
				{
					template
					<
						typename Image,
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,
						Kind (*Op)(Type), Type Value, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, (Image) Value
					>;
				};

				using ch_a_v_map_v_mutate_to_value	= cp_a_v_map_v_mutate_to_value<ch_a_value>;

				// zip mutate:

				template<typename Continuation>
				struct cp_a_vv_zip_v_mutate_to_value
				{
					template
					<
						typename Image,
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,
						typename Type2, typename List2, Kind (*Op)(Type, Type2), Type Value, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, (Image) Value
					>;
				};

				using ch_a_vv_zip_v_mutate_to_value	= cp_a_vv_zip_v_mutate_to_value<ch_a_value>;

				// map combine:

				template<typename Continuation>
				struct cp_a_v_map_v_combine_v_to_values
				{
					template
					<
						typename Image,
						typename Kind, template<Kind...> class ListKind,
						typename Aspect,
						typename Type, template<Type...> class ListType,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
						bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
						bool (*After_Combine)(Kind),

						Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
						size_type depth, size_type count,
						Kind Instance, Aspect Moment, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, Type, ListType, Values...
					>;
				};

				template<typename Continuation>
				struct cp_a_v_map_t_combine_v_to_values
				{
					template
					<
						typename Image,
						typename Kind, template<Kind...> class ListKind,
						typename Type, template<Type...> class ListType,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), template<typename> class After_Map,
						bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
						bool (*After_Combine)(Kind),

						template<Kind, typename> class Combine, template<Type> class Map,
						size_type depth, size_type count,
						Kind Instance, typename Moment, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, Type, ListType, Values...
					>;
				};

		// procedural:

			// void:

				// map:

				template<typename Continuation>
				struct cp_p_v_map_void_mutate_to_void
				{
					template<typename Type, template<Type...> class ListType, void (*Display)(Type), Type... Values>
					static constexpr void (*result)() = Continuation::result;
				};

				using ch_p_v_map_void_mutate_to_void	= cp_p_v_map_void_mutate_to_void<ch_p_void>;

	// dependent memoization:

		// The expense of the extra dependent alias is justified in contexts where Type, Kind, Image bindings
		// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		// Policy is to pass predefined info such as Kind beforehand, which otherwise could be
		// determined by use of *auto*. Assumption is it's faster not having to figure out the type info.

		// match aliases are required to have the same grammatical input form regardless of how a given
		// templated struct is partially specialized, but there is no such requirement for induct aliases.

		// match aliases default to boolean output, but we privilege minimal memoization, as well as
		// make use of continuations, and so we also provide a generic Kind output to support these.

	struct independent_memoization;		// dependency

	template<typename Type>
	struct dependent_memoization
	{
		// type:

		template<typename Exp, typename = filler>
		struct pattern_match_type
		{
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

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) false
						>;

			// induct: judgment, pair, function

				// symbolic:

				// assemblic:
		};

		template<typename Filler>
		struct pattern_match_type<Type, Filler>
		{
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
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) true
						>;

			// induct: judgment, pair, function

				// symbolic:

				// assemblic:
		};

		// values:

			// The following template pattern matcher is only here as an optimization to minimize
			// memoizations, otherwise it narratively belongs with its respective judgment module.

		template<auto... Values>
		struct pattern_match_values
		{
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

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) false
						>;
		};

		template<Type... Values>
		struct pattern_match_values<Values...>
		{
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
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) true
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, pattern_match_values, List, Args..., Values...
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, pattern_match_values, List, Args..., Values...
						>;

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

			// fast value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using sf_v_map_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

			// fast value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<Type> class Op
					>
				using sf_v_map_t_mutate_induct = typename Continuation::template result	// s_types
						<
							independent_memoization::template pattern_match_types,
							Op<Values>...
						>;

			// value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, Kind (*Op)(Type)
					>
				using s_v_map_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Op, Values...
						>;

			// value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<Type> class Op
					>
				using s_v_map_t_mutate_induct = typename Continuation::template result	// ?
						<
							independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Op, Values...
						>;

			// fast value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image af_v_map_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op(Values)...
						>;

			// fast value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<Type> class Op
					>
				static constexpr Image af_v_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Op<Values>...
						>;

			// value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image a_v_map_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Op, Values...
						>;

			// value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<Type> class Op
					>
				static constexpr Image a_v_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, independent_memoization::template pattern_match_types,
							Type,
							dependent_memoization<Type>::template pattern_match_values,
							Op, Values...
						>;

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

			// map_combine: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, typename Op_Cond, size_type count, Kind... Aspect
					>
				using s_map_combine_induct = typename Continuation::template result		// ?
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Type, Op_Cond, count, Aspect..., Values...
						>;

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
		};

		// list:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<typename>
		struct pattern_match_values_list
		{
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

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) false
						>;
		};

		template<template<Type...> class ListType, Type... Values>
		struct pattern_match_values_list<ListType<Values...>>
		{
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
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) true
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, ListType, List, Args..., Values...
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// typename Type, template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// a_grow_to_value
						<
							Image, Type, ListType, List, Args..., Values...
						>;

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

			// fast value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using sf_v_map_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op(Values)...
						>;

			// fast value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						template<Type> class Op
					>
				using sf_v_map_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Values>...
						>;

			// value map to value mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using s_v_map_v_mutate_induct = typename Continuation::template result	// ?
						<
							Kind, ListKind, Type, ListType, Op, Values...
						>;

			// value map to type mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						template<Type> class Op
					>
				using s_v_map_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, Type, ListType, Op, Values...
						>;

			// fast value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image af_v_map_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op(Values)...
						>;

			// fast value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<Type> class Op
					>
				static constexpr Image af_v_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Values>...
						>;

			// value map to value mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				static constexpr Image a_v_map_v_mutate_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, Values...
						>;

			// value map to type mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<Type> class Op
					>
				static constexpr Image a_v_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Type, ListType, Op, Values...
						>;

			// type map to void mutate: map, display.

				// procedural:

					template
					<
						typename Continuation,

						void (*Op)(Type)
					>
				static constexpr void (*p_v_map_void_mutate_induct)() = Continuation::template result
							<
								Type, ListType, Op, Values...
							>;

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

			// value map value combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,
						typename Aspect,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
						bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
						bool (*After_Combine)(Kind),

						Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
						size_type depth, size_type count,
						Kind Instance, Aspect Moment
					>
				using s_v_map_v_combine_v_induct = typename Continuation::template result		// ?
						<
							Kind, ListKind, Aspect, Type, ListType,
							Before_Depth, Before_Count, Before_Map, After_Map,
							Before_Left_Combine, Before_Right_Combine, After_Combine,
							Combine, Map, depth, count, Instance, Moment, Values...
						>;

			// value map value combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Kind, Type), size_type count, Kind... Aspect
					>
				static constexpr Image a_v_map_v_combine_v_induct = Continuation::template result	// ?
						<
							Image, Kind, ListKind, Type, ListType, Op, count, Aspect..., Values...
						>;

			// value map type combine value: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type), template<typename> class After_Map,
						bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
						bool (*After_Combine)(Kind),

						template<Kind, typename> class Combine, template<Type> class Map,
						size_type depth, size_type count,
						Kind Instance, typename Moment
					>
				static constexpr Image a_v_map_t_combine_v_induct = Continuation::template result		// ?
						<
							Image, Kind, ListKind, Type, ListType,
							Before_Depth, Before_Count, Before_Map, After_Map,
							Before_Left_Combine, Before_Right_Combine, After_Combine,
							Combine, Map, depth, count, Instance, Moment, Values...
						>;

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
		};
	};

	// independent memoization:

		// The expense of the extra dependent alias is justified in contexts where Type, Kind, Image bindings
		// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		// Policy is to pass predefined info such as Kind beforehand, which otherwise could be
		// determined by use of *auto*. Assumption is it's faster not having to figure out the type info.

		// match aliases are required to have the same grammatical input form regardless of how a given
		// templated struct is partially specialized, but there is no such requirement for induct aliases.

		// match aliases default to boolean output, but we privilege minimal memoization, as well as
		// make use of continuations, and so we also provide a generic Kind output to support these.

	struct independent_memoization
	{
		// s_front_grow_induct

		template<typename, typename = filler>
		struct pattern_match_s_front_grow_induct
		{
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

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) false
						>;
		};

		template<typename Struct>
		struct pattern_match_s_front_grow_induct<Struct, sfinae_try<Struct::template s_front_grow_induct>>
		{
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
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) true
						>;
		};

		// type:

		template<typename... Types>
		struct pattern_match_types
		{
			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_types
						<
							pattern_match_types, List, Args..., Types...
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, List, Args..., Types...
						>;

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

			// fast type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<typename> class Op
					>
				using sf_t_map_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Types>::template result<Kind>...
						>;

			// fast type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using sf_t_map_t_mutate_induct = typename Continuation::template result	// s_types
						<
							pattern_match_types, Op<Types>...
						>;

			// type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<typename> class Op
					>
				using s_t_map_v_mutate_induct = typename Continuation::template result	// ?
						<
							dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types, Op, Types...
						>;

			// type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename> class Op
					>
				using s_t_map_t_mutate_induct = typename Continuation::template result	// ?
						<
							pattern_match_types, pattern_match_types, Op, Types...
						>;

			// fast type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename> class Op
					>
				static constexpr Image af_t_map_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind,
							dependent_memoization<Kind>::template pattern_match_values,
							Op<Types>::template result<Kind>...
						>;

			// fast type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename> class Op
					>
				static constexpr Image af_t_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, Op<Types>...
						>;

			// type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<typename> class Op
					>
				static constexpr Image a_t_map_v_mutate_induct = Continuation::template result	// ?
						<
							Image, dependent_memoization<Kind>::template pattern_match_values,
							pattern_match_types, Op, Types...
						>;

			// type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename> class Op
					>
				static constexpr Image a_t_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, pattern_match_types, pattern_match_types, Op, Types...
						>;

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
		};

		// list:

		template<typename>
		struct pattern_match_types_list
		{
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

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) false
						>;
		};

		template<template<typename...> class ListName, typename... Types>
		struct pattern_match_types_list<ListName<Types...>>
		{
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
				static constexpr Image af_match_induct = Continuation::template result	// a_value
						<
							Image, (Image) true
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				using s_front_grow_induct = typename Continuation::template result	// s_grow_to_types
						<
							ListName, List, Args..., Types...
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						// template<typename...> class ListName,

						typename List, typename... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result	// ?
						<
							Image, ListName, List, Args..., Types...
						>;

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

			// fast type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				using sf_t_map_v_mutate_induct = typename Continuation::template result	// s_values
						<
							Kind, ListKind, Op<Types>::template result<Kind>...
						>;

			// fast type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						template<typename> class Op
					>
				using sf_t_map_t_mutate_induct = typename Continuation::template result	// s_types
						<
							ListLabel, Op<Types>...
						>;

			// type map to value mutate: map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				using s_t_map_v_mutate_induct = typename Continuation::template result	// ?
						<
							ListKind, ListName, Op, Types...
						>;

			// type map to type mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListLabel,

						template<typename> class Op
					>
				using s_t_map_t_mutate_induct = typename Continuation::template result	// ?
						<
							ListLabel, ListName, Op, Types...
						>;

			// fast type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				static constexpr Image af_t_map_v_mutate_induct = Continuation::template result	// a_to_value
						<
							Image, Kind, ListKind, Op<Types>::template result<Kind>...
						>;

			// fast type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<typename> class Op
					>
				static constexpr Image af_t_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, Op<Types>...
						>;

			// type map to value mutate: map.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						template<typename> class Op
					>
				static constexpr Image a_t_map_v_mutate_induct = Continuation::template result	// ?
						<
							Image, ListKind, ListName, Op, Types...
						>;

			// type map to type mutate: map, rename.

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						template<typename...> class ListLabel,

						template<typename> class Op
					>
				static constexpr Image a_t_map_t_mutate_induct = Continuation::template result	// ?
						<
							Image, ListLabel, ListName, Op, Types...
						>;

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
		};

		// The following values (list) functions are only here due to the above values (list)
		// pattern matcher, otherwise they narratively belong with their respective list languages.

		// values zip:

			// symbolic:

			template<typename Continuation>
			struct cp_sf_values_zip_induct
			{
				template
				<
					typename Kind, template<Kind...> class ListKind,
					typename Type1, template<Type1...> class ListType1,
					typename Type2, typename Values2,
					Kind (*Op)(Type1, Type2), Type1... Values1
				>
				using result = typename Values2::template
				sf_vv_zip_v_mutate_induct
				<
					Continuation, Kind, Type1, Op, Values1...
				>;
			};

			// assemblic:

			template<typename Continuation>
			struct cp_af_values_zip_induct
			{
				template
				<
					typename Image,
					typename Kind, template<Kind...> class ListKind,
					typename Type1, template<Type1...> class ListType1,
					typename Type2, typename Values2,
					Kind (*Op)(Type1, Type2), Type1... Values1
				>
				static constexpr Image result = Values2::template
				af_vv_zip_v_mutate_induct
				<
					Continuation, Image, Kind, Type1, Op, Values1...
				>;
			};

		// values list length:

			// assemblic:

			template<typename Continuation>
			struct cp_af_grow_to_value_length
			{
				template
				<
					typename Image, typename Type,
					template<Type...> class ListType, typename _Drop_, Type... Values
				>
				static constexpr Image result = Continuation::template result
				<
					Image, (Image) sizeof...(Values)
				>;
			};

			// The following values function is only here due to the above values pattern
			// matcher, otherwise it narratively belongs with its respective list languages.

		// values list zip:

			// symbolic:

			template<typename Continuation>
			struct cp_sf_values_list_zip_induct
			{
				template
				<
					typename Kind, template<Kind...> class ListKind,
					typename Type1, template<Type1...> class ListType1,
					typename Type2, typename Values2,
					Kind (*Op)(Type1, Type2), Type1... Values1
				>
				using result = typename dependent_memoization<Type2>::template
				pattern_match_values_list<Values2>::template
				sf_vv_zip_v_mutate_induct
				<
					Continuation, Kind, ListKind, Type1, Op, Values1...
				>;
			};

			// assemblic:

			template<typename Continuation>
			struct cp_af_values_list_zip_induct
			{
				template
				<
					typename Image,
					typename Kind, template<Kind...> class ListKind,
					typename Type1, template<Type1...> class ListType1,
					typename Type2, typename Values2,
					Kind (*Op)(Type1, Type2), Type1... Values1
				>
				static constexpr Image result = dependent_memoization<Type2>::template
				pattern_match_values_list<Values2>::template
				af_vv_zip_v_mutate_induct
				<
					Continuation, Image, Kind, ListKind, Type1, Op, Values1...
				>;
			};
	};
};
