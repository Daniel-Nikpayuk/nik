/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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


#define FULL		adj_list<ob_directionEnum, ob_intervalEnum, ob_imageEnum, ob_iteratorEnum>

#define SEGMENT		adj_list<ob_directionEnum, ob_intervalEnum, ob_imageEnum, Association::segment>


/***********************************************************************************************************************/


template
<
	typename ob_pointer,

	Association ob_directionEnum,
	Association ob_intervalEnum,
	Association ob_imageEnum,
	Association ob_iteratorEnum,
	typename T
>
static inline bool peek_action(ob_pointer in, ob_pointer end, const Adjective<FULL, T> & ob)
{
	return (+in != end);
}


/***********************************************************************************************************************/


template
<
	typename ob_pointer,

	Association ob_directionEnum,
	Association ob_intervalEnum,
	Association ob_imageEnum,
	typename T
>
static inline bool peek_action(ob_pointer in, ob_pointer end, const Adjective<SEGMENT, T> & ob)
{
	return (in < end);
}


/***********************************************************************************************************************/


#undef FULL

#undef SEGMENT


