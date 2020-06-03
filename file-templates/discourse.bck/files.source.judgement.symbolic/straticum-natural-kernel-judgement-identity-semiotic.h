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
#define snk_judgement_ss nik_module(straticum, natural, kernel, judgement, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkj_identity_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_bool_judgement)				= typename snk_judgement_ss::identity::template
										  s_is_bool_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char_judgement)				= typename snk_judgement_ss::identity::template
										  s_is_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_char_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_unsigned_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_char_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_signed_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_wchar_t_judgement)				= typename snk_judgement_ss::identity::template
										  s_is_wchar_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char16_t_judgement)				= typename snk_judgement_ss::identity::template
										  s_is_char16_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char32_t_judgement)				= typename snk_judgement_ss::identity::template
										  s_is_char32_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_short_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_unsigned_short_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_short_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_signed_short_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_int_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_unsigned_int_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_int_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_signed_int_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_unsigned_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_signed_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_long_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_unsigned_long_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_long_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_signed_long_long_judgement<Exp, Continuation>;

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_bool_dependent_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_bool_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char_dependent_judgement)			= typename snk_judgement_ss::identity::template
										  s_is_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_char_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_unsigned_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_char_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_signed_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_wchar_t_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_wchar_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char16_t_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_char16_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char32_t_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_char32_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_short_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_unsigned_short_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_short_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_signed_short_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_int_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_unsigned_int_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_int_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_signed_int_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_unsigned_long_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_dependent_judgement)		= typename snk_judgement_ss::identity::template
										  s_is_signed_long_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_long_dependent_judgement)	= typename snk_judgement_ss::identity::template
										  s_is_unsigned_long_long_dependent_judgement
											<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_long_dependent_judgement)	= typename snk_judgement_ss::identity::template
										  s_is_signed_long_long_dependent_judgement
											<Exp, Continuation>;

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_bool_judgement)		= snk_judgement_ss::identity::template
										  a_is_bool_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char_judgement)		= snk_judgement_ss::identity::template
										  a_is_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_char_judgement)	= snk_judgement_ss::identity::template
										  a_is_unsigned_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_char_judgement)	= snk_judgement_ss::identity::template
										  a_is_signed_char_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_wchar_t_judgement)		= snk_judgement_ss::identity::template
										  a_is_wchar_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char16_t_judgement)		= snk_judgement_ss::identity::template
										  a_is_char16_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char32_t_judgement)		= snk_judgement_ss::identity::template
										  a_is_char32_t_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_short_judgement)	= snk_judgement_ss::identity::template
										  a_is_unsigned_short_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_short_judgement)	= snk_judgement_ss::identity::template
										  a_is_signed_short_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_int_judgement)	= snk_judgement_ss::identity::template
										  a_is_unsigned_int_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_int_judgement)	= snk_judgement_ss::identity::template
										  a_is_signed_int_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_long_judgement)	= snk_judgement_ss::identity::template
										  a_is_unsigned_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_long_judgement)	= snk_judgement_ss::identity::template
										  a_is_signed_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_long_long_judgement)	= snk_judgement_ss::identity::template
										  a_is_unsigned_long_long_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_long_long_judgement)	= snk_judgement_ss::identity::template
										  a_is_signed_long_long_judgement<Exp, Continuation>;

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_bool_dependent_judgement)	= snk_judgement_ss::identity::template
										  a_is_bool_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char_dependent_judgement)	= snk_judgement_ss::identity::template
										  a_is_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_char_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_unsigned_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_char_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_signed_char_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_wchar_t_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_wchar_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char16_t_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_char16_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_char32_t_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_char32_t_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_short_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_unsigned_short_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_short_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_signed_short_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_int_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_unsigned_int_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_int_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_signed_int_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_long_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_unsigned_long_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_long_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_signed_long_dependent_judgement<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_unsigned_long_long_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_unsigned_long_long_dependent_judgement
											<Exp, Continuation>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_signed_long_long_dependent_judgement) = snk_judgement_ss::identity::template
										  a_is_signed_long_long_dependent_judgement
											<Exp, Continuation>;

//

#undef PREFIX

#undef snk_judgement_ss
#undef pnk_builtin_ss

#include"undef-size_type.h"

