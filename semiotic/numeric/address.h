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

//	Unpack dependencies: <pointer>

using Address		= nik::numeric<Module::address, Permission::semiotic, size_type>;

			  template<typename Type, Access access = Access::readwrite>
using coaddress		= typename Address::template coaddress<Type, access>;

			  template<typename WordType, size_type length>
using address		= typename Address::template address<WordType, length>;

