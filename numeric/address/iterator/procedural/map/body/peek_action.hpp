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


#define DEFAULT		LIST<directionEnum, intervalEnum, imageEnum, iteratorEnum>

#define SEGMENT		LIST<directionEnum, intervalEnum, imageEnum, Association::segment>


/***********************************************************************************************************************/


template
<
	typename pointer,

	size_type directionEnum,
	size_type intervalEnum,
	size_type imageEnum,
	size_type iteratorEnum,
	typename T
>
static bool peek_action(pointer in, pointer end, const ObjectAdjective<DEFAULT, T> & adj)
{
	return (+in != end);
}


/***********************************************************************************************************************/


template<typename pointer, size_type directionEnum, size_type intervalEnum, size_type imageEnum, typename T>
static bool peek_action(pointer in, pointer end, const ObjectAdjective<SEGMENT, T> & adj)
{
	return (in < end);
}


/***********************************************************************************************************************/


#undef DEFAULT

#undef SEGMENT

