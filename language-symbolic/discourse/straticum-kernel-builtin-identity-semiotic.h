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
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_bool)			= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_bool<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_char)			= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_char<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_unsigned_char)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_unsigned_char<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_signed_char)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_signed_char<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_wchar_t)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_wchar_t<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_char16_t)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_char16_t<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_char32_t)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_char32_t<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_unsigned_short)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_unsigned_short<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_signed_short)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_signed_short<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_unsigned_int)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_unsigned_int<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_signed_int)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_signed_int<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_unsigned_long)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_unsigned_long<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_signed_long)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_signed_long<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_unsigned_long_long)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_unsigned_long_long<Exp, Judgement, Continuation>;

							  template
							  <
								typename Exp,
								template<typename Kind, Kind> class Judgement,
								typename Continuation
							  >
	using nik_safe(PREFIX, is_signed_long_long)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  identity::template is_signed_long_long<Exp, Judgement, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

