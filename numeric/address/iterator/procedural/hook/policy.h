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

#ifndef NIK_NUMERIC_ADDRESS_ITERATOR_PROCEDURAL_HOOK_POLICY_H
#define NIK_NUMERIC_ADDRESS_ITERATOR_PROCEDURAL_HOOK_POLICY_H

namespace nik		{
namespace numeric	{
namespace address	{
namespace iterator	{
namespace procedural	{
namespace hook		{

	template<typename SizeType> struct media;

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef hook::media<size_type> media;

		#include"zip/semiotic.cpp"

			template<size_type N, size_type M=0, size_type L=0>
			using zip_unroll=typename zip::template unroll<N, M, L>;

		#include"find/semiotic.cpp"

//		#include"identity/semiotic.cpp"

		#include"discrete/semiotic.cpp"

			template<size_type N, size_type M=0, size_type L=0>
			using discrete_unroll=typename discrete::template unroll<N, M, L>;

//		#include"arithmetic/semiotic.cpp"

/*
			using arit=arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using arit_unroll=typename arit::template unroll<N, M, L>;
*/
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef hook::semiotic<size_type> semiotic;

//		#include"zip/media.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using zip_unroll=zip::template unroll<N, M, L>;

//		#include"discrete/media.cpp"

/*
			using discrete=discrete<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using discrete_unroll=typename discrete::template unroll<N, M, L>;
*/

//		#include"arithmetic/media.cpp"

/*
			using arit=arithmetic<size_type>;

			template<size_type N, size_type M=0, size_type L=0>
			using arit_unroll=typename arit::template unroll<N, M, L>;
*/
	};

}}}}}}

#endif
