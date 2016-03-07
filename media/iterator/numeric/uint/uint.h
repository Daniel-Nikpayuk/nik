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

#ifndef MEDIA_ITERATOR_UINT_H
#define MEDIA_ITERATOR_UINT_H

#include"../../../../context/context/argument/math/math.h"
#include"../../../../context/semiotic/iterator/policy/policy.h"
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
/*
	If you don't include this namespace, type deduction fails for the "display" class with the (<<) shift operator.
	Understanding this behaviour in the long run and designing for it is preferrable. As it stands, it's not necesarily
	bad design to modularize the "numeric" namespace regardless of the hack that brought it into existence.
*/
   namespace numeric
   {
	template<typename SizeType>
	struct uint
	{
		typedef SizeType size_type;

		typedef context::context::unit<size_type> unit;
/*
	block:
		Need to fix the BlockSize calculation to account for a BitLength which isn't divisible by the unit::length.
		For example one could round up to the nearest multiple of the unit::length.

		It actually might be worthwhile keeping BlockSize as a separate template parameter, as it is possible someone
		might want to subclass this and come up with their own BlockSize for their own reason.
*/
		template<size_type BitLength, size_type BlockSize=BitLength/unit::length>
		class block : protected semiotic::iterator::block<size_type, size_type, BlockSize>
		{
			protected:
				typedef context::semiotic::iterator::policy<size_type> s_policy;
				typedef context::media::iterator::policy<size_type> m_policy;

				friend s_policy; 
				friend m_policy; 
			protected:
				typedef semiotic::iterator::block<size_type, size_type, BlockSize> subblock;
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
/*
	Note: A null-initialization does not set the initial value (to 0 or otherwise).
*/
				block() : subblock() { }
				block(size_type n) : subblock()
				{
					*subblock::array=n;
					s_policy::fwd_comp_unroll<dimension-1>::
						repeat::no_return(subblock::array+1, (value_type) 0);
				}
				block(const block & b) : subblock(b) { }
				const block operator = (const block & b) : subblock::operator=(b)
/*
					subblock::terminalize();
					subblock::copy(b);
*/
					{ return *this; }
			public:
					// iterators:
				iterator begin()
					{ return subblock::array; }
				const_iterator begin() const
					{ return subblock::array; }
				const_iterator cbegin() const
					{ return subblock::array; }
				iterator end()
					{ return subblock::array+dimension; }
				const_iterator end() const
					{ return subblock::array+dimension; }
				const_iterator cend() const
					{ return subblock::array+dimension; }
			public:
				bool operator == (const block & b) const
				{
					return s_policy::fwd_arit_unroll<dimension>::
						equal::fast::with_break(subblock::array, b.array);
				}
				bool operator != (const block & b) const
				{
					return s_policy::fwd_arit_unroll<dimension>::
						not_equal::fast::with_break(subblock::array, b.array);
				}
				bool operator < (const block & b) const
				{
					return s_policy::bwd_arit_unroll<dimension>::
						less_than::fast_break(subblock::array+(dimension-1), b.array+(dimension-1));
				}
				bool operator <= (const block & b) const
				{
					return s_policy::bwd_arit_unroll<dimension>::
						less_than_or_equal::fast_break(subblock::array+(dimension-1), b.array+(dimension-1));
				}
				bool operator > (const block & b) const
				{
					return s_policy::bwd_arit_unroll<dimension>::
						greater_than::fast_break(subblock::array+(dimension-1), b.array+(dimension-1));
				}
				bool operator >= (const block & b) const
				{
					return s_policy::bwd_arit_unroll<dimension>::
						greater_than_or_equal::fast_break(subblock::array+(dimension-1), b.array+(dimension-1));
				}
			public:
/*
	m is the bit length, not the array length.
*/
				const block & operator <<= (size_type m)
				{
					size_type arr_dim(m/unit::length), bit_dim(m%unit::length);

					if (arr_dim >= dimension)
						s_policy::fwd_comp_unroll<dimension>::repeat(subblock::array, (value_type) 0);
					else
					{
						s_policy::bwd_arit_unroll<dimension>::assign::
							left_shift::with_return(subblock::array+(dimension-1),
								subblock::array-1, subblock::array+(dimension-arr_dim), bit_dim);
						*out>>;
					}

					return *this;
				}
/*
	m is the bit length, not the array length.
*/
				const block & operator >>= (size_type m) const
				{
					size_type arr_dim(m/unit::length), bit_dim(m%unit::length);

					if (arr_dim >= dimension)
						s_policy::fwd_comp_unroll<dimension>::repeat(subblock::array, (value_type) 0);
					else
					{
						s_policy::fwd_arit_unroll<dimension>::assign::
							right_shift::with_return(subblock::array+(dimension-1),
								subblock::array-1, subblock::array+(dimension-arr_dim), bit_dim);
						*out<<;
					}

					return *this;
				}
/*
	m is the bit length, not the array length.
*/
				block operator << (size_type m) const
				{
					size_type arr_dim(m/unit::length), bit_dim(m%unit::length);

					block out;
					if (arr_dim >= dimension) fwd_comp_unroll::repeat(out.array, (value_type) 0);
					else bid_arit::left_shift(out.array,
						subblock::array, dimension, arr_dim, bit_dim);

					return out;
				}
/*
	m is the bit length, not the array length.
*/
				block operator >> (size_type m) const
				{
					size_type arr_dim(m/unit::length), bit_dim(m%unit::length);

					block out;
					if (arr_dim >= dimension) fwd_comp_unroll::repeat(out.array, (value_type) 0);
					else bid_arit::right_shift(out.array,
						subblock::array, dimension, arr_dim, bit_dim);

					return out;
				}
			public:
				block operator + (const block & b) const
				{
					block out;
					m_fwd_arit_unroll<dimension>::plus::no_return(out.array, subblock::array, b.array);

					return out;
				}

				block operator - (const block & b) const
				{
					block out;
					m_fwd_arit_unroll<dimension>::minus::no_return(out.array, subblock::array, b.array);

					return out;
				}

				block operator * (size_type b) const
				{
					block out;
					m_fwd_arit_unroll<dimension>::scale::no_return(out.array, subblock::array, b);

					return out;
				}

				block operator * (const block & b) const
				{
					block out, tmp;
					s_fwd_comp_unroll<dimension>::repeat::no_return(out.array, (value_type) 0);
					m_fwd_arit_unroll<dimension>::asterisk::no_return(out.array, tmp.array, subblock::array, b.array);

					return out;
				}
		};
	};

	template<size_t BitLength>
	using uint_block=numeric::uint<size_t>::block<BitLength>;
   }
  }
 }
}

#endif
