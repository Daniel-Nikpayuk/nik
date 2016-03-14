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

/*
	This class is meant to be as narratively similar as possible to the builtin array pointer.

	It is natural that unit::pointers should be able to convert to unit::const_pointers, as such within the unit::const_pointer
	class there is a conversion constructor---thus the additional need to (at least) declare the existence of the unit::pointer
	class ahead of time.

	Moreover, in terms of dynamic binding, unit::const_pointers can semantically be considered a unit::pointer subclass,
	and are as such implemented that way (the compiler will thus all polymorphic conversion of a unit::const_pointer*
	to a unit::pointer*.

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.
*/

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
   namespace unit
   {
	template<typename T, typename SizeType, SizeType N> class const_pointer;

	template<typename T, typename SizeType, SizeType N>
	class pointer
	{
		private:
			friend class const_pointer<T, SizeType, N>;
		protected:
			typedef T value_type;
			typedef T* value_type_ptr;
			typedef T& value_type_ref;
			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;
			typedef void_ptr& void_ptr_ref;
			typedef void_ptr_ptr* void_ptr_ptr_ptr;
			typedef void_ptr_ptr& void_ptr_ptr_ref;
			typedef SizeType size_type;

			enum : size_type { value=0, next=1, previous=2, dimension=N };

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			void initialize()
				{ current=new void_ptr[N]; }

			void terminalize()
				{ delete [] current; }

			pointer() { }
			pointer(void_ptr_ptr p) { current=p; }
			pointer(const pointer & p) { current=p.current; }
			~pointer() { }

			const pointer & operator = (const pointer & p)
			{
				current=p.current;
				return *this;
			}

			value_type_ref operator * ()
				{ return *((value_type_ptr) current); }

			void_ptr_ptr_ref operator + () const
				{ return ((void_ptr_ptr_ptr) current)[next]; }

			pointer & operator ++ ()
			{
				current=((void_ptr_ptr_ptr) current)[next];
				return *this;
			}

			pointer operator ++ (int)
			{
				pointer out(*this);
				current=((void_ptr_ptr_ptr) current)[next];
				return out;
			}

			pointer & operator += (size_type n)
			{
				while (n)
				{
					current=((void_ptr_ptr_ptr) current)[next];
					--n;
				}

				return *this;
			}

			pointer operator + (size_type n) const
			{
				pointer out(*this);
				while (n)
				{
					out.current=((void_ptr_ptr_ptr) out.current)[next];
					--n;
				}

				return out;
			}

			void_ptr_ptr_ref operator - () const
				{ return ((void_ptr_ptr_ptr) current)[previous]; }

			pointer & operator -- ()
			{
				current=((void_ptr_ptr_ptr) current)[previous];
				return *this;
			}

			pointer operator -- (int)
			{
				pointer out(*this);
				current=((void_ptr_ptr_ptr) current)[previous];
				return out;
			}

			pointer & operator -= (size_type n)
			{
				while (n)
				{
					current=((void_ptr_ptr_ptr) current)[previous];
					--n;
				}

				return *this;
			}

			pointer operator - (size_type n) const
			{
				pointer out(*this);
				while (n)
				{
					out.current=((void_ptr_ptr_ptr) out.current)[previous];
					--n;
				}

				return out;
			}
	};

	template<typename T, typename SizeType, SizeType N>
	class const_pointer : public pointer<T const, SizeType, N>
	{
		private:
			typedef pointer<T const, SizeType, N> base;
			typedef typename base::value_type value_type;
			typedef typename base::value_type_ptr value_type_ptr;
			typedef typename base::value_type_ref value_type_ref;
			typedef typename base::void_ptr void_ptr;
			typedef typename base::void_ptr_ptr void_ptr_ptr;
			typedef typename base::void_ptr_ref void_ptr_ref;
			typedef typename base::void_ptr_ptr_ptr void_ptr_ptr_ptr;
			typedef typename base::void_ptr_ptr_ref void_ptr_ptr_ref;
			typedef typename base::size_type size_type;
		public:
			const_pointer() { }
			const_pointer(void_ptr_ptr p) : base::pointer(p) { }
			const_pointer(const pointer<T, SizeType, N> & p) : base::pointer(p.current) { }
			const_pointer(const const_pointer & p) : base::pointer(p) { }
			~const_pointer() { }

			const const_pointer & operator = (const const_pointer & p)
				{ return base::operator=(p); }

			value_type_ref operator * ()
				{ return *((value_type_ptr) base::current); }
	};
   }

	#define LINKED_SIZE 2
	#define CHAINED_SIZE 3

	template<typename T>
	using linked_pointer=unit::pointer<T, size_t, LINKED_SIZE>;

	template<typename T>
	using const_linked_pointer=unit::const_pointer<T, size_t, LINKED_SIZE>;

	template<typename T>
	using chained_pointer=unit::pointer<T, size_t, CHAINED_SIZE>;

	template<typename T>
	using const_chained_pointer=unit::const_pointer<T, size_t, CHAINED_SIZE>;
  }
 }

	void** new_linked_pointer() { return new void *[LINKED_SIZE]; }

	template<typename T>
	void** new_linked_pointer(const T & v)
	{
		void **rtn=new void *[LINKED_SIZE];
		*((T*) rtn)=v;
		return rtn;
	}

	void** new_const_linked_pointer() { return new void *[LINKED_SIZE]; }

	template<typename T>
	void** new_const_linked_pointer(const T & v)
	{
		void **rtn=new void *[LINKED_SIZE];
		*((T*) rtn)=v;
		return rtn;
	}

	void** new_chained_pointer() { return new void *[CHAINED_SIZE]; }

	template<typename T>
	void** new_chained_pointer(const T & v)
	{
		void **rtn=new void *[CHAINED_SIZE];
		*((T*) rtn)=v;
		return rtn;
	}

	void** new_const_chained_pointer() { return new void *[CHAINED_SIZE]; }

	template<typename T>
	void** new_const_chained_pointer(const T & v)
	{
		void **rtn=new void *[CHAINED_SIZE];
		*((T*) rtn)=v;
		return rtn;
	}

	#undef CHAINED_SIZE
	#undef LINKED_SIZE
}

#endif
