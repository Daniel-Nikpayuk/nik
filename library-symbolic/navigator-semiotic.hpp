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


enum struct Library : global_size_type
{
	peano_straticum,
	peano_patronum,

	straticum,
	patronum,

	dimension // filler
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_library(_library_, _reading_, _permission_)									\
															\
	nik::library													\
	<														\
		nik::Library::_library_,										\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_library_source(_path_, _division_, _reading_, _permission_)							\
															\
	nik_stringify(_path_/library-_reading_/_division_-_permission_.hpp)


