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
#define pnk_judgment_ss nik_module(patronum, natural, kernel, judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkj_navigator_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,

											template<Type...> class ListType =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Type>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_judgment_add)					= typename pnk_judgment_ss::navigator::template
										  s_judgment_add
											<Type, Value1, Value2, Continuation, ListType>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, s_curried_judgment_add)				= typename pnk_judgment_ss::navigator::template
										  s_curried_judgment_add
											<Type, Value1, Value2, Continuation>;

//

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,

											template<Type...> class ListType =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Type>::template
											pattern_match_values,

											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_add)			= pnk_judgment_ss::navigator::template
										  a_judgment_add
											<Type, Value1, Value2, Continuation, ListType, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_add)		= pnk_judgment_ss::navigator::template
										  a_curried_judgment_add
											<Type, Value1, Value2, Continuation, Image>;

//

#undef PREFIX

#undef pnk_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
