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

template<typename Bit, typename Filler = void>
struct constant
{
	using type		= constant;
	using type_ref		= type&;
	using type_ptr		= type*;

	using bit_type		= Bit;
	using bit_type_ref	= bit_type&;
	using bit_type_ptr	= bit_type*;

	static constexpr bit_type f(typename bit_type::binary_type::f);
	static constexpr bit_type t(typename bit_type::binary_type::t);
};

