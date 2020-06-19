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
#define snk_signed_char_judgment_as nik_module(straticum, natural, kernel, signed_char_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkscj_navigator_as_

#else

	#define PREFIX

#endif

//

											  template
											  <
												signed char Value1,
												signed char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = signed char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_add)				= typename snk_signed_char_judgment_as::navigator::template
											  s_signed_char_judgment_add
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												signed char Value1,
												signed char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = signed char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_multiply)				= typename snk_signed_char_judgment_as::navigator::template
											  s_signed_char_judgment_multiply
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												signed char Value1,
												signed char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = signed char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_subtract)				= typename snk_signed_char_judgment_as::navigator::template
											  s_signed_char_judgment_subtract
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												signed char Value1,
												signed char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = signed char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_divide)				= typename snk_signed_char_judgment_as::navigator::template
											  s_signed_char_judgment_divide
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												signed char Value1,
												signed char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = signed char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_modulo)				= typename snk_signed_char_judgment_as::navigator::template
											  s_signed_char_judgment_modulo
											<Value1, Value2, Continuation, Kind, ListKind>;

//

	static constexpr signed char (*nik_safe(PREFIX, p_signed_char_judgment_add))(signed char, signed char) =
		snk_signed_char_judgment_as::navigator::p_signed_char_judgment_add;

	static constexpr signed char (*nik_safe(PREFIX, p_signed_char_judgment_multiply))(signed char, signed char) =
		snk_signed_char_judgment_as::navigator::p_signed_char_judgment_multiply;

	static constexpr signed char (*nik_safe(PREFIX, p_signed_char_judgment_subtract))(signed char, signed char) =
		snk_signed_char_judgment_as::navigator::p_signed_char_judgment_subtract;

	static constexpr signed char (*nik_safe(PREFIX, p_signed_char_judgment_divide))(signed char, signed char) =
		snk_signed_char_judgment_as::navigator::p_signed_char_judgment_divide;

	static constexpr signed char (*nik_safe(PREFIX, p_signed_char_judgment_modulo))(signed char, signed char) =
		snk_signed_char_judgment_as::navigator::p_signed_char_judgment_modulo;

//

#undef PREFIX

#undef snk_signed_char_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
