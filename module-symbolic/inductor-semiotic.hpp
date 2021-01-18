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


template
<
	Library		library_enum,
	Universe	universe_enum,
	Language	language_enum,
	Module		module_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type = global_size_type

> struct module
{
	// Checks to see if a given language has been partially specialized.

	template<typename Continuation, typename Inductor>
	using symbolic_match = typename Continuation::template result<Inductor, bool, false>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename>
struct pattern_match_module
{
	template<typename Continuation, typename Inductor>
	using symbolic_match = typename Continuation::template result<Inductor, bool, false>;
};

template
<
	Library		library_enum,
	Universe	universe_enum,
	Language	language_enum,
	Module		module_enum,

	Reading		reading_enum,
	Permission	permission_enum,

	typename	size_type

> struct pattern_match_module<module<library_enum, universe_enum, language_enum, module_enum, reading_enum, permission_enum, size_type>>
{
	template<typename Continuation, typename Inductor>
	using symbolic_match = typename Continuation::template result<Inductor, bool, true>;

	template<typename Continuation, typename Inductor>
	using symbolic_induct = typename Continuation::template result
	<
		Inductor, library_enum, universe_enum, language_enum, module_enum, reading_enum, permission_enum, size_type
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_begin_module(_library_, _universe_, _language_, _module_, _reading_, _permission_)				\
															\
	template<typename size_type>											\
	struct module													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
		nik::Language::_language_,										\
		nik::Module::_module_,											\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		size_type												\
	>														\
	{														\
		template<typename Continuation, typename Inductor>							\
		using symbolic_match = typename Continuation::template result<Inductor, bool, true>;


#define nik_end_module(_library_, _universe_, _language_, _module_, _reading_, _permission_)				\
															\
	};


