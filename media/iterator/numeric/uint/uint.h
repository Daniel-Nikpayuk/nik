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

#ifndef MEDIA_ITERATOR_UINT_H
#define MEDIA_ITERATOR_UINT_H

#include"../../../../context/context/constant.h"
#include"../../../../context/media/iterator/policy/policy.h"
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
				template<typename SizeType>
				struct uint
				{
/*
	block:
		Need to fix the BlockSize calculation to account for a BitLength which isn't divisible by the register_length.
		For example one could round up to the nearest multiple of the register_length.

		It actually might be worthwhile keeping BlockSize as a separate template parameter, as it is possible someone
		might want to subclass this and come up with their own BlockSize for their own reason.
*/
					template<SizeType BitLength, SizeType BlockSize=
						BitLength/context::meta::constant<SizeType>::register_length>
					class block : protected semiotic::iterator::block<SizeType, SizeType, BlockSize>
					{
						protected:
							typedef context::iterator::policy generic;

							typedef typename generic::fwd_arit<SizeType> fwd_arit;
							typedef typename generic::fwd_arit_unroll<SizeType, BlockSize> fwd_arit_unroll;
							typedef typename generic::
								fwd_arit_subroll<SizeType, BlockSize, BlockSize> fwd_arit_subroll;
							friend fwd_arit;

							typedef typename generic::bwd_arit<SizeType> bwd_arit;
							typedef typename generic::bwd_arit_unroll<SizeType, BlockSize> bwd_arit_unroll;
							friend bwd_arit;

							typedef typename generic::bdl_arit<SizeType> bdl_arit;
							friend bdl_arit;

							typedef typename generic::fwd_recu_unroll<SizeType, BlockSize-1> fwd_recu_decroll;
							typedef typename generic::fwd_recu_unroll<SizeType, BlockSize> fwd_recu_unroll;
						protected:
							typedef semiotic::iterator::block<SizeType, SizeType, BlockSize> subblock;
							typedef typename subblock::value_type value_type;
							typedef typename subblock::reference reference;
							typedef typename subblock::const_reference const_reference;
							typedef typename subblock::pointer pointer;
							typedef typename subblock::const_pointer const_pointer;
							typedef typename subblock::iterator iterator;
							typedef typename subblock::const_iterator const_iterator;
							typedef typename subblock::size_type size_type;
						public:
							static const size_type dimension=BlockSize;
							static const size_type register_length=
								context::meta::constant<size_type>::register_length;
/*
	Note: A null-initialization does not set the initial value (to 0 or otherwise).
*/
							block() : subblock() { }
							block(size_type n) : subblock()
							{
								*subblock::array=n;
								fwd_recu_decroll::repeat(subblock::array+1, 0);
							}
							block(const block & b) : subblock(b) { }
							const block operator = (const block & b)
							{
								subblock::terminalize();
								subblock::copy(b);
								return *this;
							}
						public:
								// iterators:
							iterator begin() { return subblock::array; }
							const_iterator begin() const { return subblock::array; }
							const_iterator cbegin() const { return subblock::array; }
							iterator end() { return subblock::array+dimension; }
							const_iterator end() const { return subblock::array+dimension; }
							const_iterator cend() const { return subblock::array+dimension; }
						public:
							bool operator == (const block & b) const
								{ return fwd_arit_unroll::equal(subblock::array, b.array); }
							bool operator != (const block & b) const
								{ return fwd_arit_unroll::not_equal(subblock::array, b.array); }
							bool operator < (const block & b) const
								{ return bwd_arit_unroll::
									less_than(subblock::array+(dimension-1), b.array+(dimension-1)); }
							bool operator <= (const block & b) const
								{ return bwd_arit_unroll::
									less_than_or_equal(subblock::array+(dimension-1),
										b.array+(dimension-1)); }
							bool operator > (const block & b) const
								{ return bwd_arit_unroll::
									greater_than(subblock::array+(dimension-1), b.array+(dimension-1)); }
							bool operator >= (const block & b) const
								{ return bwd_arit_unroll::
									greater_than_or_equal(subblock::array+(dimension-1),
										b.array+(dimension-1)); }
						public:
/*
	m is the bit length, not the array length.
*/
							block operator << (size_type m) const
							{
								size_type arr_dim(m/register_length), bit_dim(m%register_length);

								block out;
								if (arr_dim >= dimension) fwd_recu_unroll::repeat(out.array, 0);
								else bdl_arit::left_shift_assign(out.array, dimension, arr_dim, bit_dim);
								return out;
							}
/*
	m is the bit length, not the array length.
*/
							block operator >> (size_type m) const
							{
								size_type arr_dim(m/register_length), bit_dim(m%register_length);

								block out;
								if (arr_dim >= dimension) fwd_recu_unroll::repeat(out.array, 0);
								else bdl_arit::right_shift_assign(out.array, dimension, arr_dim, bit_dim);
								return out;
							}
						public:
							block operator + (const block & b) const
							{
								block out;
								fwd_arit_unroll::plus(out.array, subblock::array, b.array, 0);
								return out;
							}

							block operator - (const block & b) const
							{
								block out;
								fwd_arit_unroll::minus(out.array, subblock::array, b.array, 0);
								return out;
							}

							block operator * (size_type b) const
							{
								block out;
								fwd_arit_unroll::scale(out.array, subblock::array, b, (size_type) 0);
								return out;
							}

							block operator * (const block & b) const
							{
								block out, tmp;
								fwd_recu_unroll::repeat(out.array, 0);
								fwd_arit_subroll::asterisk(out.array, tmp.array, subblock::array, b.array);
								return out;
							}
					};
				};
			}

			template<size_t BitLength>
			using uint_block=numeric::uint<size_t>::block<BitLength>;
		}
	}
}

#endif
