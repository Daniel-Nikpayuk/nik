/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_ITERATOR_H
#define CONTEXT_ITERATOR_H

namespace nik
{
	namespace context
	{
/*
			iterator:
				The minimal specification (axiomatic properties) of an iterator are:
				typedefs:
				constructors:
				accessors:

			For iterators in general, references are a derived type,
			but for compatibility with pointers no such derivation is assumed.
*/
		struct iterator
		{
/*
	==:
		Is generic in that the parameter iterator types need not match.
*/
			template<typename Iterator1, typename Iterator2>
			static bool equals(Iterator1 x, Iterator2 y) { return x == y; }
/*
	!=:
		Is generic in that the parameter iterator types need not match.
*/
			template<typename Iterator1, typename Iterator2>
			static bool not_equals(Iterator1 x, Iterator2 y) { return x != y; }
		};
	}
}

#endif
