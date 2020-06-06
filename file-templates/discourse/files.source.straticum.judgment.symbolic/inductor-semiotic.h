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

#include"define-size_type.h"

#define snk_judgment_ss nik_module(straticum, natural, kernel, judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkj_inductor_ss_

#else

	#define PREFIX

#endif

//

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_bool_judgment)				= typename snk_judgment_ss::inductor::template
											  pattern_match_bool_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char_judgment)				= typename snk_judgment_ss::inductor::template
											  pattern_match_char_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_char_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_char_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_char_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_char_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_wchar_t_judgment)				= typename snk_judgment_ss::inductor::template
											  pattern_match_wchar_t_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char16_t_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_char16_t_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char32_t_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_char32_t_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_short_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_short_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_short_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_short_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_int_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_int_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_int_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_int_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_long_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_long_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long_long_judgment)		= snk_judgment_ss::inductor::template
											  pattern_match_unsigned_long_long_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long_long_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_long_long_judgment<Exp>;

//

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_bool_dependent_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_bool_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char_dependent_judgment)			= typename snk_judgment_ss::inductor::template
											  pattern_match_char_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_char_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_char_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_char_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_char_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_wchar_t_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_wchar_t_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char16_t_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_char16_t_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char32_t_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_char32_t_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_short_dependent_judgment)	= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_short_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_short_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_short_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_int_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_int_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_int_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_int_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_unsigned_long_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long_dependent_judgment)		= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_long_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long_long_dependent_judgment)	= snk_judgment_ss::inductor::template
											  pattern_match_unsigned_long_long_dependent_judgment<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long_long_dependent_judgment)	= typename snk_judgment_ss::inductor::template
											  pattern_match_signed_long_long_dependent_judgment<Exp>;

//

#undef PREFIX

#undef snk_judgment_ss

#include"undef-size_type.h"

