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
class product_selector
{
	public:
		using type		= product_selector;

	protected:
		using type_ptr		= type*;
		using type_ref		= type&;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		using const_type	= product_selector<Type, Access::readonly>;

		using iterator		= product_iterator<Type, access>;
		using iterator_ptr	= iterator*;
		using iterator_ref	= iterator&;

		iterator initial;
		iterator terminal;
	public:
		product_selector(value_type_ptr i, value_type_ptr t) : initial(i), terminal(t) { }

		~product_selector() { }

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref s) const
		{
			return initial == s.initial && terminal == s.terminal;
		}

		bool operator != (const type_ref s) const
		{
			return initial != s.initial || terminal != s.terminal;
		}

		iterator_ref operator - () const
		{
			return initial;
		}

		iterator_ref operator + () const
		{
			return terminal;
		}

		type_ref operator ++ ()
		{
			++initial;
			++terminal;

			return *this;
		}

		type operator ++ (int)
		{
			return product_selector(initial++, terminal++);
		}

		type_ref operator += (size_type n)
		{
			initial += n;
			terminal += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return product_selector(initial + n, terminal + n);
		}

		type_ref operator -- ()
		{
			--initial;
			--terminal;

			return *this;
		}

		type operator -- (int)
		{
			return product_selector(initial--, terminal--);
		}

		type_ref operator -= (size_type n)
		{
			initial -= n;
			terminal -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return product_selector(initial - n, terminal - n);
		}
};

