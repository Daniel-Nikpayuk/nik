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

template<typename Type, size_type length>
struct product
{
	using type		= product;
	using type_ptr		= type*;
	using type_ref		= type&;

	using value_type	= Type;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	using iterator		= product_iterator<Type>;
	using const_iterator	= product_iterator<Type, Access::readonly>;

	using selector		= product_selector<Type>;
	using const_selector	= product_selector<Type, Access::readonly>;

	value_type value[length];

	product() { }

	~product() { }

	iterator begin() const
	{
		return iterator(value);
	}

	iterator end() const
	{
		return iterator(value + length);
	}

	selector range() const
	{
		return selector(value, value + length);
	}
};

