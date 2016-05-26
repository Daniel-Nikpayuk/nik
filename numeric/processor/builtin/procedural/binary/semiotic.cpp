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
	None of these account for shifting beyond the register length, which may have unknown side effects.
*/
static size_type shift_up(size_type in, size_type n)
	{ return in << n; }

	// common enough to optimize:
static size_type shift_up(size_type in)
	{ return in << p_policy::unit::half::length; }

static size_type shift_down(size_type in, size_type n)
	{ return in >> n; }

	// common enough to optimize:
static size_type shift_down(size_type in)
	{ return in >> p_policy::unit::half::length; }
/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.

	Should the code here be manually expanded so as to not rely on function calls? Will the compiler optimize?
*/
static size_type low_pass(size_type t)
	{ return shift_up(1, t)-1; }

static size_type high_pass(size_type s)
	{ return ~ low_pass(s); }

static size_type band_pass(size_type s, size_type t)
	{ return low_pass(t-s) << s; }

static size_type low(size_type in, size_type t)
	{ return (in & low_pass(t)); }

	// common enough to optimize:
static size_type low(size_type in)
	{ return (p_policy::unit::filter::low_pass & in); }

static size_type high(size_type in, size_type s)
	{ return shift_down(in, s); }

	// common enough to optimize:
static size_type high(size_type in)
	{ return in >> p_policy::unit::half::length; }

static size_type band(size_type in, size_type s, size_type t)
	{ return low(shift_down(in, s), t-s); }

template<size_type N, size_type M=0, size_type L=0>
struct unroll
{
/*
	order:

	Finds the index of the leading digit of the register number using the half-point method.
*/
		static size_type order(size_type primary, size_type secondary)
		{
			size_type m=band(secondary, (N >> 1), N);
			if (m) primary += (N >> 1);
			else m=band(secondary, 0, (N >> 1));

			return unroll<(N >> 1)>::order(primary, m);
		}
};

template<size_type M, size_type L>
struct unroll<0, M, L>
{
	static size_type order(size_type primary, size_type secondary)
		{ return primary; }
};

static size_type order(size_type in)
	{ return semiotic::template unroll<p_policy::unit::length>::order(0, in); }

