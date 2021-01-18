/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#define snk_builtin_ss nik_module(straticum, natural, kernel, builtin, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkb_inductor_ss_

#else

	#define PREFIX

#endif

//

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_bool)					= typename snk_builtin_ss::inductor::template
											  pattern_match_bool<Exp>;

//

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_char)				= typename snk_builtin_ss::inductor::template
											  pattern_match_unsigned_char<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_char)				= typename snk_builtin_ss::inductor::template
											  pattern_match_signed_char<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_short)				= typename snk_builtin_ss::inductor::template
											  pattern_match_unsigned_short<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_short)				= typename snk_builtin_ss::inductor::template
											  pattern_match_signed_short<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_int)				= typename snk_builtin_ss::inductor::template
											  pattern_match_unsigned_int<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_int)				= typename snk_builtin_ss::inductor::template
											  pattern_match_signed_int<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long)				= typename snk_builtin_ss::inductor::template
											  pattern_match_unsigned_long<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long)				= typename snk_builtin_ss::inductor::template
											  pattern_match_signed_long<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_long_long)			= typename snk_builtin_ss::inductor::template
											  pattern_match_unsigned_long_long<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_signed_long_long)				= typename snk_builtin_ss::inductor::template
											  pattern_match_signed_long_long<Exp>;

//

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char)					= typename snk_builtin_ss::inductor::template
											  pattern_match_char<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_wchar_t)					= typename snk_builtin_ss::inductor::template
											  pattern_match_wchar_t<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char16_t)					= typename snk_builtin_ss::inductor::template
											  pattern_match_char16_t<Exp>;

											  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_char32_t)					= typename snk_builtin_ss::inductor::template
											  pattern_match_char32_t<Exp>;

//

#undef PREFIX

#undef snk_builtin_ss

#include nik_size_type(undef)
