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
struct fast_order
{
	enum : size_type
	{
		value=gf_policy::media::template
		if_then_else
		<
			media::template band<secondary, (n>>1), n>::value,
			fast_order<primary+(n>>1), media::template band<secondary, (n>>1), n>::value, (n>>1)>,
			fast_order<primary, media::template band<secondary, 0, (n>>1)>::value, (n>>1)>
		>::return_type::value
	};
};

template<size_type primary, size_type secondary>
struct fast_order<primary, secondary, 0> { enum : size_type { value=primary }; };

