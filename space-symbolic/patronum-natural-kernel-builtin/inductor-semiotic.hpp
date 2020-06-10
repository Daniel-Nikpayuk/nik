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
	// continuation halters:

		// symbolic:

			// type:

				struct ch_s_type
				{
					template<typename Type>
					using result = Type;
				};

				struct ch_s_types
				{
					template<template<typename...> class ListType, typename... Types>
					using result = ListType<Types...>;
				};

			// value:

				struct ch_s_values
				{
					template<typename Type, template<Type...> class ListType, Type... Values>
					using result = ListType<Values...>;
				};

		// assemblic:

			// value:

				struct ch_a_value
				{
					template<typename Type, Type Value>
					static constexpr Type result = Value;
				};

	// continuation passers:

		// symbolic:

			// type:

				// types:

				template<typename Continuation>
				struct cp_s_types_to_type
				{
					template<template<typename...> class ListType, typename Type, typename... Types>
					using result = typename Continuation::template result
					<
						Type
					>;
				};

				using ch_s_types_to_type		= cp_s_types_to_type<ch_s_type>;

				// grow:

				template<typename Continuation>
				struct cp_s_grow_to_types
				{
					template<typename Type, template<typename...> class ListType, typename _Drop_, typename... Types>
					using result = typename Continuation::template result
					<
						Type, ListType, Types...
					>;
				};

				using ch_s_grow_to_type			= cp_s_grow_to_types<ch_s_types_to_type>;
				using ch_s_grow_to_types		= cp_s_grow_to_types<ch_s_types>;

			// value:

				// match:

				template<typename Continuation>
				struct cp_s_match_to_values
				{
					template<typename Type, template<Type...> class ListType, typename Kind, Kind Value>
					using result = typename Continuation::template result
					<
						Type, ListType, Value
					>;
				};

				using ch_s_match_to_values		= cp_s_match_to_values<ch_s_values>;

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

		// assemblic:

			// value:

				// match:

				template<typename Continuation>
				struct cp_a_match_to_value
				{
					template<typename Kind, typename Type, Type Value>
					static constexpr Kind result = Continuation::template result
					<
						Kind, Value
					>;
				};

				using ch_a_match_to_value		= cp_a_match_to_value<ch_a_value>;

				// grow:

	// dependent memoization:

		// The expense of the extra dependent alias is justified in contexts where Type, Kind, Image bindings
		// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		// Policy is to pass predefined info such as Kind beforehand, which otherwise could be
		// determined by use of *auto*. Assumption is it's faster not having to figure out the type info.

		// match aliases are required to have the same grammatical input form regardless of how a given
		// templated struct is partially specialized, but there is no such requirement for induct aliases.

		// match aliases default to boolean output, but we privilege minimal memoization, as well as
		// make use of continuations, and so we also provide a generic Kind output to support these.

	template<typename Type, typename = filler>
	struct dependent_memoization
	{
		// type:

		template<typename... Types>
		struct pattern_match_types
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, false
						>;

			// induct:

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListKind
					>
				using s_induct = typename Continuation::template result			// s_types
						<
							ListKind, Type, Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind
					>
				static constexpr Kind a_induct = Continuation::template result		// ?
						<
							Kind, Type, Types...
						>;
		};

		template<typename... Types>
		struct pattern_match_types<Type, Types...>
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, true
						>;

			// induct:

				// symbolic:

					template
					<
						typename Continuation,

						template<typename...> class ListKind
					>
				using s_induct = typename Continuation::template result			// s_types
						<
							ListKind, Type, Type, Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind
					>
				static constexpr Kind a_induct = Continuation::template result		// ?
						<
							Kind, Type, Type, Types...
						>;
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, false
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, true
						>;

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
						typename Continuation, typename Kind,

						typename List, Type... Args
					>
				static constexpr Kind a_front_grow_induct = Continuation::template result	// ?
						<
							Kind, Type, pattern_match_values, List, Args..., Values...
						>;

			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, pattern_match_values, List, Values..., Args...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename List, Type... Args
					>
				static constexpr Kind a_back_grow_induct = Continuation::template result	// ?
						<
							Kind, Type, pattern_match_values, List, Values..., Args...
						>;

			// fast map: no signature, but required to implement map (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, Image (*Op)(Type)
					>
				using sf_map_induct = typename Continuation::template result		// s_values
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Op(Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, Image (*Op)(Type)
					>
				static constexpr Kind af_map_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
							Op(Values)...
						>;

			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, Image (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result	// ?
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, Image (*Op)(Type)
					>
				static constexpr Kind a_map_mutate_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op, Values...
						>;

			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, Image (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result		// s_values
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, Image (*Op)(Type, Type), Type... Args
					>
				static constexpr Kind af_zip_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
							Op(Args, Values)...
						>;

			// zip mutate: zip.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, Image (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result	// ?
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, Image (*Op)(Type, Type), typename List
					>
				static constexpr Kind a_zip_mutate_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op, List, Values...
						>;

			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, typename Op_Cond, size_type count, Image... Moment
					>
				using s_shrink_induct = typename Continuation::template result		// ?
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op_Cond, count, Moment..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, typename Op_Cond, size_type count, Image... Moment
					>
				static constexpr Kind a_shrink_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op_Cond, count, Moment..., Values...
						>;

			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_patch_induct = typename Continuation::template result		// ?
						<
							Image,
							dependent_memoization<Image>::template pattern_match_values,
							Type, Op_Cond, count, List0, List1, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, typename Op_Cond, size_type count, typename List0, typename List1
					>
				static constexpr Kind a_patch_induct = Continuation::template result	// ?
						<
							Kind, Image,
							dependent_memoization<Image>::template pattern_match_values,
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, false
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, true
						>;

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
						typename Continuation, typename Kind, // template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Kind a_front_grow_induct = Continuation::template result	// ?
						<
							Kind, Type, ListType, List, Args..., Values...
						>;

			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result	// s_grow_to_values
						<
							Type, ListType, List, Values..., Args...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind, // template<Type...> class ListType,

						typename List, Type... Args
					>
				static constexpr Kind a_back_grow_induct = Continuation::template result	// ?
						<
							Kind, Type, ListType, List, Values..., Args...
						>;

			// fast map: no signature, but required to implement map (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type)
					>
				using sf_map_induct = typename Continuation::template result		// s_values
						<
							Image, ListImage, Op(Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type)
					>
				static constexpr Kind af_map_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Op(Values)...
						>;

			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListImage, Type, ListType, Op, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type)
					>
				static constexpr Kind a_map_mutate_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Type, ListType, Op, Values...
						>;

			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result		// s_value
						<
							Image, ListImage, Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type, Type), Type... Args
					>
				static constexpr Kind af_zip_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Op(Args, Values)...
						>;

			// zip mutate: zip, map, rename.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result	// ?
						<
							Image, ListImage, Type, ListType, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						Image (*Op)(Type, Type), typename List
					>
				static constexpr Kind a_zip_mutate_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Type, ListType, Op, List, Values...
						>;

			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						typename Op_Cond, size_type count, Image... Moment
					>
				using s_shrink_induct = typename Continuation::template result		// ?
						<
							Image, ListImage, Type, ListType, Op_Cond, count, Moment..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						typename Op_Cond, size_type count, Image... Moment
					>
				static constexpr Kind a_shrink_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Type, ListType, Op_Cond, count, Moment..., Values...
						>;

			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation,

						typename Image, template<Image...> class ListImage,

						typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_patch_induct = typename Continuation::template result		// ?
						<
							Image, ListImage, Type, ListType, Op_Cond, count, List0, List1, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Kind,

						typename Image, template<Image...> class ListImage,

						typename Op_Cond, size_type count, typename List0, typename List1
					>
				static constexpr Kind a_patch_induct = Continuation::template result	// ?
						<
							Kind, Image, ListImage, Type, ListType, Op_Cond, count, List0, List1, Values...
						>;
		};
	};

	template<typename Filler>
	struct dependent_memoization<void, Filler>
	{
		// type:

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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, false
						>;
		};

		template<template<typename...> class ListType, typename... Types>
		struct pattern_match_types_list<ListType<Types...>>
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, true
						>;
		};

		// induct

			// checks for symbolic member only.

		template<typename, typename = filler>
		struct pattern_match_induct
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, false
						>;
		};

		template<typename Struct>
		struct pattern_match_induct<Struct, sfinae_try<Struct::template symbolic_induct>>
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
						typename Continuation, typename Kind
					>
				static constexpr Kind a_match_induct = Continuation::template result	// a_match_to_value
						<
							Kind, bool, true
						>;
		};
	};

		// The following values list functions are only here due to the above values list pattern
		// matcher, otherwise they narratively belong with their respective list languages.

	// length:

		// assemblic:

		template<typename Continuation>
		struct cp_af_grow_to_value_length
		{
				template
				<
					typename Kind, typename Image, template<Image...> class ListImage,

					typename List, Image... Values
				>
			static constexpr Kind result = Continuation::template result
					<
						Kind, size_type, sizeof...(Values)
					>;
		};

		template<typename List, typename Continuation, typename Image>
		static constexpr Image af_values_list_length = pattern_match_values_list<List>::template
		a_front_grow_induct
		<
			cp_af_values_list_length<Continuation>, Image, filler
		>;

		// The following values function is only here due to the above values pattern
		// matcher, otherwise it narratively belongs with its respective list languages.

	// zip:

		// symbolic:

		template<typename Continuation>
		struct cp_sf_values_zip
		{
			template
			<
				typename Image, template<Image...> class ListKind,

				typename Kind, Image (*Op)(Kind, Kind), typename Values2, Kind... Values1
			>
			using result = typename Values2::template
			sf_zip_induct
			<
				Continuation, Image, Op, Values1...
			>;
		};

		template
		<
			typename Image, Image (*Op)(Type, Type), typename Values1, typename Values2,
				typename Continuation
		>
		using sf_values_zip = typename Values1::template
		s_zip_mutate_induct
		<
			cp_sf_values_zip<Continuation>, Image, Op, Values2
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_af_values_zip
		{
			template
			<
				typename Image0, typename Image1, template<Image1...> class ListImage1,

				typename Kind, Image1 (*Op)(Kind, Kind), typename Values2, Kind... Values1
			>
			static constexpr Image0 result = Values2::template
			af_zip_induct
			<
				Continuation, Image0, Image1, Op, Values1...
			>;
		};

		template
		<
			typename Image1, Image1 (*Op)(Type, Type), typename Values1, typename Values2,
				typename Continuation, typename Image0
		>
		static constexpr Image0 af_values_zip = Values1::template
		a_zip_mutate_induct
		<
			cp_af_values_zip<Continuation>, Image0, Image1, Op, Values2
		>;

	// zip:

		// symbolic:

		template<typename Continuation>
		struct cp_sf_values_list_zip
		{
			template
			<
				typename Image0, template<Image0...> class ListImage0,
				typename Image1, template<Image1...> class ListImage1,

				Image0 (*Op)(Image1, Image1), typename List2, Image1... Values1
			>
			using result = typename pattern_match_values_list<List2>::template
			sf_zip_induct
			<
				Continuation, Image0, ListImage0, Op, Values1...
			>;
		};

		template
		<
			typename Image, Image (*Op)(Type, Type), typename List1, typename List2,
				typename Continuation, template<Image...> class ListImage
		>
		using sf_values_list_zip = typename pattern_match_values_list<List1>::template
		s_zip_mutate_induct
		<
			cp_sf_values_list_zip<Continuation>, Image, ListImage, Op, List2
		>;

		// assemblic:

		template<typename Continuation>
		struct cp_af_values_list_zip
		{
			template
			<
				typename Kind,

				typename Image0, template<Image0...> class ListImage0,
				typename Image1, template<Image1...> class ListImage1,

				Image0 (*Op)(Image1, Image1), typename List2, Image1... Values1
			>
			static constexpr Kind result = pattern_match_values_list<List2>::template
			af_zip_induct
			<
				Continuation, Kind, Image0, ListImage0, Op, Values1...
			>;
		};

		template
		<
			typename Image, Image (*Op)(Type, Type), typename List1, typename List2,
				typename Continuation, template<Image...> class ListImage, typename Kind
		>
		static constexpr Kind af_values_list_zip = pattern_match_values_list<List1>::template
		a_zip_mutate_induct
		<
			cp_af_values_list_zip<Continuation>, Kind, Image, ListImage, Op, List2
		>;
};
