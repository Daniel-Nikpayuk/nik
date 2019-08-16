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

struct structure
{
	using kind		= module;

	using rtn		= structure;

/*
	pattern_match_recurse:
*/

	template<bool True, typename Filler = void>
	struct pattern_match_recurse
	{
		using rtn = pattern_match_recurse;

		template
		<
			template<typename> class signature, typename Ante,

			typename Conse

		> using transit_reflex_conditional = signature<Ante>;

		template
		<
			typename Ante,

			template<typename> class signature, typename... Conses

		> using reflex_transit_conditional = Ante;
	};

	template<typename Filler>
	struct pattern_match_recurse<false, Filler>
	{
		using rtn = pattern_match_recurse;

		template
		<
			template<typename> class signature, typename Ante,

			typename Conse

		> using transit_reflex_conditional = Conse;

		template
		<
			typename Ante,

			template<typename> class signature, typename... Conses

		> using reflex_transit_conditional = signature<Conses...>;
	};
};

