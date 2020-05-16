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

#include"define-size_type.h"

#ifdef safe_name

	#define PREFIX		nik_pi_m_

#else

	#define PREFIX

#endif

//

	using local_nik_pi_f_ch_bool			= typename nik_division(identity, perspective, nik, semiotic)::functor::
							  ch_bool;

//

							  template<typename Division, typename Continuation = local_nik_pi_f_ch_bool>
	using nik_safe(PREFIX, division_is_implemented)	= typename nik_division(identity, perspective, nik, semiotic)::model::template
							  division_is_implemented<Division, Continuation>;

							  template<typename Module, typename Continuation = local_nik_pi_f_ch_bool>
	using nik_safe(PREFIX, module_is_implemented)	= typename nik_division(identity, perspective, nik, semiotic)::model::template
							  module_is_implemented<Module, Continuation>;

//

							  template
							  <
								typename Kind1, typename Kind2,

								typename Continuation = local_nik_pi_f_ch_bool
							  >
	using nik_safe(PREFIX, equal)			= typename nik_division(identity, perspective, nik, semiotic)::model::template
							  equal<Kind1, Kind2, Continuation>;

							  template
							  <
								typename Kind1, typename Kind2,

								typename Continuation = local_nik_pi_f_ch_bool
							  >
	using nik_safe(PREFIX, not_equal)		= typename nik_division(identity, perspective, nik, semiotic)::model::template
							  not_equal<Kind1, Kind2, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

