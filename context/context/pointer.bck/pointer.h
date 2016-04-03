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

	A proper amount of memory needs to be allocated for "current" when constructed,
	otherwise there will be subtle and strange bugs and behaviours!
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
	template<typename T>
	struct type
	{
		T value;

		type() { }
		type(const T & v) : value(v) { }
		~type() { }

		const type & operator = (const type & n)
			{ value=n.value; }
	};

	template<typename T, typename SizeType, SizeType N>
	class type_pointer
	{
		protected:
			typedef type_pointer* type_pointer_ptr;
			typedef type_pointer& type_pointer_ref;
			typedef type_pointer_ptr* type_pointer_ptr_ptr;
			typedef type_pointer_ptr& type_pointer_ptr_ref;

			typedef type_pointer<T const, SizeType, N> const_type_pointer;

			typedef type<T>* type_ptr;

			typedef T value_type;
			typedef T* value_type_ptr;
			typedef T& value_type_ref;

			typedef SizeType size_type;

			enum : size_type { next=0, previous=1, dimension=N };
		protected:
			type_ptr current;
			type_pointer_ptr_ptr array;
		public:
			type_pointer() { }
			type_pointer(type_ptr p)
			{
				current=p;
				array=new type_pointer_ptr[N];
			}
			type_pointer(const type_pointer & p)
			{
				current=p.current;
				array=p.array;
			}
			~type_pointer() { }
/*
	This version is needed for compatibility with the existing constructors, to accept "=new type()" code.
	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const type_pointer & operator = (type_ptr p)
			{
				current=p;
				array=new type_pointer_ptr[N];
				return *this;
			}
/*
	In the case &p == this, nothing is changed.
	Allows for potential memory leak. Burden is placed on the api coder.
*/
			const type_pointer & operator = (const type_pointer & p)
			{
				current=p.current;
				array=p.array;
				return *this;
			}
/*
	Sufficient? Or does this cause memory leaks?
*/
			static void operator delete (void_ptr p)
			{
				delete p->array;
				delete p->current;
			}
/*
	Needed for loop condition testing "while (type_pointer)".
*/
			operator bool () const
				{ return current; }
/*
	Needed for delete conversion.
*/
			operator type_pointer_ptr () const
				{ return (type_pointer_ptr) this; }
/*
	Needed for implicit const conversions.
*/
			operator const const_type_pointer & () const
				{ return *((const_type_pointer*) this); }
/*
	Broader definitions of equality comparison.
*/
			bool operator == (const type_pointer & p) const
				{ return (current == p.current && array == p.array); }
/*
	Broader definitions of inequality comparison.
*/
			bool operator != (const type_pointer & p) const
				{ return (current != p.current || array != p.array); }
/*
	Virtually defined as const_type_pointer redefines it.
*/
			virtual value_type_ref operator * () const
				{ return (value_type_ref) current->value; }
/*
	Virtually defined as const_type_pointer redefines it.
*/
			virtual value_type_ptr operator -> () const
				{ return (value_type_ptr) current->value; }

			type_pointer_ptr_ref operator + () const
				{ return array[next]; }

			type_pointer_ref operator ++ ()
			{
				current=array[next]->current;
				array=array[next]->array;
				return *this;
			}

			type_pointer operator ++ (int)
			{
				type_pointer out(*this);
				current=array[next]->current;
				array=array[next]->array;
				return out;
			}

			type_pointer_ref operator += (size_type n)
			{
				while (n)
				{
					current=array[next]->current;
					array=array[next]->array;
					--n;
				}

				return *this;
			}

			type_pointer operator + (size_type n) const
			{
				type_pointer out(*this);
				while (n)
				{
					out.current=out.array[next]->current;
					out.array=out.array[next]->array;
					--n;
				}

				return out;
			}

			type_pointer_ptr_ref operator - () const
				{ return array[previous]; }

			type_pointer_ref operator -- ()
			{
				current=array[previous]->current;
				array=array[previous]->array;
				return *this;
			}

			type_pointer operator -- (int)
			{
				type_pointer out(*this);
				current=array[previous]->current;
				array=array[previous]->array;
				return out;
			}

			type_pointer_ref operator -= (size_type n)
			{
				while (n)
				{
					current=array[previous]->current;
					array=array[previous]->array;
					--n;
				}

				return *this;
			}

			type_pointer operator - (size_type n) const
			{
				type_pointer out(*this);
				while (n)
				{
					out.current=out.array[previous]->current;
					out.array=out.array[previous]->array;
					--n;
				}

				return out;
			}
	};

	#define HOOK_SIZE 1
	#define LINK_SIZE 2

	template<typename T> using hook=type<T>;

	template<typename T, typename SizeType=size_t>
	using hook_pointer=pointer<T, SizeType, HOOK_SIZE>;

	#undef LINK_SIZE
	#undef HOOK_SIZE
  }
 }
}

#endif
