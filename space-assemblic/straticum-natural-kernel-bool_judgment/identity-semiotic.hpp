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
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, navigator)

	// is equal:

		// symbolic:

		template
		<
			bool Value1, bool Value2,
			typename Continuation = ch_s_values
		>
		using s_bool_judgment_is_equal = sf_bool_judgment_equivalent<Value1, Value2, Continuation>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_bool_judgment_is_equal)(bool, bool) = p_bool_judgment_equivalent;
};
