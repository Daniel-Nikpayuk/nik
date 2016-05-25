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
class identity
{
	public:
		typedef Pointer pointer;
		typedef typename pointer::value_type value_type;
		typedef typename pointer::size_type size_type;
	protected:
		typedef void* void_ptr;
	public:
		static void_ptr operator new (size_t n)
			{ return new size_type; }
};

class const_identity_pointer;

class identity_pointer
{
		friend class const_identity_pointer;
	public:
		typedef bool value_type;
		typedef bit::size_type size_type;
	protected:
		typedef identity_pointer* identity_pointer_ptr;
		typedef identity_pointer& identity_pointer_ref;
		typedef identity<identity_pointer>* identity_ptr;
		typedef void* void_ptr;

		typedef size_type* size_type_ptr;
		typedef size_type& size_type_ref;

		size_type_ptr current;
		size_type location;
	public:
		identity_pointer() { }
		identity_pointer(identity_ptr p) { current=(size_type_ptr) p; }
		identity_pointer(const identity_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		~identity_pointer() { }
/*
	Needed for delete conversion.
*/
		operator identity_pointer_ptr () const
			{ return (identity_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (identity_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const identity_pointer & p) const
			{ return (current == p.current && location == p.location); }

		bool operator != (const identity_pointer & p) const
			{ return (current != p.current || location != location); }

		static void operator delete (void_ptr p)
			{ delete ((identity_pointer_ptr) p)->current; }

		const value_type operator * () const
			{ return *current & location; }

		size_type_ref operator & ()
			{ return location; }

		size_type_ref operator ! ()
			{ return *current; }

		void operator + ()
			{ *current|=location; }

		identity_pointer_ref operator ++ ()
		{
			location<<=1;
			return *this;
		}

		identity_pointer operator ++ (int)
		{
			identity_pointer out(*this);
			location<<=1;
			return out;
		}

		identity_pointer_ref operator += (size_type n)
		{
			location<<=n;

			return *this;
		}

		identity_pointer operator + (size_type n) const
		{
			identity_pointer out(*this);
			out.location<<=n;

			return out;
		}

		void operator - ()
			{ return *current&=~location; }

		identity_pointer_ref operator -- ()
		{
			location>>=1;
			return *this;
		}

		identity_pointer operator -- (int)
		{
			identity_pointer out(*this);
			location>>=1;
			return out;
		}

		identity_pointer_ref operator -= (size_type n)
		{
			location>>=n;

			return *this;
		}

		identity_pointer operator - (size_type n) const
		{
			identity_pointer out(*this);
			out.location>>=n;

			return out;
		}

		size_type operator - (identity_pointer p) const
		{
			size_type n=0;
			while (p.location != location)
			{
				p.location<<=1;
				++n;
			}

			return n;
		}
};

/*
	const version:
*/

class const_identity_pointer
{
	public:
		typedef bool const value_type;
		typedef bit::size_type size_type;
	protected:
		typedef const_identity_pointer* const_identity_pointer_ptr;
		typedef const_identity_pointer& const_identity_pointer_ref;
		typedef identity<const_identity_pointer>* const_identity_ptr;
		typedef void* void_ptr;

		typedef size_type* size_type_ptr;
		typedef size_type& size_type_ref;

			// an array of unknown types.
		size_type_ptr current;
		size_type location;
	public:
		const_identity_pointer() { }
		const_identity_pointer(const_identity_ptr p) { current=(size_type_ptr) p; }
		const_identity_pointer(const identity_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		const_identity_pointer(const const_identity_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		~const_identity_pointer() { }
/*
	Needed for delete conversion.
*/
		operator const_identity_pointer_ptr () const
			{ return (const_identity_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (identity_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const const_identity_pointer & p) const
			{ return (current == p.current && location == p.location); }

		bool operator != (const const_identity_pointer & p) const
			{ return (current != p.current || location != p.location); }

		static void operator delete (void_ptr p)
			{ delete ((const_identity_pointer_ptr) p)->current; }

		const value_type operator * () const
			{ return *current & location; }

		size_type_ref operator & ()
			{ return location; }

		const size_type operator ! () const
			{ return *current; }

		void operator + ()
			{ *current|=location; }

		const_identity_pointer_ref operator ++ ()
		{
			location<<=1;
			return *this;
		}

		const_identity_pointer operator ++ (int)
		{
			const_identity_pointer out(*this);
			location<<=1;
			return out;
		}

		const_identity_pointer_ref operator += (size_type n)
		{
			location<<=n;

			return *this;
		}

		const_identity_pointer operator + (size_type n) const
		{
			const_identity_pointer out(*this);
			out.location<<=n;

			return out;
		}

		void operator - ()
			{ *current&=~location; }

		const_identity_pointer_ref operator -- ()
		{
			location>>=1;
			return *this;
		}

		const_identity_pointer operator -- (int)
		{
			const_identity_pointer out(*this);
			location>>=1;
			return out;
		}

		const_identity_pointer_ref operator -= (size_type n)
		{
			location>>=n;

			return *this;
		}

		const_identity_pointer operator - (size_type n) const
		{
			const_identity_pointer out(*this);
			out.location>>=n;

			return out;
		}

		size_type operator - (const_identity_pointer p) const
		{
			size_type n=0;
			while (p.location != location)
			{
				p.location<<=1;
				++n;
			}

			return n;
		}
};

