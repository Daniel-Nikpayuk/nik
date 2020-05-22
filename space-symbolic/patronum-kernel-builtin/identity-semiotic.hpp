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

struct identity
{
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)

	template<typename Type1, typename Type2, typename Continuation = ch_value>
	using is_type_equal = typename dependent_memoization<Type1>::template memoized_type<Type2>::template match
	<
		Continuation
	>;

	// is_value_equal is not yet implemented.

/*
	template<typename Continuation>
	struct cp_binary
	{
		template<typename Memoized_Value, typename Type, Type Value>
		using result = typename Memoized_Value::template value_induct
		<
			Continuation, Inductor
		>;
	};
*/
};

