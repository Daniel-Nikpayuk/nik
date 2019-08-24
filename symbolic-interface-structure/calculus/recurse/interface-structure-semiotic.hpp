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
			template<typename> class Ante, typename Value,

			typename Conse

		> using transit_reflex_conditional = Ante<Value>;

		template
		<
			typename Ante,

			template<typename, typename...> class Conse, typename Value, typename... Values

		> using reflex_transit_conditional = Ante;

		template
		<
			template<typename> class Ante, typename Ante_Value,

			template<typename, typename...> class Conse, typename Value, typename... Values

		> using transit_transit_conditional = Ante<Ante_Value>;

		template
		<
			typename Type,

			typename Ante_Continuation, Type Value,

			typename Conse_Continuation, typename Cond, typename Op, size_type count,

			Type... Values

		> using builtin_break_fold_conditional = typename Ante_Continuation::template result<Type, Value>;

		template
		<
			typename Value,

			typename Conse_Continuation, template<typename> class Cond, template<typename, typename> class Op, size_type count,

			typename... Values

		> using typename_break_fold_conditional = Value;

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
			template<typename> class Ante, typename Value,

			typename Conse

		> using transit_reflex_conditional = Conse;

		template
		<
			typename Ante,

			template<typename, typename...> class Conse, typename Value, typename... Values

		> using reflex_transit_conditional = Conse<Value, Values...>;

		template
		<
			template<typename> class Ante, typename Ante_Value,

			template<typename, typename...> class Conse, typename Value, typename... Values

		> using transit_transit_conditional = Conse<Value, Values...>;

		template
		<
			typename Type,

			typename Ante_Continuation, Type Value,

			typename Conse_Continuation, typename Cond, typename Op, size_type count,

			Type... Values

		> using builtin_break_fold_conditional = typename Conse_Continuation::template
								result<Type, Cond, Op, count, Value, Values...>;

		template
		<
			typename Value,

			typename Conse_Continuation, template<typename> class Cond, template<typename, typename> class Op, size_type count,

			typename... Values

		> using typename_break_fold_conditional = typename Conse_Continuation::template result<Cond, Op, count, Value, Values...>;

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

