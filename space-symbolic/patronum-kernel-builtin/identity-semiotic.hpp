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

	// type_is_equal exists in principle, but it can't actually be used without a memoized boolean judgment.

	template<typename Exp1, typename Exp2, template<typename Kind, Kind> class Judgement, typename Continuation>
	using type_is_equal = typename type_inductor<Exp1>::template memoized_type<Exp2>::template match
	<
		Continuation, Judgement
	>;

	// value_is_equal is intentionally not implemented, as it's better to use constexpr functions instead.
};

