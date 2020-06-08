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

struct structure
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// :

		// symbolic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_judgment_ = typename pattern_match_judgment_<Type, Exp>::template
		s_induct
		<
			Continuation, Memoizer
		>;

		// assemblic:

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
};
