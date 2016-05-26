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

#ifndef NIK_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_IDENTITY_H
#define NIK_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_IDENTITY_H

#include"../../../traits/traits.h"

#include"../../../iterator/componentwise/structural/traits/traits.h"
#include"../../../iterator/componentwise/functional/policy/policy.h"

#include"../../functional/policy/policy.h"

/*
	vector:
		The policy here has taken into consideration two alternate designs: Have an "end" iterator,
		or an array length allowing near random access to the end.

			An end iterator is less memory efficient not to mention the need to relink it, but is otherwise
			more compatible with iterators for subclassing---and thus more extensible.

			An array length signifier is more efficient but less extensible.

			The policy I have settled upon is to maintain an array length. Given the inherent nature of the builtin
			pointer, as specified by an initial location and memory length, it makes more sense to extend this
			natural design.

			The burden is on the api coder of the media space to ensure code user safeties at that level as well.
*/

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
   namespace vector
   {
    namespace structural
    {
	struct semiotic
	{
		include"semiotic.cpp"
	};

	include"media.cpp"
    }
   }
  }
 }
}

#endif
