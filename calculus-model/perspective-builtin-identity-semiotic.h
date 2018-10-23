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

#include"define-size_type.h"

#ifdef safe_name

	#define PREFIX		perbui_

#else

	#define PREFIX

#endif

//

							  template<typename Type1, typename Type2>
	using nik_safe(PREFIX, is_equal)		= typename nik_branch(builtin, calculus, semiotic)::identity::template
							  is_equal<Type1, Type2>;

							  template<typename List>
	using nik_safe(PREFIX, is_untyped_list)		= typename nik_branch(builtin, calculus, semiotic)::identity::template
							  is_untyped_list<List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, is_typed_list)		= typename nik_branch(builtin, calculus, semiotic)::identity::template
							  is_typed_list<Type, List>;

							  template<typename List>
	using nik_safe(PREFIX, is_untyped_null)		= typename nik_branch(builtin, calculus, semiotic)::identity::template
							  is_untyped_null<List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, is_typed_null)		= typename nik_branch(builtin, calculus, semiotic)::identity::template
							  is_typed_null<Type, List>;

//

#undef PREFIX

#include"undef-size_type.h"

