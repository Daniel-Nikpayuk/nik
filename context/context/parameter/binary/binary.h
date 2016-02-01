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

#include"../../constant/constant.h"
#include"../meta/meta.h"

namespace nik
{
 namespace context
 {
  namespace context
  {
   namespace parameter
   {
	template<typename size_type>
	struct binary
	{
		typedef context::constant<size_type> constant;

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
			{ enum : size_type { value = shift_up<constant::one, t>::value - constant::one }; };
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
			{ enum : size_type { value = low<x, constant::half_register::length>::value }; };
		template<size_type x>
		struct upper_half
			{ enum : size_type { value = high<x, constant::half_register::length>::value }; };

		template<size_type x>
		struct order
		{
			template<size_type primary, size_type secondary, size_type n>
			struct fast_order
			{
				enum : size_type
				{
					value=meta::if_then_else<mid<secondary, (n>>constant::one), n>::value,
						fast_order<primary+(n>>constant::one),
							mid<secondary, (n>>constant::one), n>::value, (n>>constant::one)>,
						fast_order<primary,
							mid<secondary, constant::zero, (n>>constant::one)>::value, (n>>constant::one)>
							>::return_type::value
				};
			};

			template<size_type primary, size_type secondary>
			struct fast_order<primary, secondary, constant::zero> { enum : size_type { value=primary }; };

			enum : size_type { value=fast_order<constant::zero, x, constant::full_register::length>::value };
		};
	};
   }
  }
 }
}

#endif
