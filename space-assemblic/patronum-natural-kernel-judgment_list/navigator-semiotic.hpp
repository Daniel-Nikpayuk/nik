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

struct navigator
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, inductor)

	// car:

		// assemblic:

		template
		<
			typename Type, typename List,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_list_car = dependent_memoization<Type>::template
		pattern_match_values_list<List>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;

	// cdr:

		// symbolic:

		template<typename Continuation>
		struct cp_s_grow_cdr
		{
			template<typename Type, template<Type...> class ListType, typename Filler, Type Value, Type... Values>
			using result = typename Continuation::template result
			<
				Type, ListType, Filler, Values...
			>;
		};

		template<typename Type, typename List, typename Continuation = ch_s_grow_to_values>
		using s_judgment_list_cdr = typename dependent_memoization<Type>::template pattern_match_values_list<List>::template
		s_front_grow_induct
		<
			cp_s_grow_cdr<Continuation>, filler
		>;

	// catenate:

		// symbolic:

		template<typename Continuation>
		struct cp_s_grow_to_values_catenate
		{
			template<typename Type, template<Type...> class ListType, typename List2, Type... Values1>
			using result = typename dependent_memoization<Type>::template pattern_match_values_list<List2>::template
			s_front_grow_induct
			<
				Continuation, filler, Values1...
			>;
		};

		template<typename Type, typename List1, typename List2, typename Continuation = ch_s_grow_to_values>
		using s_judgment_list_catenate = typename dependent_memoization<Type>::template pattern_match_values_list<List1>::template
		s_front_grow_induct
		<
			cp_s_grow_to_values_catenate<Continuation>, List2
		>;

		// assemblic:

/*
	// :

		// symbolic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_grow_to_values
		>
		using s_judgment_list_ = typename pattern_match_judgment_list_<Type, Exp>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

		// assemblic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_list_ = pattern_match_judgment_list_<Type, Exp>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_list_(Type v) { return v; }
*/
};
