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

#define snk_judgement_as nik_module(straticum, natural, kernel, judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkj_inductor_as_

#else

	#define PREFIX

#endif

//

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_char_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_char_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_unsigned_char_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_unsigned_char_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_signed_char_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_signed_char_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_wchar_t_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_wchar_t_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_char16_t_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_char16_t_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_char32_t_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_char32_t_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_unsigned_short_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_unsigned_short_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_signed_short_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_signed_short_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_unsigned_int_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_unsigned_int_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_signed_int_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_signed_int_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_unsigned_long_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_unsigned_long_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_signed_long_value)				= typename snk_judgement_as::inductor::template
											  pattern_match_signed_long_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_unsigned_long_long_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_unsigned_long_long_value<Value>;

											  template<auto Value>
	using nik_safe(PREFIX, pattern_match_signed_long_long_value)			= typename snk_judgement_as::inductor::template
											  pattern_match_signed_long_long_value<Value>;


//

#undef PREFIX

#undef snk_judgement_as

#include"undef-size_type.h"

