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

template<typename inBase1, typename inBase2, typename outBase = typename inBase1::null>
struct subtract;

template
<
	Parameter in1_first,
	Parameter... in1_params,

	Parameter... in2_params,

	Parameter... out_params
>
struct subtract<base<in1_first, in1_params...>, base<in2_params...>, base<out_params...>>
{
	using type = typename if_then_else
	<
		contains<base<in2_params...>, in1_first>::value,

		subtract<base<in1_params...>, base<in2_params...>, base<out_params...>>,

		subtract<base<in1_params...>, base<in2_params...>, base<out_params..., in1_first>>

	>::type::type;
};

template<Parameter... in2_params, Parameter... out_params>
struct subtract<null_base, base<in2_params...>, base<out_params...>>
{
	using type = base<out_params...>;
};

