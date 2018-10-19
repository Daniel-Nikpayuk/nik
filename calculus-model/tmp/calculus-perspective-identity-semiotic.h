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

#ifdef safe_name

	#define IS_EQUAL_STRUCTURE		calpei_is_equal_structure

#else

	#define IS_EQUAL_STRUCTURE		is_equal_structure

#endif

//

				  template<typename Type1, typename Type2>
using IS_EQUAL_STRUCTURE	= typename calculus::identity::template is_equal_structure<Type1, Type2>;

//

#undef IS_EQUAL_STRUCTURE

