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

struct navigator
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, inductor)

	// add:

		// symbolic:

		template<typename Continuation>
		struct cp_s_judgment_catenate
		{
			template<typename Inductor, typename Type, Type Value>
			using result = typename Judgment2::template
			symbolic_prepend_induct
			<
				
			>;
		};

		template<typename Type, typename Judgment1, typename Judgment2, typename Continuation = ch_symbolic_values>
		using s_judgment_add = typename Judgment1::template
		symbolic_induct
		<
			dependent_memoization<Type>::template cp_s_values_list_catenate
			<
				cp_s_judgment_add<Continuation>
			>
		>;

		// assemblic:

		template<typename Type, typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr void a_judgment_ = pattern_match_judgment_<Type, Exp>::template
		assemblic_induct
		<
			Continuation
		>;
};
