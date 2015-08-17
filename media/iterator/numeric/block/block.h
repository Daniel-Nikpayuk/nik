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
	Restructure these typedefs as "traits" to be modular and reusable for the whole library.
*/
				template<typename SizeType>
				struct _block_traits
				{
/*
	forward:
*/
					typedef context::iterator::forward::arithmetic<SizeType> forward_arithmetic;
					typedef typename forward_arithmetic::template unroll<BlockSize-1> forw_arith_decroll;
					typedef typename forward_arithmetic::template unroll<BlockSize> forw_arith_unroll;
					typedef typename forw_arith_unroll::template subroll<BlockSize> forw_arith_subroll;

					typedef context::iterator::forward::recursive<SizeType> forward_recursive;
					typedef typename forward_recursive::template unroll<BlockSize-1> forw_rec_decroll;
					typedef typename forward_recursive::template unroll<BlockSize> forw_rec_unroll;
/*
	backward:
*/
					typedef context::iterator::backward::arithmetic<SizeType> backward_arithmetic;
					typedef typename backward_arithmetic::template unroll<BlockSize-1> back_arith_decroll;
					typedef typename backward_arithmetic::template unroll<BlockSize> back_arith_unroll;
					typedef typename back_arith_unroll::template subroll<BlockSize> back_arith_subroll;

					typedef context::iterator::backward::recursive<SizeType> backward_recursive;
					typedef typename backward_recursive::template unroll<BlockSize-1> back_rec_decroll;
					typedef typename backward_recursive::template unroll<BlockSize> back_rec_unroll;
/*
	bidirectional:
*/
					typedef context::iterator::bidirectional::arithmetic<SizeType> bidirectional_arithmetic;
					typedef typename bidirectional_arithmetic::template unroll<BlockSize-1> bidir_arith_decroll;
					typedef typename bidirectional_arithmetic::template unroll<BlockSize> bidir_arith_unroll;
					typedef typename bidir_arith_unroll::template subroll<BlockSize> bidir_arith_subroll;

					typedef context::iterator::bidirectional::recursive<SizeType> bidirectional_recursive;
					typedef typename bidirectional_recursive::template unroll<BlockSize-1> bidir_rec_decroll;
					typedef typename bidirectional_recursive::template unroll<BlockSize> bidir_rec_unroll;
				};
/*
	_block:
*/
				template<typename SizeType, SizeType BlockSize>
				class _block : protected semiotic::iterator::block<SizeType, SizeType, BlockSize>
				{
					protected:
						typedef context::iterator::traits<SizeType> generic;
						friend generic::forward_arithmetic;
						friend generic::backward_arithmetic;
						friend generic::bidirectional_arithmetic;
					protected:
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
							frec_decroll::repeat(block::array+1, 0);
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
							{ return arith_unroll::equal(block::array, b.array); }
						bool operator != (const _block & b) const
							{ return arith_unroll::not_equal(block::array, b.array); }
						bool operator < (const _block & b) const
							{ return arith_unroll::
								less_than(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator <= (const _block & b) const
							{ return arith_unroll::
								less_than_or_equal(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator > (const _block & b) const
							{ return arith_unroll::
								greater_than(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
						bool operator >= (const _block & b) const
							{ return arith_unroll::
								greater_than_or_equal(block::array+(BlockSize-1), b.array+(BlockSize-1)); }
					public:
							// recode this using the non-assign version for better efficiency.
						_block operator << (size_type m) const
						{
							_block out(*this); // ***
							if (m > BlockSize) componentwise::repeat(out.array, BlockSize, m);
							else arithmetic::left_shift_assign(out.array, BlockSize, m);
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
							arith_unroll::plus(out.array, block::array, b.array, 0);
							return out;
						}

						_block operator * (size_type b) const
						{
							_block out;
							arith_unroll::scale(out.array, block::array, b, (size_type) 0);
							return out;
						}

						_block operator * (const _block & b) const
						{
							_block out, tmp;
							arith_unroll::assign(out.array, 0);
							arith_unroll::template subroll<BlockSize>::
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
