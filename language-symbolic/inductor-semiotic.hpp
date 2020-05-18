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
	Language	language_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type = global_size_type

> struct language
{
	// Checks to see if a given language has been partially specialized.

	template<typename Continuation>
	using match = typename Continuation::template result<bool, false>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename>
struct memoized_language
{
	template<typename Continuation>
	using match = typename Continuation::template result<bool, false>;
};

template
<
	Library		library_enum,
	Universe	universe_enum,
	Language	language_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type

> struct memoized_language<language<library_enum, universe_enum, language_enum, reading_enum, permission_enum, size_type>>
{
	template<typename Continuation>
	using match = typename Continuation::template result<bool, true>;

	template<typename Continuation>
	using induct = typename Continuation::template result
	<
		library_enum, universe_enum, language_enum, reading_enum, permission_enum, size_type
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_begin_language(_library_, _universe_, _language_, _reading_, _permission_)					\
															\
	template<typename size_type>											\
	struct language													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
		nik::Language::_language_,										\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		size_type												\
	>														\
	{														\
		template<typename Continuation>										\
		using match = typename Continuation::template result<bool, true>;


#define nik_end_language(_library_, _universe_, _language_, _reading_, _permission_)					\
															\
	};


