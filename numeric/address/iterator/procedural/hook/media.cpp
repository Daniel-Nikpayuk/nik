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

struct hook
{
	#include"zip/media.cpp"

		template<size_type N, size_type M=0, size_type L=0>
		using zip_unroll=zip::template unroll<N, M, L>;

//	#include"discrete/media.cpp"

/*
		using discrete=discrete<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using discrete_unroll=typename discrete::template unroll<N, M, L>;
*/

//	#include"arithmetic/media.cpp"

/*
		using arit=arithmetic<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using arit_unroll=typename arit::template unroll<N, M, L>;
*/

};

