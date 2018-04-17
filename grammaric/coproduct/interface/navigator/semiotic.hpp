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
	Navigators may be optimized as they have limited perspectives.
*/

template<typename Type, Access access = Access::readwrite>
class coproduct_navigator
{
	public:
		using type		= coproduct_navigator;

	protected:
		using type_ptr		= type*;
		using type_ref		= type&;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		using const_type	= coproduct_navigator<Type, Access::readonly>;

		value_type_ptr location;
	public:
		coproduct_navigator(value_type_ref l) : location(&l) { }

		~coproduct_navigator() { }

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref n) const
		{
			return location == n.location;
		}

		bool operator != (const type_ref n) const
		{
			return location != n.location;
		}

		value_type_ref operator * () const
		{
			return *location;
		}

		type_ref operator ++ ()
		{
			++(*location);

			return *this;
		}

		type operator ++ (int)
		{
			return coproduct_navigator((*location)++);
		}

		type_ref operator += (size_type n)
		{
			(*location) += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return (*location) + n;
		}

		type_ref operator -- ()
		{
			--(*location);

			return *this;
		}

		type operator -- (int)
		{
			return coproduct_navigator((*location)--);
		}

		type_ref operator -= (size_type n)
		{
			(*location) -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return (*location) - n;
		}
};

