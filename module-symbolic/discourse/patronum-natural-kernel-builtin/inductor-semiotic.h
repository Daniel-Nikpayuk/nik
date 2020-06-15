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

#ifdef safe_name

	#define PREFIX		pnkb_inductor_ss_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, ch_s_grow_to_type)					= typename pnk_builtin_ss::inductor::
											  ch_s_grow_to_type;

	using nik_safe(PREFIX, ch_s_grow_to_types)					= typename pnk_builtin_ss::inductor::
											  ch_s_grow_to_types;

	using nik_safe(PREFIX, ch_s_t_map_t_mutate_to_type)				= typename pnk_builtin_ss::inductor::
											  ch_s_t_map_t_mutate_to_type;

	using nik_safe(PREFIX, ch_s_t_map_t_mutate_to_types)				= typename pnk_builtin_ss::inductor::
											  ch_s_t_map_t_mutate_to_types;

	using nik_safe(PREFIX, ch_s_tt_zip_t_mutate_to_type)				= typename pnk_builtin_ss::inductor::
											  ch_s_tt_zip_t_mutate_to_type;

	using nik_safe(PREFIX, ch_s_tt_zip_t_mutate_to_types)				= typename pnk_builtin_ss::inductor::
											  ch_s_tt_zip_t_mutate_to_types;

//

	using nik_safe(PREFIX, ch_s_match_to_value)					= typename pnk_builtin_ss::inductor::
											  ch_s_match_to_value;

	using nik_safe(PREFIX, ch_s_grow_to_values)					= typename pnk_builtin_ss::inductor::
											  ch_s_grow_to_values;

	using nik_safe(PREFIX, ch_s_v_map_v_mutate_to_values)				= typename pnk_builtin_ss::inductor::
											  ch_s_v_map_v_mutate_to_values;

	using nik_safe(PREFIX, ch_s_vv_zip_v_mutate_to_values)				= typename pnk_builtin_ss::inductor::
											  ch_s_vv_zip_v_mutate_to_values;

//

	using nik_safe(PREFIX, ch_a_match_to_value)					= typename pnk_builtin_ss::inductor::
											  ch_a_match_to_value;

	using nik_safe(PREFIX, ch_a_grow_to_value)					= typename pnk_builtin_ss::inductor::
											  ch_a_grow_to_value;

	using nik_safe(PREFIX, ch_a_v_map_v_mutate_to_value)				= typename pnk_builtin_ss::inductor::
											  ch_a_v_map_v_mutate_to_value;

	using nik_safe(PREFIX, ch_a_vv_zip_v_mutate_to_value)				= typename pnk_builtin_ss::inductor::
											  ch_a_vv_zip_v_mutate_to_value;

//

											  template<typename Type>
	using nik_safe(PREFIX, dependent_memoization)					= typename pnk_builtin_ss::inductor::template
											  dependent_memoization<Type>;

	using nik_safe(PREFIX, independent_memoization)					= typename pnk_builtin_ss::inductor::
											  independent_memoization;

//

#undef PREFIX

#undef pnk_builtin_ss

#include nik_size_type(undef)
