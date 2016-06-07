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
	Optimized as max > 0: We need not call the conforming version.
*/

struct low_pass
{
	static size_type with_return(size_type t)
		{ return f_policy::unit::semiotic::max >> (f_policy::unit::semiotic::length - t); }
};

struct high_pass
{
	static size_type with_return(size_type s)
		{ return f_policy::unit::semiotic::max & ~low_pass::with_return(s); }
};

/*
	Optimized as max > 0: We need not call the conforming version.
*/

struct band_pass
{
	static size_type with_return(size_type s, size_type t)
		{ return (f_policy::unit::semiotic::max >> (f_policy::unit::semiotic::length-t+s)) << s; }
};

struct low
{
	static size_type with_return(size_type x, size_type t)
		{ return x & low_pass::with_return(t); }

	struct half
	{
		static size_type with_return(size_type x)
			{ return (f_policy::unit::semiotic::filter::low_pass & x); }
	};
};

struct high
{
	static size_type with_return(size_type x, size_type s)
		{ return over::semiotic::right_shift::with_return(x, s); }

	struct half
	{
		static size_type high(size_type x)
			{ return x >> f_policy::unit::semiotic::half::length; }
	};
};

struct band
{
	static size_type with_return(size_type x, size_type s, size_type t)
		{ return over::semiotic::right_shift::with_return(x & (1 << t) - 1, s); }
};

/*
	primary != 0
*/

struct degree
{
/*
	Could be more efficient!
*/
	static size_type signed_return(size_type primary)
	{
		size_type count=-1;

		while (primary)
		{
			primary = over::semiotic::right_shift::with_return(primary, 1);
			++count;
		}

		return count;
	}
};

template<size_type N, size_type M=0, size_type L=0>
struct unroll
{
/*
	degree:

	Finds the index of the leading digit of the register number using the half-point method.
*/
		struct degree
		{
			static size_type unsigned_return(size_type primary, size_type secondary)
			{
				static constexpr size_type N0 = N >> 1;

				size_type m=band::with_return(secondary, N0, N);
				if (m) primary += N0;
				else m=band::with_return(secondary, 0, N0);

				return unroll<N0>::degree::unsigned_return(primary, m);
			}
		};
};

template<size_type M, size_type L>
struct unroll<0, M, L>
{
	struct degree
	{
		static size_type unsigned_return(size_type primary, size_type secondary)
			{ return primary; }
	};
};

