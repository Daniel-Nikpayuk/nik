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

using Conditional	= nik::metaric<Module::conditional, Permission::semiotic, size_type>;

//

			  template<typename P, typename E>
using if_then		= typename Conditional::template if_then<P, E>;

			  template<typename P, typename E>
using else_then		= typename Conditional::template else_then<P, E>;

			  template<typename E>
using then		= typename Conditional::template then<E>;

//

			  template<typename P, typename E1, typename E2>
using conditional	= typename Conditional::template conditional<P, E1, E2>;

			  template<typename... params>
using block		= typename Conditional::template block<params...>;

