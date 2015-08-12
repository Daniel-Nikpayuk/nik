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

#ifndef CONTEXT_SEMIOTIC_REGISTER_H
#define CONTEXT_SEMIOTIC_REGISTER_H

#include<stddef.h>

#include"../../../context/context/constant.h"

/*
	As block types are intended to hold int types, it's more efficient to pass the given value_type instead of
	a const reference to one.

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these block classes in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
	namespace context
	{
		namespace semiotic
		{
/*
			block:
				typename The minimal specification (axiomatic properties) of a block class are:
				typedefs:
				constructors:
				accessors:
*/
			template<typename size_type>
			struct block
			{
/*
	Has been optimized, but it might just be better to not reuse variables for reading clarity,
	and just let the compiler optimize.

	Adds to the existing out regardless of its initial value.


	if 1 < base, then 0 < base-1.
	Since -1 < 1, then base-1 < base+1.
	Hence (base-1)^2 < base^2-1.
	Thus carry < base^2.

	This shouldn't be categorized in "block" but rather in one of the generic math classes.
*/
				template<typename ValueType>
				static ValueType times(ValueType & out, ValueType mid1, ValueType mid2)
				{
					ValueType	low_in1=(context::meta::constant<size_type>::low_pass & mid1),
							high_in1 = (mid1>>context::meta::constant<size_type>::half_length);
					ValueType	low_in2=(context::meta::constant<size_type>::low_pass & mid2),
							high_in2 = (mid2>>context::meta::constant<size_type>::half_length);
					// mid1, mid2 are now free.

					mid2=low_in1*high_in2;
					mid1=high_in1*low_in2+mid2; // possible carry of 1.

					low_in2*=low_in1;
					low_in1=low_in2+(mid1<<context::meta::constant<size_type>::half_length); // possible carry of 1.

					out+=low_in1; // possible carry of 1.

					return high_in1*high_in2+
						(mid1>>context::meta::constant<size_type>::half_length)+
						((mid1 < mid2)<<context::meta::constant<size_type>::half_length)+
						(low_in1 < low_in2)+
						(out < low_in1);
				}
			};
		}
	}
}

#endif
