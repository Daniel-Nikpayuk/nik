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

#ifndef NIK_NUMERIC_PROCESSOR_ITERATOR_STRUCTURAL_TRAITS_H
#define NIK_NUMERIC_PROCESSOR_ITERATOR_STRUCTURAL_TRAITS_H

#include"../identity/identity.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
  namespace numeric
  {
   namespace processor
   {
    namespace iterator
    {
     namespace structural
     {
/*
*/
	template<typename SizeType>
	struct traits
	{
		typedef SizeType size_type;
/*
	traits:
*/
		using identity=structural::identity<size_type>;
	};
    }
   }
  }
 }
}

#endif
