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
	template<typename Type, Induction = Induction::cofactored>
	struct dependent_memoization
	{
		// type:

			// The following assemblic aliases are only here as an optimization to minimize memoizations.
			// Otherwise, they narratively belong with their respective assemblic languages.

			// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
			// overlap as it allows for reduced memoizations when implementating equality, pairs, functions.

		template<typename Kind, typename = filler>
		struct memoized_type
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
		struct memoized_type<Type, Filler>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic = typename Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Type>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic = Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_dependent = Continuation::template result<Inductor, Type, Type>;
		};

			// The following template memoization is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<auto...>
		struct memoized_values
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;
		};

		template<Type... Values>
		struct memoized_values<Values...>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic = typename Continuation::template result<Inductor, Type, Values...>;

			//

			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic = Continuation::template result<Inductor, Type, Values...>;
		};

		// value (judgement):

		template<Type Value>
		using memoized_value = memoized_values<Value>;
	};

	//

	template<typename Type>
	struct dependent_memoization<Type, Induction::symbolic>
	{
		// type:

			// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
			// overlap as it allows for reduced memoizations when implementating equality, pairs, functions.

		template<typename Kind, typename = filler>
		struct memoized_type
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Kind>;
		};

		template<typename Filler>
		struct memoized_type<Type, Filler>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic = typename Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic_dependent = typename Continuation::template result<Inductor, Type, Type>;
		};

			// The following template memoization is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<auto...>
		struct memoized_values
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, false>;
		};

		template<Type... Values>
		struct memoized_values<Values...>
		{
			template<typename Continuation, typename Inductor = inductor>
			using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = inductor>
			using symbolic = typename Continuation::template result<Inductor, Type, Values...>;
		};

		// value (judgement):

		template<Type Value>
		using memoized_value = memoized_values<Value>;
	};

	//

	template<typename Type>
	struct dependent_memoization<Type, Induction::assemblic>
	{
		// type:

			// The expense of the extra dependent alias is justified in contexts where Type, Kind bindings
			// overlap as it allows for reduced memoizations when implementating equality, pairs, functions.

		template<typename Kind, typename = filler>
		struct memoized_type
		{
			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_dependent = Continuation::template result<Inductor, Type, Kind>;
		};

		template<typename Filler>
		struct memoized_type<Type, Filler>
		{
			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic = Continuation::template result<Inductor, Type>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic_dependent = Continuation::template result<Inductor, Type, Type>;
		};

			// The following template memoization is only here as an optimization to minimize memoizations.
			// Otherwise, it narratively belongs with its respective list languages.

		template<auto...>
		struct memoized_values
		{
			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, false>;
		};

		template<Type... Values>
		struct memoized_values<Values...>
		{
			template<typename Continuation, typename Inductor = bool>
			static constexpr Inductor assemblic_match = Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = Type>
			static constexpr Inductor assemblic = Continuation::template result<Inductor, Type, Values...>;
		};

		// value (judgement):

		template<Type Value>
		using memoized_value = memoized_values<Value>;
	};

	//

	struct ch_symbolic_type
	{
		template<typename Inductor, typename Type>
		using result = typename Inductor::template dependent_memoization<Type>::template memoized_type<Type>;
	};

	struct ch_symbolic_value
	{
		template<typename Inductor, typename Type, Type Value>
		using result = typename Inductor::template dependent_memoization<Type>::template memoized_value<Value>;
	};
};

