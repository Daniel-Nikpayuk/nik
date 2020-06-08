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

	// Old note, bug seems fixed:

	// For whatever reason if I put a template after Continuation
	// in the following it produces an internal compiler error.

struct inductor
{
	// continuation halters:

		// symbolic:

		struct ch_symbolic_type
		{
			template<typename Type>
			using result = Type;
		};

		struct ch_symbolic_types
		{
			template<template<typename> class Memoizer, typename Type, typename... Types>
			using result = typename Memoizer<Type>::template pattern_match_types<Types...>;
		};

		struct ch_symbolic_values
		{
			template<template<typename> class Memoizer, typename Type, Type... Values>
			using result = typename Memoizer<Type>::template pattern_match_values<Values...>;
		};

		// assemblic:

		struct ch_assemblic_value
		{
			template<typename Image, typename Type, Type Value>
			static constexpr Image result = Value;
		};

	// dependent memoization:

		// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
		// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		// Policy is to pass predefined info such as Kind beforehand, which otherwise could be
		// determined by use of *auto*. Assumption is it's faster not having to figure out the type info.

		// match aliases are required to have the same grammatical input form regardless of how a given
		// templated struct is partially specialized, but there is no such requirement for induct aliases.

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
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, false
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, false
						>;

			// induct:

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_induct = typename Continuation::template result
						<
							Memoizer, Type, Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_induct = Continuation::template result
						<
							Image, Type, Types...
						>;
		};

		template<typename... Types>
		struct pattern_match_types<Type, Types...>
		{
			// match: id.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, true
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, true
						>;

			// induct:

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_induct = typename Continuation::template result
						<
							Memoizer, Type, Type, Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_induct = Continuation::template result
						<
							Image, Type, Type, Types...
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
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, false
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, false
						>;
		};

		template<Type... Values>
		struct pattern_match_values<Values...>
		{
			// match: id.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, true
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, true
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result
						<
							Memoizer, Type, List, Args..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result
						<
							Image, Type, List, Args..., Values...
						>;

			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result
						<
							Memoizer, Type, List, Values..., Args...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, Type... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result
						<
							Image, Type, List, Values..., Args...
						>;

			// fast map: no signature, but required to implement map (signature).

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, Kind (*Op)(Type)
					>
				using sf_map_induct = typename Continuation::template result
						<
							Memoizer, Kind, Op(Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image af_map_induct = Continuation::template result
						<
							Image, Kind, Op(Values)...
						>;

			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, Kind (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result
						<
							Memoizer, Kind, Type, Op, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type)
					>
				static constexpr Image a_map_mutate_induct = Continuation::template result
						<
							Image, Kind, Type, Op, Values...
						>;

			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, Kind (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result
						<
							Memoizer, Kind, Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type, Type), Type... Args
					>
				static constexpr Image af_zip_induct = Continuation::template result
						<
							Image, Kind, Op(Args, Values)...
						>;

			// zip mutate: zip.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, Kind (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result
						<
							Memoizer, Kind, Type, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, Kind (*Op)(Type, Type), typename List
					>
				static constexpr Image a_zip_mutate_induct = Continuation::template result
						<
							Image, Kind, Type, Op, List, Values...
						>;

			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				using s_shrink_induct = typename Continuation::template result
						<
							Memoizer, Kind, Type, Op_Cond, count, Moment..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				static constexpr Image a_shrink_induct = Continuation::template result
						<
							Image, Kind, Type, Op_Cond, count, Moment..., Values...
						>;

			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer,

						typename Kind, typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_patch_induct = typename Continuation::template result
						<
							Memoizer, Kind, Type, Op_Cond, count, List0, List1, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Op_Cond, size_type count, typename List0, typename List1
					>
				static constexpr Image a_patch_induct = Continuation::template result
						<
							Image, Kind, Type, Op_Cond, count, List0, List1, Values...
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
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, false
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, false
						>;
		};

		template<template<Type...> class ListType, Type... Values>
		struct pattern_match_values_list<ListType<Values...>>
		{
			// match: id.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, true
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, true
						>;

			// front grow: null, multicons, cons, car, cdr, length, catenate.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_front_grow_induct = typename Continuation::template result
						<
							Type, ListType, List, Args..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, Type... Args
					>
				static constexpr Image a_front_grow_induct = Continuation::template result
						<
							Image, Type, ListType, List, Args..., Values...
						>;

			// back grow: multipush, push, multiunite, unite.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename List, Type... Args
					>
				using s_back_grow_induct = typename Continuation::template result
						<
							Type, ListType, List, Values..., Args...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename List, Type... Args
					>
				static constexpr Image a_back_grow_induct = Continuation::template result
						<
							Image, Type, ListType, List, Values..., Args...
						>;

			// fast map: no signature, but required to implement map (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using sf_map_induct = typename Continuation::template result
						<
							Kind, ListKind, Op(Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind, Kind (*Op)(Type)
					>
				static constexpr Image af_map_induct = Continuation::template result
						<
							Image, Kind, ListKind, Op(Values)...
						>;

			// map mutate: map, rename.

				// symbolic:

					template
					<
						typename Continuation, typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type)
					>
				using s_map_mutate_induct = typename Continuation::template result
						<
							Kind, ListKind, Type, ListType, Op, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind, Kind (*Op)(Type)
					>
				static constexpr Image a_map_mutate_induct = Continuation::template result
						<
							Image, Kind, ListKind, Type, ListType, Op, Values...
						>;

			// fast zip: no signature, but required to implement zip (signature).

				// symbolic:

					template
					<
						typename Continuation, typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), Type... Args
					>
				using sf_zip_induct = typename Continuation::template result
						<
							Kind, ListKind, Op(Args, Values)...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), Type... Args
					>
				static constexpr Image af_zip_induct = Continuation::template result
						<
							Image, Kind, ListKind, Op(Args, Values)...
						>;

			// zip mutate: zip, map, rename.

				// symbolic:

					template
					<
						typename Continuation, typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), typename List
					>
				using s_zip_mutate_induct = typename Continuation::template result
						<
							Kind, ListKind, Type, ListType, Op, List, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						Kind (*Op)(Type, Type), typename List
					>
				static constexpr Image a_zip_mutate_induct = Continuation::template result
						<
							Image, Kind, ListKind, Type, ListType, Op, List, Values...
						>;

			// shrink: split_fold, fold, find, multicdr, multicar, reverse.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				using s_shrink_induct = typename Continuation::template result
						<
							Kind, Type, ListType, Op_Cond, count, Moment..., Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, typename Op_Cond, size_type count, Kind... Moment
					>
				static constexpr Image a_shrink_induct = Continuation::template result
						<
							Image, Kind, Type, ListType, Op_Cond, count, Moment..., Values...
						>;

			// patch: split_zip, split_map.

				// symbolic:

					template
					<
						typename Continuation, // template<Type...> class ListType,

						typename Kind, template<Kind...> class ListKind,

						typename Op_Cond, size_type count, typename List0, typename List1
					>
				using s_patch_induct = typename Continuation::template result
						<
							Kind, ListKind, Type, ListType, Op_Cond, count, List0, List1, Values...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image,

						typename Kind, template<Kind...> class ListKind,

						typename Op_Cond, size_type count, typename List0, typename List1
					>
				static constexpr Image a_patch_induct = Continuation::template result
						<
							Image, Kind, ListKind, Type, ListType, Op_Cond, count, List0, List1, Values...
						>;
		};

		// length:

			// The following values list functions are only here due to the above values list pattern
			// matcher, otherwise they narratively belong with their respective list languages.

			// assemblic:

			template<typename Continuation>
			struct cp_af_values_list_length
			{
					template
					<
						typename Image, typename Kind, template<Kind...> class ListKind,

						typename List, Kind... Values
					>
				static constexpr Image result = Continuation::template result
						<
							Image, size_type, sizeof...(Values)
						>;
			};

			template
			<
				typename List,
				typename Continuation = ch_assemblic_value,
				typename Image = size_type
			>
			static constexpr Image af_values_list_length = pattern_match_values_list<List>::template
			a_front_grow_induct
			<
				cp_af_values_list_length<Continuation>, Image, filler
			>;
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
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, false
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, false
						>;
		};

		template<template<typename...> class ListType, typename... Types>
		struct pattern_match_types_list<ListType<Types...>>
		{
			// match: id.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, true
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, true
						>;

			// induct:

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_induct = typename Continuation::template result
						<
							Memoizer, void, Types...
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_induct = Continuation::template result
						<
							Image, void, Types...
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
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, false
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, false
						>;
		};

		template<typename Struct>
		struct pattern_match_induct<Struct, sfinae_try<Struct::template symbolic_induct>>
		{
			// match: id.

				// symbolic:

					template
					<
						typename Continuation, template<typename> class Memoizer
					>
				using s_match_induct = typename Continuation::template result
						<
							Memoizer, bool, true
						>;

				// assemblic:

					template
					<
						typename Continuation, typename Image
					>
				static constexpr Image a_match_induct = Continuation::template result
						<
							Image, bool, true
						>;
		};
	};
};
