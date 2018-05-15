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
	copower<Type>	~:= Type

	Within this initial specialization, Type is arbitrary but intended for builtin register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	It is optimized as such.
*/

template<typename Type, Access access = Access::readwrite>
struct copower
{
	using type		= copower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= copower<Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

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

	copower<Type*>		~:= Type*

	We optimize in our ability to dereference more directly.
*/

template<typename Type, Access access>
struct copower<Type*, access>
{
	using type		= copower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= copower<Type*, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

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
	Copowers are also intended to be used as iterators to nested powers:

	nested_power<N+1, Type, length>			:= nested_power<N, Type, length>[length]
	nested_power<N+1, Type, length>::iterator	:= copower<nested_power<N, Type, length>*>

	copower<nested_power<N, Type, length>*>		inherits copower<nested_power<N-1, Type, length>*>

	In the general case, we recursively inherit from its predecessor. This allows us to implement
	multi_copowers using dynamic polymorphism. The initial case:

		copower<nested_power<0, Type, length>*>

	is covered by the more general match:

		copower<Type*>
*/

template
<
	size_type N,
	typename Type,
	size_type length,
	template<size_type, class, size_type> typename NestedPower,

	Access access
>
struct copower
<
	NestedPower<N, Type, length>*,
	access

> : public copower
<
	NestedPower<N-1, Type, length>*,
	access
>
{
	using type		= copower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= copower<NestedPower<N, Type, length>*, Access::readonly>;

	using value_type	= typename read_type<NestedPower<N, Type, length>, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

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

