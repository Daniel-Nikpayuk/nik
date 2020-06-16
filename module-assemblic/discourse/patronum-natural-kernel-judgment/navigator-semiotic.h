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
#define pnk_judgment_as nik_module(patronum, natural, kernel, judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkj_navigator_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type,
											Type Value1,
											Type Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, sf_judgment_add)					= typename pnk_judgment_as::navigator::template
										  sf_judgment_add<Type, Value1, Value2, Continuation>;

										  template
										  <
											typename Type,
											Type Value1,
											Type Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, sf_judgment_subtract)				= typename pnk_judgment_as::navigator::template
										  sf_judgment_subtract<Type, Value1, Value2, Continuation>;

										  template
										  <
											typename Type,
											Type Value1,
											Type Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, sf_judgment_multiply)				= typename pnk_judgment_as::navigator::template
										  sf_judgment_multiply<Type, Value1, Value2, Continuation>;

										  template
										  <
											typename Type,
											Type Value1,
											Type Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, sf_judgment_divide)				= typename pnk_judgment_as::navigator::template
										  sf_judgment_divide<Type, Value1, Value2, Continuation>;

										  template
										  <
											typename Type,
											Type Value1,
											Type Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, sf_judgment_modulo)				= typename pnk_judgment_as::navigator::template
										  sf_judgment_modulo<Type, Value1, Value2, Continuation>;

//

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_judgment_add))(Type, Type)			= pnk_judgment_as::navigator::
												  p_judgment_add;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_judgment_subtract))(Type, Type)		= pnk_judgment_as::navigator::
												  p_judgment_subtract;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_judgment_multiply))(Type, Type)		= pnk_judgment_as::navigator::
												  p_judgment_multiply;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_judgment_divide))(Type, Type)		= pnk_judgment_as::navigator::
												  p_judgment_divide;

												  template<typename Type>
	static constexpr Type (*nik_safe(PREFIX, p_judgment_modulo))(Type, Type)		= pnk_judgment_as::navigator::
												  p_judgment_modulo;

//

#undef PREFIX

#undef pnk_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
