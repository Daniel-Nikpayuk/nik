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

#ifndef CONTEXT_META_BINARY_H
#define CONTEXT_META_BINARY_H

#include"constant.h"
#include"meta.h"

#include"pre_begin.h"

namespace nik
{
	namespace context
	{
		namespace meta
		{
			template<typename size_type>
			struct binary
			{
				template<size_type x, size_type n> struct shift_up { enum : size_type { value=(size_type)x<<n }; };
				template<size_type x, size_type n> struct shift_down { enum : size_type { value=x>>n }; };

/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.
*/
				template<size_type t> struct low_pass
					{ enum : size_type { value=shift_up<ONE, t>::value-ONE }; };
				template<size_type s> struct high_pass
					{ enum : size_type { value=~low_pass<s>::value }; };
				template<size_type s, size_type t> struct band_pass
					{ enum : size_type { value=(size_type) low_pass<t-s>::value<<s }; };

				template<size_type x, size_type t> struct low
					{ enum : size_type { value=(x & low_pass<t>::value) }; };
				template<size_type x, size_type s> struct high
					{ enum : size_type { value=right_shift<x, s>::value }; };
				template<size_type x, size_type s, size_type t> struct band
					{ enum : size_type { value=left<right_shift<x, s>::value, t-s>::value }; };

				template<size_type x> struct lower_half
					{ enum : size_type { value=low<x, constant<size_type>::half_length>::value }; };
				template<size_type x> struct upper_half
					{ enum : size_type { value=high<x, constant<size_type>::half_length>::value }; };

				template<size_type x> struct order
				{
					template<size_type primary, size_type secondary, size_type n>
					struct fast_order
					{
						enum : size_type
						{
							value=if_then_else<mid<secondary, (n>>ONE), n>::value,
								fast_order<primary+(n>>ONE), mid<secondary, (n>>ONE), n>::value, (n>>ONE)>,
								fast_order<primary, mid<secondary, ZERO, (n>>ONE)>::value, (n>>ONE)>
									>::return_type::value
						};
					};

					template<size_type primary, size_type secondary>
					struct fast_order<primary, secondary, ZERO> { enum : size_type { value=primary }; };

					enum : size_type { value=fast_order<ZERO, x, constant<size_type>::register_length>::value };
				};
			};
		}
	}
}

#include"pre_end.h"

#endif
