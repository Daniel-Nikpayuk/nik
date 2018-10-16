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
	Cobit as a specification holds the copower used to construct the bit structure.

	This would be redundant except the additional specification information
	offered by a bit means we can optimize the navigational interface here.
*/

template
<
	typename BitType,
	Access access = Access::readwrite

> struct cobit;

/*
*/

template
<
	typename RegType,

	Access access

> struct cobit
<
	bit<RegType>,
	access
>
{
	using type			= cobit;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= cobit<bit<RegType>, Access::readonly>;

	using value_type		= typename read_type<RegType, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using bit_iterator		= typename bit<RegType>::iterator;
	using const_bit_iterator	= typename bit<RegType>::const_iterator;

	bit_iterator focus;

		// type:

	cobit() { }

	cobit(value_type & b) : focus(b) { }

	~cobit() { }

	bool operator == (const type & n) const
	{
		return focus == n.focus;
	}

	bool operator != (const type & n) const
	{
		return focus != n.focus;
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

	void operator + ()
	{
		*focus = One::value;
	}

	void operator - ()
	{
		*focus = Zero::value;
	}
};

/*
	Cobit as a specification holds the copower used to construct the bit structure.

	This would be redundant except the additional specification information
	offered by a bit means we can optimize the navigational interface here.
*/

template
<
	typename RegType,
	template<class> typename Bit,

	Access access

> struct cobit
<
	Bit<bool>,
	access
>
{
	using type			= cobit;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= cobit<Bit<bool>, Access::readonly>;

	using value_type		= typename read_type<bool, access>::rtn;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	value_type_ref focus;

		// type:

	cobit() { }

	cobit(value_type & b) : focus(b) { }

	~cobit() { }

	bool operator == (const type & n) const
	{
		return focus == n.focus;
	}

	bool operator != (const type & n) const
	{
		return focus != n.focus;
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

	void operator + ()
	{
		focus = true;
	}

	void operator - ()
	{
		focus = false;
	}
};

