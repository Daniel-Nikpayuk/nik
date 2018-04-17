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
	Coproduct assumes overloaded arithmetic operators as navigational operators of Type.
*/

template<typename Type, Access access = Access::readwrite>
class coproduct
{
	public:
		using type		= coproduct;

	protected:
		using type_ptr		= type*;
		using type_ref		= type&;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		using const_type	= coproduct<Type, Access::readonly>;

		value_type value;
	public:
		coproduct(const value_type_ref v) : value(v) { }

		~coproduct() { }

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref c) const
		{
			return value == c.value;
		}

		bool operator != (const type_ref c) const
		{
			return value != c.value;
		}

		type_ref operator ++ ()
		{
			++value;

			return *this;
		}

		type operator ++ (int)
		{
			return value++;
		}

		type_ref operator += (size_type n)
		{
			value += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return value + n;
		}

		type_ref operator -- ()
		{
			--value;

			return *this;
		}

		type operator -- (int)
		{
			return value--;
		}

		type_ref operator -= (size_type n)
		{
			value -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return value - n;
		}
};

