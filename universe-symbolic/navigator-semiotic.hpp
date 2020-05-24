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


enum struct Universe : global_size_type
{
// straticum, patronum:

	natural,
	real,
	analytic,

// textual:

	calculus,
	scheme,
	hott,

// hardware:

	numeric,
	literic,
	graphic,
	kinetic,
	phonetic,
	interic,

	dimension // filler
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_universe(_library_, _universe_, _reading_, _permission_)							\
															\
	nik::universe													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_universe_source(_path_, _division_, _reading_, _permission_)						\
															\
	nik_stringify(_path_/universe-_reading_/_division_-_permission_.hpp)


