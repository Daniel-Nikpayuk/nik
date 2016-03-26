/*************************************************************************************************************************
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
*************************************************************************************************************************/

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_OVERLOAD_RANDOM_ACCESS_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_OVERLOAD_RANDOM_ACCESS_H

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
	It is meant to be bootstrapped with a given macro interpretation.
*/

template<typename SizeType>
struct overload
{
	typedef SizeType size_type;

	template<size_type N, size_type M=0, size_type L=0>
	struct unroll
	{
	};

	template<size_type M, size_type L>
	struct unroll<0, M, L>
	{
	};
};

#endif
