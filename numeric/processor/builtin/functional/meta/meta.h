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

#ifndef NIK_NUMERIC_PROCESSOR_BUILTIN_FUNCTIONAL_META_H
#define NIK_NUMERIC_PROCESSOR_BUILTIN_FUNCTIONAL_META_H

#include"../../../../../grammaric/functional/policy/policy.h"

namespace nik
{
 namespace numeric
 {
  namespace processor
  {
   namespace builtin
   {
    namespace functional
    {
	template<typename SizeType>
	struct meta
	{
		typedef SizeType size_type;

		typedef grammaric::functional::policy<size_type> gf_policy;

		struct semiotic
		{
			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};
    }
   }
  }
 }
}

#endif
