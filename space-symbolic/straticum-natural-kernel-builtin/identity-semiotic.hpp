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
	#include nik_symbolic_typedef(patronum, kernel, builtin, identity)

	// builtin types:

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_bool = is_type_equal<bool, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_char = is_type_equal<char, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_unsigned_char = is_type_equal<unsigned char, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_signed_char = is_type_equal<signed char, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_wchar_t = is_type_equal<wchar_t, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_char16_t = is_type_equal<char16_t, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_char32_t = is_type_equal<char32_t, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_unsigned_short = is_type_equal<unsigned short, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_signed_short = is_type_equal<signed short, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_unsigned_int = is_type_equal<unsigned int, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_signed_int = is_type_equal<signed int, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_unsigned_long = is_type_equal<unsigned long, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_signed_long = is_type_equal<signed long, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_unsigned_long_long = is_type_equal<unsigned long long, Exp, Continuation>;

	template<typename Exp, typename Continuation = ch_coinduct_value>
	using is_signed_long_long = is_type_equal<signed long long, Exp, Continuation>;
};

