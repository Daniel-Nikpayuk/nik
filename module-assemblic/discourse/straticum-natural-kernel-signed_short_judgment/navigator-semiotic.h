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
#define snk_signed_short_judgment_as nik_module(straticum, natural, kernel, signed_short_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkssj_navigator_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_signed_short_judgment_add)			= typename snk_signed_short_judgment_as::navigator::template
										  s_signed_short_judgment_add<Value1, Value2, Continuation>;

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_signed_short_judgment_multiply)			= typename snk_signed_short_judgment_as::navigator::template
										  s_signed_short_judgment_multiply<Value1, Value2, Continuation>;

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_signed_short_judgment_subtract)			= typename snk_signed_short_judgment_as::navigator::template
										  s_signed_short_judgment_subtract<Value1, Value2, Continuation>;

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_signed_short_judgment_divide)			= typename snk_signed_short_judgment_as::navigator::template
										  s_signed_short_judgment_divide<Value1, Value2, Continuation>;

										  template
										  <
											signed short Value1,
											signed short Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_signed_short_judgment_modulo)			= typename snk_signed_short_judgment_as::navigator::template
										  s_signed_short_judgment_modulo<Value1, Value2, Continuation>;

//

	static constexpr signed short (*nik_safe(PREFIX, p_signed_short_judgment_add))(signed short, signed short) =
		snk_signed_short_judgment_as::navigator::p_signed_short_judgment_add;

	static constexpr signed short (*nik_safe(PREFIX, p_signed_short_judgment_multiply))(signed short, signed short) =
		snk_signed_short_judgment_as::navigator::p_signed_short_judgment_multiply;

	static constexpr signed short (*nik_safe(PREFIX, p_signed_short_judgment_subtract))(signed short, signed short) =
		snk_signed_short_judgment_as::navigator::p_signed_short_judgment_subtract;

	static constexpr signed short (*nik_safe(PREFIX, p_signed_short_judgment_divide))(signed short, signed short) =
		snk_signed_short_judgment_as::navigator::p_signed_short_judgment_divide;

	static constexpr signed short (*nik_safe(PREFIX, p_signed_short_judgment_modulo))(signed short, signed short) =
		snk_signed_short_judgment_as::navigator::p_signed_short_judgment_modulo;

//

#undef PREFIX

#undef snk_signed_short_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
