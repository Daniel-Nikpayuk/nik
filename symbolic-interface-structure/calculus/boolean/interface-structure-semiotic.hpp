/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	Although this module fits the narrative design, I have chosen to only implement an optimized version
	of this concept entirely for performance reasons.
*/

struct structure
{
	using kind		= module;

	using rtn		= structure;

/*
	pattern_match_boolean:
*/

	template<bool True, typename Filler = void>
	struct pattern_match_boolean
	{
		using rtn = pattern_match_boolean;

		// conditional:

		template
		<
			typename Antecedent,
			typename Consequent

				//   signature: if_then_else.

		> using conditional = Antecedent;
	};

	template<typename Filler>
	struct pattern_match_boolean<false, Filler>
	{
		using rtn = pattern_match_boolean;

		// conditional:

		template
		<
			typename Antecedent,
			typename Consequent

				//   signature: if_then_else.

		> using conditional = Consequent;
	};
};

