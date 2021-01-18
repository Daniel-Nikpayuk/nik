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

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define snk_builtin_ss nik_module(straticum, natural, kernel, builtin, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkb_structure_ss_

#else

	#define PREFIX

#endif

//

											  template
											  <
												bool Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_bool_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_bool_to_judgment
												<Value, Continuation>;

//

											  template
											  <
												unsigned char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_char_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_signed_char_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_char_to_judgment
												<Value, Continuation>;

											  template
											  <
												unsigned short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_unsigned_short_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_short_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_signed_short_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_short_to_judgment
												<Value, Continuation>;

											  template
											  <
												unsigned int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_unsigned_int_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_int_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_signed_int_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_int_to_judgment
												<Value, Continuation>;

											  template
											  <
												unsigned long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_long_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_signed_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_long_to_judgment
												<Value, Continuation>;

											  template
											  <
												unsigned long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_long_to_judgment)			= typename snk_builtin_ss::structure::template
											  s_unsigned_long_long_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_signed_long_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_long_long_to_judgment
												<Value, Continuation>;

//

											  template
											  <
												char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_char_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char_to_judgment
												<Value, Continuation>;

											  template
											  <
												wchar_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_wchar_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_wchar_t_to_judgment
												<Value, Continuation>;

											  template
											  <
												char16_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_char16_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char16_t_to_judgment
												<Value, Continuation>;

											  template
											  <
												char32_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_grow_to_values
											  >
	using nik_safe(PREFIX, s_char32_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char32_t_to_judgment
												<Value, Continuation>;

//

											  template
											  <
												bool Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = bool
											  >
	static constexpr Image nik_safe(PREFIX, a_bool_to_judgment)			= snk_builtin_ss::structure::template
											  a_bool_to_judgment
												<Value, Continuation, Image>;

//

											  template
											  <
												unsigned char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = unsigned char
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_char_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												signed char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = signed char
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_char_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_char_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												unsigned short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = unsigned short
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_short_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_short_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												signed short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = signed short
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_short_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_short_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												unsigned int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = unsigned int
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_int_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_int_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												signed int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = signed int
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_int_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_int_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												unsigned long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = unsigned long
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_long_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												signed long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = signed long
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_long_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												unsigned long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = unsigned long long
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_long_long_to_judgment)	= snk_builtin_ss::structure::template
											  a_unsigned_long_long_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												signed long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = signed long long
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_long_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_long_long_to_judgment
												<Value, Continuation, Image>;

//

											  template
											  <
												char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = char
											  >
	static constexpr Image nik_safe(PREFIX, a_char_to_judgment)			= snk_builtin_ss::structure::template
											  a_char_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												wchar_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = wchar_t
											  >
	static constexpr Image nik_safe(PREFIX, a_wchar_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_wchar_t_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												char16_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = char16_t
											  >
	static constexpr Image nik_safe(PREFIX, a_char16_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_char16_t_to_judgment
												<Value, Continuation, Image>;

											  template
											  <
												char32_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_a_grow_to_value,

												typename Image = char32_t
											  >
	static constexpr Image nik_safe(PREFIX, a_char32_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_char32_t_to_judgment
												<Value, Continuation, Image>;

//

#undef PREFIX

#undef snk_builtin_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
