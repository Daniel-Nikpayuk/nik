/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#include nik_size_type(define)

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define pnk_function_as nik_module(patronum, natural, kernel, function, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkf_embedding_as_

#else

	#define PREFIX

#endif

//

/*
										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_values
										  >
	using nik_safe(PREFIX, s_function_)					= typename pnk_function_as::embedding::template
										  s_function_<Type, Exp, Continuation>;
*/

//

/*
										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_a_grow_to_value,

											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_function_)		= pnk_function_as::embedding::template
										  a_function_<Type, Continuation, Image>;
*/

//

		template<typename Kind, typename Type>
		using zero_type = Kind (*)(Type);

		template<typename Kind, typename Type>
	static constexpr zero_type<Kind, Type> nik_safe(PREFIX, p_function_zero) =
		pnk_function_as::embedding::template p_function_zero<Kind, Type>;

		template<typename Kind, typename Type1, typename Type2>
		using binary_zero_type = Kind (*)(Type1, Type2);

		template<typename Kind, typename Type1, typename Type2>
	static constexpr binary_zero_type<Kind, Type1, Type2> nik_safe(PREFIX, p_function_binary_zero) =
		pnk_function_as::embedding::template p_function_binary_zero<Kind, Type1, Type2>;

//

#undef PREFIX

#undef pnk_function_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
