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

	#define IS_EQUAL	partui_is_equal
	#define IS_TUPLE	partui_is_tuple
	#define IS_NULL		partui_is_null

#else

	#define IS_EQUAL	is_equal
	#define IS_TUPLE	is_tuple
	#define IS_NULL		is_null

#endif

//

				  template<typename Exp1, typename Exp2>
using IS_EQUAL			= typename Tuple::identity::template is_equal<Exp1, Exp2>;

				  template<typename Exp>
using IS_TUPLE			= typename Tuple::identity::template is_tuple<Exp>;

				  template<typename Exp>
using IS_NULL			= typename Tuple::identity::template is_null<Exp>;

//

#undef IS_EQUAL
#undef IS_TUPLE
#undef IS_NULL

