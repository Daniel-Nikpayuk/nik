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
#define snk_bool_judgment_as nik_module(straticum, natural, kernel, bool_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkbj_navigator_as_

#else

	#define PREFIX

#endif

//

									  template
									  <
										bool Value,

										typename Continuation =
										typename pnk_builtin_ss::inductor::
										ch_symbolic_values,

										template<typename> class Memoizer =
										pnk_builtin_ss::inductor::template
										dependent_memoization
									  >
	using nik_safe(PREFIX, sf_bool_judgment_not)			= typename snk_bool_judgment_as::navigator::template
									  sf_bool_judgment_not<Value, Continuation, Memoizer>;

									  template
									  <
										bool Value1,
										bool Value2,

										typename Continuation =
										typename pnk_builtin_ss::inductor::
										ch_symbolic_values,

										template<typename> class Memoizer =
										pnk_builtin_ss::inductor::template
										dependent_memoization
									  >
	using nik_safe(PREFIX, sf_bool_judgment_and)			= typename snk_bool_judgment_as::navigator::template
									  sf_bool_judgment_and<Value1, Value2, Continuation, Memoizer>;

									  template
									  <
										bool Value1,
										bool Value2,

										typename Continuation =
										typename pnk_builtin_ss::inductor::
										ch_symbolic_values,

										template<typename> class Memoizer =
										pnk_builtin_ss::inductor::template
										dependent_memoization
									  >
	using nik_safe(PREFIX, sf_bool_judgment_or)			= typename snk_bool_judgment_as::navigator::template
									  sf_bool_judgment_or<Value1, Value2, Continuation, Memoizer>;

									  template
									  <
										bool Value1,
										bool Value2,

										typename Continuation =
										typename pnk_builtin_ss::inductor::
										ch_symbolic_values,

										template<typename> class Memoizer =
										pnk_builtin_ss::inductor::template
										dependent_memoization
									  >
	using nik_safe(PREFIX, sf_bool_judgment_implies)		= typename snk_bool_judgment_as::navigator::template
									  sf_bool_judgment_implies<Value1, Value2, Continuation, Memoizer>;

									  template
									  <
										bool Value1,
										bool Value2,

										typename Continuation =
										typename pnk_builtin_ss::inductor::
										ch_symbolic_values,

										template<typename> class Memoizer =
										pnk_builtin_ss::inductor::template
										dependent_memoization
									  >
	using nik_safe(PREFIX, sf_bool_judgment_equivalent)		= typename snk_bool_judgment_as::navigator::template
									  sf_bool_judgment_equivalent<Value1, Value2, Continuation, Memoizer>;

//

	static constexpr bool (*nik_safe(PREFIX, p_bool_judgment_not))(bool)			= snk_bool_judgment_as::navigator::
												  p_bool_judgment_not;

	static constexpr bool (*nik_safe(PREFIX, p_bool_judgment_and))(bool, bool)		= snk_bool_judgment_as::navigator::
												  p_bool_judgment_and;

	static constexpr bool (*nik_safe(PREFIX, p_bool_judgment_or))(bool, bool)		= snk_bool_judgment_as::navigator::
												  p_bool_judgment_or;

	static constexpr bool (*nik_safe(PREFIX, p_bool_judgment_implies))(bool, bool)		= snk_bool_judgment_as::navigator::
												  p_bool_judgment_implies;

	static constexpr bool (*nik_safe(PREFIX, p_bool_judgment_equivalent))(bool, bool)	= snk_bool_judgment_as::navigator::
												  p_bool_judgment_equivalent;

//

#undef PREFIX

#undef snk_bool_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
