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
	struct builtin_inductor
	{
		// type:

		template<typename Kind, typename = filler>
		struct memoized_type
		{
			template<typename Continuation, typename Inductor = builtin_inductor<bool>>
			using match = typename Continuation::template result<Inductor, bool, false>;

			template<typename Continuation, typename Pair = inductor>
			using pair_induct = typename Continuation::template result<Pair, Type, Kind>;
		};

		template<typename Filler>
		struct memoized_type<Type, Filler>
		{
			template<typename Continuation, typename Inductor = builtin_inductor<bool>>
			using match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, const char* string_literal, typename Inductor = builtin_inductor<const char*>>
			using type_induct = typename Continuation::template result<Inductor, const char*, string_literal>;

			template<typename Continuation, typename Pair = inductor>
			using pair_induct = typename Continuation::template result<Pair, Type, Type>;

			template<typename Continuation, typename Kind, const char* string_literal = null_string_literal>
			static constexpr Kind (*value_induct)() = Continuation::template result<const char*, string_literal>;
		};

			// value:

		template<auto>
		struct memoized_value
		{
			template<typename Continuation, typename Inductor = builtin_inductor<bool>>
			using match = typename Continuation::template result<Inductor, bool, false>;
		};

		template<Type Value>
		struct memoized_value<Value>
		{
			template<typename Continuation, typename Inductor = builtin_inductor<bool>>
			using match = typename Continuation::template result<Inductor, bool, true>;

			template<typename Continuation, typename Inductor = builtin_inductor<Type>>
			using type_induct = typename Continuation::template result<Inductor, Type, Value>;

			template<typename Continuation, typename Kind>
			static constexpr Kind (*value_induct)() = Continuation::template result<Type, Value>;
		};
	};

	//

	struct ch_type
	{
		template<typename Inductor, typename Type, Type Value>
		using result = Type;
	};

	struct ch_value
	{
		template<typename Inductor, typename Type, Type Value>
		static constexpr Type result = Value;
	};
};

