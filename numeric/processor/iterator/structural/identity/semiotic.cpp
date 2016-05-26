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
class semiotic
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

class semiotic_pointer
{
	public:
		typedef bool value_type;
		typedef identity::size_type size_type;
	protected:
		typedef semiotic_pointer* semiotic_pointer_ptr;
		typedef semiotic_pointer& semiotic_pointer_ref;
		typedef semiotic<semiotic_pointer>* semiotic_ptr;
		typedef void* void_ptr;

		typedef size_type* size_type_ptr;
		typedef size_type& size_type_ref;

		size_type_ptr current;
		size_type location;
	public:
		semiotic_pointer() { }
		semiotic_pointer(semiotic_ptr p) { current=(size_type_ptr) p; }
		semiotic_pointer(size_type v, size_type l)
		{
			*current=v;
			location=l;
		}
		semiotic_pointer(const semiotic_pointer & p)
		{
			current=p.current;
			location=p.location;
		}
		~semiotic_pointer() { }
/*
	Needed for delete conversion.
*/
		operator semiotic_pointer_ptr () const
			{ return (semiotic_pointer_ptr) this; }
/*
	Needed for loop condition testing "while (semiotic_pointer)".
*/
		operator bool () const
			{ return current; }

		bool operator == (const semiotic_pointer & p) const
			{ return (current == p.current && location == p.location); }

		bool operator != (const semiotic_pointer & p) const
			{ return (current != p.current || location != location); }

		static void operator delete (void_ptr p)
			{ delete ((semiotic_pointer_ptr) p)->current; }

		const value_type operator * () const
			{ return *current & location; }

		size_type_ref operator & ()
			{ return location; }

		size_type_ref operator ! ()
			{ return *current; }

		void operator + ()
			{ *current|=location; }

		semiotic_pointer_ref operator ++ ()
		{
			location<<=1;
			return *this;
		}

		semiotic_pointer operator ++ (int)
		{
			semiotic_pointer out(*this);
			location<<=1;
			return out;
		}

		semiotic_pointer_ref operator += (size_type n)
		{
			location<<=n;

			return *this;
		}

		semiotic_pointer operator + (size_type n) const
		{
			semiotic_pointer out(*this);
			out.location<<=n;

			return out;
		}

		void operator - ()
			{ return *current&=~location; }

		semiotic_pointer_ref operator -- ()
		{
			location>>=1;
			return *this;
		}

		semiotic_pointer operator -- (int)
		{
			semiotic_pointer out(*this);
			location>>=1;
			return out;
		}

		semiotic_pointer_ref operator -= (size_type n)
		{
			location>>=n;

			return *this;
		}

		semiotic_pointer operator - (size_type n) const
		{
			semiotic_pointer out(*this);
			out.location>>=n;

			return out;
		}

		size_type operator - (semiotic_pointer p) const
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

