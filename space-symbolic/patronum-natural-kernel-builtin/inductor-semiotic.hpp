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
			template<typename Inductor, typename Type1, typename Type2>
			using result = typename Inductor::template dependent_memoization<Type1>::template pattern_match_type<Type2>;
		};

		struct ch_symbolic_values
		{
			template<typename Inductor, typename Type, Type... Values>
			using result = typename Inductor::template dependent_memoization<Type>::template pattern_match_values<Values...>;
		};

		// assemblic:

		struct ch_assemblic_value
		{
			template<typename OutType, typename Type, Type Value>
			static constexpr OutType result = Value;
		};

	// dependent memoization:

	template<typename Type>
	struct dependent_memoization
	{
		// type:

			// The following assemblic aliases are only here as an optimization to minimize memoizations.
			// Otherwise, they narratively belong with their respective assemblic languages.

			// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
			// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

			// Policy is to pass predefined info such as OutType beforehand, which otherwise could be
			// determined by use of *auto*. Assumption is it's faster not having to figure out the type info.

		template<typename Kind, typename = filler>
		struct pattern_match_type
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation = ch_symbolic_types, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Kind>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;

				// no matching continuation halting default:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_dependent = Continuation::template result<OutType, Type, Kind>;
		};

		template<typename Filler>
		struct pattern_match_type<Type, Filler>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation = ch_symbolic_type>
			using symbolic_induct = typename Continuation::template result<Type>;

			template<typename Continuation = ch_symbolic_types, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Type>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, true>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type>;

				// no matching continuation halting default at this level:

			template<typename Continuation, typename OutType>
			static constexpr OutType assemblic_dependent = Continuation::template result<OutType, Type, Type>;
		};

		// values:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<auto...>
		struct pattern_match_values
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
		};

		template<Type... Values>
		struct pattern_match_values<Values...>
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Values...>;

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
		struct pattern_match_list
		{
			template<typename Continuation = ch_symbolic_values, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation = ch_assemblic_value, typename OutType = bool>
			static constexpr OutType assemblic_match = Continuation::template result<OutType, bool, false>;
		};

		template<template<Type...> class ListType, Type... Values>
		struct pattern_match_list<ListType<Values...>>
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

			template<typename Continuation, typename OutType = Type>
			static constexpr OutType assemblic_induct = Continuation::template result<OutType, Type, ListType, Values...>;
		};
	};
};

