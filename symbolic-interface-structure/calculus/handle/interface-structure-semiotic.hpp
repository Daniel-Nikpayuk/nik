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
	using kind		= module;

	using rtn		= structure;

/*
	memoized_value:
*/

	template<typename Type, Type Value>
	struct memoized_value
	{
		using rtn = memoized_value;

		static constexpr Type value = Value;
	};

/*
	memoized_couple:
*/

	template<typename, typename>
	struct memoized_couple
	{
		using rtn = memoized_couple;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Type>
	struct memoized_couple<Type, Type>
	{
		using rtn = memoized_couple;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;
	};

/*
	memoized_pointer:
*/

	template<typename Type>
	struct memoized_pointer
	{
		using rtn = memoized_pointer;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Type>
	struct memoized_pointer<Type*>
	{
		using rtn = memoized_pointer;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// shrink:

		template
		<
			template<typename> class signature

			//      signature: dereference.

		> using pop = signature<Type>;
	};
};

