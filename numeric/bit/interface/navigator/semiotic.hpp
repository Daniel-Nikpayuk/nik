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
	bit type	:= 0 + 1;
	bit instance	:= s^1, s^2;

	binary type assumes operators: &, *;

	Navigators may be optimized as they have limited perspectives.
*/

template<typename Binary, Access access = Access::readwrite>
class bit_navigator
{
	public:
		using type = bit_navigator;

	protected:
		using type_ptr = type *;
		using type_ref = type &;

		using binary_type = typename read_type<typename Binary::type, access>::rtn;
		using binary_type_ptr = binary_type *;
		using binary_type_ref = binary_type &;

		using const_type = bit_navigator<Binary, Access::readonly>;

		binary_type_ptr name;
	public:
		bit_navigator(binary_type_ref l) : name(&l) { }

		~bit_navigator() { }

			// Exists to convert readwrite to readonly.
			// Is redundant when already readonly.

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref b) const
		{
			return name == b.name;
		}

		bool operator != (const type_ref b) const
		{
			return name != b.name;
		}

		binary_type_ref operator * () const
		{
			return *name;
		}
};

/*
template<typename Binary, typename Filler>
class const_bit_navigator;
*/

/*
template<typename Binary, typename Filler = void>
class bit_navigator
{
	public:
		typedef bit_navigator type;

	protected:
		typedef type* type_ptr;
		typedef type& type_ref;

		typedef typename Binary::type binary_type;
		typedef binary_type* binary_type_ptr;
		typedef binary_type& binary_type_ref;

		typedef const_bit_navigator<Binary, Filler> const_type;

		binary_type_ptr name;
	public:
		bit_navigator(binary_type_ref l) : name(&l) { }

		~bit_navigator() { }

		operator const_type () const
		{
			return (const_type) this;
		}

		bool operator == (const type_ref b) const
		{
			return name == b.name;
		}

		bool operator != (const type_ref b) const
		{
			return name != b.name;
		}

		binary_type_ref operator * () const
		{
			return *name;
		}
};

template<typename Binary, typename Filler = void>
class const_bit_navigator
{
	public:
		typedef const_bit_navigator type;

	protected:
		typedef type* type_ptr;
		typedef type& type_ref;

		typedef typename Binary::type const binary_type;
		typedef binary_type* binary_type_ptr;
		typedef binary_type& binary_type_ref;

		binary_type_ptr name;
	public:
		const_bit_navigator(binary_type_ref l) : name(&l) { }

		~const_bit_navigator() { }

		bool operator == (const type_ref b) const
		{
			return name == b.name;
		}

		bool operator != (const type_ref b) const
		{
			return name != b.name;
		}

		binary_type_ref operator * () const
		{
			return *name;
		}
};
*/

