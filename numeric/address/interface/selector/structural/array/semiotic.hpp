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
	Is not meant to be interpeted as a "class" or an "object" even if it is implemented that way.
	It is only meant to have an allocator as well as meta information about the type of memory it holds.
*/

template<typename Pointer>
class array
{
	public:
		typedef Pointer pointer;
		typedef typename pointer::value_type value_type;
	protected:
		typedef void* void_ptr;
	public:
		operator pointer () const
			{ return (pointer) this; }

		static void_ptr operator new (size_t n)
			{ return new value_type; }
};

template<typename ValueType>
class array<ValueType*>
{
	public:
		typedef ValueType* pointer;
		typedef ValueType value_type;
	protected:
		typedef void* void_ptr;
	public:
		operator pointer () const
			{ return (pointer) this; }

		static void_ptr operator new (size_t n)
			{ return new value_type; }
};

template<typename T> class const_array_pointer;

template<typename T>
class array_pointer
{
		friend class const_array_pointer<T, N>;
	public:
		typedef T value_type;
	protected:
		typedef array_pointer* array_pointer_ptr;
		typedef array_pointer& array_pointer_ref;
		typedef array<array_pointer>* array_ptr;

		typedef value_type* value_type_ptr;
		typedef value_type& value_type_ref;

			// an array of unknown types.
		value_type_ptr initial;
		value_type_ptr terminal;
	public:
		array_pointer() { }
		array_pointer(value_type_ptr i, value_type_ptr t)
		{
			initial=i;
			terminal=t;
		}
		array_pointer(const array_pointer & p)
		{
			initial=p.initial;
			terminal=p.terminal;
		}
		~array_pointer() { }
/*
	Needed for delete conversion.
*/
		operator array_pointer_ptr () const
			{ return (array_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (array_pointer)".
*/
		operator bool () const
			{ return initial != terminal; }

		bool operator == (const array_pointer & p) const
			{ return (initial == p.initial && terminal == p.terminal); }

		bool operator != (const array_pointer & p) const
			{ return (initial != p.initial || terminal != p.terminal); }

		static void operator delete (void_ptr p)
		{
			delete [] ((array_pointer_ptr) p)->initial;
			delete [] ((array_pointer_ptr) p)->terminal;
		}

		value_type_ref operator * () const
			{ return *initial; }

		value_type_ref operator ~ () const
			{ return *terminal; }

		array_iterator_ref operator + () const
			{ return terminal; }

		array_pointer_ref operator ++ ()
		{
			++initial;
			return *this;
		}

		array_pointer operator ++ (int)
		{
			++terminal;
			return *this;
		}

		array_pointer_ref operator += (size_type n)
		{
			initial+=n;
			terminal+=n;

			return *this;
		}

		array_pointer operator + (size_type n) const
			{ return array_pointer out(initial+n, terminal+n); }

		array_iterator_ref operator - () const
			{ return initial; }

		array_pointer_ref operator -- ()
		{
			--initial;
			return *this;
		}

		array_pointer operator -- (int)
		{
			--terminal;
			return *this;
		}

		array_pointer_ref operator -= (size_type n)
		{
			initial-=n;
			terminal-=n;

			return *this;
		}

		array_pointer operator - (size_type n) const
			{ return array_pointer out(initial-n, terminal-n); }
};

/*
	const version:
*/

template<typename T>
class const_array_pointer
{
	public:
		typedef T const value_type;
	protected:
		typedef const_array_pointer* const_array_pointer_ptr;
		typedef const_array_pointer& const_array_pointer_ref;
		typedef array<const_array_pointer>* const_array_ptr;

		typedef value_type* value_type_ptr;
		typedef value_type& value_type_ref;

			// an array of unknown types.
		value_type_ptr initial;
		value_type_ptr terminal;
	public:
		const_array_pointer() { }
		const_array_pointer(const value_type_ptr i, const value_type_ptr t)
		{
			initial=i;
			terminal=t;
		}
		const_array_pointer(const array_pointer<T> & p)
		{
			initial=p.initial;
			terminal=p.terminal;
		}
		const_array_pointer(const const_array_pointer & p)
		{
			initial=p.initial;
			terminal=p.terminal;
		}
		~const_array_pointer() { }
/*
	Needed for delete conversion.
*/
		operator const_array_pointer_ptr () const
			{ return (const_array_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (array_pointer)".
*/
		operator bool () const
			{ return initial != terminal; }

		bool operator == (const const_array_pointer & p) const
			{ return (initial == p.initial && terminal == p.terminal); }

		bool operator != (const const_array_pointer & p) const
			{ return (initial != p.initial || terminal != p.terminal); }

		static void operator delete (void_ptr p)
		{
			delete [] ((const_array_pointer_ptr) p)->initial;
			delete [] ((const_array_pointer_ptr) p)->terminal;
		}

		value_type_ref operator * () const
			{ return *initial; }

		value_type_ref operator ~ () const
			{ return *terminal; }

		const_array_iterator_ref operator + () const
			{ return terminal; }

		const_array_pointer_ref operator ++ ()
		{
			++initial;
			return *this;
		}

		const_array_pointer operator ++ (int)
		{
			++terminal;
			return *this;
		}

		const_array_pointer_ref operator += (size_type n)
		{
			initial+=n;
			terminal+=n;

			return *this;
		}

		const_array_pointer operator + (size_type n) const
			{ return const_array_pointer(initial+n, terminal+n); }

		const_array_iterator_ref operator - () const
			{ return initial; }

		const_array_pointer_ref operator -- ()
		{
			--initial;
			return *this;
		}

		const_array_pointer operator -- (int)
		{
			--terminal;
			return *this;
		}

		const_array_pointer_ref operator -= (size_type n)
		{
			initial-=n;
			terminal-=n;

			return *this;
		}

		const_array_pointer operator - (size_type n) const
			{ return const_array_pointer(initial-n, terminal-n); }
};

