/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

using Power		= nik::grammaric<Module::power, Permission::semiotic, size_type>;

//

using Interval		= typename Power::Interval;

using Direction		= typename Power::Direction;

			  template<Interval interval, Direction direction>
using object		= typename Power::template object<interval, direction>;

//

			  template<typename Type, Access access = Access::readwrite>
using copower		= typename Power::template copower<Type, access>;

			  template<typename Type, size_type length>
using power		= typename Power::template power<Type, length>;

