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

#ifndef NIK_CONTEXT_CONTEXT_POINTER_H
#define NIK_CONTEXT_CONTEXT_POINTER_H

#include<stddef.h>

/*
	This class is meant to be as narratively similar as possible to the builtin array pointer.

	It is natural that unit::pointers should be able to convert to unit::const_pointers, as such within the unit::const_pointer
	class there is a conversion constructor---thus the additional need to (at least) declare the existence of the unit::pointer
	class ahead of time.

	In terms of dynamic binding, unit::const_pointers can semantically be considered a unit::pointer subclass,
	and is nearly implemented as such. As it stands, I have decided to prevent the use of polymorphism,
	and have implemented this code in such a way that the compiler will allow no such direct conversion.

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.

	void pointer casting is subtle, as the same memory cast to two different types works, but referencing within such memory
	changes on the interpretation of the type of that memory.
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
	template<typename T, typename SizeType, SizeType N>
	class pointer
	{
		protected:
			typedef pointer* pointer_ptr;
			typedef pointer& pointer_ref;
			typedef pointer_ptr& pointer_ptr_ref;

			typedef T value_type;
			typedef T* value_type_ptr;
			typedef T& value_type_ref;

			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;

			typedef pointer<T const, SizeType, N> const_pointer;

			typedef SizeType size_type;

			enum : size_type { value=0, next=1, previous=2, dimension=N };

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			void initialize()
				{ current=new void_ptr[N]; }
/*
	Does not properly clear the memory for cycle efficiency. Burden: Memory leaks.
*/
			void terminalize()
				{ delete [] current; }

			pointer() { }
			pointer(pointer_ptr p) { current=p? p->current : 0; }
/*
	"const pointer &" can't be zero, so no need to safely test against it.
*/
			pointer(const pointer & p) { current=p.current; }
			~pointer() { }
/*
	In the case p == this, nothing is changed.

	This version is needed for compatibility with the existing constructors, to accept "=new pointer()" code.

	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const pointer & operator = (pointer_ptr p)
			{
				current=p? p->current : 0;
				return *this;
			}
/*
	In the case &p == this, nothing is changed.

	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const pointer & operator = (const pointer & p)
			{
				current=p.current;
				return *this;
			}
/*
	Needed for loop condition testing "while (pointer)".
*/
			operator bool () const
				{ return current; }
/*
	Needed for delete conversion.
*/
			operator pointer_ptr () const
				{ return (pointer_ptr) this; }
/*
	Needed for implicit const conversions.
*/
			operator const const_pointer & () const
				{ return *((const_pointer*) this); }
/*
	Broader definitions of equality comparison.
*/
			bool operator == (const pointer & p) const
				{ return (current == p.current); }

			bool operator != (const pointer & p) const
				{ return (current != p.current); }
/*
	Safely initializes the pointer before passing it on.
*/
			static void_ptr operator new (size_t n)
			{
				pointer_ptr p=(pointer_ptr) ::operator new (n);
				p->initialize();
				return p;
			}
/*
	Sufficient? Or does this cause memory leaks?
*/
			static void operator delete (void_ptr p)
				{ ((pointer_ptr) p)->terminalize(); }
/*
	Virtually defined as const_pointer redefines it.
*/
			virtual value_type_ref operator * () const
				{ return (value_type_ref) current[value]; }
/*
	Virtually defined as const_pointer redefines it.
*/
			virtual value_type_ptr operator -> () const
				{ return (value_type_ptr) current[value]; }

			pointer_ptr_ref operator + () const
				{ return (pointer_ptr_ref) current[next]; }

			pointer_ref operator ++ ()
			{
				current=((pointer_ptr) current[next])->current;
				return *this;
			}

			pointer operator ++ (int)
			{
				pointer out(*this);
				current=((pointer_ptr) current[next])->current;
				return out;
			}

			pointer_ref operator += (size_type n)
			{
				while (n)
				{
					current=((pointer_ptr) current[next])->current;
					--n;
				}

				return *this;
			}

			pointer operator + (size_type n) const
			{
				pointer out(*this);
				while (n)
				{
					out.current=((pointer_ptr) out.current[next])->current;
					--n;
				}

				return out;
			}

			pointer_ptr_ref operator - () const
				{ return (pointer_ptr_ref) current[previous]; }

			pointer_ref operator -- ()
			{
				current=((pointer_ptr) current[previous])->current;
				return *this;
			}

			pointer operator -- (int)
			{
				pointer out(*this);
				current=((pointer_ptr) current[previous])->current;
				return out;
			}

			pointer_ref operator -= (size_type n)
			{
				while (n)
				{
					current=((pointer_ptr) current[previous])->current;
					--n;
				}

				return *this;
			}

			pointer operator - (size_type n) const
			{
				pointer out(*this);
				while (n)
				{
					out.current=((pointer_ptr) out.current[previous])->current;
					--n;
				}

				return out;
			}
	};
/*
	GCC 4.8.4 crashes when declaring a const_pointer if an uninitialized pointer has been dereferenced in the existing code.

	Dereferencing an uninitialized pointer has undefined behaviour to begin with, and in practice would not happen anyway.
	The policy here might change to initialize the pointer array member in the above pointer class to be zero,
	but for now narrative consistency is preferred.
*/
	template<typename T, typename SizeType, SizeType N>
	class const_pointer : public pointer<T const, SizeType, N>
	{
		private:
			typedef const_pointer* const_pointer_ptr;
			typedef const_pointer& const_pointer_ref;
			typedef const_pointer_ptr& const_pointer_ptr_ref;

			typedef pointer<T const, SizeType, N> base;

			typedef typename base::value_type value_type;
			typedef typename base::value_type_ptr value_type_ptr;
			typedef typename base::value_type_ref value_type_ref;

			typedef typename base::void_ptr void_ptr;
			typedef typename base::void_ptr_ptr void_ptr_ptr;

			typedef typename base::size_type size_type;
		public:
			const_pointer() { }
			const_pointer(const base & p) : base::pointer(p) { }
			const_pointer(const_pointer_ptr p) : base::pointer(p) { }
			const_pointer(const const_pointer & p) : base::pointer(p) { }
			~const_pointer() { }

			const const_pointer & operator = (const base & p)
			{
				base::operator=(p);
				return *this;
			}

			const const_pointer & operator = (const_pointer_ptr p)
			{
				base::operator=(p);
				return *this;
			}

			const const_pointer & operator = (const const_pointer & p)
			{
				base::operator=(p);
				return *this;
			}

			value_type_ref operator * () const
				{ return (value_type_ref) base::current[base::value]; }

			value_type_ptr operator -> () const
				{ return (value_type_ptr) base::current[base::value]; }
	};

	#define LIST_SIZE 2
	#define CHAIN_SIZE 3

	template<typename T, typename SizeType=size_t>
	using list_pointer=pointer<T, SizeType, LIST_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_list_pointer=const_pointer<T, SizeType, LIST_SIZE>;

	template<typename T, typename SizeType=size_t>
	using chain_pointer=pointer<T, SizeType, CHAIN_SIZE>;

	template<typename T, typename SizeType=size_t>
	using const_chain_pointer=const_pointer<T, SizeType, CHAIN_SIZE>;

	#undef CHAIN_SIZE
	#undef LIST_SIZE
  }
 }
}

#endif
