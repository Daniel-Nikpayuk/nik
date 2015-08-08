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

#ifndef CONTEXT_POINTER_ITERATOR_H
#define CONTEXT_POINTER_ITERATOR_H

namespace nik
{
	namespace context
	{
		struct pointer_iterator
		{
/*
			pointer_iterator:
				A pointer_iterator assumes access to any class satisfying a pointer concept.
				The minimal specification (axiomatic properties) of a pointer_iterator are:
				typedefs:
					const_/reference;
					const_/pointer;
				constructors:
					pointer_iterator(const_/pointer);
				accessors:
					const_/pointer address()/ const;
*/
/*
			overload:
				38 operators referenced from: http://en.cppreference.com/w/cpp/language/operators
*/
/*
	+:
			template<typename OutputType, typename InputType>
			static OutputType plus(InputType x) { return +x; }
*/
			template<typename Iterator, typename SizeType>
			static Iterator plus(const Iterator & i, SizeType n) { return Iterator(&i+n); }
/*
	-:
			template<typename OutputType, typename InputType>
			static OutputType minus(InputType x) { return -x; }
*/
			template<typename Iterator, typename SizeType>
			static Iterator minus(const Iterator & i, SizeType n) { return Iterator(&i-n); }
/*
			Requires explicitly specifying the template parameter as type deduction will fail.
*/
			template<typename SizeType, typename Iterator>
			static SizeType minus(const Iterator & i, const Iterator & j) { return &i-&j; }
/*
	*:
*/
			template<typename Iterator>
			static typename Iterator::reference asterisk(Iterator & i) { return *&i; }
/*
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType asterisk(InputType1 x, InputType2 y) { return x*y; }
*/
/*
	/:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType slash(InputType1 x, InputType2 y) { return x/y; }
*/
/*
	%:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType percent(InputType1 x, InputType2 y) { return x%y; }
*/
/*
	ˆ:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType caret(InputType1 x, InputType2 y) { return x^y; }
*/
/*
	&:
			template<typename OutputType, typename InputType>
			static OutputType ampersand(InputType x) { return &x; }

			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType ampersand(InputType1 x, InputType2 y) { return x&y; }
*/
/*
	|:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType bar(InputType1 x, InputType2 y) { return x|y; }
*/
/*
	~:
			template<typename OutputType, typename InputType>
			static OutputType tilde(InputType x) { return ~x; }
*/
/*
	!:
			template<typename OutputType, typename InputType>
			static OutputType exclamation(InputType x) { return !x; }
*/
/*
	=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType assign(InputType1 x, InputType2 y) { return x=y; }
*/
/*
	<:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType less_than(InputType1 x, InputType2 y) { return x<y; }
*/
/*
	>:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType greater_than(InputType1 x, InputType2 y) { return x>y; }
*/
/*
	+=:
*/
			template<typename Iterator, typename SizeType>
			static Iterator & plus_assign(Iterator & i, SizeType n) { return i=Iterator(&i+n); }
/*
	-=:
*/
			template<typename Iterator, typename SizeType>
			static Iterator & minus_assign(Iterator & i, SizeType n) { return i=Iterator(&i-n); }
/*
	*=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType asterisk_assign(InputType1 x, InputType2 y) { return x*=y; }
*/
/*
	/=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType slash_assign(InputType1 x, InputType2 y) { return x/=y; }
*/
/*
	%=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType percent_assign(InputType1 x, InputType2 y) { return x%=y; }
*/
/*
	ˆ=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType caret_assign(InputType1 x, InputType2 y) { return x^=y; }
*/
/*
	&=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType ampersand_assign(InputType1 x, InputType2 y) { return x&=y; }
*/
/*
	|=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType bar_assign(InputType1 x, InputType2 y) { return x|=y; }
*/
/*
	<<:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType left_shift(InputType1 x, InputType2 y) { return x<<y; }
*/
/*
	>>:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType right_shift(InputType1 x, InputType2 y) { return x>>y; }
*/
/*
	>>=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType right_shift_assign(InputType1 x, InputType2 y) { return x>>=y; }
*/
/*
	<<=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType left_shift_assign(InputType1 x, InputType2 y) { return x<<=y; }
*/
/*
	==:
			Can probably defer this function to the simplest iterator type (as all iterator types should
			have the "address()" (&) method. As it is static I don't mind a bit of redundancy.
*/
			template<typename Iterator>
			static bool equals(const Iterator & i, const Iterator & j) { return &i == &j; }
/*
	!=:
*/
			template<typename Iterator>
			static bool not_equals(const Iterator & i, const Iterator & j) { return &i != &j; }
/*
	<=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType less_than_or_equal(InputType1 x, InputType2 y) { return x<=y; }
*/
/*
	>=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType greater_than_or_equal(InputType1 x, InputType2 y) { return x>=y; }
*/
/*
	&&:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType logical_and(InputType1 x, InputType2 y) { return x&&y; }
*/
/*
	||:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType logical_or(InputType1 x, InputType2 y) { return x||y; }
*/
/*
	++:
*/
			template<typename Iterator>
			static Iterator & left_increment(Iterator & i) { return i=Iterator(&i+1); }

			template<typename Iterator>
			static Iterator right_increment(Iterator & i) { Iterator j=i; i=Iterator(&i+1); return j; }
/*
	--:
*/
			template<typename Iterator>
			static Iterator & left_decrement(Iterator & i) { return i=Iterator(&i-1); }

			template<typename Iterator>
			static Iterator right_decrement(Iterator & i) { Iterator j=i; i=Iterator(&i-1); return j; }
/*
	,:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType comma(InputType1 x, InputType2 y) { return x,y; }
*/
/*
	->*:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType point_asterisk(InputType1 x, InputType2 y) { return x->*y; }
*/
/*
	->:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType point(InputType1 x, InputType2 y) { return x->y; }
*/
/*
	():
			template<typename OutputType, typename InputType>
			static OutputType parentheses(InputType x) { return x(); }
*/
/*
	[]:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType brackets(InputType1 x, InputType2 y) { return x[y]; }
*/
		};
	}
}

#endif
