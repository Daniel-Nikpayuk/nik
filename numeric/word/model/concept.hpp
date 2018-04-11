/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
*/

template<typename BitType, size_type length>
class word
{
	public:
		typedef BitType value_type;
	protected:
		enum : size_type { value=0, next };

			// an array of unknown types.
		value_type current[length];
	public:
		hook_pointer() { }
		hook_pointer(hook_ptr p) { current=(void_ptr_ptr) p; }
		hook_pointer(const hook_pointer & p) { current=p.current; }
		~hook_pointer() { }
/*
	Needed for delete conversion.
*/
		operator hook_pointer_ptr () const
			{ return (hook_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (hook_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const hook_pointer & p) const
			{ return (current == p.current); }

		bool operator != (const hook_pointer & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((hook_pointer_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		hook_pointer_ref operator + () const
			{ return (hook_pointer_ref) current[next]; }

		hook_pointer_ref operator ++ ()
		{
			current=((hook_pointer_ref) current[next]).current;
			return *this;
		}

		hook_pointer operator ++ (int)
		{
			hook_pointer out(*this);
			current=((hook_pointer_ref) current[next]).current;
			return out;
		}

		hook_pointer_ref operator += (size_type n)
		{
			while (n)
			{
				current=((hook_pointer_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		hook_pointer operator + (size_type n) const
		{
			hook_pointer out(*this);
			while (n)
			{
				out.current=((hook_pointer_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		size_type operator - (hook_pointer p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((hook_pointer_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};

/*
	const version:
*/

template<typename T> class const_hook;

template<typename T>
class const_hook_pointer
{
	public:
		typedef T const value_type;

	protected:
		typedef const_hook_pointer* const_hook_pointer_ptr;
		typedef const_hook_pointer& const_hook_pointer_ref;
		typedef const_hook<T>* const_hook_ptr;

		typedef value_type* value_type_ptr;
		typedef value_type& value_type_ref;

		enum : size_type { value=0, next };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
	public:
		const_hook_pointer() { }
		const_hook_pointer(const_hook_ptr p) { current=(void_ptr_ptr) p; }
		const_hook_pointer(const hook_pointer<T> & p) { current=p.current; }
		const_hook_pointer(const const_hook_pointer & p) { current=p.current; }
		~const_hook_pointer() { }
/*
	Needed for delete conversion.
*/
		operator const_hook_pointer_ptr () const
			{ return (const_hook_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (hook_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const const_hook_pointer & p) const
			{ return (current == p.current); }

		bool operator != (const const_hook_pointer & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((const_hook_pointer_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		const_hook_pointer_ref operator + () const
			{ return (const_hook_pointer_ref) current[next]; }

		const_hook_pointer_ref operator ++ ()
		{
			current=((const_hook_pointer_ref) current[next]).current;
			return *this;
		}

		const_hook_pointer operator ++ (int)
		{
			const_hook_pointer out(*this);
			current=((const_hook_pointer_ref) current[next]).current;
			return out;
		}

		const_hook_pointer_ref operator += (size_type n)
		{
			while (n)
			{
				current=((const_hook_pointer_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		const_hook_pointer operator + (size_type n) const
		{
			const_hook_pointer out(*this);
			while (n)
			{
				out.current=((const_hook_pointer_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		size_type operator - (const_hook_pointer p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((const_hook_pointer_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};

#define POINTER_SIZE 2

template<typename T>
class hook : public node<T>
{
	public:
		typedef hook_pointer<T> pointer;
		typedef typename pointer::value_type value_type;
	protected:
		typedef void* void_ptr;
	public:
		static void_ptr operator new (size_t n)
			{ return new void_ptr[POINTER_SIZE]; }
};

template<typename T>
class const_hook : public node<T>
{
	public:
		typedef const_hook_pointer<T> pointer;
		typedef typename pointer::value_type value_type;
	protected:
		typedef void* void_ptr;
	public:
		static void_ptr operator new (size_t n)
			{ return new void_ptr[POINTER_SIZE]; }
};

#undef POINTER_SIZE

