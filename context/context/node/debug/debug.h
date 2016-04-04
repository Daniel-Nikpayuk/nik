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

#ifndef NIK_CONTEXT_CONTEXT_NODE_DEBUG_H
#define NIK_CONTEXT_CONTEXT_NODE_DEBUG_H

#include"../node.h"
#include"../../display/display.h"

namespace nik
{
 namespace debug
 {
	struct node
	{
		typedef context::context::node<int, int, size_t, 2> node_type;

		static void allocator()
		{
			delete new node_type();
		}
	};

	struct node_pointer
	{
		typedef context::context::node<int, int, size_t, 2> node_type;
		typedef context::context::node_pointer<int, size_t, 2> node_pointer_type;
		typedef context::context::node_pointer<int const, size_t, 2> const & node_pointer_const_type;

		static void dimension()
		{
			nik::display << node_pointer_type::dimension << nik::endl;
		}

		static void constructors()
		{
			node_pointer_type n0;
			node_pointer_type n1(0);
			node_pointer_type n2(new node_type());
			node_pointer_type n3(n0);
			node_pointer_type n4(n1);
			node_pointer_type n5(n2);
		}

		static void copy_constructors()
		{
			node_pointer_type n0;
			n0=0;
			n0=new node_type();

			node_pointer_type n1=n0;
		}

		static void type_conversion()
		{
			node_pointer_type n0;
			node_pointer_type n1=0;
			node_pointer_type n2=new node_type();
			node_pointer_type n3=n2;

			(node_pointer_type*) n0;
			(node_pointer_type*) n1;
			(node_pointer_type*) n2;
			(node_pointer_type*) n3;

			(node_pointer_const_type) n0;
			(node_pointer_const_type) n1;
			(node_pointer_const_type) n2;
			(node_pointer_const_type) n3;

			nik::display << (bool) n0 << nik::endl; // true
			nik::display << (bool) n1 << nik::endl; // false
			nik::display << (bool) n2 << nik::endl; // true
			nik::display << (bool) n3 << nik::endl; // true
		}

		static void comparison()
		{
			node_pointer_type n0;
			node_pointer_type n1=0;
			node_pointer_type n2=new node_type();
			node_pointer_type n3=n2;

			nik::display << "n0;" << nik::endl;
			nik::display << "n1=0;" << nik::endl;
			nik::display << "n2=new node();" << nik::endl;
			nik::display << "n3=n2;" << nik::endl;

			nik::display << "n0 == n0: " << (n0 == n0) << ", n0 != n0: " << (n0 != n0) << nik::endl;
			nik::display << "n0 == n1: " << (n0 == n1) << ", n0 != n1: " << (n0 != n1) << nik::endl;
			nik::display << "n0 == n2: " << (n0 == n2) << ", n0 != n2: " << (n0 != n2) << nik::endl;
			nik::display << "n0 == n3: " << (n0 == n3) << ", n0 != n3: " << (n0 != n3) << nik::endl;

			nik::display << "n1 == n0: " << (n1 == n0) << ", n1 != n0: " << (n1 != n0) << nik::endl;
			nik::display << "n1 == n1: " << (n1 == n1) << ", n1 != n1: " << (n1 != n1) << nik::endl;
			nik::display << "n1 == n2: " << (n1 == n2) << ", n1 != n2: " << (n1 != n2) << nik::endl;
			nik::display << "n1 == n3: " << (n1 == n3) << ", n1 != n3: " << (n1 != n3) << nik::endl;

			nik::display << "n2 == n0: " << (n2 == n0) << ", n2 != n0: " << (n2 != n0) << nik::endl;
			nik::display << "n2 == n1: " << (n2 == n1) << ", n2 != n1: " << (n2 != n1) << nik::endl;
			nik::display << "n2 == n2: " << (n2 == n2) << ", n2 != n2: " << (n2 != n2) << nik::endl;
			nik::display << "n2 == n3: " << (n2 == n3) << ", n2 != n3: " << (n2 != n3) << nik::endl;

			nik::display << "n3 == n0: " << (n2 == n0) << ", n3 != n0: " << (n2 != n0) << nik::endl;
			nik::display << "n3 == n1: " << (n2 == n1) << ", n3 != n1: " << (n2 != n1) << nik::endl;
			nik::display << "n3 == n2: " << (n2 == n2) << ", n3 != n2: " << (n2 != n2) << nik::endl;
			nik::display << "n3 == n3: " << (n2 == n3) << ", n3 != n3: " << (n2 != n3) << nik::endl;
		}

		static void deallocate()
		{
			node_pointer_type n0;
			node_pointer_type n1=0;
			node_pointer_type n2=new node_type();
			node_pointer_type n3=n2;

//			delete n0;
			delete n1;
			delete n2;
//			delete n3;
		}
	};
 }
}

#endif
