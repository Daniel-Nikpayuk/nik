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

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// is equal:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using sf_judgment_is_equal = typename Continuation::template result<Memoizer, bool, Value1 == Value2>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr bool p_judgment_is_equal(Type Value1, Type Value2) { return Value1 == Value2; }
};
