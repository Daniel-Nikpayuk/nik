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
	// builtin types:

	// void_ptr values:

/*
	void_ptr values aren't generally considered meaningful as template parameters,
	this inductor is only here to maintain the narrative design of this library.
*/

	template<auto>
	struct memoized_void_ptr
	{
		template<typename Continuation>
		static constexpr bool match = Continuation::template result<bool, false>;
	};

	template<void_ptr Value>
	struct memoized_void_ptr<Value>
	{
		template<typename Continuation>
		static constexpr bool match = Continuation::template result<bool, true>;

		template<typename Continuation>
		static constexpr void_ptr induct = Continuation::template result<void_ptr, Value>;
	};
};

