/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	Assumes modifier:
*/

template<typename inBase1, typename inBase2>
struct covers;

template<Parameter... in1_params, Parameter in2_first, Parameter... in2_params>
struct covers<base<in1_params...>, base<in2_first, in2_params...>>
{
	static constexpr bool value = contains<base<in1_params...>, in2_first>::value &&
					covers<base<in1_params...>, base<in2_params...>>::value;
};

template<Parameter... in1_params>
struct covers<base<in1_params...>, null_base>
{
	static constexpr bool value = true;
};

