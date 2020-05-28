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

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define snk__ss nik_module(straticum, natural, kernel, , symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snk_inductor_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_value
										  >
	using nik_safe(PREFIX, s_)						= typename snk__ss::inductor::template
										  s_<Type, Continuation>;

								  template<auto Value>
	using nik_safe(PREFIX, bool_coinduct_value)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template bool_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, char_coinduct_value)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template char_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, unsigned_char_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template unsigned_char_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, signed_char_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template signed_char_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, wchar_t_coinduct_value)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template wchar_t_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, char16_t_coinduct_value)		= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template char16_t_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, char32_t_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template char32_t_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, unsigned_short_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template unsigned_short_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, signed_short_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template signed_short_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, unsigned_int_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template unsigned_int_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, signed_int_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template signed_int_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, unsigned_long_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template unsigned_long_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, signed_long_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template signed_long_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, unsigned_long_long_coinduct_value)= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
			 					  inductor::template unsigned_long_long_coinduct_value<Value>;

								  template<auto Value>
	using nik_safe(PREFIX, signed_long_long_coinduct_value)	= typename nik_language(straticum, kernel, builtin, symbolic, semiotic)::
								  inductor::template signed_long_long_coinduct_value<Value>;

//

										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr nik_safe(PREFIX, a_)					= snk__ss::inductor::template
										  a_<Type, Continuation>;

//

#undef PREFIX

#undef snk__ss
#undef pnk_builtin_ss

#include"undef-size_type.h"

