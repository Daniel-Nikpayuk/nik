/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
				template<size_type x, size_type n> struct left_shift { enum : size_type { value=(size_type)x<<n }; };
				template<size_type x, size_type n> struct right_shift { enum : size_type { value=(size_type)x>>n }; };

				template<size_type n> struct low_pass
					{ enum : size_type { value=left_shift<ONE, n>::value-ONE }; };
				template<size_type n> struct high_pass
					{ enum : size_type { value=~low_pass<constant<size_type>::register_length-n>::value }; };
/*
	Position 't' is greater than the final position of the band pass.
*/
				template<size_type t, size_type n> struct band_pass
					{ enum : size_type { value=(size_type)low_pass<n>::value<<(t-n) }; };

				template<size_type x, size_type n> struct left
					{ enum : size_type { value=(x & low_pass<n>::value) }; };
				template<size_type x, size_type n> struct right
					{ enum : size_type { value=right_shift<x, constant<size_type>::register_length-n>::value }; };
				template<size_type x, size_type t, size_type n> struct mid
					{ enum : size_type { value=right_shift<(x & low_pass<t>::value), t-n>::value }; };

				template<size_type x> struct left_half
					{ enum : size_type { value=left<x, constant<size_type>::half_length>::value }; };
				template<size_type x> struct right_half
					{ enum : size_type { value=right<x, constant<size_type>::half_length>::value }; };

				template<size_type x> struct order
				{
					template<size_type primary, size_type secondary, size_type n>
					struct fast_order
					{
						enum : size_type
						{
							value=if_then_else<mid<secondary, n, n/2>::value,
								fast_order<primary+n/2, mid<secondary, n, n/2>::value, n/2>,
								fast_order<primary, mid<secondary, n/2, n/2>::value, n/2>
									>::return_type::value
						};
					};

					template<size_type primary, size_type secondary>
					struct fast_order<primary, secondary, 0> { enum : size_type { value=primary }; };

					enum : size_type { value=fast_order<0, x, constant<size_type>::register_length>::value };
				};
			};
		}
	}
}

#include"pre_end.h"

#endif
