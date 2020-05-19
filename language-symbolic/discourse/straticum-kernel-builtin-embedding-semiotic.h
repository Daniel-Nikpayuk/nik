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

	#define PREFIX		sk_builtin_ss_

#else

	#define PREFIX

#endif

//

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, bool_literal)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template bool_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, char_literal)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template char_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, unsigned_char_literal)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template unsigned_char_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, signed_char_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template signed_char_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, wchar_t_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template wchar_t_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, char16_t_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template char16_t_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, char32_t_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template char32_t_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, unsigned_short_literal)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template unsigned_short_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, signed_short_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template signed_short_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, unsigned_int_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template unsigned_int_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, signed_int_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template signed_int_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, unsigned_long_literal)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template unsigned_long_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, signed_long_literal)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template signed_long_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, unsigned_long_long_literal)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template unsigned_long_long_literal<Judgement, Continuation>;

							  template
							  <
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, signed_long_long_literal)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  embedding::template signed_long_long_literal<Judgement, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

