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

struct proximity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// :

		// symbolic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_grow_to_values
		>
		using s_builtin_ = typename pattern_match_builtin_<Type, Exp>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

		// assemblic:

		template
		<
			typename Type, typename Exp1, typename Exp2,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_builtin_ = pattern_match_builtin_<Type, Exp1>::template
		a_vv_zip_v_mutate_induct
		<
			Continuation, Image, Type, Exp2, Op
		>;
};
