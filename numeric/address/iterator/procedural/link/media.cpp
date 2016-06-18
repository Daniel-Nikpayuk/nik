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

struct link
{
	#include"zip/media.cpp"

//		forward:

		using fwd_zip=forward::zip;

		template<size_type N, size_type M=0, size_type L=0>
		using fwd_zip_unroll=typename fwd_zip::template unroll<N, M, L>;

//		backward:

		using bwd_zip=backward::zip;

		template<size_type N, size_type M=0, size_type L=0>
		using bwd_zip_unroll=typename bwd_zip::template unroll<N, M, L>;

//		bidirectional:

		using bid_zip=bidirectional::zip;

		template<size_type N, size_type M=0, size_type L=0>
		using bid_zip_unroll=typename bid_zip::template unroll<N, M, L>;

	#include"discrete/media.cpp"

//		forward:
/*
		using fwd_discrete=forward::discrete<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using fwd_discrete_unroll=typename fwd_discrete::template unroll<N, M, L>;
*/
//		backward:
/*
		using bwd_disc=backward::discrete<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using bwd_disc_unroll=typename bwd_disc::template unroll<N, M, L>;
*/
//		bidirectional:
/*
		using bid_disc=bidirectional::discrete<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using bid_disc_unroll=typename bid_disc::template unroll<N, M, L>;
*/

//	#include"arithmetic/media.cpp"

//		forward:
/*
		using fwd_arit=forward::arithmetic<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using fwd_arit_unroll=typename fwd_arit::template unroll<N, M, L>;
*/
//		backward:
/*
		using bwd_arit=backward::arithmetic<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using bwd_arit_unroll=typename bwd_arit::template unroll<N, M, L>;
*/
//		bidirectional:
/*
		using bid_arit=bidirectional::arithmetic<size_type>;

		template<size_type N, size_type M=0, size_type L=0>
		using bid_arit_unroll=typename bid_arit::template unroll<N, M, L>;
*/

};

