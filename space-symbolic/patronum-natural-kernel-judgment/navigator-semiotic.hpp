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

struct navigator
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

#define safe_name

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, navigator)

#undef safe_name

	// curried op:

		// symbolic:

		template<typename Continuation>
		struct cp_s_judgment_monoid
		{
			template
			<
				template<typename> class Memoizer, typename Kind,

				typename Type, Kind (*Op)(Type, Type), typename Value2, Type Value1
			>
			using result = typename Value2::template
			sf_zip_induct
			<
				Continuation, Memoizer, Kind, Op, Value1
			>;
		};

		template
		<
			typename Type, Type (*Op)(Type, Type),
			typename Value1, typename Value2,

			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_curried_judgment_monoid = typename Value1::template
		s_zip_mutate_induct
		<
			cp_s_judgment_monoid<Continuation>, Memoizer, Type, Op, Value2
		>;

		// assemblic:

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_assemblic_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_ = pattern_match_judgment_<Type, Exp>::template
		a_induct
		<
			Continuation, Image
		>;
*/

	// curried add:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_curried_judgment_add = s_curried_judgment_monoid
		<
			Type, pnkj_navigator_as_p_judgment_add<Type>, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

};
