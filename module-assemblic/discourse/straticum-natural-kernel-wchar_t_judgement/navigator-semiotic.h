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
#define snk_wchar_t_judgement_as nik_module(straticum, natural, kernel, wchar_t_judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkw_navigator_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_wchar_t_add)				= typename snk_wchar_t_judgement_as::navigator::template
										  s_wchar_t_add<Value1, Value2, Continuation>;

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_wchar_t_multiply)				= typename snk_wchar_t_judgement_as::navigator::template
										  s_wchar_t_multiply<Value1, Value2, Continuation>;

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_wchar_t_subtract)				= typename snk_wchar_t_judgement_as::navigator::template
										  s_wchar_t_subtract<Value1, Value2, Continuation>;

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_wchar_t_divide)				= typename snk_wchar_t_judgement_as::navigator::template
										  s_wchar_t_divide<Value1, Value2, Continuation>;

										  template
										  <
											wchar_t Value1,
											wchar_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_wchar_t_modulo)				= typename snk_wchar_t_judgement_as::navigator::template
										  s_wchar_t_modulo<Value1, Value2, Continuation>;

//

										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr void nik_safe(PREFIX, a_wchar_t_judgement_)			= snk_wchar_t_judgement_as::navigator::template
										  a_wchar_t_judgement_<Type, Continuation>;

//

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_wchar_t_add))(Type, Type)		= snk_wchar_t_judgement_as::navigator::
												  p_wchar_t_judgement_add<TYPE>;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_wchar_t_multiply))(Type, Type)		= snk_wchar_t_judgement_as::navigator::
												  p_wchar_t_judgement_multiply<TYPE>;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_wchar_t_subtract))(Type, Type)		= snk_wchar_t_judgement_as::navigator::
												  p_wchar_t_judgement_subtract<TYPE>;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_wchar_t_divide))(Type, Type)		= snk_wchar_t_judgement_as::navigator::
												  p_wchar_t_judgement_divide<TYPE>;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_wchar_t_modulo))(Type, Type)		= snk_wchar_t_judgement_as::navigator::
												  p_wchar_t_judgement_modulo<TYPE>;

//

#undef PREFIX

#undef snk_wchar_t_judgement_as
#undef pnk_builtin_ss

#include"undef-size_type.h"
