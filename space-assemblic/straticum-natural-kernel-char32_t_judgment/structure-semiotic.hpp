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

		template<typename Exp, typename Continuation = ch_symbolic_values>
		using s_char32_t_judgment_ = s_char32_t_judgment_<Exp, Continuation>;

		// assemblic:

		template<typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr void a_char32_t_judgment_ = a_char32_t_judgment_<Exp, Continuation>;

		// procedural:

		static constexpr void (*p_char32_t_judgment_)() = p_char32_t_judgment_<>;
};
