/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	// memoized_pointer:

	template<typename Type>
	struct memoized_pointer
	{
		template<typename Continuation>
		using match = typename Continuation::template result<false>;
	};

	template<typename Type>
	struct memoized_pointer<Type*>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		// shrink:

		template<typename Continuation>
		using induct = typename Continuation::template result<Type>;
	};

	// ch_bool_symbol

	struct ch_bool_symbol
	{
		template<bool Value>
		using result = typename ch_symbol::template result<bool, Value>;
	};
};

