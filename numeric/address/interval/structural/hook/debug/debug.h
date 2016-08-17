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

#ifndef NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_STRUCTURAL_HOOK_DEBUG_H
#define NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_ITERATOR_EXTENSIONWISE_STRUCTURAL_HOOK_DEBUG_H

#include"../../../../../../../../debug.h"
#include"../hook.h"

/*
	Make sure to consider composition of grammar as part of testing.

	Think out a clearer testing policy so that you don't have to use such long namespace compositions.
*/

namespace nik
{
 namespace debug
 {
	struct hook
	{
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::extensionwise::structural::hook<int> hook_type;

		static void allocator()
		{
			delete new hook_type();
		}
	};

	struct hook_pointer
	{
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<int> hook;
		typedef typename hook::pointer pointer;
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<int const>::pointer const & pointer_const;

		static void dimension()
		{
			nik::display << "dimension: " << pointer::dimension << nik::endl;
		}

		static void constructors()
		{
				// two atomic constructors:
			pointer n0;
			pointer n1(0);
			pointer n2(new hook());

				// copy constructor assigned the atomic.
			pointer n3(n0);
			pointer n4(n1);
			pointer n5(n2);

				// copy constructor composed with the atomic.
			pointer n6(pointer());
			pointer n7(pointer(0));
			pointer n8(pointer(new hook()));
		}

		static void assignment_operator()
		{
				// two atomic copy initializations:
			pointer n0;
			pointer n1=0;
			pointer n2=new hook();

				// copy constructor assigned the atomic.
			pointer n3;
			pointer n4;
			pointer n5;

			n4=0;
			n5=new hook();

			n3=n0;
			n4=n1;
			n5=n2;

				// copy constructor composed with the atomic.
			n3=pointer();
			n4=pointer(0);
			n5=pointer(new hook());
		}

		static void type_conversion()
		{
			pointer n0;
			pointer n1=0;
			pointer n2=new hook();
			pointer n3=n2;

			pointer *n4=(pointer*) n0;
			pointer *n5=(pointer*) n1;
			pointer *n6=(pointer*) n2;
			pointer *n7=(pointer*) n3;

			pointer_const n8=(pointer_const) n0;
			pointer_const n9=(pointer_const) n1;
			pointer_const n10=(pointer_const) n2;
			pointer_const n11=(pointer_const) n3;

			nik::display << (bool) n0 << " (true)" << nik::endl; // true
			nik::display << (bool) n1 << " (false)" << nik::endl; // false
			nik::display << (bool) n2 << " (true)" << nik::endl; // true
			nik::display << (bool) n3 << " (true)" << nik::endl; // true
		}

		static void comparison()
		{
			pointer n0;
			pointer n1=0;
			pointer n2=new hook();
			pointer n3=n2;

			nik::display << "n0;" << nik::endl;
			nik::display << "n1=0;" << nik::endl;
			nik::display << "n2=new hook();" << nik::endl;
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
			pointer n0;
			pointer n1=0;
			pointer n2=new hook();
			pointer n3=n2;

//			delete n0; // expected to crash.
			delete n1;
			delete n2;
//			delete n3; // expected to crash.
		}

		static void dereference()
		{
			pointer n=new hook();
			*n=5;
			nik::display << *n << nik::endl;
		}

		struct container
		{
			int value;
		};

		static void point()
		{
			typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<container> c_hook;
			typedef typename c_hook::pointer c_pointer;
			c_pointer n=new c_hook();
			*n=container();
			n->value=5;
			nik::display << n->value << nik::endl;
		}

		static void peek()
		{
			pointer n=new hook();
			*n=5;
			+n=new hook();
			*+n=6;
			nik::display << *n << nik::endl;
			nik::display << *+n << nik::endl;
		}

		static void inc()
		{
			pointer n=new hook();
			*n=5;
			+n=new hook();
			*+n=6;
			+(+n)=new hook();
			*+(+n)=7;
			nik::display << *(n++) << nik::endl;
			nik::display << *n << nik::endl;
			++n;
			nik::display << *n << nik::endl;
		}

		static void leap()
		{
			pointer n=new hook();

			pointer m=n;
			for (int k=0; k < 10; ++k)
			{
				m=+m=new hook();
				*m=k;
			}

				// warns of ambiguity as implicit conversion allows for standard pointer arithmetic.
				// in practice should not be an issue. Given the ambiguous nature of numeric literals
				// in the first place, it is more consistent policy to define the (pointer*) conversion
				// as implicit (instead of explicit).

//			nik::display << *(n+10) << nik::endl;

			size_t i=10;
			nik::display << *(n+i) << nik::endl;
			nik::display << *(n+=10) << nik::endl;
		}
	};

	struct const_hook_pointer
	{
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<int> hook;
		typedef typename hook::pointer pointer;
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<int const>::pointer const & pointer_const;

		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::const_hook<int> const_hook;
		typedef typename const_hook::pointer const_pointer;
		typedef semiotic::numeric::random_access::iterator::extensionwise::structural::const_hook<int const>::pointer const & const_pointer_const;

		static void dimension()
		{
			nik::display << "dimension: " << const_pointer::dimension << nik::endl;
		}

		static void constructors()
		{
				// two atomic constructors:
			pointer n0;
			pointer n1(0);
			pointer n2(new hook());

				// copy constructor assigned the atomic.
			pointer n3(n0);
			pointer n4(n1);
			pointer n5(n2);

				// copy constructor composed with the atomic.
			pointer n6(pointer());
			pointer n7(pointer(0));
			pointer n8(pointer(new hook()));

				// two atomic constructors:
			const_pointer c0;
			const_pointer c1(0);
			const_pointer c2(new const_hook());

				// copy constructor assigned the atomic.
			const_pointer c3(c0);
			const_pointer c4(c1);
			const_pointer c5(c2);

				// copy constructor composed with the atomic.
			const_pointer c6(const_pointer());
			const_pointer c7(const_pointer(0));
			const_pointer c8(const_pointer(new const_hook()));

			// composition:

			const_pointer c9(n0);
			const_pointer c10(n1);
			const_pointer c11(n2);
			const_pointer c12(n3);
			const_pointer c13(n4);
			const_pointer c14(n5);
				// doesn't work, but would never be used in practice.
				// seems to assume it's passing a function type.
//			const_pointer c15(n6);
			const_pointer c16(n7);
			const_pointer c17(n8);
		}

		static void assignment_operator()
		{
				// two atomic copy initializations:
			const_pointer c0;
			const_pointer c1=0;
			const_pointer c2=new const_hook();

				// copy constructor assigned the atomic.
			const_pointer c3;
			const_pointer c4;
			const_pointer c5;

			c4=0;
			c5=new const_hook();

			c3=c0;
			c4=c1;
			c5=c2;

				// copy constructor composed with the atomic.
			c3=const_pointer();
			c4=const_pointer(0);
			c5=const_pointer(new const_hook());
		}

		static void type_conversion()
		{
			const_pointer c0;
			const_pointer c1=0;
			const_pointer c2=new const_hook();
			const_pointer c3=c2;

			const_pointer *c4=(const_pointer*) c0;
			const_pointer *c5=(const_pointer*) c1;
			const_pointer *c6=(const_pointer*) c2;
			const_pointer *c7=(const_pointer*) c3;

			const_pointer_const c8=(const_pointer_const) c0;
			const_pointer_const c9=(const_pointer_const) c1;
			const_pointer_const c10=(const_pointer_const) c2;
			const_pointer_const c11=(const_pointer_const) c3;

			nik::display << (bool) c0 << " (true)" << nik::endl; // true
			nik::display << (bool) c1 << " (false)" << nik::endl; // false
			nik::display << (bool) c2 << " (true)" << nik::endl; // true
			nik::display << (bool) c3 << " (true)" << nik::endl; // true
		}

		static void comparison()
		{
			const_pointer c0;
			const_pointer c1=0;
			const_pointer c2=new const_hook();
			const_pointer c3=c2;

			nik::display << "c0;" << nik::endl;
			nik::display << "c1=0;" << nik::endl;
			nik::display << "c2=new const_hook();" << nik::endl;
			nik::display << "c3=c2;" << nik::endl;

			nik::display << "c0 == c0: " << (c0 == c0) << ", c0 != c0: " << (c0 != c0) << nik::endl;
			nik::display << "c0 == c1: " << (c0 == c1) << ", c0 != c1: " << (c0 != c1) << nik::endl;
			nik::display << "c0 == c2: " << (c0 == c2) << ", c0 != c2: " << (c0 != c2) << nik::endl;
			nik::display << "c0 == c3: " << (c0 == c3) << ", c0 != c3: " << (c0 != c3) << nik::endl;

			nik::display << "c1 == c0: " << (c1 == c0) << ", c1 != c0: " << (c1 != c0) << nik::endl;
			nik::display << "c1 == c1: " << (c1 == c1) << ", c1 != c1: " << (c1 != c1) << nik::endl;
			nik::display << "c1 == c2: " << (c1 == c2) << ", c1 != c2: " << (c1 != c2) << nik::endl;
			nik::display << "c1 == c3: " << (c1 == c3) << ", c1 != c3: " << (c1 != c3) << nik::endl;

			nik::display << "c2 == c0: " << (c2 == c0) << ", c2 != c0: " << (c2 != c0) << nik::endl;
			nik::display << "c2 == c1: " << (c2 == c1) << ", c2 != c1: " << (c2 != c1) << nik::endl;
			nik::display << "c2 == c2: " << (c2 == c2) << ", c2 != c2: " << (c2 != c2) << nik::endl;
			nik::display << "c2 == c3: " << (c2 == c3) << ", c2 != c3: " << (c2 != c3) << nik::endl;

			nik::display << "c3 == c0: " << (c2 == c0) << ", c3 != c0: " << (c2 != c0) << nik::endl;
			nik::display << "c3 == c1: " << (c2 == c1) << ", c3 != c1: " << (c2 != c1) << nik::endl;
			nik::display << "c3 == c2: " << (c2 == c2) << ", c3 != c2: " << (c2 != c2) << nik::endl;
			nik::display << "c3 == c3: " << (c2 == c3) << ", c3 != c3: " << (c2 != c3) << nik::endl;
		}

		static void deallocate()
		{
			const_pointer c0;
			const_pointer c1=0;
			const_pointer c2=new const_hook();
			const_pointer c3=c2;

//			delete c0; // expected to crash.
			delete c1;
			delete c2;
//			delete c3; // expected to crash.
		}

		static void dereference()
		{
			const_pointer c=new const_hook();
//			*c=5; // expected to fail.
			nik::display << *c << nik::endl;
		}

		struct container
		{
			int value;
		};

		static void point()
		{
			typedef semiotic::numeric::random_access::iterator::extensionwise::structural::hook<container> c_hook;
			typedef typename c_hook::pointer c_pointer;

			typedef semiotic::numeric::random_access::iterator::extensionwise::structural::const_hook<container> c_const_hook;
			typedef typename c_const_hook::pointer c_const_pointer;

			c_pointer n=new c_hook();
			*n=container();
			n->value=5;
			nik::display << n->value << nik::endl;

			c_const_pointer c=n;
//			c->value=7; // expected to fail.
			nik::display << c->value << nik::endl;
		}

		static void peek()
		{
			pointer n=new hook();
			*n=5;
			+n=new hook();
			*+n=6;
			nik::display << *n << nik::endl;
			nik::display << *+n << nik::endl;

			const_pointer c=n;
			nik::display << *c << nik::endl;
			nik::display << *+c << nik::endl;
		}

		static void inc()
		{
			pointer n=new hook();
			const_pointer c=n;

			*n=5;
			+n=new hook();
			*+n=6;
			+(+n)=new hook();
			*+(+n)=7;
			nik::display << *(n++) << nik::endl;
			nik::display << *n << nik::endl;
			++n;
			nik::display << *n << nik::endl;

			nik::display << *(c++) << nik::endl;
			nik::display << *c << nik::endl;
			++c;
			nik::display << *c << nik::endl;
		}

		static void leap()
		{
			pointer n=new hook();
			const_pointer c=n;

			pointer m=n;
			for (int k=0; k < 10; ++k)
			{
				m=+m=new hook();
				*m=k;
			}

			size_t i=10;
			nik::display << *(n+i) << nik::endl;
			nik::display << *(n+=10) << nik::endl;

			nik::display << *(c+i) << nik::endl;
			nik::display << *(c+=10) << nik::endl;
		}
	};
 }
}

#endif
