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
#define snk_unsigned_char_judgment_as nik_module(straticum, natural, kernel, unsigned_char_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkucj_navigator_as_

#else

	#define PREFIX

#endif

//

											  template
											  <
												unsigned char Value1,
												unsigned char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_add)				= typename snk_unsigned_char_judgment_as::navigator::template
											  s_unsigned_char_judgment_add
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												unsigned char Value1,
												unsigned char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_multiply)				= typename snk_unsigned_char_judgment_as::navigator::template
											  s_unsigned_char_judgment_multiply
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												unsigned char Value1,
												unsigned char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_subtract)				= typename snk_unsigned_char_judgment_as::navigator::template
											  s_unsigned_char_judgment_subtract
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												unsigned char Value1,
												unsigned char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_divide)				= typename snk_unsigned_char_judgment_as::navigator::template
											  s_unsigned_char_judgment_divide
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												unsigned char Value1,
												unsigned char Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_modulo)				= typename snk_unsigned_char_judgment_as::navigator::template
											  s_unsigned_char_judgment_modulo
											<Value1, Value2, Continuation, Kind, ListKind>;

//

	static constexpr unsigned char (*nik_safe(PREFIX, p_unsigned_char_judgment_add))(unsigned char, unsigned char) =
		snk_unsigned_char_judgment_as::navigator::p_unsigned_char_judgment_add;

	static constexpr unsigned char (*nik_safe(PREFIX, p_unsigned_char_judgment_multiply))(unsigned char, unsigned char) =
		snk_unsigned_char_judgment_as::navigator::p_unsigned_char_judgment_multiply;

	static constexpr unsigned char (*nik_safe(PREFIX, p_unsigned_char_judgment_subtract))(unsigned char, unsigned char) =
		snk_unsigned_char_judgment_as::navigator::p_unsigned_char_judgment_subtract;

	static constexpr unsigned char (*nik_safe(PREFIX, p_unsigned_char_judgment_divide))(unsigned char, unsigned char) =
		snk_unsigned_char_judgment_as::navigator::p_unsigned_char_judgment_divide;

	static constexpr unsigned char (*nik_safe(PREFIX, p_unsigned_char_judgment_modulo))(unsigned char, unsigned char) =
		snk_unsigned_char_judgment_as::navigator::p_unsigned_char_judgment_modulo;

//

#undef PREFIX

#undef snk_unsigned_char_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
