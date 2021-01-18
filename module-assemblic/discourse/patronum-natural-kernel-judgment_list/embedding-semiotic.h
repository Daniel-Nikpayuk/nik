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
#define pnk_judgment_list_as nik_module(patronum, natural, kernel, judgment_list, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkjl_embedding_as_

#else

	#define PREFIX

#endif

//

/*
										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_values
										  >
	using nik_safe(PREFIX, s_judgment_list_)					= typename pnk_judgment_list_as::embedding::template
										  s_judgment_list_<Type, Exp, Continuation>;
*/

										  template
										  <
											typename Type, Type Instance,
											Type (*Monoid)(Type, Type),
											typename List,

											template<Type...> class ListType =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Type>::template
											pattern_match_values,

											typename Continuation = nik::ch_s_values
										  >
	using nik_safe(PREFIX, s_judgment_list_monoid_fold)			= typename pnk_judgment_list_as::embedding::template
										  s_judgment_list_monoid_fold
										<Type, Instance, Monoid, List, ListType, Continuation>;

//

										  template
										  <
											typename Type, typename Kind,
											typename Moment, Kind Instance,
											template<Type> class Map,
											template<Kind, typename> class Combine,
											typename List,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											typename Continuation = nik::ch_a_to_value,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_list_v_map_t_combine_v) = pnk_judgment_list_as::embedding::template
										  a_judgment_list_v_map_t_combine_v
								<Type, Kind, Moment, Instance, Map, Combine, ListKind, Continuation, Image>;

//

		template
		<
		      typename Type, void (*Map)(Type), typename List,

		      typename Continuation// = nik::ch_a_to_value,
		>
	static constexpr void (*nik_safe(PREFIX, af_judgment_list_v_map_void_combine_void))() =
		pnk_judgment_list_as::embedding::template af_judgment_list_v_map_void_combine_void<Type, Map, Continuation>;

		template
		<
			typename Type,
			void (*Display)(Type),
			typename List,
			typename Continuation =
			typename pnk_builtin_ss::inductor::
			ch_p_v_map_void_mutate_to_void
		>
	static constexpr void (*nik_safe(PREFIX, p_judgment_list_display))() =
		pnk_judgment_list_as::embedding::template p_judgment_list_display<Type, Display, List, Continuation>;

		template
		<
			typename Type, typename List
		>
	static constexpr void (*nik_safe(PREFIX, af_judgment_list_display))() =
		pnk_judgment_list_as::embedding::template af_judgment_list_display<Type, List>;

/*
	static constexpr void (*nik_safe(PREFIX, p_judgment_list_))() =
		pnk_judgment_list_as::embedding::p_judgment_list_;
*/

//

#undef PREFIX

#undef pnk_judgment_list_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
