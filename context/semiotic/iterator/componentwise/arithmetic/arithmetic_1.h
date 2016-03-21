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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_ARITHMETIC_1_H
#define CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_ARITHMETIC_1_H

// overhead dependencies:

#include"arithmetic_0.h"

#include"../../../../context/policy/policy.h"
#include"../overload/overload.h"

// for debugging:

//#include"../../../context/display/display.h"

// Clean up the typedefs/usings namespace stuff.

/*
	The main difference between "overload" and "arithmetic" from an algorithmic lens is that with overload is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a c_policy::unit location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace componentwise
    {
     namespace forward
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		typedef overload<size_type> fwd_over;

		typedef arithmetic_0<size_type> fwd_arit;

		struct scale
		{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
			template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
			static void no_return(ValueType carry, WIterator out, RIterator in1, ERIterator end1, ValueType in2)
			{
				while (in1 != end1)
				{
					carry=c_policy::arg_math::multiply::high_return(*out=carry, *in1, in2);
					++out; ++in1;
				}
			}
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
			template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
			static WIterator with_return(ValueType carry, WIterator out, RIterator in1, ERIterator end1, ValueType in2)
			{
				while (in1 != end1)
				{
					carry=c_policy::arg_math::multiply::high_return(*out=carry, *in1, in2);
					++out; ++in1;
				}

				return out;
			}
		};
/*
	This version is for reference, otherwise the below version---optimized for memory using composition---is the same.

	Should it be acceptable to assume size_type == Numeral::size_type ?

			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_equal(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				out.terminal=method::template plus_assign<base>(out.initial, in.initial, in.terminal);
				out.terminal=method::template plus_push_count<base>(out.terminal, in.terminal->value, count);
				return count;
			}

	This equal case also holds for &out==&in, which is nice, but it should be verified.
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_equal(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				out.terminal=method::template plus_push_count<base>(
					method::template plus_assign<base>(out.initial, in.initial, in.terminal),
					in.terminal->value, count);
				return count;
			}
/*
	This version is for reference, otherwise the below version---optimized for memory using composition---is the same.

	Should it be acceptable to assume size_type == Numeral::size_type ?

			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_less_than(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				typename Numeral::const_pointer i=method::template
					converse_plus_assign<base>(out.initial, out.terminal, in.initial);
				out.terminal=method::template plus_push<base>(out.terminal, i, in.terminal, count);
				out.terminal=method::template plus_push_count<base>(out.terminal, in.terminal->value, count);
				return count;
			}
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_less_than(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				out.terminal=method::template plus_push_count<base>(
					method::template plus_push<base>(out.terminal,
						method::template converse_plus_assign<base>(out.initial, out.terminal, in.initial),
						in.terminal),
					in.terminal->value, count);
				return count;
			}
/*
	This version is for reference, otherwise the below version---optimized for memory using composition---is the same.

	Should it be acceptable to assume size_type == Numeral::size_type ?

			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_greater_than(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				typename Numeral::pointer i=method::template plus_assign<base>(out.initial, in.initial, in.terminal);
				method::template plus_assign<base>(i, out.terminal, in.terminal->value);
				out.terminal=method::template plus_push_count<base>(out.terminal, 0, count);
				return count;
			}
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type plus_assign_greater_than(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				method::template plus_assign<base>(
					method::template plus_assign<base>(out.initial, in.initial, in.terminal),
					out.terminal, in.terminal->value);
				out.terminal=method::template plus_push_count<base>(out.terminal, 0, count);
				return count;
			}
/*
			template<size_type base, typename Numeral>
			static Numeral* equal_plus(Numeral *out, const Numeral *in1, const Numeral *in2, const Numeral *end2, size_type & count)
			{
				out=method::template plus_push<base>(out, in1, in2, end2);
				return method::template plus_push_count<base>(out, in1->value+end2->value, count);
			}
*/
/*
	Provided for symmetry, but in practice try to use either the less_than or greater_than version but not both (expensive).
			template<size_type base, typename Numeral>
			static Numeral* less_than_plus(Numeral *out,
				const Numeral *in1, const Numeral *end1, const Numeral *in2, const Numeral *end2, size_type & count)
			{
				out=method::template plus_push<base>(out, in2, in1, end1);
				out->value+=end1->value;
				out=method::template plus_push<base>(out, in2, end2);
				return method::template plus_push_count<base>(out, end2->value, count);
			}
*/
/*
	Provided for symmetry, but in practice try to use either the less_than or greater_than version but not both (expensive).
			template<size_type base, typename Numeral>
			static Numeral* greater_than_plus(Numeral *out,
				const Numeral *in1, const Numeral *end1, const Numeral *in2, const Numeral *end2, size_type & count)
			{
				out=method::template plus_push<base>(out, in1, in2, end2);
				out->value+=end2->value;
				out=method::template plus_push<base>(out, in1, end1);
				return method::template plus_push_count<base>(out, end1->value, count);
			}
*/
/*
					natural_number operator - (const natural_number & n) const
					{
						natural_number out;
						if (n < *this)
							out.terminal=method::minus<radix>(out.terminal,
								out.magnitude, numeral::initial, n.initial);

						return out;
					}
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type double_assign(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				out.terminal=method::template double_push<base>(out.initial, in.initial, in.terminal);
				out.terminal=method::template double_push_count<base>(out.terminal, in.terminal->value<<1, count);
				return count;
			}
/*
				if (in.initial == in.terminal) out.initial->value=(in.initial->value>>1);
				else
				{
					typename Numeral::const_pointer i=in.initial;
					out.terminal=method::template halve_push<base>(out.initial, i, in.terminal);
					out.terminal=method::template halve_pop_count<base>(out.terminal, i, count);
				}
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type halve_assign(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				if (in.initial == in.terminal) out.initial->value=(in.initial->value>>1);
				else
				{
					typename Numeral::const_pointer i=in.initial;
					out.terminal=method::template halve_push<base>(out.initial, i, in.terminal);
					out.terminal=method::template halve_pop_count<base>(out.terminal, i, count);
				}
				return count;
			}

/*
	Might need the case for in == 0, but probably not for your purposes.
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type decrement(Numeral & out, const Numeral & in)
			{
				typename Numeral::size_type count(0);
				if (in.initial == in.terminal) out.initial->value=in.initial->value-1;
				else
				{
					typename Numeral::const_pointer i=in.initial;
					out.terminal=method::template decrement_push<base>(out.initial, i, in.terminal);
					out.terminal=method::template decrement_pop_count<base>(out.terminal, i, count);
				}
				return count;
			}
/*
*/
			template<size_type base, typename Numeral>
			static typename Numeral::size_type fast_asterisk_assign(Numeral & out, typename Numeral::size_type in)
			{
				typename Numeral::size_type count(0);
/*
				natural_number s(*this);
				numeral::terminalize(0); magnitude=0;
				while (n != 0)
				{
					if (n & 1)
					{
						operator+=(s);
						--n;
					}
					else
					{
						s+=s;
						n>>=1;
					}
				}
*/

				return count;
			}
/*
			template<size_type base, typename Numeral>
			static typename Numeral::size_type halve_assign(Numeral & out)
			{
				typename Numeral::size_type count(0);
				out=method::template push_double<base>(out);
				out=method::template push_double_count<base>(out, count);
				return count;
			}
*/
/*
	As this algorithm is complicated and relies on many assumptions to make the magnitude match, it needs a thorough
	proof and debugging.
*/
			template<size_type base>
			struct asterisk
			{
				private:
					template<typename Numeral>
					static typename Numeral::size_type scalar_product(
						Numeral & out, const Numeral & in, typename Numeral::size_type repeat,
							typename Numeral::value_type value, typename Numeral::size_type & carry2)
					{
						typename Numeral::size_type carry1(carry2);
						Numeral prod(0, repeat);
						prod.terminal=method::template
							asterisk_push<base>(prod.terminal, in.initial, in.terminal, value);
						prod.terminal=method::template
							plus_push_count<base>(prod.terminal, in.terminal->value*value, carry2);
						if (carry1 && !carry2) return plus_assign_equal<base>(out, prod);
						else return plus_assign_less_than<base>(out, prod);
					}

					template<typename Numeral>
					static typename Numeral::size_type multiply(Numeral & out, const Numeral & in1, const Numeral & in2)
					{
						typename Numeral::size_type carry(0), repeat(1);
						for (typename Numeral::const_pointer i(in2.initial); i != in2.terminal; i=i->edge0, ++repeat)
							if (i->value) scalar_product(out, in1, repeat, i->value, carry);
						repeat=scalar_product(out, in1, repeat, in2.terminal->value, carry);
						return carry+repeat;
					}
				public:
					template<typename Numeral>
					static typename Numeral::size_type times_equals(Numeral & out, const Numeral & in2)
					{
						Numeral in1; in1.initial=out.initial; in1.terminal=out.terminal;
						out.initialize(0);
						return multiply(out, in1, in2);
					}

					template<typename Numeral>
					static typename Numeral::size_type square_equals(Numeral & out)
					{
						Numeral in; in.initial=out.initial; in.terminal=out.terminal;
						out.initialize(0);
						return multiply(out, in, in);
					}
			};

			template<size_type base, typename Numeral>
			static typename Numeral::size_type hat_assign(Numeral & out, typename Numeral::size_type in2)
			{
				Numeral in1; in1.initial=out.initial; in1.terminal=out.terminal; out.initialize(1);
				while (in2 != 1)
				{
					if (in2 & 1)
					{
						asterisk<base>::times_equals(out, in1);
						--in2;
					}
					else
					{
						asterisk<base>::square_equals(in1);
						in2>>=1;
					}
				}

				return asterisk<base>::times_equals(out, in1);
			}

		struct assign
		{
			struct scale
			{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename ValueType, typename WIterator, typename EIterator>
				static void no_return(ValueType carry, WIterator out, EIterator end, ValueType in)
				{
					ValueType before;
					while (out != end)
					{
						before=*out;
						carry=c_policy::arg_math::multiply::high_return(*out=carry, before, in);
						++out;
					}
				}
			};
		};
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public fwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using fwd_unroll=typename fwd_arit::template unroll_0<K, J, I>;

			struct scale
			{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename ValueType, typename WIterator, typename RIterator>
				static void no_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
				{
					carry=c_policy::arg_math::multiply::high_return(*out=carry, *in1, in2);
					unroll_1<N-1>::scale::no_return(carry, ++out, ++in1, in2);
				}
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename ValueType, typename WIterator, typename RIterator>
				static WIterator with_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
				{
					carry=c_policy::arg_math::multiply::high_return(*out=carry, *in1, in2);
					return unroll_1<N-1>::scale::with_return(carry, ++out, ++in1, in2);
				}
			};
/*
	N is initially the length of in1.
	M is the length of in1.
	L is the length of in2. It is assumed M >= L.

	out1 is the carry, but is semantically meaningful as the proper output.
		Does not assume anything about the existing value of out1.
	out2 is meant to be a temporary variable.

	Is it worth testing for *in2 == 0 ?
*/
			struct multiply
			{
				struct half
				{
					template<typename ValueType,
						typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
					{
						fwd_unroll<M+N-L>::scale::half::no_return((ValueType) 0,
							fwd_over::template unroll<L-N>::repeat::with_return(out2, (ValueType) 0),
							in1, *in2);
						fwd_unroll<M>::assign::plus::half::no_return((ValueType) 0, out1, out2);
						unroll_1<N-1, M, L>::template multiply<ValueType>::
							half::no_return(out1, out2, in1, ++in2);
					}
				};
			};

			struct assign
			{
				struct scale
				{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
					template<typename ValueType, typename WIterator>
					static void no_return(ValueType carry, WIterator out, ValueType in)
					{
						ValueType before(*out);
						carry=c_policy::arg_math::multiply::high_return(*out=carry, before, in);
						unroll_1<N-1>::assign::scale::no_return(carry, ++out, in);
					}
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
					template<typename ValueType, typename WIterator>
					static WIterator with_return(ValueType carry, WIterator out, ValueType in)
					{
						ValueType before(*out);
						carry=c_policy::arg_math::multiply::high_return(*out=carry, before, in);
						return unroll_1<N-1>::assign::scale::with_return(carry, ++out, in);
					}
				};

				// Multiply requires a deep copy anyway, so there's no point to an assign version.
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public fwd_arit::template unroll_0<0, M, L>
		{
			struct scale
			{
				template<typename ValueType, typename WIterator, typename RIterator>
				static void no_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
					{ }

				template<typename ValueType, typename WIterator, typename RIterator>
				static WIterator with_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
					{ return out; }
			};

			struct multiply
			{
				struct half
				{
					template<typename ValueType,
						typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
						{ }
				};
			};

			struct assign
			{
				struct scale
				{
					template<typename ValueType, typename WIterator>
					static void no_return(ValueType carry, WIterator out, ValueType in)
						{ }

					template<typename ValueType, typename WIterator>
					static WIterator with_return(ValueType carry, WIterator out, ValueType in)
						{ return out; }
				};
			};
		};
	};
     }

     namespace backward
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		typedef forward::overload<size_type> fwd_over;
		typedef overload<size_type> bwd_over;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef arithmetic_0<size_type> bwd_arit;

		struct divide
		{
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the half digit denominator.
*/
			struct half_digit
			{
				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					while (n != end)
					{
						if (rc) *q=c_policy::arg_math::divide::half::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						r=*n;
						--q; --n;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					while (n != end)
					{
						if (rc) *q=c_policy::arg_math::divide::half::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						r=*n;
						--q; --n;
					}

					return q;
				}
			};
/*
	rc is the higher carry value.
		Set this to zero for the "normal" interpretation.
		Values are shifted into it from the lower carry until big enough to divide.
	r is the lower carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
			struct single_digit
			{
				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					while (n != end)
					{
						if (rc) *q=c_policy::arg_math::divide::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						r=*n;
						--q; --n;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					while (n != end)
					{
						if (rc) *q=c_policy::arg_math::divide::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						r=*n;
						--q; --n;
					}

					return q;
				}
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static void no_return(ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
					{
						while (n != end)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=c_policy::unit::half::length)+=*n;
							--q; --n;
						}
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static WIterator with_return(ValueType r, WIterator q, RIterator n, ERIterator end, ValueType d)
					{
						while (n != end)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=c_policy::unit::half::length)+=*n;
							--q; --n;
						}

						return q;
					}
				};
			};
		};

		struct assign
		{
		};
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;

			struct divide
			{
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the half digit denominator.
*/
				struct half_digit
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
					{
						if (rc) *q=c_policy::arg_math::divide::half::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						unroll_1<N-1>::divide::half_digit::no_return(r=*n, --q, --n, d);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
					{
						if (rc) *q=c_policy::arg_math::divide::half::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						return unroll_1<N-1>::divide::half_digit::with_return(r=*n, --q, --n, d);
					}
				};
/*
	rc is the higher carry value.
		Set this to zero for the "normal" interpretation.
		Values are shifted into it from the lower carry until big enough to divide.
	r is the lower carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
				struct single_digit
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
					{
						if (rc) *q=c_policy::arg_math::divide::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						unroll_1<N-1>::divide::single_digit::no_return(r=*n, --q, --n, d);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
					{
						if (rc) *q=c_policy::arg_math::divide::with_return(rc, rc, r, d);
						else if (r >= d) { *q=r/d; rc=r%d; }
						else { *q=0; rc=r; }

						return unroll_1<N-1>::divide::single_digit::with_return(r=*n, --q, --n, d);
					}
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType r, WIterator q, RIterator n, ValueType d)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=c_policy::unit::half::length)+=*n;
							unroll_1<N-1>::divide::single_digit::half::no_return(r, --q, --n, d);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType r, WIterator q, RIterator n, ValueType d)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=c_policy::unit::half::length)+=*n;
							return unroll_1<N-1>::divide::single_digit::half::with_return(r, --q, --n, d);
						}
					};
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public bwd_arit::template unroll_0<0, M, L>
		{
			struct divide
			{
				struct half_digit
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
						{ return q; }
				};

				struct single_digit
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType rc, ValueType r, WIterator q, RIterator n, ValueType d)
						{ return q; }

					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType r, WIterator q, RIterator n, ValueType d)
							{ }

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType r, WIterator q, RIterator n, ValueType d)
							{ return q; }
					};
				};
			};
		};
	};
     }

     namespace bidirectional
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		typedef forward::overload<size_type> fwd_over;
		typedef backward::overload<size_type> bwd_over;
		typedef overload<size_type> bid_over;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef arithmetic_0<size_type> bid_arit;

		struct multiply
		{
/*
	Set out identically equal to zero for the normal interpretation.
	Set the arguement out2=out1 for the normal interpretation.
*/
			template<typename ValueType, typename WIterator, typename WIterator1, typename WIterator2,
				typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(WIterator out, WIterator1 out1, WIterator2 out2,
				RIterator1 in1, ERIterator1 end1, RIterator2 in2, ERIterator2 end2)
			{
				while (in2 != end2)
				{
					fwd_over::repeat::no_return(out1, out2, (ValueType) 0),
					fwd_arit::assign::plus::no_return((ValueType) 0, out, out1,
						fwd_arit::scale::with_return((ValueType) 0, out2, in1, end1, *in2));
					--end1;
					++out2; ++in2;
				}
			}

			struct half
			{
/*
	Set out identically equal to zero for the normal interpretation.
	Set out2=out1 for the normal interpretation.
*/
				template<typename ValueType, typename WIterator, typename WIterator1, typename WIterator2,
					typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(WIterator out, WIterator1 out1, WIterator2 out2,
					RIterator1 in1, ERIterator1 end1, RIterator2 in2, ERIterator2 end2)
				{
					while (in2 != end2)
					{
						fwd_over::repeat::no_return(out1, out2, (ValueType) 0),
						fwd_arit::assign::plus::half::no_return((ValueType) 0, out, out1,
							fwd_arit::scale::half::with_return((ValueType) 0, out2, in1, end1, *in2));
						--end1;
						++out2; ++in2;
					}
				}
			};
		};

		struct assign
		{
			// Multiply requires a deep copy anyway, so there's no point to an assign version.
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public bwd_arit::template unroll_0<0, M, L>
		{
		};
	};
     }

     namespace random_access
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;

		typedef forward::overload<size_type> fwd_over;
		typedef backward::overload<size_type> bwd_over;
		typedef bidirectional::overload<size_type> bid_over;
		typedef overload<size_type> rnd_over;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef bidirectional::arithmetic_1<size_type> bid_arit;
		typedef arithmetic_0<size_type> rnd_arit;

		struct divide
		{
/*
	L is the specification block length of the denominator.
		2 <= L
	M is the specification block length of the numerator.
		L <= M
	N is initialized as M-L+1.

	r is the initial location of the overhead value (carry; remainder).
		To implement under the normal interpretation, copy this to be
		the leading digits of the numerator---the same length as the denominator.
	lr is the location of the leading digit of the overhead value (carry; remainder).
	q is the final location of the quotient to be determined (it works its way backwards).
	t is the initial location of a temporary used for internal computations.
		Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
	n is the digit location within the numerator following the digits already held within the remainder.
	d is the initial location of the denominator (divisor).
		Initializing the final location to zero is necessary only if (L < M); see the notes below.
	ld is the location of the leading digit of the denominator (divisor).

	Assumes (r|n) >= d, and that they are already normalized for Knuth multiple precision division optimization.

	Block length for the above arguments is conditional upon the block length of the carry,
	because the intention of the carry is to shift digits into its register until it is big enough to divide by
	the divisor. The carry length is itself conditional upon the template parameters:

	(L == M):

		r
			As (r|n) >= d then no extra digits will be shifted into r
			and so r only needs to be of block size L.
		q
			As a block it has implementation length M-L+1.
		t
			As a block it has implementation length L.
		n
			As a block it has implementation length M-L (as it is not the full numerator).
		d
			As a block it has implementation length L.

	(L < M):

		r
			This is equivalent to (L+1 <= M). No assumptions can be made as to whether or not an additional digit
			will be shifted into the register, and as such as a block it has implementation length L+1.
		q
			As a block it has implementation length M-L+1.
		t
			As a block it has implementation length L+1. It is used as memory for the value q'*d
			within the knuth_remainder subroutine, where q' is the local quotient within that iteration.
			We know that q'*d < r, but as r is of block length L+1 we have to allow for the possibility
			q'*d is of block length L+1.
		n
			As a block it has implementation length M-L (as it is not the full numerator).
		d
			As a block it has implementation length L+1. It is used to generate q'*d mapping onto
			a block length of size L+1 within the knuth_remainder subroutine, as such it needs its
			to be of the same length where its leading digit is set to zero.

	What is termed "dord" here is refactored as the compile-time constant set to value L-1.

	Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
	On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.
*/
			struct multiple_digit
			{
/*
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least three digits if (uord == 2).
	Assumes v has at least two digits.
*/
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static bool improve_quotient(ValueType & q, WIterator t, RIterator1 u, RIterator2 v, size_type uord)
				{
					ValueType tc=0;
					fwd_arit::template unroll_0<2>::scale::template no_return<ValueType&>(tc, t, v, q);

					ValueType uc=(uord == 2) ? *(u+2) : (ValueType) 0;
						// this way of using "greater_than" is a small hack.
					if (fwd_arit::template unroll_0<2>::greater_than::template fast_return(false, t, u, tc, uc))
					{
						--q;
						return true;
					}
					else return false;
				}
/*
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least 3 digits if (uord != vord).
	Assumes v has at least two digits.
*/
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void knuth_quotient(ValueType & q, WIterator t,
					RIterator1 u, RIterator2 v, size_type uord, size_type vord)
				{
					RIterator1 bu=u-1;
					if (uord == vord) q=*u / *v;
					else
					{
						q=(*u < *v) ?
							c_policy::arg_math::divide::with_return(*u, *bu, *v) :
								c_policy::unit::max_size;
						--bu;
					}

					RIterator2 bv=v-1;
					size_type buord=u-bu;
					if (improve_quotient(q, t, bu, bv, buord))
						improve_quotient(q, t, bu, bv, buord);
				}
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
	d is expected to be of size L+1 if L < M, of size L otherwise.
*/
				template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
				static WIterator2 knuth_remainder(ValueType & q,
					WIterator1 t, WIterator1 tend, WIterator2 r, WIterator2 lr, RIterator d, RIterator dend)
				{
					fwd_arit::scale::no_return((ValueType) 0, t, d, dend, q);
					fwd_arit::assign::minus::no_return((ValueType) 0, r, t, tend);

						// r < d at this point.
					return bwd_arit::zero::with_break(lr, r);
				}
/*
	no_return:
*/
				template<typename WIterator1, typename WIterator2,
					typename WIterator3, typename RIterator1, typename RIterator2>
				static void no_return(WIterator1 r, WIterator1 lr, WIterator1 rend,
					WIterator2 q, WIterator3 t, WIterator3 tend, RIterator1 n, RIterator1 nend,
						RIterator2 d, RIterator2 ld, RIterator2 dend)
				{
					size_type dord=ld-d;
					WIterator1 br=r-1;

					while (n != nend)
					{
						size_type rord=lr-r;
						if (fwd_arit::less_than::fast_return(false, r, d, rord, dord)) *q=0;
						else
						{
							knuth_quotient(*q, t, lr, ld, rord, dord);
							lr=knuth_remainder(*q, t, tend, r, lr, d, dend);
						}

						WIterator1 olr(lr);
						*bwd_over::assign::with_return(++lr, olr, br)=*n;
						--q; --n;
					}
				}

				struct half
				{
/*
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least three digits if (uord == 2).
	Assumes v has at least two digits.
*/
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static bool improve_quotient(ValueType & q, WIterator t, RIterator1 u, RIterator2 v, size_type uord)
					{
						ValueType tc=0;
						fwd_arit::template unroll_0<2>::scale::half::template no_return<ValueType&>(tc, t, v, q);

						ValueType uc=(uord == 2) ? *(u+2) : (ValueType) 0;
							// this way of using "greater_than" is a small hack.
						if (fwd_arit::template unroll_0<2>::greater_than::template fast_return(false, t, u, tc, uc))
						{
							--q;
							return true;
						}
						else return false;
					}
/*
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least 3 digits if (uord != vord).
	Assumes v has at least two digits.
*/
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void knuth_quotient(ValueType & q, WIterator t,
						RIterator1 u, RIterator2 v, size_type uord, size_type vord)
					{
						RIterator1 bu=u-1;
						if (uord == vord) q=*u / *v;
						else
						{
							q=(*u < *v) ?
								((*u<<c_policy::unit::half::length) + *bu) / *v :
									c_policy::unit::half::max_size;
							--bu;
						}

						RIterator2 bv=v-1;
						size_type buord=u-bu;
						if (improve_quotient(q, t, bu, bv, buord))
							improve_quotient(q, t, bu, bv, buord);
					}
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
	d is expected to be of size L+1 if L < M, of size L otherwise.
*/
					template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
					static WIterator2 knuth_remainder(ValueType & q,
						WIterator1 t, WIterator1 tend, WIterator2 r, WIterator2 lr, RIterator d, RIterator dend)
					{
						fwd_arit::scale::half::no_return((ValueType) 0, t, d, dend, q);
						fwd_arit::assign::minus::half::no_return((ValueType) 0, r, t, tend);

							// r < d at this point.
						return bwd_arit::zero::with_break(lr, r);
					}
/*
	no_return:
*/
					template<typename WIterator1, typename WIterator2,
						typename WIterator3, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 r, WIterator1 lr, WIterator1 rend,
						WIterator2 q, WIterator3 t, WIterator3 tend, RIterator1 n, RIterator1 nend,
							RIterator2 d, RIterator2 ld, RIterator2 dend)
					{
						size_type dord=ld-d;
						WIterator1 br=r-1;

						while (n != nend)
						{
							size_type rord=lr-r;
							if (fwd_arit::less_than::fast_return(false, r, d, rord, dord)) *q=0;
							else
							{
								knuth_quotient(*q, t, lr, ld, rord, dord);
								lr=knuth_remainder(*q, t, tend, r, lr, d, dend);
							}

							WIterator1 olr(lr);
							*bwd_over::assign::with_return(++lr, olr, br)=*n;
							--q; --n;
						}
					}
				};
			};
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public rnd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using rnd_unroll=typename rnd_arit::template unroll_0<K, J, I>;

			struct divide
			{
/*
		L is the specification block length of the denominator.
			2 <= L
		M is the specification block length of the numerator.
			L <= M
		N is initialized as M-L+1.

		r is the initial location of the overhead value (carry; remainder).
			To implement under the normal interpretation, copy this to be
			the leading digits of the numerator---the same length as the denominator.
		lr is the location of the leading digit of the overhead value (carry; remainder).
		q is the final location of the quotient to be determined (it works its way backwards).
		t is the initial location of a temporary used for internal computations.
			Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
		n is the digit location within the numerator following the digits already held within the remainder.
		d is the initial location of the denominator (divisor).
			Initializing the final location to zero is necessary only if (L < M); see the notes below.
		ld is the location of the leading digit of the denominator (divisor).

		Assumes (r|n) >= d, and that they are already normalized for Knuth multiple precision division optimization.

		Block length for the above arguments is conditional upon the block length of the carry,
		because the intention of the carry is to shift digits into its register until it is big enough to divide by
		the divisor. The carry length is itself conditional upon the template parameters:

		(L == M):

			r
				As (r|n) >= d then no extra digits will be shifted into r
				and so r only needs to be of block size L.
			q
				As a block it has implementation length M-L+1.
			t
				As a block it has implementation length L.
			n
				As a block it has implementation length M-L (as it is not the full numerator).
			d
				As a block it has implementation length L.

		(L < M):

			r
				This is equivalent to (L+1 <= M). No assumptions can be made as to whether or not an additional digit
				will be shifted into the register, and as such as a block it has implementation length L+1.
			q
				As a block it has implementation length M-L+1.
			t
				As a block it has implementation length L+1. It is used as memory for the value q'*d
				within the knuth_remainder subroutine, where q' is the local quotient within that iteration.
				We know that q'*d < r, but as r is of block length L+1 we have to allow for the possibility
				q'*d is of block length L+1.
			n
				As a block it has implementation length M-L (as it is not the full numerator).
			d
				As a block it has implementation length L+1. It is used to generate q'*d mapping onto
				a block length of size L+1 within the knuth_remainder subroutine, as such it needs its
				to be of the same length where its leading digit is set to zero.

		What is termed "dord" here is refactored as the compile-time constant set to value L-1.

		Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
		On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.
*/
				struct multiple_digit
				{
					static const size_type dord=L-1;
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
	d is expected to be of size L+1 if L < M, of size L otherwise.
*/
					template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
					static WIterator2 knuth_remainder(ValueType & q, WIterator1 t, WIterator2 r, RIterator d)
					{
						fwd_arit::template unroll_0<L+(L < M)>::scale::no_return((ValueType) 0, t, d, q);
						fwd_arit::template unroll_0<L+(L < M)>::assign::minus::no_return((ValueType) 0, r, t);

							// r < d at this point.
						return bwd_arit::zero::with_break(r+dord, r);
					}
/*
	no_return:
*/
					template<typename WIterator1, typename WIterator2,
						typename WIterator3, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 r, WIterator1 lr,
						WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
					{
						size_type rord=lr-r;
							// Use of L here is an optimization.
						if (fwd_arit::template unroll_0<L+(L < M)>::
							less_than::fast_return(false, r, d, rord, dord)) *q=0;
						else
						{
								// Use of L here is an optimization.
							arithmetic_1::divide::multiple_digit::
								knuth_quotient(*q, t, lr, ld, rord, dord);
							lr=knuth_remainder(*q, t, r, d);
						}

						WIterator1 olr(lr);
						*bwd_over::assign::with_return(++lr, olr, r-1)=*n;
						unroll_1<N-1, M, L>::divide::multiple_digit::no_return(r, lr, --q, t, --n, d, ld);
					}

					struct half
					{
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
	d is expected to be of size L+1 if L < M, of size L otherwise.
*/
						template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
						static WIterator2 knuth_remainder(ValueType & q, WIterator1 t, WIterator2 r, RIterator d)
						{
							fwd_arit::template unroll_0<L+(L < M)>::scale::
								half::no_return((ValueType) 0, t, d, q);
							fwd_arit::template unroll_0<L+(L < M)>::assign::minus::
								half::no_return((ValueType) 0, r, t);

								// r < d at this point.
							return bwd_arit::zero::with_break(r+dord, r);
						}
/*
	Debugging note: Every function call within needs to be robust against its "half" version.
*/
						template<typename WIterator1, typename WIterator2,
							typename WIterator3, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 r, WIterator1 lr,
							WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
						{
							size_type rord=lr-r;
								// Use of L here is an optimization.
							if (fwd_arit::template unroll_0<L+(L < M)>::
								less_than::fast_return(false, r, d, rord, dord)) *q=0;
							else
							{
									// Use of L here is an optimization.
								arithmetic_1::divide::multiple_digit::half::
									knuth_quotient(*q, t, lr, ld, rord, dord);
								lr=knuth_remainder(*q, t, r, d);
							}

							WIterator1 olr(lr);
							*bwd_over::assign::with_return(++lr, olr, r-1)=*n;
							unroll_1<N-1, M, L>::divide::multiple_digit::
								half::no_return(r, lr, --q, t, --n, d, ld);
						}
					};
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public rnd_arit::template unroll_0<0, M, L>
		{
			struct divide
			{
				struct multiple_digit
				{
					template<typename WIterator1, typename WIterator2,
						typename WIterator3, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 r, WIterator1 lr,
						WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
							{ }

					struct half
					{
						template<typename WIterator1, typename WIterator2,
							typename WIterator3, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 r, WIterator1 lr,
							WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
								{ }
					};
				};
			};
		};
	};
     }
    }
   }
  }
 }
}

#endif
