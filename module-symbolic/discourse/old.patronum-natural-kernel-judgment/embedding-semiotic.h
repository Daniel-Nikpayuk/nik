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

	#define PREFIX		pnkj_embedding_ss_

#else

	#define PREFIX

#endif

//

/*
										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_judgment_type)				= typename pnk_judgment_ss::embedding::template
										  cp_s_judgment_type<Continuation>;

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_type
										  >
	using nik_safe(PREFIX, s_judgment_type)					= typename pnk_judgment_ss::embedding::template
										  s_judgment_type<Type, Judgment, Continuation>;
*/

//

/*
										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_judgment_value)				= typename pnk_judgment_ss::embedding::template
										  cp_s_judgment_value<Continuation>;

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_judgment_value)				= typename pnk_judgment_ss::embedding::template
										  s_judgment_value<Type, Judgment, Continuation>;
*/

//

/*
										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_curried_judgment_type)			= typename pnk_judgment_ss::embedding::template
										  cp_s_curried_judgment_type<Continuation>;

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_type
										  >
	using nik_safe(PREFIX, s_curried_judgment_type)				= typename pnk_judgment_ss::embedding::template
										  s_curried_judgment_type<Type, Judgment, Continuation>;
*/

//

/*
										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_curried_judgment_value)			= typename pnk_judgment_ss::embedding::template
										  s_curried_judgment_value<Type, Judgment, Continuation>;
*/

//

/*
										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_judgment_value)				= typename pnk_judgment_ss::embedding::template
										  cp_a_judgment_value<Continuation>;

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr Type nik_safe(PREFIX, a_judgment_value)		= pnk_judgment_ss::embedding::template
										  a_judgment_value<Type, Judgment, Continuation>;
*/

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_curried_judgment_value)			= typename pnk_judgment_ss::embedding::template
										  cp_a_curried_judgment_value<Continuation>;

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value,

											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_value)	= pnk_judgment_ss::embedding::template
										  a_curried_judgment_value
											<Type, Judgment, Continuation, Image>;

//

#undef PREFIX

#undef pnk_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)