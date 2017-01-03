/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
************************************************************************************************************************/

struct math
{
	/*
		multiply:

		Has been optimized, but it might just be better to not reuse variables for reading clarity,
		and just let the compiler optimize.

		if 1 < base, then 0 < base-1.
		Since -1 < 1, then base-1 < base+1.
		Hence (base-1)^2 < base^2-1.
		Thus carry < base^2.
	*/

	struct multiply
	{
	/*
		Reverify this is optimized.
		static size_type low_return(size_type mid1, size_type mid2)
		{
			size_type	little_in1=sift::semiotic::low::with_return(mid1),
					big_in1=sift::semiotic::high::with_return(mid1),
					little_in2=sift::semiotic::low::with_return(mid2),
					big_in2=sift::semiotic::high::with_return(mid2);
			// mid1, mid2 are now free.

			mid2=little_in1*big_in2;
			mid1=big_in1*little_in2+mid2; // possible carry of 1.

			little_in2*=little_in1;

			return little_in2+sift::semiotic::left_shift::with_return(mid1);
		}
	*/
	/*
		Adds the initial out value to the return value (carry).
		The return value is the "little" digit.
		out is the "big" digit.
		static size_type low_return(size_type & out, size_type mid1, size_type mid2)
		{
			size_type	little_in1=sift::semiotic::low::with_return(mid1),
					big_in1=sift::semiotic::high::with_return(mid1),
					little_in2=sift::semiotic::low::with_return(mid2),
					big_in2=sift::semiotic::high::with_return(mid2);
			// mid1, mid2 are now free.

			mid2=little_in1*big_in2;
			mid1=big_in1*little_in2+mid2; // possible carry of 1.

			little_in2*=little_in1;
			little_in1=little_in2+sift::semiotic::left_shift::with_return(mid1); // possible carry of 1.

			big_in1*=big_in2;
			// big_in2, is now free.
			big_in2=out+little_in1;

			out=big_in1+
				sift::semiotic::right_shift::with_return(mid1)+
				sift::semiotic::left_shift::with_return(mid1 < mid2)+
				(little_in1 < little_in2)+
				(big_in2 < little_in1);
			// uses mid1, mid2, little_in1, big_in1, little_in2, big_in2, 

			return big_in2;
		}
	*/
	/*
		Adds to the existing out regardless of its initial value.
		The return value is the "big" digit.
		out is the "little" digit.
		This is intuitively opposite of what it should be, but implements recursively/iteratively better when unrolling.
		static size_type high_return(size_type & out, size_type mid1, size_type mid2)
		{
			size_type	little_in1=sift::semiotic::low::with_return(mid1),
					big_in1=sift::semiotic::high::with_return(mid1),
					little_in2=sift::semiotic::low::with_return(mid2),
					big_in2=sift::semiotic::high::with_return(mid2);
			// mid1, mid2 are now free.

			mid2=little_in1*big_in2;
			mid1=big_in1*little_in2+mid2; // possible carry of 1.

			little_in2*=little_in1;
			little_in1=little_in2+sift::semiotic::left_shift::with_return(mid1); // possible carry of 1.

			out+=little_in1; // possible carry of 1.

			return big_in1*big_in2+
				sift::semiotic::right_shift::with_return(mid1)+
				sift::semiotic::left_shift::with_return(mid1 < mid2)+
				(little_in1 < little_in2)+
				(out < little_in1);
			// uses mid1, mid2, little_in1, big_in1, little_in2, big_in2, 
		}
	*/
	};

	/*
		divide:

		These algorithms are highly optimized and only work (semantically) if (in1|in2 >= d) where (in1 != 0), and (in1 < d).

		The cases d == 0 , d == 1 are not covered as no optimized algorithms are required.
	*/

	struct divide
	{
/*
		static constexpr size_type length = f_semiotic::unit::length;
		static constexpr size_type max = f_semiotic::unit::max;
		static constexpr size_type head = f_semiotic::unit::head;

		static constexpr size_type half_length = f_semiotic::unit::half::length;
		static constexpr size_type half_max = f_semiotic::unit::half::max;

		static constexpr size_type low_pass = f_semiotic::unit::filter::low_pass;
*/
	/*
		The case where d == 2 implies in1 == 1:
		struct shift
		{

			static size_type with_return(size_type & out, size_type in2)
			{
				out=(1 & in2);
				return head + (in2 >> 1);
			}
		};
	*/

		struct half
		{
	/*
		The case where d is at most a half register can be optimized as follows:

		Let in1=|w3|w2| and in2=|w1|w0| with d=|y1|y0|.
		Since d > in1, we have (|y1| > |w3|) or (|y1|==|w3| and |y0| > |w2|).
		For the "single digit case", this means |y1|=0 which implies |w3|=0 and |y0| > |w2|.
	*/
			static size_type with_return(size_type & out, size_type in1, size_type in2, size_type d)
			{
				size_type	little_in2	= (f_semiotic::unit::filter::low_pass & in2),
						big_in2		= (in2 >> f_semiotic::unit::half::length);

				// in2 is now free.
				in2 = (in1 << f_semiotic::unit::half::length) + big_in2;
				// in1, big_in2 are now free.
				in1 = in2/d; big_in2 = in2%d;

				(big_in2 <<= f_semiotic::unit::half::length) += little_in2;
				// little_in2 is now free.

				little_in2 = big_in2/d; out = big_in2%d;

				return (in1 <<= f_semiotic::unit::half::length) + little_in2;
			}
		};

/*
		static bool improve_quotient(size_type & q, size_type uc, size_type u, size_type v)
		{
			size_type t=0, tc=multiply::high_return(t, v, q);
			if (tc > uc || (tc == uc && t > u))
			{
				--q;
				return true;
			}
			else return false;
		}

		static size_type knuth_quotient(size_type uc, size_type u, size_type v)
		{
			size_type q, big_v=sift::semiotic::high::with_return(v);

			if (uc) q=(uc < big_v) ?
				(sift::semiotic::left_shift::with_return(uc)+sift::semiotic::high::with_return(u))/big_v :
					half_max;
			else q=u/v;

			if (improve_quotient(q, uc, u, v))
				improve_quotient(q, uc, u, v);

			return q;
		}
*/
	/*
			The full algorithm assumes u=(u3|u2|u1|u0), v=(v1|v0), where (u3|u2) < v.
			After the Knuth normalization, we end up with n=(n3|n2|n1|n0), as well as d=(d1|d0).
			Keep in mind since (u3|u2) < v, when shifting the relationship will be preserved: (n3|n2) < d.
			Since (n3|n2) < d, we optimize by shifting in another digit: (n3|n2|n1) / d.

			r is the overhead value (carry).
				Set r=n3 for the normal interpretation: An extra digit is assumed shifted in when calling this function.
			in1 is the mid two half digits of the Knuth normalized numerator.
				Set in1=(n2|n1) for the normal interpretation.
			in2 is the lower half digit of the Knuth normalized numerator.
				Set in2=n0 for the normal interpretation.
			d is the Knuth normalized denominator.
				Assumes left_shift(r)+big(in1) < d.

			q is the quotient to be determined (it works its way backwards in half register increments).
			When reading this code, it helps to think of (r|in1) as a single object (the remainder's register).

			Debugging note: Every function call within needs to be "half" robust.
	*/
/*
		static size_type clean_return(size_type & r, size_type in1, size_type in2, size_type d)
		{
			size_type q=0;
			if (r || in1 >= d)
			{
				q=knuth_quotient(r, in1, d);
				in1-=multiply::low_return(q, d);
				q <<= half_length;
			}

			r=sift::semiotic::high::with_return(in1);
			(in1 <<= half_length)+=in2;
			// in2 is now free.

			if (r || in1 >= d)
			{
				in2=knuth_quotient(r, in1, d);
				r=in1-multiply::low_return(in2, d);
				q+=in2;
			}
			else r=in1;

			return q;
		}

		static size_type with_return(size_type in1, size_type in2, size_type d)
		{
			size_type	rank=sift::semiotic::degree::with_return(d), // +1 ?
					power=length-rank;

			(in1<<=power)+=bool(power)*sift::semiotic::high::with_return(in2, rank);
			in2<<=power;
			d<<=power;

			return clean_return(sift::semiotic::high::with_return(in1),
				(in1 <<= half_length) += sift::semiotic::high::with_return(in2),
				sift::semiotic::low::with_return(in2), d);
		}

		static size_type with_return(size_type & r, size_type in1, size_type in2, size_type d)
		{
			size_type	rank=sift::semiotic::degree::with_return(d), // +1 ?
					power=length-rank;

			(in1<<=power)+=bool(power)*sift::semiotic::high::with_return(in2, rank);
			in2<<=power;
			d<<=power;

			r=sift::semiotic::high::with_return(in1);
			in1=clean_return(r,
				(in1 <<= half_length) += sift::semiotic::high::with_return(in2),
				sift::semiotic::low::with_return(in2), d);

			r>>=power;

			return in1;
		}
*/
	};
};

