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

#define pnk_judgment_stem_as nik_module(patronum, natural, kernel, judgment_stem, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkjs_inductor_as_

#else

	#define PREFIX

#endif

//

/*
										  template<typename Type>
	using nik_safe(PREFIX, pattern_match_judgment_stem)			= typename pnk_judgment_stem_as::inductor::template
										  pattern_match_judgment_stem<Type>;
*/

//

										  template<typename Condition, typename Break, typename Next>
	using nik_safe(PREFIX, cp_s_judgment_stem_v_map_v_combine_v)		= typename pnk_judgment_stem_as::inductor::template
										  cp_s_judgment_stem_v_map_v_combine_v
											<Condition, Break, Next>;

										  template<typename Condition, typename Break, typename Next>
	using nik_safe(PREFIX, cp_a_judgment_stem_v_map_t_combine_v)		= typename pnk_judgment_stem_as::inductor::template
										  cp_a_judgment_stem_v_map_t_combine_v
											<Condition, Break, Next>;

										  template<typename Condition, typename Break, typename Next>
	using nik_safe(PREFIX, cp_af_judgment_stem_v_map_void_combine_void)	= typename pnk_judgment_stem_as::inductor::template
										  cp_af_judgment_stem_v_map_void_combine_void
											<Condition, Break, Next>;

//

#undef PREFIX

#undef pnk_judgment_stem_as

#include nik_size_type(undef)
