/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef NORMAL_H
#define NORMAL_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"lazy.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct metaric
	{
		static_assert(false, "This is not a valid metaric module!");
	};

	#include nik_source(., metaric, empty, semiotic)

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct grammaric
	{
		static_assert(false, "This is not a valid grammaric module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct numeric
	{
		static_assert(false, "This is not a valid numeric module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct literic
	{
		static_assert(false, "This is not a valid literic module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct graphic
	{
		static_assert(false, "This is not a valid graphic module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct phonetic
	{
		static_assert(false, "This is not a valid phonetic module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct kinetic
	{
		static_assert(false, "This is not a valid kinetic module!");
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct interic
	{
		static_assert(false, "This is not a valid interic module!");
	};
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
