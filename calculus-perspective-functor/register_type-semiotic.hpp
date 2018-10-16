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

template<bool, typename>	struct pair;
template<typename...>		struct first_true;

template<typename Value, typename... Pairs>
struct first_true<pair<false, Value>, Pairs...>
{
	using rtn = typename first_true<Pairs...>::rtn;
};

template<typename Value, typename... Pairs>
struct first_true<pair<true, Value>, Pairs...>
{
	using rtn = Value;
};

/***********************************************************************************************************************/

template<global_size_type N, Sign = Sign::natural> struct register_type;

/*
	unsigned:
*/

template<global_size_type N>
struct register_type<N, Sign::natural>
{
	using rtn = typename first_true
	<
		pair<(N <= length<unsigned char		>::value), unsigned char	>,
		pair<(N <= length<unsigned short	>::value), unsigned short	>,
		pair<(N <= length<unsigned int		>::value), unsigned int		>,
		pair<(N <= length<unsigned long		>::value), unsigned long	>,
		pair<(N <= length<unsigned long long	>::value), unsigned long long	>

	>::rtn;
};

/*
	signed:
*/

template<global_size_type N>
struct register_type<N, Sign::integer>
{
	using rtn = typename first_true
	<
		pair<(N <= length<signed char		>::value), signed char		>,
		pair<(N <= length<signed short		>::value), signed short		>,
		pair<(N <= length<signed int		>::value), signed int		>,
		pair<(N <= length<signed long		>::value), signed long		>,
		pair<(N <= length<signed long long	>::value), signed long long	>

	>::rtn;
};

