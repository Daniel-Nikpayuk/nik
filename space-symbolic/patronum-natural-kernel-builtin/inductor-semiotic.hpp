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
	template<typename Type>
	struct dependent_memoization
	{
		// type:

			// coinduct:

			// The following assemblic aliases are only here as an optimization to minimize memoizations.
			// Otherwise, they narratively belong with their respective assemblic languages.

			// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
			// overlap as it allows for reduced memoizations when implementing equality, pairs, functions.

		template<typename Kind, typename = filler>
		struct coinduct_type
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Kind>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_dependent = Continuation::template result<Inductor, Type, Kind>;
		};

		template<typename Filler>
		struct coinduct_type<Type, Filler>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Type>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_induct = Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_dependent = Continuation::template result<Inductor, Type, Type>;
		};

			// symbolic induct:

			// assemblic induct:

		// values:

			// coinduct:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<auto...>
		struct coinduct_values
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;
		};

		template<Type... Values>
		struct coinduct_values<Values...>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, Type, Values...>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_induct = Continuation::template result<Inductor, Type, Values...>;
		};

			// value (judgement):

		template<auto Value>
		using coinduct_value = coinduct_values<Value>;

			// symbolic induct:

			// assemblic induct:

		// list:

			// coinduct:

			// The following template pattern matcher is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<typename>
		struct coinduct_list
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;
		};

		template<template<Type...> class ListType, Type... Values>
		struct coinduct_list<ListType<Values...>>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_induct = typename Continuation::template result<Inductor, ListType, Type, Values...>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_induct = Continuation::template result<Inductor, ListType, Type, Values...>;
		};

			// symbolic induct:

			// assemblic induct:
	};

	// continuation halters:

		// coinduct:

	struct ch_coinduct_type
	{
		template<typename Inductor, typename Type>
		using result = typename Inductor::template dependent_memoization<Type>::template coinduct_type<Type>;
	};

	struct ch_coinduct_value
	{
		template<typename Inductor, typename Type, Type Value>
		using result = typename Inductor::template dependent_memoization<Type>::template coinduct_value<Value>;
	};

		// symbolic induct:

		// assemblic induct:

};

