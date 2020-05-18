/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct embedding
{
	#include nik_assemblic_typedef(straticum, kernel, builtin, inductor)

	// builtin_types:

	template<typename Exp>
	static constexpr void builtin_display()			{ printf("%s", memoized_builtin<Exp>::induct()); }

	// void_ptr values:

	template<auto Value>
	static constexpr void void_ptr_display()		{ printf("%p", memoized_void_ptr<Value>::induct()); }
};

