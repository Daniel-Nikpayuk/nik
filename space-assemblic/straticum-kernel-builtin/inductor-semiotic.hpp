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
};

//	memoized_builtin:

/*
	template<typename>
	struct memoized_builtin
	{
		using rtn = pattern_match_builtin_builtin_pair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
	struct pattern_match_builtin_builtin_pair<PairType<ValueX, ValueY>>
	{
		using rtn = pattern_match_builtin_builtin_pair;

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

				//   signature: car, cdr, left, right.

		> using pop = typename Continuation::template result<TypeX, TypeY, PairType, ValueX, ValueY>;
	};

//	pattern_match_builtin_typename_pair:

	template<typename>
	struct pattern_match_builtin_typename_pair
	{
		using rtn = pattern_match_builtin_typename_pair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename TypenameY>
	struct pattern_match_builtin_typename_pair<PairType<ValueX, TypenameY>>
	{
		using rtn = pattern_match_builtin_typename_pair;

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

				//   signature: car, cdr, left.

		> using pop = typename Continuation::template result<TypeX, PairType, ValueX, TypenameY>;
	};

//	pattern_match_typename_builtin_pair:

	template<typename>
	struct pattern_match_typename_builtin_pair
	{
		using rtn = pattern_match_typename_builtin_pair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename TypeY, template<typename, TypeY> class PairType, typename TypenameX, TypeY ValueY>
	struct pattern_match_typename_builtin_pair<PairType<TypenameX, ValueY>>
	{
		using rtn = pattern_match_typename_builtin_pair;

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

				//   signature: car, cdr, right.

		> using pop = typename Continuation::template result<TypeY, PairType, TypenameX, ValueY>;
	};

//	pattern_match_typename_typename_pair:

	template<typename>
	struct pattern_match_typename_typename_pair
	{
		using rtn = pattern_match_typename_typename_pair;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<template<typename, typename> class PairType, typename TypenameX, typename TypenameY>
	struct pattern_match_typename_typename_pair<PairType<TypenameX, TypenameY>>
	{
		using rtn = pattern_match_typename_typename_pair;

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

				//   signature: car, cdr.

		> using pop = typename Continuation::template result<PairType, TypenameX, TypenameY>;
	};
*/

