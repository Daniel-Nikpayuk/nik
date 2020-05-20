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

struct inductor
{
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)

	// builtin types:

	template<typename Exp> using memoized_bool			= type_inductor<bool>::template memoized_type<Exp>;
	template<typename Exp> using memoized_char			= type_inductor<char>::template memoized_type<Exp>;
	template<typename Exp> using memoized_unsigned_char		= type_inductor<unsigned char>::template memoized_type<Exp>;
	template<typename Exp> using memoized_signed_char		= type_inductor<signed char>::template memoized_type<Exp>;
	template<typename Exp> using memoized_wchar_t			= type_inductor<wchar_t>::template memoized_type<Exp>;
	template<typename Exp> using memoized_char16_t			= type_inductor<char16_t>::template memoized_type<Exp>;
	template<typename Exp> using memoized_char32_t			= type_inductor<char32_t>::template memoized_type<Exp>;
	template<typename Exp> using memoized_unsigned_short		= type_inductor<unsigned short>::template memoized_type<Exp>;
	template<typename Exp> using memoized_signed_short		= type_inductor<signed short>::template memoized_type<Exp>;
	template<typename Exp> using memoized_unsigned_int		= type_inductor<unsigned int>::template memoized_type<Exp>;
	template<typename Exp> using memoized_signed_int		= type_inductor<signed int>::template memoized_type<Exp>;
	template<typename Exp> using memoized_unsigned_long		= type_inductor<unsigned long>::template memoized_type<Exp>;
	template<typename Exp> using memoized_signed_long		= type_inductor<signed long>::template memoized_type<Exp>;
	template<typename Exp> using memoized_unsigned_long_long	= type_inductor<unsigned long long>::template memoized_type<Exp>;
	template<typename Exp> using memoized_signed_long_long		= type_inductor<signed long long>::template memoized_type<Exp>;

	// void_ptr values:

/*
	void_ptr values aren't generally considered meaningful as template parameters,
	this inductor is only here to maintain the narrative design of this library.
*/

	template<auto Exp> using memoized_void_ptr			= value_inductor<void_ptr(0)>::template memoized_value<Exp>;
};

