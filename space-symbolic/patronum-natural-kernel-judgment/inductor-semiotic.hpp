/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#define NIK_ONE 1

struct inductor
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

			template
			<
				typename Type, typename List,
				typename Continuation = ch_a_value,
				typename Image = size_type
			>
			static constexpr Image af_values_list_length = dependent_memoization<Type>::template
			pattern_match_values_list<List>::template
			a_front_grow_induct
			<
				typename independent_memoization::template cp_af_grow_to_value_length<Continuation>,
				Image, filler
			>;

		// The general nik algorithmic paradigm is ignored here as it is intended for the nik narrative design.
		// Notably, the issue here is we have implemented judgments as specialized lists in order to privilege
		// meta C++ minimal memoization best practices, but we otherwise don't yet have the necessary boolean
		// operators.

	template<typename Type, typename Exp>
	using pattern_match_judgment = if_then_else
	<
		dependent_memoization<Type>::template pattern_match_values_list<Exp>::template af_match_induct<ch_a_value, bool>	&&
		af_values_list_length<Type, Exp> == NIK_ONE										,

		typename dependent_memoization<Type>::template pattern_match_values_list<Exp>						,
		typename dependent_memoization<Type>::template pattern_match_values_list<filler>
													// assumes filler is
													// not a values list.
	>;

	template<typename Type, typename Exp>
	using pattern_match_curried_judgment = if_then_else
	<
		dependent_memoization<Type>::template pattern_match_values_list<Exp>::template af_match_induct<ch_a_value, bool>	&&
		af_values_list_length<Type, Exp> == NIK_ONE										&&
		independent_memoization::template pattern_match_s_front_grow_induct<Exp>::template af_match_induct<ch_a_value, bool>	,

		typename dependent_memoization<Type>::template pattern_match_values_list<Exp>						,
		typename dependent_memoization<Type>::template pattern_match_values_list<filler>
													// assumes filler is
													// not a values list.
	>;
};

#undef NIK_ONE
