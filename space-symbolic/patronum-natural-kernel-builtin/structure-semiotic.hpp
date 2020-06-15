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

	// to judgment:

		// symbolic:

		template
		<
			typename Type, Type Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_to_judgment = typename dependent_memoization<Type>::template pattern_match_values<Value>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

		// assemblic:

		template
		<
			typename Type, Type Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_to_judgment = dependent_memoization<Type>::template pattern_match_values<Value>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;
};
