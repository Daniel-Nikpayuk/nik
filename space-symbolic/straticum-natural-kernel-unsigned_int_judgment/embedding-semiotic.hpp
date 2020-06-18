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

struct embedding
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, embedding)

	// value:

		// symbolic:

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned int
		>
		static constexpr Image a_unsigned_int_judgment_value = a_judgment_value
		<
			unsigned int, Judgment, Continuation, Image
		>;

	// curried value:

		// symbolic:

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned int
		>
		static constexpr Image a_curried_unsigned_int_judgment_value = a_curried_judgment_value
		<
			unsigned int, Judgment, Continuation, Image
		>;
};
