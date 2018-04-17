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

template<typename Base, typename...modifiers>
struct dispatch;

template<Parameter... mask_params, typename modifier, typename...modifiers>
struct dispatch<base<mask_params...>, modifier, modifiers...>
{
	using type = typename block
	<
		if_then
		<
			covers<base<mask_params...>, typename modifier::type>,
			modifier

		>, then
		<
			dispatch<base<mask_params...>, modifiers...>
		>

	>::type;
};

template<Parameter... mask_params, typename modifier>
struct dispatch<base<mask_params...>, modifier>
{
	using type = typename modifier::type;
};

