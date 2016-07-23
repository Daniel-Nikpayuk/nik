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

#include"../../../../../grammaric/variadic/structural/traits.h"
#include"../../../../../grammaric/variadic/functional/policy.h"

#include"../../../../word/uint/functional/policy.h"

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

		typedef grammaric::variadic::structural::semiotic<size_type> gvss_traits;

		typedef grammaric::variadic::functional::semiotic<size_type> gvfs_policy;
		typedef grammaric::variadic::functional::media<size_type> gvfm_policy;

		typedef word::uint::functional::semiotic<size_type> wufs_policy;

		typedef hook::media<size_type> media;

		#include"map/preprocessed.cpp"
//		#include"map/semiotic.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using map_unroll=typename map::template unroll<N, M, L>;

//		#include"search/semiotic.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using search_unroll=typename search::template unroll<N, M, L>;

//		#include"identity/semiotic.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using identity_unroll=typename identity::template unroll<N, M, L>;

//		#include"arithmetic/semiotic.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using arithmetic_unroll=typename arithmetic::template unroll<N, M, L>;
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef hook::semiotic<size_type> semiotic;

//		#include"map/media.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using map_unroll=map::template unroll<N, M, L>;

//		#include"search/media.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using search_unroll=typename search::template unroll<N, M, L>;

//		#include"identity/media.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using identity_unroll=typename identity::template unroll<N, M, L>;

//		#include"arithmetic/media.cpp"

//			template<size_type N, size_type M=0, size_type L=0>
//			using arithmetic_unroll=typename arithmetic::template unroll<N, M, L>;
	};

}}}}}}

#endif
