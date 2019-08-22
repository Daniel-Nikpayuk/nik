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

			template<typename...> class signature, typename... Conses

		> using reflex_transit_conditional = Ante;

		template
		<
			typename Type, template<Type...> class ListType,

			typename Ante_Continuation, Type Value,

			typename Conse_Continuation, typename Cond, size_type count,

			Type... Values

		> using builtin_find_conditional = typename Ante_Continuation::template result<Type, ListType, Value, Values...>;

		template
		<
			template<typename...> class ListType,

			typename Ante_Continuation, typename Value,

			typename Conse_Continuation, template<typename> class Cond, size_type count,

			typename... Values

		> using typename_find_conditional = typename Ante_Continuation::template result<ListType, Value, Values...>;
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

			template<typename...> class signature, typename... Conses

		> using reflex_transit_conditional = signature<Conses...>;

		template
		<
			typename Type, template<Type...> class ListType,

			typename Ante_Continuation, Type Value,

			typename Conse_Continuation, typename Cond, size_type count,

			Type... Values

		> using builtin_find_conditional = typename Conse_Continuation::template result<Type, ListType, Cond, count, Values...>;

		template
		<
			template<typename...> class ListType,

			typename Ante_Continuation, typename Value,

			typename Conse_Continuation, template<typename> class Cond, size_type count,

			typename... Values

		> using typename_find_conditional = typename Conse_Continuation::template result<ListType, Cond, count, Values...>;
	};
};

