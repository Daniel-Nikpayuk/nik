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

	#define PREFIX		pk_judgement_ss_

#else

	#define PREFIX

#endif

//

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Type, Type Value
							  >
	using nik_safe(PREFIX, judgement_make)		= typename nik_language(patronum, kernel, judgement, symbolic, semiotic)::
							  embedding::template judgement_make<Judgement, Type, Value>;

							  template
							  <
								typename Judgement,

								typename Continuation =
								typename nik_language(patronum, kernel, judgement, symbolic, semiotic)::
								inductor::ch_judgement_type
							  >
	using nik_safe(PREFIX, judgement_type)		= typename nik_language(patronum, kernel, judgement, symbolic, semiotic)::
							  embedding::template judgement_type<Judgement, Continuation>;

							  template
							  <
								typename Judgement,

								typename Continuation =
								typename nik_language(patronum, kernel, judgement, symbolic, semiotic)::
								inductor::ch_judgement_value
							  >
	static constexpr nik_safe(PREFIX, judgement_type)
	<Judgement> nik_safe(PREFIX, judgement_value)	= nik_language(patronum, kernel, judgement, symbolic, semiotic)::
							  embedding::template judgement_value<Judgement, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

