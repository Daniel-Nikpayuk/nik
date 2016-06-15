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

#ifndef NIK_NUMERIC_PROCESSOR_BUILTIN_PROCEDURAL_SIFT_H
#define NIK_NUMERIC_PROCESSOR_BUILTIN_PROCEDURAL_SIFT_H

#include"../../../../../grammaric/functional/policy/policy.h"
#include"../../functional/policy/policy.h"

#include"../overload/overload.h"

/*
	As optimized (fast) types are intended to hold int types, it's more efficient to pass the given size_type instead of
	a const reference to one.

	Incrementing and decrementing pointers which should otherwise maintain a unit location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. As such, given some routines and subroutines are powerhouse workhorses
	relative to the whole library, it is worth implementing a few to be as processor and memory efficient as possible.

	Shifting functions are actually provided less for improved efficiency, but more for coercion and type deduction safety.
*/

namespace nik
{
 namespace numeric
 {
  namespace processor
  {
   namespace builtin
   {
    namespace procedural
    {
	template<typename SizeType>
	struct sift
	{
		typedef SizeType size_type;

		typedef grammaric::functional::policy<size_type> gf_policy;
		typedef functional::policy<size_type> f_policy;

		typedef procedural::overload<size_type> over;

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
