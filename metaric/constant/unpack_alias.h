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

			  template<bool Value>
using boolean		= constant<bool, (bool) Value>;

/*
	We include here a list of commonly used literal constants,
	parameterized for different register sizes:
*/

			  template<typename RegType>
using zero		= constant<RegType, (RegType) 0>;

			  template<typename RegType>
using one		= constant<RegType, (RegType) 1>;

			  template<typename RegType>
using two		= constant<RegType, (RegType) 2>;

			  template<typename RegType>
using three		= constant<RegType, (RegType) 3>;

//

			  template<typename RegType>
using nibble		= constant<RegType, (RegType) 4>;

			  template<typename RegType>
using byte		= constant<RegType, (RegType) 8>;

