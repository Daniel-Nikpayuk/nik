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

	By defining the node before the node_pointer, we can call "new node()" outside of the pointer's scope,
	the tradeoff is the extended namespace calling in order to do so (nik::context::context:: ...).
	One would need to typedef. I have included a typedef of the pointer within its node.
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

	template<typename T, typename SizeType, SizeType N> class const_node_pointer;

	template<typename T, typename SizeType, SizeType N>
	class node_pointer
	{
			friend class const_node_pointer<T, SizeType, N>;
		protected:
			typedef node_pointer* node_pointer_ptr;
			typedef node_pointer& node_pointer_ref;
			typedef node<T, node_pointer, SizeType, N>* node_ptr;

			typedef T* value_type_ptr;
			typedef T& value_type_ref;

			typedef SizeType size_type;
			enum : size_type { value=0, next=1, previous=2 };

			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			enum : size_type { dimension=N };
		public:
			node_pointer() { }
			node_pointer(node_ptr p) { current=(void_ptr_ptr) p; }
			node_pointer(const node_pointer & p) { current=p.current; }
			~node_pointer() { }
/*
	Needed for delete conversion.
*/
			operator node_pointer_ptr () const
				{ return (node_pointer_ptr) this; }
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
				{ delete [] ((node_pointer_ptr) p)->current; }

			value_type_ref operator * () const
				{ return (value_type_ref) current[value]; }

			value_type_ptr operator -> () const
				{ return & (value_type_ref) current[value]; }

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
	template<typename T, typename SizeType, SizeType N>
	class const_node_pointer
	{
		protected:
			typedef const_node_pointer* const_node_pointer_ptr;
			typedef const_node_pointer& const_node_pointer_ref;
			typedef node<T const, const_node_pointer, SizeType, N>* const_node_ptr;

			typedef T const * value_type_ptr;
			typedef T const & value_type_ref;

			typedef SizeType size_type;
			enum : size_type { value=0, next=1, previous=2 };

			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			enum : size_type { dimension=N };
		public:
			const_node_pointer() { }
			const_node_pointer(const_node_ptr p) { current=(void_ptr_ptr) p; }
			const_node_pointer(const node_pointer<T, SizeType, N> & p) { current=p.current; }
			const_node_pointer(const const_node_pointer & p) { current=p.current; }
			~const_node_pointer() { }
/*
	Needed for delete conversion.
*/
			operator const_node_pointer_ptr () const
				{ return (const_node_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (node_pointer)".
*/
			operator bool () const
				{ return current; }

			bool operator == (const const_node_pointer & p) const
				{ return (current == p.current); }

			bool operator != (const const_node_pointer & p) const
				{ return (current != p.current); }

			static void operator delete (void_ptr p)
				{ delete [] ((const_node_pointer_ptr) p)->current; }

			value_type_ref operator * () const
				{ return (value_type_ref) current[value]; }

			value_type_ptr operator -> () const
				{ return & (value_type_ref) current[value]; }

			const_node_pointer_ref operator + () const
				{ return (const_node_pointer_ref) current[next]; }

			const_node_pointer_ref operator ++ ()
			{
				current=((const_node_pointer_ref) current[next]).current;
				return *this;
			}

			const_node_pointer operator ++ (int)
			{
				const_node_pointer out(*this);
				current=((const_node_pointer_ref) current[next]).current;
				return out;
			}

			const_node_pointer_ref operator += (size_type n)
			{
				while (n)
				{
					current=((const_node_pointer_ref) current[next]).current;
					--n;
				}

				return *this;
			}

			const_node_pointer operator + (size_type n) const
			{
				const_node_pointer out(*this);
				while (n)
				{
					out.current=((const_node_pointer_ref) out.current[next]).current;
					--n;
				}

				return out;
			}

			const_node_pointer_ref operator - () const
				{ return (const_node_pointer_ref) current[previous]; }

			const_node_pointer_ref operator -- ()
			{
				current=((const_node_pointer_ref) current[previous]).current;
				return *this;
			}

			const_node_pointer operator -- (int)
			{
				const_node_pointer out(*this);
				current=((const_node_pointer_ref) current[previous]).current;
				return out;
			}

			const_node_pointer_ref operator -= (size_type n)
			{
				while (n)
				{
					current=((const_node_pointer_ref) current[previous]).current;
					--n;
				}

				return *this;
			}

			const_node_pointer operator - (size_type n) const
			{
				const_node_pointer out(*this);
				while (n)
				{
					out.current=((const_node_pointer_ref) out.current[previous]).current;
					--n;
				}

				return out;
			}
	};

	#define HOOK_SIZE 2

	template<typename T, typename SizeType=size_t>
	using hook=node<T, node_pointer<T, SizeType, HOOK_SIZE>, SizeType, HOOK_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_hook=node<T const, const_node_pointer<T, SizeType, HOOK_SIZE>, SizeType, HOOK_SIZE>;

	#undef HOOK_SIZE
	#define LINK_SIZE 3

	template<typename T, typename SizeType=size_t>
	using link=node<T, node_pointer<T, SizeType, LINK_SIZE>, SizeType, LINK_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_link=node<T const, const_node_pointer<T, SizeType, LINK_SIZE>, SizeType, LINK_SIZE>;

	#undef LINK_SIZE
  }
 }
}

#endif
