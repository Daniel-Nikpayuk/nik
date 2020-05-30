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

	#define PREFIX		snkj_identity_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											bool Value1,
											bool Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_bool_equal)					= typename snk_judgement_as::identity::template
										  s_is_bool_equal<Value1, Value2, Continuation>;

										  template
										  <
											char Value1,
											char Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char_equal)					= typename snk_judgement_as::identity::template
										  s_is_char_equal<Value1, Value2, Continuation>;

										  template
										  <
											unsigned char Value1,
											unsigned char Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_char_equal)			= typename snk_judgement_as::identity::template
										  s_is_unsigned_char_equal<Value1, Value2, Continuation>;

										  template
										  <
											signed char Value1,
											signed char Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_char_equal)				= typename snk_judgement_as::identity::template
										  s_is_signed_char_equal<Value1, Value2, Continuation>;

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_wchar_t_equal)				= typename snk_judgement_as::identity::template
										  s_is_wchar_t_equal<Value1, Value2, Continuation>;

										  template
										  <
											char16_t Value1,
											char16_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char16_t_equal)				= typename snk_judgement_as::identity::template
										  s_is_char16_t_equal<Value1, Value2, Continuation>;

										  template
										  <
											char32_t Value1,
											char32_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char32_t_equal)				= typename snk_judgement_as::identity::template
										  s_is_char32_t_equal<Value1, Value2, Continuation>;

										  template
										  <
											unsigned short Value1,
											unsigned short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_short_equal)			= typename snk_judgement_as::identity::template
										  s_is_unsigned_short_equal<Value1, Value2, Continuation>;

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_short_equal)				= typename snk_judgement_as::identity::template
										  s_is_signed_short_equal<Value1, Value2, Continuation>;

										  template
										  <
											unsigned int Value1,
											unsigned int Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_int_equal)				= typename snk_judgement_as::identity::template
										  s_is_unsigned_int_equal<Value1, Value2, Continuation>;

										  template
										  <
											signed int Value1,
											signed int Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_int_equal)				= typename snk_judgement_as::identity::template
										  s_is_signed_int_equal<Value1, Value2, Continuation>;

										  template
										  <
											unsigned long Value1,
											unsigned long Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_equal)			= typename snk_judgement_as::identity::template
										  s_is_unsigned_long_equal<Value1, Value2, Continuation>;

										  template
										  <
											signed long Value1,
											signed long Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_equal)				= typename snk_judgement_as::identity::template
										  s_is_signed_long_equal<Value1, Value2, Continuation>;

										  template
										  <
											unsigned long long Value1,
											unsigned long long Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_long_equal)			= typename snk_judgement_as::identity::template
										  s_is_unsigned_long_long_equal<Value1, Value2, Continuation>;

										  template
										  <
											signed long long Value1,
											signed long long Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_long_equal)			= typename snk_judgement_as::identity::template
										  s_is_signed_long_long_equal<Value1, Value2, Continuation>;

//

	static constexpr bool (*nik_safe(PREFIX, p_is_bool_equal))(bool, bool) =
	snk_judgement_as::identity::p_is_bool_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_char_equal))(char, char) =
	snk_judgement_as::identity::p_is_char_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_unsigned_char_equal))(unsigned char, unsigned char) =
	snk_judgement_as::identity::p_is_unsigned_char_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_signed_char_equal))(signed char, signed char) =
	snk_judgement_as::identity::p_is_signed_char_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_wchar_t_equal))(wchar_t, wchar_t) =
	snk_judgement_as::identity::p_is_wchar_t_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_char16_t_equal))(char16_t, char16_t) =
	snk_judgement_as::identity::p_is_char16_t_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_char32_t_equal))(char32_t, char32_t) =
	snk_judgement_as::identity::p_is_char32_t_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_unsigned_short_equal))(unsigned short, unsigned short) =
	snk_judgement_as::identity::p_is_unsigned_short_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_signed_short_equal))(signed short, signed short) =
	snk_judgement_as::identity::p_is_signed_short_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_unsigned_int_equal))(unsigned int, unsigned int) =
	snk_judgement_as::identity::p_is_unsigned_int_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_signed_int_equal))(signed int, signed int) =
	snk_judgement_as::identity::p_is_signed_int_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_unsigned_long_equal))(unsigned long, unsigned long) =
	snk_judgement_as::identity::p_is_unsigned_long_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_signed_long_equal))(signed long, signed long) =
	snk_judgement_as::identity::p_is_signed_long_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_unsigned_long_long_equal))(unsigned long long, unsigned long long) =
	snk_judgement_as::identity::p_is_unsigned_long_long_equal;

	static constexpr bool (*nik_safe(PREFIX, p_is_signed_long_long_equal))(signed long long, signed long long) =
	snk_judgement_as::identity::p_is_signed_long_long_equal;

//

#undef PREFIX

#undef snk_judgement_as
#undef pnk_builtin_ss

#include"undef-size_type.h"

