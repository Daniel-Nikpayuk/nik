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

#ifndef NIK_NUMERIC_PROCESSOR_VECTOR_STRUCTURAL_IDENTITY_H
#define NIK_NUMERIC_PROCESSOR_VECTOR_STRUCTURAL_IDENTITY_H

#include"../../../iterator/structural/traits/traits.h"

namespace nik
{
 namespace numeric
 {
  namespace processor
  {
   namespace vector
   {
    namespace structural
    {
	template<typename SizeType>
	struct semiotic
	{
		typedef Sizetype size_type;

		typedef iterator::structural::traits<size_type> is_traits;

		include"semiotic.cpp"
	};

	template<typename SizeType>
	struct media
	{
		typedef Sizetype size_type;

		typedef iterator::structural::traits<size_type> is_traits;

		include"media.cpp"
	};
    }
   }
  }
 }
}

#endif
