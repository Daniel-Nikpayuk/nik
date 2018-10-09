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

#ifdef name_safe

	#define BOOLEAN		struct_boolean

#else

	#define BOOLEAN		boolean

#endif

//

using Sign		= typename Kernel::Sign;

//

			  template<typename Exp>
using act		= typename Kernel::structure::template act<Exp>;

//

			  template<bool Value>
using BOOLEAN		= typename Kernel::structure::template boolean<Value>;

//

			  template<typename Pred, typename Exp>
using if_then		= typename Kernel::structure::template if_then<Pred, Exp>;

			  template<typename Pred, typename Exp>
using else_then		= typename Kernel::structure::template else_then<Pred, Exp>;

			  template<typename Exp>
using then		= typename Kernel::structure::template then<Exp>;

//

			  template<typename RegType>
using builtin		= typename Kernel::structure::template builtin<RegType>;

//

#undef BOOLEAN

