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

struct math
{
	/*
		multiply:
	*/

	struct multiply
	{
	};

	/*
		divide:

		These algorithms are highly optimized and only work (semantically) if (in1|in2 >= d) where (in1 != 0), and (in1 < d).

		The cases d == 0 , d == 1 are not covered as no optimized algorithms are required.
	*/

	struct divide
	{
	/*
		return_quotient:

		The return value is the quotient of the division.
		out is the remainder from the division.
		in1 is the first digit of the dividend and is such that in1 != 0.
		in2 is the second digit of the dividend.
		d is the divisor and is such that in1 < d. Given in1 != 0, this implies 2 <= d.
				template<typename size_type>
				static size_type return_quotient(size_type & out, size_type in1, size_type in2, size_type d)
				{
					if (d == (size_type) 2) return divisor_equals_2(out, in2);
					else if (d < shift_up((size_type) 1)) return half::with_return(out, in1, in2, d);
					else return with_return(out, in1, in2, d);
				}
	*/
	};
};

