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

#ifndef NIK_CONTEXT_CONTEXT_NODE_H
#define NIK_CONTEXT_CONTEXT_NODE_H

#include<stddef.h>

/*
	This class is meant to be as narratively similar as possible to the builtin array node_pointer.

	It is intuitive that node_pointers should be able to convert to const_node_pointers, the design follows this intuition.

	In terms of dynamic binding, const_node_pointers can semantically be considered a node_pointer subclass,
	and is nearly implemented as such. As it stands, I have decided to prevent this use of polymorphism,
	and have implemented this code in such a way that the compiler will allow no such direct conversion.
	Otherwise, I have defined hook as well as chain pointers as semantically related allowing polymorphism
	through their common base class node_pointer.

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.

	void node_pointer casting is subtle, as the same memory cast to two different types works, but referencing within such memory
	changes on the interpretation of the type of that memory.

	By defining the node before the node_pointer, we can call "new node()" outside of the pointer's scope,
	the tradeoff is the extended namespace calling in order to do so (nik::context::context:: ...).
	One would need to typedef both the node_pointer as well as the node. The complication here is in needing to specify
	the same template parameters for both.

	Some coders may wish to still do this, and so it is policy to leave the definition of node outside the node_pointer
	scope, but for those coders looking to refactor specifying the template parameters, I have included a typedef of
	the node_pointer within its respective specialized node.

	Intermixing polymorphism and void* seems to cause issues. Though I don't fully understand why, I resolved a bug by
	removing the virtual declarations of the (*) and (+) operator overloads. The bug arose when they combined (*+).
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
	template<typename T, typename Pointer, typename SizeType, SizeType N>
	class node
	{
		protected:
			typedef void* void_ptr;
		public:
			typedef T value_type;
			typedef Pointer pointer;
		public:
			static void_ptr operator new (size_t n)
				{ return new void_ptr[N]; }
	};

	template<typename T, typename SizeType, SizeType N>
	class node_pointer
	{
		protected:
			typedef node_pointer* node_pointer_ptr;
			typedef node_pointer& node_pointer_ref;
			typedef node_pointer<T const, SizeType, N> const_node_pointer;
			typedef node<T, node_pointer, SizeType, N>* node_ptr;

			typedef T* value_type_ptr;
			typedef T& value_type_ref;

			typedef SizeType size_type;
			enum : size_type { value=0, next=1, previous=2 };

			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;
			typedef void_ptr const* void_ptr_const_ptr;

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			enum : size_type { dimension=N };
		public:
			node_pointer() { }
			node_pointer(void_ptr p) { current=(void_ptr_ptr) p; }
			node_pointer(const node_pointer & p) { current=p.current; }
			~node_pointer() { }
/*
	This version is needed for compatibility with the existing constructors, to accept "=new node()" code.
	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const node_pointer & operator = (node_ptr p)
			{
				current=(void_ptr_ptr) p;
				return *this;
			}
/*
	In the case &p == this, nothing is changed.
	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const node_pointer & operator = (const node_pointer & p)
			{
				current=p.current;
				return *this;
			}
/*
	Needed for delete conversion.
*/
			operator node_pointer_ptr () const
				{ return (node_pointer_ptr) this; }
/*
	Needed for implicit const conversions.
*/
			operator const const_node_pointer & () const
				{ return *((const_node_pointer*) this); }
/*
	Needed for loop condition testing "while (node_pointer)".
*/
			operator bool () const
				{ return current; }

			bool operator == (const node_pointer & p) const
				{ return (current == p.current); }

			bool operator != (const node_pointer & p) const
				{ return (current != p.current); }

			static void operator delete (void_ptr p)
				{ delete ((node_pointer_ptr) p)->current; }

			value_type_ref operator * () const
				{ return (value_type_ref) current[value]; }

			value_type_ptr operator -> () const
				{ return (value_type_ptr) current[value]; }

			node_pointer_ref operator + () const
				{ return (node_pointer_ref) current[next]; }

			node_pointer_ref operator ++ ()
			{
				current=((node_pointer_ref) current[next]).current;
				return *this;
			}

			node_pointer operator ++ (int)
			{
				node_pointer out(*this);
				current=((node_pointer_ref) current[next]).current;
				return out;
			}

			node_pointer_ref operator += (size_type n)
			{
				while (n)
				{
					current=((node_pointer_ref) current[next]).current;
					--n;
				}

				return *this;
			}

			node_pointer operator + (size_type n) const
			{
				node_pointer out(*this);
				while (n)
				{
					out.current=((node_pointer_ref) out.current[next]).current;
					--n;
				}

				return out;
			}

			node_pointer_ref operator - () const
				{ return (node_pointer_ref) current[previous]; }

			node_pointer_ref operator -- ()
			{
				current=((node_pointer_ref) current[previous]).current;
				return *this;
			}

			node_pointer operator -- (int)
			{
				node_pointer out(*this);
				current=((node_pointer_ref) current[previous]).current;
				return out;
			}

			node_pointer_ref operator -= (size_type n)
			{
				while (n)
				{
					current=((node_pointer_ref) current[previous]).current;
					--n;
				}

				return *this;
			}

			node_pointer operator - (size_type n) const
			{
				node_pointer out(*this);
				while (n)
				{
					out.current=((node_pointer_ref) out.current[previous]).current;
					--n;
				}

				return out;
			}
	};
/*
	const version:
*/
	template<typename T, typename Pointer, typename SizeType, SizeType N>
	using const_node=node<T const, Pointer, SizeType, N>;

	template<typename T, typename SizeType, SizeType N>
	class const_node_pointer : public node_pointer<T const, SizeType, N>
	{
		private:
			typedef node_pointer<T const, SizeType, N> base;
			typedef const_node<T, base, SizeType, N>* const_node_ptr;

			typedef typename base::value_type_ptr value_type_ptr;
			typedef typename base::value_type_ref value_type_ref;
		public:
			const_node_pointer() { }
			const_node_pointer(const_node_ptr p) : base::node_pointer(p) { }
			const_node_pointer(const node_pointer<T, SizeType, N> & p) : base::node_pointer(p) { }
			const_node_pointer(const const_node_pointer & p) : base::node_pointer(p) { }
			~const_node_pointer() { }

			const const_node_pointer & operator = (const_node_ptr p)
			{
				base::operator=(p);
				return *this;
			}

			const const_node_pointer & operator = (const node_pointer<T, SizeType, N> & p)
			{
				base::operator=(p);
				return *this;
			}

			const const_node_pointer & operator = (const const_node_pointer & p)
			{
				base::operator=(p);
				return *this;
			}

			value_type_ref operator * () const
				{ return (value_type_ref) base::current[base::value]; }

			value_type_ptr operator -> () const
				{ return (value_type_ptr) base::current[base::value]; }
	};

	#define HOOK_SIZE 2

	template<typename T, typename SizeType=size_t>
	using hook=node<T, node_pointer<T, SizeType, HOOK_SIZE>, SizeType, HOOK_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_hook=const_node<T, node_pointer<T const, SizeType, HOOK_SIZE>, SizeType, HOOK_SIZE>;

	#undef HOOK_SIZE
	#define LINK_SIZE 3

	template<typename T, typename SizeType=size_t>
	using link=node<T, node_pointer<T, SizeType, LINK_SIZE>, SizeType, LINK_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_link=const_node<T, node_pointer<T const, SizeType, LINK_SIZE>, SizeType, LINK_SIZE>;

	#undef LINK_SIZE
  }
 }
}

#endif
