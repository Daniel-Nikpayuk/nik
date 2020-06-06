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
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_bool_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_bool_to_judgment<Value, Continuation>;

											  template
											  <
												char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char_to_judgment<Value, Continuation>;

											  template
											  <
												unsigned char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_char_to_judgment<Value, Continuation>;

											  template
											  <
												signed char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_char_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_char_to_judgment<Value, Continuation>;

											  template
											  <
												wchar_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_wchar_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_wchar_t_to_judgment<Value, Continuation>;

											  template
											  <
												char16_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char16_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char16_t_to_judgment<Value, Continuation>;

											  template
											  <
												char32_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_char32_t_to_judgment)					= typename snk_builtin_ss::structure::template
											  s_char32_t_to_judgment<Value, Continuation>;

											  template
											  <
												unsigned short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_short_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_short_to_judgment<Value, Continuation>;

											  template
											  <
												signed short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_short_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_short_to_judgment<Value, Continuation>;

											  template
											  <
												unsigned int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_int_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_int_to_judgment<Value, Continuation>;

											  template
											  <
												signed int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_int_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_int_to_judgment<Value, Continuation>;

											  template
											  <
												unsigned long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_unsigned_long_to_judgment<Value, Continuation>;

											  template
											  <
												signed long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_long_to_judgment<Value, Continuation>;

											  template
											  <
												unsigned long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_unsigned_long_long_to_judgment)			= typename snk_builtin_ss::structure::template
											  s_unsigned_long_long_to_judgment
												<Value, Continuation>;

											  template
											  <
												signed long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_symbolic_values
											  >
	using nik_safe(PREFIX, s_signed_long_long_to_judgment)				= typename snk_builtin_ss::structure::template
											  s_signed_long_long_to_judgment
												<Value, Continuation>;

//

											  template
											  <
												typename Kind, bool Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_bool_to_judgment)			= snk_builtin_ss::structure::template
											  a_bool_to_judgment<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_char_to_judgment)			= snk_builtin_ss::structure::template
											  a_char_to_judgment<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, unsigned char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_unsigned_char_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_char_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, signed char Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_signed_char_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_char_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, wchar_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_wchar_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_wchar_t_to_judgment<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, char16_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_char16_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_char16_t_to_judgment<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, char32_t Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_char32_t_to_judgment)			= snk_builtin_ss::structure::template
											  a_char32_t_to_judgment<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, unsigned short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_unsigned_short_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_short_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, signed short Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_signed_short_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_short_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, unsigned int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_unsigned_int_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_int_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, signed int Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_signed_int_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_int_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, unsigned long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_unsigned_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_unsigned_long_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, signed long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_signed_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_long_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, unsigned long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_unsigned_long_long_to_judgment)	= snk_builtin_ss::structure::template
											  a_unsigned_long_long_to_judgment
												<Kind, Value, Continuation>;

											  template
											  <
												typename Kind, signed long long Value,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_assemblic_value
											  >
	static constexpr Kind nik_safe(PREFIX, a_signed_long_long_to_judgment)		= snk_builtin_ss::structure::template
											  a_signed_long_long_to_judgment
												<Kind, Value, Continuation>;

//

#undef PREFIX

#undef snk_builtin_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
