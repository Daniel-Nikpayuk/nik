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

#ifndef CONTEXT_CONTEXT_ARGUMENT_BINARY_H
#define CONTEXT_CONTEXT_ARGUMENT_BINARY_H

#include"../../unit/unit.h"

/*
	As optimized (fast) types are intended to hold int types, it's more efficient to pass the given size_type instead of
	a const reference to one.

	Incrementing and decrementing pointers which should otherwise maintain a unit location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. As such, given some routines and subroutines are powerhouse workhorses
	relative to the whole library, it is worth implementing a few to be as processor and memory efficient as possible.

	Shifting functions are actually provided less for improved efficiency, but more for coercion and type deduction safety.
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
   namespace argument
   {
/*
	None of these account for shifting beyond the register length, which may have unknown side effects.
*/
	template<typename SizeType>
	struct binary
	{
		typedef SizeType size_type;

		typedef context::unit<size_type> unit;

		static size_type shift_up(size_type in, size_type n)
			{ return in << n; }

	// common enough to optimize:
		static size_type shift_up(size_type in)
			{ return in << unit::half::length; }

		static size_type shift_down(size_type in, size_type n)
			{ return in >> n; }

	// common enough to optimize:
		static size_type shift_down(size_type in)
			{ return in >> unit::half::length; }
/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.

	Should the code here be manually expanded so as to not rely on function calls? Will the compiler optimize?
*/
		static size_type low_pass(size_type t)
			{ return shift_up(unit::one, t)-unit::one; }

		static size_type high_pass(size_type s)
			{ return ~ low_pass(s); }

		static size_type band_pass(size_type s, size_type t)
			{ return low_pass(t-s) << s; }

		static size_type low(size_type in, size_type t)
			{ return (in & low_pass(t)); }

			// common enough to optimize:
		static size_type low(size_type in)
			{ return (unit::filter::low_pass & in); }

		static size_type high(size_type in, size_type s)
			{ return shift_down(in, s); }

			// common enough to optimize:
		static size_type high(size_type in)
			{ return in >> unit::half::length; }

		static size_type mid(size_type in, size_type s, size_type t)
			{ return low(shift_down(in, s), t-s); }

		template<size_type N, size_type M=unit::zero, size_type L=unit::zero>
		struct unroll
		{
/*
	order:

	Finds the index of the leading digit of the register number using the half-point method.
*/
			static size_type order(size_type primary, size_type secondary)
			{
				size_type m=mid(secondary, (N >> unit::one), N);
				if (m) primary += (N >> unit::one);
				else m=mid(secondary, unit::zero, (N >> unit::one));

				return unroll<(N >> unit::one)>::order(primary, m);
			}
		};

		template<size_type M, size_type L>
		struct unroll<unit::zero, M, L>
		{
			static size_type order(size_type primary, size_type secondary)
				{ return primary; }
		};

		static size_type order(size_type in)
			{ return unroll<unit::length>::order(unit::zero, in); }
	};
   }
  }
 }
}

#endif
