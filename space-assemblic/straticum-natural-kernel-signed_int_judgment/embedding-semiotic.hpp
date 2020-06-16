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
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, embedding)

	// judgment value:

		// symbolic:

		template
		<
			signed int Value,
			typename Continuation = ch_s_values
		>
		using s_signed_int_judgment_value = sf_judgment_value
		<
			signed int, Value, Continuation
		>;

	// display:

		// procedural:

		static constexpr void p_signed_int_judgment_display(signed int v) { printf("%d", v); }
};
