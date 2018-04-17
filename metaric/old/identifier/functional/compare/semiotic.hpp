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

template<typename expression1, typename expression2>
struct eq
{
	template<typename str1, typename str2>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = (str1::value == str2::value);
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn,
		typename expression2::rtn

	>::rtn;
};

template<typename expression1, typename expression2>
struct equal
{
	template<typename T, typename U>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = false;
		};
	};

	template<typename T>
	struct strict<T, T>
	{
		struct rtn
		{
			static constexpr bool value = true;
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn::type,
		typename expression2::rtn::type

	>::rtn;
};

//

template<typename expression1, typename expression2>
struct less_than
{
	template<typename str1, typename str2>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = (str1::value < str2::value);
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn,
		typename expression2::rtn

	>::rtn;
};

template<typename expression1, typename expression2>
struct less_than_or_equal
{
	template<typename str1, typename str2>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = (str1::value <= str2::value);
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn,
		typename expression2::rtn

	>::rtn;
};

//

template<typename expression1, typename expression2>
struct greater_than
{
	template<typename str1, typename str2>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = (str1::value > str2::value);
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn,
		typename expression2::rtn

	>::rtn;
};

template<typename expression1, typename expression2>
struct greater_than_or_equal
{
	template<typename str1, typename str2>
	struct strict
	{
		struct rtn
		{
			static constexpr bool value = (str1::value >= str2::value);
		};
	};

	using rtn = typename strict
	<
		typename expression1::rtn,
		typename expression2::rtn

	>::rtn;
};

