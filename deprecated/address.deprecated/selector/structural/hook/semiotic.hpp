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

#define POINTER_SIZE 2

template<typename T>
using hook_pointer = node_pointer<T, POINTER_SIZE>;

template<typename T>
using hook = node< hook_pointer<T> >;

template<typename T>
using const_hook_pointer = const_node_pointer<T, POINTER_SIZE>;

template<typename T>
using const_hook = node< const_hook_pointer<T> >;

#undef POINTER_SIZE

