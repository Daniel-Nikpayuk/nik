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

namespace nik		{
namespace numeric	{
namespace address	{
namespace list		{
namespace procedural	{

	template<typename SizeType> struct media;

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef functional::media<size_type> media;

		#include"identity/semiotic.cpp"

		template<size_type N, size_type M=0, size_type L=0>
		using unroll=identity::template unroll<N, M, L>;

//		#include"arithmetic/semiotic.cpp"
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef functional::semiotic<size_type> semiotic;

		#include"identity/media.cpp"

		template<size_type N, size_type M=0, size_type L=0>
		using unroll=identity::template unroll<N, M, L>;

//		#include"arithmetic/media.cpp"
	};

}}}}}

