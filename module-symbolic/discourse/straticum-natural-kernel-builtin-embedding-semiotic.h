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
#define snk_builtin_ss nik_module(straticum, natural, kernel, builtin, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkb_embedding_ss_

#else

	#define PREFIX

#endif

//

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_bool_literal)						= typename snk_builtin_ss::embedding::template
											  s_bool_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char_literal)						= typename snk_builtin_ss::embedding::template
											  s_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_literal)					= typename snk_builtin_ss::embedding::template
											  s_unsigned_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_char_literal)					= typename snk_builtin_ss::embedding::template
											  s_signed_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_wchar_t_literal)					= typename snk_builtin_ss::embedding::template
											  s_wchar_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char16_t_literal)					= typename snk_builtin_ss::embedding::template
											  s_char16_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char32_t_literal)					= typename snk_builtin_ss::embedding::template
											  s_char32_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_short_literal)				= typename snk_builtin_ss::embedding::template
											  s_unsigned_short_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_short_literal)					= typename snk_builtin_ss::embedding::template
											  s_signed_short_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_int_literal)					= typename snk_builtin_ss::embedding::template
											  s_unsigned_int_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_int_literal)					= typename snk_builtin_ss::embedding::template
											  s_signed_int_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_literal)					= typename snk_builtin_ss::embedding::template
											  s_unsigned_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_long_literal)					= typename snk_builtin_ss::embedding::template
											  s_signed_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_long_literal)				= typename snk_builtin_ss::embedding::template
											  s_unsigned_long_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_long_long_literal)				= typename snk_builtin_ss::embedding::template
											  s_signed_long_long_literal<Continuation>;

//

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_bool_literal)			= snk_builtin_ss::embedding::template
											  a_bool_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_char_literal)			= snk_builtin_ss::embedding::template
											  a_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_unsigned_char_literal)		= snk_builtin_ss::embedding::template
											  a_unsigned_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_signed_char_literal)		= snk_builtin_ss::embedding::template
											  a_signed_char_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_wchar_t_literal)		= snk_builtin_ss::embedding::template
											  a_wchar_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_char16_t_literal)		= snk_builtin_ss::embedding::template
											  a_char16_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_char32_t_literal)		= snk_builtin_ss::embedding::template
											  a_char32_t_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_unsigned_short_literal)		= snk_builtin_ss::embedding::template
											  a_unsigned_short_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_signed_short_literal)		= snk_builtin_ss::embedding::template
											  a_signed_short_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_unsigned_int_literal)		= snk_builtin_ss::embedding::template
											  a_unsigned_int_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_signed_int_literal)		= snk_builtin_ss::embedding::template
											  a_signed_int_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_unsigned_long_literal)		= snk_builtin_ss::embedding::template
											  a_unsigned_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_signed_long_literal)		= snk_builtin_ss::embedding::template
											  a_signed_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_unsigned_long_long_literal)	= snk_builtin_ss::embedding::template
											  a_unsigned_long_long_literal<Continuation>;

											  template
											  <
												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr const char* nik_safe(PREFIX, a_signed_long_long_literal)	= snk_builtin_ss::embedding::template
											  a_signed_long_long_literal<Continuation>;

//

#undef PREFIX

#undef snk_builtin_ss
#undef pnk_builtin_ss

#include"undef-size_type.h"

