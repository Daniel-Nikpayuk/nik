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

	In terms of dynamic binding, unit::const_pointers can semantically be considered a unit::pointer subclass,
	and is nearly implemented as such. As it stands, I have decided to prevent the use of polymorphism,
	and have implemented this code in such a way that the compiler will allow no such direct conversion.

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.

	void pointer casting is subtle, as the same memory cast to two different types works, but referencing within such memory
	changes on the interpretation of the type of that memory.
*/

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
	template<typename T, typename SizeType, SizeType N> class const_pointer;

	template<typename T, typename SizeType, SizeType N>
	class pointer
	{
		private:
			friend class const_pointer<T, SizeType, N>;
		protected:
			typedef pointer* pointer_ptr;
			typedef pointer& pointer_ref;
			typedef pointer_ptr& pointer_ptr_ref;

			typedef T value_type;
			typedef T* value_type_ptr;
			typedef T& value_type_ref;

			typedef void* void_ptr;
			typedef void_ptr* void_ptr_ptr;

			typedef SizeType size_type;

			enum : size_type { value=0, next=1, previous=2, dimension=N };

				// an array of unknown types.
			void_ptr_ptr current;
		public:
			void initialize()
				{ current=new void_ptr[N]; }
/*
	Does not properly clear the memory for cycle efficiency.
*/
			void terminalize()
				{ delete [] current; }

			pointer() { }
			pointer(pointer_ptr p) { current=p? p->current : 0; }
			pointer(const pointer & p) { current=p.current; }
			~pointer() { }

/*
	In the case p == this, nothing is changed.

	This version is needed in case a pointer is dereferenced before it is initialized.
	In such a case, the compiler assumes it is initialized and will call the equals operator
	before calling the necessary constructor.
*/
			const pointer & operator = (pointer_ptr p)
			{
				current=p? p->current : 0;
				return *this;
			}
/*
	In the case &p == this, nothing is changed.
*/
			const pointer & operator = (const pointer & p)
			{
				current=p.current;
				return *this;
			}

			static void_ptr operator new (size_t n)
			{
				pointer_ptr p=(pointer_ptr) ::operator new (n);
				p->initialize();
				return p;
			}

// correct?
			static void operator delete (void_ptr p)
			{
				((pointer_ptr) p)->terminalize();
				::operator delete (p);
			}

			value_type_ref operator * () const
				{ return (value_type_ref) current[value]; }

			value_type_ptr operator -> () const
				{ return (value_type_ptr) current[value]; }

			operator bool () const
				{ return current; }

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
			const_pointer(const_pointer_ptr p) : base::pointer(p) { }
			const_pointer(const pointer<T, SizeType, N> & p) : base::pointer(p.current) { }
			const_pointer(const const_pointer & p) : base::pointer(p) { }
			~const_pointer() { }

			const const_pointer & operator = (const const_pointer & p)
				{ return base::operator=(p); }

			value_type_ref operator * () const
				{ return (value_type_ref) base::current[base::value]; }

			value_type_ptr operator -> () const
				{ return (value_type_ptr) base::current[base::value]; }
	};

	#define LIST_SIZE 2
	#define CHAIN_SIZE 3

	template<typename T>
	using list_pointer=pointer<T, size_t, LIST_SIZE>;

	template<typename T>
	using const_list_pointer=const_pointer<T, size_t, LIST_SIZE>;

	template<typename T>
	using chain_pointer=pointer<T, size_t, CHAIN_SIZE>;

	template<typename T>
	using const_chain_pointer=const_pointer<T, size_t, CHAIN_SIZE>;

	#undef CHAIN_SIZE
	#undef LIST_SIZE
  }
 }
}

#endif
