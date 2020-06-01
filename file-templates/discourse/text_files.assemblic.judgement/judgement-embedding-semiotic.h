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

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define snk_judgement_as nik_module(straticum, natural, kernel, judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkj_embedding_as_

#else

	#define PREFIX

#endif

//

	static constexpr void (*nik_safe(PREFIX, char_display))(char)					= snk_judgement_as::embedding::
													  char_display;

	static constexpr void (*nik_safe(PREFIX, unsigned_char_display))(unsigned char)			= snk_judgement_as::embedding::
													  unsigned_char_display;

	static constexpr void (*nik_safe(PREFIX, signed_char_display))(signed char)			= snk_judgement_as::embedding::
													  signed_char_display;

	static constexpr void (*nik_safe(PREFIX, wchar_t_display))(wchar_t)				= snk_judgement_as::embedding::
													  wchar_t_display;

	static constexpr void (*nik_safe(PREFIX, char16_t_display))(char16_t)				= snk_judgement_as::embedding::
													  char16_t_display;

	static constexpr void (*nik_safe(PREFIX, char32_t_display))(char32_t)				= snk_judgement_as::embedding::
													  char32_t_display;

	static constexpr void (*nik_safe(PREFIX, unsigned_short_display))(unsigned short)		= snk_judgement_as::embedding::
													  unsigned_short_display;

	static constexpr void (*nik_safe(PREFIX, signed_short_display))(signed short)			= snk_judgement_as::embedding::
													  signed_short_display;

	static constexpr void (*nik_safe(PREFIX, unsigned_int_display))(unsigned int)			= snk_judgement_as::embedding::
													  unsigned_int_display;

	static constexpr void (*nik_safe(PREFIX, signed_int_display))(signed int)			= snk_judgement_as::embedding::
													  signed_int_display;

	static constexpr void (*nik_safe(PREFIX, unsigned_long_display))(unsigned long)			= snk_judgement_as::embedding::
													  unsigned_long_display;

	static constexpr void (*nik_safe(PREFIX, signed_long_display))(signed long)			= snk_judgement_as::embedding::
													  signed_long_display;

	static constexpr void (*nik_safe(PREFIX, unsigned_long_long_display))(unsigned long long)	= snk_judgement_as::embedding::
													  unsigned_long_long_display;

	static constexpr void (*nik_safe(PREFIX, signed_long_long_display))(signed long long)		= snk_judgement_as::embedding::
													  signed_long_long_display;

//

#undef PREFIX

#undef snk_judgement_as
#undef pnk_builtin_ss

#include"undef-size_type.h"

