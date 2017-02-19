/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename E1, typename E2>
struct equal
{
	template<typename, typename> struct strict;

	template<typename Type1, typename Type2>
	struct strict<c<Type1>, c<Type2>>
	{
		static constexpr bool value = false;
	};

	template<typename Type>
	struct strict<c<Type>, c<Type>>
	{
		static constexpr bool value = true;
	};

	// Assumes "Type" has an implicit equals operator:

	template<typename Type, Type value1, Type value2>
	struct strict<c<Type, value1>, c<Type, value2>>
	{
		static constexpr bool value = (value1 == value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn

		>::value
	>;
};

// Assumes "Type" has an implicit equals operator:

template<typename E1, typename E2>
struct less_than
{
	template<typename, typename> struct strict;

	template<typename Type, Type value1, Type value2>
	struct strict<c<Type, value1>, c<Type, value2>>
	{
		static constexpr bool value = (value1 < value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn

		>::value
	>;
};

template<typename E1, typename E2>
struct less_than_or_equal
{
	template<typename, typename> struct strict;

	template<typename Type, Type value1, Type value2>
	struct strict<c<Type, value1>, c<Type, value2>>
	{
		static constexpr bool value = (value1 <= value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn

		>::value
	>;
};

//

template<typename E1, typename E2>
struct greater_than
{
	template<typename, typename> struct strict;

	template<typename Type, Type value1, Type value2>
	struct strict<c<Type, value1>, c<Type, value2>>
	{
		static constexpr bool value = (value1 > value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn

		>::value
	>;
};

template<typename E1, typename E2>
struct greater_than_or_equal
{
	template<typename, typename> struct strict;

	template<typename Type, Type value1, Type value2>
	struct strict<c<Type, value1>, c<Type, value2>>
	{
		static constexpr bool value = (value1 >= value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn

		>::value
	>;
};

