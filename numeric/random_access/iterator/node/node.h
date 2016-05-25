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

#ifndef NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_NODE_H
#define NIK_NUMERIC_RANDOM_ACCESS_ITERATOR_NODE_H

#include<stddef.h>

/*
	Intuition:

	A standard pointer is a variable to an address. A node is a bundling of addresses, and a pointer
	to such a bundling is thus a variable to a bundling of addresses. So when you dereference for example,
	you don't dereference the bundling of addresses as an object, you deference the value. The plus (+)
	as well as minus (-) unary operators become ways to dereference the alternate addresses. The difference
	being that if you conceptualize this space memory addresses as an object, it means all the regular
	grammar and interpretations of C++ all of a sudden apply: If it's an object, then you should be able to
	dereference the pointer as an object as well as act on the object itself. You'd also then need to make
	the additional function call of dereferencing the value from the object. The idea of the pointer is to
	access the memory directly, with no inbetween object.

	This intuitive conceptualization is the guiding design for any additional future considerations.
	For example, one might wish to create specialized convenience constructors for a node, but from the above
	interpretation, a node is not an object, it is NOT meant to be perceived to have constructors, only allocators.

	-----------

	This class is meant to be as narratively similar as possible to the builtin array pointer.
	I have privileged this above all other considerations in the design. Let me reiterate:
	The design privileges effective grammar expressivity as similar as possible to the builtin array pointer.

	As this is an exceptionally low-level class upon which many other classes are meant to be built, it is safe
	to say it has not been thorough tested in production. As such, I cannot guarantee it has been as optimized
	as it can be (premature optimization is the root of all evil).

	It is intuitive that node_pointers should be able to convert to const_node_pointers, the design follows this intuition.

	In terms of dynamic binding, const_node_pointers can semantically be considered a node_pointer subclass,
	and is nearly implemented as such. As it stands, I have decided to prevent this use of polymorphism.
	This policy will hold unless I find sufficient reason to change it. Furthermore, in a previous iteration in which
	it was allowed, I have learned intermixing polymorphism and void* seems to cause general issues. Though I don't
	fully understand why, I resolved a bug by removing the virtual declarations of the (*) and (+) operator overloads.
	The bug arose when they combined (*+).

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.

	void* casting is subtle, as the same memory cast to two different types works, but referencing within such memory
	changes on the interpretation of the type of that memory.

	By defining the node before the node_pointer, we can call "new node" outside of the pointer's scope,
	the tradeoff is the extended namespace calling in order to do so (nik::context::context:: ...).
	One would need to typedef. I have included a typedef of the pointer within its node.
*/

namespace nik
{
 namespace numeric
 {
  namespace random_access
  {
   namespace iterator
   {
	template<typename SizeType>
	struct node
	{
		typedef SizeType size_type;

		struct semiotic
		{
			#include"semiotic.cpp"
		};

		// change the name of base?
		// instead incude hook and link here as the media versions of node.
	};
   }
  }
 }
}

#endif
