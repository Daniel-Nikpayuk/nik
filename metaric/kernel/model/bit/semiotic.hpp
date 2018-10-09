/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct bit
{
	#include nik_unpack_typedef(module)
	#include nik_unpack_typedef(structure)
	#include nik_unpack_typedef(identity)
	#include nik_unpack_typedef(boolean)
	#include nik_unpack_typedef(conditional)

	#define EIGHT 8

	template<typename reg_type>
	struct length
	{
		static constexpr reg_type value		= reg_type(EIGHT) * sizeof(reg_type);
	};

	#undef EIGHT

	template<typename reg_type>
	struct sign
	{
		using is_signed = typename Or
		<
			is_equal<reg_type, signed char		>,
			is_equal<reg_type, signed short		>,
			is_equal<reg_type, signed int		>,
			is_equal<reg_type, signed long		>,
			is_equal<reg_type, signed long long	>

		>::rtn;

		static constexpr Sign value		= is_signed::value ? Sign::integer : Sign::natural;
	};

/***********************************************************************************************************************/

	template<size_type N, Sign = Sign::natural> struct register_type;

/*
	unsigned:
*/

	template<size_type N>
	struct register_type<N, Sign::natural>
	{
		using rtn = typename evaluate
		<
			if_then	 
			<
				boolean<N <= length<unsigned char>::value>,
				unsigned char

			>, else_then
			<
				boolean<N <= length<unsigned short>::value>,
				unsigned short

			>, else_then
			<
				boolean<N <= length<unsigned int>::value>,
				unsigned int

			>, else_then
			<
				boolean<N <= length<unsigned long>::value>,
				unsigned long

			>, else_then
			<
				boolean<N <= length<unsigned long long>::value>,
				unsigned long long

			>, then
			<
				unsigned long long
			>

		>::rtn;
	};

/*
	signed:
*/

	template<size_type N>
	struct register_type<N, Sign::integer>
	{
		using rtn = typename evaluate
		<
			if_then	 
			<
				boolean<N <= length<signed char>::value>,
				signed char

			>, else_then
			<
				boolean<N <= length<signed short>::value>,
				signed short

			>, else_then
			<
				boolean<N <= length<signed int>::value>,
				signed int

			>, else_then
			<
				boolean<N <= length<signed long>::value>,
				signed long

			>, else_then
			<
				boolean<N <= length<signed long long>::value>,
				signed long long

			>, then
			<
				signed long long
			>

		>::rtn;
	};
};

