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

#ifndef NIK_CONTEXT_CONTEXT_PARAMETER_BINARY_H
#define NIK_CONTEXT_CONTEXT_PARAMETER_BINARY_H

#include"../../generic/unit/unit.h"
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

		typedef generic::policy<size_type> cg_policy;

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
			{ enum : size_type { value = shift_up<cg_policy::unit::one, t>::value - cg_policy::unit::one }; };
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
			{ enum : size_type { value = shift_down<x, s>::value }; };
		template<size_type x, size_type s, size_type t>
		struct band
			{ enum : size_type { value = shift_up<shift_down<x, s>::value, t-s>::value }; };

		template<size_type x>
		struct lower_half
			{ enum : size_type { value = low<x, cg_policy::unit::half::length>::value }; };
		template<size_type x>
		struct upper_half
			{ enum : size_type { value = high<x, cg_policy::unit::half::length>::value }; };

		template<size_type x>
		struct order
		{
			template<size_type primary, size_type secondary, size_type n>
			struct fast_order
			{
				enum : size_type
				{
					value=meta::if_then_else<band<secondary, (n>>cg_policy::unit::one), n>::value,
						fast_order<primary+(n>>cg_policy::unit::one),
							band<secondary, (n>>cg_policy::unit::one), n>::value, (n>>cg_policy::unit::one)>,
						fast_order<primary,
							band<secondary, cg_policy::unit::zero,
								(n>>cg_policy::unit::one)>::value, (n>>cg_policy::unit::one)>
							>::return_type::value
				};
			};

			template<size_type primary, size_type secondary>
			struct fast_order<primary, secondary, cg_policy::unit::zero> { enum : size_type { value=primary }; };

			enum : size_type { value=fast_order<cg_policy::unit::zero, x, cg_policy::unit::length>::value };
		};
	};
   }
  }
 }
}

#endif
