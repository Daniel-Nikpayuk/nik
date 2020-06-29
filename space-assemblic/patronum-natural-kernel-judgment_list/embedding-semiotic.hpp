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

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, navigator)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment_list, identity)

	// length:

		// symbolic:

		template<typename Continuation>
		struct cp_sf_grow_to_values_length
		{
			template<typename Type, template<Type...> class ListType, typename _Drop_, Type... Values>
			using result = typename Continuation::template result
			<
				Type, ListType, (Type) sizeof...(Values)
			>;
		};

		// assemblic:

		template<typename Continuation>
		using cp_af_grow_to_value_length = typename independent_memoization::template cp_af_grow_to_value_length<Continuation>;

	// zip:

		// symbolic:

		template<typename Continuation>
		using cp_sf_values_list_zip_induct = typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>;

		// assemblic:

		template<typename Continuation>
		using cp_af_values_list_zip_induct = typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>;

	// :

		// symbolic:

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_grow_to_values
		>
		using s_judgment_list_ = typename pattern_match_judgment_list_<Type, Exp>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;
*/

		// assemblic:

/*
		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_list_ = pattern_match_judgment_list_<Type, Exp>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;
*/

		// procedural:

		template<bool isEmpty, typename Type, void (*)(Type)>
		struct fast_display
		{
			template<typename List>
			static constexpr void result()
			{
				// do nothing.
			}
		};

		template<typename Type, void (*Display)(Type), typename List>
		static constexpr void p_judgment_list_display()
		{
			fast_display
			<
				a_is_judgment_list_empty<Type, List>,
				Type, Display

			>::template result<List>();
		}

		template<typename Type, void (*Display)(Type)>
		struct fast_display<false, Type, Display>
		{
			template<typename List>
			static constexpr void result()
			{
				using Rest = s_judgment_list_cdr<Type, List>;

				Display(a_judgment_list_car<Type, List>);
				if (!a_is_judgment_list_empty<Type, Rest>) printf("%s", ", ");

				p_judgment_list_display<Type, Display, Rest>();
			}
		};
};
