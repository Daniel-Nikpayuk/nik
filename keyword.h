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

#include<stdio.h>

namespace nik
{
	using global_size_type = size_t;

	constexpr void *null_ptr = 0; // use builtin "nullptr" instead!

	constexpr char endl='\n';

	//

	template<typename Type>
	struct dereference_type
		{ using rtn = Type; };

	template<typename Type>
	struct dereference_type<Type*>
		{ using rtn = Type; };

	//

/*
	Currently deprecrated, parts of this will likely be restored once Branch::grammaric is restored.

	struct undefined
	{
		using rtn = undefined;

		static void print() { builtin_printer::print("undefined"); }
	};

	template<typename> struct act { };
	template<typename> struct pass { };

	#define grammaric_import_act()										\
														\
		template<typename Exp>										\
		using act = nik::grammaric::act<Exp>;

	#define grammaric_import_pass()										\
														\
		template<typename Exp>										\
		using pass = nik::grammaric::pass<Exp>;
*/
}

