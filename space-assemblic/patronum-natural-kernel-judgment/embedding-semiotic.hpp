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

	// judgment:

		// symbolic:

		template
		<
			typename Type, Type Value,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_value = typename Continuation::template result
		<
			Kind, ListKind, Type, Value
		>;

	// constant zero:

		// assemblic:

		template<typename Type> static constexpr Type af_judgment_zero			= 0;
		template<typename Type> static constexpr Type additive_identity			= 0;
		template<typename Type> static constexpr Type af_judgment_filler		= 0;

	// constant one:

		// assemblic:

		template<typename Type> static constexpr Type af_judgment_one			= 1;
		template<typename Type> static constexpr Type multiplicative_identity		= 1;
};
