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
	#define safe_name

		#include nik_symbolic_typedef(patronum, kernel, builtin, identity)
		#include nik_symbolic_typedef(patronum, kernel, judgment, inductor)
		#include nik_symbolic_typedef(patronum, kernel, judgment, identity)

	#undef safe_name

	#include nik_symbolic_typedef(straticum, kernel, judgment, inductor)

	template<typename Exp, typename Continuation = pk_judgment_ss_ch_judgment>
	using is_judgment = pk_judgment_ss_is_judgment
	<
		Exp, judgment, Continuation
	>;

	//

	template<typename Exp1, typename Exp2, typename Continuation = pk_judgment_ss_ch_judgment>
	using is_equal = pk_builtin_ss_is_equal
	<
		Exp1, Exp2, judgment, Continuation
	>;
};

