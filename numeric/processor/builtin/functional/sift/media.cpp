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

/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.
*/
template<size_type t>
struct low_pass
	{ enum : size_type { value = over::media::template shift_up<1, t>::value - 1 }; };

template<size_type s>
struct high_pass
	{ enum : size_type { value = ~ low_pass<s>::value }; };

template<size_type s, size_type t>
struct band_pass
	{ enum : size_type { value = low_pass<t-s>::value << s }; };

template<size_type x, size_type t>
struct low
	{ enum : size_type { value = (x & low_pass<t>::value) }; };

template<size_type x, size_type s>
struct high
	{ enum : size_type { value = over::media::template shift_down<x, s>::value }; };

template<size_type x, size_type s, size_type t>
struct band
	{ enum : size_type { value = over::media::template shift_up<over::media::template shift_down<x, s>::value, t-s>::value }; };

template<size_type x>
struct lower_half
	{ enum : size_type { value = low<x, unit::half::length>::value }; };

template<size_type x>
struct upper_half
	{ enum : size_type { value = high<x, unit::half::length>::value }; };

template<size_type x>
struct order
{
	enum : size_type { value=semiotic::template fast_order<0, x, unit::length>::value };
};

