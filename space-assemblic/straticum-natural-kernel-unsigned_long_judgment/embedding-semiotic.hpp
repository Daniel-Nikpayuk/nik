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

	// value:

		// symbolic:

		template
		<
			unsigned long Value,
			typename Continuation = ch_s_values
		>
		using s_unsigned_long_judgment_value = sf_judgment_value
		<
			unsigned long, Value, Continuation
		>;

	// display:

		// procedural:

		static constexpr void p_unsigned_long_judgment_display(unsigned long v) { printf("%lu", v); }
};
