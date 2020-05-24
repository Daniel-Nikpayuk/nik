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

							  template<bool Value>
	using nik_safe(PREFIX, make_bool_judgement)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_bool_judgement<Value>;

							  template<char Value>
	using nik_safe(PREFIX, make_char_judgement)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_char_judgement<Value>;

							  template<unsigned char Value>
	using nik_safe(PREFIX, make_unsigned_char_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_unsigned_char_judgement<Value>;

							  template<signed char Value>
	using nik_safe(PREFIX, make_signed_char_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_signed_char_judgement<Value>;

							  template<wchar_t Value>
	using nik_safe(PREFIX, make_wchar_t_judgement)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_wchar_t_judgement<Value>;

							  template<char16_t Value>
	using nik_safe(PREFIX, make_char16_t_judgement)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_char16_t_judgement<Value>;

							  template<char32_t Value>
	using nik_safe(PREFIX, make_char32_t_judgement)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_char32_t_judgement<Value>;

							  template<unsigned short Value>
	using nik_safe(PREFIX, make_unsigned_short_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_unsigned_short_judgement<Value>;

							  template<signed short Value>
	using nik_safe(PREFIX, make_signed_short_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_signed_short_judgement<Value>;

							  template<unsigned int Value>
	using nik_safe(PREFIX, make_unsigned_int_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_unsigned_int_judgement<Value>;

							  template<signed int Value>
	using nik_safe(PREFIX, make_signed_int_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_signed_int_judgement<Value>;

							  template<unsigned long Value>
	using nik_safe(PREFIX, make_unsigned_long_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_unsigned_long_judgement<Value>;

							  template<signed long Value>
	using nik_safe(PREFIX, make_signed_long_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_signed_long_judgement<Value>;

							  template<unsigned long long Value>
	using nik_safe(PREFIX, make_unsigned_long_long_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_unsigned_long_long_judgement<Value>;

							  template<signed long long Value>
	using nik_safe(PREFIX, make_signed_long_long_judgement)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_signed_long_long_judgement<Value>;

//

#undef PREFIX

#include"undef-size_type.h"

