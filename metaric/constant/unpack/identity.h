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

#ifdef name_safe

	#define IS_EQUAL	met_cons_is_equal
	#define IS_CONSTANT	met_cons_is_constant

#else

	#define IS_EQUAL	is_equal
	#define IS_CONSTANT	is_constant

#endif

//

				  template<typename Exp1, typename Exp2>
using IS_EQUAL			= typename Constant::identity::template is_equal<Exp1, Exp2>;

				  template<typename Exp>
using IS_CONSTANT		= typename Constant::identity::template is_constant<Exp>;

//

#undef IS_EQUAL
#undef IS_CONSTANT

