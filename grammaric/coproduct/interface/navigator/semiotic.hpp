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

	Coproducts aren't mutable, they only describe the current focus of an otherwise predetermined set of alternatives.
*/

template<typename Type>
class coproduct_navigator
{
	public:
		using type		= coproduct_navigator;

	protected:
		using type_ptr		= type*;
		using type_ref		= type&;

		using value_type	= Type;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		value_type_ptr *location;
		value_type index;
	public:
		coproduct(value_type_ref v) : location(&v), index(v) { }

		~coproduct() { }

			// Interpreted by index instead of location as two locations are otherwise indicative
			// of two unrelated coproducts. Indices on the other hand relate back to the same index.

		bool operator == (const type_ref n) const
		{
			return index == n.index;
		}

		bool operator != (const type_ref n) const
		{
			return index != n.index;
		}

			// Shows you what value you're currently on.

		const value_type_ref operator * () const
		{
			return index;
		}

			// Changes the focus of the coproduct to the current index.

		void operator ! ()
		{
			*location = index;
		}

		type_ref operator ++ ()
		{
			++index;

			return *this;
		}

		type operator ++ (int)
		{
			return index++;
		}

		type_ref operator += (size_type n)
		{
			index += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return index + n;
		}

		type_ref operator -- ()
		{
			--index;

			return *this;
		}

		type operator -- (int)
		{
			return index--;
		}

		type_ref operator -= (size_type n)
		{
			index -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return index - n;
		}

		size_type operator - (const type_ref n) const
		{
			return index - n.index;
		}
};

