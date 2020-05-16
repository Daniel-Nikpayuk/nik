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


template
<
	Library		library_enum,
	Universe	universe_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type = global_size_type

> struct universe
{
	// Checks to see if a given universe has been partially specialized.

	template<typename Continuation>
	using match = typename Continuation::template result<false>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename>
struct memoized_universe
{
	template<typename Continuation>
	using match = typename Continuation::template result<false>;
};

template
<
	Library		library_enum,
	Universe	universe_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type

> struct memoized_universe<universe<library_enum, universe_enum, reading_enum, permission_enum, size_type>>
{
	template<typename Continuation>
	using match = typename Continuation::template result<true>;

	template<typename Continuation>
	using induct = typename Continuation::template result
	<
		library_enum, universe_enum, reading_enum, permission_enum, size_type
	>;
};


