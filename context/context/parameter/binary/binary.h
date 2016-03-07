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

#ifndef CONTEXT_CONTEXT_PARAMETER_BINARY_H
#define CONTEXT_CONTEXT_PARAMETER_BINARY_H

#include"../../unit/unit.h"
#include"../meta/meta.h"

namespace nik
{
 namespace context
 {
  namespace context
  {
   namespace parameter
   {
	template<typename SizeType>
	struct binary
	{
		typedef SizeType size_type;

		typedef context::unit<size_type> unit;

		template<size_type x, size_type n>
		struct shift_up
			{ enum : size_type { value = x << n }; };
		template<size_type x, size_type n>
		struct shift_down
			{ enum : size_type { value = x >> n }; };
/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.
*/
		template<size_type t>
		struct low_pass
			{ enum : size_type { value = shift_up<unit::one, t>::value - unit::one }; };
		template<size_type s>
		struct high_pass
			{ enum : size_type { value = ~ low_pass<s>::value }; };
		template<size_type s, size_type t>
		struct band_pass
			{ enum : size_type { value = low_pass<t-s>::value << s }; };

		template<size_type x, size_type t>
		struct low
			{ enum : size_type { value = (x & low_pass<t>::value) }; };
		template<size_type x, size_type s>
		struct high
			{ enum : size_type { value = right_shift<x, s>::value }; };
		template<size_type x, size_type s, size_type t>
		struct band
			{ enum : size_type { value = left_shift<right_shift<x, s>::value, t-s>::value }; };

		template<size_type x>
		struct lower_half
			{ enum : size_type { value = low<x, unit::half::length>::value }; };
		template<size_type x>
		struct upper_half
			{ enum : size_type { value = high<x, unit::half::length>::value }; };

		template<size_type x>
		struct order
		{
			template<size_type primary, size_type secondary, size_type n>
			struct fast_order
			{
				enum : size_type
				{
					value=meta::if_then_else<mid<secondary, (n>>unit::one), n>::value,
						fast_order<primary+(n>>unit::one),
							mid<secondary, (n>>unit::one), n>::value, (n>>unit::one)>,
						fast_order<primary,
							mid<secondary, unit::zero, (n>>unit::one)>::value, (n>>unit::one)>
							>::return_type::value
				};
			};

			template<size_type primary, size_type secondary>
			struct fast_order<primary, secondary, unit::zero> { enum : size_type { value=primary }; };

			enum : size_type { value=fast_order<unit::zero, x, unit::length>::value };
		};
	};
   }
  }
 }
}

#endif
