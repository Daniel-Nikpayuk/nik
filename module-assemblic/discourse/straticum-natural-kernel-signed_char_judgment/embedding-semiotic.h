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

	#define PREFIX		snkscj_embedding_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											signed char Value,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = signed char,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_signed_char_judgment_value)				= typename snk_signed_char_judgment_as::embedding::template
										  s_signed_char_judgment_value
											<Value, Continuation, Kind, ListKind>;

//

	static constexpr void (*nik_safe(PREFIX, p_signed_char_judgment_display))(signed char) =
		snk_signed_char_judgment_as::embedding::p_signed_char_judgment_display;

//

#undef PREFIX

#undef snk_signed_char_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
