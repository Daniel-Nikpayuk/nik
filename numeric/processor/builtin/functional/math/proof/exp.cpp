/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1

	b == -1
	>>> sign

	n == 1
	>>> b

	b == 0 
	>>> n < 0
		>>> error()
		>>> 0

	n < 0
	>>> 0

	b < 0
*/

template<size_type rtn, size_type b, size_type n>
struct exp
{
	enum : size_type
	{
		value = gf_policy::cont::media::template
		if_then_else
		<
			(1 & n),
			exp<rtn*b, b, n-1>,
			exp<rtn, media::template square<b>::value, (n>>1)>
		>::return_type::value
	};
};

template<size_type rtn, size_type b>
struct exp<rtn, b, 0> { static constexpr size_type value = rtn; };

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1

	b == -1
	>>> sign

	n == 1
	>>> b

	b == 0 
	>>> n < 0
		>>> error()
		>>> 0

	n < 0
	>>> 0
*/

template<size_type b, size_type n>
struct exp1
{
	static constexpr size_type sign=1-2*(n % 2);

	enum : size_type
	{
		value = b < 0 ? sign*exp<1, -b, n>::value
			: exp<1, b, n>::value
	};
};

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1

	b == -1
	>>> sign

	n == 1
	>>> b

	b == 0 
	>>> n < 0
		>>> error()
		>>> 0
*/

template<size_type b, size_type n>
struct exp2
{
	static constexpr size_type n1=(n < 0) ? 0 : n;

	enum : size_type
	{
		value = n < 0 ? 0
			: exp<1, b, n1>::value
	};
};

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1

	b == -1
	>>> sign

	n == 1
	>>> b
*/

template<size_type b, size_type n>
struct exp3
{
	static size_type error() throw();
	static constexpr size_type b1=!b ? 0 : b;
	static constexpr size_type n1=(n < 0) ? 0 : n;

	enum : size_type
	{
		value = !b ?
				n < 0 ? error()
				: 0
			: exp<1, b1, n1>::value
	};
};

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1

	b == -1
	>>> sign
*/

template<size_type b, size_type n>
struct exp4
{
	static constexpr size_type n1=(n == 1) ? 0 : n;

	enum : size_type
	{
		value = n == 1 ? b
			: exp<1, b, n1>::value
	};
};

/*
	exceptions:

	b == 1 || (n == 0)
	>>> 1
*/

template<size_type b, size_type n>
struct exp5
{
	static constexpr size_type sign=1-2*(n % 2);
	static constexpr size_type b1=(b == -1) ? 0 : b;

	enum : size_type
	{
		value = b == -1 ? sign
			: exp<1, b1, n>::value
	};
};

