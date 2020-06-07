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
			template<typename Inductor, typename Type, typename... Types>
			using result = typename Inductor::template dependent_memoization<Type>::template
			pattern_match_types<Types...>;
		};

		struct ch_symbolic_values
		{
			template<typename Inductor, typename Type, Type... Values>
			using result = typename Inductor::template dependent_memoization<Type>::template
			pattern_match_values<Values...>;
		};

		// assemblic:

		struct ch_assemblic_value
		{
			template<typename OutType, typename Type, Type Value>
			static constexpr OutType result = Value;
		};

	// dependent memoization:

		// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
		// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		// Policy is to pass predefined info such as OutType beforehand, which otherwise could be
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
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation = ch_symbolic_types, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Types...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;

				// no matching continuation halting default:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, Types...>;
		};

		template<typename... Types>
		struct pattern_match_types<Type, Types...>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation = ch_symbolic_types, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Types...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, Types...>;
		};

		// values:

			// The following template pattern matcher is only here as an optimization to minimize
			// memoizations, otherwise it narratively belongs with its respective judgment module.

		template<auto... Values>
		struct pattern_match_values
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Values...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, Values...>;
		};

		template<Type... Values>
		struct pattern_match_values<Values...>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Values...>;

			template<typename Continuation, typename Inductor, Type... oValues>
			using symbolic_prepend_induct = typename Continuation::template result<Inductor, Type, oValues..., Values...>;

			template<typename Continuation, typename Inductor, Type... oValues>
			using symbolic_append_induct = typename Continuation::template result<Inductor, Type, Values..., oValues...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType = Type>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, Values...>;
		};

		// list:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<typename>
		struct pattern_match_values_list
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
		};

		template<template<Type...> class ListType, Type... Values>
		struct pattern_match_values_list<ListType<Values...>>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation>
			using symbolic_induct = typename Continuation::template result<Type, ListType, Values...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, ListType, Values...>;
		};

		// length:

			// The following values list functions are only here due to the above values list pattern
			// matcher, otherwise they narratively belong with their respective list languages.

			// symbolic:

			template<typename Continuation>
			struct cp_s_values_list_length
			{
				template<typename Kind, template<Kind...> class ListType, Kind... Values>
				using result = typename Continuation::template result
				<
					inductor, size_type, sizeof...(Values)
				>;
			};

			template<typename List, typename Continuation = ch_symbolic_values>
			using s_values_list_length = typename pattern_match_values_list<List>::template
			symbolic_induct
			<
				cp_s_values_list_length<Continuation>
			>;

			// assemblic:

			template<typename Continuation>
			struct cp_a_values_list_length
			{
				template<typename OutType, typename Kind, template<Kind...> class ListType, Kind... Values>
				static constexpr OutType result = Continuation::template result
				<
					size_type, size_type, sizeof...(Values)
				>;
			};

			template<typename List, typename Continuation = ch_assemblic_value>
			static constexpr size_type a_values_list_length = pattern_match_values_list<List>::template
			assemblic_induct
			<
				cp_a_values_list_length<Continuation>, size_type
			>;
	};

	template<typename Filler>
	struct dependent_memoization<void, Filler>
	{
		// type:

		template<typename>
		struct pattern_match_types_list
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
		};

		template<template<typename...> class ListType, typename... Types>
		struct pattern_match_types_list<ListType<Types...>>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename Inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Types...>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Types...>;
		};

		// induct

			// checks for symbolic member only.

		template<typename, typename = filler>
		struct pattern_match_induct
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;
		
			//
		
			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
		};
		
		template<typename Struct>
		struct pattern_match_induct<Struct, sfinae_try<Struct::template symbolic_induct>>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;
		
			//
		
			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;
		};
	};
};
