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

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_bool)		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_bool<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_char)		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_char<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_unsigned_char)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_unsigned_char<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_signed_char)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_signed_char<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_wchar_t)		= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_wchar_t<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_char16_t)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_char16_t<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_char32_t)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_char32_t<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_unsigned_short)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_unsigned_short<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_signed_short)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_signed_short<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_unsigned_int)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_unsigned_int<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_signed_int)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_signed_int<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_unsigned_long)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_unsigned_long<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_signed_long)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_signed_long<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_unsigned_long_long)= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_unsigned_long_long<Continuation>;

									  template<typename Continuation>
	static constexpr auto nik_safe(PREFIX, literal_signed_long_long)= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template literal_signed_long_long<Continuation>;

//

									  template<auto Exp, typename Continuation>
	static constexpr auto nik_safe(PREFIX, display_void_ptr)	= nik_language(straticum, kernel, builtin, assemblic, semiotic)::
									  embedding::template display_void_ptr<Exp, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

