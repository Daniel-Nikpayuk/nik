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

/*
	Is not meant to be interpeted as a "class" or an "object" even if it is implemented that way.
	It is only meant to have an allocator as well as meta information about the type of memory it holds.
*/

template<typename Pointer>
class base
{
	public:
		typedef Pointer pointer;
		typedef typename pointer::value_type value_type;
		typedef typename pointer::size_type size_type;
	protected:
		typedef void* void_ptr;
	public:
		static void_ptr operator new (size_t n)
			{ return new void_ptr[pointer::dimension]; }
};

template<typename T, size_type N> class const_base_pointer;

template<typename T, size_type N>
class base_pointer
{
		friend class const_base_pointer<T, N>;
	public:
		typedef T value_type;
		typedef node::size_type size_type;

		enum : size_type { dimension=N };
	protected:
		typedef base_pointer* base_pointer_ptr;
		typedef base_pointer& base_pointer_ref;
		typedef base<base_pointer>* base_ptr;

		typedef T* value_type_ptr;
		typedef T& value_type_ref;

		enum : size_type { value=0, next=1, previous=2 };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
	public:
		base_pointer() { }
		base_pointer(base_ptr p) { current=(void_ptr_ptr) p; }
		base_pointer(const base_pointer & p) { current=p.current; }
		~base_pointer() { }
/*
	Needed for delete conversion.
*/
		operator base_pointer_ptr () const
			{ return (base_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (base_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const base_pointer & p) const
			{ return (current == p.current); }

		bool operator != (const base_pointer & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((base_pointer_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		base_pointer_ref operator + () const
			{ return (base_pointer_ref) current[next]; }

		base_pointer_ref operator ++ ()
		{
			current=((base_pointer_ref) current[next]).current;
			return *this;
		}

		base_pointer operator ++ (int)
		{
			base_pointer out(*this);
			current=((base_pointer_ref) current[next]).current;
			return out;
		}

		base_pointer_ref operator += (size_type n)
		{
			while (n)
			{
				current=((base_pointer_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		base_pointer operator + (size_type n) const
		{
			base_pointer out(*this);
			while (n)
			{
				out.current=((base_pointer_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		base_pointer_ref operator - () const
			{ return (base_pointer_ref) current[previous]; }

		base_pointer_ref operator -- ()
		{
			current=((base_pointer_ref) current[previous]).current;
			return *this;
		}

		base_pointer operator -- (int)
		{
			base_pointer out(*this);
			current=((base_pointer_ref) current[previous]).current;
			return out;
		}

		base_pointer_ref operator -= (size_type n)
		{
			while (n)
			{
				current=((base_pointer_ref) current[previous]).current;
				--n;
			}

			return *this;
		}

		base_pointer operator - (size_type n) const
		{
			base_pointer out(*this);
			while (n)
			{
				out.current=((base_pointer_ref) out.current[previous]).current;
				--n;
			}

			return out;
		}

		size_type operator - (base_pointer p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((base_pointer_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};

/*
	const version:
*/

template<typename T, size_type N>
class const_base_pointer
{
	public:
		typedef T const value_type;
		typedef node::size_type size_type;

		enum : size_type { dimension=N };
	protected:
		typedef const_base_pointer* const_base_pointer_ptr;
		typedef const_base_pointer& const_base_pointer_ref;
		typedef base<const_base_pointer>* const_base_ptr;

		typedef T const * value_type_ptr;
		typedef T const & value_type_ref;

		enum : size_type { value=0, next=1, previous=2 };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
	public:
		const_base_pointer() { }
		const_base_pointer(const_base_ptr p) { current=(void_ptr_ptr) p; }
		const_base_pointer(const base_pointer<T, N> & p) { current=p.current; }
		const_base_pointer(const const_base_pointer & p) { current=p.current; }
		~const_base_pointer() { }
/*
	Needed for delete conversion.
*/
		operator const_base_pointer_ptr () const
			{ return (const_base_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (base_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const const_base_pointer & p) const
			{ return (current == p.current); }

		bool operator != (const const_base_pointer & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((const_base_pointer_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		const_base_pointer_ref operator + () const
			{ return (const_base_pointer_ref) current[next]; }

		const_base_pointer_ref operator ++ ()
		{
			current=((const_base_pointer_ref) current[next]).current;
			return *this;
		}

		const_base_pointer operator ++ (int)
		{
			const_base_pointer out(*this);
			current=((const_base_pointer_ref) current[next]).current;
			return out;
		}

		const_base_pointer_ref operator += (size_type n)
		{
			while (n)
			{
				current=((const_base_pointer_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		const_base_pointer operator + (size_type n) const
		{
			const_base_pointer out(*this);
			while (n)
			{
				out.current=((const_base_pointer_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		const_base_pointer_ref operator - () const
			{ return (const_base_pointer_ref) current[previous]; }

		const_base_pointer_ref operator -- ()
		{
			current=((const_base_pointer_ref) current[previous]).current;
			return *this;
		}

		const_base_pointer operator -- (int)
		{
			const_base_pointer out(*this);
			current=((const_base_pointer_ref) current[previous]).current;
			return out;
		}

		const_base_pointer_ref operator -= (size_type n)
		{
			while (n)
			{
				current=((const_base_pointer_ref) current[previous]).current;
				--n;
			}

			return *this;
		}

		const_base_pointer operator - (size_type n) const
		{
			const_base_pointer out(*this);
			while (n)
			{
				out.current=((const_base_pointer_ref) out.current[previous]).current;
				--n;
			}

			return out;
		}

		size_type operator - (const_base_pointer p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((const_base_pointer_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};

