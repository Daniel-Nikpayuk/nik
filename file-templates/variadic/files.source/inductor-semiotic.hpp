/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

				template<typename Continuation>
				struct cp_af_v_map_void_combine_void_to_values
				{
					template
					<
						typename Image,
						typename Type, template<Type...> class ListType,

						bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
						bool (*Before_Map)(Type),

						void (*Map)(Type),
						size_type depth, size_type count,
						Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, Type, ListType, Values...
					>;
				};

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
<<<TYPE_DEFAULT_INDUCT_TEXT>>>
		};

		template<typename Filler>
		struct pattern_match_type<Type, Filler>
		{
<<<TYPE_SPECIALIZED_INDUCT_TEXT>>>
		};

		// values:

			// The following template pattern matcher is only here as an optimization to minimize
			// memoizations, otherwise it narratively belongs with its respective judgment module.

		template<auto... Values>
		struct pattern_match_values
		{
<<<VALUES_DEFAULT_INDUCT_TEXT>>>
		};

		template<Type... Values>
		struct pattern_match_values<Values...>
		{
<<<VALUES_SPECIALIZED_INDUCT_TEXT>>>
		};

		// list:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<typename>
		struct pattern_match_values_list
		{
<<<VALUES_LIST_DEFAULT_INDUCT_TEXT>>>
		};

		template<template<Type...> class ListType, Type... Values>
		struct pattern_match_values_list<ListType<Values...>>
		{
<<<VALUES_LIST_SPECIALIZED_INDUCT_TEXT>>>
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
<<<S_FRONT_GROW_DEFAULT_INDUCT_TEXT>>>
		};

		template<typename Struct>
		struct pattern_match_s_front_grow_induct<Struct, sfinae_try<Struct::template s_front_grow_induct>>
		{
<<<S_FRONT_GROW_SPECIALIZED_INDUCT_TEXT>>>
		};

		// type:

		template<typename... Types>
		struct pattern_match_types
		{
<<<TYPES_DEFAULT_INDUCT_TEXT>>>
		};

		// list:

		template<typename>
		struct pattern_match_types_list
		{
<<<TYPES_LIST_DEFAULT_INDUCT_TEXT>>>
		};

		template<template<typename...> class ListName, typename... Types>
		struct pattern_match_types_list<ListName<Types...>>
		{
<<<TYPES_LIST_SPECIALIZED_INDUCT_TEXT>>>
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
