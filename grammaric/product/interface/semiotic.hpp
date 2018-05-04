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
	Although the template parameter allows for arbitrary types, product is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	8 << 3, void*

	In the context of this library, products are the disjoint union of concurrent instances of the same type.
	As this generic code is only intended for a fixed number of similar types, the basic methods for the objects
        of this class are builtin rather than being called as external static functions.
*/

template<typename Type, size_type length>
struct product
{
	using type		= product;
	using type_ptr		= type*;
	using type_ref		= type&;

	using selector		= copair<Type*>;
	using const_selector	= copair<Type*, Access::readonly>;

	using iterator		= coproduct<Type*>;
	using const_iterator	= coproduct<Type*, Access::readonly>;

	using value_type	= Type;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type value[length];

		// type:

	product() { }

	~product() { }

		// identity:

			// if they're of the same Type it is assumed they have the same length.

	bool operator == (const type_ref p) const
	{
		value_type_ptr const k = value;
		value_type_ptr const e = value + length;
		value_type_ptr const l = p.value;

		for (; k != e; ++k, ++l) if (*k != *l) return false;

		return true;
	}

	bool operator != (const type_ref p) const
	{
		value_type_ptr const k = value;
		value_type_ptr const e = value + length;
		value_type_ptr const l = p.value;

		for (; k != e; ++k, ++l) if (*k != *l) return true;

		return false;
	}

		// proximity:

			// if they're of the same Type it is assumed they have the same length.

	bool operator < (const type_ref p) const
	{
		value_type_ptr b = value;
		value_type_ptr k = value + length;
		value_type_ptr l = p.value + length;

		for (--k, --l; k != b; --k, --l) if (*k > *l) return false;

		return (*k < *p.value);
	}

	bool operator <= (const type_ref p) const
	{
		value_type_ptr b = value;
		value_type_ptr k = value + length;
		value_type_ptr l = p.value + length;

		for (--k, --l; k != b; --k, --l) if (*k > *l) return false;

		return (*k <= *p.value);
	}

	bool operator > (const type_ref p) const
	{
		value_type_ptr b = value;
		value_type_ptr k = value + length;
		value_type_ptr l = p.value + length;

		for (--k, --l; k != b; --k, --l) if (*k < *l) return false;

		return (*k > *p.value);
	}

	bool operator >= (const type_ref p) const
	{
		value_type_ptr b = value;
		value_type_ptr k = value + length;
		value_type_ptr l = p.value + length;

		for (--k, --l; k != b; --k, --l) if (*k < *l) return false;

		return (*k >= *p.value);
	}

		// shape:

		// navigator:

	selector range()
	{
		return selector(value, value + length);
	}

	const_selector range() const
	{
		return const_selector(value, value + length);
	}

	iterator begin()
	{
		return value;
	}

	const_iterator begin() const
	{
		return value;
	}

	iterator end()
	{
		return value + length;
	}

	const_iterator end() const
	{
		return value + length;
	}

		// value:
};

