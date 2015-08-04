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

#ifndef MEDIA_BLOCK_H
#define MEDIA_BLOCK_H

#include"../../../semiotic/block/block.h"

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
		namespace numeric
		{
/*
	_block:
*/
			template<size_t BlockSize>
			class _block : protected semiotic::block<size_t, size_t, BlockSize>
			{
				protected:
					typedef context::block<size_t, BlockSize> method;
					friend method;
					typedef semiotic::block<size_t, size_t, BlockSize> block;
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
					_block(const _block & n) : block(n) { }
					const _block operator = (const _block & n)
					{
						block::terminalize();
						block::copy(n);
						return *this;
					}
				public:
					bool operator == (const _block & n) const
						{ return method::equal(block::array, n.array); }
					bool operator != (const _block & n) const
						{ return method::not_equal(block::array, n.array); }
					bool operator < (const _block & n) const
						{ return method::less_than(block::array, n.array); }
					bool operator <= (const _block & n) const
						{ return method::less_than_or_equal(block::array, n.array); }
					bool operator > (const _block & n) const
						{ return method::greater_than(block::array, n.array); }
					bool operator >= (const _block & n) const
						{ return method::greater_than_or_equal(block::array, n.array); }
			};
		}

		template<size_t BitLength>
		using block=numeric::_block<BitLength/(8*sizeof(size_t))>;
	}
}

#endif
