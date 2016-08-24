/************************************************************************************************************************
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
************************************************************************************************************************/


template
<
	typename oAdjective,

	size_type oArityEnum = oAdjective::traits::arity_enum
>
struct declare_variables
{
	typename oAdjective::traits::pointer_type in;

	declare_variables(const oAdjective & object) : in(object.initial) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename oAdjective>
struct declare_variables<oAdjective, ModIterator::binary>
{
	typename oAdjective::traits::pointer_type fin;
	typename oAdjective::traits::pointer_type in;

	declare_variables(const oAdjective & object) : fin(object.first), in(object.initial) { }
};

