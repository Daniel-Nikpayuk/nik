/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	To minimize memory use, we would implement dynamic polymorhism: Internally, a single base pointer would be sufficient.
	Unfortunately, this approach requires allocating and deallocating memory, which is a strategy we're trying to avoid.

	The next best alternative if such strict memory constraints aren't required is to create fixed memory locations
	for reuse. Conceptually for each copower, we need heap allocated fixed memory for a parent copower and a child
	copower. As for the recursive definition, it contains enough information to dereference a power and that can
	be used to create a sub_copower temporary, for which we can then raise its status to persistent by passing
	it to the heap allocated fixed child copower. The question becomes: Where do we locate this memory?

	I have chosen to embed child memory directly into a recursive definition. As for parent memory, this can
	be achieved through an external array of polymorphic copower pointers, the previous location in the array
	being the parent. It uses only a constant difference of memory than embedding parents into the recursive
	definition.
*/

template
<
	typename Type,
	Access access = Access::readwrite

> struct linked_copower;

/*
*/

template
<
	typename Type,
	size_type length,
	template<class, size_type, size_type> typename Power,

	Access access

> struct linked_copower
<
	Power<Type, length, One::value>,
	access
>
{
	using type			= linked_copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= linked_copower<Power<Type, length, One::value>, Access::readonly>;

	using value_type		= typename read_type<Type, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	value_type_ptr focus;

		// type:

	linked_copower() { }

	linked_copower(value_type_ptr f) : focus(f) { }

	linked_copower(const type & c) : focus(c.focus) { }

	~linked_copower() { }

	bool operator == (const type & c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type & c) const
	{
		return focus != c.focus;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	virtual value_type_ref operator * () const
	{
		return *focus;
	}

		// meta:

	virtual type_ptr operator + ()
	{
		return this;
	}

		// navigator:

	virtual type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	virtual type operator ++ (int)
	{
		return focus++;
	}

	virtual type_ref operator += (size_type n)
	{
		focus += n;

		nik::display << "who?" << nik::endl;

		return *this;
	}

	virtual type operator + (size_type n) const
	{
		return focus + n;
	}

	virtual type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	virtual type operator -- (int)
	{
		return focus--;
	}

	virtual type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	virtual type operator - (size_type n) const
	{
		return focus - n;
	}

	virtual size_type operator - (const type & c) const
	{
		return focus - c.focus;
	}
};

/*
	The recursive case:

	power<N>				~= power<N-1>[length]
	power<N>::mobile_iterator		~= copower<power<N-1>>

	copower<power<N>>			~= *power<N>[length]

	In this case, we both recursively contain and inherit copowers from their predecessors.
	This allows us to implement copowers using dynamic polymorphism.
*/

template
<
	typename Type,
	size_type length,
	size_type N,
	template<class, size_type, size_type> typename Power,

	Access access

> struct linked_copower
<
	Power<Type, length, N>,
	access

> : public linked_copower
<
	Power<Type, length, N-1>,
	access
>
{
	using type			= linked_copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= linked_copower<Power<Type, length, N>, Access::readonly>;

	using value_type		= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using sub_type			= linked_copower<Power<Type, length, N-1>, access>;
	using sub_type_ref		= sub_type&;
	using sub_type_ptr		= sub_type*;

	using base_type			= linked_copower<Power<Type, length, One::value>, access>;
	using base_type_ref		= base_type&;
	using base_type_ptr		= base_type*;

	value_type_ptr focus;

	sub_type location;

		// type:

	linked_copower() { }

	linked_copower(value_type_ptr f) : focus(f) { }

	linked_copower(const type & c) : focus(c.focus) { }

	~linked_copower() { }

	bool operator == (const type & c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type & c) const
	{
		return focus != c.focus;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	virtual value_type_ref operator * () const
	{
		return *focus;
	}

		// meta:

	virtual base_type_ptr operator + ()
	{
		location = sub_type(focus->value);

		return &location;
	}

		// navigator:

	virtual type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	virtual type operator ++ (int)
	{
		return focus++;
	}

	virtual type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	virtual type operator + (size_type n) const
	{
		return focus + n;
	}

	virtual type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	virtual type operator -- (int)
	{
		return focus--;
	}

	virtual type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	virtual type operator - (size_type n) const
	{
		return focus - n;
	}

	virtual size_type operator - (const type & c) const
	{
		return focus - c.focus;
	}
};

/*
	The key thing to note in their implementation is that products recursively interleave their constructions with
	their iterators: Each iterator must build its own relationship with the product independently of each other.
	With that said, each iterator is otherwise built the same way, only that it diverges in keeping some
	additional information for itself.

	Copowers recursively extend their use as pointers to interact directly with the power grammar:

	The initial case:

	copower<power<1>>
*/

template
<
	typename Type,
	Access access = Access::readwrite

> struct mobile_copower;

/*
	Implementation decisions:

	We need a path of parents as a data structure. A simple array is the first structure which comes to mind,
	but each parent has a distinct type, this array needs to be one of pointers of the base type to allow
	for dynamic polymorphism. Finally, we need not worry about dynamically allocating memory using "new"
	as the top level is assumed to exist in a persistent way (it is passed to the constructor)
	so we can pass its address to be the first parent when we move down the array to its children.

	Implementation lacks modularity:

	Is optimized to work directly with powers,
	which is to say it references the internals of the mobile power specification.
*/

template
<
	typename Type,
	size_type length,
	size_type N,
	template<class, size_type, size_type> typename Power,

	Access access

> struct mobile_copower
<
	Power<Type, length, N>,
	access
>
{
	using type				= mobile_copower;
	using type_ref				= type&;
	using type_ptr				= type*;

	using const_type			= mobile_copower<Power<Type, length, N>, Access::readonly>;

	using value_type			= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref			= value_type&;
	using value_type_ptr			= value_type*;

	using copower_type			= linked_copower<Power<Type, length, N>, access>;
	using copower_type_ref			= copower_type&;
	using copower_type_ptr			= copower_type*;

		// base is required for dynamic polymorphism.

	using copower_base			= linked_copower<Power<Type, length, One::value>, access>;
	using copower_base_ref			= copower_base&;
	using copower_base_ptr			= copower_base*;

		// defined as an array of pointers of the initial (N = 0) recursive copower,
		// as this allows for dynamic polymorphism.

	copower_type focus;

	copower_base_ptr path[N];
	copower_base_ptr *location;

		// type:

	mobile_copower() { }

		// initialize location to the initial position in the array.
		// this aligns with the use of operators +,-  ().

	mobile_copower(value_type_ptr p) : focus(p), location(path)
	{
		*location = &focus;
	}

		// Destructor: Does nothing. Iterators can (de)allocate,
		// but otherwise default to passive interaction.

	~mobile_copower() { }

		// identity comparisons are applied to copowers,
		// and otherwise stay within the local level of complexity.

	bool operator == (const type & c) const
	{
		return **location == **c.location;
	}

	bool operator != (const type & c) const
	{
		return **location != **c.location;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

		// Here mobile_copowers return copower pointers instead of dereferences.
		// This is valuable as different copower specializations return different types.

	Type & operator * () const
	{
		return ***location;
	}

		// meta:

	void operator + ()
	{
		*(location+1) = (*location)->operator+();

		nik::display << "next!" << nik::endl;

		++location;
	}

	void operator - ()
	{
		--location;
	}

		// navigator:

	type_ref operator ++ ()
	{
		(*location)->operator++();

		return *this;
	}

	type operator ++ (int int_value)
	{
		return (*location)->operator++(int_value);
	}

	type_ref operator += (size_type n)
	{
		(*location)->operator+=(n);

		return *this;
	}

	type operator + (size_type n) const
	{
		return (*location)->operator+(n);
	}

	type_ref operator -- ()
	{
		(*location)->operator--();

		return *this;
	}

	type operator -- (int int_value)
	{
		return (*location)->operator--(int_value);
	}

	type_ref operator -= (size_type n)
	{
		(*location)->operator-=(n);

		return *this;
	}

	type operator - (size_type n) const
	{
		return (*location)->operator-(n);
	}

	size_type operator - (const type & c) const
	{
		return *location - *c.location;
	}
};

