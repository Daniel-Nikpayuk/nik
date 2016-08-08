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
template<typename T> class const_identity;

template<typename T>
class identity
{
		friend class const_identity<T>;
	public:
		typedef T value_type;
		typedef address::size_type size_type;

		enum : size_type { dimension=N };
	protected:
		typedef identity* identity_ptr;
		typedef identity& identity_ref;
		typedef base<identity>* base_ptr;

		typedef T* value_type_ptr;
		typedef T& value_type_ref;

		enum : size_type { value=0, next=1, previous=2 };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
	public:
		identity() { }
		identity(base_ptr p) { current=(void_ptr_ptr) p; }
		identity(const identity & p) { current=p.current; }
		~identity() { }

//			Needed for delete conversion.
		operator identity_ptr () const
			{ return (identity_ptr) this; }

//			Needed for loop condition testing "while (identity)".
		operator bool () const
			{ return current; }

		bool operator == (const identity & p) const
			{ return (current == p.current); }

		bool operator != (const identity & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((identity_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		identity_ref operator + () const
			{ return (identity_ref) current[next]; }

		identity_ref operator ++ ()
		{
			current=((identity_ref) current[next]).current;
			return *this;
		}

		identity operator ++ (int)
		{
			identity out(*this);
			current=((identity_ref) current[next]).current;
			return out;
		}

		identity_ref operator += (size_type n)
		{
			while (n)
			{
				current=((identity_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		identity operator + (size_type n) const
		{
			identity out(*this);
			while (n)
			{
				out.current=((identity_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		identity_ref operator - () const
			{ return (identity_ref) current[previous]; }

		identity_ref operator -- ()
		{
			current=((identity_ref) current[previous]).current;
			return *this;
		}

		identity operator -- (int)
		{
			identity out(*this);
			current=((identity_ref) current[previous]).current;
			return out;
		}

		identity_ref operator -= (size_type n)
		{
			while (n)
			{
				current=((identity_ref) current[previous]).current;
				--n;
			}

			return *this;
		}

		identity operator - (size_type n) const
		{
			identity out(*this);
			while (n)
			{
				out.current=((identity_ref) out.current[previous]).current;
				--n;
			}

			return out;
		}

		size_type operator - (identity p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((identity_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};

//	const version:

template<typename T, size_type N>
class const_identity
{
	public:
		typedef T const value_type;
		typedef node::size_type size_type;

		enum : size_type { dimension=N };
	protected:
		typedef const_identity* const_identity_ptr;
		typedef const_identity& const_identity_ref;
		typedef base<const_identity>* const_base_ptr;

		typedef T const * value_type_ptr;
		typedef T const & value_type_ref;

		enum : size_type { value=0, next=1, previous=2 };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
	public:
		const_identity() { }
		const_identity(const_base_ptr p) { current=(void_ptr_ptr) p; }
		const_identity(const identity<T, N> & p) { current=p.current; }
		const_identity(const const_identity & p) { current=p.current; }
		~const_identity() { }

//			Needed for delete conversion.
		operator const_identity_ptr () const
			{ return (const_identity_ptr) this; }

//			Needed for loop condition testing "while (identity)".
		operator bool () const
			{ return current; }

		bool operator == (const const_identity & p) const
			{ return (current == p.current); }

		bool operator != (const const_identity & p) const
			{ return (current != p.current); }

		static void operator delete (void_ptr p)
			{ delete [] ((const_identity_ptr) p)->current; }

		value_type_ref operator * () const
			{ return (value_type_ref) current[value]; }

		value_type_ptr operator -> () const
			{ return & (value_type_ref) current[value]; }

		const_identity_ref operator + () const
			{ return (const_identity_ref) current[next]; }

		const_identity_ref operator ++ ()
		{
			current=((const_identity_ref) current[next]).current;
			return *this;
		}

		const_identity operator ++ (int)
		{
			const_identity out(*this);
			current=((const_identity_ref) current[next]).current;
			return out;
		}

		const_identity_ref operator += (size_type n)
		{
			while (n)
			{
				current=((const_identity_ref) current[next]).current;
				--n;
			}

			return *this;
		}

		const_identity operator + (size_type n) const
		{
			const_identity out(*this);
			while (n)
			{
				out.current=((const_identity_ref) out.current[next]).current;
				--n;
			}

			return out;
		}

		const_identity_ref operator - () const
			{ return (const_identity_ref) current[previous]; }

		const_identity_ref operator -- ()
		{
			current=((const_identity_ref) current[previous]).current;
			return *this;
		}

		const_identity operator -- (int)
		{
			const_identity out(*this);
			current=((const_identity_ref) current[previous]).current;
			return out;
		}

		const_identity_ref operator -= (size_type n)
		{
			while (n)
			{
				current=((const_identity_ref) current[previous]).current;
				--n;
			}

			return *this;
		}

		const_identity operator - (size_type n) const
		{
			const_identity out(*this);
			while (n)
			{
				out.current=((const_identity_ref) out.current[previous]).current;
				--n;
			}

			return out;
		}

		size_type operator - (const_identity p) const
		{
			size_type n=0;
			while (p.current != current)
			{
				p.current=((const_identity_ref) p.current[next]).current;
				++n;
			}

			return n;
		}
};
*/

