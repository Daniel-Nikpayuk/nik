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

/*
	As this code is intended to be a convenience function to begin with, the "Field" type is
	passed instead of the more specific "Relation" type which is simpler from the user's point of view.
*/

template<typename Field, typename Relation, Relation... params>
struct sortFill
{
	using in = typename parameter<Relation>::template list<params...>;

	using sorted = typename semiotic::template quickSort<in>::rtn;

	using rtn = typename semiotic::template fill<sorted, Field>::rtn;
};

