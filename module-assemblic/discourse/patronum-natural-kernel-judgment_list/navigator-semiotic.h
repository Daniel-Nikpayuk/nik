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

#include nik_size_type(define)

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define pnk_judgment_list_as nik_module(patronum, natural, kernel, judgment_list, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkjl_navigator_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type, typename List,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_values
										  >
	using nik_safe(PREFIX, s_judgment_list_cdr)				= typename pnk_judgment_list_as::navigator::template
										  s_judgment_list_cdr
											<Type, List, Continuation>;

										  template
										  <
											typename Type,
											typename List1, typename List2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_values
										  >
	using nik_safe(PREFIX, s_judgment_list_catenate)			= typename pnk_judgment_list_as::navigator::template
										  s_judgment_list_catenate
											<Type, List1, List2, Continuation>;

//

										  template
										  <
											typename Type, typename List,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_a_grow_to_value,

											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_list_car)		= pnk_judgment_list_as::navigator::template
										  a_judgment_list_car<Type, List, Continuation, Image>;

//

/*
	static constexpr void (*nik_safe(PREFIX, p_judgment_list_))() =
		pnk_judgment_list_as::navigator::p_judgment_list_;
*/

//

#undef PREFIX

#undef pnk_judgment_list_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
