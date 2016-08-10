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

#ifndef NIK_NUMERIC_ADDRESS_LIST_STRUCTURAL_TRAITS_H
#define NIK_NUMERIC_ADDRESS_LIST_STRUCTURAL_TRAITS_H

#include"../../../../grammaric/structural/traits.h"
#include"../../iterator/structural/traits.h"

#include"../../../word/uint/functional/policy.h"
#include"../../../word/sint/functional/policy.h"
#include"../../iterator/procedural/hook/policy.h"

namespace nik		{
namespace numeric	{
namespace address	{
namespace list		{
namespace structural	{

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef grammaric::structural::media<size_type> gsm_traits;
		typedef iterator::structural::semiotic<size_type> iss_traits;

		typedef word::uint::functional::semiotic<size_type> wufs_policy;
		typedef word::sint::functional::semiotic<size_type> wsfs_policy;

		typedef iterator::procedural::hook::semiotic<size_type> iphs_policy;

		#include"base/semiotic.cpp"
		#include"identity/semiotic.cpp"
		#include"uint/semiotic.cpp"
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef grammaric::structural::media<size_type> gsm_traits;

//		#include"base/media.cpp"
//		#include"identity/media.cpp"
	};

}}}}}

#endif
