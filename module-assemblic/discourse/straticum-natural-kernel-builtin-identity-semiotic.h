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

	#define PREFIX		sk_builtin_as_

#else

	#define PREFIX

#endif

//

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_bool))()		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_bool<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_char))()		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_char<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_unsigned_char))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_unsigned_char<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_signed_char))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_signed_char<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_wchar_t))()		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_wchar_t<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_char16_t))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_char16_t<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_char32_t))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_char32_t<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_unsigned_short))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_unsigned_short<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_signed_short))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_signed_short<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_unsigned_int))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_unsigned_int<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_signed_int))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_signed_int<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_unsigned_long))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_unsigned_long<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_signed_long))()	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_signed_long<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_unsigned_long_long))()= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_unsigned_long_long<Exp, Continuation>;

									  template<typename Exp, typename Continuation>
	static constexpr bool (*nik_safe(PREFIX, is_signed_long_long))()= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  identity::template is_signed_long_long<Exp, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

