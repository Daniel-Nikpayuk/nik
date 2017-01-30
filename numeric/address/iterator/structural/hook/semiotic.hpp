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
	Intuition:

	A standard pointer is a variable to an address. A node is a bundling of addresses, and a pointer
	to such a bundling is thus a variable to a bundling of addresses. So when you dereference for example,
	you don't dereference the bundling of addresses as an object, you deference the value. The plus (+)
	as well as minus (-) unary operators become ways to dereference the alternate addresses. The difference
	being that if you conceptualize this space memory addresses as an object, it means all the regular
	grammar and interpretations of C++ all of a sudden apply: If it's an object, then you should be able to
	dereference the pointer as an object as well as act on the object itself. You'd also then need to make
	the additional function call of dereferencing the value from the object. The idea of the pointer is to
	access the memory directly, with no inbetween object.

	This intuitive conceptualization is the guiding design for any additional future considerations.
	For example, one might wish to create specialized convenience constructors for a node, but from the above
	interpretation, a node is not an object, it is NOT meant to be perceived to have constructors, only allocators.

	-----------

	This class is meant to be as narratively similar as possible to the builtin array pointer.
	I have privileged this above all other considerations in the design. Let me reiterate:
	The design privileges effective grammar expressivity as similar as possible to the builtin array pointer.

	As this is an exceptionally low-level class upon which many other classes are meant to be built, it is safe
	to say it has not been thorough tested in production. As such, I cannot guarantee it has been as optimized
	as it can be (premature optimization is the root of all evil).

	It is intuitive that node_pointers should be able to convert to const_node_pointers, the design follows this intuition.

	In terms of dynamic binding, const_node_pointers can semantically be considered a node_pointer subclass,
	and is nearly implemented as such. As it stands, I have decided to prevent this use of polymorphism.
	This policy will hold unless I find sufficient reason to change it. Furthermore, in a previous iteration in which
	it was allowed, I have learned intermixing polymorphism and void* seems to cause general issues. Though I don't
	fully understand why, I resolved a bug by removing the virtual declarations of the (*) and (+) operator overloads.
	The bug arose when they combined (*+).

	It takes a policy of soft or shallow copying, and does not delete or destroy by default.

	void* casting is subtle, as the same memory cast to two different types works, but referencing within such memory
	changes on the interpretation of the type of that memory.

	By defining the node before the node_pointer, we can call "new node" outside of the pointer's scope,
	the tradeoff is the extended namespace calling in order to do so (nik::context::context:: ...).
	One would need to typedef. I have included a typedef of the pointer within its node.
*/

/*
	Is not meant to be interpeted as a "class" or an "object" even if it is implemented that way.
	It is only meant to have an allocator as well as meta information about the type of memory it holds.
*/

template<typename T> class hook;
template<typename T> class const_hook_pointer;

template<typename T>
class hook_pointer
{
		friend class const_hook_pointer<T>;
	public:
		typedef T value_type;

	protected:
		typedef hook_pointer* hook_pointer_ptr;
		typedef hook_pointer& hook_pointer_ref;
		typedef hook<T>* hook_ptr;

		typedef value_type* value_type_ptr;
		typedef value_type& value_type_ref;

		enum : size_type { value=0, next };

		typedef void* void_ptr;
		typedef void_ptr* void_ptr_ptr;

			// an array of unknown types.
		void_ptr_ptr current;
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
class hook
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
class const_hook
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

