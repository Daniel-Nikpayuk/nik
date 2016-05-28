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

#define HOOK_SIZE 2

template<typename T>
using base=
	typename i_traits::node::semiotic::template base<
		typename i_traits::node::semiotic::template base_pointer<T, HOOK_SIZE>
	>;

template<typename T>
using const_base=
	typename i_traits::node::semiotic::template base<
		typename i_traits::node::semiotic::template const_base_pointer<T, HOOK_SIZE>
	>;

#undef HOOK_SIZE

