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

#ifndef SEMIOTIC_ITERATOR_LINKED_POINTER_H
#define SEMIOTIC_ITERATOR_LINKED_POINTER_H

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
   namespace unit
   {
	template<typename T, typename SizeType, SizeType N>
	struct linked_pointer
	{
		typedef T value_type;
		typedef T* type_ptr;
		typedef T& type_ref;
		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;
		typedef void_ptr& void_ptr_ref;
		typedef SizeType size_type;

		void_ptr current;

		void new_linked_pointer()
			{ current=new void_ptr[N]; }

		void new_linked_pointer(const value_type & value)
		{
			current=new void_ptr[N];
			*((type_ptr) current)=value;
		}

		void delete_linked_pointer()
			{ delete [] current; }

		type_ref operator * ()
			{ return *((type_ptr) current); }
	};
   }

   namespace forward
   {
   }

   namespace backward
   {
   }

   namespace bidirectional
   {
   }

   namespace random_access
   {
	template<typename T, typename SizeType>
	struct linked_pointer
	{
		typedef unit::linked_pointer<T, SizeType, 3> base;
		typedef typename base::value_type value_type;
		typedef typename base::type_ptr type_ptr;
		typedef typename base::type_ref type_ref;
		typedef typename base::void_ptr void_ptr;
		typedef typename base::void_ptr_ptr void_ptr_ptr;
		typedef typename base::void_ptr_ref void_ptr_ref;
		typedef typename base::size_type size_type;

		enum : size_type { next=1, prev=2 };

		linked_pointer() { }
		linked_pointer(size_type n) : base::current(n) { }
		template<typename Pointer> linked_pointer(Pointer p)
			{ base::current=p.base::current; }

		~linked_pointer() { }

		void_ptr_ref operator + ()
			{ return ((void_ptr_ptr) base::current)[next]; }

		linked_pointer & operator ++ ()
		{
			base::current=((void_ptr_ptr) base::current)[next];
			return *this;
		}

		linked_pointer operator ++ (int)
		{
			linked_pointer out(*this);
			base::current=((void_ptr_ptr) base::current)[next];
			return out;
		}

		linked_pointer & operator += (size_type n)
		{
			while (n)
			{
				base::current=((void_ptr_ptr) base::current)[next];
				--n;
			}

			return *this;
		}

		linked_pointer operator + (size_type n)
		{
			linked_pointer out(*this);
			while (n)
			{
				out.base::current=((void_ptr_ptr) out.base::current)[next];
				--n;
			}

			return out;
		}

		void_ptr_ref operator - ()
			{ return ((void_ptr_ptr) base::current)[prev]; }

		linked_pointer & operator -- ()
		{
			base::current=((void_ptr_ptr) base::current)[prev];
			return *this;
		}

		linked_pointer operator -- (int)
		{
			linked_pointer out(*this);
			base::current=((void_ptr_ptr) base::current)[prev];
			return out;
		}

		linked_pointer & operator -= (size_type n)
		{
			while (n)
			{
				base::current=((void_ptr_ptr) base::current)[prev];
				--n;
			}

			return *this;
		}

		linked_pointer operator - (size_type n)
		{
			linked_pointer out(*this);
			while (n)
			{
				out.base::current=((void_ptr_ptr) out.base::current)[prev];
				--n;
			}

			return out;
		}
	};
   }
  }
 }
}

#endif
