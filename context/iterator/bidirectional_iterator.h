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

#ifndef CONTEXT_BIDIRECTIONAL_ITERATOR_H
#define CONTEXT_BIDIRECTIONAL_ITERATOR_H

#include"forward_iterator.h"

namespace nik
{
	namespace context
	{
		struct bidirectional_iterator : public forward_iterator
		{
/*
	+:
			template<typename OutputType, typename InputType>
			static OutputType plus(InputType x) { return +x; }
*/
			template<typename Iterator, typename SizeType>
			static Iterator plus(Iterator i, SizeType n)
			{
				for (SizeType k(0); k != n; ++k) ++i;
				return i;
			}
/*
	-:
			template<typename OutputType, typename InputType>
			static OutputType minus(InputType x) { return -x; }

			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType minus(InputType1 x, InputType2 y) { return x-y; }
*/
			template<typename Iterator, typename SizeType>
			static Iterator minus(Iterator i, SizeType n)
			{
				for (SizeType k(0); k != n; ++k) --i;
				return i;
			}
/*
	*:
			template<typename OutputType, typename InputType>
			static OutputType asterisk(InputType x) { return *x; }

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
			static Iterator & plus_assign(Iterator & i, SizeType n)
			{
				for (SizeType k(0); k != n; ++k) ++i;
				return i;
			}
/*
	-=:
*/
			template<typename Iterator, typename SizeType>
			static Iterator & minus_assign(Iterator & i, SizeType n)
			{
				for (SizeType k(0); k != n; ++k) --i;
				return i;
			}
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
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType equals(InputType1 x, InputType2 y) { return x==y; }
*/
/*
	!=:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType not_equals(InputType1 x, InputType2 y) { return x!=y; }
*/
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
			template<typename OutputType, typename InputType>
			static OutputType left_increment(InputType x) { return ++x; }

			template<typename OutputType, typename InputType>
			static OutputType right_increment(InputType x) { return x++; }
*/
/*
	--:
			template<typename OutputType, typename InputType>
			static OutputType left_decrement(InputType x) { return --x; }

			template<typename OutputType, typename InputType>
			static OutputType right_decrement(InputType x) { return x--; }
*/
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
/*
	decrement assign:
		This method is primarily useful in shifting values to the right.  Note that "in" and "end" are opposites (in > end).
*/
			template<typename OutputIterator, typename InputIterator>
			static OutputIterator decrement_assign(OutputIterator out, InputIterator in, const InputIterator end)
				{ while (in != end) *(out--)=*(in--); return out; }
		};
	}
}

#endif
