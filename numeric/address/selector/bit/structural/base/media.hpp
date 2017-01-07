/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
class media
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

class const_media_pointer;

class media_pointer
{
		friend class const_media_pointer;
	public:
		typedef bool value_type;
		typedef bit::size_type size_type;
	protected:
		typedef media_pointer* media_pointer_ptr;
		typedef media_pointer& media_pointer_ref;
		typedef media<media_pointer>* media_ptr;

		typedef void* void_ptr;
		typedef size_type* size_type_ptr;

		size_type_ptr current;
		size_type location;
	public:
		media_pointer() { }
		media_pointer(media_ptr p) { current=(size_type_ptr) p; }
		media_pointer(const media_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		~media_pointer() { }
/*
	Needed for delete conversion.
*/
		operator media_pointer_ptr () const
			{ return (media_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (media_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const media_pointer & p) const
			{ return (current == p.current && location == p.location); }

		bool operator != (const media_pointer & p) const
			{ return (current != p.current || location != location); }

		static void operator delete (void_ptr p)
			{ delete ((media_pointer_ptr) p)->current; }

		const value_type operator * () const
			{ return *current & location; }

		const value_type operator & () const
			{ return *current; }

		const value_type operator ! () const
			{ return *current; }

		void operator + ()
			{ *current|=location; }

		media_pointer_ref operator ++ ()
		{
			location<<=1;
			return *this;
		}

		media_pointer operator ++ (int)
		{
			media_pointer out(*this);
			location<<=1;
			return out;
		}

		media_pointer_ref operator += (size_type n)
		{
			location<<=n;

			return *this;
		}

		media_pointer operator + (size_type n) const
		{
			media_pointer out(*this);
			out.location<<=n;

			return out;
		}

		void operator - ()
			{ return *current&=~location; }

		media_pointer_ref operator -- ()
		{
			location>>=1;
			return *this;
		}

		media_pointer operator -- (int)
		{
			media_pointer out(*this);
			location>>=1;
			return out;
		}

		media_pointer_ref operator -= (size_type n)
		{
			location>>=n;

			return *this;
		}

		media_pointer operator - (size_type n) const
		{
			media_pointer out(*this);
			out.location>>=n;

			return out;
		}

		size_type operator - (media_pointer p) const
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

class const_media_pointer
{
	public:
		typedef bool const value_type;
		typedef bit::size_type size_type;
	protected:
		typedef const_media_pointer* const_media_pointer_ptr;
		typedef const_media_pointer& const_media_pointer_ref;
		typedef media<const_media_pointer>* const_media_ptr;

		typedef void* void_ptr;
		typedef size_type* size_type_ptr;

			// an array of unknown types.
		size_type_ptr current;
		size_type location;
	public:
		const_media_pointer() { }
		const_media_pointer(const_media_ptr p) { current=(size_type_ptr) p; }
		const_media_pointer(const media_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		const_media_pointer(const const_media_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		~const_media_pointer() { }
/*
	Needed for delete conversion.
*/
		operator const_media_pointer_ptr () const
			{ return (const_media_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (media_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const const_media_pointer & p) const
			{ return (current == p.current && location == p.location); }

		bool operator != (const const_media_pointer & p) const
			{ return (current != p.current || location != p.location); }

		static void operator delete (void_ptr p)
			{ delete ((const_media_pointer_ptr) p)->current; }

		const value_type operator * () const
			{ return *current & location; }

		void operator + ()
			{ *current|=location; }

		const_media_pointer_ref operator ++ ()
		{
			location<<=1;
			return *this;
		}

		const_media_pointer operator ++ (int)
		{
			const_media_pointer out(*this);
			location<<=1;
			return out;
		}

		const_media_pointer_ref operator += (size_type n)
		{
			location<<=n;

			return *this;
		}

		const_media_pointer operator + (size_type n) const
		{
			const_media_pointer out(*this);
			out.location<<=n;

			return out;
		}

		void operator - ()
			{ *current&=~location; }

		const_media_pointer_ref operator -- ()
		{
			location>>=1;
			return *this;
		}

		const_media_pointer operator -- (int)
		{
			const_media_pointer out(*this);
			location>>=1;
			return out;
		}

		const_media_pointer_ref operator -= (size_type n)
		{
			location>>=n;

			return *this;
		}

		const_media_pointer operator - (size_type n) const
		{
			const_media_pointer out(*this);
			out.location>>=n;

			return out;
		}

		size_type operator - (const_media_pointer p) const
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

