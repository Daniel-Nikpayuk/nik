/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct structure
{
	using kind						= module;

	using rtn						= structure;

/*
	memoized_list:
*/

	template<typename, typename, typename>
	struct builtin_builtin_pair
	{
		using rtn = builtin_builtin_pair;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<false>;
	};

	template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
	struct builtin_builtin_pair<TypeX, TypeY, PairType<ValueX, ValueY>>
	{
		using rtn = builtin_builtin_pair;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<true>;

		// shrink:

		template
		<
			typename Continuation,

				//   signature: car, cdr.

		> using pop = typename Continuation::template result<TypeX, TypeY, PairType, ValueX, ValueY>;
	};
};

