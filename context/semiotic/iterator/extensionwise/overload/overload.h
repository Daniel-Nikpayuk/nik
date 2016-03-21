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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_H
#define CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_H

// overhead dependencies:

#include"overload_macro.h"

#include"../../../context/policy/policy.h"

/*
	overload: 38 operators referenced from: http://en.cppreference.com/w/cpp/language/operators

	Overload operators are similar enough to factorize and pass the specific operator
	as a method, but it is more cpu efficient to NOT---especially given there are few practical
	contexts in which many different such operators will all be used together.

	"Side effects" at the general coder level is bad policy, but at this intended low level
	where safety is minimal it is more memory efficient given the dynamic size of arrays.

	iterator:
		The minimal specification (axiomatic properties) of an iterator are:
		typedefs:
		constructors:
		accessors:

	For iterators in general, references are a derived type,
	but for compatibility with pointers no specific instance of a derived type is assumed.

	Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
	entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
	As far as debugging goes, keep in mind the location of an array (as pointer) is c_policy::unit and thus not
	allowed as a reference, so for example if you declare "int array[100]" you can't pass "array" directly
	if you're template parameter is specified as a variable. Instead you need to make a copy of array:
		"int *a=array", so then you can pass "a" instead.

	Strictly speaking, there are infinitely many different methods of each overload type based on side effects.

	If there is no "with_return" variant of a given method, it means it has and "end"
	parameter which is already equivalent to such a returned value. Would be redundant.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace extensionwise
    {
     namespace forward
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct plus
		{
			no_return_1(+, =+)
			with_return_1(+, =+)

			no_return_2(+, +)
			with_return_2(+, +)
		};
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct minus
		{
			no_return_1(+, =-)
			with_return_1(+, =-)

			no_return_2(+, -)
			with_return_2(+, -)
		};
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct asterisk
		{
			no_return_1(+, =*)
			with_return_1(+, =*)

			no_return_2(+, *)
			with_return_2(+, *)
		};
/*
	/:
*/
		struct slash
		{
			no_return_2(+, /)
			with_return_2(+, /)
		};
/*
	%:
*/
		struct percent
		{
			no_return_2(+, %)
			with_return_2(+, %)
		};
/*
	ˆ:
*/
		struct caret
		{
			no_return_2(+, ^)
			with_return_2(+, ^)
		};
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct ampersand
		{
			no_return_1(+, =&)
			with_return_1(+, =&)

			no_return_2(+, &)
			with_return_2(+, &)
		};
/*
	|:
*/
		struct bar
		{
			no_return_2(+, |)
			with_return_2(+, |)
		};
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct tilde
		{
			no_return_1(+, =~)
			with_return_1(+, =~)
		};
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct exclamation
		{
			no_return_1(+, =!)
			with_return_1(+, =!)
		};
/*
	<:
*/
		struct less_than
		{
			no_return_2(+, <)
			with_return_2(+, <)
		};
/*
	>:
*/
		struct greater_than
		{
			no_return_2(+, >)
			with_return_2(+, >)
		};
/*
	<<:
*/
		struct left_shift
		{
			no_return_2(+, <<)
			with_return_2(+, <<)
		};
/*
	>>:
*/
		struct right_shift
		{
			no_return_2(+, >>)
			with_return_2(+, >>)
		};
/*
	==:
*/
		struct equals
		{
			no_return_2(+, ==)
			with_return_2(+, ==)
		};
/*
	!=:
*/
		struct not_equals
		{
			no_return_2(+, !=)
			with_return_2(+, !=)
		};
/*
	<=:
*/
		struct less_than_or_equal
		{
			no_return_2(+, <=)
			with_return_2(+, <=)
		};
/*
	>=:
*/
		struct greater_than_or_equal
		{
			no_return_2(+, >=)
			with_return_2(+, >=)
		};
/*
	&&:
*/
		struct logical_and
		{
			no_return_2(+, &&)
			with_return_2(+, &&)
		};
/*
	||:
*/
		struct logical_or
		{
			no_return_2(+, ||)
			with_return_2(+, ||)
		};
/*
	++:
*/
		struct left_increment
		{
			no_return_left_0(+, ++)
		};

		struct right_increment
		{
			no_return_right_0(+, ++)
		};
/*
	--:
*/
		struct left_decrement
		{
			no_return_left_0(+, --)
		};

		struct right_decrement
		{
			no_return_right_0(+, --)
		};
/*
	,:
*/
		struct comma
		{
		};
/*
	->*:
*/
		struct point_asterisk
		{
			no_return_2(+, ->*)
			with_return_2(+, ->*)
		};
/*
	->:
*/
		struct point
		{
			with_return_2(+, .operator->)
		};
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
		struct parentheses
		{
			no_return_right_0(+, ())

			no_return_right_1(+, =, ())
			with_return_right_1(+, =, ())

			no_return_2(+, )
			with_return_2(+, )
		};
/*
	[]:
*/
		struct brackets
		{
			no_return_bracket_2(+, )
			with_return_bracket_2(+, )
		};
/*
	There's no need for a "return" version of "c_policy::unit value" assign as the out iterator equals the end iterator upon halting.
*/
		struct repeat
		{
/*
		=:
*/
			no_return_0(+, =)
/*
		+=:
*/
			struct plus
			{
				no_return_0(+, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_0(+, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_0(+, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_0(+, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_0(+, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_0(+, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_0(+, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_0(+, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_0(+, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_0(+, <<=)
			};
		};

		struct assign
		{
/*
		=:
*/
			no_return_1(+, =)
			with_return_1(+, =)
/*
		+=:
*/
			struct plus
			{
				no_return_1(+, +=)
				with_return_1(+, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_1(+, -=)
				with_return_1(+, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_1(+, *=)
				with_return_1(+, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_1(+, /=)
				with_return_1(+, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_1(+, %=)
				with_return_1(+, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_1(+, ^=)
				with_return_1(+, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_1(+, &=)
				with_return_1(+, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_1(+, |=)
				with_return_1(+, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_1(+, >>=)
				with_return_1(+, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_1(+, <<=)
				with_return_1(+, <<=)
			};
		};

		struct convert
		{
		};
/*
	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "extend" struct. Notice the semantics of the word "extend"
			itself are a signifier of the overhead word space, which is to say it's a metaname.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
			struct right_shift
			{
			};

			struct repeat
			{
/*
*/
				template<typename WPointer, typename ValueType>
				static void no_return(WPointer out, ValueType in)
				{
					out=+out=new WPointer();
					*out=in;
					unroll<N-1>::repeat::no_return(++out, in);
				}
/*
*/
				template<typename WIterator, typename ValueType>
				static WIterator with_return(WIterator out, ValueType in)
				{
					out=+out=new WPointer();
					*out=in;
					return unroll<N-1>::repeat::with_return(++out, in);
				}
			};
/*
*/
			struct assign
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
				{
					out=+out=new WPointer();
					*out=*in;
					unroll<N-1>::assign::no_return(++out, ++in);
				}
/*
*/
				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
				{
					out=+out=new WPointer();
					*out=*in;
					return unroll<N-1>::assign::with_return(++out, ++in);
				}

				struct right_shift
				{
				};
			};
/*
	Not fully satisfied with the categorization or naming scheme within this library.
*/
			struct convert
			{
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
/*
*/
			struct right_shift
			{
			};

			struct repeat
			{
				template<typename WIterator, typename ValueType>
				static void no_return(WIterator out, ValueType in)
					{ }

				template<typename WIterator, typename ValueType>
				static WIterator with_return(WIterator out, ValueType in)
					{ return out; }
			};

			struct assign
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
					{ }

				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
					{ return out; }
/*
	Does not perform adding (*in<<n) as in2 may be past the boundary.
*/
				struct right_shift
				{
				};
			};

			struct convert
			{
			};
		};
	};
     }

/************************************************************************************************************************/

     namespace backward
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct plus
		{
			no_return_1(-, =+)
			with_return_1(-, =+)

			no_return_2(-, +)
			with_return_2(-, +)
		};
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct minus
		{
			no_return_1(-, =-)
			with_return_1(-, =-)

			no_return_2(-, -)
			with_return_2(-, -)
		};
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct asterisk
		{
			no_return_1(-, =*)
			with_return_1(-, =*)

			no_return_2(-, *)
			with_return_2(-, *)
		};
/*
	/:
*/
		struct slash
		{
			no_return_2(-, /)
			with_return_2(-, /)
		};
/*
	%:
*/
		struct percent
		{
			no_return_2(-, %)
			with_return_2(-, %)
		};
/*
	ˆ:
*/
		struct caret
		{
			no_return_2(-, ^)
			with_return_2(-, ^)
		};
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct ampersand
		{
			no_return_1(-, =&)
			with_return_1(-, =&)

			no_return_2(-, &)
			with_return_2(-, &)
		};
/*
	|:
*/
		struct bar
		{
			no_return_2(-, |)
			with_return_2(-, |)
		};
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct tilde
		{
			no_return_1(-, =~)
			with_return_1(-, =~)
		};
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct exclamation
		{
			no_return_1(-, =!)
			with_return_1(-, =!)
		};
/*
	<:
*/
		struct less_than
		{
			no_return_2(-, <)
			with_return_2(-, <)
		};
/*
	>:
*/
		struct greater_than
		{
			no_return_2(-, >)
			with_return_2(-, >)
		};
/*
	<<:
*/
		struct left_shift
		{
			no_return_2(-, <<)
			with_return_2(-, <<)
		};
/*
	>>:
*/
		struct right_shift
		{
			no_return_2(-, >>)
			with_return_2(-, >>)
		};
/*
	==:
*/
		struct equals
		{
			no_return_2(-, ==)
			with_return_2(-, ==)
		};
/*
	!=:
*/
		struct not_equals
		{
			no_return_2(-, !=)
			with_return_2(-, !=)
		};
/*
	<=:
*/
		struct less_than_or_equal
		{
			no_return_2(-, <=)
			with_return_2(-, <=)
		};
/*
	>=:
*/
		struct greater_than_or_equal
		{
			no_return_2(-, >=)
			with_return_2(-, >=)
		};
/*
	&&:
*/
		struct logical_and
		{
			no_return_2(-, &&)
			with_return_2(-, &&)
		};
/*
	||:
*/
		struct logical_or
		{
			no_return_2(-, ||)
			with_return_2(-, ||)
		};
/*
	++:
*/
		struct left_increment
		{
			no_return_left_0(-, ++)
		};

		struct right_increment
		{
			no_return_right_0(-, ++)
		};
/*
	--:
*/
		struct left_decrement
		{
			no_return_left_0(-, --)
		};

		struct right_decrement
		{
			no_return_right_0(-, --)
		};
/*
	,:
*/
		struct comma
		{
		};

/*
	->*:
*/
		struct point_asterisk
		{
			no_return_2(-, ->*)
			with_return_2(-, ->*)
		};
/*
	->:
*/
		struct point
		{
			with_return_2(-, .operator->)
		};
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
		struct parentheses
		{
			no_return_right_0(-, ())

			no_return_right_1(-, =, ())
			with_return_right_1(-, =, ())

			no_return_2(-, )
			with_return_2(-, )
		};
/*
	[]:
*/
		struct brackets
		{
			no_return_bracket_2(-, )
			with_return_bracket_2(-, )
		};
/*
	There's no need for a "return" version of "c_policy::unit value" assign as the out iterator equals the end iterator upon halting.

	There is the concern where EIterator "end" needs to be beyond the initial iterator address of the structure.
	In the case of a user-defined iterator class, the details of implementation informs such a discussion.
	In the case of a C++ array, I assume modular arithmetic applies to the iterator (pointer). In this case,
	as far as I've read nothing states that the array address can't start with the zero address, but even in that case (0-1 == -1)
	the algorithm will still halt accordingly. The only issue then is if the WIterator is a reference type, as the iterator
	then might halt in an unexpected position. Of course if one was expecting address array-1, they would know in advance not to
	dereference there, and would still need to increment to access valid data. As such there still should be no issue.
*/
		struct repeat
		{
/*
		=:
*/
			no_return_0(-, =)
/*
		+=:
*/
			struct plus
			{
				no_return_0(-, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_0(-, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_0(-, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_0(-, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_0(-, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_0(-, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_0(-, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_0(-, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_0(-, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_0(-, <<=)
			};
		};

		struct assign
		{
/*
		=:
*/
			no_return_1(-, =)
			with_return_1(-, =)
/*
		+=:
*/
			struct plus
			{
				no_return_1(-, +=)
				with_return_1(-, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_1(-, -=)
				with_return_1(-, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_1(-, *=)
				with_return_1(-, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_1(-, /=)
				with_return_1(-, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_1(-, %=)
				with_return_1(-, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_1(-, ^=)
				with_return_1(-, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_1(-, &=)
				with_return_1(-, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_1(-, |=)
				with_return_1(-, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_1(-, >>=)
				with_return_1(-, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_1(-, <<=)
				with_return_1(-, <<=)
			};
		};

/*
	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "extend" struct. Notice the semantics of the word "extend"
			itself are a signifier of the overhead word space, which is to say it's a metaname.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = c_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1<<m); }.
	Do not add (*in2>>n) as in this specialization, in2 may be past the boundary.
*/
			struct left_shift
			{
			};

			struct repeat
			{
/*
*/
				template<typename WIterator, typename ValueType>
				static void no_return(WIterator out, ValueType in)
				{
					out=-out=new WPointer();
					*out=in;
					unroll<N-1>::repeat::no_return(--out, in);
				}
/*
*/
				template<typename WIterator, typename ValueType>
				static WIterator with_return(WIterator out, ValueType in)
				{
					out=-out=new WPointer();
					*out=in;
					return unroll<N-1>::repeat::with_return(--out, in);
				}
			};
/*
*/
			struct assign
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
				{
					out=-out=new WPointer();
					*out=*in;
					unroll<N-1>::assign::no_return(--out, --in);
				}
/*
*/
				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
				{
					out=-out=new WPointer();
					*out=*in;
					return unroll<N-1>::assign::with_return(--out, --in);
				}
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = ++RIterator(in1),
	as well as n = c_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out<<=m); }.
	Do not add (*in>>n) as in this specialization, in2 may be past the boundary.
*/
				struct left_shift
				{
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
/*
	Does not perform adding (*in2>>n) as in2 may be past the boundary.
*/
			struct left_shift
			{
			};

			struct repeat
			{
				template<typename WIterator, typename ValueType>
				static void no_return(WIterator out, ValueType in)
					{ }

				template<typename WIterator, typename ValueType>
				static WIterator with_return(WIterator out, ValueType in)
					{ return out; }
			};

			struct assign
			{
				template<typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in)
					{ }

				template<typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in)
					{ return out; }
/*
	Does not perform adding (*in>>n) as in2 may be past the boundary.
*/
				struct left_shift
				{
				};
			};
		};
	};
     }

/************************************************************************************************************************/

     namespace bidirectional
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
     }

/************************************************************************************************************************/

     namespace random_access
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
	};
     }
    }
   }
  }
 }
}

#undef CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_MACRO_H

#endif
