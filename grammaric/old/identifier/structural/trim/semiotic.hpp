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

// default to returning the original type if it is already "trimmed".

template<typename T>
struct trim
{
	using constant = T;

	using reference = T;
	using const_reference = T;

	using pointer = T;
	using const_pointer = T;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/

template<typename T>
struct trim<T const>
{
	using constant = T;
};

/***********************************************************************************************************************/

template<typename T>
struct trim<T&>
{
	using reference = T;
};

template<typename T>
struct trim<T const &>
{
	using const_reference = T;
};

/***********************************************************************************************************************/

template<typename T>
struct trim<T*>
{
	using pointer = T;
};

template<typename T>
struct trim<T const *>
{
	using const_pointer = T;
};

