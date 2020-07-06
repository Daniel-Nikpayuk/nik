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

	#define PREFIX		pnkjl_identity_as_

#else

	#define PREFIX

#endif

//

/*
										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_judgment_list)				= typename pnk_judgment_list_as::identity::template
										  s_is_judgment_list<Type, Continuation, Kind, ListKind>;
*/

	using nik_safe(PREFIX, ch_a_v_map_v_combine_v_to_value_is_empty)	= typename pnk_judgment_list_as::identity::
										  ch_a_v_map_v_combine_v_to_value_is_empty;

	using nik_safe(PREFIX, ch_a_v_map_t_combine_v_to_value_is_empty)	= typename pnk_judgment_list_as::identity::
										  ch_a_v_map_t_combine_v_to_value_is_empty;

//

										  template
										  <
											typename Type, typename List,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_list_is_empty)	= pnk_judgment_list_as::identity::template
										  a_judgment_list_is_empty
											<Type, List, Continuation, Image>;

/*
										  template
										  <
											typename Type,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_judgment_list)		= pnk_judgment_list_as::identity::template
										  a_is_judgment_list
											<Type, Continuation, Image>;
*/

//

/*
	static constexpr void (*nik_safe(PREFIX, p_judgment_list_))() =
		pnk_judgment_list_as::identity::p_judgment_list_;
*/

//

#undef PREFIX

#undef pnk_judgment_list_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
