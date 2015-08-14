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

#ifndef MEDIA_ITERATOR_BLOCK_H
#define MEDIA_ITERATOR_BLOCK_H

#include"../../../../context/context/constant.h"
#include"../../../../context/media/iterator/arithmetic/arithmetic.h"
#include"../../../../semiotic/iterator/block/block.h"

/*
	The design of block requires deciding whether or not the base of representation should be part of the template
	parameter or a modifiable member within the class.

	If it were a modifiable member, then block would require native support for base conversion, whereas if it were
	a template parameter, to change base would be to instantiate a new template class with the new base and convert. At the
	same time, conversion itself is built upon basic operators such as addition and multiplication of these block
	objects. Such operations break the rule of simplicity (type dispatches increase complexity and decrease efficiency).

	Given these considerations I have decided to add the base as a template parameter.
*/

namespace nik
{
	namespace media
	{
		namespace iterator
		{
			namespace numeric
			{
/*
	_block:
*/
				template<typename SizeType, SizeType BlockSize>
				class _block : protected semiotic::iterator::block<SizeType, SizeType, BlockSize>
				{
					protected:
						typedef context::iterator::arithmetic<SizeType> arithmetic;
						friend arithmetic;
						typedef typename arithmetic::template unroll<BlockSize> method;
						typedef typename arithmetic::template unroll<BlockSize-1> submethod;
						typedef semiotic::iterator::block<SizeType, SizeType, BlockSize> block;
						typedef typename block::pointer pointer;
						typedef typename block::const_pointer const_pointer;
					public:
						typedef typename block::value_type value_type;
						typedef typename block::reference reference;
						typedef typename block::const_reference const_reference;
						typedef typename block::iterator iterator;
						typedef typename block::const_iterator const_iterator;
						typedef typename block::size_type size_type;
					public:
						static const size_type dimension=BlockSize;

						_block() : block() { }
						_block(size_type n) : block()
						{
							*block::array=n;
							submethod::assign(block::array+1, 0);
						}
						_block(const _block & b) : block(b) { }
						const _block operator = (const _block & b)
						{
							block::terminalize();
							block::copy(b);
							return *this;
						}
					public:
							// iterators:
						iterator begin() { return block::array; }
						const_iterator begin() const { return block::array; }
						const_iterator cbegin() const { return block::array; }
						iterator end() { return block::array+BlockSize; }
						const_iterator end() const { return block::array+BlockSize; }
						const_iterator cend() const { return block::array+BlockSize; }
					public:
						bool operator == (const _block & b) const
							{ return method::equal(block::array, b.array); }
						bool operator != (const _block & b) const
							{ return method::not_equal(block::array, b.array); }
						bool operator < (const _block & b) const
							{ return method::
								less_than(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator <= (const _block & b) const
							{ return method::
								less_than_or_equal(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator > (const _block & b) const
							{ return method::
								greater_than(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator >= (const _block & b) const
							{ return method::
								greater_than_or_equal(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
					public:
							// recode this using the non-assign version for better efficiency.
						_block operator << (size_type m) const
						{
							m%=BlockSize;
							_block out(*this); // ***
							arithmetic::left_shift_assign(out.array, BlockSize, m);
							return out;
						}
							// recode this using the non-assign version for better efficiency.
						_block operator >> (size_type m) const
						{
							m%=BlockSize;
							_block out(*this); // ***
							arithmetic::right_shift_assign(out.array, BlockSize, m);
							return out;
						}
					public:
						_block operator + (const _block & b) const
						{
							_block out;
							method::plus(out.array, block::array, b.array, 0);
							return out;
						}

						_block operator * (size_type b) const
						{
							_block out;
							method::scale(out.array, block::array, b, (size_type) 0);
							return out;
						}

						_block operator * (const _block & b) const
						{
							_block out, tmp;
							method::assign(out.array, 0);
							method::template subroll<BlockSize>::
								asterisk(out.array, tmp.array, block::array, b.array);
							return out;
						}
				};
			}

			template<size_t BitLength>
			using block=numeric::_block<size_t, BitLength/context::meta::constant<size_t>::register_length>;
		}
	}
}

#endif
