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

struct base;

template<typename T, unsigned char size>
struct size_assert
{
	static_assert(sizeof(T) == size, "uint size_assert mismatch!");

	typedef T return_type;
};

typedef typename size_assert<unsigned char	, 1>::return_type identity8; 
typedef typename size_assert<unsigned short	, 2>::return_type identity16;
typedef typename size_assert<unsigned int	, 4>::return_type identity32;
typedef typename size_assert<unsigned long	, 8>::return_type identity64;

