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

#define pnk_judgment_list_as nik_module(patronum, natural, kernel, judgment_list, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkjl_inductor_as_

#else

	#define PREFIX

#endif

//

										  template<typename Type, typename Exp>
	using nik_safe(PREFIX, pattern_match_judgment_list)			= typename pnk_judgment_list_as::inductor::template
										  pattern_match_judgment_list<Type, Exp>;

//

	static constexpr SIZE_TYPE nik_safe(PREFIX, default_depth)		= pnk_judgment_list_as::inductor::
										  default_depth;

	static constexpr SIZE_TYPE nik_safe(PREFIX, default_count)		= pnk_judgment_list_as::inductor::
										  default_count;

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_v_map_v_combine_v_apply_map)		= typename pnk_judgment_list_as::inductor::template
										  cp_s_v_map_v_combine_v_apply_map
											<Continuation>;

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_v_map_v_combine_v_apply_combine)		= typename pnk_judgment_list_as::inductor::template
										  cp_s_v_map_v_combine_v_apply_combine
											<Continuation>;

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_v_map_v_combine_v_apply_identity_map_then_combine) = typename pnk_judgment_list_as::inductor::template
										  cp_s_v_map_v_combine_v_apply_identity_map_then_combine
											<Continuation>;

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_v_map_t_combine_v_apply_map)		= typename pnk_judgment_list_as::inductor::template
										  cp_a_v_map_t_combine_v_apply_map
											<Continuation>;

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_v_map_t_combine_v_apply_combine)		= typename pnk_judgment_list_as::inductor::template
										  cp_a_v_map_t_combine_v_apply_combine
											<Continuation>;

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_af_v_map_void_combine_void_apply)		= typename pnk_judgment_list_as::inductor::template
										  cp_af_v_map_void_combine_void_apply
											<Continuation>;

//

#undef PREFIX

#undef pnk_judgment_list_as

#include nik_size_type(undef)
