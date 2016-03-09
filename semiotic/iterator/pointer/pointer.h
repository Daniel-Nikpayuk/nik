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

#ifndef SEMIOTIC_ITERATOR_POINTER_H
#define SEMIOTIC_ITERATOR_POINTER_H

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
	template<typename SizeType, typename T, SizeType FwdPos=1, SizeType BwdPos=2>
	struct pointer
	{
		typedef T value_type;
		typedef T* type_ptr;
		typedef T& type_ref;
		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;
		typedef void_ptr& void_ptr_ref;
		typedef SizeType size_type;

		void_ptr current;

		pointer() : current(0) { }
		~pointer() { }

		pointer(const pointer & p)
			{ current=new void_ptr(p); }

		type_ref operator * ()
			{ return *((type_ptr) current); }

		void_ptr_ref operator + ()
			{ return ((void_ptr_ptr) current)[FwdPos]; }

		pointer & operator ++ ()
		{
			current=((void_ptr_ptr) current)[FwdPos];
			return *this;
		}

		pointer operator ++ (int)
		{
			pointer out(*this);
			current=((void_ptr_ptr) current)[FwdPos];
			return out;
		}

		pointer & operator += (size_type n)
		{
			while (n)
			{
				current=((void_ptr_ptr) current)[FwdPos];
				--n;
			}

			return *this;
		}

		pointer operator + (size_type n)
		{
			pointer out(*this);
			while (n)
			{
				out.current=((void_ptr_ptr) out.current)[FwdPos];
				--n;
			}

			return out;
		}

		void_ptr_ref operator - ()
			{ return ((void_ptr_ptr) current)[BwdPos]; }

		pointer & operator -- ()
		{
			current=((void_ptr_ptr) current)[BwdPos];
			return *this;
		}

		pointer operator -- (int)
		{
			pointer out(*this);
			current=((void_ptr_ptr) current)[BwdPos];
			return out;
		}

		pointer & operator -= (size_type n)
		{
			while (n)
			{
				current=((void_ptr_ptr) current)[BwdPos];
				--n;
			}

			return *this;
		}

		pointer operator - (size_type n)
		{
			pointer out(*this);
			while (n)
			{
				out.current=((void_ptr_ptr) out.current)[BwdPos];
				--n;
			}

			return out;
		}
	};

   namespace forward
   {
	template<typename SizeType, typename T>
	struct linked_pointer : public pointer<SizeType, T, 1, 1>
	{
		typedef pointer<SizeType, T, 1, 1> base;
		typedef typename base::value_type value_type;
		typedef typename base::type_ptr type_ptr;
		typedef typename base::type_ref type_ref;
		typedef typename base::void_ptr void_ptr;
		typedef typename base::void_ptr_ptr void_ptr_ptr;
		typedef typename base::void_ptr_ref void_ptr_ref;
		typedef typename base::size_type size_type;
	
		linked_pointer() : base::current(0) { }
	
		linked_pointer(const value_type & value)
		{
			base::current=new void_ptr[2];
			*((type_ptr) base::current)=value;
		}
	
		~linked_pointer() { } // design policy not yet in place.
	
		using base::operator *;
	
		using base::operator +;
		using base::operator ++;
	
		private:
			using base::operator +=;

			using base::operator -;
			using base::operator --;
			using base::operator -=;
	};

	template<typename T>
	using linked_ptr=linked_pointer<size_t, T>;
   }

   namespace backward
   {
	template<typename SizeType, typename T>
	struct linked_pointer : public pointer<SizeType, T, 1, 1>
	{
		typedef pointer<SizeType, T, 1, 1> base;
		typedef typename base::value_type value_type;
		typedef typename base::type_ptr type_ptr;
		typedef typename base::type_ref type_ref;
		typedef typename base::void_ptr void_ptr;
		typedef typename base::void_ptr_ptr void_ptr_ptr;
		typedef typename base::void_ptr_ref void_ptr_ref;
		typedef typename base::size_type size_type;
	
		linked_pointer() : base::current(0) { }
	
		linked_pointer(const value_type & value)
		{
			base::current=new void_ptr[2];
			*((type_ptr) base::current)=value;
		}
	
		~linked_pointer() { } // design policy not yet in place.
	
		using base::operator *;

		using base::operator -;
		using base::operator --;
	
		private:
			using base::operator +;
			using base::operator ++;
			using base::operator +=;

			using base::operator -=;
	};

	template<typename T>
	using linked_ptr=linked_pointer<size_t, T>;
   }

   namespace bidirectional
   {
	template<typename SizeType, typename T>
	struct linked_pointer : public pointer<SizeType, T>
	{
		typedef pointer<SizeType, T> base;
		typedef typename base::value_type value_type;
		typedef typename base::type_ptr type_ptr;
		typedef typename base::type_ref type_ref;
		typedef typename base::void_ptr void_ptr;
		typedef typename base::void_ptr_ptr void_ptr_ptr;
		typedef typename base::void_ptr_ref void_ptr_ref;
		typedef typename base::size_type size_type;
	
		linked_pointer() : base::current(0) { }
	
		linked_pointer(const value_type & value)
		{
			base::current=new void_ptr[3];
			*((type_ptr) base::current)=value;
		}
	
		~linked_pointer() { } // design policy not yet in place.
	
		using base::operator *;
	
		using base::operator +;
		using base::operator ++;

		using base::operator -;
		using base::operator --;
	
		private:
			using base::operator +=;

			using base::operator -=;
	};

	template<typename T>
	using linked_ptr=linked_pointer<size_t, T>;
   }

   namespace random_access
   {
	template<typename SizeType, typename T>
	struct linked_pointer : public pointer<SizeType, T>
	{
		typedef pointer<SizeType, T> base;
		typedef typename base::value_type value_type;
		typedef typename base::type_ptr type_ptr;
		typedef typename base::type_ref type_ref;
		typedef typename base::void_ptr void_ptr;
		typedef typename base::void_ptr_ptr void_ptr_ptr;
		typedef typename base::void_ptr_ref void_ptr_ref;
		typedef typename base::size_type size_type;
	
		linked_pointer() : base::current(0) { }
	
		linked_pointer(const value_type & value)
		{
			base::current=new void_ptr[3];
			*((type_ptr) base::current)=value;
		}
	
		~linked_pointer() { } // design policy not yet in place.
	
		using base::operator *;
	
		using base::operator +;
		using base::operator ++;
		using base::operator +=;
	
		using base::operator -;
		using base::operator --;
		using base::operator -=;
	};

	template<typename T>
	using linked_ptr=linked_pointer<size_t, T>;
   }
  }
 }
}

#endif
