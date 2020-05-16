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

/*
	Given that copair is implemented as a specific pair, pattern matching here is redundant,
	but is still included for optimization purposes. For this reason it is better to use these
	operators for copairs instead of the more generic pair operators, when possible.
*/

struct structure
{
	using kind		= module;

	using rtn		= structure;

	template<typename Type, Type Value>	struct builtin_inl	{ };
	template<typename Value>		struct typename_inl	{ };

	template<typename Type, Type Value>	struct builtin_inr	{ };
	template<typename Value>		struct typename_inr	{ };

/*
	pattern_match_builtin_copair:
*/

	template<typename>
	struct pattern_match_builtin_copair
	{
		using rtn = pattern_match_builtin_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Type, Type Value>
	struct pattern_match_builtin_copair<builtin_inl<Type, Value>>
	{
		using rtn = pattern_match_builtin_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// shrink:

		template
		<
			typename Continuation

				//   signature: value.

		> using pop = typename Continuation::template result<false, Type, Value>;
	};

	template<typename Type, Type Value>
	struct pattern_match_builtin_copair<builtin_inr<Type, Value>>
	{
		using rtn = pattern_match_builtin_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// shrink:

		template
		<
			typename Continuation

				//   signature: value.

		> using pop = typename Continuation::template result<true, Type, Value>;
	};

/*
	pattern_match_typename_copair:
*/

	template<typename>
	struct pattern_match_typename_copair
	{
		using rtn = pattern_match_typename_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Value>
	struct pattern_match_typename_copair<typename_inl<Value>>
	{
		using rtn = pattern_match_typename_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// shrink:

		template
		<
			typename Continuation

				//   signature: value.

		> using pop = typename Continuation::template result<false, Value>;
	};

	template<typename Value>
	struct pattern_match_typename_copair<typename_inr<Value>>
	{
		using rtn = pattern_match_typename_copair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// shrink:

		template
		<
			typename Continuation

				//   signature: value.

		> using pop = typename Continuation::template result<true, Value>;
	};
};

