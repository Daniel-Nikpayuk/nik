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
	In the context of this library, copowers are the disjoint union of alternative instances of the same type.
	At the grammaric level, register types and pointers are intended to be indistinguishable.
	Copowers are a grammatical class which represents both.

	When building more complex navigators out of simpler ones,
	the only reasons to reimplement copowers are as follows:

	1. Optimizing the method interface.
	2. Optimization by unraveling. This is necessary if the context
	   requires frequently moving between levels of navigational complexity.
*/

enum struct Orientation : size_type
{
	identity,
	nested,
	multi,

	dimension // filler
};

/*
	copower<Type>	~:= Type

	Within this initial specialization, Type is arbitrary but intended for builtin register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	It is optimized as such.
*/

template
<
	typename Type,
	Orientation orientation = Orientation::identity,
	Access access = Access::readwrite

> struct copower
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<Type, orientation, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type focus;

		// type:

	copower() { }

	copower(value_type f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

/*
	Beyond register sizes, copowers are intended to be used as an alternative to pointers:

	copower<Type>		~:= Type*

	We optimize in our ability to dereference more directly.
*/

template
<
	typename Type,
	Orientation orientation,
	Access access

> struct copower
<
	Type*,
	orientation,
	access
>
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<Type*, orientation, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type_ptr focus;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

/*
	Nested_copowers are intended to be multi-dimensional copowers for use with powers.
	Effectively, you can think of them as powers of copowers.

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
	size_type length,
	template<class, size_type, size_type> typename Power,

	Orientation orientation,
	Access access

> struct copower
<
	Power<Type, length, One::value>,
	orientation,
	access
>
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<Power<Type, length, One::value>, orientation, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ref	= value_type&;
	using value_type_ptr	= value_type*;

	value_type_ptr focus;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

/*
	The recursive case:

	power<N>				~= power<N-1>[length]
	power<N>::iterator			~= copower<power<N-1>>

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

> struct copower
<
	Power<Type, length, N>,
	Orientation::identity,
	access

> : public copower
<
	Power<Type, length, N-1>,
	Orientation::identity,
	access
>
{
	using type			= copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= copower<Power<Type, length, N>, Orientation::identity, Access::readonly>;

	using value_type		= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	value_type_ptr focus;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

/*
	The recursive case:

	power<N>				~= power<N-1>[length]
	power<N>::multi_iterator		~= copower<power<N-1>>

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

> struct copower
<
	Power<Type, length, N>,
	Orientation::nested,
	access

> : public copower
<
	Power<Type, length, N-1>,
	Orientation::nested,
	access
>
{
	using type			= copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= copower<Power<Type, length, N>, Orientation::nested, Access::readonly>;

	using value_type		= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using sub_type			= copower<value_type, Orientation::nested, access>;
	using sub_type_ref		= sub_type&;
	using sub_type_ptr		= sub_type*;

	value_type_ptr focus;

		// sub_copowers aren't updated at this level as there's
		// no guarantee they'll even be accessed in a given cycle.

	sub_type location;

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

/*
	The recursive case:

	power<N>				~= power<N-1>[length]
	power<N>::multi_iterator		~= copower<power<N-1>>

	copower<power<N>>			~= *power<N>[length]

	In this case, we both recursively contain and inherit copowers from their predecessors.
	This allows us to implement multi_copowers using dynamic polymorphism.
*/

template
<
	typename Type,
	size_type length,
	size_type N,
	template<class, size_type, size_type> typename Power,

	Access access

> struct copower
<
	Power<Type, length, N>,
	Orientation::multi,
	access

> : public copower
<
	Power<Type, length, N-1>,
	Orientation::multi,
	access
>
{
	using type			= copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= copower<Power<Type, length, N>, Orientation::multi, Access::readonly>;

	using value_type		= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using sub_type			= copower<value_type, Orientation::multi, access>;
	using sub_type_ref		= sub_type&;
	using sub_type_ptr		= sub_type*;

	value_type_ptr focus;

		// sub_copowers aren't updated at this level as there's
		// no guarantee they'll even be accessed in a given cycle.

	sub_type location[length];

		// type:

	copower() { }

	copower(value_type_ptr f) : focus(f) { }

	copower(const type_ref c) : focus(c.focus) { }

	~copower() { }

	bool operator == (const type_ref c) const
	{
		return focus == c.focus;
	}

	bool operator != (const type_ref c) const
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

	value_type_ref operator * () const
	{
		return *focus;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++focus;

		return *this;
	}

	type operator ++ (int)
	{
		return focus++;
	}

	type_ref operator += (size_type n)
	{
		focus += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return focus + n;
	}

	type_ref operator -- ()
	{
		--focus;

		return *this;
	}

	type operator -- (int)
	{
		return focus--;
	}

	type_ref operator -= (size_type n)
	{
		focus -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return focus - n;
	}

	size_type operator - (const type_ref c) const
	{
		return focus - c.focus;
	}
};

