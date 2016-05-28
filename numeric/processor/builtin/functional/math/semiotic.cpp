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

template<size_type primary, size_type secondary, size_type n>
struct fast_exp
{
	enum : size_type
	{
		value = gf_policy::cont::media::template
			if_then_else
			<
				(1 & n),
				fast_exp<primary*secondary, secondary, n-1>,
				fast_exp<primary, media::template square<secondary>::value, (n>>1)>
			>::return_type::value
	};
};

template<size_type primary, size_type secondary>
struct fast_exp<primary, secondary, 0> { enum : size_type { value=primary }; };

