/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

template<size_type x>
struct abs
	{ enum : size_type { value=(x >= 0) ? x : -x }; };

template<size_type x>
struct square
	{ enum : size_type { value=x*x }; };

template<size_type base, size_type exponent>
struct exp
{
	static constexpr bool neg_and_odd=(!unit::media::is_unsigned && base < 0 && exponent%2);

	enum : size_type
	{
		value=
			exponent ?
			base ?
			(unit::media::is_unsigned || exponent > 0) ?
				(1-2*neg_and_odd)*semiotic::template
					fast_exp<1, abs<base>::value, abs<exponent>::value>::value
			: 0
			: 0
			: 1
	};
};

