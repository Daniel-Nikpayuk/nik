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
	Copowers recursively extend their use as pointers to interact directly with the power grammar:

	The initial case:

	copower<power<1>>
*/

template
<
	typename Type,
	size_type length,
	template<class, size_type, size_type> typename Power,

	Access access

> struct copower
<
	Power<Type, length, One::value>,
	access
>
{
	using type		= copower;
	using type_ref		= type&;
	using type_ptr		= type*;

	using const_type	= copower<Power<Type, length, One::value>, Access::readonly>;

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
	access

> : public copower
<
	Power<Type, length, N-1>,
	access
>
{
	using type			= copower;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= copower<Power<Type, length, N>, Access::readonly>;

	using value_type		= typename read_type<Power<Type, length, N-1>, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

		// sub_copowers aren't updated at this level
		// as there's no guarantee they'll even be accessed.

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

