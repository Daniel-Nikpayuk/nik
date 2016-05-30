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
	First ask what the idea version is. In this case it's:

		left_shift<right_shift<unit::media::max, unit::media::length-(t-s)>::value, s>::value

	Then ask what constraints of the new parameters are required to make this work. The reason we chose the
	full safe version is that it comes embedded with the necessary assumptions to begin with. In practice,
	if we had many layers in the efficiency stratification, we would peel one layer at a time and reduce
	until our additional assumptions were gone.
*/

template<size_type s, size_type t>
struct band_pass
{
	enum : size_type
	{
		value = left_shift<right_shift<unit::media::max, unit::media::length-(t-s)>::value, s>::value
	};
};

// restructure
template<size_type s, size_type t>
struct band_pass
{
	static constexpr size_type tmp0=right_shift<unit::media::max, unit::media::length-(t-s)>::value;

	enum : size_type
	{
		value = left_shift<tmp0, s>::value
	};
};

